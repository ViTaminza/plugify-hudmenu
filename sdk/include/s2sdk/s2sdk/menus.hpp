#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: menus)

namespace s2sdk {

  using _RegisterMenuType = bool (*)(const plg::string&, MenuDisplayCallback, MenuCloseCallback, MenuFrameCallback);
}
extern "C" PLUGIN_API s2sdk::_RegisterMenuType __s2sdk_RegisterMenuType;
namespace s2sdk {
  /**
   * @brief Registers a new menu type backend (e.g. a custom rendering style), so it can be selected via CreateMenu/SetMenuType. Built-in types "chat", "console", "centerhtml" and "button" are registered automatically at startup.
   * @param name (string): The unique, case-insensitive name of the menu type.
   * @param display (function): Callback invoked to render the menu's current state to a client.
   * @param close (function): Callback invoked to hide/clean up whatever UI was shown to a client.
   * @param frame (function): Optional callback invoked every server frame while a client has this menu type open (e.g. for input polling). Pass null if not needed.
   * @return bool: True if the type was registered; false if the name is empty, a callback is null, or the name is already taken.
   */
  inline bool RegisterMenuType(const plg::string& name, MenuDisplayCallback display, MenuCloseCallback close, MenuFrameCallback frame) {
    return __s2sdk_RegisterMenuType(name, display, close, frame);
  }

  using _UnregisterMenuType = bool (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_UnregisterMenuType __s2sdk_UnregisterMenuType;
namespace s2sdk {
  /**
   * @brief Unregisters a previously registered menu type.
   * @param name (string): The name of the menu type to remove.
   * @return bool: True if a type with that name was found and removed.
   */
  inline bool UnregisterMenuType(const plg::string& name) {
    return __s2sdk_UnregisterMenuType(name);
  }

  using _IsMenuTypeRegistered = bool (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_IsMenuTypeRegistered __s2sdk_IsMenuTypeRegistered;
namespace s2sdk {
  /**
   * @brief Checks whether a menu type with the given name is currently registered.
   * @param name (string): The name of the menu type.
   * @return bool: True if the menu type is registered.
   */
  inline bool IsMenuTypeRegistered(const plg::string& name) {
    return __s2sdk_IsMenuTypeRegistered(name);
  }

  using _GetMenuTypes = plg::vector<plg::string> (*)();
}
extern "C" PLUGIN_API s2sdk::_GetMenuTypes __s2sdk_GetMenuTypes;
namespace s2sdk {
  /**
   * @brief Returns the names of all currently registered menu types.
   * @return string[]: The vector of menu type names.
   */
  inline plg::vector<plg::string> GetMenuTypes() {
    return __s2sdk_GetMenuTypes();
  }

  using _SetDefaultMenuType = bool (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetDefaultMenuType __s2sdk_SetDefaultMenuType;
namespace s2sdk {
  /**
   * @brief Sets the menu type used by menus that don't specify one explicitly.
   * @param name (string): The name of an already-registered menu type.
   * @return bool: True if the type exists and was set as default.
   */
  inline bool SetDefaultMenuType(const plg::string& name) {
    return __s2sdk_SetDefaultMenuType(name);
  }

  using _GetDefaultMenuType = plg::string (*)();
}
extern "C" PLUGIN_API s2sdk::_GetDefaultMenuType __s2sdk_GetDefaultMenuType;
namespace s2sdk {
  /**
   * @brief Returns the current default menu type name.
   * @return string: The default menu type name.
   */
  inline plg::string GetDefaultMenuType() {
    return __s2sdk_GetDefaultMenuType();
  }

  using _CreateMenu = MenuId (*)(const plg::string&, MenuHandlerCallback, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_CreateMenu __s2sdk_CreateMenu;
namespace s2sdk {
  /**
   * @brief Creates a new menu.
   * @param title (string): The title shown at the top of the menu.
   * @param handler (function): Callback invoked with Start/Select/Cancel/End actions as the menu is displayed and interacted with.
   * @param menuType (string): The name of the menu type backend to render with. Empty uses the current default menu type.
   * @return uint32: A handle to the created menu.
   */
  inline MenuId CreateMenu(const plg::string& title, MenuHandlerCallback handler, const plg::string& menuType) {
    return __s2sdk_CreateMenu(title, handler, menuType);
  }

  using _DestroyMenu = bool (*)(MenuId);
}
extern "C" PLUGIN_API s2sdk::_DestroyMenu __s2sdk_DestroyMenu;
namespace s2sdk {
  /**
   * @brief Destroys a menu. Any client currently viewing it is cancelled first (MenuCancelReason::Destroyed).
   * @param id (uint32): The handle to the menu.
   * @return bool: True if the menu existed and was destroyed.
   */
  inline bool DestroyMenu(MenuId id) {
    return __s2sdk_DestroyMenu(id);
  }

  using _IsValidMenu = bool (*)(MenuId);
}
extern "C" PLUGIN_API s2sdk::_IsValidMenu __s2sdk_IsValidMenu;
namespace s2sdk {
  /**
   * @brief Checks whether a menu handle refers to an existing menu.
   * @param id (uint32): The handle to the menu.
   * @return bool: True if the handle is valid.
   */
  inline bool IsValidMenu(MenuId id) {
    return __s2sdk_IsValidMenu(id);
  }

  using _SetMenuTitle = bool (*)(MenuId, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetMenuTitle __s2sdk_SetMenuTitle;
namespace s2sdk {
  /**
   * @brief Sets a menu's title.
   * @param id (uint32): The handle to the menu.
   * @param title (string): The new title.
   * @return bool: True if the menu exists.
   */
  inline bool SetMenuTitle(MenuId id, const plg::string& title) {
    return __s2sdk_SetMenuTitle(id, title);
  }

  using _GetMenuTitle = plg::string (*)(MenuId);
}
extern "C" PLUGIN_API s2sdk::_GetMenuTitle __s2sdk_GetMenuTitle;
namespace s2sdk {
  /**
   * @brief Gets a menu's title.
   * @param id (uint32): The handle to the menu.
   * @return string: The menu's title, or an empty string if the handle is invalid.
   */
  inline plg::string GetMenuTitle(MenuId id) {
    return __s2sdk_GetMenuTitle(id);
  }

  using _SetMenuType = bool (*)(MenuId, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetMenuType __s2sdk_SetMenuType;
namespace s2sdk {
  /**
   * @brief Sets which registered menu type backend renders this menu.
   * @param id (uint32): The handle to the menu.
   * @param typeName (string): The name of a registered menu type, or empty to use the default menu type.
   * @return bool: True if the menu exists.
   */
  inline bool SetMenuType(MenuId id, const plg::string& typeName) {
    return __s2sdk_SetMenuType(id, typeName);
  }

  using _GetMenuType = plg::string (*)(MenuId);
}
extern "C" PLUGIN_API s2sdk::_GetMenuType __s2sdk_GetMenuType;
namespace s2sdk {
  /**
   * @brief Gets the menu type backend name assigned to this menu.
   * @param id (uint32): The handle to the menu.
   * @return string: The menu type name (may be empty, meaning "use the default").
   */
  inline plg::string GetMenuType(MenuId id) {
    return __s2sdk_GetMenuType(id);
  }

  using _SetMenuPagination = bool (*)(MenuId, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetMenuPagination __s2sdk_SetMenuPagination;
namespace s2sdk {
  /**
   * @brief Sets how many items are shown per page.
   * @param id (uint32): The handle to the menu.
   * @param itemsPerPage (int32): The number of items per page, or 0 to disable pagination (show every item on one page).
   * @return bool: True if the menu exists and itemsPerPage is not negative.
   */
  inline bool SetMenuPagination(MenuId id, int32_t itemsPerPage) {
    return __s2sdk_SetMenuPagination(id, itemsPerPage);
  }

  using _GetMenuPagination = int32_t (*)(MenuId);
}
extern "C" PLUGIN_API s2sdk::_GetMenuPagination __s2sdk_GetMenuPagination;
namespace s2sdk {
  /**
   * @brief Gets how many items are shown per page.
   * @param id (uint32): The handle to the menu.
   * @return int32: The items-per-page value, 0 meaning pagination is disabled.
   */
  inline int32_t GetMenuPagination(MenuId id) {
    return __s2sdk_GetMenuPagination(id);
  }

  using _SetMenuExitButton = bool (*)(MenuId, bool);
}
extern "C" PLUGIN_API s2sdk::_SetMenuExitButton __s2sdk_SetMenuExitButton;
namespace s2sdk {
  /**
   * @brief Sets whether the menu shows an exit option.
   * @param id (uint32): The handle to the menu.
   * @param enabled (bool): True to show an exit option.
   * @return bool: True if the menu exists.
   */
  inline bool SetMenuExitButton(MenuId id, bool enabled) {
    return __s2sdk_SetMenuExitButton(id, enabled);
  }

  using _GetMenuExitButton = bool (*)(MenuId);
}
extern "C" PLUGIN_API s2sdk::_GetMenuExitButton __s2sdk_GetMenuExitButton;
namespace s2sdk {
  /**
   * @brief Gets whether the menu shows an exit option.
   * @param id (uint32): The handle to the menu.
   * @return bool: True if the exit option is enabled.
   */
  inline bool GetMenuExitButton(MenuId id) {
    return __s2sdk_GetMenuExitButton(id);
  }

  using _SetMenuExitBackButton = bool (*)(MenuId, bool);
}
extern "C" PLUGIN_API s2sdk::_SetMenuExitBackButton __s2sdk_SetMenuExitBackButton;
namespace s2sdk {
  /**
   * @brief Sets whether the menu shows a "back" option in place of the exit option. Selecting it cancels the display with MenuCancelReason::ExitBack instead of MenuCancelReason::Exit, which a handler can use to redisplay a parent menu (SourceMod-style ExitBack).
   * @param id (uint32): The handle to the menu.
   * @param enabled (bool): True to show a back option instead of the exit option.
   * @return bool: True if the menu exists.
   */
  inline bool SetMenuExitBackButton(MenuId id, bool enabled) {
    return __s2sdk_SetMenuExitBackButton(id, enabled);
  }

  using _GetMenuExitBackButton = bool (*)(MenuId);
}
extern "C" PLUGIN_API s2sdk::_GetMenuExitBackButton __s2sdk_GetMenuExitBackButton;
namespace s2sdk {
  /**
   * @brief Gets whether the menu shows a "back" option in place of the exit option.
   * @param id (uint32): The handle to the menu.
   * @return bool: True if the back option is enabled.
   */
  inline bool GetMenuExitBackButton(MenuId id) {
    return __s2sdk_GetMenuExitBackButton(id);
  }

  using _SetMenuCloseOnSelect = bool (*)(MenuId, bool);
}
extern "C" PLUGIN_API s2sdk::_SetMenuCloseOnSelect __s2sdk_SetMenuCloseOnSelect;
namespace s2sdk {
  /**
   * @brief Sets whether selecting an item automatically closes the menu display for that client. When disabled, the display stays open after MenuAction::Select and the handler is responsible for closing/redisplaying it if desired.
   * @param id (uint32): The handle to the menu.
   * @param enabled (bool): True to auto-close on selection (the default).
   * @return bool: True if the menu exists.
   */
  inline bool SetMenuCloseOnSelect(MenuId id, bool enabled) {
    return __s2sdk_SetMenuCloseOnSelect(id, enabled);
  }

  using _GetMenuCloseOnSelect = bool (*)(MenuId);
}
extern "C" PLUGIN_API s2sdk::_GetMenuCloseOnSelect __s2sdk_GetMenuCloseOnSelect;
namespace s2sdk {
  /**
   * @brief Gets whether selecting an item automatically closes the menu display for that client.
   * @param id (uint32): The handle to the menu.
   * @return bool: True if close-on-select is enabled.
   */
  inline bool GetMenuCloseOnSelect(MenuId id) {
    return __s2sdk_GetMenuCloseOnSelect(id);
  }

  using _AddMenuItem = int32_t (*)(MenuId, const plg::string&, const plg::string&, MenuItemStyle);
}
extern "C" PLUGIN_API s2sdk::_AddMenuItem __s2sdk_AddMenuItem;
namespace s2sdk {
  /**
   * @brief Appends an item to the end of a menu.
   * @param id (uint32): The handle to the menu.
   * @param info (string): An internal identifier for the item, not shown to the client; retrieve it with GetMenuItemInfo from within the handler callback.
   * @param display (string): The text shown to the client.
   * @param style (int32): The item's draw style (Default/Disabled/Spacer).
   * @return int32: The index of the newly added item, or -1 if the menu handle is invalid.
   */
  inline int32_t AddMenuItem(MenuId id, const plg::string& info, const plg::string& display, MenuItemStyle style) {
    return __s2sdk_AddMenuItem(id, info, display, style);
  }

  using _InsertMenuItemAt = int32_t (*)(MenuId, int32_t, const plg::string&, const plg::string&, MenuItemStyle);
}
extern "C" PLUGIN_API s2sdk::_InsertMenuItemAt __s2sdk_InsertMenuItemAt;
namespace s2sdk {
  /**
   * @brief Inserts an item into a menu at a specific index.
   * @param id (uint32): The handle to the menu.
   * @param index (int32): The index to insert at; must be within [0, item count].
   * @param info (string): An internal identifier for the item, not shown to the client.
   * @param display (string): The text shown to the client.
   * @param style (int32): The item's draw style (Default/Disabled/Spacer).
   * @return int32: The index the item was inserted at, or -1 on failure.
   */
  inline int32_t InsertMenuItemAt(MenuId id, int32_t index, const plg::string& info, const plg::string& display, MenuItemStyle style) {
    return __s2sdk_InsertMenuItemAt(id, index, info, display, style);
  }

  using _RemoveMenuItem = bool (*)(MenuId, int32_t);
}
extern "C" PLUGIN_API s2sdk::_RemoveMenuItem __s2sdk_RemoveMenuItem;
namespace s2sdk {
  /**
   * @brief Removes an item from a menu.
   * @param id (uint32): The handle to the menu.
   * @param index (int32): The index of the item to remove.
   * @return bool: True if the item existed and was removed.
   */
  inline bool RemoveMenuItem(MenuId id, int32_t index) {
    return __s2sdk_RemoveMenuItem(id, index);
  }

  using _RemoveAllMenuItems = bool (*)(MenuId);
}
extern "C" PLUGIN_API s2sdk::_RemoveAllMenuItems __s2sdk_RemoveAllMenuItems;
namespace s2sdk {
  /**
   * @brief Removes every item from a menu.
   * @param id (uint32): The handle to the menu.
   * @return bool: True if the menu exists.
   */
  inline bool RemoveAllMenuItems(MenuId id) {
    return __s2sdk_RemoveAllMenuItems(id);
  }

  using _GetMenuItemsCount = int32_t (*)(MenuId);
}
extern "C" PLUGIN_API s2sdk::_GetMenuItemsCount __s2sdk_GetMenuItemsCount;
namespace s2sdk {
  /**
   * @brief Gets the number of items in a menu.
   * @param id (uint32): The handle to the menu.
   * @return int32: The item count, or 0 if the handle is invalid.
   */
  inline int32_t GetMenuItemsCount(MenuId id) {
    return __s2sdk_GetMenuItemsCount(id);
  }

  using _GetMenuItemInfoText = plg::string (*)(MenuId, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetMenuItemInfoText __s2sdk_GetMenuItemInfoText;
namespace s2sdk {
  /**
   * @brief Gets an item's internal info string.
   * @param id (uint32): The handle to the menu.
   * @param index (int32): The index of the item.
   * @return string: The item's info string, or empty if out of range.
   */
  inline plg::string GetMenuItemInfoText(MenuId id, int32_t index) {
    return __s2sdk_GetMenuItemInfoText(id, index);
  }

  using _GetMenuItemDisplay = plg::string (*)(MenuId, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetMenuItemDisplay __s2sdk_GetMenuItemDisplay;
namespace s2sdk {
  /**
   * @brief Gets an item's display text.
   * @param id (uint32): The handle to the menu.
   * @param index (int32): The index of the item.
   * @return string: The item's display text, or empty if out of range.
   */
  inline plg::string GetMenuItemDisplay(MenuId id, int32_t index) {
    return __s2sdk_GetMenuItemDisplay(id, index);
  }

  using _GetMenuItemStyle = MenuItemStyle (*)(MenuId, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetMenuItemStyle __s2sdk_GetMenuItemStyle;
namespace s2sdk {
  /**
   * @brief Gets an item's draw style.
   * @param id (uint32): The handle to the menu.
   * @param index (int32): The index of the item.
   * @return int32: The item's style; MenuItemStyle::Disabled if out of range.
   */
  inline MenuItemStyle GetMenuItemStyle(MenuId id, int32_t index) {
    return __s2sdk_GetMenuItemStyle(id, index);
  }

  using _IsMenuItemSelectable = bool (*)(MenuId, int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsMenuItemSelectable __s2sdk_IsMenuItemSelectable;
namespace s2sdk {
  /**
   * @brief Checks whether an item can currently be selected (style is Default).
   * @param id (uint32): The handle to the menu.
   * @param index (int32): The index of the item.
   * @return bool: True if the item is selectable.
   */
  inline bool IsMenuItemSelectable(MenuId id, int32_t index) {
    return __s2sdk_IsMenuItemSelectable(id, index);
  }

  using _SetMenuItemDisplay = bool (*)(MenuId, int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetMenuItemDisplay __s2sdk_SetMenuItemDisplay;
namespace s2sdk {
  /**
   * @brief Changes an item's display text.
   * @param id (uint32): The handle to the menu.
   * @param index (int32): The index of the item.
   * @param display (string): The new display text.
   * @return bool: True if the item exists.
   */
  inline bool SetMenuItemDisplay(MenuId id, int32_t index, const plg::string& display) {
    return __s2sdk_SetMenuItemDisplay(id, index, display);
  }

  using _SetMenuItemStyle = bool (*)(MenuId, int32_t, MenuItemStyle);
}
extern "C" PLUGIN_API s2sdk::_SetMenuItemStyle __s2sdk_SetMenuItemStyle;
namespace s2sdk {
  /**
   * @brief Changes an item's draw style.
   * @param id (uint32): The handle to the menu.
   * @param index (int32): The index of the item.
   * @param style (int32): The new style.
   * @return bool: True if the item exists.
   */
  inline bool SetMenuItemStyle(MenuId id, int32_t index, MenuItemStyle style) {
    return __s2sdk_SetMenuItemStyle(id, index, style);
  }

  using _DisplayMenu = bool (*)(MenuId, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_DisplayMenu __s2sdk_DisplayMenu;
namespace s2sdk {
  /**
   * @brief Displays a menu to a client, starting at the first item. Replaces whatever menu the client currently has open, if any.
   * @param id (uint32): The handle to the menu.
   * @param playerSlot (int32): The client's player slot.
   * @param time (int32): How long, in seconds, before the menu auto-closes (MenuCancelReason::Timeout). 0 or negative means no timeout.
   * @return bool: True if the menu was displayed.
   */
  inline bool DisplayMenu(MenuId id, int32_t playerSlot, int32_t time) {
    return __s2sdk_DisplayMenu(id, playerSlot, time);
  }

  using _DisplayMenuAtItem = bool (*)(MenuId, int32_t, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_DisplayMenuAtItem __s2sdk_DisplayMenuAtItem;
namespace s2sdk {
  /**
   * @brief Displays a menu to a client, starting at a specific item.
   * @param id (uint32): The handle to the menu.
   * @param playerSlot (int32): The client's player slot.
   * @param firstItem (int32): The index of the first item to show.
   * @param time (int32): How long, in seconds, before the menu auto-closes. 0 or negative means no timeout.
   * @return bool: True if the menu was displayed.
   */
  inline bool DisplayMenuAtItem(MenuId id, int32_t playerSlot, int32_t firstItem, int32_t time) {
    return __s2sdk_DisplayMenuAtItem(id, playerSlot, firstItem, time);
  }

  using _CancelClientMenu = bool (*)(int32_t, MenuCancelReason);
}
extern "C" PLUGIN_API s2sdk::_CancelClientMenu __s2sdk_CancelClientMenu;
namespace s2sdk {
  /**
   * @brief Cancels whatever menu a client currently has open.
   * @param playerSlot (int32): The client's player slot.
   * @param reason (int32): The reason reported to the menu's handler via MenuAction::Cancel.
   * @return bool: True if the client had a menu open and it was cancelled.
   */
  inline bool CancelClientMenu(int32_t playerSlot, MenuCancelReason reason) {
    return __s2sdk_CancelClientMenu(playerSlot, reason);
  }

  using _GetClientMenu = MenuId (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientMenu __s2sdk_GetClientMenu;
namespace s2sdk {
  /**
   * @brief Gets the menu a client currently has open.
   * @param playerSlot (int32): The client's player slot.
   * @return uint32: The open menu's handle, or 0 if none.
   */
  inline MenuId GetClientMenu(int32_t playerSlot) {
    return __s2sdk_GetClientMenu(playerSlot);
  }

  using _GetClientMenuOffset = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientMenuOffset __s2sdk_GetClientMenuOffset;
namespace s2sdk {
  /**
   * @brief Gets the index of the first item shown on the client's current page.
   * @param playerSlot (int32): The client's player slot.
   * @return int32: The current page offset.
   */
  inline int32_t GetClientMenuOffset(int32_t playerSlot) {
    return __s2sdk_GetClientMenuOffset(playerSlot);
  }

  using _GetClientMenuTime = double (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientMenuTime __s2sdk_GetClientMenuTime;
namespace s2sdk {
  /**
   * @brief Gets the `time` value the client's current menu was displayed with.
   * @param playerSlot (int32): The client's player slot.
   * @return double: The display time in seconds, 0 meaning no timeout.
   */
  inline double GetClientMenuTime(int32_t playerSlot) {
    return __s2sdk_GetClientMenuTime(playerSlot);
  }

  using _GetClientMenuCursor = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientMenuCursor __s2sdk_GetClientMenuCursor;
namespace s2sdk {
  /**
   * @brief Gets the absolute item index highlighted by cursor-driven menu types (e.g. the button menu).
   * @param playerSlot (int32): The client's player slot.
   * @return int32: The cursor's item index.
   */
  inline int32_t GetClientMenuCursor(int32_t playerSlot) {
    return __s2sdk_GetClientMenuCursor(playerSlot);
  }

  using _SetClientMenuCursor = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetClientMenuCursor __s2sdk_SetClientMenuCursor;
namespace s2sdk {
  /**
   * @brief Sets the absolute item index highlighted by cursor-driven menu types.
   * @param playerSlot (int32): The client's player slot.
   * @param index (int32): The item index to highlight.
   */
  inline void SetClientMenuCursor(int32_t playerSlot, int32_t index) {
    return __s2sdk_SetClientMenuCursor(playerSlot, index);
  }

  using _ClientMenuHasPrevPage = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_ClientMenuHasPrevPage __s2sdk_ClientMenuHasPrevPage;
namespace s2sdk {
  /**
   * @brief Checks whether the client's current menu display has a previous page to go back to.
   * @param playerSlot (int32): The client's player slot.
   * @return bool: True if a previous page exists.
   */
  inline bool ClientMenuHasPrevPage(int32_t playerSlot) {
    return __s2sdk_ClientMenuHasPrevPage(playerSlot);
  }

  using _ClientMenuHasNextPage = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_ClientMenuHasNextPage __s2sdk_ClientMenuHasNextPage;
namespace s2sdk {
  /**
   * @brief Checks whether the client's current menu display has a next page.
   * @param playerSlot (int32): The client's player slot.
   * @return bool: True if a next page exists.
   */
  inline bool ClientMenuHasNextPage(int32_t playerSlot) {
    return __s2sdk_ClientMenuHasNextPage(playerSlot);
  }

  using _MenuNextPage = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_MenuNextPage __s2sdk_MenuNextPage;
namespace s2sdk {
  /**
   * @brief Advances the client's current menu display to the next page and redraws it.
   * @param playerSlot (int32): The client's player slot.
   * @return bool: True if there was a next page to move to.
   */
  inline bool MenuNextPage(int32_t playerSlot) {
    return __s2sdk_MenuNextPage(playerSlot);
  }

  using _MenuPrevPage = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_MenuPrevPage __s2sdk_MenuPrevPage;
namespace s2sdk {
  /**
   * @brief Moves the client's current menu display back to the previous page and redraws it.
   * @param playerSlot (int32): The client's player slot.
   * @return bool: True if there was a previous page to move to.
   */
  inline bool MenuPrevPage(int32_t playerSlot) {
    return __s2sdk_MenuPrevPage(playerSlot);
  }

  using _SelectMenuItem = bool (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SelectMenuItem __s2sdk_SelectMenuItem;
namespace s2sdk {
  /**
   * @brief Selects an item on the client's current menu display by its absolute index. Intended to be called by menu type backends once they've resolved raw input into an item index.
   * @param playerSlot (int32): The client's player slot.
   * @param itemIndex (int32): The absolute index of the item to select.
   * @return bool: True if the item existed and was selectable.
   */
  inline bool SelectMenuItem(int32_t playerSlot, int32_t itemIndex) {
    return __s2sdk_SelectMenuItem(playerSlot, itemIndex);
  }

  using _HandleDigitInput = bool (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_HandleDigitInput __s2sdk_HandleDigitInput;
namespace s2sdk {
  /**
   * @brief Shared input path for digit-driven menu types (chat/console/centerhtml): 1-7 select an item on the current page, 8 goes to the previous page, 9 to the next page, 0 exits.
   * @param playerSlot (int32): The client's player slot.
   * @param digit (int32): The digit (0-9) that was pressed.
   * @return bool: True if the digit resulted in an action.
   */
  inline bool HandleDigitInput(int32_t playerSlot, int32_t digit) {
    return __s2sdk_HandleDigitInput(playerSlot, digit);
  }

  /**
   * @brief RAII wrapper for Menu handle.
   * @return 
   */
  class Menu final {
  public:
    Menu() = default;

    /**
     * @brief Creates a new menu.
     * @param title (string): The title shown at the top of the menu.
     * @param handler (function): Callback invoked with Start/Select/Cancel/End actions as the menu is displayed and interacted with.
     * @param menuType (string): The name of the menu type backend to render with. Empty uses the current default menu type.
     * @return 
     */
    explicit Menu(const plg::string& title, MenuHandlerCallback handler, const plg::string& menuType)
      : Menu(CreateMenu(title, handler, menuType), Ownership::Owned) {}

    Menu(const Menu&) = default;
    Menu& operator=(const Menu&) = default;
    Menu(Menu&&) noexcept = default;
    Menu& operator=(Menu&&) noexcept = default;
    ~Menu() = default;

    explicit Menu(MenuId handle, [[maybe_unused]] Ownership ownership = Ownership::Borrowed) : _handle(handle) {}

    [[nodiscard]] auto get() const noexcept { return _handle; }

    [[nodiscard]] auto release() noexcept {
      auto handle = _handle;
      _handle = 0;
      return handle;
    }

    void reset() noexcept {
      _handle = 0;
    }

    void swap(Menu& other) noexcept {
      using std::swap;
      swap(_handle, other._handle);
    }

    friend void swap(Menu& lhs, Menu& rhs) noexcept { lhs.swap(rhs); }

    explicit operator bool() const noexcept { return _handle != 0; }
    [[nodiscard]] auto operator<=>(const Menu& other) const noexcept { return _handle <=> other._handle; }
    [[nodiscard]] bool operator==(const Menu& other) const noexcept { return _handle == other._handle; }

    /**
     * @brief Destroys a menu. Any client currently viewing it is cancelled first (MenuCancelReason::Destroyed).
     * @return bool: True if the menu existed and was destroyed.
     */
    bool Destroy() {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::DestroyMenu(_handle);
    }

    /**
     * @brief Checks whether a menu handle refers to an existing menu.
     * @return bool: True if the handle is valid.
     */
    bool IsValid() {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::IsValidMenu(_handle);
    }

    /**
     * @brief Sets a menu's title.
     * @param title (string): The new title.
     * @return bool: True if the menu exists.
     */
    bool SetTitle(const plg::string& title) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::SetMenuTitle(_handle, title);
    }

    /**
     * @brief Gets a menu's title.
     * @return string: The menu's title, or an empty string if the handle is invalid.
     */
    plg::string GetTitle() {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::GetMenuTitle(_handle);
    }

    /**
     * @brief Sets which registered menu type backend renders this menu.
     * @param typeName (string): The name of a registered menu type, or empty to use the default menu type.
     * @return bool: True if the menu exists.
     */
    bool SetType(const plg::string& typeName) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::SetMenuType(_handle, typeName);
    }

    /**
     * @brief Gets the menu type backend name assigned to this menu.
     * @return string: The menu type name (may be empty, meaning "use the default").
     */
    plg::string GetType() {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::GetMenuType(_handle);
    }

    /**
     * @brief Sets how many items are shown per page.
     * @param itemsPerPage (int32): The number of items per page, or 0 to disable pagination (show every item on one page).
     * @return bool: True if the menu exists and itemsPerPage is not negative.
     */
    bool SetPagination(int32_t itemsPerPage) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::SetMenuPagination(_handle, itemsPerPage);
    }

    /**
     * @brief Gets how many items are shown per page.
     * @return int32: The items-per-page value, 0 meaning pagination is disabled.
     */
    int32_t GetPagination() {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::GetMenuPagination(_handle);
    }

    /**
     * @brief Sets whether the menu shows an exit option.
     * @param enabled (bool): True to show an exit option.
     * @return bool: True if the menu exists.
     */
    bool SetExitButton(bool enabled) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::SetMenuExitButton(_handle, enabled);
    }

    /**
     * @brief Gets whether the menu shows an exit option.
     * @return bool: True if the exit option is enabled.
     */
    bool GetExitButton() {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::GetMenuExitButton(_handle);
    }

    /**
     * @brief Sets whether the menu shows a "back" option in place of the exit option. Selecting it cancels the display with MenuCancelReason::ExitBack instead of MenuCancelReason::Exit, which a handler can use to redisplay a parent menu (SourceMod-style ExitBack).
     * @param enabled (bool): True to show a back option instead of the exit option.
     * @return bool: True if the menu exists.
     */
    bool SetExitBackButton(bool enabled) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::SetMenuExitBackButton(_handle, enabled);
    }

    /**
     * @brief Gets whether the menu shows a "back" option in place of the exit option.
     * @return bool: True if the back option is enabled.
     */
    bool GetExitBackButton() {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::GetMenuExitBackButton(_handle);
    }

    /**
     * @brief Sets whether selecting an item automatically closes the menu display for that client. When disabled, the display stays open after MenuAction::Select and the handler is responsible for closing/redisplaying it if desired.
     * @param enabled (bool): True to auto-close on selection (the default).
     * @return bool: True if the menu exists.
     */
    bool SetCloseOnSelect(bool enabled) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::SetMenuCloseOnSelect(_handle, enabled);
    }

    /**
     * @brief Gets whether selecting an item automatically closes the menu display for that client.
     * @return bool: True if close-on-select is enabled.
     */
    bool GetCloseOnSelect() {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::GetMenuCloseOnSelect(_handle);
    }

    /**
     * @brief Appends an item to the end of a menu.
     * @param info (string): An internal identifier for the item, not shown to the client; retrieve it with GetMenuItemInfo from within the handler callback.
     * @param display (string): The text shown to the client.
     * @param style (int32): The item's draw style (Default/Disabled/Spacer).
     * @return int32: The index of the newly added item, or -1 if the menu handle is invalid.
     */
    int32_t AddItem(const plg::string& info, const plg::string& display, MenuItemStyle style) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::AddMenuItem(_handle, info, display, style);
    }

    /**
     * @brief Inserts an item into a menu at a specific index.
     * @param index (int32): The index to insert at; must be within [0, item count].
     * @param info (string): An internal identifier for the item, not shown to the client.
     * @param display (string): The text shown to the client.
     * @param style (int32): The item's draw style (Default/Disabled/Spacer).
     * @return int32: The index the item was inserted at, or -1 on failure.
     */
    int32_t InsertItemAt(int32_t index, const plg::string& info, const plg::string& display, MenuItemStyle style) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::InsertMenuItemAt(_handle, index, info, display, style);
    }

    /**
     * @brief Removes an item from a menu.
     * @param index (int32): The index of the item to remove.
     * @return bool: True if the item existed and was removed.
     */
    bool RemoveItem(int32_t index) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::RemoveMenuItem(_handle, index);
    }

    /**
     * @brief Removes every item from a menu.
     * @return bool: True if the menu exists.
     */
    bool RemoveAllItems() {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::RemoveAllMenuItems(_handle);
    }

    /**
     * @brief Gets the number of items in a menu.
     * @return int32: The item count, or 0 if the handle is invalid.
     */
    int32_t GetItemsCount() {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::GetMenuItemsCount(_handle);
    }

    /**
     * @brief Gets an item's internal info string.
     * @param index (int32): The index of the item.
     * @return string: The item's info string, or empty if out of range.
     */
    plg::string GetItemInfoText(int32_t index) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::GetMenuItemInfoText(_handle, index);
    }

    /**
     * @brief Gets an item's display text.
     * @param index (int32): The index of the item.
     * @return string: The item's display text, or empty if out of range.
     */
    plg::string GetItemDisplay(int32_t index) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::GetMenuItemDisplay(_handle, index);
    }

    /**
     * @brief Gets an item's draw style.
     * @param index (int32): The index of the item.
     * @return int32: The item's style; MenuItemStyle::Disabled if out of range.
     */
    MenuItemStyle GetItemStyle(int32_t index) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::GetMenuItemStyle(_handle, index);
    }

    /**
     * @brief Checks whether an item can currently be selected (style is Default).
     * @param index (int32): The index of the item.
     * @return bool: True if the item is selectable.
     */
    bool IsItemSelectable(int32_t index) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::IsMenuItemSelectable(_handle, index);
    }

    /**
     * @brief Changes an item's display text.
     * @param index (int32): The index of the item.
     * @param display (string): The new display text.
     * @return bool: True if the item exists.
     */
    bool SetItemDisplay(int32_t index, const plg::string& display) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::SetMenuItemDisplay(_handle, index, display);
    }

    /**
     * @brief Changes an item's draw style.
     * @param index (int32): The index of the item.
     * @param style (int32): The new style.
     * @return bool: True if the item exists.
     */
    bool SetItemStyle(int32_t index, MenuItemStyle style) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::SetMenuItemStyle(_handle, index, style);
    }

    /**
     * @brief Displays a menu to a client, starting at the first item. Replaces whatever menu the client currently has open, if any.
     * @param playerSlot (int32): The client's player slot.
     * @param time (int32): How long, in seconds, before the menu auto-closes (MenuCancelReason::Timeout). 0 or negative means no timeout.
     * @return bool: True if the menu was displayed.
     */
    bool Display(int32_t playerSlot, int32_t time) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::DisplayMenu(_handle, playerSlot, time);
    }

    /**
     * @brief Displays a menu to a client, starting at a specific item.
     * @param playerSlot (int32): The client's player slot.
     * @param firstItem (int32): The index of the first item to show.
     * @param time (int32): How long, in seconds, before the menu auto-closes. 0 or negative means no timeout.
     * @return bool: True if the menu was displayed.
     */
    bool DisplayAtItem(int32_t playerSlot, int32_t firstItem, int32_t time) {
      if (_handle == 0) throw std::runtime_error("Menu: empty handle");
      return s2sdk::DisplayMenuAtItem(_handle, playerSlot, firstItem, time);
    }

  private:
    MenuId _handle{0};
  };


} // namespace s2sdk
