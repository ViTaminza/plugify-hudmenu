#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: cvars)

namespace s2sdk {

  using _CreateConVar = uint64_t (*)(const plg::string&, const plg::any&, const plg::string&, ConVarFlag);
}
extern "C" PLUGIN_API s2sdk::_CreateConVar __s2sdk_CreateConVar;
namespace s2sdk {
  /**
   * @brief Creates a new console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (any): The default value of the console variable.
   * @param description (string): A description of the console variable's purpose.
   * @param flags (int64): Additional flags for the console variable.
   * @return uint64: A handle to the created console variable.
   */
  inline uint64_t CreateConVar(const plg::string& name, const plg::any& defaultValue, const plg::string& description, ConVarFlag flags) {
    return __s2sdk_CreateConVar(name, defaultValue, description, flags);
  }

  using _CreateConVarBool = uint64_t (*)(const plg::string&, bool, const plg::string&, ConVarFlag, bool, bool, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarBool __s2sdk_CreateConVarBool;
namespace s2sdk {
  /**
   * @brief Creates a new boolean console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (bool): The default value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (bool): The minimum value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (bool): The maximum value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarBool(const plg::string& name, bool defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, bool min, bool hasMax, bool max) {
    return __s2sdk_CreateConVarBool(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarInt16 = uint64_t (*)(const plg::string&, int16_t, const plg::string&, ConVarFlag, bool, int16_t, bool, int16_t);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarInt16 __s2sdk_CreateConVarInt16;
namespace s2sdk {
  /**
   * @brief Creates a new 16-bit signed integer console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (int16): The default value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (int16): The minimum value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (int16): The maximum value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarInt16(const plg::string& name, int16_t defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, int16_t min, bool hasMax, int16_t max) {
    return __s2sdk_CreateConVarInt16(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarUInt16 = uint64_t (*)(const plg::string&, uint16_t, const plg::string&, ConVarFlag, bool, uint16_t, bool, uint16_t);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarUInt16 __s2sdk_CreateConVarUInt16;
namespace s2sdk {
  /**
   * @brief Creates a new 16-bit unsigned integer console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (uint16): The default value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (uint16): The minimum value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (uint16): The maximum value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarUInt16(const plg::string& name, uint16_t defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, uint16_t min, bool hasMax, uint16_t max) {
    return __s2sdk_CreateConVarUInt16(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarInt32 = uint64_t (*)(const plg::string&, int32_t, const plg::string&, ConVarFlag, bool, int32_t, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarInt32 __s2sdk_CreateConVarInt32;
namespace s2sdk {
  /**
   * @brief Creates a new 32-bit signed integer console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (int32): The default value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (int32): The minimum value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (int32): The maximum value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarInt32(const plg::string& name, int32_t defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, int32_t min, bool hasMax, int32_t max) {
    return __s2sdk_CreateConVarInt32(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarUInt32 = uint64_t (*)(const plg::string&, uint32_t, const plg::string&, ConVarFlag, bool, uint32_t, bool, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarUInt32 __s2sdk_CreateConVarUInt32;
namespace s2sdk {
  /**
   * @brief Creates a new 32-bit unsigned integer console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (uint32): The default value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (uint32): The minimum value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (uint32): The maximum value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarUInt32(const plg::string& name, uint32_t defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, uint32_t min, bool hasMax, uint32_t max) {
    return __s2sdk_CreateConVarUInt32(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarInt64 = uint64_t (*)(const plg::string&, int64_t, const plg::string&, ConVarFlag, bool, int64_t, bool, int64_t);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarInt64 __s2sdk_CreateConVarInt64;
namespace s2sdk {
  /**
   * @brief Creates a new 64-bit signed integer console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (int64): The default value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (int64): The minimum value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (int64): The maximum value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarInt64(const plg::string& name, int64_t defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, int64_t min, bool hasMax, int64_t max) {
    return __s2sdk_CreateConVarInt64(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarUInt64 = uint64_t (*)(const plg::string&, uint64_t, const plg::string&, ConVarFlag, bool, uint64_t, bool, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarUInt64 __s2sdk_CreateConVarUInt64;
namespace s2sdk {
  /**
   * @brief Creates a new 64-bit unsigned integer console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (uint64): The default value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (uint64): The minimum value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (uint64): The maximum value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarUInt64(const plg::string& name, uint64_t defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, uint64_t min, bool hasMax, uint64_t max) {
    return __s2sdk_CreateConVarUInt64(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarFloat = uint64_t (*)(const plg::string&, float, const plg::string&, ConVarFlag, bool, float, bool, float);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarFloat __s2sdk_CreateConVarFloat;
namespace s2sdk {
  /**
   * @brief Creates a new floating-point console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (float): The default value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (float): The minimum value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (float): The maximum value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarFloat(const plg::string& name, float defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, float min, bool hasMax, float max) {
    return __s2sdk_CreateConVarFloat(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarDouble = uint64_t (*)(const plg::string&, double, const plg::string&, ConVarFlag, bool, double, bool, double);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarDouble __s2sdk_CreateConVarDouble;
namespace s2sdk {
  /**
   * @brief Creates a new double-precision console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (double): The default value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (double): The minimum value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (double): The maximum value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarDouble(const plg::string& name, double defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, double min, bool hasMax, double max) {
    return __s2sdk_CreateConVarDouble(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarColor = uint64_t (*)(const plg::string&, const plg::vec4&, const plg::string&, ConVarFlag, bool, const plg::vec4&, bool, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarColor __s2sdk_CreateConVarColor;
namespace s2sdk {
  /**
   * @brief Creates a new color console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (vec4): The default color value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (vec4): The minimum color value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (vec4): The maximum color value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarColor(const plg::string& name, const plg::vec4& defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, const plg::vec4& min, bool hasMax, const plg::vec4& max) {
    return __s2sdk_CreateConVarColor(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarVector2 = uint64_t (*)(const plg::string&, const plg::vec2&, const plg::string&, ConVarFlag, bool, const plg::vec2&, bool, const plg::vec2&);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarVector2 __s2sdk_CreateConVarVector2;
namespace s2sdk {
  /**
   * @brief Creates a new 2D vector console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (vec2): The default value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (vec2): The minimum value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (vec2): The maximum value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarVector2(const plg::string& name, const plg::vec2& defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, const plg::vec2& min, bool hasMax, const plg::vec2& max) {
    return __s2sdk_CreateConVarVector2(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarVector3 = uint64_t (*)(const plg::string&, const plg::vec3&, const plg::string&, ConVarFlag, bool, const plg::vec3&, bool, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarVector3 __s2sdk_CreateConVarVector3;
namespace s2sdk {
  /**
   * @brief Creates a new 3D vector console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (vec3): The default value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (vec3): The minimum value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (vec3): The maximum value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarVector3(const plg::string& name, const plg::vec3& defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, const plg::vec3& min, bool hasMax, const plg::vec3& max) {
    return __s2sdk_CreateConVarVector3(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarVector4 = uint64_t (*)(const plg::string&, const plg::vec4&, const plg::string&, ConVarFlag, bool, const plg::vec4&, bool, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarVector4 __s2sdk_CreateConVarVector4;
namespace s2sdk {
  /**
   * @brief Creates a new 4D vector console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (vec4): The default value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (vec4): The minimum value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (vec4): The maximum value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarVector4(const plg::string& name, const plg::vec4& defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, const plg::vec4& min, bool hasMax, const plg::vec4& max) {
    return __s2sdk_CreateConVarVector4(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarQAngle = uint64_t (*)(const plg::string&, const plg::vec3&, const plg::string&, ConVarFlag, bool, const plg::vec3&, bool, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarQAngle __s2sdk_CreateConVarQAngle;
namespace s2sdk {
  /**
   * @brief Creates a new quaternion angle console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (vec3): The default value for the console variable.
   * @param description (string): A brief description of the console variable.
   * @param flags (int64): Flags that define the behavior of the console variable.
   * @param hasMin (bool): Indicates if a minimum value is provided.
   * @param min (vec3): The minimum value if hasMin is true.
   * @param hasMax (bool): Indicates if a maximum value is provided.
   * @param max (vec3): The maximum value if hasMax is true.
   * @return uint64: A handle to the created console variable data.
   */
  inline uint64_t CreateConVarQAngle(const plg::string& name, const plg::vec3& defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, const plg::vec3& min, bool hasMax, const plg::vec3& max) {
    return __s2sdk_CreateConVarQAngle(name, defaultValue, description, flags, hasMin, min, hasMax, max);
  }

  using _CreateConVarString = uint64_t (*)(const plg::string&, const plg::string&, const plg::string&, ConVarFlag);
}
extern "C" PLUGIN_API s2sdk::_CreateConVarString __s2sdk_CreateConVarString;
namespace s2sdk {
  /**
   * @brief Creates a new string console variable.
   * @param name (string): The name of the console variable.
   * @param defaultValue (string): The default value of the console variable.
   * @param description (string): A description of the console variable's purpose.
   * @param flags (int64): Additional flags for the console variable.
   * @return uint64: A handle to the created console variable.
   */
  inline uint64_t CreateConVarString(const plg::string& name, const plg::string& defaultValue, const plg::string& description, ConVarFlag flags) {
    return __s2sdk_CreateConVarString(name, defaultValue, description, flags);
  }

  using _FindConVar = uint64_t (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_FindConVar __s2sdk_FindConVar;
namespace s2sdk {
  /**
   * @brief Searches for a console variable.
   * @param name (string): The name of the console variable to search for.
   * @return uint64: A handle to the console variable data if found; otherwise, nullptr.
   */
  inline uint64_t FindConVar(const plg::string& name) {
    return __s2sdk_FindConVar(name);
  }

  using _FindConVar2 = uint64_t (*)(const plg::string&, ConVarType);
}
extern "C" PLUGIN_API s2sdk::_FindConVar2 __s2sdk_FindConVar2;
namespace s2sdk {
  /**
   * @brief Searches for a console variable of a specific type.
   * @param name (string): The name of the console variable to search for.
   * @param type (int16): The type of the console variable to search for.
   * @return uint64: A handle to the console variable data if found; otherwise, nullptr.
   */
  inline uint64_t FindConVar2(const plg::string& name, ConVarType type) {
    return __s2sdk_FindConVar2(name, type);
  }

  using _HookConVarChange = void (*)(uint64_t, ConVarCallback);
}
extern "C" PLUGIN_API s2sdk::_HookConVarChange __s2sdk_HookConVarChange;
namespace s2sdk {
  /**
   * @brief Creates a hook for when a console variable's value is changed.
   * @param conVarHandle (uint64): TThe handle to the console variable data.
   * @param callback (function): The callback function to be executed when the variable's value changes.
   */
  inline void HookConVarChange(uint64_t conVarHandle, ConVarCallback callback) {
    return __s2sdk_HookConVarChange(conVarHandle, callback);
  }

  using _UnhookConVarChange = void (*)(uint64_t, ConVarCallback);
}
extern "C" PLUGIN_API s2sdk::_UnhookConVarChange __s2sdk_UnhookConVarChange;
namespace s2sdk {
  /**
   * @brief Removes a hook for when a console variable's value is changed.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param callback (function): The callback function to be removed.
   */
  inline void UnhookConVarChange(uint64_t conVarHandle, ConVarCallback callback) {
    return __s2sdk_UnhookConVarChange(conVarHandle, callback);
  }

  using _IsConVarFlagSet = bool (*)(uint64_t, int64_t);
}
extern "C" PLUGIN_API s2sdk::_IsConVarFlagSet __s2sdk_IsConVarFlagSet;
namespace s2sdk {
  /**
   * @brief Checks if a specific flag is set for a console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param flag (int64): The flag to check against the console variable.
   * @return bool: True if the flag is set; otherwise, false.
   */
  inline bool IsConVarFlagSet(uint64_t conVarHandle, int64_t flag) {
    return __s2sdk_IsConVarFlagSet(conVarHandle, flag);
  }

  using _AddConVarFlags = void (*)(uint64_t, ConVarFlag);
}
extern "C" PLUGIN_API s2sdk::_AddConVarFlags __s2sdk_AddConVarFlags;
namespace s2sdk {
  /**
   * @brief Adds flags to a console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param flags (int64): The flags to be added.
   */
  inline void AddConVarFlags(uint64_t conVarHandle, ConVarFlag flags) {
    return __s2sdk_AddConVarFlags(conVarHandle, flags);
  }

  using _RemoveConVarFlags = void (*)(uint64_t, ConVarFlag);
}
extern "C" PLUGIN_API s2sdk::_RemoveConVarFlags __s2sdk_RemoveConVarFlags;
namespace s2sdk {
  /**
   * @brief Removes flags from a console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param flags (int64): The flags to be removed.
   */
  inline void RemoveConVarFlags(uint64_t conVarHandle, ConVarFlag flags) {
    return __s2sdk_RemoveConVarFlags(conVarHandle, flags);
  }

  using _GetConVarFlags = ConVarFlag (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarFlags __s2sdk_GetConVarFlags;
namespace s2sdk {
  /**
   * @brief Retrieves the current flags of a console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return int64: The current flags set on the console variable.
   */
  inline ConVarFlag GetConVarFlags(uint64_t conVarHandle) {
    return __s2sdk_GetConVarFlags(conVarHandle);
  }

  using _GetConVarBounds = plg::string (*)(uint64_t, bool);
}
extern "C" PLUGIN_API s2sdk::_GetConVarBounds __s2sdk_GetConVarBounds;
namespace s2sdk {
  /**
   * @brief Gets the specified bound (max or min) of a console variable and stores it in the output string.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param max (bool): Indicates whether to get the maximum (true) or minimum (false) bound.
   * @return string: The bound value.
   */
  inline plg::string GetConVarBounds(uint64_t conVarHandle, bool max) {
    return __s2sdk_GetConVarBounds(conVarHandle, max);
  }

  using _SetConVarBounds = void (*)(uint64_t, bool, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetConVarBounds __s2sdk_SetConVarBounds;
namespace s2sdk {
  /**
   * @brief Sets the specified bound (max or min) for a console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param max (bool): Indicates whether to set the maximum (true) or minimum (false) bound.
   * @param value (string): The value to set as the bound.
   */
  inline void SetConVarBounds(uint64_t conVarHandle, bool max, const plg::string& value) {
    return __s2sdk_SetConVarBounds(conVarHandle, max, value);
  }

  using _GetConVarDefault = plg::string (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarDefault __s2sdk_GetConVarDefault;
namespace s2sdk {
  /**
   * @brief Retrieves the default value of a console variable and stores it in the output string.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return string: The output value in string format.
   */
  inline plg::string GetConVarDefault(uint64_t conVarHandle) {
    return __s2sdk_GetConVarDefault(conVarHandle);
  }

  using _SetConVarDefault = void (*)(uint64_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetConVarDefault __s2sdk_SetConVarDefault;
namespace s2sdk {
  /**
   * @brief Sets the specified default value for a console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (string): The value to set as the default.
   */
  inline void SetConVarDefault(uint64_t conVarHandle, const plg::string& value) {
    return __s2sdk_SetConVarDefault(conVarHandle, value);
  }

  using _GetConVarValue = plg::string (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarValue __s2sdk_GetConVarValue;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a console variable and stores it in the output string.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return string: The output value in string format.
   */
  inline plg::string GetConVarValue(uint64_t conVarHandle) {
    return __s2sdk_GetConVarValue(conVarHandle);
  }

  using _GetConVar = plg::any (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVar __s2sdk_GetConVar;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a console variable and stores it in the output.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return any: The output value.
   */
  inline plg::any GetConVar(uint64_t conVarHandle) {
    return __s2sdk_GetConVar(conVarHandle);
  }

  using _GetConVarBool = bool (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarBool __s2sdk_GetConVarBool;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a boolean console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return bool: The current boolean value of the console variable.
   */
  inline bool GetConVarBool(uint64_t conVarHandle) {
    return __s2sdk_GetConVarBool(conVarHandle);
  }

  using _GetConVarInt16 = int16_t (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarInt16 __s2sdk_GetConVarInt16;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a signed 16-bit integer console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return int16: The current int16_t value of the console variable.
   */
  inline int16_t GetConVarInt16(uint64_t conVarHandle) {
    return __s2sdk_GetConVarInt16(conVarHandle);
  }

  using _GetConVarUInt16 = uint16_t (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarUInt16 __s2sdk_GetConVarUInt16;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of an unsigned 16-bit integer console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return uint16: The current uint16_t value of the console variable.
   */
  inline uint16_t GetConVarUInt16(uint64_t conVarHandle) {
    return __s2sdk_GetConVarUInt16(conVarHandle);
  }

  using _GetConVarInt32 = int32_t (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarInt32 __s2sdk_GetConVarInt32;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a signed 32-bit integer console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return int32: The current int32_t value of the console variable.
   */
  inline int32_t GetConVarInt32(uint64_t conVarHandle) {
    return __s2sdk_GetConVarInt32(conVarHandle);
  }

  using _GetConVarUInt32 = uint32_t (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarUInt32 __s2sdk_GetConVarUInt32;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of an unsigned 32-bit integer console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return uint32: The current uint32_t value of the console variable.
   */
  inline uint32_t GetConVarUInt32(uint64_t conVarHandle) {
    return __s2sdk_GetConVarUInt32(conVarHandle);
  }

  using _GetConVarInt64 = int64_t (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarInt64 __s2sdk_GetConVarInt64;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a signed 64-bit integer console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return int64: The current int64_t value of the console variable.
   */
  inline int64_t GetConVarInt64(uint64_t conVarHandle) {
    return __s2sdk_GetConVarInt64(conVarHandle);
  }

  using _GetConVarUInt64 = uint64_t (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarUInt64 __s2sdk_GetConVarUInt64;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of an unsigned 64-bit integer console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return uint64: The current uint64_t value of the console variable.
   */
  inline uint64_t GetConVarUInt64(uint64_t conVarHandle) {
    return __s2sdk_GetConVarUInt64(conVarHandle);
  }

  using _GetConVarFloat = float (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarFloat __s2sdk_GetConVarFloat;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a float console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return float: The current float value of the console variable.
   */
  inline float GetConVarFloat(uint64_t conVarHandle) {
    return __s2sdk_GetConVarFloat(conVarHandle);
  }

  using _GetConVarDouble = double (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarDouble __s2sdk_GetConVarDouble;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a double console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return double: The current double value of the console variable.
   */
  inline double GetConVarDouble(uint64_t conVarHandle) {
    return __s2sdk_GetConVarDouble(conVarHandle);
  }

  using _GetConVarString = plg::string (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarString __s2sdk_GetConVarString;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a string console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return string: The current string value of the console variable.
   */
  inline plg::string GetConVarString(uint64_t conVarHandle) {
    return __s2sdk_GetConVarString(conVarHandle);
  }

  using _GetConVarColor = plg::vec4 (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarColor __s2sdk_GetConVarColor;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a Color console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return vec4: The current Color value of the console variable.
   */
  inline plg::vec4 GetConVarColor(uint64_t conVarHandle) {
    return __s2sdk_GetConVarColor(conVarHandle);
  }

  using _GetConVarVector2 = plg::vec2 (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarVector2 __s2sdk_GetConVarVector2;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a Vector2D console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return vec2: The current Vector2D value of the console variable.
   */
  inline plg::vec2 GetConVarVector2(uint64_t conVarHandle) {
    return __s2sdk_GetConVarVector2(conVarHandle);
  }

  using _GetConVarVector = plg::vec3 (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarVector __s2sdk_GetConVarVector;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a Vector console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return vec3: The current Vector value of the console variable.
   */
  inline plg::vec3 GetConVarVector(uint64_t conVarHandle) {
    return __s2sdk_GetConVarVector(conVarHandle);
  }

  using _GetConVarVector4 = plg::vec4 (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarVector4 __s2sdk_GetConVarVector4;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a Vector4D console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return vec4: The current Vector4D value of the console variable.
   */
  inline plg::vec4 GetConVarVector4(uint64_t conVarHandle) {
    return __s2sdk_GetConVarVector4(conVarHandle);
  }

  using _GetConVarQAngle = plg::vec3 (*)(uint64_t);
}
extern "C" PLUGIN_API s2sdk::_GetConVarQAngle __s2sdk_GetConVarQAngle;
namespace s2sdk {
  /**
   * @brief Retrieves the current value of a QAngle console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @return vec3: The current QAngle value of the console variable.
   */
  inline plg::vec3 GetConVarQAngle(uint64_t conVarHandle) {
    return __s2sdk_GetConVarQAngle(conVarHandle);
  }

  using _SetConVarValue = void (*)(uint64_t, const plg::string&, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarValue __s2sdk_SetConVarValue;
namespace s2sdk {
  /**
   * @brief Sets the value of a console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (string): The string value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarValue(uint64_t conVarHandle, const plg::string& value, bool replicate, bool notify) {
    return __s2sdk_SetConVarValue(conVarHandle, value, replicate, notify);
  }

  using _SetConVar = void (*)(uint64_t, const plg::any&, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVar __s2sdk_SetConVar;
namespace s2sdk {
  /**
   * @brief Sets the value of a console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (any): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVar(uint64_t conVarHandle, const plg::any& value, bool replicate, bool notify) {
    return __s2sdk_SetConVar(conVarHandle, value, replicate, notify);
  }

  using _SetConVarBool = void (*)(uint64_t, bool, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarBool __s2sdk_SetConVarBool;
namespace s2sdk {
  /**
   * @brief Sets the value of a boolean console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (bool): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarBool(uint64_t conVarHandle, bool value, bool replicate, bool notify) {
    return __s2sdk_SetConVarBool(conVarHandle, value, replicate, notify);
  }

  using _SetConVarInt16 = void (*)(uint64_t, int16_t, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarInt16 __s2sdk_SetConVarInt16;
namespace s2sdk {
  /**
   * @brief Sets the value of a signed 16-bit integer console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (int16): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarInt16(uint64_t conVarHandle, int16_t value, bool replicate, bool notify) {
    return __s2sdk_SetConVarInt16(conVarHandle, value, replicate, notify);
  }

  using _SetConVarUInt16 = void (*)(uint64_t, uint16_t, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarUInt16 __s2sdk_SetConVarUInt16;
namespace s2sdk {
  /**
   * @brief Sets the value of an unsigned 16-bit integer console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (uint16): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarUInt16(uint64_t conVarHandle, uint16_t value, bool replicate, bool notify) {
    return __s2sdk_SetConVarUInt16(conVarHandle, value, replicate, notify);
  }

  using _SetConVarInt32 = void (*)(uint64_t, int32_t, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarInt32 __s2sdk_SetConVarInt32;
namespace s2sdk {
  /**
   * @brief Sets the value of a signed 32-bit integer console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (int32): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarInt32(uint64_t conVarHandle, int32_t value, bool replicate, bool notify) {
    return __s2sdk_SetConVarInt32(conVarHandle, value, replicate, notify);
  }

  using _SetConVarUInt32 = void (*)(uint64_t, uint32_t, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarUInt32 __s2sdk_SetConVarUInt32;
namespace s2sdk {
  /**
   * @brief Sets the value of an unsigned 32-bit integer console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (uint32): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarUInt32(uint64_t conVarHandle, uint32_t value, bool replicate, bool notify) {
    return __s2sdk_SetConVarUInt32(conVarHandle, value, replicate, notify);
  }

  using _SetConVarInt64 = void (*)(uint64_t, int64_t, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarInt64 __s2sdk_SetConVarInt64;
namespace s2sdk {
  /**
   * @brief Sets the value of a signed 64-bit integer console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (int64): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarInt64(uint64_t conVarHandle, int64_t value, bool replicate, bool notify) {
    return __s2sdk_SetConVarInt64(conVarHandle, value, replicate, notify);
  }

  using _SetConVarUInt64 = void (*)(uint64_t, uint64_t, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarUInt64 __s2sdk_SetConVarUInt64;
namespace s2sdk {
  /**
   * @brief Sets the value of an unsigned 64-bit integer console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (uint64): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarUInt64(uint64_t conVarHandle, uint64_t value, bool replicate, bool notify) {
    return __s2sdk_SetConVarUInt64(conVarHandle, value, replicate, notify);
  }

  using _SetConVarFloat = void (*)(uint64_t, float, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarFloat __s2sdk_SetConVarFloat;
namespace s2sdk {
  /**
   * @brief Sets the value of a floating-point console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (float): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarFloat(uint64_t conVarHandle, float value, bool replicate, bool notify) {
    return __s2sdk_SetConVarFloat(conVarHandle, value, replicate, notify);
  }

  using _SetConVarDouble = void (*)(uint64_t, double, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarDouble __s2sdk_SetConVarDouble;
namespace s2sdk {
  /**
   * @brief Sets the value of a double-precision floating-point console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (double): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarDouble(uint64_t conVarHandle, double value, bool replicate, bool notify) {
    return __s2sdk_SetConVarDouble(conVarHandle, value, replicate, notify);
  }

  using _SetConVarString = void (*)(uint64_t, const plg::string&, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarString __s2sdk_SetConVarString;
namespace s2sdk {
  /**
   * @brief Sets the value of a string console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (string): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarString(uint64_t conVarHandle, const plg::string& value, bool replicate, bool notify) {
    return __s2sdk_SetConVarString(conVarHandle, value, replicate, notify);
  }

  using _SetConVarColor = void (*)(uint64_t, const plg::vec4&, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarColor __s2sdk_SetConVarColor;
namespace s2sdk {
  /**
   * @brief Sets the value of a color console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (vec4): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarColor(uint64_t conVarHandle, const plg::vec4& value, bool replicate, bool notify) {
    return __s2sdk_SetConVarColor(conVarHandle, value, replicate, notify);
  }

  using _SetConVarVector2 = void (*)(uint64_t, const plg::vec2&, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarVector2 __s2sdk_SetConVarVector2;
namespace s2sdk {
  /**
   * @brief Sets the value of a 2D vector console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (vec2): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarVector2(uint64_t conVarHandle, const plg::vec2& value, bool replicate, bool notify) {
    return __s2sdk_SetConVarVector2(conVarHandle, value, replicate, notify);
  }

  using _SetConVarVector3 = void (*)(uint64_t, const plg::vec3&, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarVector3 __s2sdk_SetConVarVector3;
namespace s2sdk {
  /**
   * @brief Sets the value of a 3D vector console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (vec3): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarVector3(uint64_t conVarHandle, const plg::vec3& value, bool replicate, bool notify) {
    return __s2sdk_SetConVarVector3(conVarHandle, value, replicate, notify);
  }

  using _SetConVarVector4 = void (*)(uint64_t, const plg::vec4&, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarVector4 __s2sdk_SetConVarVector4;
namespace s2sdk {
  /**
   * @brief Sets the value of a 4D vector console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (vec4): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarVector4(uint64_t conVarHandle, const plg::vec4& value, bool replicate, bool notify) {
    return __s2sdk_SetConVarVector4(conVarHandle, value, replicate, notify);
  }

  using _SetConVarQAngle = void (*)(uint64_t, const plg::vec3&, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_SetConVarQAngle __s2sdk_SetConVarQAngle;
namespace s2sdk {
  /**
   * @brief Sets the value of a quaternion angle console variable.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (vec3): The value to set for the console variable.
   * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
   * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
   */
  inline void SetConVarQAngle(uint64_t conVarHandle, const plg::vec3& value, bool replicate, bool notify) {
    return __s2sdk_SetConVarQAngle(conVarHandle, value, replicate, notify);
  }

  using _SendConVarValue = void (*)(int32_t, uint64_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SendConVarValue __s2sdk_SendConVarValue;
namespace s2sdk {
  /**
   * @brief Replicates a console variable value to a specific client. This does not change the actual console variable value.
   * @param playerSlot (int32): The index of the client to replicate the value to.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param value (string): The value to send to the client.
   */
  inline void SendConVarValue(int32_t playerSlot, uint64_t conVarHandle, const plg::string& value) {
    return __s2sdk_SendConVarValue(playerSlot, conVarHandle, value);
  }

  using _SendConVarValue2 = void (*)(uint64_t, int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SendConVarValue2 __s2sdk_SendConVarValue2;
namespace s2sdk {
  /**
   * @brief Replicates a console variable value to a specific client. This does not change the actual console variable value.
   * @param conVarHandle (uint64): The handle to the console variable data.
   * @param playerSlot (int32): The index of the client to replicate the value to.
   * @param value (string): The value to send to the client.
   */
  inline void SendConVarValue2(uint64_t conVarHandle, int32_t playerSlot, const plg::string& value) {
    return __s2sdk_SendConVarValue2(conVarHandle, playerSlot, value);
  }

  using _GetClientConVarValue = plg::string (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetClientConVarValue __s2sdk_GetClientConVarValue;
namespace s2sdk {
  /**
   * @brief Retrieves the value of a client's console variable and stores it in the output string.
   * @param playerSlot (int32): The index of the client whose console variable value is being retrieved.
   * @param convarName (string): The name of the console variable to retrieve.
   * @return string: The output string to store the client's console variable value.
   */
  inline plg::string GetClientConVarValue(int32_t playerSlot, const plg::string& convarName) {
    return __s2sdk_GetClientConVarValue(playerSlot, convarName);
  }

  using _SetFakeClientConVarValue = void (*)(int32_t, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetFakeClientConVarValue __s2sdk_SetFakeClientConVarValue;
namespace s2sdk {
  /**
   * @brief Replicates a console variable value to a specific fake client. This does not change the actual console variable value.
   * @param playerSlot (int32): The index of the fake client to replicate the value to.
   * @param convarName (string): The name of the console variable.
   * @param convarValue (string): The value to set for the console variable.
   */
  inline void SetFakeClientConVarValue(int32_t playerSlot, const plg::string& convarName, const plg::string& convarValue) {
    return __s2sdk_SetFakeClientConVarValue(playerSlot, convarName, convarValue);
  }

  using _QueryClientConVar = int32_t (*)(int32_t, const plg::string&, CvarValueCallback, const plg::vector<plg::any>&);
}
extern "C" PLUGIN_API s2sdk::_QueryClientConVar __s2sdk_QueryClientConVar;
namespace s2sdk {
  /**
   * @brief Starts a query to retrieve the value of a client's console variable.
   * @param playerSlot (int32): The index of the player's slot to query the value from.
   * @param convarName (string): The name of client convar to query.
   * @param callback (function): A function to use as a callback when the query has finished.
   * @param data (any[]): Optional values to pass to the callback function.
   * @return int32: A cookie that uniquely identifies the query. Returns -1 on failure, such as when used on a bot.
   */
  inline int32_t QueryClientConVar(int32_t playerSlot, const plg::string& convarName, CvarValueCallback callback, const plg::vector<plg::any>& data) {
    return __s2sdk_QueryClientConVar(playerSlot, convarName, callback, data);
  }

  using _AutoExecConfig = bool (*)(const plg::vector<uint64_t>&, bool, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_AutoExecConfig __s2sdk_AutoExecConfig;
namespace s2sdk {
  /**
   * @brief  Specifies that the given config file should be executed.
   * @param conVarHandles (uint64[]): List of handles to the console variable data.
   * @param autoCreate (bool): If true, and the config file does not exist, such a config file will be automatically created and populated with information from the plugin's registered cvars.
   * @param name (string): Name of the config file, excluding the .cfg extension. Cannot be empty.
   * @param folder (string): Folder under cfg/ to use. By default this is "plugify." Can be empty.
   * @return bool: True on success, false otherwise.
   */
  inline bool AutoExecConfig(const plg::vector<uint64_t>& conVarHandles, bool autoCreate, const plg::string& name, const plg::string& folder) {
    return __s2sdk_AutoExecConfig(conVarHandles, autoCreate, name, folder);
  }

  using _GetServerLanguage = plg::string (*)();
}
extern "C" PLUGIN_API s2sdk::_GetServerLanguage __s2sdk_GetServerLanguage;
namespace s2sdk {
  /**
   * @brief Returns the current server language.
   * @return string: The server language as a string.
   */
  inline plg::string GetServerLanguage() {
    return __s2sdk_GetServerLanguage();
  }

  using _GetAllConVars = plg::vector<plg::string> (*)();
}
extern "C" PLUGIN_API s2sdk::_GetAllConVars __s2sdk_GetAllConVars;
namespace s2sdk {
  /**
   * @brief Returns all console variables registered by this plugin
   * @return string[]: The vector of ConVar names.
   */
  inline plg::vector<plg::string> GetAllConVars() {
    return __s2sdk_GetAllConVars();
  }

  /**
   * @brief RAII wrapper for ConVar handle.
   * @return 
   */
  class ConVar final {
  public:
    ConVar() = default;

    /**
     * @brief Creates a new console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (any): The default value of the console variable.
     * @param description (string): A description of the console variable's purpose.
     * @param flags (int64): Additional flags for the console variable.
     * @return 
     */
    explicit ConVar(const plg::string& name, const plg::any& defaultValue, const plg::string& description, ConVarFlag flags)
      : ConVar(CreateConVar(name, defaultValue, description, flags), Ownership::Owned) {}

    /**
     * @brief Creates a new boolean console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (bool): The default value for the console variable.
     * @param description (string): A brief description of the console variable.
     * @param flags (int64): Flags that define the behavior of the console variable.
     * @param hasMin (bool): Indicates if a minimum value is provided.
     * @param min (bool): The minimum value if hasMin is true.
     * @param hasMax (bool): Indicates if a maximum value is provided.
     * @param max (bool): The maximum value if hasMax is true.
     * @return 
     */
    explicit ConVar(const plg::string& name, bool defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, bool min, bool hasMax, bool max)
      : ConVar(CreateConVarBool(name, defaultValue, description, flags, hasMin, min, hasMax, max), Ownership::Owned) {}

    /**
     * @brief Creates a new 16-bit signed integer console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (int16): The default value for the console variable.
     * @param description (string): A brief description of the console variable.
     * @param flags (int64): Flags that define the behavior of the console variable.
     * @param hasMin (bool): Indicates if a minimum value is provided.
     * @param min (int16): The minimum value if hasMin is true.
     * @param hasMax (bool): Indicates if a maximum value is provided.
     * @param max (int16): The maximum value if hasMax is true.
     * @return 
     */
    explicit ConVar(const plg::string& name, int16_t defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, int16_t min, bool hasMax, int16_t max)
      : ConVar(CreateConVarInt16(name, defaultValue, description, flags, hasMin, min, hasMax, max), Ownership::Owned) {}

    /**
     * @brief Creates a new 16-bit unsigned integer console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (uint16): The default value for the console variable.
     * @param description (string): A brief description of the console variable.
     * @param flags (int64): Flags that define the behavior of the console variable.
     * @param hasMin (bool): Indicates if a minimum value is provided.
     * @param min (uint16): The minimum value if hasMin is true.
     * @param hasMax (bool): Indicates if a maximum value is provided.
     * @param max (uint16): The maximum value if hasMax is true.
     * @return 
     */
    explicit ConVar(const plg::string& name, uint16_t defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, uint16_t min, bool hasMax, uint16_t max)
      : ConVar(CreateConVarUInt16(name, defaultValue, description, flags, hasMin, min, hasMax, max), Ownership::Owned) {}

    /**
     * @brief Creates a new 32-bit signed integer console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (int32): The default value for the console variable.
     * @param description (string): A brief description of the console variable.
     * @param flags (int64): Flags that define the behavior of the console variable.
     * @param hasMin (bool): Indicates if a minimum value is provided.
     * @param min (int32): The minimum value if hasMin is true.
     * @param hasMax (bool): Indicates if a maximum value is provided.
     * @param max (int32): The maximum value if hasMax is true.
     * @return 
     */
    explicit ConVar(const plg::string& name, int32_t defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, int32_t min, bool hasMax, int32_t max)
      : ConVar(CreateConVarInt32(name, defaultValue, description, flags, hasMin, min, hasMax, max), Ownership::Owned) {}

    /**
     * @brief Creates a new 32-bit unsigned integer console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (uint32): The default value for the console variable.
     * @param description (string): A brief description of the console variable.
     * @param flags (int64): Flags that define the behavior of the console variable.
     * @param hasMin (bool): Indicates if a minimum value is provided.
     * @param min (uint32): The minimum value if hasMin is true.
     * @param hasMax (bool): Indicates if a maximum value is provided.
     * @param max (uint32): The maximum value if hasMax is true.
     * @return 
     */
    explicit ConVar(const plg::string& name, uint32_t defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, uint32_t min, bool hasMax, uint32_t max)
      : ConVar(CreateConVarUInt32(name, defaultValue, description, flags, hasMin, min, hasMax, max), Ownership::Owned) {}

    /**
     * @brief Creates a new 64-bit signed integer console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (int64): The default value for the console variable.
     * @param description (string): A brief description of the console variable.
     * @param flags (int64): Flags that define the behavior of the console variable.
     * @param hasMin (bool): Indicates if a minimum value is provided.
     * @param min (int64): The minimum value if hasMin is true.
     * @param hasMax (bool): Indicates if a maximum value is provided.
     * @param max (int64): The maximum value if hasMax is true.
     * @return 
     */
    explicit ConVar(const plg::string& name, int64_t defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, int64_t min, bool hasMax, int64_t max)
      : ConVar(CreateConVarInt64(name, defaultValue, description, flags, hasMin, min, hasMax, max), Ownership::Owned) {}

    /**
     * @brief Creates a new 64-bit unsigned integer console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (uint64): The default value for the console variable.
     * @param description (string): A brief description of the console variable.
     * @param flags (int64): Flags that define the behavior of the console variable.
     * @param hasMin (bool): Indicates if a minimum value is provided.
     * @param min (uint64): The minimum value if hasMin is true.
     * @param hasMax (bool): Indicates if a maximum value is provided.
     * @param max (uint64): The maximum value if hasMax is true.
     * @return 
     */
    explicit ConVar(const plg::string& name, uint64_t defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, uint64_t min, bool hasMax, uint64_t max)
      : ConVar(CreateConVarUInt64(name, defaultValue, description, flags, hasMin, min, hasMax, max), Ownership::Owned) {}

    /**
     * @brief Creates a new floating-point console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (float): The default value for the console variable.
     * @param description (string): A brief description of the console variable.
     * @param flags (int64): Flags that define the behavior of the console variable.
     * @param hasMin (bool): Indicates if a minimum value is provided.
     * @param min (float): The minimum value if hasMin is true.
     * @param hasMax (bool): Indicates if a maximum value is provided.
     * @param max (float): The maximum value if hasMax is true.
     * @return 
     */
    explicit ConVar(const plg::string& name, float defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, float min, bool hasMax, float max)
      : ConVar(CreateConVarFloat(name, defaultValue, description, flags, hasMin, min, hasMax, max), Ownership::Owned) {}

    /**
     * @brief Creates a new double-precision console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (double): The default value for the console variable.
     * @param description (string): A brief description of the console variable.
     * @param flags (int64): Flags that define the behavior of the console variable.
     * @param hasMin (bool): Indicates if a minimum value is provided.
     * @param min (double): The minimum value if hasMin is true.
     * @param hasMax (bool): Indicates if a maximum value is provided.
     * @param max (double): The maximum value if hasMax is true.
     * @return 
     */
    explicit ConVar(const plg::string& name, double defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, double min, bool hasMax, double max)
      : ConVar(CreateConVarDouble(name, defaultValue, description, flags, hasMin, min, hasMax, max), Ownership::Owned) {}

    /**
     * @brief Creates a new 2D vector console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (vec2): The default value for the console variable.
     * @param description (string): A brief description of the console variable.
     * @param flags (int64): Flags that define the behavior of the console variable.
     * @param hasMin (bool): Indicates if a minimum value is provided.
     * @param min (vec2): The minimum value if hasMin is true.
     * @param hasMax (bool): Indicates if a maximum value is provided.
     * @param max (vec2): The maximum value if hasMax is true.
     * @return 
     */
    explicit ConVar(const plg::string& name, const plg::vec2& defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, const plg::vec2& min, bool hasMax, const plg::vec2& max)
      : ConVar(CreateConVarVector2(name, defaultValue, description, flags, hasMin, min, hasMax, max), Ownership::Owned) {}

    /**
     * @brief Creates a new 3D vector console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (vec3): The default value for the console variable.
     * @param description (string): A brief description of the console variable.
     * @param flags (int64): Flags that define the behavior of the console variable.
     * @param hasMin (bool): Indicates if a minimum value is provided.
     * @param min (vec3): The minimum value if hasMin is true.
     * @param hasMax (bool): Indicates if a maximum value is provided.
     * @param max (vec3): The maximum value if hasMax is true.
     * @return 
     */
    explicit ConVar(const plg::string& name, const plg::vec3& defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, const plg::vec3& min, bool hasMax, const plg::vec3& max)
      : ConVar(CreateConVarVector3(name, defaultValue, description, flags, hasMin, min, hasMax, max), Ownership::Owned) {}

    /**
     * @brief Creates a new 4D vector console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (vec4): The default value for the console variable.
     * @param description (string): A brief description of the console variable.
     * @param flags (int64): Flags that define the behavior of the console variable.
     * @param hasMin (bool): Indicates if a minimum value is provided.
     * @param min (vec4): The minimum value if hasMin is true.
     * @param hasMax (bool): Indicates if a maximum value is provided.
     * @param max (vec4): The maximum value if hasMax is true.
     * @return 
     */
    explicit ConVar(const plg::string& name, const plg::vec4& defaultValue, const plg::string& description, ConVarFlag flags, bool hasMin, const plg::vec4& min, bool hasMax, const plg::vec4& max)
      : ConVar(CreateConVarVector4(name, defaultValue, description, flags, hasMin, min, hasMax, max), Ownership::Owned) {}

    /**
     * @brief Creates a new string console variable.
     * @param name (string): The name of the console variable.
     * @param defaultValue (string): The default value of the console variable.
     * @param description (string): A description of the console variable's purpose.
     * @param flags (int64): Additional flags for the console variable.
     * @return 
     */
    explicit ConVar(const plg::string& name, const plg::string& defaultValue, const plg::string& description, ConVarFlag flags)
      : ConVar(CreateConVarString(name, defaultValue, description, flags), Ownership::Owned) {}

    ConVar(const ConVar&) = default;
    ConVar& operator=(const ConVar&) = default;
    ConVar(ConVar&&) noexcept = default;
    ConVar& operator=(ConVar&&) noexcept = default;
    ~ConVar() = default;

    explicit ConVar(uint64_t handle, [[maybe_unused]] Ownership ownership = Ownership::Borrowed) : _handle(handle) {}

    [[nodiscard]] auto get() const noexcept { return _handle; }

    [[nodiscard]] auto release() noexcept {
      auto handle = _handle;
      _handle = 0;
      return handle;
    }

    void reset() noexcept {
      _handle = 0;
    }

    void swap(ConVar& other) noexcept {
      using std::swap;
      swap(_handle, other._handle);
    }

    friend void swap(ConVar& lhs, ConVar& rhs) noexcept { lhs.swap(rhs); }

    explicit operator bool() const noexcept { return _handle != 0; }
    [[nodiscard]] auto operator<=>(const ConVar& other) const noexcept { return _handle <=> other._handle; }
    [[nodiscard]] bool operator==(const ConVar& other) const noexcept { return _handle == other._handle; }

    /**
     * @brief Searches for a console variable.
     * @param name (string): The name of the console variable to search for.
     * @return ConVar: A handle to the console variable data if found; otherwise, nullptr.
     */
    static ConVar Find(const plg::string& name) {
      return ConVar(s2sdk::FindConVar(name));
    }

    /**
     * @brief Searches for a console variable of a specific type.
     * @param name (string): The name of the console variable to search for.
     * @param type (int16): The type of the console variable to search for.
     * @return ConVar: A handle to the console variable data if found; otherwise, nullptr.
     */
    static ConVar Find2(const plg::string& name, ConVarType type) {
      return ConVar(s2sdk::FindConVar2(name, type));
    }

    /**
     * @brief Creates a hook for when a console variable's value is changed.
     * @param callback (function): The callback function to be executed when the variable's value changes.
     */
    void HookChange(ConVarCallback callback) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::HookConVarChange(_handle, callback);
    }

    /**
     * @brief Removes a hook for when a console variable's value is changed.
     * @param callback (function): The callback function to be removed.
     */
    void UnhookChange(ConVarCallback callback) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::UnhookConVarChange(_handle, callback);
    }

    /**
     * @brief Checks if a specific flag is set for a console variable.
     * @param flag (int64): The flag to check against the console variable.
     * @return bool: True if the flag is set; otherwise, false.
     */
    bool IsFlagSet(int64_t flag) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::IsConVarFlagSet(_handle, flag);
    }

    /**
     * @brief Adds flags to a console variable.
     * @param flags (int64): The flags to be added.
     */
    void AddFlags(ConVarFlag flags) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::AddConVarFlags(_handle, flags);
    }

    /**
     * @brief Removes flags from a console variable.
     * @param flags (int64): The flags to be removed.
     */
    void RemoveFlags(ConVarFlag flags) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::RemoveConVarFlags(_handle, flags);
    }

    /**
     * @brief Retrieves the current flags of a console variable.
     * @return int64: The current flags set on the console variable.
     */
    ConVarFlag GetFlags() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarFlags(_handle);
    }

    /**
     * @brief Gets the specified bound (max or min) of a console variable and stores it in the output string.
     * @param max (bool): Indicates whether to get the maximum (true) or minimum (false) bound.
     * @return string: The bound value.
     */
    plg::string GetBounds(bool max) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarBounds(_handle, max);
    }

    /**
     * @brief Sets the specified bound (max or min) for a console variable.
     * @param max (bool): Indicates whether to set the maximum (true) or minimum (false) bound.
     * @param value (string): The value to set as the bound.
     */
    void SetBounds(bool max, const plg::string& value) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarBounds(_handle, max, value);
    }

    /**
     * @brief Retrieves the default value of a console variable and stores it in the output string.
     * @return string: The output value in string format.
     */
    plg::string GetDefault() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarDefault(_handle);
    }

    /**
     * @brief Sets the specified default value for a console variable.
     * @param value (string): The value to set as the default.
     */
    void SetDefault(const plg::string& value) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarDefault(_handle, value);
    }

    /**
     * @brief Retrieves the current value of a console variable and stores it in the output string.
     * @return string: The output value in string format.
     */
    plg::string GetValue() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarValue(_handle);
    }

    /**
     * @brief Retrieves the current value of a console variable and stores it in the output.
     * @return any: The output value.
     */
    plg::any GetObject() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVar(_handle);
    }

    /**
     * @brief Retrieves the current value of a boolean console variable.
     * @return bool: The current boolean value of the console variable.
     */
    bool GetBool() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarBool(_handle);
    }

    /**
     * @brief Retrieves the current value of a signed 16-bit integer console variable.
     * @return int16: The current int16_t value of the console variable.
     */
    int16_t GetInt16() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarInt16(_handle);
    }

    /**
     * @brief Retrieves the current value of an unsigned 16-bit integer console variable.
     * @return uint16: The current uint16_t value of the console variable.
     */
    uint16_t GetUInt16() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarUInt16(_handle);
    }

    /**
     * @brief Retrieves the current value of a signed 32-bit integer console variable.
     * @return int32: The current int32_t value of the console variable.
     */
    int32_t GetInt32() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarInt32(_handle);
    }

    /**
     * @brief Retrieves the current value of an unsigned 32-bit integer console variable.
     * @return uint32: The current uint32_t value of the console variable.
     */
    uint32_t GetUInt32() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarUInt32(_handle);
    }

    /**
     * @brief Retrieves the current value of a signed 64-bit integer console variable.
     * @return int64: The current int64_t value of the console variable.
     */
    int64_t GetInt64() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarInt64(_handle);
    }

    /**
     * @brief Retrieves the current value of an unsigned 64-bit integer console variable.
     * @return uint64: The current uint64_t value of the console variable.
     */
    uint64_t GetUInt64() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarUInt64(_handle);
    }

    /**
     * @brief Retrieves the current value of a float console variable.
     * @return float: The current float value of the console variable.
     */
    float GetFloat() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarFloat(_handle);
    }

    /**
     * @brief Retrieves the current value of a double console variable.
     * @return double: The current double value of the console variable.
     */
    double GetDouble() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarDouble(_handle);
    }

    /**
     * @brief Retrieves the current value of a string console variable.
     * @return string: The current string value of the console variable.
     */
    plg::string GetString() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarString(_handle);
    }

    /**
     * @brief Retrieves the current value of a Color console variable.
     * @return vec4: The current Color value of the console variable.
     */
    plg::vec4 GetColor() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarColor(_handle);
    }

    /**
     * @brief Retrieves the current value of a Vector2D console variable.
     * @return vec2: The current Vector2D value of the console variable.
     */
    plg::vec2 GetVector2() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarVector2(_handle);
    }

    /**
     * @brief Retrieves the current value of a Vector console variable.
     * @return vec3: The current Vector value of the console variable.
     */
    plg::vec3 GetVector() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarVector(_handle);
    }

    /**
     * @brief Retrieves the current value of a Vector4D console variable.
     * @return vec4: The current Vector4D value of the console variable.
     */
    plg::vec4 GetVector4() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarVector4(_handle);
    }

    /**
     * @brief Retrieves the current value of a QAngle console variable.
     * @return vec3: The current QAngle value of the console variable.
     */
    plg::vec3 GetQAngle() {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      return s2sdk::GetConVarQAngle(_handle);
    }

    /**
     * @brief Sets the value of a console variable.
     * @param value (string): The string value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetValue(const plg::string& value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarValue(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of a console variable.
     * @param value (any): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void Set(const plg::any& value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVar(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of a boolean console variable.
     * @param value (bool): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetBool(bool value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarBool(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of a signed 16-bit integer console variable.
     * @param value (int16): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetInt16(int16_t value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarInt16(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of an unsigned 16-bit integer console variable.
     * @param value (uint16): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetUInt16(uint16_t value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarUInt16(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of a signed 32-bit integer console variable.
     * @param value (int32): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetInt32(int32_t value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarInt32(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of an unsigned 32-bit integer console variable.
     * @param value (uint32): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetUInt32(uint32_t value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarUInt32(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of a signed 64-bit integer console variable.
     * @param value (int64): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetInt64(int64_t value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarInt64(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of an unsigned 64-bit integer console variable.
     * @param value (uint64): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetUInt64(uint64_t value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarUInt64(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of a floating-point console variable.
     * @param value (float): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetFloat(float value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarFloat(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of a double-precision floating-point console variable.
     * @param value (double): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetDouble(double value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarDouble(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of a string console variable.
     * @param value (string): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetString(const plg::string& value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarString(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of a color console variable.
     * @param value (vec4): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetColor(const plg::vec4& value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarColor(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of a 2D vector console variable.
     * @param value (vec2): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetVector2(const plg::vec2& value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarVector2(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of a 3D vector console variable.
     * @param value (vec3): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetVector3(const plg::vec3& value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarVector3(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of a 4D vector console variable.
     * @param value (vec4): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetVector4(const plg::vec4& value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarVector4(_handle, value, replicate, notify);
    }

    /**
     * @brief Sets the value of a quaternion angle console variable.
     * @param value (vec3): The value to set for the console variable.
     * @param replicate (bool): If set to true, the new convar value will be set on all clients. This will only work if the convar has the FCVAR_REPLICATED flag and actually exists on clients.
     * @param notify (bool): If set to true, clients will be notified that the convar has changed. This will only work if the convar has the FCVAR_NOTIFY flag.
     */
    void SetQAngle(const plg::vec3& value, bool replicate, bool notify) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SetConVarQAngle(_handle, value, replicate, notify);
    }

    /**
     * @brief Replicates a console variable value to a specific client. This does not change the actual console variable value.
     * @param playerSlot (int32): The index of the client to replicate the value to.
     * @param value (string): The value to send to the client.
     */
    void SendValue(int32_t playerSlot, const plg::string& value) {
      if (_handle == 0) throw std::runtime_error("ConVar: empty handle");
      s2sdk::SendConVarValue2(_handle, playerSlot, value);
    }

    /**
     * @brief Retrieves the value of a client's console variable and stores it in the output string.
     * @param playerSlot (int32): The index of the client whose console variable value is being retrieved.
     * @param convarName (string): The name of the console variable to retrieve.
     * @return string: The output string to store the client's console variable value.
     */
    static plg::string GetClientValue(int32_t playerSlot, const plg::string& convarName) {
      return s2sdk::GetClientConVarValue(playerSlot, convarName);
    }

    /**
     * @brief Replicates a console variable value to a specific fake client. This does not change the actual console variable value.
     * @param playerSlot (int32): The index of the fake client to replicate the value to.
     * @param convarName (string): The name of the console variable.
     * @param convarValue (string): The value to set for the console variable.
     */
    static void SetFakeClientValue(int32_t playerSlot, const plg::string& convarName, const plg::string& convarValue) {
      s2sdk::SetFakeClientConVarValue(playerSlot, convarName, convarValue);
    }

  private:
    uint64_t _handle{0};
  };


} // namespace s2sdk
