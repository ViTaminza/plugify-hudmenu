// pisexcompat — the Pisex menu builder over s2sdk menus.
//
// The ported code keeps its shape:
//
//   Menu hMenu;
//   g_pMenus->SetTitleMenu(hMenu, phrase);
//   g_pMenus->AddItemMenu(hMenu, "kick", display);
//   g_pMenus->SetExitMenu(hMenu, true);
//   g_pMenus->SetCallback(hMenu, [](const char* back, const char* front, int iItem, int iSlot) {
//       if (iItem < 7) { /* item "back" was chosen */ }
//       else if (iItem == 7) { /* exit-back */ }
//   });
//   g_pMenus->DisplayPlayerMenu(hMenu, iSlot);
//
// Item numbers are the Pisex ones: 1..5 for the items of the current page, 7 = exit-back ("back"),
// 9 = exit ("exit"). s2sdk's built-in backends use their own digits (1-7 items, 8 previous page,
// 9 next page, 0 exit) - the trampoline translates the actions back into Pisex numbers, so ported
// callbacks keep working unchanged. Paging itself is handled by the s2sdk backend and does *not*
// call the callback (Pisex called it with ("next","next",8) / ("back","back",7) for page turns).
//
// ITEM_HIDE items are dropped when the menu is created (like Pisex: AddItemMenu ignores iType 0),
// ITEM_DISABLED items are added as s2sdk "Disabled" items and are not selectable.
//
// Which s2sdk menu type a displayed menu gets (ResolveS2sdkMenuTypeName):
//   1. an explicit per-slot SetMenuType(slot, ...) wins (the plugin forced it);
//   2. otherwise the player's own choice is used when the hudmenu plugin is installed - its
//      exported GetClientMenuType(slot) returns "hud"/"wasd"/"button"/"centerhtml"/"chat" from
//      the permissions cookie "Utils.MenuType" (Pisex's "!menu" choice), so every plugin's
//      menus follow what the player picked;
//   3. without hudmenu, the slot's Pisex MenuType is mapped (HUD_LAYOUT -> "hud" and
//      CENTER_WASD -> "wasd" when the matching backend is registered, else "button").
//
// Only the s2sdk menu features are offered: the HUD_LAYOUT/Panorama extras of cs2-menus
// (SetDescriptionMenu, toggles, selects) exist as no-ops or throw-away state - see README.

#pragma once

#include <array>
#include <cstdint>
#include <functional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace pisex {

// cs2-menus item types.
inline constexpr int ITEM_HIDE = 0;
inline constexpr int ITEM_DEFAULT = 1;
inline constexpr int ITEM_DISABLED = 2;

struct Items {
	int iType = ITEM_DEFAULT;
	std::string sBack;
	std::string sText;
};

// cs2-menus MenuType.
enum class MenuType : int {
	CHAT = 0,
	CENTER = 1,
	CENTER_WASD = 2,
	HUD_LAYOUT = 3,
};

// Pisex's MenuCallbackFunc: (back value, front text, item number, slot).
using MenuCallbackFunc = std::function<void(const char* szBack, const char* szFront, int iItem, int iSlot)>;

struct Menu {
	std::string szTitle;
	std::vector<Items> hItems;
	bool bBack = false;
	bool bExit = false;
	MenuCallbackFunc hFunc;
	// HUD_LAYOUT only in Pisex; kept so SetDescriptionMenu() has somewhere to store it.
	std::string szDescription;

	void clear() {
		szTitle.clear();
		hItems.clear();
		bBack = false;
		bExit = false;
		hFunc = nullptr;
		szDescription.clear();
	}
};

// Adds an item (iType ITEM_DEFAULT/ITEM_DISABLED; ITEM_HIDE is ignored, exactly like Pisex).
void AddItemMenu(Menu& hMenu, const char* sBack, const char* sText, int iType = ITEM_DEFAULT);
// Same without the escaping Pisex applies to the display text (for pre-formatted text).
void AddRawItemMenu(Menu& hMenu, const char* sBack, const char* sText, int iType = ITEM_DEFAULT);
void SetTitleMenu(Menu& hMenu, const char* szTitle);
void SetExitMenu(Menu& hMenu, bool bExit);
void SetBackMenu(Menu& hMenu, bool bBack);
void SetCallback(Menu& hMenu, MenuCallbackFunc func);
void SetDescriptionMenu(Menu& hMenu, const char* szDescription);

// Shows the menu to the client. bClose/bReset exist for Pisex compatibility: the s2sdk menu of
// that slot is always replaced (Pisex's "keep the old state" path was only used for page turns,
// which s2sdk does itself).
void DisplayPlayerMenu(Menu& hMenu, int iSlot, bool bClose = true);
void DisplayPlayerMenu(Menu& hMenu, int iSlot, bool bClose, bool bReset);
// Closes whatever menu the client has, without calling the callback (Pisex behaviour).
void ClosePlayerMenu(int iSlot);
// Internal (called by Init): reserves s2sdk menu id 0, see menu.cpp.
void BurnMenuIdZero();
// Closes every open menu of this library (map end / plugin end).
void CloseAllMenus();
bool IsMenuOpen(int iSlot);

// Pisex's escapeString(): % -> %%, \ " \n \r \t and < > escaped for the Panorama layout.
std::string escapeString(const std::string& input);

MenuType GetMenuType(int iSlot);
// Forces this slot's s2sdk menu type: ResolveS2sdkMenuTypeName then ignores the player's own
// "!menu" choice for the slot (Pisex's SetMenuType semantics, kept for module overrides).
void SetMenuType(int iSlot, MenuType type);
// Resets the default for every slot (and clears all per-slot overrides, like the Pisex original
// which overwrote the whole table). Slots without an override follow the players' own choice.
void SetDefaultMenuType(MenuType type);
// True while this slot carries an explicit SetMenuType() override (diagnostics/tests).
bool IsMenuTypeForced(int iSlot);

// Pure part of the type selection, exposed for the tests:
//   forced                 - the slot has an explicit SetMenuType() override
//   type                   - the slot's Pisex MenuType (the default when not forced)
//   playerTypeChoice       - hudmenu's GetClientMenuType() answer, empty when hudmenu is not
//                            installed; must be "hud", "wasd", "button", "centerhtml" or "chat"
//   hudTypeRegistered      - the "hud" s2sdk menu type is registered
//   wasdTypeRegistered     - the "wasd" s2sdk menu type is registered
// Returns one of the registered s2sdk type names (the returned view is a literal or points
// into playerTypeChoice).
std::string_view ResolveS2sdkMenuTypeName(bool forced, MenuType type, std::string_view playerTypeChoice,
										  bool hudTypeRegistered, bool wasdTypeRegistered);
// Seconds before an open menu closes by itself (cs2-menus core.ini "MenuTime", default 60).
void SetMenuTimeout(int seconds);
int MenuTimeout();

// Applies the menu changes a callback asked for (pisex::Poll() calls this). A menu handler runs
// inside s2sdk's menu manager (under its recursive mutex, so no deadlock); the hazard is
// re-entrancy: DestroyMenu ends the menu for every viewer and calls the handler's Cancel and End
// again while the outer handler is still on the stack (ref/s2sdk-src menu_manager.cpp
// DestroyMenu/EndClientMenu). So DisplayPlayerMenu() and ClosePlayerMenu() *from inside a
// callback* queue the request and it is executed here, one frame later. Calls from anywhere else (commands, timers, event handlers) are applied immediately.
void ProcessMenuRequests();

} // namespace pisex
