#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: console)

namespace s2sdk {

  using _PrintToServer = void (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PrintToServer __s2sdk_PrintToServer;
namespace s2sdk {
  /**
   * @brief Sends a message to the server console.
   * @param msg (string): The message to be sent to the server console.
   */
  inline void PrintToServer(const plg::string& msg) {
    return __s2sdk_PrintToServer(msg);
  }

  using _PrintToConsole = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PrintToConsole __s2sdk_PrintToConsole;
namespace s2sdk {
  /**
   * @brief Sends a message to a client's console.
   * @param playerSlot (int32): The index of the player's slot to whom the message will be sent.
   * @param message (string): The message to be sent to the client's console.
   */
  inline void PrintToConsole(int32_t playerSlot, const plg::string& message) {
    return __s2sdk_PrintToConsole(playerSlot, message);
  }

  using _PrintToChat = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PrintToChat __s2sdk_PrintToChat;
namespace s2sdk {
  /**
   * @brief Prints a message to a specific client in the chat area.
   * @param playerSlot (int32): The index of the player's slot to whom the message will be sent.
   * @param message (string): The message to be printed in the chat area.
   */
  inline void PrintToChat(int32_t playerSlot, const plg::string& message) {
    return __s2sdk_PrintToChat(playerSlot, message);
  }

  using _PrintCenterText = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PrintCenterText __s2sdk_PrintCenterText;
namespace s2sdk {
  /**
   * @brief Prints a message to a specific client in the center of the screen.
   * @param playerSlot (int32): The index of the player's slot to whom the message will be sent.
   * @param message (string): The message to be printed in the center of the screen.
   */
  inline void PrintCenterText(int32_t playerSlot, const plg::string& message) {
    return __s2sdk_PrintCenterText(playerSlot, message);
  }

  using _PrintAlertText = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PrintAlertText __s2sdk_PrintAlertText;
namespace s2sdk {
  /**
   * @brief Prints a message to a specific client with an alert box.
   * @param playerSlot (int32): The index of the player's slot to whom the message will be sent.
   * @param message (string): The message to be printed in the alert box.
   */
  inline void PrintAlertText(int32_t playerSlot, const plg::string& message) {
    return __s2sdk_PrintAlertText(playerSlot, message);
  }

  using _PrintCentreHtml = void (*)(int32_t, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PrintCentreHtml __s2sdk_PrintCentreHtml;
namespace s2sdk {
  /**
   * @brief Prints a html message to a specific client in the center of the screen.
   * @param playerSlot (int32): The index of the player's slot to whom the message will be sent.
   * @param message (string): The HTML-formatted message to be printed.
   * @param duration (int32): The duration of the message in seconds.
   */
  inline void PrintCentreHtml(int32_t playerSlot, const plg::string& message, int32_t duration) {
    return __s2sdk_PrintCentreHtml(playerSlot, message, duration);
  }

  using _PrintToConsoleAll = void (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PrintToConsoleAll __s2sdk_PrintToConsoleAll;
namespace s2sdk {
  /**
   * @brief Sends a message to every client's console.
   * @param message (string): The message to be sent to all clients' consoles.
   */
  inline void PrintToConsoleAll(const plg::string& message) {
    return __s2sdk_PrintToConsoleAll(message);
  }

  using _PrintToChatAll = void (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PrintToChatAll __s2sdk_PrintToChatAll;
namespace s2sdk {
  /**
   * @brief Prints a message to all clients in the chat area.
   * @param message (string): The message to be printed in the chat area for all clients.
   */
  inline void PrintToChatAll(const plg::string& message) {
    return __s2sdk_PrintToChatAll(message);
  }

  using _PrintCenterTextAll = void (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PrintCenterTextAll __s2sdk_PrintCenterTextAll;
namespace s2sdk {
  /**
   * @brief Prints a message to all clients in the center of the screen.
   * @param message (string): The message to be printed in the center of the screen for all clients.
   */
  inline void PrintCenterTextAll(const plg::string& message) {
    return __s2sdk_PrintCenterTextAll(message);
  }

  using _PrintAlertTextAll = void (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PrintAlertTextAll __s2sdk_PrintAlertTextAll;
namespace s2sdk {
  /**
   * @brief Prints a message to all clients with an alert box.
   * @param message (string): The message to be printed in an alert box for all clients.
   */
  inline void PrintAlertTextAll(const plg::string& message) {
    return __s2sdk_PrintAlertTextAll(message);
  }

  using _PrintCentreHtmlAll = void (*)(const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PrintCentreHtmlAll __s2sdk_PrintCentreHtmlAll;
namespace s2sdk {
  /**
   * @brief Prints a html message to all clients in the center of the screen.
   * @param message (string): The HTML-formatted message to be printed in the center of the screen for all clients.
   * @param duration (int32): The duration of the message in seconds.
   */
  inline void PrintCentreHtmlAll(const plg::string& message, int32_t duration) {
    return __s2sdk_PrintCentreHtmlAll(message, duration);
  }

  using _PrintToChatColored = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PrintToChatColored __s2sdk_PrintToChatColored;
namespace s2sdk {
  /**
   * @brief Prints a colored message to a specific client in the chat area.
   * @param playerSlot (int32): The index of the player's slot to whom the message will be sent.
   * @param message (string): The message to be printed in the chat area with color.
   */
  inline void PrintToChatColored(int32_t playerSlot, const plg::string& message) {
    return __s2sdk_PrintToChatColored(playerSlot, message);
  }

  using _PrintToChatColoredAll = void (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PrintToChatColoredAll __s2sdk_PrintToChatColoredAll;
namespace s2sdk {
  /**
   * @brief Prints a colored message to all clients in the chat area.
   * @param message (string): The colored message to be printed in the chat area for all clients.
   */
  inline void PrintToChatColoredAll(const plg::string& message) {
    return __s2sdk_PrintToChatColoredAll(message);
  }

  using _ReplyToCommand = void (*)(ConCommandContext, int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_ReplyToCommand __s2sdk_ReplyToCommand;
namespace s2sdk {
  /**
   * @brief Sends a reply message to a player or to the server console depending on the command context.
   * @param context (int32): The context from which the command was called (e.g., Console or Chat).
   * @param playerSlot (int32): The slot/index of the player receiving the message.
   * @param message (string): The message string to be sent as a reply.
   */
  inline void ReplyToCommand(ConCommandContext context, int32_t playerSlot, const plg::string& message) {
    return __s2sdk_ReplyToCommand(context, playerSlot, message);
  }

} // namespace s2sdk
