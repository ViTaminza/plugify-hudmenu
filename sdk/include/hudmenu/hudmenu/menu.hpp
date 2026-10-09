#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from hudmenu.pplugin (group: menu)

namespace hudmenu {

  using _GetClientMenuType = plg::string (*)(int32_t);
}
extern "C" PLUGIN_API hudmenu::_GetClientMenuType __hudmenu_GetClientMenuType;
namespace hudmenu {
  /**
   * @brief The s2sdk menu type name this player's menus should be rendered with: 'hud', 'wasd', 'button', 'centerhtml' or 'chat'. Returns the player's saved choice (permissions cookie 'Utils.MenuType', Pisex numbering 0=chat 1=centerhtml 2=wasd 3=hud, cached per slot and refreshed when the permissions user loads); when the player has no saved choice or the permissions user is not loaded yet, the server default from config.jsonc ('default_menu_type', 'hud' out of the box) is returned. 'hud' and 'wasd' are only returned when hudmenu registered the matching backend - otherwise 'button' is used. Slots without a connected, authorised human player also get the server default.
   * @param playerSlot (int32): The client's player slot.
   * @return string: One of 'hud', 'button', 'centerhtml' or 'chat'.
   */
  inline plg::string GetClientMenuType(int32_t playerSlot) {
    return __hudmenu_GetClientMenuType(playerSlot);
  }

  using _SetClientMenuType = bool (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API hudmenu::_SetClientMenuType __hudmenu_SetClientMenuType;
namespace hudmenu {
  /**
   * @brief Saves the player's menu type choice (permissions cookie 'Utils.MenuType', int64 with the Pisex numbering) and updates the per-slot cache, so the next GetClientMenuType returns it immediately. Accepts 'hud', 'wasd', 'button', 'centerhtml' or 'chat' (case-insensitive; 'hud_layout'/'center_wasd'/'center' and the numeric Pisex values '0'..'3' also work). 'hud'/'wasd' are rejected when the matching hudmenu backend is not registered. When the permissions core does not know the user yet the choice is remembered and written as soon as the user loads. Returns false for invalid slots, bots/fake clients, unknown type names and cookie write failures.
   * @param playerSlot (int32): The client's player slot.
   * @param type (string): 'hud', 'button', 'centerhtml' or 'chat'.
   * @return bool: True when the choice was accepted (and persisted once the user is loaded).
   */
  inline bool SetClientMenuType(int32_t playerSlot, const plg::string& type) {
    return __hudmenu_SetClientMenuType(playerSlot, type);
  }

} // namespace hudmenu
