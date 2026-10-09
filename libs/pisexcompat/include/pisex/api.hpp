// pisexcompat — the Pisex-shaped API objects.
//
// A ported plugin keeps the exact call sites it had with Metamod:
//
//   #include <pisex/pisex.hpp>
//   using namespace pisex;               // makes g_pUtils/g_pMenus/g_pPlayers visible
//   ...
//   g_pUtils->PrintToChat(iSlot, phrase, name);
//   g_pMenus->AddItemMenu(hMenu, "kick", display);
//   g_pPlayers->GetSteamID64(iSlot);
//
// The three objects forward to the free functions of the headers next to this one (same names,
// same behaviour). Nothing else about the Pisex interfaces is emulated: a plugin that needs a
// functionality s2sdk does not have keeps failing loudly at compile time instead of silently at
// runtime. The unused ones are listed in README.md under "not covered".

#pragma once

#include <chrono>
#include <functional>
#include <string>
#include <vector>

#include <pisex/commands.hpp>
#include <pisex/compat.hpp>
#include <pisex/events.hpp>
#include <pisex/menu.hpp>
#include <pisex/output.hpp>
#include <pisex/phrases.hpp>
#include <pisex/players.hpp>
#include <pisex/timers.hpp>

namespace pisex {

// Deferred "the server started" callback (Pisex's IUtilsApi::StartupServer, whose listener fires
// once per server start). pisexcompat runs it on the first Poll(), i.e. with a map loaded, because
// the Pisex startup handlers load configs and open databases.
using StartupCallback = std::function<void()>;
using MapStartCallback = std::function<void(const char* szMap)>;

class UtilsApi {
public:
	// --- messages ----------------------------------------------------------------------------
	void PrintToChat(int iSlot, const char* msg, ...) __attribute__((format(printf, 3, 4)));
	void PrintToChatAll(const char* msg, ...) __attribute__((format(printf, 2, 3)));
	void PrintToConsole(int iSlot, const char* msg, ...) __attribute__((format(printf, 3, 4)));
	void PrintToConsoleAll(const char* msg, ...) __attribute__((format(printf, 2, 3)));
	void PrintToCenter(int iSlot, const char* msg, ...) __attribute__((format(printf, 3, 4)));
	void PrintToCenterAll(const char* msg, ...) __attribute__((format(printf, 2, 3)));
	void PrintToCenterHtml(int iSlot, int iDuration, const char* msg, ...) __attribute__((format(printf, 4, 5)));
	void PrintToCenterHtmlAll(int iDuration, const char* msg, ...) __attribute__((format(printf, 3, 4)));
	void PrintToAlert(int iSlot, const char* msg, ...) __attribute__((format(printf, 3, 4)));
	void PrintToAlertAll(const char* msg, ...) __attribute__((format(printf, 2, 3)));
	void ErrorLog(const char* msg, ...) __attribute__((format(printf, 2, 3)));
	void LogToFile(const char* szFile, const char* szText, ...) __attribute__((format(printf, 3, 4)));

	// --- commands / events -------------------------------------------------------------------
	// Pisex's PluginId parameter is gone: the library owns every registration and drops them all
	// in pisex::Shutdown().
	void RegCommand(const std::vector<std::string>& console, const std::vector<std::string>& chat,
					const CommandCallback& callback);
	void AddChatListenerPre(const CommandCallbackPre& callback);
	void HookEvent(const char* sName, const EventCallback& callback);

	// --- timers ------------------------------------------------------------------------------
	CTimer* CreateTimer(float flInterval, std::function<float()> func);
	void RemoveTimer(CTimer* timer);
	void NextFrame(std::function<void()> fn);

	// --- lifecycle / info --------------------------------------------------------------------
	// Runs fn once, on the first update with a map loaded (Pisex: on server startup).
	void StartupServer(StartupCallback fn);
	void MapStartHook(MapStartCallback fn);
	void MapEndHook(StartupCallback fn);
	// Loads <translations dir>/<file>.txt into pisex::g_translations (Pisex's IUtilsApi method).
	void LoadTranslations(const char* file);
	const char* GetLanguage();
	const char* GetVersion();

	// --- engine ------------------------------------------------------------------------------
	GlobalVars* GetCGlobalVars();
	// s2sdk has no entity-system pointer with an engine-defined layout: these return nullptr.
	// Use pisex/schema.hpp (or the s2sdk entity functions) instead of iterating the entity system.
	void* GetCGameEntitySystem();
	void* GetCEntitySystem();

	// --- helpers (not part of IUtilsApi) ------------------------------------------------------
	std::string Colorize(const std::string& text);
};

class MenusApi {
public:
	void AddItemMenu(Menu& hMenu, const char* sBack, const char* sText, int iType = ITEM_DEFAULT);
	void AddRawItemMenu(Menu& hMenu, const char* sBack, const char* sText, int iType = ITEM_DEFAULT);
	void SetTitleMenu(Menu& hMenu, const char* szTitle);
	void SetExitMenu(Menu& hMenu, bool bExit);
	void SetBackMenu(Menu& hMenu, bool bBack);
	void SetCallback(Menu& hMenu, MenuCallbackFunc func);
	void SetDescriptionMenu(Menu& hMenu, const char* szDescription);
	void DisplayPlayerMenu(Menu& hMenu, int iSlot, bool bClose = true);
	void DisplayPlayerMenu(Menu& hMenu, int iSlot, bool bClose, bool bReset);
	void ClosePlayerMenu(int iSlot);
	bool IsMenuOpen(int iSlot);
	std::string escapeString(const std::string& input);
	MenuType GetMenuType(int iSlot);
	void SetMenuType(int iSlot, MenuType type);
	void SetMenuTimeout(int iSeconds);
};

class PlayersApi {
public:
	bool IsFakeClient(int iSlot);
	bool IsConnected(int iSlot);
	bool IsInGame(int iSlot);
	bool IsAuthenticated(int iSlot);
	bool IsAlive(int iSlot);
	void HookOnClientAuthorized(const OnClientAuthorizedCallback& callback);
	uint64_t GetSteamID64(int iSlot);
	const char* GetSteamID(int iSlot);
	const char* GetIpAddress(int iSlot);
	const char* GetPlayerName(int iSlot);
	void SetPlayerName(int iSlot, const char* szName);
	const char* GetClientLanguage(int iSlot);
	int FindPlayer(uint64_t iSteamID64);
	int FindPlayer(const char* szName);
	int GetHealth(int iSlot);
	int GetArmor(int iSlot);
	int GetMoney(int iSlot);
	int GetTeam(int iSlot);
	void ChangeTeam(int iSlot, int iNewTeam);
	void SwitchTeam(int iSlot, int iNewTeam);
	void Respawn(int iSlot);
	void CommitSuicide(int iSlot, bool bExplode, bool bForce);
	void SetMoveType(int iSlot, int moveType);
	void RemoveWeapons(int iSlot);
};

// The Pisex globals. They are non-null from program start, so a plugin may use them in any
// callback as long as pisex::Init() has run before the call site (the printers themselves are
// no-ops before a map exists).
extern UtilsApi* const g_pUtils;
extern MenusApi* const g_pMenus;
extern PlayersApi* const g_pPlayers;

// The instances behind the pointers.
UtilsApi& Utils();
MenusApi& Menus();
PlayersApi& Players();

} // namespace pisex
