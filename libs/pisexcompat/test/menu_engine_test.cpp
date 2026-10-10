// pisexcompat menu test — drives the real menu layer with a fake s2sdk menu manager.
//
// The rule under test (s2sdk's menus guide: always destroy your menus - call DestroyMenu(id) from
// your handler's End case, otherwise every menu you display leaks for the lifetime of the
// plugin): s2sdk's EndClientMenu() only clears the client state, so a menu whose display ends on
// its own (exit button, timeout, disconnect) has to be destroyed by us — from outside the handler,
// which runs under the menu manager's recursive mutex and would otherwise re-enter the plugin.
//
// The fake mimics s2sdk closely enough to count: CreateMenu/DestroyMenu/AddMenuItem/DisplayMenu/
// GetClientMenu/CancelClientMenu, the handler dispatch order (Cancel then End, End always last)
// and DestroyMenu ending every client session that still shows the menu. Run by ../test.sh.

#include <pisex/compat.hpp> // Poll(): the deferred menu pump
#include <pisex/menu.hpp>

#include <plg/plugin.hpp>

#include <s2sdk/s2sdk.hpp>

#include <array>
#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

// A real plugin gets these from PLUGIFY_PLUGIN; the test leaves them null (no plugify module).
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

// --- the fake s2sdk menu manager ---------------------------------------------------------------

constexpr int kSlots = 64;

struct FakeMenu {
	s2sdk::MenuId id = 0;
	s2sdk::MenuHandlerCallback handler = nullptr;
	std::vector<std::string> items;
};

std::vector<FakeMenu> g_menus;
std::array<s2sdk::MenuId, kSlots> g_displayed{};
s2sdk::MenuId g_nextMenuId = 1;
bool g_displaySucceeds = true;

int g_createCalls = 0;
int g_destroyCalls = 0;
int g_destroysInsideHandler = 0;
std::vector<s2sdk::MenuId> g_destroyedIds;
int g_handlerDepth = 0;

const FakeMenu* FindMenu(s2sdk::MenuId id) {
	for (const FakeMenu& menu : g_menus) {
		if (menu.id == id) {
			return &menu;
		}
	}
	return nullptr;
}

void CallHandler(s2sdk::MenuId id, s2sdk::MenuAction action, int32_t slot, int32_t param) {
	const FakeMenu* menu = FindMenu(id);
	if (!menu || !menu->handler) {
		return;
	}
	++g_handlerDepth;
	try {
		menu->handler(id, action, slot, param);
	} catch (...) {
	}
	--g_handlerDepth;
}

s2sdk::MenuId FakeCreateMenu(const plg::string& title, s2sdk::MenuHandlerCallback handler, const plg::string& type) {
	(void)title;
	(void)type;
	++g_createCalls;
	FakeMenu menu;
	menu.id = g_nextMenuId++;
	menu.handler = handler;
	g_menus.push_back(menu);
	return menu.id;
}

// Like s2sdk's DestroyMenu: ends every client session that shows the menu (Cancel + End handler
// calls), then drops the MenuData. Only a plugin ever calls it - nothing in s2sdk does.
bool FakeDestroyMenu(s2sdk::MenuId id) {
	++g_destroyCalls;
	if (g_handlerDepth > 0) {
		++g_destroysInsideHandler;
	}
	for (auto it = g_menus.begin(); it != g_menus.end(); ++it) {
		if (it->id != id) {
			continue;
		}
		for (int slot = 0; slot < kSlots; ++slot) {
			if (g_displayed[static_cast<std::size_t>(slot)] == id) {
				g_displayed[static_cast<std::size_t>(slot)] = 0;
				CallHandler(id, s2sdk::MenuAction::Cancel, slot, static_cast<int32_t>(s2sdk::MenuCancelReason::Destroyed));
				CallHandler(id, s2sdk::MenuAction::End, slot, 0);
			}
		}
		g_menus.erase(it);
		g_destroyedIds.push_back(id);
		return true;
	}
	return false;
}

int32_t FakeAddMenuItem(s2sdk::MenuId id, const plg::string& info, const plg::string& display, s2sdk::MenuItemStyle style) {
	(void)style;
	for (FakeMenu& menu : g_menus) {
		if (menu.id == id) {
			menu.items.push_back(std::string(display.data(), display.size()));
			(void)info;
			return static_cast<int32_t>(menu.items.size()) - 1;
		}
	}
	return -1;
}

bool FakeDisplayMenu(s2sdk::MenuId id, int32_t slot, int32_t time) {
	(void)time;
	if (!g_displaySucceeds || !FindMenu(id) || slot < 0 || slot >= kSlots) {
		return false;
	}
	g_displayed[static_cast<std::size_t>(slot)] = id;
	return true;
}

s2sdk::MenuId FakeGetClientMenu(int32_t slot) {
	return (slot >= 0 && slot < kSlots) ? g_displayed[static_cast<std::size_t>(slot)] : 0;
}

// The engine ending a display on its own: timeout, disconnect or the exit button. s2sdk sends
// Cancel first, End last (its EndClientMenu).
bool FakeCancelClientMenu(int32_t slot, s2sdk::MenuCancelReason reason) {
	if (slot < 0 || slot >= kSlots) {
		return false;
	}
	const s2sdk::MenuId id = g_displayed[static_cast<std::size_t>(slot)];
	if (id == 0) {
		return false;
	}
	g_displayed[static_cast<std::size_t>(slot)] = 0;
	CallHandler(id, s2sdk::MenuAction::Cancel, slot, static_cast<int32_t>(reason));
	CallHandler(id, s2sdk::MenuAction::End, slot, 0);
	return true;
}

bool FakeSetMenuPagination(s2sdk::MenuId id, int32_t items) {
	(void)id;
	(void)items;
	return true;
}

bool FakeSetMenuBool(s2sdk::MenuId id, bool value) {
	(void)id;
	(void)value;
	return true;
}

bool FakeIsMenuTypeRegistered(const plg::string& name) {
	(void)name;
	return false; // no custom backends: everything maps to the built-in types
}

void InstallFakes() {
	__s2sdk_CreateMenu = &FakeCreateMenu;
	__s2sdk_DestroyMenu = &FakeDestroyMenu;
	__s2sdk_AddMenuItem = &FakeAddMenuItem;
	__s2sdk_DisplayMenu = &FakeDisplayMenu;
	__s2sdk_GetClientMenu = &FakeGetClientMenu;
	__s2sdk_CancelClientMenu = &FakeCancelClientMenu;
	__s2sdk_SetMenuPagination = &FakeSetMenuPagination;
	__s2sdk_SetMenuExitButton = &FakeSetMenuBool;
	__s2sdk_SetMenuExitBackButton = &FakeSetMenuBool;
	__s2sdk_SetMenuCloseOnSelect = &FakeSetMenuBool;
	__s2sdk_IsMenuTypeRegistered = &FakeIsMenuTypeRegistered;
}

void MakeReady() {
	pisex::OnMapEndNotify(); // normalise the map lifecycle state
	pisex::Poll();
	pisex::OnMapStartNotify();
	pisex::Poll();
}

// Drives one display of a fresh menu and returns the fake's menu id.
s2sdk::MenuId DisplayMenu(int slot, const pisex::MenuCallbackFunc& callback = nullptr) {
	pisex::Menu menu;
	pisex::SetTitleMenu(menu, "Test menu");
	pisex::SetExitMenu(menu, true);
	pisex::AddItemMenu(menu, "one", "One", pisex::ITEM_DEFAULT);
	pisex::AddItemMenu(menu, "two", "Two", pisex::ITEM_DEFAULT);
	if (callback) {
		pisex::SetCallback(menu, callback);
	}
	pisex::DisplayPlayerMenu(menu, slot, true, true);
	return g_displayed[static_cast<std::size_t>(slot)];
}

// --- tests -------------------------------------------------------------------------------------

// The audit item: a display that ends on its own (timeout / disconnect) must destroy the menu -
// deferred out of the handler, exactly once.
void TestEndedDisplayIsDestroyed() {
	g_menus.clear();
	g_displayed.fill(0);
	g_nextMenuId = 1;
	g_createCalls = g_destroyCalls = g_destroysInsideHandler = 0;
	g_destroyedIds.clear();

	const s2sdk::MenuId id = DisplayMenu(3);
	Check(id != 0, "the menu was created and displayed");
	Check(g_menus.size() == 1, "the fake holds the menu");
	Check(pisex::IsMenuOpen(3), "the library reports the menu as open");
	Check(g_destroyCalls == 0, "no destroy happened while displaying");

	// The display times out: s2sdk calls the handler (Cancel then End) and clears its client
	// state. Nothing may be destroyed from inside the handler.
	FakeCancelClientMenu(3, s2sdk::MenuCancelReason::Timeout);
	Check(g_destroyCalls == 0, "the menu is not destroyed inside the handler (deferred)");
	Check(g_destroysInsideHandler == 0, "no DestroyMenu call happens under the menu manager's lock");
	Check(!pisex::IsMenuOpen(3), "the ended display is no longer open");

	pisex::Poll();
	Check(g_destroyCalls == 1, "Poll() destroys the menu whose display ended");
	Check(g_destroyedIds.size() == 1 && g_destroyedIds.front() == id, "the destroyed id is the menu's");
	Check(g_menus.empty(), "no MenuData left in the fake manager");

	pisex::Poll();
	Check(g_destroyCalls == 1, "a second Poll must not destroy it again");
}

// The exit button: the plugin callback still gets Pisex's exit values, and the menu is freed once.
void TestExitDestroysOnceAndKeepsCallback() {
	g_createCalls = g_destroyCalls = g_destroysInsideHandler = 0;
	g_destroyedIds.clear();

	std::string back;
	std::string front;
	int item = -1;
	const s2sdk::MenuId id = DisplayMenu(4, [&](const char* szBack, const char* szFront, int iItem, int iSlot) {
		back = szBack ? szBack : "";
		front = szFront ? szFront : "";
		item = iItem;
		(void)iSlot;
	});
	Check(id != 0, "menu displayed for the exit test");

	FakeCancelClientMenu(4, s2sdk::MenuCancelReason::Exit);
	Check(back == "exit" && front == "exit" && item == 9, "the Pisex exit callback values");
	pisex::Poll();
	Check(g_destroyCalls == 1, "the exited menu is destroyed exactly once");
}

// An explicit close destroys immediately; the engine's later End must not destroy it a second time.
void TestExplicitCloseIsSingle() {
	g_createCalls = g_destroyCalls = g_destroysInsideHandler = 0;
	g_destroyedIds.clear();

	const s2sdk::MenuId id = DisplayMenu(5);
	Check(id != 0, "menu displayed for the close test");
	pisex::ClosePlayerMenu(5);
	Check(g_destroyCalls == 1, "ClosePlayerMenu destroys the menu right away");
	Check(g_menus.empty(), "the menu is gone after the explicit close");
	pisex::Poll();
	Check(g_destroyCalls == 1, "the deferred End of that session does not destroy it again");
}

// A display that the backend refuses (no client, wrong state): the created menu must not leak.
void TestFailedDisplayIsDestroyed() {
	g_createCalls = g_destroyCalls = g_destroysInsideHandler = 0;
	g_destroyedIds.clear();
	g_displaySucceeds = false;

	DisplayMenu(6);
	Check(g_createCalls == 1, "the menu was created");
	Check(g_destroyCalls == 1, "a menu that could not be displayed is destroyed immediately");
	Check(g_menus.empty(), "nothing is left in the fake manager");
	Check(!pisex::IsMenuOpen(6), "no menu is registered for the slot");
	g_displaySucceeds = true;
}

// pisexcompat creates one menu per display, but s2sdk menus are shared objects: if the same id is
// still displayed to another client, the destroy must wait for that session to end.
void TestMultiRecipientSafety() {
	g_createCalls = g_destroyCalls = g_destroysInsideHandler = 0;
	g_destroyedIds.clear();

	const s2sdk::MenuId id = DisplayMenu(7);
	Check(id != 0, "menu displayed for the multi-recipient test");
	g_displayed[8] = id; // as if the same menu had been shown to a second client

	FakeCancelClientMenu(7, s2sdk::MenuCancelReason::Timeout);
	pisex::Poll();
	Check(g_destroyCalls == 0, "a menu still displayed to another client is not destroyed");
	Check(FindMenu(id) != nullptr, "the menu still exists");
	Check(g_displayed[8] == id, "the other client still shows it");

	FakeCancelClientMenu(8, s2sdk::MenuCancelReason::Timeout);
	pisex::Poll();
	Check(g_destroyCalls == 1, "the last session's end destroys it exactly once");
	Check(g_menus.empty(), "nothing is left after the last session");
}

// Map end / plugin shutdown: everything open or queued is destroyed, so `plg reload` does not
// leave MenuData (and handlers into unloaded code) behind.
void TestMapEndAndShutdownDestroyEverything() {
	g_createCalls = g_destroyCalls = g_destroysInsideHandler = 0;
	g_destroyedIds.clear();

	const s2sdk::MenuId open = DisplayMenu(9);
	const s2sdk::MenuId ended = DisplayMenu(10);
	Check(open != 0 && ended != 0, "two menus displayed");
	FakeCancelClientMenu(10, s2sdk::MenuCancelReason::Disconnect); // queued for destroy

	pisex::OnMapEndNotify(); // map end runs CloseAllMenus
	Check(g_destroyCalls == 2, "map end destroys the open and the queued menu");
	Check(g_menus.empty(), "no MenuData survives the map end");
	Check(g_destroysInsideHandler == 0, "no destroy ran inside a handler");

	pisex::OnMapStartNotify();
	pisex::Poll();
	Check(DisplayMenu(11) != 0, "a menu works again on the new map");
	pisex::Shutdown();
	Check(g_menus.empty(), "Shutdown destroys everything too");
}

} // namespace

int main() {
	std::printf("pisexcompat menu engine tests (fake s2sdk menu manager)\n");

	InstallFakes();
	MakeReady();

	TestEndedDisplayIsDestroyed();
	TestExitDestroysOnceAndKeepsCallback();
	TestExplicitCloseIsSingle();
	TestFailedDisplayIsDestroyed();
	TestMultiRecipientSafety();
	TestMapEndAndShutdownDestroyEverything();

	std::printf("%d checks, %d failures\n", g_checks, g_failures);
	return g_failures == 0 ? 0 : 1;
}
