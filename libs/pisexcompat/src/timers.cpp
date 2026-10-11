#include <pisex/timers.hpp>

#include <pisex/compat.hpp> // IsGameReady(): callbacks must not run while no map is up
#include <pisex/output.hpp>

#include <s2sdk/s2sdk.hpp>

#include <cstddef>
#include <deque>
#include <exception>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace pisex {
namespace {

// How many dead handles are remembered so that RemoveTimer() on an already dead timer stays a
// no-op. One entry is a pointer, so the cap costs ~160 KB at the very most; a plugin that keeps a
// handle across thousands of other timer lifetimes is buggy anyway (Pisex would have crashed).
constexpr std::size_t kMaxDeadHandles = 4096;

// Owns the CTimer objects. The plugin only ever holds raw CTimer* handles (Pisex's CreateTimer
// returns a raw pointer) and Pisex frees a timer the moment it stops, so ported cleanup code
// routinely calls RemoveTimer() on a dead handle - stopped handles are remembered for that reason.
//
// One thread (the game thread) touches this class, but at two different points of the frame:
//   * from TimerSystem::RunFrame() -> Trampoline() -> OnFire() - the engine is inside its own
//     callback loop here, so OnFire() makes no s2sdk timer call at all: it only records what the
//     callback wants. (A callback that removes its own timer does call KillsTimer through
//     Remove(); the engine defers the erase for a timer that is executing, so that is safe. What
//     is *not* safe is touching the CTimer after the callback returned, or freeing it while the
//     callback is on the stack - both are handled by Firing_/pendingReap_.)
//   * from pisex::Poll() -> Process(), which does the killing/rescheduling after the engine loop,
//   * from plugin code (game thread as well) -> Create()/Remove().
class TimerRegistry {
public:
	TimerRegistry() = default;
	TimerRegistry(const TimerRegistry&) = delete;
	TimerRegistry& operator=(const TimerRegistry&) = delete;

	CTimer* Create(float interval, std::function<float()> fn) {
		if (!__s2sdk_CreateTimer || fn == nullptr) {
			return nullptr;
		}
		auto timer = std::make_unique<CTimer>();
		TimerAccess::Interval(*timer) = interval;
		TimerAccess::Fn(*timer) = std::move(fn);

		// The delay handed to s2sdk is floored at one server tick (see ClampTimerDelay: the
		// backend re-inserts a repeating timer at universalTime + the *stored* delay, so a 0 would
		// loop forever inside one RunFrame()). The CTimer keeps the value the plugin asked for, so
		// GetInterval()/SetInterval() stay Pisex-shaped.
		// Repeat: the timer stays alive until we kill it. Deliberately *without* NoMapChange -
		// the Pisex timers keep running across map changes (the admin core's punishment-expiry
		// timer relies on that).
		const s2sdk::TimerId id =
			s2sdk::CreateTimer(ClampTimerDelay(static_cast<double>(interval)), &TimerRegistry::Trampoline,
							   s2sdk::TimerFlag::Repeat, plg::vector<plg::any>{});
		// s2sdk's ids start at 0 (TimerSystem::m_nextId{}), so id 0 is a real timer - only the
		// documented -1 means "could not create". Treating 0 as failure broke the process's first
		// timer (the plugin got nullptr) and leaked its untracked engine timer.
		if (id == static_cast<s2sdk::TimerId>(-1)) {
			return nullptr;
		}

		CTimer* raw = timer.release();
		// The dead-handle bookkeeping (dead_) matches raw pointer *values*, and CTimer objects are
		// recycled by the allocator: a fresh timer can be allocated at the address of one that was
		// removed earlier. Forget any stale entry for that address, or the new timer would be
		// treated as dead by the first RemoveTimer() call (silently not stopping it) and by OnFire()
		// (which would free the live object after its first callback - a use-after-free).
		dead_.erase(raw);
		TimerAccess::Id(*raw) = id;
		byId_[id] = raw;
		live_.insert(raw);
		return raw;
	}

	void Remove(CTimer* timer) {
		if (!timer || Gone(timer) || live_.count(timer) == 0) {
			return; // unknown, already dead, or stopped and waiting for Process() to reap it
		}
		Kill(timer);
		MarkDead(timer);
		// Both registries must forget the object before it goes away: a leftover byId_ entry would
		// be dereferenced by the engine's next fire (use-after-free - and for id 0, the engine
		// timer was never even killed), a leftover live_ entry would be written to and freed a
		// second time by Clear() during Shutdown().
		byId_.erase(TimerAccess::Id(*timer));
		live_.erase(timer);
		if (TimerAccess::Firing(*timer)) {
			// Called from inside this timer's own callback: the callback still owns the object -
			// OnFire() reads it once more when the callback returns - and fn_ is executing right
			// now, so neither the object nor fn_ may be touched here. OnFire() frees the object as
			// soon as the callback has returned (the registries no longer know it, so the handle
			// is dead and the engine timer is gone).
			return;
		}
		TimerAccess::Fn(*timer) = nullptr;
		delete timer;
	}

	// Game thread, once per frame (pisex::Poll).
	void Process() {
		const std::vector<CTimer*> reschedule = std::move(pendingReschedule_);
		pendingReschedule_.clear();
		for (CTimer* timer : reschedule) {
			if (Gone(timer) || live_.count(timer) == 0 || !TimerAccess::Alive(*timer)) {
				continue;
			}
			if (!IsGameReady()) {
				// No map (or a map change in progress): callbacks must not run, so the timer
				// stays parked - Pending is still set, which makes OnFire() ignore the engine's
				// repeated fires. Keep it queued and re-arm it on the first ready Poll.
				pendingReschedule_.push_back(timer);
				continue;
			}
			const bool postponed = TimerAccess::Postponed(*timer);
			TimerAccess::Postponed(*timer) = false;
			TimerAccess::Pending(*timer) = false;
			if (__s2sdk_RescheduleTimer) {
				try {
					// Same clamp as Create(): the value the callback returned (Pisex's "0 = next
					// frame" included) must never reach the backend below one tick, or the
					// engine's RunFrame() re-fires this repeating timer inside the same frame.
					// A fire that was postponed over the map change is re-armed with one tick so
					// the callback runs as soon as the engine can again (the delay the callback
					// returns then governs the following runs).
					s2sdk::RescheduleTimer(TimerAccess::Id(*timer),
										   postponed ? kMinTimerDelay
													 : ClampTimerDelay(static_cast<double>(TimerAccess::Interval(*timer))));
				} catch (...) {
					Kill(timer);
					MarkDead(timer);
					byId_.erase(TimerAccess::Id(*timer));
					live_.erase(timer);
					TimerAccess::Fn(*timer) = nullptr;
					stragglers_.erase(timer);
					delete timer;
				}
			}
		}

		const std::vector<CTimer*> reap = std::move(pendingReap_);
		pendingReap_.clear();
		for (CTimer* timer : reap) {
			// Queued exactly once: Remove()/OnFire() only queue an object they also just erased
			// from live_/byId_ (a second RemoveTimer() call on it is a no-op), and the object is
			// still allocated here. The kill is what stops the engine timer of a one-shot whose
			// callback returned a negative delay - OnFire() itself makes no s2sdk call. Killing an
			// id Remove() already killed is a no-op.
			stragglers_.erase(timer);
			Kill(timer);
			delete timer;
		}
	}

	void Clear() {
		for (const auto& entry : byId_) {
			Kill(entry.second);
		}
		for (CTimer* timer : live_) {
			if (TimerAccess::Firing(*timer)) {
				// Shutdown() came from inside this timer's own callback: the callback still owns
				// the object and fn_ is on the stack. OnFire() frees the object once the callback
				// returned (the engine timer was killed above, so it never runs again); freeing or
				// clearing fn_ here would be a use-after-free.
				continue;
			}
			TimerAccess::Alive(*timer) = false;
			TimerAccess::Fn(*timer) = nullptr;
			delete timer;
		}
		for (CTimer* timer : stragglers_) { // stopped or removed, waiting for a Process()
			delete timer;
		}
		live_.clear();
		byId_.clear();
		dead_.clear();
		deadOrder_.clear();
		stragglers_.clear();
		pendingReschedule_.clear();
		pendingReap_.clear();
	}

	// Engine thread; must never throw.
	static void Trampoline(uint32_t id, const plg::vector<plg::any>& userData) {
		(void)userData;
		try {
			Instance().OnFire(id);
		} catch (...) {
		}
	}

	static TimerRegistry& Instance() {
		static TimerRegistry registry;
		return registry;
	}

private:
	// A pointer that was freed (or is about to be freed by Process) - never dereferenced.
	bool Gone(CTimer* timer) const { return dead_.count(timer) != 0; }

	void MarkDead(CTimer* timer) {
		dead_.insert(timer);
		deadOrder_.push_back(timer);
		while (deadOrder_.size() > kMaxDeadHandles) {
			dead_.erase(deadOrder_.front());
			deadOrder_.pop_front();
		}
	}

	// No s2sdk call here (see the class comment): only bookkeeping.
	void OnFire(uint32_t id) {
		const auto found = byId_.find(id);
		if (found == byId_.end()) {
			return; // timer destroyed on our side
		}
		CTimer* timer = found->second;
		if (!TimerAccess::Alive(*timer) || TimerAccess::Pending(*timer) || !TimerAccess::Fn(*timer)) {
			return; // already ran this frame, waiting for Process() - or postponed (see below)
		}

		if (!IsGameReady()) {
			// No map is up (map end -> next map start): ported callbacks query clients/entities,
			// which s2sdk cannot serve in that window (its client list is gone; a query segfaults
			// at address 0). Do not run the callback now; mark the fire as
			// postponed and let Process() re-arm the timer with one tick on the first ready frame.
			// Pending stays set, so every further engine fire in this window is ignored.
			TimerAccess::Postponed(*timer) = true;
			TimerAccess::Pending(*timer) = true;
			pendingReschedule_.push_back(timer);
			return;
		}

		// While the flag is set, Remove() must not free the object or touch fn_ (the callback is
		// executing it): it only records the removal, and the code below frees the object.
		TimerAccess::Firing(*timer) = true;
		float next = -1.0f;
		try {
			next = TimerAccess::Fn(*timer)();
		} catch (const std::exception& ex) {
			ErrorLog("pisexcompat: timer callback threw: %s", ex.what());
			next = -1.0f;
		} catch (...) {
			ErrorLog("pisexcompat: timer callback threw an unknown exception");
			next = -1.0f;
		}
		TimerAccess::Firing(*timer) = false;

		if (Gone(timer) || live_.count(timer) == 0) {
			// The callback removed its own timer (Pisex handles are raw pointers and ported code
			// does that), or Shutdown() ran inside the callback: Remove()/Clear() killed the
			// engine timer, erased the registries and deliberately left the object for us. The
			// callback has returned by now, so fn_ is no longer executing - free it now (waiting
			// for Process() would leak it whenever Shutdown() is not followed by another Poll()).
			stragglers_.erase(timer);
			delete timer;
			return;
		}

		if (next >= 0.0f) {
			TimerAccess::Alive(*timer) = true;
			TimerAccess::Interval(*timer) = next;
			TimerAccess::Pending(*timer) = true;
			pendingReschedule_.push_back(timer);
			return;
		}

		// The callback wants to stop. Keep the handle valid for the caller (IsAlive() is false,
		// RemoveTimer() on it is a no-op) and let Process() kill the engine timer and free it.
		TimerAccess::Alive(*timer) = false;
		TimerAccess::Fn(*timer) = nullptr;
		byId_.erase(id);
		live_.erase(timer);
		MarkDead(timer);
		stragglers_.insert(timer);
		pendingReap_.push_back(timer);
	}

	void Kill(CTimer* timer) {
		// id 0 is as valid as any other (s2sdk's ids start at 0) - killing it is what makes the
		// first timer of the process work.
		if (__s2sdk_KillsTimer) {
			try {
				s2sdk::KillsTimer(TimerAccess::Id(*timer));
			} catch (...) {
			}
		}
	}

	std::unordered_map<uint32_t, CTimer*> byId_;
	std::unordered_set<CTimer*> live_;
	std::unordered_set<CTimer*> dead_;
	std::deque<CTimer*> deadOrder_;
	std::unordered_set<CTimer*> stragglers_; // stopped timers not yet deleted by Process()
	std::vector<CTimer*> pendingReschedule_;
	std::vector<CTimer*> pendingReap_;
};

std::deque<std::function<void()>> g_nextFrame;

} // namespace

void CTimer::RemoveTimer() {
	pisex::RemoveTimer(this);
}

CTimer* CreateTimer(float flInterval, std::function<float()> fn) {
	try {
		return TimerRegistry::Instance().Create(flInterval, std::move(fn));
	} catch (const std::exception& ex) {
		ErrorLog("pisexcompat: CreateTimer failed: %s", ex.what());
	} catch (...) {
		ErrorLog("pisexcompat: CreateTimer failed with an unknown exception");
	}
	return nullptr;
}

void RemoveTimer(CTimer* timer) {
	try {
		TimerRegistry::Instance().Remove(timer);
	} catch (...) {
	}
}

void NextFrame(std::function<void()> fn) {
	if (fn == nullptr) {
		return;
	}
	g_nextFrame.push_back(std::move(fn));
}

void ProcessTimers() {
	// Next-frame callbacks first: they are the cheapest "later" work a plugin queues, and the
	// budget keeps a callback that queues another one from starving the frame.
	// While no map is up they stay queued ("next frame" cannot mean "during the map change"):
	// they run on the first ready frame, like the postponed timers, so they never see stale slots.
	if (IsGameReady()) {
		std::size_t budget = g_nextFrame.size();
		while (budget-- > 0 && !g_nextFrame.empty()) {
			std::function<void()> fn = std::move(g_nextFrame.front());
			g_nextFrame.pop_front();
			try {
				fn();
			} catch (const std::exception& ex) {
				ErrorLog("pisexcompat: NextFrame callback threw: %s", ex.what());
			} catch (...) {
				ErrorLog("pisexcompat: NextFrame callback threw an unknown exception");
			}
		}
	}
	TimerRegistry::Instance().Process();
}

void ClearTimers() {
	TimerRegistry::Instance().Clear();
	g_nextFrame.clear();
}

} // namespace pisex
