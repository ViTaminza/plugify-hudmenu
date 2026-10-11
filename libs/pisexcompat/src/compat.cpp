#include <pisex/compat.hpp>

#include <pisex/commands.hpp>
#include <pisex/events.hpp>
#include <pisex/menu.hpp>
#include <pisex/output.hpp>
#include <pisex/paths.hpp>
#include <pisex/phrases.hpp>
#include <pisex/players.hpp>
#include <pisex/timers.hpp>

#include <plg/string.hpp>
#include <s2sdk/s2sdk.hpp>

#include <exception>
#include <string>
#include <utility>
#include <vector>

namespace pisex {
namespace {

bool g_initialized = false;
bool g_listenersRegistered = false;
bool g_gameReady = false;
bool g_mapStartPending = false;
bool g_mapStartSeen = false; // an OnMapStart arrived (since Init / the last OnMapEnd)
bool g_mapEndSeen = false;   // an OnMapEnd arrived (since Init)
bool g_startupRan = false;
std::string g_mapName;
GlobalVars g_globalVars;

std::vector<std::function<void()>> g_startupCallbacks;
std::vector<std::function<void(const char*)>> g_mapStartCallbacks;
std::vector<std::function<void()>> g_mapEndCallbacks;

std::string ToString(const plg::string& text) {
	return std::string(text.data(), text.size());
}

void RunSafely(const char* what, const std::function<void()>& callback) {
	if (!callback) {
		return;
	}
	try {
		callback();
	} catch (const std::exception& ex) {
		ErrorLog("pisexcompat: %s callback threw: %s", what, ex.what());
	} catch (...) {
		ErrorLog("pisexcompat: %s callback threw an unknown exception", what);
	}
}

// --- s2sdk listeners -------------------------------------------------------------------------
// Only ever registered from Init() and removed by Shutdown(). They run on the game thread.

void OnMapStartListener() {
	try {
		g_mapStartPending = true;
		g_mapStartSeen = true;
		if (__s2sdk_GetCurrentMap) {
			g_mapName = ToString(s2sdk::GetCurrentMap());
		}
	} catch (...) {
	}
}

void OnMapEndListener() {
	try {
		// From here on - until the next map start - every s2sdk client query is unsafe: the client
		// list is torn down during the level shutdown (a crash: utils::GetClientBySlot reads
		// m_Clients.Element(slot) on the half-destroyed server and segfaults at address 0). The
		// ready flag needs a *new* map start, not just another Poll, see Poll().
		g_gameReady = false;
		g_mapStartPending = false;
		g_mapStartSeen = false;
		g_mapEndSeen = true;
		g_mapName.clear();
		// The engine has already destroyed the menus of every disconnecting client; dropping our
		// registry entries here keeps no state pointing at them (no client/entity call from map
		// end - the sessions are ended through the menu manager only, see CloseAllMenus).
		CloseAllMenus();
		for (const std::function<void()>& callback : g_mapEndCallbacks) {
			RunSafely("map end", callback);
		}
	} catch (...) {
	}
}

bool BindingsAvailable() {
	// A missing s2sdk plugin leaves every binding null: the library then degrades to a no-op
	// instead of crashing on the first call.
	return __s2sdk_IsClientConnected != nullptr && __s2sdk_IsClientInGame != nullptr &&
		   __s2sdk_GetClientName != nullptr && __s2sdk_PrintToChat != nullptr && __s2sdk_PrintToChatAll != nullptr;
}

void RegisterListeners() {
	if (g_listenersRegistered || !__s2sdk_OnMapStart_Register || !__s2sdk_OnMapEnd_Register) {
		return;
	}
	// The register functions return nothing; a failure shows up as the callback never firing, so
	// nothing to check here (the bindings themselves were checked by BindingsAvailable()).
	s2sdk::OnMapStart_Register(&OnMapStartListener);
	s2sdk::OnMapEnd_Register(&OnMapEndListener);
	g_listenersRegistered = true;
}

void UnregisterListeners() {
	if (!g_listenersRegistered) {
		return;
	}
	g_listenersRegistered = false;
	if (__s2sdk_OnMapStart_Unregister) {
		s2sdk::OnMapStart_Unregister(&OnMapStartListener);
	}
	if (__s2sdk_OnMapEnd_Unregister) {
		s2sdk::OnMapEnd_Unregister(&OnMapEndListener);
	}
}

} // namespace

bool Init(std::string_view pluginName) {
	return Init(pluginName, {}, {});
}

bool Init(std::string_view pluginName, std::string_view configDir, std::string_view translationsDir) {
	g_startupRan = false;
	g_gameReady = false;
	g_mapStartPending = false;
	g_mapStartSeen = false;
	g_mapEndSeen = false;
	g_mapName.clear();

	if (!pluginName.empty()) {
		SetPluginName(pluginName);
	}
	if (!configDir.empty()) {
		SetConfigDir(configDir);
	}
	if (!translationsDir.empty()) {
		SetTranslationsDir(translationsDir);
	}

	RefreshChatTriggers();
	RegisterListeners();

	g_initialized = true;
	if (!BindingsAvailable()) {
		ErrorLog("pisexcompat: the s2sdk bindings are not available (is the s2sdk plugin loaded?) - "
				 "pisexcompat runs in no-op mode");
		return false;
	}
	BurnMenuIdZero();
	return true;
}

void Shutdown() {
	try {
		UnregisterListeners();
		RemoveAllCommands();
		RemoveAllEvents();
		RemoveAllPlayerHooks();
		ClearTimers();
		CloseAllMenus();
		g_startupCallbacks.clear();
		g_mapStartCallbacks.clear();
		g_mapEndCallbacks.clear();
		g_mapStartPending = false;
		g_mapStartSeen = false;
		g_mapEndSeen = false;
		g_gameReady = false;
		g_initialized = false;
	} catch (...) {
	}
}

void OnMapStartNotify() {
	OnMapStartListener();
}

void OnMapEndNotify() {
	OnMapEndListener();
}

bool IsGameReady() {
	return g_gameReady;
}

std::string_view CurrentMap() {
	if (g_gameReady && __s2sdk_GetCurrentMap) {
		try {
			g_mapName = ToString(s2sdk::GetCurrentMap());
		} catch (...) {
		}
	}
	return g_mapName;
}

void Poll() {
	// Map lifecycle gate. Client/entity queries are only safe while a map is really up: s2sdk
	// tears its client list down during the level shutdown, so between OnMapEnd and the *next*
	// map start every client call is a crash (utils::GetClientBySlot runs on the half-destroyed
	// server, and Player::SetName dereferences a clientless slot). Granting readiness again on the
	// next Poll would be wrong - the host can pump updates throughout a changelevel - so a new
	// OnMapStart is required. A plugin loaded into an already running map never saw one; its first
	// update is the proof of a running server (the host pumps this from ServerPostSimulate, which
	// only runs with a map up), which is the `!g_mapEndSeen` case.
	if (!g_gameReady && (g_mapStartSeen || !g_mapEndSeen)) {
		g_gameReady = true;
	}
	if (!g_gameReady) {
		// Map change in progress: nothing may touch a client or an entity. The pumps keep
		// running - timers stay parked and are postponed to the first ready frame (timers.cpp),
		// menu requests are dropped/cleared (no client to serve, see CloseAllMenus at map end).
		ProcessMenuRequests();
		ProcessTimers();
		return;
	}

	RefreshGlobalVars();
	PollCommandRegistrations();

	if (!g_initialized) {
		// A plugin that calls Poll() without Init() still gets the timer pump.
		ProcessMenuRequests();
		ProcessTimers();
		return;
	}

	if (!g_startupRan) {
		g_startupRan = true;
		if (__s2sdk_GetCurrentMap) {
			try {
				g_mapName = ToString(s2sdk::GetCurrentMap());
			} catch (...) {
			}
		}
		for (const std::function<void()>& callback : g_startupCallbacks) {
			RunSafely("startup", callback);
		}
		g_mapStartPending = true; // a plugin loaded mid-map gets its map-start hook too
	}

	// Menu changes requested from inside a menu callback (the engine holds the menu manager's lock
	// while it calls us, so they cannot be applied there).
	ProcessMenuRequests();

	if (g_mapStartPending) {
		g_mapStartPending = false;
		// Remove the callbacks registered *by* a map-start callback from the current iteration.
		const std::vector<std::function<void(const char*)>> callbacks = g_mapStartCallbacks;
		for (const std::function<void(const char*)>& callback : callbacks) {
			if (!callback) {
				continue;
			}
			try {
				callback(g_mapName.c_str());
			} catch (const std::exception& ex) {
				ErrorLog("pisexcompat: map start callback threw: %s", ex.what());
			} catch (...) {
				ErrorLog("pisexcompat: map start callback threw an unknown exception");
			}
		}
	}

	ProcessTimers();
}

void RegisterStartupCallback(std::function<void()> callback) {
	if (callback) {
		g_startupCallbacks.push_back(std::move(callback));
	}
}

void RegisterMapStartCallback(std::function<void(const char*)> callback) {
	if (callback) {
		g_mapStartCallbacks.push_back(std::move(callback));
	}
}

void RegisterMapEndCallback(std::function<void()> callback) {
	if (callback) {
		g_mapEndCallbacks.push_back(std::move(callback));
	}
}

GlobalVars* GetCGlobalVars() {
	if (g_globalVars.intervalPerTick == 0.0f) {
		RefreshGlobalVars();
	}
	return &g_globalVars;
}

void RefreshGlobalVars() {
	try {
		if (__s2sdk_GetGameTime) {
			g_globalVars.curtime = s2sdk::GetGameTime();
		}
		if (__s2sdk_GetGameFrameTime) {
			g_globalVars.frametime = s2sdk::GetGameFrameTime();
			g_globalVars.absoluteFrameTime = g_globalVars.frametime;
		}
		if (__s2sdk_GetTickInterval) {
			g_globalVars.intervalPerTick = static_cast<float>(s2sdk::GetTickInterval());
		}
		if (__s2sdk_GetMaxClients) {
			const int maxClients = s2sdk::GetMaxClients();
			if (maxClients > 0 && maxClients <= 64) {
				g_globalVars.maxClients = maxClients;
			}
		}
		if (__s2sdk_GetGameTickCount) {
			g_globalVars.tickcount = s2sdk::GetGameTickCount();
		}
		if (__s2sdk_GetEngineTime) {
			g_globalVars.realtime = s2sdk::GetEngineTime();
		}
	} catch (...) {
	}
}

} // namespace pisex
