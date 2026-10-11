// pisexcompat — Pisex timers over s2sdk timers.
//
//   CTimer* t = g_pUtils->CreateTimer(1.0f, [] { ...; return 1.0f; }); // repeat after 1s
//   CTimer* u = g_pUtils->CreateTimer(0.0f, [] { ...; return -1.0f; }); // stop after one run
//
// Semantics kept from Pisex's CTimer: the callback returns the delay (in seconds) until its next
// run, or a negative value to stop and destroy the timer. The timer object is owned by
// pisexcompat and freed when it stops (or at Shutdown()); RemoveTimer() on an already dead handle
// is a safe no-op (Pisex's version would use-after-free).
//
// Delay floor: every delay handed to s2sdk is clamped to one server tick (kMinTimerDelay, 1/64 s).
// The s2sdk timer system re-inserts a repeating timer at
// universalTime + its *stored* delay inside a `while` loop that runs callbacks as long as one is
// due, so a stored delay of 0 makes that loop re-run the callback forever inside a single frame —
// "Server took too long to process (probably infinite loop)" -> FATAL. Pisex's "0 (or negative) =
// run again next frame" is preserved by the clamp: one tick is the earliest the engine can fire
// the timer again.
//
// Implementation notes (why there is a Poll()):
//   * s2sdk timers are single-shot by default; we create them with TimerFlag::Repeat and always
//     call RescheduleTimer with the value the callback returned.
//   * TimerSystem::RunFrame() invokes the callback from inside its own loop (the mutex is
//     recursive and both KillTimer/RescheduleTimer special-case a timer that is *executing*:
//     KillTimer defers the erase, RescheduleTimer ignores the call). OnFire() therefore makes no
//     s2sdk call of its own: the callback only *records* the requested next delay, and
//     pisex::Poll() (game thread, once per frame) performs the reschedule/kill after the engine's
//     loop is done. While a timer waits for that (at most one frame), further fires are ignored,
//     so a callback never runs twice per frame - which is what Pisex's own timer loop guarantees.
//   * Timers survive map changes, exactly like the Pisex ones (the admin core's one-second
//     punishment-expiry timer is expected to keep running across maps). Shutdown() kills them.
//     While no map is up (from OnMapEnd to the next map start - s2sdk's client list is torn down
//     in that window) a timer never invokes its callback: the fire is *postponed* and the timer
//     is re-armed with one tick on the first ready frame, so the callback runs as early as the
//     engine can again but with a live map. The next delay is still whatever the callback
//     returns when it finally runs.

#pragma once

#include <cstdint>
#include <functional>

namespace pisex {

// One engine tick at the default 64 tickrate; the same constant s2sdk's TimerSystem uses
// (engineFixedTickInterval). No delay below this is ever passed to the s2sdk timer calls.
constexpr double kMinTimerDelay = 1.0 / 64.0; // 0.015625

// Floors a timer delay at one server tick. Pure logic (unit-tested in tests/pisexcompat_tests.cpp).
// A non-positive, sub-tick or NaN delay all mean "as soon as possible" in Pisex terms - which is
// one tick away, never 0: s2sdk stores the delay and re-inserts a repeating timer at
// universalTime + stored delay, and a stored 0 loops forever inside one RunFrame() call.
inline double ClampTimerDelay(double delay) noexcept {
	// NaN fails both comparisons intentionally: it is treated like 0 ("next frame").
	return delay > kMinTimerDelay ? delay : kMinTimerDelay;
}

class CTimer {
public:
	// Stops and destroys the timer (safe to call with the handle the callback runs in).
	void RemoveTimer();
	bool IsAlive() const { return alive_; }
	// Delay currently scheduled (the value the last callback run returned).
	float GetInterval() const { return interval_; }
	// Applies from the next run onwards.
	void SetInterval(float interval) { interval_ = interval; }

	// pisexcompat internals.
	uint32_t Handle() const { return id_; }

private:
	friend struct TimerAccess; // internal: only timers.cpp uses it

	uint32_t id_ = 0;
	float interval_ = 0.0f;
	bool alive_ = true;
	bool pending_ = false;   // callback ran, waiting for Poll() to reschedule
	bool firing_ = false;    // the callback is on the stack right now (see RemoveTimer in timers.cpp)
	bool postponed_ = false; // fired while no map was up; re-armed with one tick after the next map start
	std::function<float()> fn_;
};

// Internal — not part of the Pisex surface. Exists so the registry in timers.cpp can reach the
// private state of CTimer without making the fields public.
struct TimerAccess {
	static uint32_t& Id(CTimer& timer) { return timer.id_; }
	static float& Interval(CTimer& timer) { return timer.interval_; }
	static bool& Alive(CTimer& timer) { return timer.alive_; }
	static bool& Pending(CTimer& timer) { return timer.pending_; }
	static bool& Firing(CTimer& timer) { return timer.firing_; }
	static bool& Postponed(CTimer& timer) { return timer.postponed_; }
	static std::function<float()>& Fn(CTimer& timer) { return timer.fn_; }
};

// Pisex's IUtilsApi::CreateTimer. Returns nullptr when the s2sdk timer binding is missing.
CTimer* CreateTimer(float flInterval, std::function<float()> fn);
// Pisex's IUtilsApi::RemoveTimer.
void RemoveTimer(CTimer* timer);

// Pisex's IUtilsApi::NextFrame: runs fn once on the next Poll() (next server frame).
void NextFrame(std::function<void()> fn);

// pisexcompat internals, called by pisex::Poll().
void ProcessTimers();
// Kills every timer and drops the next-frame queue (Shutdown()).
void ClearTimers();

} // namespace pisex
