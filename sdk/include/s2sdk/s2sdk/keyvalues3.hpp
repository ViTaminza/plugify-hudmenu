#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: keyvalues3)

namespace s2sdk {

  using _Kv3Create = void* (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3Create __s2sdk_Kv3Create;
namespace s2sdk {
  /**
   * @brief Creates a new KeyValues3 object with specified type and subtype
   * @param type (int32): The KV3 type enumeration value
   * @param subtype (int32): The KV3 subtype enumeration value
   * @return ptr64: Pointer to the newly created KeyValues3 object
   */
  inline void* Kv3Create(int32_t type, int32_t subtype) {
    return __s2sdk_Kv3Create(type, subtype);
  }

  using _Kv3CreateWithCluster = void* (*)(int32_t, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3CreateWithCluster __s2sdk_Kv3CreateWithCluster;
namespace s2sdk {
  /**
   * @brief Creates a new KeyValues3 object with cluster element, type, and subtype
   * @param cluster_elem (int32): The cluster element index
   * @param type (int32): The KV3 type enumeration value
   * @param subtype (int32): The KV3 subtype enumeration value
   * @return ptr64: Pointer to the newly created KeyValues3 object
   */
  inline void* Kv3CreateWithCluster(int32_t cluster_elem, int32_t type, int32_t subtype) {
    return __s2sdk_Kv3CreateWithCluster(cluster_elem, type, subtype);
  }

  using _Kv3CreateCopy = void* (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3CreateCopy __s2sdk_Kv3CreateCopy;
namespace s2sdk {
  /**
   * @brief Creates a copy of an existing KeyValues3 object
   * @param other (ptr64): Pointer to the KeyValues3 object to copy
   * @return ptr64: Pointer to the newly created copy, or nullptr if other is null
   */
  inline void* Kv3CreateCopy(void* other) {
    return __s2sdk_Kv3CreateCopy(other);
  }

  using _Kv3Destroy = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3Destroy __s2sdk_Kv3Destroy;
namespace s2sdk {
  /**
   * @brief Destroys a KeyValues3 object and frees its memory
   * @param kv (ptr64): Pointer to the KeyValues3 object to destroy
   */
  inline void Kv3Destroy(void* kv) {
    return __s2sdk_Kv3Destroy(kv);
  }

  using _Kv3CopyFrom = void (*)(void*, void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3CopyFrom __s2sdk_Kv3CopyFrom;
namespace s2sdk {
  /**
   * @brief Copies data from another KeyValues3 object
   * @param kv (ptr64): Pointer to the destination KeyValues3 object
   * @param other (ptr64): Pointer to the source KeyValues3 object
   */
  inline void Kv3CopyFrom(void* kv, void* other) {
    return __s2sdk_Kv3CopyFrom(kv, other);
  }

  using _Kv3OverlayKeysFrom = void (*)(void*, void*, bool);
}
extern "C" PLUGIN_API s2sdk::_Kv3OverlayKeysFrom __s2sdk_Kv3OverlayKeysFrom;
namespace s2sdk {
  /**
   * @brief Overlays keys from another KeyValues3 object
   * @param kv (ptr64): Pointer to the destination KeyValues3 object
   * @param other (ptr64): Pointer to the source KeyValues3 object
   * @param depth (bool): Whether to perform a deep overlay
   */
  inline void Kv3OverlayKeysFrom(void* kv, void* other, bool depth) {
    return __s2sdk_Kv3OverlayKeysFrom(kv, other, depth);
  }

  using _Kv3GetContext = void* (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetContext __s2sdk_Kv3GetContext;
namespace s2sdk {
  /**
   * @brief Gets the context associated with a KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return ptr64: Pointer to the CKV3Arena, or nullptr if kv is null
   */
  inline void* Kv3GetContext(void* kv) {
    return __s2sdk_Kv3GetContext(kv);
  }

  using _Kv3GetMetaData = void* (*)(void*, void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMetaData __s2sdk_Kv3GetMetaData;
namespace s2sdk {
  /**
   * @brief Gets the metadata associated with a KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param ppCtx (ptr64): Pointer to store the context pointer
   * @return ptr64: Pointer to the KV3MetaData_t structure, or nullptr if kv is null
   */
  inline void* Kv3GetMetaData(void* kv, void* ppCtx) {
    return __s2sdk_Kv3GetMetaData(kv, ppCtx);
  }

  using _Kv3HasFlag = bool (*)(void*, uint8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3HasFlag __s2sdk_Kv3HasFlag;
namespace s2sdk {
  /**
   * @brief Checks if a specific flag is set
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param flag (uint8): The flag to check
   * @return bool: true if the flag is set, false otherwise
   */
  inline bool Kv3HasFlag(void* kv, uint8_t flag) {
    return __s2sdk_Kv3HasFlag(kv, flag);
  }

  using _Kv3HasAnyFlags = bool (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3HasAnyFlags __s2sdk_Kv3HasAnyFlags;
namespace s2sdk {
  /**
   * @brief Checks if any flags are set
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return bool: true if any flags are set, false otherwise
   */
  inline bool Kv3HasAnyFlags(void* kv) {
    return __s2sdk_Kv3HasAnyFlags(kv);
  }

  using _Kv3GetAllFlags = uint8_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetAllFlags __s2sdk_Kv3GetAllFlags;
namespace s2sdk {
  /**
   * @brief Gets all flags as a bitmask
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return uint8: Bitmask of all flags, or 0 if kv is null
   */
  inline uint8_t Kv3GetAllFlags(void* kv) {
    return __s2sdk_Kv3GetAllFlags(kv);
  }

  using _Kv3SetAllFlags = void (*)(void*, uint8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetAllFlags __s2sdk_Kv3SetAllFlags;
namespace s2sdk {
  /**
   * @brief Sets all flags from a bitmask
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param flags (uint8): Bitmask of flags to set
   */
  inline void Kv3SetAllFlags(void* kv, uint8_t flags) {
    return __s2sdk_Kv3SetAllFlags(kv, flags);
  }

  using _Kv3SetFlag = void (*)(void*, uint8_t, bool);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetFlag __s2sdk_Kv3SetFlag;
namespace s2sdk {
  /**
   * @brief Sets or clears a specific flag
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param flag (uint8): The flag to modify
   * @param state (bool): true to set the flag, false to clear it
   */
  inline void Kv3SetFlag(void* kv, uint8_t flag, bool state) {
    return __s2sdk_Kv3SetFlag(kv, flag, state);
  }

  using _Kv3GetType = uint8_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetType __s2sdk_Kv3GetType;
namespace s2sdk {
  /**
   * @brief Gets the basic type of the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return uint8: The type enumeration value, or 0 if kv is null
   */
  inline uint8_t Kv3GetType(void* kv) {
    return __s2sdk_Kv3GetType(kv);
  }

  using _Kv3GetTypeEx = uint8_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetTypeEx __s2sdk_Kv3GetTypeEx;
namespace s2sdk {
  /**
   * @brief Gets the extended type of the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return uint8: The extended type enumeration value, or 0 if kv is null
   */
  inline uint8_t Kv3GetTypeEx(void* kv) {
    return __s2sdk_Kv3GetTypeEx(kv);
  }

  using _Kv3GetSubType = uint8_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetSubType __s2sdk_Kv3GetSubType;
namespace s2sdk {
  /**
   * @brief Gets the subtype of the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return uint8: The subtype enumeration value, or 0 if kv is null
   */
  inline uint8_t Kv3GetSubType(void* kv) {
    return __s2sdk_Kv3GetSubType(kv);
  }

  using _Kv3HasInvalidMemberNames = bool (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3HasInvalidMemberNames __s2sdk_Kv3HasInvalidMemberNames;
namespace s2sdk {
  /**
   * @brief Checks if the object has invalid member names
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return bool: true if invalid member names exist, false otherwise
   */
  inline bool Kv3HasInvalidMemberNames(void* kv) {
    return __s2sdk_Kv3HasInvalidMemberNames(kv);
  }

  using _Kv3SetHasInvalidMemberNames = void (*)(void*, bool);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetHasInvalidMemberNames __s2sdk_Kv3SetHasInvalidMemberNames;
namespace s2sdk {
  /**
   * @brief Sets the invalid member names flag
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param bValue (bool): true to mark as having invalid member names, false otherwise
   */
  inline void Kv3SetHasInvalidMemberNames(void* kv, bool bValue) {
    return __s2sdk_Kv3SetHasInvalidMemberNames(kv, bValue);
  }

  using _Kv3GetTypeAsString = plg::string (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetTypeAsString __s2sdk_Kv3GetTypeAsString;
namespace s2sdk {
  /**
   * @brief Gets the type as a string representation
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return string: String representation of the type, or empty string if kv is null
   */
  inline plg::string Kv3GetTypeAsString(void* kv) {
    return __s2sdk_Kv3GetTypeAsString(kv);
  }

  using _Kv3GetSubTypeAsString = plg::string (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetSubTypeAsString __s2sdk_Kv3GetSubTypeAsString;
namespace s2sdk {
  /**
   * @brief Gets the subtype as a string representation
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return string: String representation of the subtype, or empty string if kv is null
   */
  inline plg::string Kv3GetSubTypeAsString(void* kv) {
    return __s2sdk_Kv3GetSubTypeAsString(kv);
  }

  using _Kv3ToString = plg::string (*)(void*, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3ToString __s2sdk_Kv3ToString;
namespace s2sdk {
  /**
   * @brief Converts the KeyValues3 object to a string representation
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param flags (uint32): Formatting flags for the string conversion
   * @return string: String representation of the object, or empty string if kv is null
   */
  inline plg::string Kv3ToString(void* kv, uint32_t flags) {
    return __s2sdk_Kv3ToString(kv, flags);
  }

  using _Kv3IsNull = bool (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3IsNull __s2sdk_Kv3IsNull;
namespace s2sdk {
  /**
   * @brief Checks if the KeyValues3 object is null
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return bool: true if the object is null or the pointer is null, false otherwise
   */
  inline bool Kv3IsNull(void* kv) {
    return __s2sdk_Kv3IsNull(kv);
  }

  using _Kv3SetToNull = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetToNull __s2sdk_Kv3SetToNull;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to null
   * @param kv (ptr64): Pointer to the KeyValues3 object
   */
  inline void Kv3SetToNull(void* kv) {
    return __s2sdk_Kv3SetToNull(kv);
  }

  using _Kv3IsArray = bool (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3IsArray __s2sdk_Kv3IsArray;
namespace s2sdk {
  /**
   * @brief Checks if the KeyValues3 object is an array
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return bool: true if the object is an array, false otherwise
   */
  inline bool Kv3IsArray(void* kv) {
    return __s2sdk_Kv3IsArray(kv);
  }

  using _Kv3IsKV3Array = bool (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3IsKV3Array __s2sdk_Kv3IsKV3Array;
namespace s2sdk {
  /**
   * @brief Checks if the KeyValues3 object is a KV3 array
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return bool: true if the object is a KV3 array, false otherwise
   */
  inline bool Kv3IsKV3Array(void* kv) {
    return __s2sdk_Kv3IsKV3Array(kv);
  }

  using _Kv3IsTable = bool (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3IsTable __s2sdk_Kv3IsTable;
namespace s2sdk {
  /**
   * @brief Checks if the KeyValues3 object is a table
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return bool: true if the object is a table, false otherwise
   */
  inline bool Kv3IsTable(void* kv) {
    return __s2sdk_Kv3IsTable(kv);
  }

  using _Kv3IsString = bool (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3IsString __s2sdk_Kv3IsString;
namespace s2sdk {
  /**
   * @brief Checks if the KeyValues3 object is a string
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return bool: true if the object is a string, false otherwise
   */
  inline bool Kv3IsString(void* kv) {
    return __s2sdk_Kv3IsString(kv);
  }

  using _Kv3GetBool = bool (*)(void*, bool);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetBool __s2sdk_Kv3GetBool;
namespace s2sdk {
  /**
   * @brief Gets the boolean value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (bool): Default value to return if kv is null or conversion fails
   * @return bool: Boolean value or defaultValue
   */
  inline bool Kv3GetBool(void* kv, bool defaultValue) {
    return __s2sdk_Kv3GetBool(kv, defaultValue);
  }

  using _Kv3GetChar = char (*)(void*, char);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetChar __s2sdk_Kv3GetChar;
namespace s2sdk {
  /**
   * @brief Gets the char value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (char8): Default value to return if kv is null or conversion fails
   * @return char8: Char value or defaultValue
   */
  inline char Kv3GetChar(void* kv, char defaultValue) {
    return __s2sdk_Kv3GetChar(kv, defaultValue);
  }

  using _Kv3GetUChar32 = uint32_t (*)(void*, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetUChar32 __s2sdk_Kv3GetUChar32;
namespace s2sdk {
  /**
   * @brief Gets the 32-bit Unicode character value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (uint32): Default value to return if kv is null or conversion fails
   * @return uint32: 32-bit Unicode character value or defaultValue
   */
  inline uint32_t Kv3GetUChar32(void* kv, uint32_t defaultValue) {
    return __s2sdk_Kv3GetUChar32(kv, defaultValue);
  }

  using _Kv3GetInt8 = int8_t (*)(void*, int8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetInt8 __s2sdk_Kv3GetInt8;
namespace s2sdk {
  /**
   * @brief Gets the signed 8-bit integer value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (int8): Default value to return if kv is null or conversion fails
   * @return int8: int8_t value or defaultValue
   */
  inline int8_t Kv3GetInt8(void* kv, int8_t defaultValue) {
    return __s2sdk_Kv3GetInt8(kv, defaultValue);
  }

  using _Kv3GetUInt8 = uint8_t (*)(void*, uint8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetUInt8 __s2sdk_Kv3GetUInt8;
namespace s2sdk {
  /**
   * @brief Gets the unsigned 8-bit integer value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (uint8): Default value to return if kv is null or conversion fails
   * @return uint8: uint8_t value or defaultValue
   */
  inline uint8_t Kv3GetUInt8(void* kv, uint8_t defaultValue) {
    return __s2sdk_Kv3GetUInt8(kv, defaultValue);
  }

  using _Kv3GetShort = int16_t (*)(void*, int16_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetShort __s2sdk_Kv3GetShort;
namespace s2sdk {
  /**
   * @brief Gets the signed 16-bit integer value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (int16): Default value to return if kv is null or conversion fails
   * @return int16: int16_t value or defaultValue
   */
  inline int16_t Kv3GetShort(void* kv, int16_t defaultValue) {
    return __s2sdk_Kv3GetShort(kv, defaultValue);
  }

  using _Kv3GetUShort = uint16_t (*)(void*, uint16_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetUShort __s2sdk_Kv3GetUShort;
namespace s2sdk {
  /**
   * @brief Gets the unsigned 16-bit integer value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (uint16): Default value to return if kv is null or conversion fails
   * @return uint16: uint16_t value or defaultValue
   */
  inline uint16_t Kv3GetUShort(void* kv, uint16_t defaultValue) {
    return __s2sdk_Kv3GetUShort(kv, defaultValue);
  }

  using _Kv3GetInt = int32_t (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetInt __s2sdk_Kv3GetInt;
namespace s2sdk {
  /**
   * @brief Gets the signed 32-bit integer value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (int32): Default value to return if kv is null or conversion fails
   * @return int32: int32_t value or defaultValue
   */
  inline int32_t Kv3GetInt(void* kv, int32_t defaultValue) {
    return __s2sdk_Kv3GetInt(kv, defaultValue);
  }

  using _Kv3GetUInt = uint32_t (*)(void*, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetUInt __s2sdk_Kv3GetUInt;
namespace s2sdk {
  /**
   * @brief Gets the unsigned 32-bit integer value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (uint32): Default value to return if kv is null or conversion fails
   * @return uint32: uint32_t value or defaultValue
   */
  inline uint32_t Kv3GetUInt(void* kv, uint32_t defaultValue) {
    return __s2sdk_Kv3GetUInt(kv, defaultValue);
  }

  using _Kv3GetInt64 = int64_t (*)(void*, int64_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetInt64 __s2sdk_Kv3GetInt64;
namespace s2sdk {
  /**
   * @brief Gets the signed 64-bit integer value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (int64): Default value to return if kv is null or conversion fails
   * @return int64: int64_t value or defaultValue
   */
  inline int64_t Kv3GetInt64(void* kv, int64_t defaultValue) {
    return __s2sdk_Kv3GetInt64(kv, defaultValue);
  }

  using _Kv3GetUInt64 = uint64_t (*)(void*, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetUInt64 __s2sdk_Kv3GetUInt64;
namespace s2sdk {
  /**
   * @brief Gets the unsigned 64-bit integer value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (uint64): Default value to return if kv is null or conversion fails
   * @return uint64: uint64_t value or defaultValue
   */
  inline uint64_t Kv3GetUInt64(void* kv, uint64_t defaultValue) {
    return __s2sdk_Kv3GetUInt64(kv, defaultValue);
  }

  using _Kv3GetFloat = float (*)(void*, float);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetFloat __s2sdk_Kv3GetFloat;
namespace s2sdk {
  /**
   * @brief Gets the float value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (float): Default value to return if kv is null or conversion fails
   * @return float: Float value or defaultValue
   */
  inline float Kv3GetFloat(void* kv, float defaultValue) {
    return __s2sdk_Kv3GetFloat(kv, defaultValue);
  }

  using _Kv3GetDouble = double (*)(void*, double);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetDouble __s2sdk_Kv3GetDouble;
namespace s2sdk {
  /**
   * @brief Gets the double value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (double): Default value to return if kv is null or conversion fails
   * @return double: Double value or defaultValue
   */
  inline double Kv3GetDouble(void* kv, double defaultValue) {
    return __s2sdk_Kv3GetDouble(kv, defaultValue);
  }

  using _Kv3SetBool = void (*)(void*, bool);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetBool __s2sdk_Kv3SetBool;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a boolean value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param value (bool): Boolean value to set
   */
  inline void Kv3SetBool(void* kv, bool value) {
    return __s2sdk_Kv3SetBool(kv, value);
  }

  using _Kv3SetChar = void (*)(void*, char);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetChar __s2sdk_Kv3SetChar;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a char value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param value (char8): Char value to set
   */
  inline void Kv3SetChar(void* kv, char value) {
    return __s2sdk_Kv3SetChar(kv, value);
  }

  using _Kv3SetUChar32 = void (*)(void*, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetUChar32 __s2sdk_Kv3SetUChar32;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a 32-bit Unicode character value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param value (uint32): 32-bit Unicode character value to set
   */
  inline void Kv3SetUChar32(void* kv, uint32_t value) {
    return __s2sdk_Kv3SetUChar32(kv, value);
  }

  using _Kv3SetInt8 = void (*)(void*, int8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetInt8 __s2sdk_Kv3SetInt8;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a signed 8-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param value (int8): int8_t value to set
   */
  inline void Kv3SetInt8(void* kv, int8_t value) {
    return __s2sdk_Kv3SetInt8(kv, value);
  }

  using _Kv3SetUInt8 = void (*)(void*, uint8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetUInt8 __s2sdk_Kv3SetUInt8;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to an unsigned 8-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param value (uint8): uint8_t value to set
   */
  inline void Kv3SetUInt8(void* kv, uint8_t value) {
    return __s2sdk_Kv3SetUInt8(kv, value);
  }

  using _Kv3SetShort = void (*)(void*, int16_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetShort __s2sdk_Kv3SetShort;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a signed 16-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param value (int16): int16_t value to set
   */
  inline void Kv3SetShort(void* kv, int16_t value) {
    return __s2sdk_Kv3SetShort(kv, value);
  }

  using _Kv3SetUShort = void (*)(void*, uint16_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetUShort __s2sdk_Kv3SetUShort;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to an unsigned 16-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param value (uint16): uint16_t value to set
   */
  inline void Kv3SetUShort(void* kv, uint16_t value) {
    return __s2sdk_Kv3SetUShort(kv, value);
  }

  using _Kv3SetInt = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetInt __s2sdk_Kv3SetInt;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a signed 32-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param value (int32): int32_t value to set
   */
  inline void Kv3SetInt(void* kv, int32_t value) {
    return __s2sdk_Kv3SetInt(kv, value);
  }

  using _Kv3SetUInt = void (*)(void*, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetUInt __s2sdk_Kv3SetUInt;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to an unsigned 32-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param value (uint32): uint32_t value to set
   */
  inline void Kv3SetUInt(void* kv, uint32_t value) {
    return __s2sdk_Kv3SetUInt(kv, value);
  }

  using _Kv3SetInt64 = void (*)(void*, int64_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetInt64 __s2sdk_Kv3SetInt64;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a signed 64-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param value (int64): int64_t value to set
   */
  inline void Kv3SetInt64(void* kv, int64_t value) {
    return __s2sdk_Kv3SetInt64(kv, value);
  }

  using _Kv3SetUInt64 = void (*)(void*, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetUInt64 __s2sdk_Kv3SetUInt64;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to an unsigned 64-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param value (uint64): uint64_t value to set
   */
  inline void Kv3SetUInt64(void* kv, uint64_t value) {
    return __s2sdk_Kv3SetUInt64(kv, value);
  }

  using _Kv3SetFloat = void (*)(void*, float);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetFloat __s2sdk_Kv3SetFloat;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a float value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param value (float): Float value to set
   */
  inline void Kv3SetFloat(void* kv, float value) {
    return __s2sdk_Kv3SetFloat(kv, value);
  }

  using _Kv3SetDouble = void (*)(void*, double);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetDouble __s2sdk_Kv3SetDouble;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a double value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param value (double): Double value to set
   */
  inline void Kv3SetDouble(void* kv, double value) {
    return __s2sdk_Kv3SetDouble(kv, value);
  }

  using _Kv3GetPointer = void* (*)(void*, void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetPointer __s2sdk_Kv3GetPointer;
namespace s2sdk {
  /**
   * @brief Gets the pointer value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (ptr64): Default value to return if kv is null
   * @return ptr64: Pointer value as uintptr_t or defaultValue
   */
  inline void* Kv3GetPointer(void* kv, void* defaultValue) {
    return __s2sdk_Kv3GetPointer(kv, defaultValue);
  }

  using _Kv3SetPointer = void (*)(void*, void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetPointer __s2sdk_Kv3SetPointer;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a pointer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param ptr (ptr64): Pointer value as uintptr_t to set
   */
  inline void Kv3SetPointer(void* kv, void* ptr) {
    return __s2sdk_Kv3SetPointer(kv, ptr);
  }

  using _Kv3GetStringToken = uint32_t (*)(void*, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetStringToken __s2sdk_Kv3GetStringToken;
namespace s2sdk {
  /**
   * @brief Gets the string token value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (uint32): Default token value to return if kv is null
   * @return uint32: String token hash code or defaultValue
   */
  inline uint32_t Kv3GetStringToken(void* kv, uint32_t defaultValue) {
    return __s2sdk_Kv3GetStringToken(kv, defaultValue);
  }

  using _Kv3SetStringToken = void (*)(void*, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetStringToken __s2sdk_Kv3SetStringToken;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a string token value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param token (uint32): String token hash code to set
   */
  inline void Kv3SetStringToken(void* kv, uint32_t token) {
    return __s2sdk_Kv3SetStringToken(kv, token);
  }

  using _Kv3GetEHandle = int32_t (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetEHandle __s2sdk_Kv3GetEHandle;
namespace s2sdk {
  /**
   * @brief Gets the entity handle value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (int32): Default entity handle value to return if kv is null
   * @return int32: Entity handle as int32_t or defaultValue
   */
  inline int32_t Kv3GetEHandle(void* kv, int32_t defaultValue) {
    return __s2sdk_Kv3GetEHandle(kv, defaultValue);
  }

  using _Kv3SetEHandle = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetEHandle __s2sdk_Kv3SetEHandle;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to an entity handle value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param ehandle (int32): Entity handle value to set
   */
  inline void Kv3SetEHandle(void* kv, int32_t ehandle) {
    return __s2sdk_Kv3SetEHandle(kv, ehandle);
  }

  using _Kv3GetString = plg::string (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetString __s2sdk_Kv3GetString;
namespace s2sdk {
  /**
   * @brief Gets the string value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (string): Default string to return if kv is null or value is empty
   * @return string: String value or defaultValue
   */
  inline plg::string Kv3GetString(void* kv, const plg::string& defaultValue) {
    return __s2sdk_Kv3GetString(kv, defaultValue);
  }

  using _Kv3SetString = void (*)(void*, const plg::string&, uint8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetString __s2sdk_Kv3SetString;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a string value (copies the string)
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param str (string): String value to set
   * @param subtype (uint8): String subtype enumeration value
   */
  inline void Kv3SetString(void* kv, const plg::string& str, uint8_t subtype) {
    return __s2sdk_Kv3SetString(kv, str, subtype);
  }

  using _Kv3SetStringExternal = void (*)(void*, const plg::string&, uint8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetStringExternal __s2sdk_Kv3SetStringExternal;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to an external string value (does not copy)
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param str (string): External string value to reference
   * @param subtype (uint8): String subtype enumeration value
   */
  inline void Kv3SetStringExternal(void* kv, const plg::string& str, uint8_t subtype) {
    return __s2sdk_Kv3SetStringExternal(kv, str, subtype);
  }

  using _Kv3GetBinaryBlob = plg::vector<uint8_t> (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetBinaryBlob __s2sdk_Kv3GetBinaryBlob;
namespace s2sdk {
  /**
   * @brief Gets the binary blob from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return uint8[]: Vector containing the binary blob data, or empty vector if kv is null
   */
  inline plg::vector<uint8_t> Kv3GetBinaryBlob(void* kv) {
    return __s2sdk_Kv3GetBinaryBlob(kv);
  }

  using _Kv3GetBinaryBlobSize = int32_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetBinaryBlobSize __s2sdk_Kv3GetBinaryBlobSize;
namespace s2sdk {
  /**
   * @brief Gets the size of the binary blob in the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return int32: Size of the binary blob in bytes, or 0 if kv is null
   */
  inline int32_t Kv3GetBinaryBlobSize(void* kv) {
    return __s2sdk_Kv3GetBinaryBlobSize(kv);
  }

  using _Kv3SetToBinaryBlob = void (*)(void*, const plg::vector<uint8_t>&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetToBinaryBlob __s2sdk_Kv3SetToBinaryBlob;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a binary blob (copies the data)
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param blob (uint8[]): Vector containing the binary blob data
   */
  inline void Kv3SetToBinaryBlob(void* kv, const plg::vector<uint8_t>& blob) {
    return __s2sdk_Kv3SetToBinaryBlob(kv, blob);
  }

  using _Kv3SetToBinaryBlobExternal = void (*)(void*, const plg::vector<uint8_t>&, bool);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetToBinaryBlobExternal __s2sdk_Kv3SetToBinaryBlobExternal;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to an external binary blob (does not copy)
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param blob (uint8[]): Vector containing the external binary blob data
   * @param free_mem (bool): Whether to free the memory when the object is destroyed
   */
  inline void Kv3SetToBinaryBlobExternal(void* kv, const plg::vector<uint8_t>& blob, bool free_mem) {
    return __s2sdk_Kv3SetToBinaryBlobExternal(kv, blob, free_mem);
  }

  using _Kv3GetColor = plg::vec4 (*)(void*, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetColor __s2sdk_Kv3GetColor;
namespace s2sdk {
  /**
   * @brief Gets the color value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (vec4): Default color value to return if kv is null
   * @return vec4: Color value as vec4 or defaultValue
   */
  inline plg::vec4 Kv3GetColor(void* kv, const plg::vec4& defaultValue) {
    return __s2sdk_Kv3GetColor(kv, defaultValue);
  }

  using _Kv3SetColor = void (*)(void*, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetColor __s2sdk_Kv3SetColor;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a color value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param color (vec4): Color value as vec4 to set
   */
  inline void Kv3SetColor(void* kv, const plg::vec4& color) {
    return __s2sdk_Kv3SetColor(kv, color);
  }

  using _Kv3GetVector = plg::vec3 (*)(void*, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetVector __s2sdk_Kv3GetVector;
namespace s2sdk {
  /**
   * @brief Gets the 3D vector value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (vec3): Default vector to return if kv is null
   * @return vec3: 3D vector or defaultValue
   */
  inline plg::vec3 Kv3GetVector(void* kv, const plg::vec3& defaultValue) {
    return __s2sdk_Kv3GetVector(kv, defaultValue);
  }

  using _Kv3GetVector2D = plg::vec2 (*)(void*, const plg::vec2&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetVector2D __s2sdk_Kv3GetVector2D;
namespace s2sdk {
  /**
   * @brief Gets the 2D vector value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (vec2): Default 2D vector to return if kv is null
   * @return vec2: 2D vector or defaultValue
   */
  inline plg::vec2 Kv3GetVector2D(void* kv, const plg::vec2& defaultValue) {
    return __s2sdk_Kv3GetVector2D(kv, defaultValue);
  }

  using _Kv3GetVector4D = plg::vec4 (*)(void*, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetVector4D __s2sdk_Kv3GetVector4D;
namespace s2sdk {
  /**
   * @brief Gets the 4D vector value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (vec4): Default 4D vector to return if kv is null
   * @return vec4: 4D vector or defaultValue
   */
  inline plg::vec4 Kv3GetVector4D(void* kv, const plg::vec4& defaultValue) {
    return __s2sdk_Kv3GetVector4D(kv, defaultValue);
  }

  using _Kv3GetQuaternion = plg::vec4 (*)(void*, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetQuaternion __s2sdk_Kv3GetQuaternion;
namespace s2sdk {
  /**
   * @brief Gets the quaternion value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (vec4): Default quaternion to return if kv is null
   * @return vec4: Quaternion as vec4 or defaultValue
   */
  inline plg::vec4 Kv3GetQuaternion(void* kv, const plg::vec4& defaultValue) {
    return __s2sdk_Kv3GetQuaternion(kv, defaultValue);
  }

  using _Kv3GetQAngle = plg::vec3 (*)(void*, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetQAngle __s2sdk_Kv3GetQAngle;
namespace s2sdk {
  /**
   * @brief Gets the angle (QAngle) value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (vec3): Default angle to return if kv is null
   * @return vec3: QAngle as vec3 or defaultValue
   */
  inline plg::vec3 Kv3GetQAngle(void* kv, const plg::vec3& defaultValue) {
    return __s2sdk_Kv3GetQAngle(kv, defaultValue);
  }

  using _Kv3GetMatrix3x4 = plg::mat4x4 (*)(void*, const plg::mat4x4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMatrix3x4 __s2sdk_Kv3GetMatrix3x4;
namespace s2sdk {
  /**
   * @brief Gets the 3x4 matrix value from the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param defaultValue (mat4x4): Default matrix to return if kv is null
   * @return mat4x4: 3x4 matrix as mat4x4 or defaultValue
   */
  inline plg::mat4x4 Kv3GetMatrix3x4(void* kv, const plg::mat4x4& defaultValue) {
    return __s2sdk_Kv3GetMatrix3x4(kv, defaultValue);
  }

  using _Kv3SetVector = void (*)(void*, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetVector __s2sdk_Kv3SetVector;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a 3D vector value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param vec (vec3): 3D vector to set
   */
  inline void Kv3SetVector(void* kv, const plg::vec3& vec) {
    return __s2sdk_Kv3SetVector(kv, vec);
  }

  using _Kv3SetVector2D = void (*)(void*, const plg::vec2&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetVector2D __s2sdk_Kv3SetVector2D;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a 2D vector value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param vec2d (vec2): 2D vector to set
   */
  inline void Kv3SetVector2D(void* kv, const plg::vec2& vec2d) {
    return __s2sdk_Kv3SetVector2D(kv, vec2d);
  }

  using _Kv3SetVector4D = void (*)(void*, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetVector4D __s2sdk_Kv3SetVector4D;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a 4D vector value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param vec4d (vec4): 4D vector to set
   */
  inline void Kv3SetVector4D(void* kv, const plg::vec4& vec4d) {
    return __s2sdk_Kv3SetVector4D(kv, vec4d);
  }

  using _Kv3SetQuaternion = void (*)(void*, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetQuaternion __s2sdk_Kv3SetQuaternion;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a quaternion value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param quat (vec4): Quaternion to set (as vec4)
   */
  inline void Kv3SetQuaternion(void* kv, const plg::vec4& quat) {
    return __s2sdk_Kv3SetQuaternion(kv, quat);
  }

  using _Kv3SetQAngle = void (*)(void*, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetQAngle __s2sdk_Kv3SetQAngle;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to an angle (QAngle) value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param ang (vec3): QAngle to set (as vec3)
   */
  inline void Kv3SetQAngle(void* kv, const plg::vec3& ang) {
    return __s2sdk_Kv3SetQAngle(kv, ang);
  }

  using _Kv3SetMatrix3x4 = void (*)(void*, const plg::mat4x4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMatrix3x4 __s2sdk_Kv3SetMatrix3x4;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to a 3x4 matrix value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param matrix (mat4x4): 3x4 matrix to set (as mat4x4)
   */
  inline void Kv3SetMatrix3x4(void* kv, const plg::mat4x4& matrix) {
    return __s2sdk_Kv3SetMatrix3x4(kv, matrix);
  }

  using _Kv3GetArrayElementCount = int32_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetArrayElementCount __s2sdk_Kv3GetArrayElementCount;
namespace s2sdk {
  /**
   * @brief Gets the number of elements in the array
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return int32: Number of array elements, or 0 if kv is null or not an array
   */
  inline int32_t Kv3GetArrayElementCount(void* kv) {
    return __s2sdk_Kv3GetArrayElementCount(kv);
  }

  using _Kv3SetArrayElementCount = void (*)(void*, int32_t, uint8_t, uint8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetArrayElementCount __s2sdk_Kv3SetArrayElementCount;
namespace s2sdk {
  /**
   * @brief Sets the number of elements in the array
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param count (int32): Number of elements to set
   * @param type (uint8): Type of array elements
   * @param subtype (uint8): Subtype of array elements
   */
  inline void Kv3SetArrayElementCount(void* kv, int32_t count, uint8_t type, uint8_t subtype) {
    return __s2sdk_Kv3SetArrayElementCount(kv, count, type, subtype);
  }

  using _Kv3SetToEmptyKV3Array = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetToEmptyKV3Array __s2sdk_Kv3SetToEmptyKV3Array;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to an empty KV3 array
   * @param kv (ptr64): Pointer to the KeyValues3 object
   */
  inline void Kv3SetToEmptyKV3Array(void* kv) {
    return __s2sdk_Kv3SetToEmptyKV3Array(kv);
  }

  using _Kv3GetArrayElement = void* (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetArrayElement __s2sdk_Kv3GetArrayElement;
namespace s2sdk {
  /**
   * @brief Gets an array element at the specified index
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param elem (int32): Index of the element to get
   * @return ptr64: Pointer to the element KeyValues3 object, or nullptr if invalid
   */
  inline void* Kv3GetArrayElement(void* kv, int32_t elem) {
    return __s2sdk_Kv3GetArrayElement(kv, elem);
  }

  using _Kv3ArrayInsertElementBefore = void* (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3ArrayInsertElementBefore __s2sdk_Kv3ArrayInsertElementBefore;
namespace s2sdk {
  /**
   * @brief Inserts a new element before the specified index
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param elem (int32): Index before which to insert
   * @return ptr64: Pointer to the newly inserted element, or nullptr if invalid
   */
  inline void* Kv3ArrayInsertElementBefore(void* kv, int32_t elem) {
    return __s2sdk_Kv3ArrayInsertElementBefore(kv, elem);
  }

  using _Kv3ArrayInsertElementAfter = void* (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3ArrayInsertElementAfter __s2sdk_Kv3ArrayInsertElementAfter;
namespace s2sdk {
  /**
   * @brief Inserts a new element after the specified index
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param elem (int32): Index after which to insert
   * @return ptr64: Pointer to the newly inserted element, or nullptr if invalid
   */
  inline void* Kv3ArrayInsertElementAfter(void* kv, int32_t elem) {
    return __s2sdk_Kv3ArrayInsertElementAfter(kv, elem);
  }

  using _Kv3ArrayAddElementToTail = void* (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3ArrayAddElementToTail __s2sdk_Kv3ArrayAddElementToTail;
namespace s2sdk {
  /**
   * @brief Adds a new element to the end of the array
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return ptr64: Pointer to the newly added element, or nullptr if invalid
   */
  inline void* Kv3ArrayAddElementToTail(void* kv) {
    return __s2sdk_Kv3ArrayAddElementToTail(kv);
  }

  using _Kv3ArraySwapItems = void (*)(void*, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3ArraySwapItems __s2sdk_Kv3ArraySwapItems;
namespace s2sdk {
  /**
   * @brief Swaps two array elements
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param idx1 (int32): Index of the first element
   * @param idx2 (int32): Index of the second element
   */
  inline void Kv3ArraySwapItems(void* kv, int32_t idx1, int32_t idx2) {
    return __s2sdk_Kv3ArraySwapItems(kv, idx1, idx2);
  }

  using _Kv3ArrayRemoveElement = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3ArrayRemoveElement __s2sdk_Kv3ArrayRemoveElement;
namespace s2sdk {
  /**
   * @brief Removes an element from the array
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param elem (int32): Index of the element to remove
   */
  inline void Kv3ArrayRemoveElement(void* kv, int32_t elem) {
    return __s2sdk_Kv3ArrayRemoveElement(kv, elem);
  }

  using _Kv3SetToEmptyTable = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetToEmptyTable __s2sdk_Kv3SetToEmptyTable;
namespace s2sdk {
  /**
   * @brief Sets the KeyValues3 object to an empty table
   * @param kv (ptr64): Pointer to the KeyValues3 object
   */
  inline void Kv3SetToEmptyTable(void* kv) {
    return __s2sdk_Kv3SetToEmptyTable(kv);
  }

  using _Kv3GetMemberCount = int32_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberCount __s2sdk_Kv3GetMemberCount;
namespace s2sdk {
  /**
   * @brief Gets the number of members in the table
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @return int32: Number of table members, or 0 if kv is null or not a table
   */
  inline int32_t Kv3GetMemberCount(void* kv) {
    return __s2sdk_Kv3GetMemberCount(kv);
  }

  using _Kv3HasMember = bool (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_Kv3HasMember __s2sdk_Kv3HasMember;
namespace s2sdk {
  /**
   * @brief Checks if a member with the specified name exists
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member to check
   * @return bool: true if the member exists, false otherwise
   */
  inline bool Kv3HasMember(void* kv, const plg::string& name) {
    return __s2sdk_Kv3HasMember(kv, name);
  }

  using _Kv3FindMember = void* (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_Kv3FindMember __s2sdk_Kv3FindMember;
namespace s2sdk {
  /**
   * @brief Finds a member by name
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member to find
   * @return ptr64: Pointer to the member KeyValues3 object, or nullptr if not found
   */
  inline void* Kv3FindMember(void* kv, const plg::string& name) {
    return __s2sdk_Kv3FindMember(kv, name);
  }

  using _Kv3FindOrCreateMember = void* (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_Kv3FindOrCreateMember __s2sdk_Kv3FindOrCreateMember;
namespace s2sdk {
  /**
   * @brief Finds a member by name, or creates it if it doesn't exist
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member to find or create
   * @return ptr64: Pointer to the member KeyValues3 object, or nullptr if kv is null
   */
  inline void* Kv3FindOrCreateMember(void* kv, const plg::string& name) {
    return __s2sdk_Kv3FindOrCreateMember(kv, name);
  }

  using _Kv3RemoveMember = bool (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_Kv3RemoveMember __s2sdk_Kv3RemoveMember;
namespace s2sdk {
  /**
   * @brief Removes a member from the table
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member to remove
   * @return bool: true if the member was removed, false otherwise
   */
  inline bool Kv3RemoveMember(void* kv, const plg::string& name) {
    return __s2sdk_Kv3RemoveMember(kv, name);
  }

  using _Kv3GetMemberName = plg::string (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberName __s2sdk_Kv3GetMemberName;
namespace s2sdk {
  /**
   * @brief Gets the name of a member at the specified index
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param index (int32): Index of the member
   * @return string: Name of the member, or empty string if invalid
   */
  inline plg::string Kv3GetMemberName(void* kv, int32_t index) {
    return __s2sdk_Kv3GetMemberName(kv, index);
  }

  using _Kv3GetMemberByIndex = void* (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberByIndex __s2sdk_Kv3GetMemberByIndex;
namespace s2sdk {
  /**
   * @brief Gets a member by index
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param index (int32): Index of the member to get
   * @return ptr64: Pointer to the member KeyValues3 object, or nullptr if invalid
   */
  inline void* Kv3GetMemberByIndex(void* kv, int32_t index) {
    return __s2sdk_Kv3GetMemberByIndex(kv, index);
  }

  using _Kv3GetMemberBool = bool (*)(void*, const plg::string&, bool);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberBool __s2sdk_Kv3GetMemberBool;
namespace s2sdk {
  /**
   * @brief Gets a boolean value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (bool): Default value to return if member not found
   * @return bool: Boolean value or defaultValue
   */
  inline bool Kv3GetMemberBool(void* kv, const plg::string& name, bool defaultValue) {
    return __s2sdk_Kv3GetMemberBool(kv, name, defaultValue);
  }

  using _Kv3GetMemberChar = char (*)(void*, const plg::string&, char);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberChar __s2sdk_Kv3GetMemberChar;
namespace s2sdk {
  /**
   * @brief Gets a char value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (char8): Default value to return if member not found
   * @return char8: Char value or defaultValue
   */
  inline char Kv3GetMemberChar(void* kv, const plg::string& name, char defaultValue) {
    return __s2sdk_Kv3GetMemberChar(kv, name, defaultValue);
  }

  using _Kv3GetMemberUChar32 = uint32_t (*)(void*, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberUChar32 __s2sdk_Kv3GetMemberUChar32;
namespace s2sdk {
  /**
   * @brief Gets a 32-bit Unicode character value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (uint32): Default value to return if member not found
   * @return uint32: 32-bit Unicode character value or defaultValue
   */
  inline uint32_t Kv3GetMemberUChar32(void* kv, const plg::string& name, uint32_t defaultValue) {
    return __s2sdk_Kv3GetMemberUChar32(kv, name, defaultValue);
  }

  using _Kv3GetMemberInt8 = int8_t (*)(void*, const plg::string&, int8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberInt8 __s2sdk_Kv3GetMemberInt8;
namespace s2sdk {
  /**
   * @brief Gets a signed 8-bit integer value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (int8): Default value to return if member not found
   * @return int8: int8_t value or defaultValue
   */
  inline int8_t Kv3GetMemberInt8(void* kv, const plg::string& name, int8_t defaultValue) {
    return __s2sdk_Kv3GetMemberInt8(kv, name, defaultValue);
  }

  using _Kv3GetMemberUInt8 = uint8_t (*)(void*, const plg::string&, uint8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberUInt8 __s2sdk_Kv3GetMemberUInt8;
namespace s2sdk {
  /**
   * @brief Gets an unsigned 8-bit integer value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (uint8): Default value to return if member not found
   * @return uint8: uint8_t value or defaultValue
   */
  inline uint8_t Kv3GetMemberUInt8(void* kv, const plg::string& name, uint8_t defaultValue) {
    return __s2sdk_Kv3GetMemberUInt8(kv, name, defaultValue);
  }

  using _Kv3GetMemberShort = int16_t (*)(void*, const plg::string&, int16_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberShort __s2sdk_Kv3GetMemberShort;
namespace s2sdk {
  /**
   * @brief Gets a signed 16-bit integer value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (int16): Default value to return if member not found
   * @return int16: int16_t value or defaultValue
   */
  inline int16_t Kv3GetMemberShort(void* kv, const plg::string& name, int16_t defaultValue) {
    return __s2sdk_Kv3GetMemberShort(kv, name, defaultValue);
  }

  using _Kv3GetMemberUShort = uint16_t (*)(void*, const plg::string&, uint16_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberUShort __s2sdk_Kv3GetMemberUShort;
namespace s2sdk {
  /**
   * @brief Gets an unsigned 16-bit integer value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (uint16): Default value to return if member not found
   * @return uint16: uint16_t value or defaultValue
   */
  inline uint16_t Kv3GetMemberUShort(void* kv, const plg::string& name, uint16_t defaultValue) {
    return __s2sdk_Kv3GetMemberUShort(kv, name, defaultValue);
  }

  using _Kv3GetMemberInt = int32_t (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberInt __s2sdk_Kv3GetMemberInt;
namespace s2sdk {
  /**
   * @brief Gets a signed 32-bit integer value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (int32): Default value to return if member not found
   * @return int32: int32_t value or defaultValue
   */
  inline int32_t Kv3GetMemberInt(void* kv, const plg::string& name, int32_t defaultValue) {
    return __s2sdk_Kv3GetMemberInt(kv, name, defaultValue);
  }

  using _Kv3GetMemberUInt = uint32_t (*)(void*, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberUInt __s2sdk_Kv3GetMemberUInt;
namespace s2sdk {
  /**
   * @brief Gets an unsigned 32-bit integer value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (uint32): Default value to return if member not found
   * @return uint32: uint32_t value or defaultValue
   */
  inline uint32_t Kv3GetMemberUInt(void* kv, const plg::string& name, uint32_t defaultValue) {
    return __s2sdk_Kv3GetMemberUInt(kv, name, defaultValue);
  }

  using _Kv3GetMemberInt64 = int64_t (*)(void*, const plg::string&, int64_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberInt64 __s2sdk_Kv3GetMemberInt64;
namespace s2sdk {
  /**
   * @brief Gets a signed 64-bit integer value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (int64): Default value to return if member not found
   * @return int64: int64_t value or defaultValue
   */
  inline int64_t Kv3GetMemberInt64(void* kv, const plg::string& name, int64_t defaultValue) {
    return __s2sdk_Kv3GetMemberInt64(kv, name, defaultValue);
  }

  using _Kv3GetMemberUInt64 = uint64_t (*)(void*, const plg::string&, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberUInt64 __s2sdk_Kv3GetMemberUInt64;
namespace s2sdk {
  /**
   * @brief Gets an unsigned 64-bit integer value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (uint64): Default value to return if member not found
   * @return uint64: uint64_t value or defaultValue
   */
  inline uint64_t Kv3GetMemberUInt64(void* kv, const plg::string& name, uint64_t defaultValue) {
    return __s2sdk_Kv3GetMemberUInt64(kv, name, defaultValue);
  }

  using _Kv3GetMemberFloat = float (*)(void*, const plg::string&, float);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberFloat __s2sdk_Kv3GetMemberFloat;
namespace s2sdk {
  /**
   * @brief Gets a float value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (float): Default value to return if member not found
   * @return float: Float value or defaultValue
   */
  inline float Kv3GetMemberFloat(void* kv, const plg::string& name, float defaultValue) {
    return __s2sdk_Kv3GetMemberFloat(kv, name, defaultValue);
  }

  using _Kv3GetMemberDouble = double (*)(void*, const plg::string&, double);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberDouble __s2sdk_Kv3GetMemberDouble;
namespace s2sdk {
  /**
   * @brief Gets a double value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (double): Default value to return if member not found
   * @return double: Double value or defaultValue
   */
  inline double Kv3GetMemberDouble(void* kv, const plg::string& name, double defaultValue) {
    return __s2sdk_Kv3GetMemberDouble(kv, name, defaultValue);
  }

  using _Kv3GetMemberPointer = void* (*)(void*, const plg::string&, void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberPointer __s2sdk_Kv3GetMemberPointer;
namespace s2sdk {
  /**
   * @brief Gets a pointer value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (ptr64): Default value to return if member not found
   * @return ptr64: Pointer value as uintptr_t or defaultValue
   */
  inline void* Kv3GetMemberPointer(void* kv, const plg::string& name, void* defaultValue) {
    return __s2sdk_Kv3GetMemberPointer(kv, name, defaultValue);
  }

  using _Kv3GetMemberStringToken = uint32_t (*)(void*, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberStringToken __s2sdk_Kv3GetMemberStringToken;
namespace s2sdk {
  /**
   * @brief Gets a string token value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (uint32): Default token value to return if member not found
   * @return uint32: String token hash code or defaultValue
   */
  inline uint32_t Kv3GetMemberStringToken(void* kv, const plg::string& name, uint32_t defaultValue) {
    return __s2sdk_Kv3GetMemberStringToken(kv, name, defaultValue);
  }

  using _Kv3GetMemberEHandle = int32_t (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberEHandle __s2sdk_Kv3GetMemberEHandle;
namespace s2sdk {
  /**
   * @brief Gets an entity handle value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (int32): Default entity handle value to return if member not found
   * @return int32: Entity handle as int32_t or defaultValue
   */
  inline int32_t Kv3GetMemberEHandle(void* kv, const plg::string& name, int32_t defaultValue) {
    return __s2sdk_Kv3GetMemberEHandle(kv, name, defaultValue);
  }

  using _Kv3GetMemberString = plg::string (*)(void*, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberString __s2sdk_Kv3GetMemberString;
namespace s2sdk {
  /**
   * @brief Gets a string value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (string): Default string to return if member not found
   * @return string: String value or defaultValue
   */
  inline plg::string Kv3GetMemberString(void* kv, const plg::string& name, const plg::string& defaultValue) {
    return __s2sdk_Kv3GetMemberString(kv, name, defaultValue);
  }

  using _Kv3GetMemberColor = plg::vec4 (*)(void*, const plg::string&, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberColor __s2sdk_Kv3GetMemberColor;
namespace s2sdk {
  /**
   * @brief Gets a color value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (vec4): Default color value to return if member not found
   * @return vec4: Color value as vec4 or defaultValue
   */
  inline plg::vec4 Kv3GetMemberColor(void* kv, const plg::string& name, const plg::vec4& defaultValue) {
    return __s2sdk_Kv3GetMemberColor(kv, name, defaultValue);
  }

  using _Kv3GetMemberVector = plg::vec3 (*)(void*, const plg::string&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberVector __s2sdk_Kv3GetMemberVector;
namespace s2sdk {
  /**
   * @brief Gets a 3D vector value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (vec3): Default vector to return if member not found
   * @return vec3: 3D vector or defaultValue
   */
  inline plg::vec3 Kv3GetMemberVector(void* kv, const plg::string& name, const plg::vec3& defaultValue) {
    return __s2sdk_Kv3GetMemberVector(kv, name, defaultValue);
  }

  using _Kv3GetMemberVector2D = plg::vec2 (*)(void*, const plg::string&, const plg::vec2&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberVector2D __s2sdk_Kv3GetMemberVector2D;
namespace s2sdk {
  /**
   * @brief Gets a 2D vector value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (vec2): Default 2D vector to return if member not found
   * @return vec2: 2D vector or defaultValue
   */
  inline plg::vec2 Kv3GetMemberVector2D(void* kv, const plg::string& name, const plg::vec2& defaultValue) {
    return __s2sdk_Kv3GetMemberVector2D(kv, name, defaultValue);
  }

  using _Kv3GetMemberVector4D = plg::vec4 (*)(void*, const plg::string&, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberVector4D __s2sdk_Kv3GetMemberVector4D;
namespace s2sdk {
  /**
   * @brief Gets a 4D vector value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (vec4): Default 4D vector to return if member not found
   * @return vec4: 4D vector or defaultValue
   */
  inline plg::vec4 Kv3GetMemberVector4D(void* kv, const plg::string& name, const plg::vec4& defaultValue) {
    return __s2sdk_Kv3GetMemberVector4D(kv, name, defaultValue);
  }

  using _Kv3GetMemberQuaternion = plg::vec4 (*)(void*, const plg::string&, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberQuaternion __s2sdk_Kv3GetMemberQuaternion;
namespace s2sdk {
  /**
   * @brief Gets a quaternion value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (vec4): Default quaternion to return if member not found
   * @return vec4: Quaternion as vec4 or defaultValue
   */
  inline plg::vec4 Kv3GetMemberQuaternion(void* kv, const plg::string& name, const plg::vec4& defaultValue) {
    return __s2sdk_Kv3GetMemberQuaternion(kv, name, defaultValue);
  }

  using _Kv3GetMemberQAngle = plg::vec3 (*)(void*, const plg::string&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberQAngle __s2sdk_Kv3GetMemberQAngle;
namespace s2sdk {
  /**
   * @brief Gets an angle (QAngle) value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (vec3): Default angle to return if member not found
   * @return vec3: QAngle as vec3 or defaultValue
   */
  inline plg::vec3 Kv3GetMemberQAngle(void* kv, const plg::string& name, const plg::vec3& defaultValue) {
    return __s2sdk_Kv3GetMemberQAngle(kv, name, defaultValue);
  }

  using _Kv3GetMemberMatrix3x4 = plg::mat4x4 (*)(void*, const plg::string&, const plg::mat4x4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3GetMemberMatrix3x4 __s2sdk_Kv3GetMemberMatrix3x4;
namespace s2sdk {
  /**
   * @brief Gets a 3x4 matrix value from a table member
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param defaultValue (mat4x4): Default matrix to return if member not found
   * @return mat4x4: 3x4 matrix as mat4x4 or defaultValue
   */
  inline plg::mat4x4 Kv3GetMemberMatrix3x4(void* kv, const plg::string& name, const plg::mat4x4& defaultValue) {
    return __s2sdk_Kv3GetMemberMatrix3x4(kv, name, defaultValue);
  }

  using _Kv3SetMemberToNull = void (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberToNull __s2sdk_Kv3SetMemberToNull;
namespace s2sdk {
  /**
   * @brief Sets a table member to null
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   */
  inline void Kv3SetMemberToNull(void* kv, const plg::string& name) {
    return __s2sdk_Kv3SetMemberToNull(kv, name);
  }

  using _Kv3SetMemberToEmptyArray = void (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberToEmptyArray __s2sdk_Kv3SetMemberToEmptyArray;
namespace s2sdk {
  /**
   * @brief Sets a table member to an empty array
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   */
  inline void Kv3SetMemberToEmptyArray(void* kv, const plg::string& name) {
    return __s2sdk_Kv3SetMemberToEmptyArray(kv, name);
  }

  using _Kv3SetMemberToEmptyTable = void (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberToEmptyTable __s2sdk_Kv3SetMemberToEmptyTable;
namespace s2sdk {
  /**
   * @brief Sets a table member to an empty table
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   */
  inline void Kv3SetMemberToEmptyTable(void* kv, const plg::string& name) {
    return __s2sdk_Kv3SetMemberToEmptyTable(kv, name);
  }

  using _Kv3SetMemberToBinaryBlob = void (*)(void*, const plg::string&, const plg::vector<uint8_t>&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberToBinaryBlob __s2sdk_Kv3SetMemberToBinaryBlob;
namespace s2sdk {
  /**
   * @brief Sets a table member to a binary blob (copies the data)
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param blob (uint8[]): Vector containing the binary blob data
   */
  inline void Kv3SetMemberToBinaryBlob(void* kv, const plg::string& name, const plg::vector<uint8_t>& blob) {
    return __s2sdk_Kv3SetMemberToBinaryBlob(kv, name, blob);
  }

  using _Kv3SetMemberToBinaryBlobExternal = void (*)(void*, const plg::string&, const plg::vector<uint8_t>&, bool);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberToBinaryBlobExternal __s2sdk_Kv3SetMemberToBinaryBlobExternal;
namespace s2sdk {
  /**
   * @brief Sets a table member to an external binary blob (does not copy)
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param blob (uint8[]): Vector containing the external binary blob data
   * @param free_mem (bool): Whether to free the memory when the object is destroyed
   */
  inline void Kv3SetMemberToBinaryBlobExternal(void* kv, const plg::string& name, const plg::vector<uint8_t>& blob, bool free_mem) {
    return __s2sdk_Kv3SetMemberToBinaryBlobExternal(kv, name, blob, free_mem);
  }

  using _Kv3SetMemberToCopyOfValue = void (*)(void*, const plg::string&, void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberToCopyOfValue __s2sdk_Kv3SetMemberToCopyOfValue;
namespace s2sdk {
  /**
   * @brief Sets a table member to a copy of another KeyValues3 value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param other (ptr64): Pointer to the KeyValues3 object to copy
   */
  inline void Kv3SetMemberToCopyOfValue(void* kv, const plg::string& name, void* other) {
    return __s2sdk_Kv3SetMemberToCopyOfValue(kv, name, other);
  }

  using _Kv3SetMemberBool = void (*)(void*, const plg::string&, bool);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberBool __s2sdk_Kv3SetMemberBool;
namespace s2sdk {
  /**
   * @brief Sets a table member to a boolean value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param value (bool): Boolean value to set
   */
  inline void Kv3SetMemberBool(void* kv, const plg::string& name, bool value) {
    return __s2sdk_Kv3SetMemberBool(kv, name, value);
  }

  using _Kv3SetMemberChar = void (*)(void*, const plg::string&, char);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberChar __s2sdk_Kv3SetMemberChar;
namespace s2sdk {
  /**
   * @brief Sets a table member to a char value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param value (char8): Char value to set
   */
  inline void Kv3SetMemberChar(void* kv, const plg::string& name, char value) {
    return __s2sdk_Kv3SetMemberChar(kv, name, value);
  }

  using _Kv3SetMemberUChar32 = void (*)(void*, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberUChar32 __s2sdk_Kv3SetMemberUChar32;
namespace s2sdk {
  /**
   * @brief Sets a table member to a 32-bit Unicode character value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param value (uint32): 32-bit Unicode character value to set
   */
  inline void Kv3SetMemberUChar32(void* kv, const plg::string& name, uint32_t value) {
    return __s2sdk_Kv3SetMemberUChar32(kv, name, value);
  }

  using _Kv3SetMemberInt8 = void (*)(void*, const plg::string&, int8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberInt8 __s2sdk_Kv3SetMemberInt8;
namespace s2sdk {
  /**
   * @brief Sets a table member to a signed 8-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param value (int8): int8_t value to set
   */
  inline void Kv3SetMemberInt8(void* kv, const plg::string& name, int8_t value) {
    return __s2sdk_Kv3SetMemberInt8(kv, name, value);
  }

  using _Kv3SetMemberUInt8 = void (*)(void*, const plg::string&, uint8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberUInt8 __s2sdk_Kv3SetMemberUInt8;
namespace s2sdk {
  /**
   * @brief Sets a table member to an unsigned 8-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param value (uint8): uint8_t value to set
   */
  inline void Kv3SetMemberUInt8(void* kv, const plg::string& name, uint8_t value) {
    return __s2sdk_Kv3SetMemberUInt8(kv, name, value);
  }

  using _Kv3SetMemberShort = void (*)(void*, const plg::string&, int16_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberShort __s2sdk_Kv3SetMemberShort;
namespace s2sdk {
  /**
   * @brief Sets a table member to a signed 16-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param value (int16): int16_t value to set
   */
  inline void Kv3SetMemberShort(void* kv, const plg::string& name, int16_t value) {
    return __s2sdk_Kv3SetMemberShort(kv, name, value);
  }

  using _Kv3SetMemberUShort = void (*)(void*, const plg::string&, uint16_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberUShort __s2sdk_Kv3SetMemberUShort;
namespace s2sdk {
  /**
   * @brief Sets a table member to an unsigned 16-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param value (uint16): uint16_t value to set
   */
  inline void Kv3SetMemberUShort(void* kv, const plg::string& name, uint16_t value) {
    return __s2sdk_Kv3SetMemberUShort(kv, name, value);
  }

  using _Kv3SetMemberInt = void (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberInt __s2sdk_Kv3SetMemberInt;
namespace s2sdk {
  /**
   * @brief Sets a table member to a signed 32-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param value (int32): int32_t value to set
   */
  inline void Kv3SetMemberInt(void* kv, const plg::string& name, int32_t value) {
    return __s2sdk_Kv3SetMemberInt(kv, name, value);
  }

  using _Kv3SetMemberUInt = void (*)(void*, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberUInt __s2sdk_Kv3SetMemberUInt;
namespace s2sdk {
  /**
   * @brief Sets a table member to an unsigned 32-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param value (uint32): uint32_t value to set
   */
  inline void Kv3SetMemberUInt(void* kv, const plg::string& name, uint32_t value) {
    return __s2sdk_Kv3SetMemberUInt(kv, name, value);
  }

  using _Kv3SetMemberInt64 = void (*)(void*, const plg::string&, int64_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberInt64 __s2sdk_Kv3SetMemberInt64;
namespace s2sdk {
  /**
   * @brief Sets a table member to a signed 64-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param value (int64): int64_t value to set
   */
  inline void Kv3SetMemberInt64(void* kv, const plg::string& name, int64_t value) {
    return __s2sdk_Kv3SetMemberInt64(kv, name, value);
  }

  using _Kv3SetMemberUInt64 = void (*)(void*, const plg::string&, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberUInt64 __s2sdk_Kv3SetMemberUInt64;
namespace s2sdk {
  /**
   * @brief Sets a table member to an unsigned 64-bit integer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param value (uint64): uint64_t value to set
   */
  inline void Kv3SetMemberUInt64(void* kv, const plg::string& name, uint64_t value) {
    return __s2sdk_Kv3SetMemberUInt64(kv, name, value);
  }

  using _Kv3SetMemberFloat = void (*)(void*, const plg::string&, float);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberFloat __s2sdk_Kv3SetMemberFloat;
namespace s2sdk {
  /**
   * @brief Sets a table member to a float value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param value (float): Float value to set
   */
  inline void Kv3SetMemberFloat(void* kv, const plg::string& name, float value) {
    return __s2sdk_Kv3SetMemberFloat(kv, name, value);
  }

  using _Kv3SetMemberDouble = void (*)(void*, const plg::string&, double);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberDouble __s2sdk_Kv3SetMemberDouble;
namespace s2sdk {
  /**
   * @brief Sets a table member to a double value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param value (double): Double value to set
   */
  inline void Kv3SetMemberDouble(void* kv, const plg::string& name, double value) {
    return __s2sdk_Kv3SetMemberDouble(kv, name, value);
  }

  using _Kv3SetMemberPointer = void (*)(void*, const plg::string&, void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberPointer __s2sdk_Kv3SetMemberPointer;
namespace s2sdk {
  /**
   * @brief Sets a table member to a pointer value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param ptr (ptr64): Pointer value as uintptr_t to set
   */
  inline void Kv3SetMemberPointer(void* kv, const plg::string& name, void* ptr) {
    return __s2sdk_Kv3SetMemberPointer(kv, name, ptr);
  }

  using _Kv3SetMemberStringToken = void (*)(void*, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberStringToken __s2sdk_Kv3SetMemberStringToken;
namespace s2sdk {
  /**
   * @brief Sets a table member to a string token value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param token (uint32): String token hash code to set
   */
  inline void Kv3SetMemberStringToken(void* kv, const plg::string& name, uint32_t token) {
    return __s2sdk_Kv3SetMemberStringToken(kv, name, token);
  }

  using _Kv3SetMemberEHandle = void (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberEHandle __s2sdk_Kv3SetMemberEHandle;
namespace s2sdk {
  /**
   * @brief Sets a table member to an entity handle value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param ehandle (int32): Entity handle value to set
   */
  inline void Kv3SetMemberEHandle(void* kv, const plg::string& name, int32_t ehandle) {
    return __s2sdk_Kv3SetMemberEHandle(kv, name, ehandle);
  }

  using _Kv3SetMemberString = void (*)(void*, const plg::string&, const plg::string&, uint8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberString __s2sdk_Kv3SetMemberString;
namespace s2sdk {
  /**
   * @brief Sets a table member to a string value (copies the string)
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param str (string): String value to set
   * @param subtype (uint8): String subtype enumeration value
   */
  inline void Kv3SetMemberString(void* kv, const plg::string& name, const plg::string& str, uint8_t subtype) {
    return __s2sdk_Kv3SetMemberString(kv, name, str, subtype);
  }

  using _Kv3SetMemberStringExternal = void (*)(void*, const plg::string&, const plg::string&, uint8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberStringExternal __s2sdk_Kv3SetMemberStringExternal;
namespace s2sdk {
  /**
   * @brief Sets a table member to an external string value (does not copy)
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param str (string): External string value to reference
   * @param subtype (uint8): String subtype enumeration value
   */
  inline void Kv3SetMemberStringExternal(void* kv, const plg::string& name, const plg::string& str, uint8_t subtype) {
    return __s2sdk_Kv3SetMemberStringExternal(kv, name, str, subtype);
  }

  using _Kv3SetMemberColor = void (*)(void*, const plg::string&, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberColor __s2sdk_Kv3SetMemberColor;
namespace s2sdk {
  /**
   * @brief Sets a table member to a color value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param color (vec4): Color value as vec4 to set
   */
  inline void Kv3SetMemberColor(void* kv, const plg::string& name, const plg::vec4& color) {
    return __s2sdk_Kv3SetMemberColor(kv, name, color);
  }

  using _Kv3SetMemberVector = void (*)(void*, const plg::string&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberVector __s2sdk_Kv3SetMemberVector;
namespace s2sdk {
  /**
   * @brief Sets a table member to a 3D vector value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param vec (vec3): 3D vector to set
   */
  inline void Kv3SetMemberVector(void* kv, const plg::string& name, const plg::vec3& vec) {
    return __s2sdk_Kv3SetMemberVector(kv, name, vec);
  }

  using _Kv3SetMemberVector2D = void (*)(void*, const plg::string&, const plg::vec2&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberVector2D __s2sdk_Kv3SetMemberVector2D;
namespace s2sdk {
  /**
   * @brief Sets a table member to a 2D vector value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param vec2d (vec2): 2D vector to set
   */
  inline void Kv3SetMemberVector2D(void* kv, const plg::string& name, const plg::vec2& vec2d) {
    return __s2sdk_Kv3SetMemberVector2D(kv, name, vec2d);
  }

  using _Kv3SetMemberVector4D = void (*)(void*, const plg::string&, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberVector4D __s2sdk_Kv3SetMemberVector4D;
namespace s2sdk {
  /**
   * @brief Sets a table member to a 4D vector value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param vec4d (vec4): 4D vector to set
   */
  inline void Kv3SetMemberVector4D(void* kv, const plg::string& name, const plg::vec4& vec4d) {
    return __s2sdk_Kv3SetMemberVector4D(kv, name, vec4d);
  }

  using _Kv3SetMemberQuaternion = void (*)(void*, const plg::string&, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberQuaternion __s2sdk_Kv3SetMemberQuaternion;
namespace s2sdk {
  /**
   * @brief Sets a table member to a quaternion value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param quat (vec4): Quaternion to set (as vec4)
   */
  inline void Kv3SetMemberQuaternion(void* kv, const plg::string& name, const plg::vec4& quat) {
    return __s2sdk_Kv3SetMemberQuaternion(kv, name, quat);
  }

  using _Kv3SetMemberQAngle = void (*)(void*, const plg::string&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberQAngle __s2sdk_Kv3SetMemberQAngle;
namespace s2sdk {
  /**
   * @brief Sets a table member to an angle (QAngle) value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param ang (vec3): QAngle to set (as vec3)
   */
  inline void Kv3SetMemberQAngle(void* kv, const plg::string& name, const plg::vec3& ang) {
    return __s2sdk_Kv3SetMemberQAngle(kv, name, ang);
  }

  using _Kv3SetMemberMatrix3x4 = void (*)(void*, const plg::string&, const plg::mat4x4&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SetMemberMatrix3x4 __s2sdk_Kv3SetMemberMatrix3x4;
namespace s2sdk {
  /**
   * @brief Sets a table member to a 3x4 matrix value
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param name (string): Name of the member
   * @param matrix (mat4x4): 3x4 matrix to set (as mat4x4)
   */
  inline void Kv3SetMemberMatrix3x4(void* kv, const plg::string& name, const plg::mat4x4& matrix) {
    return __s2sdk_Kv3SetMemberMatrix3x4(kv, name, matrix);
  }

  using _Kv3DebugPrint = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_Kv3DebugPrint __s2sdk_Kv3DebugPrint;
namespace s2sdk {
  /**
   * @brief Prints debug information about the KeyValues3 object
   * @param kv (ptr64): Pointer to the KeyValues3 object
   */
  inline void Kv3DebugPrint(void* kv) {
    return __s2sdk_Kv3DebugPrint(kv);
  }

  using _Kv3LoadFromBuffer = bool (*)(void*, plg::string&, const plg::vector<uint8_t>&, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3LoadFromBuffer __s2sdk_Kv3LoadFromBuffer;
namespace s2sdk {
  /**
   * @brief Loads KeyValues3 data from a buffer into a context
   * @param context (ptr64): Pointer to the KeyValues3 context
   * @param error (string&): Output string for error messages
   * @param input (uint8[]): Vector containing the input buffer data
   * @param kv_name (string): Name for the KeyValues3 object
   * @param flags (uint32): Loading flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3LoadFromBuffer(void* context, plg::string& error, const plg::vector<uint8_t>& input, const plg::string& kv_name, uint32_t flags) {
    return __s2sdk_Kv3LoadFromBuffer(context, error, input, kv_name, flags);
  }

  using _Kv3Load = bool (*)(void*, plg::string&, const plg::vector<uint8_t>&, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3Load __s2sdk_Kv3Load;
namespace s2sdk {
  /**
   * @brief Loads KeyValues3 data from a buffer
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param input (uint8[]): Vector containing the input buffer data
   * @param kv_name (string): Name for the KeyValues3 object
   * @param flags (uint32): Loading flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3Load(void* kv, plg::string& error, const plg::vector<uint8_t>& input, const plg::string& kv_name, uint32_t flags) {
    return __s2sdk_Kv3Load(kv, error, input, kv_name, flags);
  }

  using _Kv3LoadFromText = bool (*)(void*, plg::string&, const plg::string&, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3LoadFromText __s2sdk_Kv3LoadFromText;
namespace s2sdk {
  /**
   * @brief Loads KeyValues3 data from a text string
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param input (string): Text string containing KV3 data
   * @param kv_name (string): Name for the KeyValues3 object
   * @param flags (uint32): Loading flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3LoadFromText(void* kv, plg::string& error, const plg::string& input, const plg::string& kv_name, uint32_t flags) {
    return __s2sdk_Kv3LoadFromText(kv, error, input, kv_name, flags);
  }

  using _Kv3LoadFromFileToContext = bool (*)(void*, plg::string&, const plg::string&, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3LoadFromFileToContext __s2sdk_Kv3LoadFromFileToContext;
namespace s2sdk {
  /**
   * @brief Loads KeyValues3 data from a file into a context
   * @param context (ptr64): Pointer to the KeyValues3 context
   * @param error (string&): Output string for error messages
   * @param filename (string): Name of the file to load
   * @param path (string): Path to the file
   * @param flags (uint32): Loading flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3LoadFromFileToContext(void* context, plg::string& error, const plg::string& filename, const plg::string& path, uint32_t flags) {
    return __s2sdk_Kv3LoadFromFileToContext(context, error, filename, path, flags);
  }

  using _Kv3LoadFromFile = bool (*)(void*, plg::string&, const plg::string&, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3LoadFromFile __s2sdk_Kv3LoadFromFile;
namespace s2sdk {
  /**
   * @brief Loads KeyValues3 data from a file
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param filename (string): Name of the file to load
   * @param path (string): Path to the file
   * @param flags (uint32): Loading flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3LoadFromFile(void* kv, plg::string& error, const plg::string& filename, const plg::string& path, uint32_t flags) {
    return __s2sdk_Kv3LoadFromFile(kv, error, filename, path, flags);
  }

  using _Kv3LoadFromJSON = bool (*)(void*, plg::string&, const plg::string&, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3LoadFromJSON __s2sdk_Kv3LoadFromJSON;
namespace s2sdk {
  /**
   * @brief Loads KeyValues3 data from a JSON string
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param input (string): JSON string
   * @param kv_name (string): Name for the KeyValues3 object
   * @param flags (uint32): Loading flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3LoadFromJSON(void* kv, plg::string& error, const plg::string& input, const plg::string& kv_name, uint32_t flags) {
    return __s2sdk_Kv3LoadFromJSON(kv, error, input, kv_name, flags);
  }

  using _Kv3LoadFromJSONFile = bool (*)(void*, plg::string&, const plg::string&, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3LoadFromJSONFile __s2sdk_Kv3LoadFromJSONFile;
namespace s2sdk {
  /**
   * @brief Loads KeyValues3 data from a JSON file
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param path (string): Path to the file
   * @param filename (string): Name of the file to load
   * @param flags (uint32): Loading flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3LoadFromJSONFile(void* kv, plg::string& error, const plg::string& path, const plg::string& filename, uint32_t flags) {
    return __s2sdk_Kv3LoadFromJSONFile(kv, error, path, filename, flags);
  }

  using _Kv3LoadFromKV1File = bool (*)(void*, plg::string&, const plg::string&, const plg::string&, uint8_t, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3LoadFromKV1File __s2sdk_Kv3LoadFromKV1File;
namespace s2sdk {
  /**
   * @brief Loads KeyValues3 data from a KeyValues1 file
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param path (string): Path to the file
   * @param filename (string): Name of the file to load
   * @param esc_behavior (uint8): Escape sequence behavior for KV1 text
   * @param flags (uint32): Loading flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3LoadFromKV1File(void* kv, plg::string& error, const plg::string& path, const plg::string& filename, uint8_t esc_behavior, uint32_t flags) {
    return __s2sdk_Kv3LoadFromKV1File(kv, error, path, filename, esc_behavior, flags);
  }

  using _Kv3LoadFromKV1Text = bool (*)(void*, plg::string&, const plg::string&, uint8_t, const plg::string&, bool, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3LoadFromKV1Text __s2sdk_Kv3LoadFromKV1Text;
namespace s2sdk {
  /**
   * @brief Loads KeyValues3 data from a KeyValues1 text string
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param input (string): KV1 text string
   * @param esc_behavior (uint8): Escape sequence behavior for KV1 text
   * @param kv_name (string): Name for the KeyValues3 object
   * @param unk (bool): Unknown boolean parameter
   * @param flags (uint32): Loading flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3LoadFromKV1Text(void* kv, plg::string& error, const plg::string& input, uint8_t esc_behavior, const plg::string& kv_name, bool unk, uint32_t flags) {
    return __s2sdk_Kv3LoadFromKV1Text(kv, error, input, esc_behavior, kv_name, unk, flags);
  }

  using _Kv3LoadFromKV1TextTranslated = bool (*)(void*, plg::string&, const plg::string&, uint8_t, void*, int32_t, const plg::string&, bool, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3LoadFromKV1TextTranslated __s2sdk_Kv3LoadFromKV1TextTranslated;
namespace s2sdk {
  /**
   * @brief Loads KeyValues3 data from a KeyValues1 text string with translation
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param input (string): KV1 text string
   * @param esc_behavior (uint8): Escape sequence behavior for KV1 text
   * @param translation (ptr64): Pointer to translation table
   * @param unk1 (int32): Unknown integer parameter
   * @param kv_name (string): Name for the KeyValues3 object
   * @param unk2 (bool): Unknown boolean parameter
   * @param flags (uint32): Loading flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3LoadFromKV1TextTranslated(void* kv, plg::string& error, const plg::string& input, uint8_t esc_behavior, void* translation, int32_t unk1, const plg::string& kv_name, bool unk2, uint32_t flags) {
    return __s2sdk_Kv3LoadFromKV1TextTranslated(kv, error, input, esc_behavior, translation, unk1, kv_name, unk2, flags);
  }

  using _Kv3LoadFromKV3OrKV1 = bool (*)(void*, plg::string&, const plg::vector<uint8_t>&, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3LoadFromKV3OrKV1 __s2sdk_Kv3LoadFromKV3OrKV1;
namespace s2sdk {
  /**
   * @brief Loads data from a buffer that may be KV3 or KV1 format
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param input (uint8[]): Vector containing the input buffer data
   * @param kv_name (string): Name for the KeyValues3 object
   * @param flags (uint32): Loading flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3LoadFromKV3OrKV1(void* kv, plg::string& error, const plg::vector<uint8_t>& input, const plg::string& kv_name, uint32_t flags) {
    return __s2sdk_Kv3LoadFromKV3OrKV1(kv, error, input, kv_name, flags);
  }

  using _Kv3LoadFromOldSchemaText = bool (*)(void*, plg::string&, const plg::vector<uint8_t>&, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3LoadFromOldSchemaText __s2sdk_Kv3LoadFromOldSchemaText;
namespace s2sdk {
  /**
   * @brief Loads KeyValues3 data from old schema text format
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param input (uint8[]): Vector containing the input buffer data
   * @param kv_name (string): Name for the KeyValues3 object
   * @param flags (uint32): Loading flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3LoadFromOldSchemaText(void* kv, plg::string& error, const plg::vector<uint8_t>& input, const plg::string& kv_name, uint32_t flags) {
    return __s2sdk_Kv3LoadFromOldSchemaText(kv, error, input, kv_name, flags);
  }

  using _Kv3LoadTextNoHeader = bool (*)(void*, plg::string&, const plg::string&, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3LoadTextNoHeader __s2sdk_Kv3LoadTextNoHeader;
namespace s2sdk {
  /**
   * @brief Loads KeyValues3 text without a header
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param input (string): Text string containing KV3 data
   * @param kv_name (string): Name for the KeyValues3 object
   * @param flags (uint32): Loading flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3LoadTextNoHeader(void* kv, plg::string& error, const plg::string& input, const plg::string& kv_name, uint32_t flags) {
    return __s2sdk_Kv3LoadTextNoHeader(kv, error, input, kv_name, flags);
  }

  using _Kv3Save = bool (*)(void*, plg::string&, plg::vector<uint8_t>&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3Save __s2sdk_Kv3Save;
namespace s2sdk {
  /**
   * @brief Saves KeyValues3 data to a buffer
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param output (uint8[]&): Vector to store the output buffer data
   * @param flags (uint32): Saving flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3Save(void* kv, plg::string& error, plg::vector<uint8_t>& output, uint32_t flags) {
    return __s2sdk_Kv3Save(kv, error, output, flags);
  }

  using _Kv3SaveAsJSON = bool (*)(void*, plg::string&, plg::vector<uint8_t>&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SaveAsJSON __s2sdk_Kv3SaveAsJSON;
namespace s2sdk {
  /**
   * @brief Saves KeyValues3 data as JSON to a buffer
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param output (uint8[]&): Vector to store the output JSON data
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3SaveAsJSON(void* kv, plg::string& error, plg::vector<uint8_t>& output) {
    return __s2sdk_Kv3SaveAsJSON(kv, error, output);
  }

  using _Kv3SaveAsJSONString = bool (*)(void*, plg::string&, plg::string&);
}
extern "C" PLUGIN_API s2sdk::_Kv3SaveAsJSONString __s2sdk_Kv3SaveAsJSONString;
namespace s2sdk {
  /**
   * @brief Saves KeyValues3 data as a JSON string
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param output (string&): String to store the JSON output
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3SaveAsJSONString(void* kv, plg::string& error, plg::string& output) {
    return __s2sdk_Kv3SaveAsJSONString(kv, error, output);
  }

  using _Kv3SaveAsKV1Text = bool (*)(void*, plg::string&, plg::vector<uint8_t>&, uint8_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SaveAsKV1Text __s2sdk_Kv3SaveAsKV1Text;
namespace s2sdk {
  /**
   * @brief Saves KeyValues3 data as KeyValues1 text to a buffer
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param output (uint8[]&): Vector to store the output KV1 text data
   * @param esc_behavior (uint8): Escape sequence behavior for KV1 text
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3SaveAsKV1Text(void* kv, plg::string& error, plg::vector<uint8_t>& output, uint8_t esc_behavior) {
    return __s2sdk_Kv3SaveAsKV1Text(kv, error, output, esc_behavior);
  }

  using _Kv3SaveAsKV1TextTranslated = bool (*)(void*, plg::string&, plg::vector<uint8_t>&, uint8_t, void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SaveAsKV1TextTranslated __s2sdk_Kv3SaveAsKV1TextTranslated;
namespace s2sdk {
  /**
   * @brief Saves KeyValues3 data as KeyValues1 text with translation to a buffer
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param output (uint8[]&): Vector to store the output KV1 text data
   * @param esc_behavior (uint8): Escape sequence behavior for KV1 text
   * @param translation (ptr64): Pointer to translation table
   * @param unk (int32): Unknown integer parameter
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3SaveAsKV1TextTranslated(void* kv, plg::string& error, plg::vector<uint8_t>& output, uint8_t esc_behavior, void* translation, int32_t unk) {
    return __s2sdk_Kv3SaveAsKV1TextTranslated(kv, error, output, esc_behavior, translation, unk);
  }

  using _Kv3SaveTextNoHeaderToBuffer = bool (*)(void*, plg::string&, plg::vector<uint8_t>&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SaveTextNoHeaderToBuffer __s2sdk_Kv3SaveTextNoHeaderToBuffer;
namespace s2sdk {
  /**
   * @brief Saves KeyValues3 text without a header to a buffer
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param output (uint8[]&): Vector to store the output text data
   * @param flags (uint32): Saving flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3SaveTextNoHeaderToBuffer(void* kv, plg::string& error, plg::vector<uint8_t>& output, uint32_t flags) {
    return __s2sdk_Kv3SaveTextNoHeaderToBuffer(kv, error, output, flags);
  }

  using _Kv3SaveTextNoHeader = bool (*)(void*, plg::string&, plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SaveTextNoHeader __s2sdk_Kv3SaveTextNoHeader;
namespace s2sdk {
  /**
   * @brief Saves KeyValues3 text without a header to a string
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param output (string&): String to store the text output
   * @param flags (uint32): Saving flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3SaveTextNoHeader(void* kv, plg::string& error, plg::string& output, uint32_t flags) {
    return __s2sdk_Kv3SaveTextNoHeader(kv, error, output, flags);
  }

  using _Kv3SaveTextToString = bool (*)(void*, plg::string&, plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SaveTextToString __s2sdk_Kv3SaveTextToString;
namespace s2sdk {
  /**
   * @brief Saves KeyValues3 text to a string
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param output (string&): String to store the text output
   * @param flags (uint32): Saving flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3SaveTextToString(void* kv, plg::string& error, plg::string& output, uint32_t flags) {
    return __s2sdk_Kv3SaveTextToString(kv, error, output, flags);
  }

  using _Kv3SaveToFile = bool (*)(void*, plg::string&, const plg::string&, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_Kv3SaveToFile __s2sdk_Kv3SaveToFile;
namespace s2sdk {
  /**
   * @brief Saves KeyValues3 data to a file
   * @param kv (ptr64): Pointer to the KeyValues3 object
   * @param error (string&): Output string for error messages
   * @param filename (string): Name of the file to save
   * @param path (string): Path to save the file
   * @param flags (uint32): Saving flags
   * @return bool: true if successful, false otherwise
   */
  inline bool Kv3SaveToFile(void* kv, plg::string& error, const plg::string& filename, const plg::string& path, uint32_t flags) {
    return __s2sdk_Kv3SaveToFile(kv, error, filename, path, flags);
  }

  /**
   * @brief RAII wrapper for KeyValues3 handle.
   * @return 
   */
  class KeyValues3 final {
  public:
    KeyValues3() = default;

    /**
     * @brief Creates a new KeyValues3 object with specified type and subtype
     * @param type (int32): The KV3 type enumeration value
     * @param subtype (int32): The KV3 subtype enumeration value
     * @return 
     */
    explicit KeyValues3(int32_t type, int32_t subtype)
      : KeyValues3(Kv3Create(type, subtype), Ownership::Owned) {}

    /**
     * @brief Creates a new KeyValues3 object with cluster element, type, and subtype
     * @param cluster_elem (int32): The cluster element index
     * @param type (int32): The KV3 type enumeration value
     * @param subtype (int32): The KV3 subtype enumeration value
     * @return 
     */
    explicit KeyValues3(int32_t cluster_elem, int32_t type, int32_t subtype)
      : KeyValues3(Kv3CreateWithCluster(cluster_elem, type, subtype), Ownership::Owned) {}

    /**
     * @brief Creates a copy of an existing KeyValues3 object
     * @param other (ptr64): Pointer to the KeyValues3 object to copy
     * @return 
     */
    explicit KeyValues3(void* other)
      : KeyValues3(Kv3CreateCopy(other), Ownership::Owned) {}

    ~KeyValues3() {
      destroy();
    }

    KeyValues3(const KeyValues3&) = delete;
    KeyValues3& operator=(const KeyValues3&) = delete;

    KeyValues3(KeyValues3&& other) noexcept
      : _handle(other._handle)
      , _ownership(other._ownership) {
      other.nullify();
    }

    KeyValues3& operator=(KeyValues3&& other) noexcept {
      if (this != &other) {
        destroy();
        _handle = other._handle;
        _ownership = other._ownership;
        other.nullify();
      }
      return *this;
    }

    KeyValues3(void* handle, Ownership ownership) : _handle(handle), _ownership(ownership) {}

    [[nodiscard]] auto get() const noexcept { return _handle; }

    [[nodiscard]] auto release() noexcept {
      auto handle = _handle;
      nullify();
      return handle;
    }

    void reset() noexcept {
      destroy();
      nullify();
    }

    void swap(KeyValues3& other) noexcept {
      using std::swap;
      swap(_handle, other._handle);
      swap(_ownership, other._ownership);
    }

    friend void swap(KeyValues3& lhs, KeyValues3& rhs) noexcept { lhs.swap(rhs); }

    explicit operator bool() const noexcept { return _handle != nullptr; }
    [[nodiscard]] auto operator<=>(const KeyValues3& other) const noexcept { return _handle <=> other._handle; }
    [[nodiscard]] bool operator==(const KeyValues3& other) const noexcept { return _handle == other._handle; }

    /**
     * @brief Copies data from another KeyValues3 object
     * @param other (KeyValues3): Pointer to the source KeyValues3 object
     */
    void CopyFrom(const KeyValues3& other) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3CopyFrom(_handle, other.get());
    }

    /**
     * @brief Overlays keys from another KeyValues3 object
     * @param other (KeyValues3): Pointer to the source KeyValues3 object
     * @param depth (bool): Whether to perform a deep overlay
     */
    void OverlayKeysFrom(const KeyValues3& other, bool depth) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3OverlayKeysFrom(_handle, other.get(), depth);
    }

    /**
     * @brief Gets the context associated with a KeyValues3 object
     * @return ptr64: Pointer to the CKV3Arena, or nullptr if kv is null
     */
    void* GetContext() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetContext(_handle);
    }

    /**
     * @brief Gets the metadata associated with a KeyValues3 object
     * @param ppCtx (ptr64): Pointer to store the context pointer
     * @return ptr64: Pointer to the KV3MetaData_t structure, or nullptr if kv is null
     */
    void* GetMetaData(void* ppCtx) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMetaData(_handle, ppCtx);
    }

    /**
     * @brief Checks if a specific flag is set
     * @param flag (uint8): The flag to check
     * @return bool: true if the flag is set, false otherwise
     */
    bool HasFlag(uint8_t flag) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3HasFlag(_handle, flag);
    }

    /**
     * @brief Checks if any flags are set
     * @return bool: true if any flags are set, false otherwise
     */
    bool HasAnyFlags() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3HasAnyFlags(_handle);
    }

    /**
     * @brief Gets all flags as a bitmask
     * @return uint8: Bitmask of all flags, or 0 if kv is null
     */
    uint8_t GetAllFlags() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetAllFlags(_handle);
    }

    /**
     * @brief Sets all flags from a bitmask
     * @param flags (uint8): Bitmask of flags to set
     */
    void SetAllFlags(uint8_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetAllFlags(_handle, flags);
    }

    /**
     * @brief Sets or clears a specific flag
     * @param flag (uint8): The flag to modify
     * @param state (bool): true to set the flag, false to clear it
     */
    void SetFlag(uint8_t flag, bool state) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetFlag(_handle, flag, state);
    }

    /**
     * @brief Gets the basic type of the KeyValues3 object
     * @return uint8: The type enumeration value, or 0 if kv is null
     */
    uint8_t GetType() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetType(_handle);
    }

    /**
     * @brief Gets the extended type of the KeyValues3 object
     * @return uint8: The extended type enumeration value, or 0 if kv is null
     */
    uint8_t GetTypeEx() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetTypeEx(_handle);
    }

    /**
     * @brief Gets the subtype of the KeyValues3 object
     * @return uint8: The subtype enumeration value, or 0 if kv is null
     */
    uint8_t GetSubType() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetSubType(_handle);
    }

    /**
     * @brief Checks if the object has invalid member names
     * @return bool: true if invalid member names exist, false otherwise
     */
    bool HasInvalidMemberNames() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3HasInvalidMemberNames(_handle);
    }

    /**
     * @brief Sets the invalid member names flag
     * @param bValue (bool): true to mark as having invalid member names, false otherwise
     */
    void SetHasInvalidMemberNames(bool bValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetHasInvalidMemberNames(_handle, bValue);
    }

    /**
     * @brief Gets the type as a string representation
     * @return string: String representation of the type, or empty string if kv is null
     */
    plg::string GetTypeAsString() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetTypeAsString(_handle);
    }

    /**
     * @brief Gets the subtype as a string representation
     * @return string: String representation of the subtype, or empty string if kv is null
     */
    plg::string GetSubTypeAsString() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetSubTypeAsString(_handle);
    }

    /**
     * @brief Converts the KeyValues3 object to a string representation
     * @param flags (uint32): Formatting flags for the string conversion
     * @return string: String representation of the object, or empty string if kv is null
     */
    plg::string ToString(uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3ToString(_handle, flags);
    }

    /**
     * @brief Checks if the KeyValues3 object is null
     * @return bool: true if the object is null or the pointer is null, false otherwise
     */
    bool IsNull() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3IsNull(_handle);
    }

    /**
     * @brief Sets the KeyValues3 object to null
     */
    void SetToNull() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetToNull(_handle);
    }

    /**
     * @brief Checks if the KeyValues3 object is an array
     * @return bool: true if the object is an array, false otherwise
     */
    bool IsArray() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3IsArray(_handle);
    }

    /**
     * @brief Checks if the KeyValues3 object is a KV3 array
     * @return bool: true if the object is a KV3 array, false otherwise
     */
    bool IsKV3Array() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3IsKV3Array(_handle);
    }

    /**
     * @brief Checks if the KeyValues3 object is a table
     * @return bool: true if the object is a table, false otherwise
     */
    bool IsTable() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3IsTable(_handle);
    }

    /**
     * @brief Checks if the KeyValues3 object is a string
     * @return bool: true if the object is a string, false otherwise
     */
    bool IsString() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3IsString(_handle);
    }

    /**
     * @brief Gets the boolean value from the KeyValues3 object
     * @param defaultValue (bool): Default value to return if kv is null or conversion fails
     * @return bool: Boolean value or defaultValue
     */
    bool GetBool(bool defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetBool(_handle, defaultValue);
    }

    /**
     * @brief Gets the char value from the KeyValues3 object
     * @param defaultValue (char8): Default value to return if kv is null or conversion fails
     * @return char8: Char value or defaultValue
     */
    char GetChar(char defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetChar(_handle, defaultValue);
    }

    /**
     * @brief Gets the 32-bit Unicode character value from the KeyValues3 object
     * @param defaultValue (uint32): Default value to return if kv is null or conversion fails
     * @return uint32: 32-bit Unicode character value or defaultValue
     */
    uint32_t GetUChar32(uint32_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetUChar32(_handle, defaultValue);
    }

    /**
     * @brief Gets the signed 8-bit integer value from the KeyValues3 object
     * @param defaultValue (int8): Default value to return if kv is null or conversion fails
     * @return int8: int8_t value or defaultValue
     */
    int8_t GetInt8(int8_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetInt8(_handle, defaultValue);
    }

    /**
     * @brief Gets the unsigned 8-bit integer value from the KeyValues3 object
     * @param defaultValue (uint8): Default value to return if kv is null or conversion fails
     * @return uint8: uint8_t value or defaultValue
     */
    uint8_t GetUInt8(uint8_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetUInt8(_handle, defaultValue);
    }

    /**
     * @brief Gets the signed 16-bit integer value from the KeyValues3 object
     * @param defaultValue (int16): Default value to return if kv is null or conversion fails
     * @return int16: int16_t value or defaultValue
     */
    int16_t GetShort(int16_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetShort(_handle, defaultValue);
    }

    /**
     * @brief Gets the unsigned 16-bit integer value from the KeyValues3 object
     * @param defaultValue (uint16): Default value to return if kv is null or conversion fails
     * @return uint16: uint16_t value or defaultValue
     */
    uint16_t GetUShort(uint16_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetUShort(_handle, defaultValue);
    }

    /**
     * @brief Gets the signed 32-bit integer value from the KeyValues3 object
     * @param defaultValue (int32): Default value to return if kv is null or conversion fails
     * @return int32: int32_t value or defaultValue
     */
    int32_t GetInt(int32_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetInt(_handle, defaultValue);
    }

    /**
     * @brief Gets the unsigned 32-bit integer value from the KeyValues3 object
     * @param defaultValue (uint32): Default value to return if kv is null or conversion fails
     * @return uint32: uint32_t value or defaultValue
     */
    uint32_t GetUInt(uint32_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetUInt(_handle, defaultValue);
    }

    /**
     * @brief Gets the signed 64-bit integer value from the KeyValues3 object
     * @param defaultValue (int64): Default value to return if kv is null or conversion fails
     * @return int64: int64_t value or defaultValue
     */
    int64_t GetInt64(int64_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetInt64(_handle, defaultValue);
    }

    /**
     * @brief Gets the unsigned 64-bit integer value from the KeyValues3 object
     * @param defaultValue (uint64): Default value to return if kv is null or conversion fails
     * @return uint64: uint64_t value or defaultValue
     */
    uint64_t GetUInt64(uint64_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetUInt64(_handle, defaultValue);
    }

    /**
     * @brief Gets the float value from the KeyValues3 object
     * @param defaultValue (float): Default value to return if kv is null or conversion fails
     * @return float: Float value or defaultValue
     */
    float GetFloat(float defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetFloat(_handle, defaultValue);
    }

    /**
     * @brief Gets the double value from the KeyValues3 object
     * @param defaultValue (double): Default value to return if kv is null or conversion fails
     * @return double: Double value or defaultValue
     */
    double GetDouble(double defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetDouble(_handle, defaultValue);
    }

    /**
     * @brief Sets the KeyValues3 object to a boolean value
     * @param value (bool): Boolean value to set
     */
    void SetBool(bool value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetBool(_handle, value);
    }

    /**
     * @brief Sets the KeyValues3 object to a char value
     * @param value (char8): Char value to set
     */
    void SetChar(char value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetChar(_handle, value);
    }

    /**
     * @brief Sets the KeyValues3 object to a 32-bit Unicode character value
     * @param value (uint32): 32-bit Unicode character value to set
     */
    void SetUChar32(uint32_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetUChar32(_handle, value);
    }

    /**
     * @brief Sets the KeyValues3 object to a signed 8-bit integer value
     * @param value (int8): int8_t value to set
     */
    void SetInt8(int8_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetInt8(_handle, value);
    }

    /**
     * @brief Sets the KeyValues3 object to an unsigned 8-bit integer value
     * @param value (uint8): uint8_t value to set
     */
    void SetUInt8(uint8_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetUInt8(_handle, value);
    }

    /**
     * @brief Sets the KeyValues3 object to a signed 16-bit integer value
     * @param value (int16): int16_t value to set
     */
    void SetShort(int16_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetShort(_handle, value);
    }

    /**
     * @brief Sets the KeyValues3 object to an unsigned 16-bit integer value
     * @param value (uint16): uint16_t value to set
     */
    void SetUShort(uint16_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetUShort(_handle, value);
    }

    /**
     * @brief Sets the KeyValues3 object to a signed 32-bit integer value
     * @param value (int32): int32_t value to set
     */
    void SetInt(int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetInt(_handle, value);
    }

    /**
     * @brief Sets the KeyValues3 object to an unsigned 32-bit integer value
     * @param value (uint32): uint32_t value to set
     */
    void SetUInt(uint32_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetUInt(_handle, value);
    }

    /**
     * @brief Sets the KeyValues3 object to a signed 64-bit integer value
     * @param value (int64): int64_t value to set
     */
    void SetInt64(int64_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetInt64(_handle, value);
    }

    /**
     * @brief Sets the KeyValues3 object to an unsigned 64-bit integer value
     * @param value (uint64): uint64_t value to set
     */
    void SetUInt64(uint64_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetUInt64(_handle, value);
    }

    /**
     * @brief Sets the KeyValues3 object to a float value
     * @param value (float): Float value to set
     */
    void SetFloat(float value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetFloat(_handle, value);
    }

    /**
     * @brief Sets the KeyValues3 object to a double value
     * @param value (double): Double value to set
     */
    void SetDouble(double value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetDouble(_handle, value);
    }

    /**
     * @brief Gets the pointer value from the KeyValues3 object
     * @param defaultValue (ptr64): Default value to return if kv is null
     * @return ptr64: Pointer value as uintptr_t or defaultValue
     */
    void* GetPointer(void* defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetPointer(_handle, defaultValue);
    }

    /**
     * @brief Sets the KeyValues3 object to a pointer value
     * @param ptr (ptr64): Pointer value as uintptr_t to set
     */
    void SetPointer(void* ptr) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetPointer(_handle, ptr);
    }

    /**
     * @brief Gets the string token value from the KeyValues3 object
     * @param defaultValue (uint32): Default token value to return if kv is null
     * @return uint32: String token hash code or defaultValue
     */
    uint32_t GetStringToken(uint32_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetStringToken(_handle, defaultValue);
    }

    /**
     * @brief Sets the KeyValues3 object to a string token value
     * @param token (uint32): String token hash code to set
     */
    void SetStringToken(uint32_t token) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetStringToken(_handle, token);
    }

    /**
     * @brief Gets the entity handle value from the KeyValues3 object
     * @param defaultValue (int32): Default entity handle value to return if kv is null
     * @return int32: Entity handle as int32_t or defaultValue
     */
    int32_t GetEHandle(int32_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetEHandle(_handle, defaultValue);
    }

    /**
     * @brief Sets the KeyValues3 object to an entity handle value
     * @param ehandle (int32): Entity handle value to set
     */
    void SetEHandle(int32_t ehandle) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetEHandle(_handle, ehandle);
    }

    /**
     * @brief Gets the string value from the KeyValues3 object
     * @param defaultValue (string): Default string to return if kv is null or value is empty
     * @return string: String value or defaultValue
     */
    plg::string GetString(const plg::string& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetString(_handle, defaultValue);
    }

    /**
     * @brief Sets the KeyValues3 object to a string value (copies the string)
     * @param str (string): String value to set
     * @param subtype (uint8): String subtype enumeration value
     */
    void SetString(const plg::string& str, uint8_t subtype) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetString(_handle, str, subtype);
    }

    /**
     * @brief Sets the KeyValues3 object to an external string value (does not copy)
     * @param str (string): External string value to reference
     * @param subtype (uint8): String subtype enumeration value
     */
    void SetStringExternal(const plg::string& str, uint8_t subtype) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetStringExternal(_handle, str, subtype);
    }

    /**
     * @brief Gets the binary blob from the KeyValues3 object
     * @return uint8[]: Vector containing the binary blob data, or empty vector if kv is null
     */
    plg::vector<uint8_t> GetBinaryBlob() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetBinaryBlob(_handle);
    }

    /**
     * @brief Gets the size of the binary blob in the KeyValues3 object
     * @return int32: Size of the binary blob in bytes, or 0 if kv is null
     */
    int32_t GetBinaryBlobSize() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetBinaryBlobSize(_handle);
    }

    /**
     * @brief Sets the KeyValues3 object to a binary blob (copies the data)
     * @param blob (uint8[]): Vector containing the binary blob data
     */
    void SetToBinaryBlob(const plg::vector<uint8_t>& blob) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetToBinaryBlob(_handle, blob);
    }

    /**
     * @brief Sets the KeyValues3 object to an external binary blob (does not copy)
     * @param blob (uint8[]): Vector containing the external binary blob data
     * @param free_mem (bool): Whether to free the memory when the object is destroyed
     */
    void SetToBinaryBlobExternal(const plg::vector<uint8_t>& blob, bool free_mem) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetToBinaryBlobExternal(_handle, blob, free_mem);
    }

    /**
     * @brief Gets the color value from the KeyValues3 object
     * @param defaultValue (vec4): Default color value to return if kv is null
     * @return vec4: Color value as vec4 or defaultValue
     */
    plg::vec4 GetColor(const plg::vec4& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetColor(_handle, defaultValue);
    }

    /**
     * @brief Sets the KeyValues3 object to a color value
     * @param color (vec4): Color value as vec4 to set
     */
    void SetColor(const plg::vec4& color) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetColor(_handle, color);
    }

    /**
     * @brief Gets the 3D vector value from the KeyValues3 object
     * @param defaultValue (vec3): Default vector to return if kv is null
     * @return vec3: 3D vector or defaultValue
     */
    plg::vec3 GetVector(const plg::vec3& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetVector(_handle, defaultValue);
    }

    /**
     * @brief Gets the 2D vector value from the KeyValues3 object
     * @param defaultValue (vec2): Default 2D vector to return if kv is null
     * @return vec2: 2D vector or defaultValue
     */
    plg::vec2 GetVector2D(const plg::vec2& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetVector2D(_handle, defaultValue);
    }

    /**
     * @brief Gets the 4D vector value from the KeyValues3 object
     * @param defaultValue (vec4): Default 4D vector to return if kv is null
     * @return vec4: 4D vector or defaultValue
     */
    plg::vec4 GetVector4D(const plg::vec4& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetVector4D(_handle, defaultValue);
    }

    /**
     * @brief Gets the quaternion value from the KeyValues3 object
     * @param defaultValue (vec4): Default quaternion to return if kv is null
     * @return vec4: Quaternion as vec4 or defaultValue
     */
    plg::vec4 GetQuaternion(const plg::vec4& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetQuaternion(_handle, defaultValue);
    }

    /**
     * @brief Gets the angle (QAngle) value from the KeyValues3 object
     * @param defaultValue (vec3): Default angle to return if kv is null
     * @return vec3: QAngle as vec3 or defaultValue
     */
    plg::vec3 GetQAngle(const plg::vec3& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetQAngle(_handle, defaultValue);
    }

    /**
     * @brief Gets the 3x4 matrix value from the KeyValues3 object
     * @param defaultValue (mat4x4): Default matrix to return if kv is null
     * @return mat4x4: 3x4 matrix as mat4x4 or defaultValue
     */
    plg::mat4x4 GetMatrix3x4(const plg::mat4x4& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMatrix3x4(_handle, defaultValue);
    }

    /**
     * @brief Sets the KeyValues3 object to a 3D vector value
     * @param vec (vec3): 3D vector to set
     */
    void SetVector(const plg::vec3& vec) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetVector(_handle, vec);
    }

    /**
     * @brief Sets the KeyValues3 object to a 2D vector value
     * @param vec2d (vec2): 2D vector to set
     */
    void SetVector2D(const plg::vec2& vec2d) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetVector2D(_handle, vec2d);
    }

    /**
     * @brief Sets the KeyValues3 object to a 4D vector value
     * @param vec4d (vec4): 4D vector to set
     */
    void SetVector4D(const plg::vec4& vec4d) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetVector4D(_handle, vec4d);
    }

    /**
     * @brief Sets the KeyValues3 object to a quaternion value
     * @param quat (vec4): Quaternion to set (as vec4)
     */
    void SetQuaternion(const plg::vec4& quat) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetQuaternion(_handle, quat);
    }

    /**
     * @brief Sets the KeyValues3 object to an angle (QAngle) value
     * @param ang (vec3): QAngle to set (as vec3)
     */
    void SetQAngle(const plg::vec3& ang) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetQAngle(_handle, ang);
    }

    /**
     * @brief Sets the KeyValues3 object to a 3x4 matrix value
     * @param matrix (mat4x4): 3x4 matrix to set (as mat4x4)
     */
    void SetMatrix3x4(const plg::mat4x4& matrix) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMatrix3x4(_handle, matrix);
    }

    /**
     * @brief Gets the number of elements in the array
     * @return int32: Number of array elements, or 0 if kv is null or not an array
     */
    int32_t GetArrayElementCount() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetArrayElementCount(_handle);
    }

    /**
     * @brief Sets the number of elements in the array
     * @param count (int32): Number of elements to set
     * @param type (uint8): Type of array elements
     * @param subtype (uint8): Subtype of array elements
     */
    void SetArrayElementCount(int32_t count, uint8_t type, uint8_t subtype) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetArrayElementCount(_handle, count, type, subtype);
    }

    /**
     * @brief Sets the KeyValues3 object to an empty KV3 array
     */
    void SetToEmptyKV3Array() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetToEmptyKV3Array(_handle);
    }

    /**
     * @brief Gets an array element at the specified index
     * @param elem (int32): Index of the element to get
     * @return KeyValues3: Pointer to the element KeyValues3 object, or nullptr if invalid
     */
    KeyValues3 GetArrayElement(int32_t elem) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return KeyValues3(s2sdk::Kv3GetArrayElement(_handle, elem), Ownership::Borrowed);
    }

    /**
     * @brief Inserts a new element before the specified index
     * @param elem (int32): Index before which to insert
     * @return KeyValues3: Pointer to the newly inserted element, or nullptr if invalid
     */
    KeyValues3 ArrayInsertElementBefore(int32_t elem) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return KeyValues3(s2sdk::Kv3ArrayInsertElementBefore(_handle, elem), Ownership::Borrowed);
    }

    /**
     * @brief Inserts a new element after the specified index
     * @param elem (int32): Index after which to insert
     * @return KeyValues3: Pointer to the newly inserted element, or nullptr if invalid
     */
    KeyValues3 ArrayInsertElementAfter(int32_t elem) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return KeyValues3(s2sdk::Kv3ArrayInsertElementAfter(_handle, elem), Ownership::Borrowed);
    }

    /**
     * @brief Adds a new element to the end of the array
     * @return KeyValues3: Pointer to the newly added element, or nullptr if invalid
     */
    KeyValues3 ArrayAddElementToTail() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return KeyValues3(s2sdk::Kv3ArrayAddElementToTail(_handle), Ownership::Borrowed);
    }

    /**
     * @brief Swaps two array elements
     * @param idx1 (int32): Index of the first element
     * @param idx2 (int32): Index of the second element
     */
    void ArraySwapItems(int32_t idx1, int32_t idx2) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3ArraySwapItems(_handle, idx1, idx2);
    }

    /**
     * @brief Removes an element from the array
     * @param elem (int32): Index of the element to remove
     */
    void ArrayRemoveElement(int32_t elem) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3ArrayRemoveElement(_handle, elem);
    }

    /**
     * @brief Sets the KeyValues3 object to an empty table
     */
    void SetToEmptyTable() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetToEmptyTable(_handle);
    }

    /**
     * @brief Gets the number of members in the table
     * @return int32: Number of table members, or 0 if kv is null or not a table
     */
    int32_t GetMemberCount() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberCount(_handle);
    }

    /**
     * @brief Checks if a member with the specified name exists
     * @param name (string): Name of the member to check
     * @return bool: true if the member exists, false otherwise
     */
    bool HasMember(const plg::string& name) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3HasMember(_handle, name);
    }

    /**
     * @brief Finds a member by name
     * @param name (string): Name of the member to find
     * @return KeyValues3: Pointer to the member KeyValues3 object, or nullptr if not found
     */
    KeyValues3 FindMember(const plg::string& name) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return KeyValues3(s2sdk::Kv3FindMember(_handle, name), Ownership::Borrowed);
    }

    /**
     * @brief Finds a member by name, or creates it if it doesn't exist
     * @param name (string): Name of the member to find or create
     * @return KeyValues3: Pointer to the member KeyValues3 object, or nullptr if kv is null
     */
    KeyValues3 FindOrCreateMember(const plg::string& name) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return KeyValues3(s2sdk::Kv3FindOrCreateMember(_handle, name), Ownership::Borrowed);
    }

    /**
     * @brief Removes a member from the table
     * @param name (string): Name of the member to remove
     * @return bool: true if the member was removed, false otherwise
     */
    bool RemoveMember(const plg::string& name) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3RemoveMember(_handle, name);
    }

    /**
     * @brief Gets the name of a member at the specified index
     * @param index (int32): Index of the member
     * @return string: Name of the member, or empty string if invalid
     */
    plg::string GetMemberName(int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberName(_handle, index);
    }

    /**
     * @brief Gets a member by index
     * @param index (int32): Index of the member to get
     * @return KeyValues3: Pointer to the member KeyValues3 object, or nullptr if invalid
     */
    KeyValues3 GetMemberByIndex(int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return KeyValues3(s2sdk::Kv3GetMemberByIndex(_handle, index), Ownership::Borrowed);
    }

    /**
     * @brief Gets a boolean value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (bool): Default value to return if member not found
     * @return bool: Boolean value or defaultValue
     */
    bool GetMemberBool(const plg::string& name, bool defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberBool(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a char value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (char8): Default value to return if member not found
     * @return char8: Char value or defaultValue
     */
    char GetMemberChar(const plg::string& name, char defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberChar(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a 32-bit Unicode character value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (uint32): Default value to return if member not found
     * @return uint32: 32-bit Unicode character value or defaultValue
     */
    uint32_t GetMemberUChar32(const plg::string& name, uint32_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberUChar32(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a signed 8-bit integer value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (int8): Default value to return if member not found
     * @return int8: int8_t value or defaultValue
     */
    int8_t GetMemberInt8(const plg::string& name, int8_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberInt8(_handle, name, defaultValue);
    }

    /**
     * @brief Gets an unsigned 8-bit integer value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (uint8): Default value to return if member not found
     * @return uint8: uint8_t value or defaultValue
     */
    uint8_t GetMemberUInt8(const plg::string& name, uint8_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberUInt8(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a signed 16-bit integer value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (int16): Default value to return if member not found
     * @return int16: int16_t value or defaultValue
     */
    int16_t GetMemberShort(const plg::string& name, int16_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberShort(_handle, name, defaultValue);
    }

    /**
     * @brief Gets an unsigned 16-bit integer value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (uint16): Default value to return if member not found
     * @return uint16: uint16_t value or defaultValue
     */
    uint16_t GetMemberUShort(const plg::string& name, uint16_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberUShort(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a signed 32-bit integer value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (int32): Default value to return if member not found
     * @return int32: int32_t value or defaultValue
     */
    int32_t GetMemberInt(const plg::string& name, int32_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberInt(_handle, name, defaultValue);
    }

    /**
     * @brief Gets an unsigned 32-bit integer value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (uint32): Default value to return if member not found
     * @return uint32: uint32_t value or defaultValue
     */
    uint32_t GetMemberUInt(const plg::string& name, uint32_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberUInt(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a signed 64-bit integer value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (int64): Default value to return if member not found
     * @return int64: int64_t value or defaultValue
     */
    int64_t GetMemberInt64(const plg::string& name, int64_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberInt64(_handle, name, defaultValue);
    }

    /**
     * @brief Gets an unsigned 64-bit integer value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (uint64): Default value to return if member not found
     * @return uint64: uint64_t value or defaultValue
     */
    uint64_t GetMemberUInt64(const plg::string& name, uint64_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberUInt64(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a float value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (float): Default value to return if member not found
     * @return float: Float value or defaultValue
     */
    float GetMemberFloat(const plg::string& name, float defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberFloat(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a double value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (double): Default value to return if member not found
     * @return double: Double value or defaultValue
     */
    double GetMemberDouble(const plg::string& name, double defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberDouble(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a pointer value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (ptr64): Default value to return if member not found
     * @return ptr64: Pointer value as uintptr_t or defaultValue
     */
    void* GetMemberPointer(const plg::string& name, void* defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberPointer(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a string token value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (uint32): Default token value to return if member not found
     * @return uint32: String token hash code or defaultValue
     */
    uint32_t GetMemberStringToken(const plg::string& name, uint32_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberStringToken(_handle, name, defaultValue);
    }

    /**
     * @brief Gets an entity handle value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (int32): Default entity handle value to return if member not found
     * @return int32: Entity handle as int32_t or defaultValue
     */
    int32_t GetMemberEHandle(const plg::string& name, int32_t defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberEHandle(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a string value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (string): Default string to return if member not found
     * @return string: String value or defaultValue
     */
    plg::string GetMemberString(const plg::string& name, const plg::string& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberString(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a color value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (vec4): Default color value to return if member not found
     * @return vec4: Color value as vec4 or defaultValue
     */
    plg::vec4 GetMemberColor(const plg::string& name, const plg::vec4& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberColor(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a 3D vector value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (vec3): Default vector to return if member not found
     * @return vec3: 3D vector or defaultValue
     */
    plg::vec3 GetMemberVector(const plg::string& name, const plg::vec3& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberVector(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a 2D vector value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (vec2): Default 2D vector to return if member not found
     * @return vec2: 2D vector or defaultValue
     */
    plg::vec2 GetMemberVector2D(const plg::string& name, const plg::vec2& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberVector2D(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a 4D vector value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (vec4): Default 4D vector to return if member not found
     * @return vec4: 4D vector or defaultValue
     */
    plg::vec4 GetMemberVector4D(const plg::string& name, const plg::vec4& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberVector4D(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a quaternion value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (vec4): Default quaternion to return if member not found
     * @return vec4: Quaternion as vec4 or defaultValue
     */
    plg::vec4 GetMemberQuaternion(const plg::string& name, const plg::vec4& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberQuaternion(_handle, name, defaultValue);
    }

    /**
     * @brief Gets an angle (QAngle) value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (vec3): Default angle to return if member not found
     * @return vec3: QAngle as vec3 or defaultValue
     */
    plg::vec3 GetMemberQAngle(const plg::string& name, const plg::vec3& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberQAngle(_handle, name, defaultValue);
    }

    /**
     * @brief Gets a 3x4 matrix value from a table member
     * @param name (string): Name of the member
     * @param defaultValue (mat4x4): Default matrix to return if member not found
     * @return mat4x4: 3x4 matrix as mat4x4 or defaultValue
     */
    plg::mat4x4 GetMemberMatrix3x4(const plg::string& name, const plg::mat4x4& defaultValue) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3GetMemberMatrix3x4(_handle, name, defaultValue);
    }

    /**
     * @brief Sets a table member to null
     * @param name (string): Name of the member
     */
    void SetMemberToNull(const plg::string& name) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberToNull(_handle, name);
    }

    /**
     * @brief Sets a table member to an empty array
     * @param name (string): Name of the member
     */
    void SetMemberToEmptyArray(const plg::string& name) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberToEmptyArray(_handle, name);
    }

    /**
     * @brief Sets a table member to an empty table
     * @param name (string): Name of the member
     */
    void SetMemberToEmptyTable(const plg::string& name) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberToEmptyTable(_handle, name);
    }

    /**
     * @brief Sets a table member to a binary blob (copies the data)
     * @param name (string): Name of the member
     * @param blob (uint8[]): Vector containing the binary blob data
     */
    void SetMemberToBinaryBlob(const plg::string& name, const plg::vector<uint8_t>& blob) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberToBinaryBlob(_handle, name, blob);
    }

    /**
     * @brief Sets a table member to an external binary blob (does not copy)
     * @param name (string): Name of the member
     * @param blob (uint8[]): Vector containing the external binary blob data
     * @param free_mem (bool): Whether to free the memory when the object is destroyed
     */
    void SetMemberToBinaryBlobExternal(const plg::string& name, const plg::vector<uint8_t>& blob, bool free_mem) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberToBinaryBlobExternal(_handle, name, blob, free_mem);
    }

    /**
     * @brief Sets a table member to a copy of another KeyValues3 value
     * @param name (string): Name of the member
     * @param other (ptr64): Pointer to the KeyValues3 object to copy
     */
    void SetMemberToCopyOfValue(const plg::string& name, void* other) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberToCopyOfValue(_handle, name, other);
    }

    /**
     * @brief Sets a table member to a boolean value
     * @param name (string): Name of the member
     * @param value (bool): Boolean value to set
     */
    void SetMemberBool(const plg::string& name, bool value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberBool(_handle, name, value);
    }

    /**
     * @brief Sets a table member to a char value
     * @param name (string): Name of the member
     * @param value (char8): Char value to set
     */
    void SetMemberChar(const plg::string& name, char value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberChar(_handle, name, value);
    }

    /**
     * @brief Sets a table member to a 32-bit Unicode character value
     * @param name (string): Name of the member
     * @param value (uint32): 32-bit Unicode character value to set
     */
    void SetMemberUChar32(const plg::string& name, uint32_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberUChar32(_handle, name, value);
    }

    /**
     * @brief Sets a table member to a signed 8-bit integer value
     * @param name (string): Name of the member
     * @param value (int8): int8_t value to set
     */
    void SetMemberInt8(const plg::string& name, int8_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberInt8(_handle, name, value);
    }

    /**
     * @brief Sets a table member to an unsigned 8-bit integer value
     * @param name (string): Name of the member
     * @param value (uint8): uint8_t value to set
     */
    void SetMemberUInt8(const plg::string& name, uint8_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberUInt8(_handle, name, value);
    }

    /**
     * @brief Sets a table member to a signed 16-bit integer value
     * @param name (string): Name of the member
     * @param value (int16): int16_t value to set
     */
    void SetMemberShort(const plg::string& name, int16_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberShort(_handle, name, value);
    }

    /**
     * @brief Sets a table member to an unsigned 16-bit integer value
     * @param name (string): Name of the member
     * @param value (uint16): uint16_t value to set
     */
    void SetMemberUShort(const plg::string& name, uint16_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberUShort(_handle, name, value);
    }

    /**
     * @brief Sets a table member to a signed 32-bit integer value
     * @param name (string): Name of the member
     * @param value (int32): int32_t value to set
     */
    void SetMemberInt(const plg::string& name, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberInt(_handle, name, value);
    }

    /**
     * @brief Sets a table member to an unsigned 32-bit integer value
     * @param name (string): Name of the member
     * @param value (uint32): uint32_t value to set
     */
    void SetMemberUInt(const plg::string& name, uint32_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberUInt(_handle, name, value);
    }

    /**
     * @brief Sets a table member to a signed 64-bit integer value
     * @param name (string): Name of the member
     * @param value (int64): int64_t value to set
     */
    void SetMemberInt64(const plg::string& name, int64_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberInt64(_handle, name, value);
    }

    /**
     * @brief Sets a table member to an unsigned 64-bit integer value
     * @param name (string): Name of the member
     * @param value (uint64): uint64_t value to set
     */
    void SetMemberUInt64(const plg::string& name, uint64_t value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberUInt64(_handle, name, value);
    }

    /**
     * @brief Sets a table member to a float value
     * @param name (string): Name of the member
     * @param value (float): Float value to set
     */
    void SetMemberFloat(const plg::string& name, float value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberFloat(_handle, name, value);
    }

    /**
     * @brief Sets a table member to a double value
     * @param name (string): Name of the member
     * @param value (double): Double value to set
     */
    void SetMemberDouble(const plg::string& name, double value) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberDouble(_handle, name, value);
    }

    /**
     * @brief Sets a table member to a pointer value
     * @param name (string): Name of the member
     * @param ptr (ptr64): Pointer value as uintptr_t to set
     */
    void SetMemberPointer(const plg::string& name, void* ptr) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberPointer(_handle, name, ptr);
    }

    /**
     * @brief Sets a table member to a string token value
     * @param name (string): Name of the member
     * @param token (uint32): String token hash code to set
     */
    void SetMemberStringToken(const plg::string& name, uint32_t token) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberStringToken(_handle, name, token);
    }

    /**
     * @brief Sets a table member to an entity handle value
     * @param name (string): Name of the member
     * @param ehandle (int32): Entity handle value to set
     */
    void SetMemberEHandle(const plg::string& name, int32_t ehandle) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberEHandle(_handle, name, ehandle);
    }

    /**
     * @brief Sets a table member to a string value (copies the string)
     * @param name (string): Name of the member
     * @param str (string): String value to set
     * @param subtype (uint8): String subtype enumeration value
     */
    void SetMemberString(const plg::string& name, const plg::string& str, uint8_t subtype) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberString(_handle, name, str, subtype);
    }

    /**
     * @brief Sets a table member to an external string value (does not copy)
     * @param name (string): Name of the member
     * @param str (string): External string value to reference
     * @param subtype (uint8): String subtype enumeration value
     */
    void SetMemberStringExternal(const plg::string& name, const plg::string& str, uint8_t subtype) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberStringExternal(_handle, name, str, subtype);
    }

    /**
     * @brief Sets a table member to a color value
     * @param name (string): Name of the member
     * @param color (vec4): Color value as vec4 to set
     */
    void SetMemberColor(const plg::string& name, const plg::vec4& color) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberColor(_handle, name, color);
    }

    /**
     * @brief Sets a table member to a 3D vector value
     * @param name (string): Name of the member
     * @param vec (vec3): 3D vector to set
     */
    void SetMemberVector(const plg::string& name, const plg::vec3& vec) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberVector(_handle, name, vec);
    }

    /**
     * @brief Sets a table member to a 2D vector value
     * @param name (string): Name of the member
     * @param vec2d (vec2): 2D vector to set
     */
    void SetMemberVector2D(const plg::string& name, const plg::vec2& vec2d) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberVector2D(_handle, name, vec2d);
    }

    /**
     * @brief Sets a table member to a 4D vector value
     * @param name (string): Name of the member
     * @param vec4d (vec4): 4D vector to set
     */
    void SetMemberVector4D(const plg::string& name, const plg::vec4& vec4d) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberVector4D(_handle, name, vec4d);
    }

    /**
     * @brief Sets a table member to a quaternion value
     * @param name (string): Name of the member
     * @param quat (vec4): Quaternion to set (as vec4)
     */
    void SetMemberQuaternion(const plg::string& name, const plg::vec4& quat) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberQuaternion(_handle, name, quat);
    }

    /**
     * @brief Sets a table member to an angle (QAngle) value
     * @param name (string): Name of the member
     * @param ang (vec3): QAngle to set (as vec3)
     */
    void SetMemberQAngle(const plg::string& name, const plg::vec3& ang) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberQAngle(_handle, name, ang);
    }

    /**
     * @brief Sets a table member to a 3x4 matrix value
     * @param name (string): Name of the member
     * @param matrix (mat4x4): 3x4 matrix to set (as mat4x4)
     */
    void SetMemberMatrix3x4(const plg::string& name, const plg::mat4x4& matrix) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3SetMemberMatrix3x4(_handle, name, matrix);
    }

    /**
     * @brief Prints debug information about the KeyValues3 object
     */
    void DebugPrint() {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      s2sdk::Kv3DebugPrint(_handle);
    }

    /**
     * @brief Loads KeyValues3 data from a buffer
     * @param error (string&): Output string for error messages
     * @param input (uint8[]): Vector containing the input buffer data
     * @param kv_name (string): Name for the KeyValues3 object
     * @param flags (uint32): Loading flags
     * @return bool: true if successful, false otherwise
     */
    bool Load(plg::string& error, const plg::vector<uint8_t>& input, const plg::string& kv_name, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3Load(_handle, error, input, kv_name, flags);
    }

    /**
     * @brief Loads KeyValues3 data from a text string
     * @param error (string&): Output string for error messages
     * @param input (string): Text string containing KV3 data
     * @param kv_name (string): Name for the KeyValues3 object
     * @param flags (uint32): Loading flags
     * @return bool: true if successful, false otherwise
     */
    bool LoadFromText(plg::string& error, const plg::string& input, const plg::string& kv_name, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3LoadFromText(_handle, error, input, kv_name, flags);
    }

    /**
     * @brief Loads KeyValues3 data from a file
     * @param error (string&): Output string for error messages
     * @param filename (string): Name of the file to load
     * @param path (string): Path to the file
     * @param flags (uint32): Loading flags
     * @return bool: true if successful, false otherwise
     */
    bool LoadFromFile(plg::string& error, const plg::string& filename, const plg::string& path, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3LoadFromFile(_handle, error, filename, path, flags);
    }

    /**
     * @brief Loads KeyValues3 data from a JSON string
     * @param error (string&): Output string for error messages
     * @param input (string): JSON string
     * @param kv_name (string): Name for the KeyValues3 object
     * @param flags (uint32): Loading flags
     * @return bool: true if successful, false otherwise
     */
    bool LoadFromJSON(plg::string& error, const plg::string& input, const plg::string& kv_name, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3LoadFromJSON(_handle, error, input, kv_name, flags);
    }

    /**
     * @brief Loads KeyValues3 data from a JSON file
     * @param error (string&): Output string for error messages
     * @param path (string): Path to the file
     * @param filename (string): Name of the file to load
     * @param flags (uint32): Loading flags
     * @return bool: true if successful, false otherwise
     */
    bool LoadFromJSONFile(plg::string& error, const plg::string& path, const plg::string& filename, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3LoadFromJSONFile(_handle, error, path, filename, flags);
    }

    /**
     * @brief Loads KeyValues3 data from a KeyValues1 file
     * @param error (string&): Output string for error messages
     * @param path (string): Path to the file
     * @param filename (string): Name of the file to load
     * @param esc_behavior (uint8): Escape sequence behavior for KV1 text
     * @param flags (uint32): Loading flags
     * @return bool: true if successful, false otherwise
     */
    bool LoadFromKV1File(plg::string& error, const plg::string& path, const plg::string& filename, uint8_t esc_behavior, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3LoadFromKV1File(_handle, error, path, filename, esc_behavior, flags);
    }

    /**
     * @brief Loads KeyValues3 data from a KeyValues1 text string
     * @param error (string&): Output string for error messages
     * @param input (string): KV1 text string
     * @param esc_behavior (uint8): Escape sequence behavior for KV1 text
     * @param kv_name (string): Name for the KeyValues3 object
     * @param unk (bool): Unknown boolean parameter
     * @param flags (uint32): Loading flags
     * @return bool: true if successful, false otherwise
     */
    bool LoadFromKV1Text(plg::string& error, const plg::string& input, uint8_t esc_behavior, const plg::string& kv_name, bool unk, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3LoadFromKV1Text(_handle, error, input, esc_behavior, kv_name, unk, flags);
    }

    /**
     * @brief Loads KeyValues3 data from a KeyValues1 text string with translation
     * @param error (string&): Output string for error messages
     * @param input (string): KV1 text string
     * @param esc_behavior (uint8): Escape sequence behavior for KV1 text
     * @param translation (ptr64): Pointer to translation table
     * @param unk1 (int32): Unknown integer parameter
     * @param kv_name (string): Name for the KeyValues3 object
     * @param unk2 (bool): Unknown boolean parameter
     * @param flags (uint32): Loading flags
     * @return bool: true if successful, false otherwise
     */
    bool LoadFromKV1TextTranslated(plg::string& error, const plg::string& input, uint8_t esc_behavior, void* translation, int32_t unk1, const plg::string& kv_name, bool unk2, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3LoadFromKV1TextTranslated(_handle, error, input, esc_behavior, translation, unk1, kv_name, unk2, flags);
    }

    /**
     * @brief Loads data from a buffer that may be KV3 or KV1 format
     * @param error (string&): Output string for error messages
     * @param input (uint8[]): Vector containing the input buffer data
     * @param kv_name (string): Name for the KeyValues3 object
     * @param flags (uint32): Loading flags
     * @return bool: true if successful, false otherwise
     */
    bool LoadFromKV3OrKV1(plg::string& error, const plg::vector<uint8_t>& input, const plg::string& kv_name, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3LoadFromKV3OrKV1(_handle, error, input, kv_name, flags);
    }

    /**
     * @brief Loads KeyValues3 data from old schema text format
     * @param error (string&): Output string for error messages
     * @param input (uint8[]): Vector containing the input buffer data
     * @param kv_name (string): Name for the KeyValues3 object
     * @param flags (uint32): Loading flags
     * @return bool: true if successful, false otherwise
     */
    bool LoadFromOldSchemaText(plg::string& error, const plg::vector<uint8_t>& input, const plg::string& kv_name, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3LoadFromOldSchemaText(_handle, error, input, kv_name, flags);
    }

    /**
     * @brief Loads KeyValues3 text without a header
     * @param error (string&): Output string for error messages
     * @param input (string): Text string containing KV3 data
     * @param kv_name (string): Name for the KeyValues3 object
     * @param flags (uint32): Loading flags
     * @return bool: true if successful, false otherwise
     */
    bool LoadTextNoHeader(plg::string& error, const plg::string& input, const plg::string& kv_name, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3LoadTextNoHeader(_handle, error, input, kv_name, flags);
    }

    /**
     * @brief Saves KeyValues3 data to a buffer
     * @param error (string&): Output string for error messages
     * @param output (uint8[]&): Vector to store the output buffer data
     * @param flags (uint32): Saving flags
     * @return bool: true if successful, false otherwise
     */
    bool Save(plg::string& error, plg::vector<uint8_t>& output, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3Save(_handle, error, output, flags);
    }

    /**
     * @brief Saves KeyValues3 data as JSON to a buffer
     * @param error (string&): Output string for error messages
     * @param output (uint8[]&): Vector to store the output JSON data
     * @return bool: true if successful, false otherwise
     */
    bool SaveAsJSON(plg::string& error, plg::vector<uint8_t>& output) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3SaveAsJSON(_handle, error, output);
    }

    /**
     * @brief Saves KeyValues3 data as a JSON string
     * @param error (string&): Output string for error messages
     * @param output (string&): String to store the JSON output
     * @return bool: true if successful, false otherwise
     */
    bool SaveAsJSONString(plg::string& error, plg::string& output) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3SaveAsJSONString(_handle, error, output);
    }

    /**
     * @brief Saves KeyValues3 data as KeyValues1 text to a buffer
     * @param error (string&): Output string for error messages
     * @param output (uint8[]&): Vector to store the output KV1 text data
     * @param esc_behavior (uint8): Escape sequence behavior for KV1 text
     * @return bool: true if successful, false otherwise
     */
    bool SaveAsKV1Text(plg::string& error, plg::vector<uint8_t>& output, uint8_t esc_behavior) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3SaveAsKV1Text(_handle, error, output, esc_behavior);
    }

    /**
     * @brief Saves KeyValues3 data as KeyValues1 text with translation to a buffer
     * @param error (string&): Output string for error messages
     * @param output (uint8[]&): Vector to store the output KV1 text data
     * @param esc_behavior (uint8): Escape sequence behavior for KV1 text
     * @param translation (ptr64): Pointer to translation table
     * @param unk (int32): Unknown integer parameter
     * @return bool: true if successful, false otherwise
     */
    bool SaveAsKV1TextTranslated(plg::string& error, plg::vector<uint8_t>& output, uint8_t esc_behavior, void* translation, int32_t unk) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3SaveAsKV1TextTranslated(_handle, error, output, esc_behavior, translation, unk);
    }

    /**
     * @brief Saves KeyValues3 text without a header to a buffer
     * @param error (string&): Output string for error messages
     * @param output (uint8[]&): Vector to store the output text data
     * @param flags (uint32): Saving flags
     * @return bool: true if successful, false otherwise
     */
    bool SaveTextNoHeaderToBuffer(plg::string& error, plg::vector<uint8_t>& output, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3SaveTextNoHeaderToBuffer(_handle, error, output, flags);
    }

    /**
     * @brief Saves KeyValues3 text without a header to a string
     * @param error (string&): Output string for error messages
     * @param output (string&): String to store the text output
     * @param flags (uint32): Saving flags
     * @return bool: true if successful, false otherwise
     */
    bool SaveTextNoHeader(plg::string& error, plg::string& output, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3SaveTextNoHeader(_handle, error, output, flags);
    }

    /**
     * @brief Saves KeyValues3 text to a string
     * @param error (string&): Output string for error messages
     * @param output (string&): String to store the text output
     * @param flags (uint32): Saving flags
     * @return bool: true if successful, false otherwise
     */
    bool SaveTextToString(plg::string& error, plg::string& output, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3SaveTextToString(_handle, error, output, flags);
    }

    /**
     * @brief Saves KeyValues3 data to a file
     * @param error (string&): Output string for error messages
     * @param filename (string): Name of the file to save
     * @param path (string): Path to save the file
     * @param flags (uint32): Saving flags
     * @return bool: true if successful, false otherwise
     */
    bool SaveToFile(plg::string& error, const plg::string& filename, const plg::string& path, uint32_t flags) {
      if (_handle == nullptr) throw std::runtime_error("KeyValues3: empty handle");
      return s2sdk::Kv3SaveToFile(_handle, error, filename, path, flags);
    }

  private:
    void destroy() const noexcept {
      if (_handle != nullptr && _ownership == Ownership::Owned) {
        Kv3Destroy(_handle);
      }
    }

    void nullify() noexcept {
      _handle = nullptr;
      _ownership = Ownership::Borrowed;
    }

    void* _handle{nullptr};
    Ownership _ownership{Ownership::Borrowed};
  };


} // namespace s2sdk
