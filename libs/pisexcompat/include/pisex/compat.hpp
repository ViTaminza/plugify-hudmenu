// pisexcompat — the single entry point a ported Pisex plugin uses.
//
//   plg::PluginResult OnPluginStart() {
//       pisex::Init("admin_system");            // names the plugin (config/translations dirs)
//       pisex::g_pUtils->StartupServer([] { ... }); // deferred to the first update with a map
//       return plg::PluginResult::Success;      // never Failed: that stops every Plugify plugin
//   }
//   plg::PluginResult OnPluginUpdate(std::chrono::milliseconds) {
//       pisex::Poll();                          // timers, next-frame queue, deferred startup
//       return plg::PluginResult::Continue;
//   }
//   plg::PluginResult OnPluginEnd() { pisex::Shutdown(); return plg::PluginResult::Success; }
//
// Why the trio exists:
//   * s2sdk client queries (IsClientConnected & friends) crash when they run before a map exists,
//     so everything that touches clients waits for the first Poll() (OnPluginUpdate is pumped from
//     ServerPostSimulate, i.e. only with a live map). pisex::IsGameReady() exposes that state to
//     the ported plugin, and every player wrapper in <pisex/players.hpp> checks it first.
//   * timers and the next-frame queue need a game-thread pump that is ours, not the engine's
//     (see <pisex/timers.hpp> for why s2sdk timers are rescheduled from Poll()).
//
// The s2sdk listeners are registered defensively: if the s2sdk plugin (or a single binding) is
// missing, Init() logs and returns false instead of throwing - a plugin that returns Failed from
// OnPluginStart stops every Plugify plugin on the server.

#pragma once

#include <chrono>
#include <cstdint>
#include <functional>
#include <string_view>

namespace pisex {

// Sets the plugin name (config/translations/data dirs) and registers the s2sdk listeners used by
// this library (map start/end, say, ...). Safe to call before a map exists; no client query is
// made here. Returns false when the s2sdk bindings are unavailable.
bool Init(std::string_view pluginName);
// Same, with explicit dirs (empty = derive from the plugify dirs + plugin name).
bool Init(std::string_view pluginName, std::string_view configDir, std::string_view translationsDir);
// Unregisters everything this library registered, removes the remaining timers and drops the
// registries (commands, menus, events, chat listeners, next-frame queue).
void Shutdown();
// Must be called from OnPluginUpdate (game thread, once per frame): pumps the next-frame queue and
// reschedules/kills s2sdk timers. Also marks the game as ready and fires the deferred
// StartupServer callbacks on the first call.
void Poll();

// True once a map is running (from the first Poll or from the engine's map-start callback).
// Every wrapper that could reach a client query checks it.
bool IsGameReady();
// Current map name (empty when no map is running).
std::string_view CurrentMap();

// Set by the plugin when it wants the library to know about map changes (optional; Init already
// registers the s2sdk listeners when they are available).
void OnMapStartNotify();
void OnMapEndNotify();

// --- engine globals ---------------------------------------------------------------------------
//
// The Pisex modules keep `gpGlobals = g_pUtils->GetCGlobalVars()` and read gpGlobals->curtime /
// ->maxClients. s2sdk exposes the same values as functions, so GetCGlobalVars() hands out a
// snapshot struct that is refreshed at the start of every Poll(). Values are therefore up to one
// frame old, which is what the Metamod pointers effectively were as well (they were read between
// engine updates).
struct GlobalVars {
	float curtime = 0.0f;			  // GetGameTime()
	float frametime = 0.0f;			  // GetGameFrameTime()
	float intervalPerTick = 0.0f;	  // GetTickInterval()
	int maxClients = 64;			  // GetMaxClients()
	int tickcount = 0;				  // GetGameTickCount()
	double realtime = 0.0;			  // GetEngineTime()
	float absoluteFrameTime = 0.0f;	  // GetGameFrameTime()
};
GlobalVars* GetCGlobalVars();
// Refreshes the snapshot (called by Poll(); call manually if you read it outside of a frame).
void RefreshGlobalVars();

// --- deferred server-start / map callbacks ----------------------------------------------------
// Registering here rather than running immediately is what makes them safe: every callback fires
// from Poll(), i.e. with a live map and on the game thread.
void RegisterStartupCallback(std::function<void()> callback);
void RegisterMapStartCallback(std::function<void(const char* map)> callback);
void RegisterMapEndCallback(std::function<void()> callback);

} // namespace pisex
