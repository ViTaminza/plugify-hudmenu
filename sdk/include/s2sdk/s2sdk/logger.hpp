#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: logger)

namespace s2sdk {

  using _RegisterLoggingChannel = int32_t (*)(const plg::string&, int32_t, LoggingVerbosity, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_RegisterLoggingChannel __s2sdk_RegisterLoggingChannel;
namespace s2sdk {
  /**
   * @brief Registers a new logging channel with specified properties.
   * @param name (string): The name of the logging channel.
   * @param flags (int32): Flags associated with the logging channel.
   * @param verbosity (int32): The verbosity level for the logging channel.
   * @param color (vec4): The color for messages logged to this channel.
   * @return int32: The ID of the newly created logging channel.
   */
  inline int32_t RegisterLoggingChannel(const plg::string& name, int32_t flags, LoggingVerbosity verbosity, const plg::vec4& color) {
    return __s2sdk_RegisterLoggingChannel(name, flags, verbosity, color);
  }

  using _AddLoggerTagToChannel = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_AddLoggerTagToChannel __s2sdk_AddLoggerTagToChannel;
namespace s2sdk {
  /**
   * @brief Adds a tag to a specified logging channel.
   * @param channelID (int32): The ID of the logging channel to which the tag will be added.
   * @param tagName (string): The name of the tag to add to the channel.
   */
  inline void AddLoggerTagToChannel(int32_t channelID, const plg::string& tagName) {
    return __s2sdk_AddLoggerTagToChannel(channelID, tagName);
  }

  using _HasLoggerTag = bool (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_HasLoggerTag __s2sdk_HasLoggerTag;
namespace s2sdk {
  /**
   * @brief Checks if a specified tag exists in a logging channel.
   * @param channelID (int32): The ID of the logging channel.
   * @param tag (string): The name of the tag to check for.
   * @return bool: True if the tag exists in the channel, otherwise false.
   */
  inline bool HasLoggerTag(int32_t channelID, const plg::string& tag) {
    return __s2sdk_HasLoggerTag(channelID, tag);
  }

  using _IsLoggerChannelEnabledBySeverity = bool (*)(int32_t, LoggingSeverity);
}
extern "C" PLUGIN_API s2sdk::_IsLoggerChannelEnabledBySeverity __s2sdk_IsLoggerChannelEnabledBySeverity;
namespace s2sdk {
  /**
   * @brief Checks if a logging channel is enabled based on severity.
   * @param channelID (int32): The ID of the logging channel.
   * @param severity (int32): The severity of a logging operation.
   * @return bool: True if the channel is enabled for the specified severity, otherwise false.
   */
  inline bool IsLoggerChannelEnabledBySeverity(int32_t channelID, LoggingSeverity severity) {
    return __s2sdk_IsLoggerChannelEnabledBySeverity(channelID, severity);
  }

  using _IsLoggerChannelEnabledByVerbosity = bool (*)(int32_t, LoggingVerbosity);
}
extern "C" PLUGIN_API s2sdk::_IsLoggerChannelEnabledByVerbosity __s2sdk_IsLoggerChannelEnabledByVerbosity;
namespace s2sdk {
  /**
   * @brief Checks if a logging channel is enabled based on verbosity.
   * @param channelID (int32): The ID of the logging channel.
   * @param verbosity (int32): The verbosity level to check.
   * @return bool: True if the channel is enabled for the specified verbosity, otherwise false.
   */
  inline bool IsLoggerChannelEnabledByVerbosity(int32_t channelID, LoggingVerbosity verbosity) {
    return __s2sdk_IsLoggerChannelEnabledByVerbosity(channelID, verbosity);
  }

  using _GetLoggerChannelVerbosity = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetLoggerChannelVerbosity __s2sdk_GetLoggerChannelVerbosity;
namespace s2sdk {
  /**
   * @brief Retrieves the verbosity level of a logging channel.
   * @param channelID (int32): The ID of the logging channel.
   * @return int32: The verbosity level of the specified logging channel.
   */
  inline int32_t GetLoggerChannelVerbosity(int32_t channelID) {
    return __s2sdk_GetLoggerChannelVerbosity(channelID);
  }

  using _SetLoggerChannelVerbosity = void (*)(int32_t, LoggingVerbosity);
}
extern "C" PLUGIN_API s2sdk::_SetLoggerChannelVerbosity __s2sdk_SetLoggerChannelVerbosity;
namespace s2sdk {
  /**
   * @brief Sets the verbosity level of a logging channel.
   * @param channelID (int32): The ID of the logging channel.
   * @param verbosity (int32): The new verbosity level to set.
   */
  inline void SetLoggerChannelVerbosity(int32_t channelID, LoggingVerbosity verbosity) {
    return __s2sdk_SetLoggerChannelVerbosity(channelID, verbosity);
  }

  using _SetLoggerChannelVerbosityByName = void (*)(int32_t, const plg::string&, LoggingVerbosity);
}
extern "C" PLUGIN_API s2sdk::_SetLoggerChannelVerbosityByName __s2sdk_SetLoggerChannelVerbosityByName;
namespace s2sdk {
  /**
   * @brief Sets the verbosity level of a logging channel by name.
   * @param channelID (int32): The ID of the logging channel.
   * @param name (string): The name of the logging channel.
   * @param verbosity (int32): The new verbosity level to set.
   */
  inline void SetLoggerChannelVerbosityByName(int32_t channelID, const plg::string& name, LoggingVerbosity verbosity) {
    return __s2sdk_SetLoggerChannelVerbosityByName(channelID, name, verbosity);
  }

  using _SetLoggerChannelVerbosityByTag = void (*)(int32_t, const plg::string&, LoggingVerbosity);
}
extern "C" PLUGIN_API s2sdk::_SetLoggerChannelVerbosityByTag __s2sdk_SetLoggerChannelVerbosityByTag;
namespace s2sdk {
  /**
   * @brief Sets the verbosity level of a logging channel by tag.
   * @param channelID (int32): The ID of the logging channel.
   * @param tag (string): The name of the tag.
   * @param verbosity (int32): The new verbosity level to set.
   */
  inline void SetLoggerChannelVerbosityByTag(int32_t channelID, const plg::string& tag, LoggingVerbosity verbosity) {
    return __s2sdk_SetLoggerChannelVerbosityByTag(channelID, tag, verbosity);
  }

  using _GetLoggerChannelColor = plg::vec4 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetLoggerChannelColor __s2sdk_GetLoggerChannelColor;
namespace s2sdk {
  /**
   * @brief Retrieves the color setting of a logging channel.
   * @param channelID (int32): The ID of the logging channel.
   * @return vec4: The color value of the specified logging channel.
   */
  inline plg::vec4 GetLoggerChannelColor(int32_t channelID) {
    return __s2sdk_GetLoggerChannelColor(channelID);
  }

  using _SetLoggerChannelColor = void (*)(int32_t, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_SetLoggerChannelColor __s2sdk_SetLoggerChannelColor;
namespace s2sdk {
  /**
   * @brief Sets the color setting of a logging channel.
   * @param channelID (int32): The ID of the logging channel.
   * @param color (vec4): The new color value to set for the channel.
   */
  inline void SetLoggerChannelColor(int32_t channelID, const plg::vec4& color) {
    return __s2sdk_SetLoggerChannelColor(channelID, color);
  }

  using _GetLoggerChannelFlags = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetLoggerChannelFlags __s2sdk_GetLoggerChannelFlags;
namespace s2sdk {
  /**
   * @brief Retrieves the flags of a logging channel.
   * @param channelID (int32): The ID of the logging channel.
   * @return int32: The flags of the specified logging channel.
   */
  inline int32_t GetLoggerChannelFlags(int32_t channelID) {
    return __s2sdk_GetLoggerChannelFlags(channelID);
  }

  using _SetLoggerChannelFlags = void (*)(int32_t, LoggingChannelFlags);
}
extern "C" PLUGIN_API s2sdk::_SetLoggerChannelFlags __s2sdk_SetLoggerChannelFlags;
namespace s2sdk {
  /**
   * @brief Sets the flags of a logging channel.
   * @param channelID (int32): The ID of the logging channel.
   * @param eFlags (int32): The new flags to set for the channel.
   */
  inline void SetLoggerChannelFlags(int32_t channelID, LoggingChannelFlags eFlags) {
    return __s2sdk_SetLoggerChannelFlags(channelID, eFlags);
  }

  using _Log = int32_t (*)(int32_t, LoggingSeverity, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_Log __s2sdk_Log;
namespace s2sdk {
  /**
   * @brief Logs a message to a specified channel with a severity level.
   * @param channelID (int32): The ID of the logging channel.
   * @param severity (int32): The severity level for the log message.
   * @param message (string): The message to log.
   * @return int32: An integer indicating the result of the logging operation.
   */
  inline int32_t Log(int32_t channelID, LoggingSeverity severity, const plg::string& message) {
    return __s2sdk_Log(channelID, severity, message);
  }

  using _LogColored = int32_t (*)(int32_t, LoggingSeverity, const plg::vec4&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_LogColored __s2sdk_LogColored;
namespace s2sdk {
  /**
   * @brief Logs a colored message to a specified channel with a severity level.
   * @param channelID (int32): The ID of the logging channel.
   * @param severity (int32): The severity level for the log message.
   * @param color (vec4): The color for the log message.
   * @param message (string): The message to log.
   * @return int32: An integer indicating the result of the logging operation.
   */
  inline int32_t LogColored(int32_t channelID, LoggingSeverity severity, const plg::vec4& color, const plg::string& message) {
    return __s2sdk_LogColored(channelID, severity, color, message);
  }

  using _LogFull = int32_t (*)(int32_t, LoggingSeverity, const plg::string&, int32_t, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_LogFull __s2sdk_LogFull;
namespace s2sdk {
  /**
   * @brief Logs a detailed message to a specified channel, including source code info.
   * @param channelID (int32): The ID of the logging channel.
   * @param severity (int32): The severity level for the log message.
   * @param file (string): The file name where the log call occurred.
   * @param line (int32): The line number where the log call occurred.
   * @param function (string): The name of the function where the log call occurred.
   * @param message (string): The message to log.
   * @return int32: An integer indicating the result of the logging operation.
   */
  inline int32_t LogFull(int32_t channelID, LoggingSeverity severity, const plg::string& file, int32_t line, const plg::string& function, const plg::string& message) {
    return __s2sdk_LogFull(channelID, severity, file, line, function, message);
  }

  using _LogFullColored = int32_t (*)(int32_t, LoggingSeverity, const plg::string&, int32_t, const plg::string&, const plg::vec4&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_LogFullColored __s2sdk_LogFullColored;
namespace s2sdk {
  /**
   * @brief Logs a detailed colored message to a specified channel, including source code info.
   * @param channelID (int32): The ID of the logging channel.
   * @param severity (int32): The severity level for the log message.
   * @param file (string): The file name where the log call occurred.
   * @param line (int32): The line number where the log call occurred.
   * @param function (string): The name of the function where the log call occurred.
   * @param color (vec4): The color for the log message.
   * @param message (string): The message to log.
   * @return int32: An integer indicating the result of the logging operation.
   */
  inline int32_t LogFullColored(int32_t channelID, LoggingSeverity severity, const plg::string& file, int32_t line, const plg::string& function, const plg::vec4& color, const plg::string& message) {
    return __s2sdk_LogFullColored(channelID, severity, file, line, function, color, message);
  }

} // namespace s2sdk
