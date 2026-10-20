#include <pisex/menu.hpp>

#include <pisex/compat.hpp>
#include <pisex/output.hpp>

#include <hudmenu/hudmenu.hpp>
#include <plg/string.hpp>
#include <s2sdk/s2sdk.hpp>

#include <array>
#include <cstddef>
#include <exception>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

namespace pisex {
namespace {

constexpr int kSlots = 64;
// cs2-menus shows five items per chat page.
constexpr int kItemsPerPage = 5;

struct OpenMenu {
	s2sdk::MenuId id = 0;
	std::vector<Items> items; // only the items that were added (ITEM_HIDE dropped)
	MenuCallbackFunc callback;
	std::string title;
};

std::array<OpenMenu, kSlots> g_open;
// True while a menu handler is running: the engine calls handlers with the menu manager's lock
// held, so any menu mutation has to be deferred to ProcessMenuRequests().
bool g_inHandler = false;

struct PendingShow {
	int slot = -1;
	Menu menu;
};
std::vector<PendingShow> g_pendingShow;
std::vector<int> g_pendingClose;
std::vector<s2sdk::MenuId> g_pendingDestroy;

// Default menu type: HUD_LAYOUT, which ResolveS2sdkMenuTypeName() maps to the "hud" Panorama
// backend (plugins/hudmenu) when that is registered and to the WASD "button" type otherwise -
// both are on-screen, dead-player-usable presentations. Without an explicit SetMenuType()
// override the players' own "!menu" choice (hudmenu) takes precedence, see the resolver.
MenuType g_defaultType = MenuType::HUD_LAYOUT;
std::array<MenuType, kSlots> g_slotType = [] {
	std::array<MenuType, kSlots> types{};
	types.fill(MenuType::HUD_LAYOUT); // same as g_defaultType; a value-initialized array would be CHAT (0)
	return types;
}();
// Slots with an explicit SetMenuType(slot, ...) override (the plugin forced the type there).
std::array<bool, kSlots> g_slotForced{};
int g_menuTimeout = 60;

void ClearSlot(int slot) {
	g_open[static_cast<std::size_t>(slot)] = OpenMenu{};
}

void DestroySlotMenu(int slot) {
	OpenMenu& state = g_open[static_cast<std::size_t>(slot)];
	const s2sdk::MenuId id = state.id;
	ClearSlot(slot); // forget it first: the engine's Cancel/End callbacks must not re-enter the plugin
	if (id != 0 && __s2sdk_DestroyMenu) {
		try {
			s2sdk::DestroyMenu(id);
		} catch (...) {
		}
	}
}

// The "hud" backend (plugins/hudmenu) is cs2-menus' HUD_LAYOUT: a Panorama on-screen menu
// driven by mouse clicks, usable while dead. Registered only when the game signatures, the
// CUtlString helpers and the click hook all resolved.
bool IsHudTypeRegistered() {
	if (!__s2sdk_IsMenuTypeRegistered) {
		return false;
	}
	try {
		return s2sdk::IsMenuTypeRegistered("hud");
	} catch (...) {
		return false;
	}
}

// The "wasd" backend (plugins/hudmenu) is cs2-menus' CENTER_WASD: the center-HTML menu with
// the W/S/A/D/E/R controls and Pisex's per-frame refresh. Without it s2sdk's own "button"
// type is the closest equivalent.
bool IsWasdTypeRegistered() {
	if (!__s2sdk_IsMenuTypeRegistered) {
		return false;
	}
	try {
		return s2sdk::IsMenuTypeRegistered("wasd");
	} catch (...) {
		return false;
	}
}

// Maps a Pisex MenuType onto an s2sdk type name (used when no player choice applies).
std::string_view MappedMenuTypeName(MenuType type, bool hudTypeRegistered, bool wasdTypeRegistered) {
	switch (type) {
	case MenuType::CHAT: return "chat";
	case MenuType::CENTER: return "centerhtml";
	// Pisex's CENTER_WASD: the hudmenu "wasd" backend; s2sdk's built-in "button" (a WASD-driven
	// center HTML panel) is the fallback while it is not registered.
	case MenuType::CENTER_WASD: return wasdTypeRegistered ? "wasd" : "button";
	case MenuType::HUD_LAYOUT: return hudTypeRegistered ? "hud" : "button"; // without the backend, WASD is the closest
	}
	return "chat";
}

// The player's own "!menu" choice, asked from the hudmenu plugin. Empty when hudmenu is not
// installed (binding null), the slot has no live client or anything went wrong - the caller
// then falls back to the slot's Pisex MenuType.
std::string PlayerTypeChoice(int slot) {
	if (!__hudmenu_GetClientMenuType) {
		return {};
	}
	try {
		const plg::string answer = hudmenu::GetClientMenuType(slot);
		return std::string(std::string_view(answer));
	} catch (...) {
		return {};
	}
}

// An ids display session ended (Cancel or End) and still has to go to s2sdk::DestroyMenu. s2sdk's
// menus guide is explicit about it (call DestroyMenu(id) from your handler's End case, otherwise
// every menu you display leaks for the lifetime of the plugin) and s2sdk does not do it for us:
// its EndClientMenu() only clears the client state and DestroyMenu() is only ever called by a
// plugin. Without this queue every timed-out / exited / disconnected display leaves its MenuData
// in s2sdk's menu table forever.
void QueueMenuDestroy(s2sdk::MenuId id) {
	if (id == 0) {
		return; // s2sdk's "no menu"
	}
	for (const s2sdk::MenuId queued : g_pendingDestroy) {
		if (queued == id) {
			return; // Cancel and End both report the same session end: destroy it once
		}
	}
	g_pendingDestroy.push_back(id);
}

// True while the id is still a slot's registered menu or still displayed to a client. pisexcompat
// creates one menu per display, but s2sdk menus are shared objects: a menu that another session
// still uses must not be destroyed here - that session's own end queues it again.
bool MenuIdStillUsed(s2sdk::MenuId id) {
	for (const OpenMenu& state : g_open) {
		if (state.id == id) {
			return true;
		}
	}
	if (!IsGameReady() || !__s2sdk_GetClientMenu) {
		return false; // no map: nobody can be displaying it
	}
	for (int slot = 0; slot < kSlots; ++slot) {
		try {
			if (s2sdk::GetClientMenu(slot) == id) {
				return true;
			}
		} catch (...) {
		}
	}
	return false;
}

// Runs outside the menu manager's lock (from ProcessMenuRequests()/CloseAllMenus()), never from a
// handler - s2sdk::DestroyMenu re-enters the menu manager and calls the affected handlers.
// An id that another display session still uses stays queued and is re-checked on a later frame
// (dropping it would leak that menu for good: that session's end is not guaranteed to pass through
// our registry). `force` is for the map end / Shutdown path, where every display is over anyway
// and the plugin must not leave s2sdk menus pointing at its handlers.
void DestroyQueuedMenus(bool force) {
	if (g_pendingDestroy.empty()) {
		return;
	}
	std::vector<s2sdk::MenuId> ids = std::move(g_pendingDestroy);
	g_pendingDestroy.clear();
	if (!__s2sdk_DestroyMenu) {
		return;
	}
	for (const s2sdk::MenuId id : ids) {
		if (!force && MenuIdStillUsed(id)) {
			g_pendingDestroy.push_back(id); // still displayed somewhere: retry next frame
			continue;
		}
		try {
			s2sdk::DestroyMenu(id);
		} catch (...) {
		}
	}
}

// A menu that was created but never registered (an exception between CreateMenu and the registry
// write, or a refused display): nothing tracks it, so it is freed right here - this never runs
// inside a handler, so the direct DestroyMenu is safe.
void DestroyUnregisteredMenu(int slot, s2sdk::MenuId id) {
	ClearSlot(slot);
	if (id != 0 && __s2sdk_DestroyMenu) {
		try {
			s2sdk::DestroyMenu(id);
		} catch (...) {
		}
	}
}

// Called by the engine for Start/Select/Cancel/End. No plugin callback may be called with a
// dangling registry entry, and no exception may escape into the engine.
void MenuHandlerTrampoline(s2sdk::MenuId id, s2sdk::MenuAction action, int32_t slot, int32_t param) {
	// Everything a callback does goes through the deferred queue (see g_inHandler). The flag is
	// saved/restored rather than cleared, so a handler that re-enters (SelectMenuItem on the same
	// menu) does not clear it for the outer one.
	struct HandlerScope {
		bool previous;
		HandlerScope() : previous(g_inHandler) { g_inHandler = true; }
		~HandlerScope() { g_inHandler = previous; }
	} scope;
	try {
		if (slot < 0 || slot >= kSlots) {
			return;
		}
		OpenMenu& state = g_open[static_cast<std::size_t>(slot)];
		if (state.id != id) {
			return; // stale (the plugin already closed/replaced it)
		}

		switch (action) {
		case s2sdk::MenuAction::Select: {
			if (param < 0 || static_cast<std::size_t>(param) >= state.items.size()) {
				return;
			}
			const Items item = state.items[static_cast<std::size_t>(param)];
			if (item.iType != ITEM_DEFAULT) {
				return;
			}
			// s2sdk digits are 1..7 for the page items; Pisex numbers the five items of a page
			// 1..5. The menu is paginated by kItemsPerPage (see DisplayPlayerMenu), so the page
			// offsets are multiples of it and the digit is the remainder plus one - no s2sdk call
			// is needed here (and none may be made, see g_inHandler).
			const int button = (param % kItemsPerPage) + 1;
			const MenuCallbackFunc callback = state.callback; // copy: the callback may redisplay/close
			if (callback) {
				callback(item.sBack.c_str(), item.sText.c_str(), button, slot);
			}
			break;
		}
		case s2sdk::MenuAction::Cancel: {
			const auto reason = static_cast<s2sdk::MenuCancelReason>(param);
			const MenuCallbackFunc callback = state.callback;
			// The display session is over (End follows it, see the End case); the id has to be
			// destroyed or its MenuData leaks for the process lifetime.
			QueueMenuDestroy(id);
			ClearSlot(slot);
			// Pisex's exit/back values; a timeout or a disconnect just drops the menu.
			if (reason == s2sdk::MenuCancelReason::Exit) {
				if (callback) {
					callback("exit", "exit", 9, slot);
				}
			} else if (reason == s2sdk::MenuCancelReason::ExitBack) {
				if (callback) {
					callback("back", "back", 7, slot);
				}
			}
			break;
		}
		case s2sdk::MenuAction::End:
			// Reached for timeout/disconnect/destroyed (Cancel already ran for the first ones; the
			// queue dedupes). The session is fully closed now: hand the menu to the deferred
			// destroy queue (no s2sdk call may happen here - the handler runs under the menu
			// manager's lock).
			QueueMenuDestroy(id);
			ClearSlot(slot);
			break;
		case s2sdk::MenuAction::Start:
			break;
		}
	} catch (const std::exception& ex) {
		ErrorLog("pisexcompat: menu handler threw: %s", ex.what());
	} catch (...) {
		ErrorLog("pisexcompat: menu handler threw an unknown exception");
	}
}

} // namespace

std::string_view ResolveS2sdkMenuTypeName(bool forced, MenuType type, std::string_view playerTypeChoice,
										  bool hudTypeRegistered, bool wasdTypeRegistered) {
	if (!forced && !playerTypeChoice.empty()) {
		// hudmenu's answer: only the known names are accepted, and "hud"/"wasd" only while the
		// matching backend is really registered (a stale/foreign answer falls through to the
		// mapped type).
		if (playerTypeChoice == "chat" || playerTypeChoice == "centerhtml" || playerTypeChoice == "button") {
			return playerTypeChoice;
		}
		if (playerTypeChoice == "hud") {
			return hudTypeRegistered ? "hud" : "button";
		}
		if (playerTypeChoice == "wasd") {
			return wasdTypeRegistered ? "wasd" : "button";
		}
	}
	return MappedMenuTypeName(type, hudTypeRegistered, wasdTypeRegistered);
}

void AddItemMenu(Menu& hMenu, const char* sBack, const char* sText, int iType) {
	// Deliberately *not* escaped: cs2-menus escaped the item text because its Panorama layout is
	// printf- and XML-formatted, the s2sdk backends take plain text. Porting note: drop the
	// escapeString() calls around item texts, or the client sees "&lt;" and "%%".
	AddRawItemMenu(hMenu, sBack, sText, iType);
}

void AddRawItemMenu(Menu& hMenu, const char* sBack, const char* sText, int iType) {
	if (iType == ITEM_HIDE) {
		return; // Pisex drops hidden items before displaying
	}
	Items item;
	item.iType = iType;
	item.sBack = sBack ? sBack : "";
	item.sText = sText ? sText : "";
	hMenu.hItems.push_back(std::move(item));
}

void SetTitleMenu(Menu& hMenu, const char* szTitle) {
	hMenu.szTitle = szTitle ? szTitle : "";
}

void SetExitMenu(Menu& hMenu, bool bExit) {
	hMenu.bExit = bExit;
}

void SetBackMenu(Menu& hMenu, bool bBack) {
	hMenu.bBack = bBack;
}

void SetCallback(Menu& hMenu, MenuCallbackFunc func) {
	hMenu.hFunc = std::move(func);
}

void SetDescriptionMenu(Menu& hMenu, const char* szDescription) {
	hMenu.szDescription = szDescription ? szDescription : "";
}

void DisplayPlayerMenu(Menu& hMenu, int iSlot, bool bClose) {
	DisplayPlayerMenu(hMenu, iSlot, bClose, true);
}

void DisplayPlayerMenu(Menu& hMenu, int iSlot, bool bClose, bool bReset) {
	(void)bClose;
	(void)bReset;
	if (iSlot < 0 || iSlot >= kSlots) {
		return;
	}
	if (!IsGameReady() || !__s2sdk_CreateMenu || !__s2sdk_AddMenuItem || !__s2sdk_DisplayMenu) {
		// No map (yet) means no client to show it to; the display path would also dereference
		// gpGlobals, which s2sdk only fills in on server start.
		return;
	}
	if (g_inHandler) {
		// Called from a menu callback: queue it (the menu manager's lock is held right now).
		g_pendingShow.push_back(PendingShow{iSlot, hMenu});
		return;
	}
	s2sdk::MenuId id = 0;
	try {
		// Replace whatever this client had open (Pisex's bClose/bReset pair behaved the same way
		// for a fresh menu).
		DestroySlotMenu(iSlot);

		// An explicit SetMenuType() override wins; otherwise the player's own choice from
		// hudmenu (no-op when the plugin is not installed). See ResolveS2sdkMenuTypeName.
		const bool forced = g_slotForced[static_cast<std::size_t>(iSlot)];
		const std::string playerChoice = forced ? std::string() : PlayerTypeChoice(iSlot);
		const std::string_view typeName =
			ResolveS2sdkMenuTypeName(forced, g_slotType[static_cast<std::size_t>(iSlot)], playerChoice,
									 IsHudTypeRegistered(), IsWasdTypeRegistered());
		id = s2sdk::CreateMenu(plg::string(hMenu.szTitle), &MenuHandlerTrampoline,
							   plg::string(typeName));
		if (id == 0) {
			ErrorLog("pisexcompat: s2sdk refused to create the menu for slot %d", iSlot);
			return;
		}

		OpenMenu state;
		state.id = id;
		state.callback = hMenu.hFunc;
		state.title = hMenu.szTitle;

		for (const Items& item : hMenu.hItems) {
			const s2sdk::MenuItemStyle style =
				item.iType == ITEM_DISABLED ? s2sdk::MenuItemStyle::Disabled : s2sdk::MenuItemStyle::Default;
			s2sdk::AddMenuItem(id, plg::string(item.sBack), plg::string(item.sText), style);
			state.items.push_back(item); // index-aligned with the s2sdk item list
		}

		if (__s2sdk_SetMenuPagination) {
			s2sdk::SetMenuPagination(id, kItemsPerPage); // chat pages of 5, like cs2-menus
		}
		if (__s2sdk_SetMenuExitButton) {
			s2sdk::SetMenuExitButton(id, hMenu.bExit);
		}
		if (__s2sdk_SetMenuExitBackButton) {
			s2sdk::SetMenuExitBackButton(id, hMenu.bBack);
		}
		if (__s2sdk_SetMenuCloseOnSelect) {
			// Pisex keeps the menu open after a selection; the callback decides what happens next.
			s2sdk::SetMenuCloseOnSelect(id, false);
		}

		g_open[static_cast<std::size_t>(iSlot)] = std::move(state);

		if (!s2sdk::DisplayMenu(id, iSlot, g_menuTimeout)) {
			ErrorLog("pisexcompat: s2sdk could not display the menu on slot %d", iSlot);
			DestroyUnregisteredMenu(iSlot, id);
		}
	} catch (const std::exception& ex) {
		ErrorLog("pisexcompat: DisplayPlayerMenu failed: %s", ex.what());
		// The menu may already exist (an exception after CreateMenu): it is not registered, so
		// nothing else would ever destroy it.
		DestroyUnregisteredMenu(iSlot, id);
	} catch (...) {
		ErrorLog("pisexcompat: DisplayPlayerMenu failed with an unknown exception");
		DestroyUnregisteredMenu(iSlot, id);
	}
}

void ClosePlayerMenu(int iSlot) {
	if (iSlot < 0 || iSlot >= kSlots) {
		return;
	}
	if (g_inHandler) {
		g_pendingClose.push_back(iSlot); // see DisplayPlayerMenu
		return;
	}
	const bool wasOpen = g_open[static_cast<std::size_t>(iSlot)].id != 0;
	DestroySlotMenu(iSlot);
	if (wasOpen && __s2sdk_CancelClientMenu) {
		try {
			s2sdk::CancelClientMenu(iSlot, s2sdk::MenuCancelReason::Exit);
		} catch (...) {
		}
	}
}

void CloseAllMenus() {
	g_pendingShow.clear();
	g_pendingClose.clear();
	if (IsGameReady()) {
		for (int slot = 0; slot < kSlots; ++slot) {
			if (g_open[static_cast<std::size_t>(slot)].id != 0) {
				DestroySlotMenu(slot);
			}
		}
	} else {
		// Map end: no client/entity call may happen from here. DestroyMenu() is only safe for a
		// menu nobody displays - it cancels a viewer through the menu type backend (PrintHtmlCentre,
		// hudmenu's HideForSlot), all of which reach the client layer that is being torn down.
		// Ending the session first with the Disconnect reason is s2sdk's own teardown for a client
		// that is gone: it skips the backend close, clears the manager's state and runs our handler,
		// which only queues the destroy - the drain below then frees the menu with no viewer left.
		for (int slot = 0; slot < kSlots; ++slot) {
			const s2sdk::MenuId id = g_open[static_cast<std::size_t>(slot)].id;
			if (id == 0) {
				continue;
			}
			if (__s2sdk_GetClientMenu && s2sdk::GetClientMenu(slot) == id) {
				if (__s2sdk_CancelClientMenu) {
					try {
						s2sdk::CancelClientMenu(slot, s2sdk::MenuCancelReason::Disconnect);
					} catch (...) {
					}
				}
			} else {
				QueueMenuDestroy(id); // nobody displays it: destroyed below without a backend call
			}
			ClearSlot(slot); // in case the handler did not run (id no longer in the manager)
		}
	}
	// Menus whose display already ended but whose destroy is still queued (map end / Shutdown):
	// without this they would sit in s2sdk's m_menuInsts until the process exits. Forced: the
	// plugin is going away, so nothing may be left pointing at its handlers.
	DestroyQueuedMenus(true);
}

void ProcessMenuRequests() {
	if (g_pendingShow.empty() && g_pendingClose.empty() && g_pendingDestroy.empty()) {
		return;
	}
	// A callback may have queued another request while these are applied, so take a snapshot and
	// keep the rest for the next frame.
	std::vector<PendingShow> shows = std::move(g_pendingShow);
	g_pendingShow.clear();
	std::vector<int> closes = std::move(g_pendingClose);
	g_pendingClose.clear();

	for (const int slot : closes) {
		ClosePlayerMenu(slot); // no longer inside a handler, so it runs immediately
	}
	for (const PendingShow& show : shows) {
		Menu menu = show.menu; // DisplayPlayerMenu may queue another show for the same slot
		DisplayPlayerMenu(menu, show.slot);
	}
	// Sessions that ended since the last frame (timeout, exit, disconnect, End): destroy them
	// here, outside the menu manager's lock and after the replacements above.
	DestroyQueuedMenus(false);
}

bool IsMenuOpen(int iSlot) {
	if (iSlot < 0 || iSlot >= kSlots) {
		return false;
	}
	const s2sdk::MenuId id = g_open[static_cast<std::size_t>(iSlot)].id;
	if (id == 0 || !__s2sdk_GetClientMenu) {
		return false;
	}
	try {
		return s2sdk::GetClientMenu(iSlot) == id;
	} catch (...) {
		return false;
	}
}

std::string escapeString(const std::string& input) {
	std::string escaped;
	escaped.reserve(input.size());
	for (const char c : input) {
		switch (c) {
		case '\\': escaped += "\\\\"; break;
		case '"': escaped += "\\\""; break;
		case '\n': escaped += "\\n"; break;
		case '\r': escaped += "\\r"; break;
		case '\t': escaped += "\\t"; break;
		case '<': escaped += "&lt;"; break;
		case '>': escaped += "&gt;"; break;
		case '%': escaped += "%%"; break;
		default: escaped += c; break;
		}
	}
	return escaped;
}

MenuType GetMenuType(int iSlot) {
	if (iSlot < 0 || iSlot >= kSlots) {
		return g_defaultType;
	}
	return g_slotType[static_cast<std::size_t>(iSlot)];
}

void SetMenuType(int iSlot, MenuType type) {
	if (iSlot < 0 || iSlot >= kSlots) {
		return;
	}
	g_slotType[static_cast<std::size_t>(iSlot)] = type;
	g_slotForced[static_cast<std::size_t>(iSlot)] = true; // explicit override: beats the player's choice
}

void SetDefaultMenuType(MenuType type) {
	g_defaultType = type;
	for (MenuType& slotType : g_slotType) {
		slotType = type;
	}
	g_slotForced.fill(false); // the Pisex original replaced the whole table; overrides reset with it
}

bool IsMenuTypeForced(int iSlot) {
	if (iSlot < 0 || iSlot >= kSlots) {
		return false;
	}
	return g_slotForced[static_cast<std::size_t>(iSlot)];
}

void SetMenuTimeout(int seconds) {
	g_menuTimeout = seconds;
}

int MenuTimeout() {
	return g_menuTimeout;
}

// s2sdk's MenuManager starts ids at 0 but also uses 0 for "no menu" (ClientMenuState::id{}), so
// the first menu created in the process could never be shown/tracked. Create and keep one dummy
// menu if we got id 0 (cheap; done once per process by whichever plugin runs first).
void BurnMenuIdZero() {
	if (!__s2sdk_CreateMenu) {
		return;
	}
	try {
		const s2sdk::MenuId id = s2sdk::CreateMenu(plg::string("pisexcompat:reserved-id-0"), &MenuHandlerTrampoline,
												   plg::string("chat"));
		if (id != 0 && __s2sdk_DestroyMenu) {
			s2sdk::DestroyMenu(id); // id 0 was already taken elsewhere: nothing to keep
		}
	} catch (...) {
	}
}

} // namespace pisex
