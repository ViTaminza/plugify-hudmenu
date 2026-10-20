// pisexcompat timer-registry test — drives the *real* Create/Remove/Process/OnFire code with fake
// s2sdk timer bindings. This is the part of the library that crashed the server: a repeating
// s2sdk timer with a stored delay of 0 makes TimerSystem::RunFrame() re-run the callback forever
// inside one frame ("Server took too long to process" FATAL), and the registry's remove/kill
// bookkeeping had a use-after-free and leaked engine timers for every one-shot timer.
//
// The engine is simulated: the fake CreateTimer records the callback the library registered, and
// the test invokes it exactly like the engine's RunFrame() would (twice per "frame" where the
// engine would repeat a still-scheduled timer). Everything runs in-process and single threaded,
// like the game thread. Run by ../test.sh.

#include <pisex/compat.hpp> // Poll()/Shutdown(): the timer pump the plugin host calls
#include <pisex/timers.hpp>

#include <plg/plugin.hpp>

#include <s2sdk/s2sdk.hpp>

#include <cstdint>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>

// A real plugin gets these from PLUGIFY_PLUGIN; the test leaves them null (no plugify module),
// which is also the state the library has to survive.
namespace plg {
GetBaseDirFn GetBaseDir{nullptr};
GetExtensionsDirFn GetExtensionsDir{nullptr};
GetConfigsDirFn GetConfigsDir{nullptr};
GetDataDirFn GetDataDir{nullptr};
GetLogsDirFn GetLogsDir{nullptr};
GetCacheDirFn GetCacheDir{nullptr};
IsLoadedFn IsLoaded{nullptr};
LogFn Log{nullptr};
BeginZoneFn BeginZone{nullptr};
EndZoneFn EndZone{nullptr};
} // namespace plg

namespace {

int g_checks = 0;
int g_failures = 0;

void Check(bool condition, const std::string& what) {
	++g_checks;
	if (!condition) {
		++g_failures;
		std::printf("FAIL: %s\n", what.c_str());
	}
}

// --- the fake engine ---------------------------------------------------------------------------

struct EngineTimer {
	uint32_t id = 0;
	double delay = 0.0;
	s2sdk::TimerCallback callback = nullptr;
	bool repeat = false;
};

std::vector<EngineTimer> g_engineTimers;
std::vector<uint32_t> g_killed;
std::vector<std::pair<uint32_t, double>> g_rescheduled;
uint32_t g_nextId = 0;

const EngineTimer* FindEngineTimer(uint32_t id) {
	for (const EngineTimer& timer : g_engineTimers) {
		if (timer.id == id) {
			return &timer;
		}
	}
	return nullptr;
}

// Forgets every recorded engine state (so the next timer gets id 0 again) but keeps the fake
// bindings installed.
void ClearRecording() {
	g_engineTimers.clear();
	g_killed.clear();
	g_rescheduled.clear();
	g_nextId = 0;
}

// Removes the fake bindings again: the "no s2sdk plugin" state.
void ResetEngine() {
	ClearRecording();
	__s2sdk_CreateTimer = nullptr;
	__s2sdk_KillsTimer = nullptr;
	__s2sdk_RescheduleTimer = nullptr;
}

// Ids start at 0, like s2sdk's TimerSystem::m_nextId{} - the first timer of the process really has
// id 0, and the library must treat that as a valid id.
s2sdk::TimerId FakeCreateTimer(double delay, s2sdk::TimerCallback callback, s2sdk::TimerFlag flags,
							   const plg::vector<plg::any>& userData) {
	(void)userData;
	EngineTimer timer;
	timer.id = g_nextId++;
	timer.delay = delay;
	timer.callback = callback;
	timer.repeat = (static_cast<int32_t>(flags) & static_cast<int32_t>(s2sdk::TimerFlag::Repeat)) != 0;
	g_engineTimers.push_back(timer);
	return timer.id;
}

void FakeKillsTimer(s2sdk::TimerId id) {
	g_killed.push_back(id);
	for (auto it = g_engineTimers.begin(); it != g_engineTimers.end(); ++it) {
		if (it->id == id) {
			g_engineTimers.erase(it);
			return;
		}
	}
}

void FakeRescheduleTimer(s2sdk::TimerId id, double delay) {
	g_rescheduled.emplace_back(id, delay);
	if (const EngineTimer* timer = FindEngineTimer(id)) {
		const_cast<EngineTimer*>(timer)->delay = delay;
	}
}

void InstallEngine() {
	ResetEngine();
	__s2sdk_CreateTimer = &FakeCreateTimer;
	__s2sdk_KillsTimer = &FakeKillsTimer;
	__s2sdk_RescheduleTimer = &FakeRescheduleTimer;
}

// What TimerSystem::RunFrame() does to a timer that is still scheduled: call it. A Repeat timer is
// re-inserted and fires again on every RunFrame() pass, which is exactly what the test simulates by
// firing twice before the next Poll().
void FireEngineTimer(uint32_t id) {
	const EngineTimer* timer = FindEngineTimer(id);
	Check(timer != nullptr, "the engine still knows timer " + std::to_string(id));
	if (timer && timer->callback) {
		timer->callback(id, plg::vector<plg::any>{});
	}
}

int KillCount(uint32_t id) {
	int count = 0;
	for (const uint32_t killed : g_killed) {
		count += killed == id ? 1 : 0;
	}
	return count;
}

bool RescheduledWith(uint32_t id, double delay) {
	for (const auto& [rescheduledId, value] : g_rescheduled) {
		if (rescheduledId == id && value == delay) {
			return true;
		}
	}
	return false;
}

// --- the tests ---------------------------------------------------------------------------------

// The delay handed to s2sdk (both at creation and on reschedule) must never be below one tick.
void TestCreateAndRescheduleClamp() {
	InstallEngine();

	struct Case {
		float interval;
		double expectedDelay;
	};
	// 0 (and negative) is Pisex's "run again next frame" - the only safe encoding is one tick.
	const Case cases[] = {
		{0.0f, pisex::kMinTimerDelay},	 { -2.0f, pisex::kMinTimerDelay }, {0.001f, pisex::kMinTimerDelay},
		{0.0156249f, pisex::kMinTimerDelay}, {1.0f, 1.0},				{60.0f, 60.0},
	};

	for (const Case& testCase : cases) {
		ClearRecording(); // keep the bindings, restart the id counter
		pisex::CTimer* timer = pisex::CreateTimer(testCase.interval, [] { return -1.0f; });
		Check(timer != nullptr, "CreateTimer(" + std::to_string(testCase.interval) + ") works");
		const EngineTimer* created = g_engineTimers.empty() ? nullptr : &g_engineTimers.front();
		Check(created != nullptr && created->delay == testCase.expectedDelay,
			  "CreateTimer(" + std::to_string(testCase.interval) + ") hands s2sdk the clamped delay");
		Check(created != nullptr && created->repeat, "the s2sdk timer is a Repeat timer");
		pisex::RemoveTimer(timer);
	}

	// TimerSystem ids start at 0: the first timer of a process must not be rejected as "failure",
	// and it must be killable (the old code skipped KillsTimer for id 0 - the engine timer then
	// fired forever with its CTimer already freed).
	ClearRecording();
	pisex::CTimer* first = pisex::CreateTimer(1.0f, [] { return -1.0f; });
	Check(first != nullptr, "a timer with s2sdk id 0 is accepted");
	Check(first != nullptr && first->Handle() == 0, "the id really is 0");
	pisex::RemoveTimer(first);
	Check(KillCount(0) == 1, "RemoveTimer kills the engine timer with id 0");
	pisex::RemoveTimer(first); // dead handle: must stay a no-op (this is Pisex cleanup code)
	Check(KillCount(0) == 1, "RemoveTimer on a dead handle does not kill twice");

	// The value the callback returned goes through RescheduleTimer - clamped as well (Pisex's
	// "return 0" is the common repeat-next-frame idiom that crashed the server).
	ClearRecording();
	pisex::CTimer* repeat = pisex::CreateTimer(1.0f, [] { return 0.0f; });
	Check(repeat != nullptr, "a next-frame repeating timer is created");
	const uint32_t repeatId = repeat != nullptr ? repeat->Handle() : 0;
	const std::size_t killCountBefore = g_killed.size();
	FireEngineTimer(repeatId);
	Check(g_rescheduled.empty(), "firing a timer makes no s2sdk call from inside the callback");
	Check(g_killed.size() == killCountBefore, "firing a timer kills nothing from inside the callback");
	pisex::Poll();
	Check(RescheduledWith(repeatId, pisex::kMinTimerDelay), "a returned 0 is clamped to one tick at reschedule");
	// The engine re-fires the same timer before the next Poll (it is still scheduled with the old
	// delay): the callback must not run twice per frame.
	FireEngineTimer(repeatId);
	FireEngineTimer(repeatId);
	Check(g_rescheduled.size() == 1, "a timer that is waiting for its reschedule ignores further fires");
	pisex::Poll();
	Check(g_rescheduled.size() == 2, "after the reschedule the timer can fire again");
	pisex::RemoveTimer(repeat);

	ResetEngine();
}

// A callback that returns a negative value stops the timer: the engine timer must be killed (the
// old reap path skipped already-marked timers, so every one-shot leaked its CTimer and left a
// repeating s2sdk timer firing forever).
void TestOneShotIsKilled() {
	InstallEngine();

	pisex::CTimer* oneShot = pisex::CreateTimer(0.5f, [] { return -1.0f; });
	Check(oneShot != nullptr, "one-shot timer created");
	const uint32_t id = oneShot != nullptr ? oneShot->Handle() : 0;
	FireEngineTimer(id);
	Check(oneShot != nullptr && !oneShot->IsAlive(), "the handle reports the timer as stopped");
	Check(g_killed.empty(), "the kill happens in Poll(), not inside the callback");
	pisex::Poll();
	Check(KillCount(id) == 1, "Process() kills the engine timer of a stopped one-shot");
	pisex::RemoveTimer(oneShot); // the handle is dead but must stay safe
	Check(KillCount(id) == 1, "the dead one-shot handle stays a no-op");

	ResetEngine();
}

// A callback removing its *own* timer is legal Pisex usage - the old code freed the CTimer while
// OnFire() was still using it (use-after-free, and a double free at Shutdown()).
void TestRemoveFromInsideCallback() {
	InstallEngine();

	pisex::CTimer* self = nullptr;
	int runs = 0;
	self = pisex::CreateTimer(0.5f, [&self, &runs] {
		++runs;
		self->RemoveTimer();
		return -1.0f;
	});
	Check(self != nullptr, "self-removing timer created");
	const uint32_t id = self != nullptr ? self->Handle() : 0;
	FireEngineTimer(id); // the callback runs RemoveTimer() on its own handle
	Check(runs == 1, "the self-removing callback ran exactly once");
	Check(KillCount(id) == 1, "self-removal killed the engine timer");
	pisex::RemoveTimer(self); // dangling-looking handle: must still be a safe no-op
	Check(KillCount(id) == 1, "the handle of a self-removed timer stays a no-op");
	pisex::Poll(); // frees the object; must not touch it again
	Check(true, "Poll() after a self-removal does not crash");

	// A callback may also remove a *different* timer (the admin core's cleanup does).
	InstallEngine();
	pisex::CTimer* other = pisex::CreateTimer(5.0f, [] { return -1.0f; });
	pisex::CTimer* remover = nullptr;
	remover = pisex::CreateTimer(0.5f, [&other] {
		pisex::RemoveTimer(other);
		other = nullptr;
		return -1.0f;
	});
	const uint32_t otherId = other != nullptr ? other->Handle() : 0;
	Check(other != nullptr && remover != nullptr, "two timers created");
	FireEngineTimer(remover->Handle());
	Check(KillCount(otherId) == 1, "removing another timer from inside a callback kills it");
	pisex::Poll();
	Check(true, "Poll() after a cross-timer removal does not crash");

	ResetEngine();
}

// Shutdown() from inside a timer callback (a plugin unloading itself): Clear() must not free or
// clear the fn_ of the timer whose callback is on the stack.
void TestShutdownFromInsideCallback() {
	InstallEngine();

	pisex::CTimer* timer = nullptr;
	int runs = 0;
	timer = pisex::CreateTimer(0.5f, [&timer, &runs] {
		++runs;
		pisex::Shutdown();
		return -1.0f;
	});
	pisex::CTimer* other = pisex::CreateTimer(1.0f, [] { return -1.0f; });
	Check(timer != nullptr && other != nullptr, "timers created before the in-callback Shutdown");
	const uint32_t id = timer->Handle();
	const uint32_t otherId = other->Handle();
	FireEngineTimer(id);
	Check(runs == 1, "the callback ran");
	Check(KillCount(id) == 1 && KillCount(otherId) == 1, "Shutdown() killed both engine timers");
	pisex::RemoveTimer(timer); // safe no-op on a dead handle
	pisex::RemoveTimer(other);
	Check(true, "handles stay safe after an in-callback Shutdown");
	pisex::Poll();
	Check(true, "Poll() after an in-callback Shutdown does not crash");

	// The registry is usable again after Shutdown (a plugin may call Init/Poll once more).
	InstallEngine();
	pisex::CTimer* again = pisex::CreateTimer(1.0f, [] { return 1.0f; });
	Check(again != nullptr, "timers can be created again after Shutdown");
	if (again) {
		pisex::RemoveTimer(again);
	}
	pisex::Shutdown();

	// Leave the process in the "no s2sdk plugin" state the other checks rely on.
	ResetEngine();
}

// The dead-handle bookkeeping remembers freed *addresses*, and the allocator hands a freed
// CTimer's memory straight to the next one: a fresh timer must never be mistaken for a dead
// handle. (With the bug this test caught, the second cycle's RemoveTimer() silently did nothing -
// engine timer left running - and OnFire() freed the live object after its first callback, which
// is a use-after-free.)
void TestRecycledAddresses() {
	InstallEngine();

	// RemoveTimer() path - each cycle's allocation reuses the previous cycle's freed address.
	for (int i = 0; i < 64; ++i) {
		pisex::CTimer* timer = pisex::CreateTimer(1.0f, [] { return -1.0f; });
		Check(timer != nullptr, "cycle timer created");
		const uint32_t id = timer != nullptr ? timer->Handle() : 0;
		pisex::RemoveTimer(timer);
		Check(KillCount(id) == 1, "RemoveTimer kills the engine timer in cycle " + std::to_string(i));
	}

	// Fire path - the object is freed by Poll() and its address is reused by the next timer.
	for (int i = 0; i < 16; ++i) {
		int runs = 0;
		pisex::CTimer* timer = pisex::CreateTimer(1.0f, [&runs] {
			++runs;
			return -1.0f;
		});
		Check(timer != nullptr, "stop-cycle timer created");
		const uint32_t id = timer != nullptr ? timer->Handle() : 0;
		FireEngineTimer(id);
		Check(runs == 1, "stop-cycle callback ran (cycle " + std::to_string(i) + ")");
		Check(timer != nullptr && !timer->IsAlive(), "stop-cycle timer stopped (cycle " + std::to_string(i) + ")");
		pisex::Poll(); // frees the object; its address becomes the next allocation's
		Check(KillCount(id) == 1, "stopped timer was killed (cycle " + std::to_string(i) + ")");
	}

	ResetEngine();
}

// Timers survive a map change (Pisex semantics - the admin core's expiry timer relies on it), but
// their callbacks must not run while no map is up: s2sdk's client list is torn down in that window
// and a ported callback almost always touches players (a timer that renames a player reaches
// Player::SetName on a clientless slot, which crashes). The fire is postponed and the
// timer re-armed with one tick on the first ready frame. NextFrame behaves the same way.
void TestMapChangePostponement() {
	InstallEngine();

	// Normalise the lifecycle: end any map, then start a fresh one.
	pisex::OnMapEndNotify();
	pisex::Poll();
	Check(!pisex::IsGameReady(), "no map is ready after a map end");
	pisex::OnMapStartNotify();
	Check(!pisex::IsGameReady(), "the map start alone does not grant readiness (no update yet)");
	pisex::Poll();
	Check(pisex::IsGameReady(), "the first update after the map start is ready");

	int runs = 0;
	pisex::CTimer* timer = pisex::CreateTimer(1.0f, [&runs] {
		++runs;
		return 1.0f;
	});
	Check(timer != nullptr, "timer created on a ready map");
	const uint32_t id = timer != nullptr ? timer->Handle() : 0;
	FireEngineTimer(id);
	Check(runs == 1, "the callback runs while the map is up");
	pisex::Poll(); // applies the reschedule

	// The map ends. The engine keeps firing our Repeat timer; no callback may run.
	pisex::OnMapEndNotify();
	Check(!pisex::IsGameReady(), "the map end disables client/entity access");
	FireEngineTimer(id);
	FireEngineTimer(id);
	Check(runs == 1, "a fire during the map change is postponed (the callback does not run)");
	Check(!pisex::IsGameReady(), "the fires did not make the library ready");
	pisex::Poll();
	Check(runs == 1, "a Poll during the map change does not run the callback");
	Check(!pisex::IsGameReady(), "a Poll during the map change does not re-enable readiness");
	FireEngineTimer(id);
	Check(runs == 1, "still postponed several frames into the map change");

	bool nextFrameRan = false;
	pisex::NextFrame([&nextFrameRan] { nextFrameRan = true; });
	pisex::Poll();
	Check(!nextFrameRan, "NextFrame waits for a ready frame");

	// The new map is up: the postponed timer is re-armed with one tick, then fires normally.
	pisex::OnMapStartNotify();
	pisex::Poll();
	Check(pisex::IsGameReady(), "ready again after the new map start");
	Check(RescheduledWith(id, pisex::kMinTimerDelay), "the postponed timer is re-armed with one tick");
	Check(nextFrameRan, "NextFrame runs on the first ready frame");
	FireEngineTimer(id);
	Check(runs == 2, "the postponed callback runs on the new map");
	pisex::Poll();
	pisex::RemoveTimer(timer);

	ResetEngine();
}

// Without the bindings nothing may be created, and every entry point stays a no-op.
void TestWithoutBindings() {
	ResetEngine();
	Check(pisex::CreateTimer(1.0f, [] { return -1.0f; }) == nullptr, "CreateTimer degrades to nullptr");
	pisex::NextFrame([] {});
	pisex::Poll();
	pisex::Shutdown();
	Check(true, "Poll/Shutdown without bindings are safe");
}

} // namespace

int main() {
	std::printf("pisexcompat timer engine tests (fake s2sdk timer bindings)\n");

	TestWithoutBindings();
	TestCreateAndRescheduleClamp();
	TestOneShotIsKilled();
	TestRecycledAddresses();
	TestRemoveFromInsideCallback();
	TestMapChangePostponement();
	TestShutdownFromInsideCallback();
	TestWithoutBindings();

	std::printf("%d checks, %d failures\n", g_checks, g_failures);
	return g_failures == 0 ? 0 : 1;
}
