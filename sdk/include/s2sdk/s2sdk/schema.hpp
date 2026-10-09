#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: schema)

namespace s2sdk {

  using _GetSchemaOffset = int32_t (*)(const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetSchemaOffset __s2sdk_GetSchemaOffset;
namespace s2sdk {
  /**
   * @brief Get the offset of a member in a given schema class.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the member whose offset is to be retrieved.
   * @return int32: The offset of the member in the class, or -1 if the offset is not found.
   */
  inline int32_t GetSchemaOffset(const plg::string& className, const plg::string& memberName) {
    return __s2sdk_GetSchemaOffset(className, memberName);
  }

  using _GetSchemaChainOffset = int32_t (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetSchemaChainOffset __s2sdk_GetSchemaChainOffset;
namespace s2sdk {
  /**
   * @brief Get the offset of a chain in a given schema class.
   * @param className (string): The name of the class.
   * @return int32: The offset of the chain entity in the class, or -1 if the offset is not found.
   */
  inline int32_t GetSchemaChainOffset(const plg::string& className) {
    return __s2sdk_GetSchemaChainOffset(className);
  }

  using _IsSchemaFieldNetworked = bool (*)(const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_IsSchemaFieldNetworked __s2sdk_IsSchemaFieldNetworked;
namespace s2sdk {
  /**
   * @brief Check if a schema field is networked.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the member to check.
   * @return bool: True if the member is networked, false otherwise.
   */
  inline bool IsSchemaFieldNetworked(const plg::string& className, const plg::string& memberName) {
    return __s2sdk_IsSchemaFieldNetworked(className, memberName);
  }

  using _GetSchemaClassSize = int32_t (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetSchemaClassSize __s2sdk_GetSchemaClassSize;
namespace s2sdk {
  /**
   * @brief Get the size of a schema class.
   * @param className (string): The name of the class.
   * @return int32: The size of the class in bytes, or -1 if the class is not found.
   */
  inline int32_t GetSchemaClassSize(const plg::string& className) {
    return __s2sdk_GetSchemaClassSize(className);
  }

  using _GetEntData2 = int64_t (*)(void*, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntData2 __s2sdk_GetEntData2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the integer value at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @param size (int32): Number of bytes to read (valid values are 1, 2, 4 or 8).
   * @return int64: The integer value at the given memory location.
   */
  inline int64_t GetEntData2(void* entity, int32_t offset, int32_t size) {
    return __s2sdk_GetEntData2(entity, offset, size);
  }

  using _SetEntData2 = void (*)(void*, int32_t, int64_t, int32_t, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntData2 __s2sdk_SetEntData2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the integer value at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @param value (int64): The integer value to set.
   * @param size (int32): Number of bytes to write (valid values are 1, 2, 4 or 8).
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntData2(void* entity, int32_t offset, int64_t value, int32_t size, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntData2(entity, offset, value, size, changeState, chainOffset);
  }

  using _GetEntDataFloat2 = double (*)(void*, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataFloat2 __s2sdk_GetEntDataFloat2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the float value at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @param size (int32): Number of bytes to read (valid values are 1, 2, 4 or 8).
   * @return double: The float value at the given memory location.
   */
  inline double GetEntDataFloat2(void* entity, int32_t offset, int32_t size) {
    return __s2sdk_GetEntDataFloat2(entity, offset, size);
  }

  using _SetEntDataFloat2 = void (*)(void*, int32_t, double, int32_t, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataFloat2 __s2sdk_SetEntDataFloat2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the float value at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @param value (double): The float value to set.
   * @param size (int32): Number of bytes to write (valid values are 1, 2, 4 or 8).
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataFloat2(void* entity, int32_t offset, double value, int32_t size, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataFloat2(entity, offset, value, size, changeState, chainOffset);
  }

  using _GetEntDataColor2 = plg::vec4 (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataColor2 __s2sdk_GetEntDataColor2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the color value at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @return vec4: The color value at the given memory location.
   */
  inline plg::vec4 GetEntDataColor2(void* entity, int32_t offset) {
    return __s2sdk_GetEntDataColor2(entity, offset);
  }

  using _SetEntDataColor2 = void (*)(void*, int32_t, const plg::vec4&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataColor2 __s2sdk_SetEntDataColor2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the color at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @param value (vec4): The color value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataColor2(void* entity, int32_t offset, const plg::vec4& value, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataColor2(entity, offset, value, changeState, chainOffset);
  }

  using _GetEntDataString2 = plg::string (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataString2 __s2sdk_GetEntDataString2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the string value at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @return string: The string value at the given memory location.
   */
  inline plg::string GetEntDataString2(void* entity, int32_t offset) {
    return __s2sdk_GetEntDataString2(entity, offset);
  }

  using _SetEntDataString2 = void (*)(void*, int32_t, const plg::string&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataString2 __s2sdk_SetEntDataString2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the string at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @param value (string): The string value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataString2(void* entity, int32_t offset, const plg::string& value, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataString2(entity, offset, value, changeState, chainOffset);
  }

  using _GetEntDataCString2 = plg::string (*)(void*, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataCString2 __s2sdk_GetEntDataCString2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the string value at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @param size (int32): Number of bytes to read.
   * @return string: The string value at the given memory location.
   */
  inline plg::string GetEntDataCString2(void* entity, int32_t offset, int32_t size) {
    return __s2sdk_GetEntDataCString2(entity, offset, size);
  }

  using _SetEntDataCString2 = void (*)(void*, int32_t, const plg::string&, int32_t, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataCString2 __s2sdk_SetEntDataCString2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the string at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @param value (string): The string value to set.
   * @param size (int32): Number of bytes to write.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataCString2(void* entity, int32_t offset, const plg::string& value, int32_t size, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataCString2(entity, offset, value, size, changeState, chainOffset);
  }

  using _GetEntDataVector3D2 = plg::vec3 (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataVector3D2 __s2sdk_GetEntDataVector3D2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the vector value at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @return vec3: The vector value at the given memory location.
   */
  inline plg::vec3 GetEntDataVector3D2(void* entity, int32_t offset) {
    return __s2sdk_GetEntDataVector3D2(entity, offset);
  }

  using _SetEntDataVector3D2 = void (*)(void*, int32_t, const plg::vec3&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataVector3D2 __s2sdk_SetEntDataVector3D2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the vector at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @param value (vec3): The vector value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataVector3D2(void* entity, int32_t offset, const plg::vec3& value, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataVector3D2(entity, offset, value, changeState, chainOffset);
  }

  using _GetEntDataVector4D2 = plg::vec4 (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataVector4D2 __s2sdk_GetEntDataVector4D2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the vector value at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @return vec4: The vector value at the given memory location.
   */
  inline plg::vec4 GetEntDataVector4D2(void* entity, int32_t offset) {
    return __s2sdk_GetEntDataVector4D2(entity, offset);
  }

  using _SetEntDataVector4D2 = void (*)(void*, int32_t, const plg::vec4&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataVector4D2 __s2sdk_SetEntDataVector4D2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the vector at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @param value (vec4): The vector value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataVector4D2(void* entity, int32_t offset, const plg::vec4& value, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataVector4D2(entity, offset, value, changeState, chainOffset);
  }

  using _GetEntDataVector2D2 = plg::vec2 (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataVector2D2 __s2sdk_GetEntDataVector2D2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the vector value at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @return vec2: The vector value at the given memory location.
   */
  inline plg::vec2 GetEntDataVector2D2(void* entity, int32_t offset) {
    return __s2sdk_GetEntDataVector2D2(entity, offset);
  }

  using _SetEntDataVector2D2 = void (*)(void*, int32_t, const plg::vec2&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataVector2D2 __s2sdk_SetEntDataVector2D2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the vector at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @param value (vec2): The vector value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataVector2D2(void* entity, int32_t offset, const plg::vec2& value, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataVector2D2(entity, offset, value, changeState, chainOffset);
  }

  using _GetEntDataEnt2 = int32_t (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataEnt2 __s2sdk_GetEntDataEnt2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and retrieves the entity handle at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @return int32: The entity handle at the given memory location.
   */
  inline int32_t GetEntDataEnt2(void* entity, int32_t offset) {
    return __s2sdk_GetEntDataEnt2(entity, offset);
  }

  using _SetEntDataEnt2 = void (*)(void*, int32_t, int32_t, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataEnt2 __s2sdk_SetEntDataEnt2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the entity handle at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @param value (int32): The entity handle to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataEnt2(void* entity, int32_t offset, int32_t value, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataEnt2(entity, offset, value, changeState, chainOffset);
  }

  using _GetEntDataPtr2 = void* (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataPtr2 __s2sdk_GetEntDataPtr2;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and retrieves a pointer to the data at the given offset.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @return ptr64: A pointer to the data at the given memory location.
   */
  inline void* GetEntDataPtr2(void* entity, int32_t offset) {
    return __s2sdk_GetEntDataPtr2(entity, offset);
  }

  using _ChangeEntityState2 = void (*)(void*, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_ChangeEntityState2 __s2sdk_ChangeEntityState2;
namespace s2sdk {
  /**
   * @brief Updates the networked state of a schema field for a given entity pointer.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param offset (int32): The offset of the schema to use.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void ChangeEntityState2(void* entity, int32_t offset, int32_t chainOffset) {
    return __s2sdk_ChangeEntityState2(entity, offset, chainOffset);
  }

  using _GetEntData = int64_t (*)(int32_t, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntData __s2sdk_GetEntData;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the integer value at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @param size (int32): Number of bytes to read (valid values are 1, 2, 4 or 8).
   * @return int64: The integer value at the given memory location.
   */
  inline int64_t GetEntData(int32_t entityHandle, int32_t offset, int32_t size) {
    return __s2sdk_GetEntData(entityHandle, offset, size);
  }

  using _SetEntData = void (*)(int32_t, int32_t, int64_t, int32_t, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntData __s2sdk_SetEntData;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the integer value at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @param value (int64): The integer value to set.
   * @param size (int32): Number of bytes to write (valid values are 1, 2, 4 or 8).
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntData(int32_t entityHandle, int32_t offset, int64_t value, int32_t size, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntData(entityHandle, offset, value, size, changeState, chainOffset);
  }

  using _GetEntDataFloat = double (*)(int32_t, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataFloat __s2sdk_GetEntDataFloat;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the float value at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @param size (int32): Number of bytes to read (valid values are 1, 2, 4 or 8).
   * @return double: The float value at the given memory location.
   */
  inline double GetEntDataFloat(int32_t entityHandle, int32_t offset, int32_t size) {
    return __s2sdk_GetEntDataFloat(entityHandle, offset, size);
  }

  using _SetEntDataFloat = void (*)(int32_t, int32_t, double, int32_t, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataFloat __s2sdk_SetEntDataFloat;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the float value at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @param value (double): The float value to set.
   * @param size (int32): Number of bytes to write (valid values are 1, 2, 4 or 8).
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataFloat(int32_t entityHandle, int32_t offset, double value, int32_t size, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataFloat(entityHandle, offset, value, size, changeState, chainOffset);
  }

  using _GetEntDataColor = plg::vec4 (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataColor __s2sdk_GetEntDataColor;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the color value at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @return vec4: The color value at the given memory location.
   */
  inline plg::vec4 GetEntDataColor(int32_t entityHandle, int32_t offset) {
    return __s2sdk_GetEntDataColor(entityHandle, offset);
  }

  using _SetEntDataColor = void (*)(int32_t, int32_t, const plg::vec4&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataColor __s2sdk_SetEntDataColor;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the color at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @param value (vec4): The color value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataColor(int32_t entityHandle, int32_t offset, const plg::vec4& value, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataColor(entityHandle, offset, value, changeState, chainOffset);
  }

  using _GetEntDataString = plg::string (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataString __s2sdk_GetEntDataString;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the string value at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @return string: The string value at the given memory location.
   */
  inline plg::string GetEntDataString(int32_t entityHandle, int32_t offset) {
    return __s2sdk_GetEntDataString(entityHandle, offset);
  }

  using _SetEntDataString = void (*)(int32_t, int32_t, const plg::string&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataString __s2sdk_SetEntDataString;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the string at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @param value (string): The string value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataString(int32_t entityHandle, int32_t offset, const plg::string& value, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataString(entityHandle, offset, value, changeState, chainOffset);
  }

  using _GetEntDataCString = plg::string (*)(int32_t, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataCString __s2sdk_GetEntDataCString;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the string value at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @param size (int32): Number of bytes to read.
   * @return string: The string value at the given memory location.
   */
  inline plg::string GetEntDataCString(int32_t entityHandle, int32_t offset, int32_t size) {
    return __s2sdk_GetEntDataCString(entityHandle, offset, size);
  }

  using _SetEntDataCString = void (*)(int32_t, int32_t, const plg::string&, int32_t, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataCString __s2sdk_SetEntDataCString;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the string at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @param value (string): The string value to set.
   * @param size (int32): Number of bytes to write.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataCString(int32_t entityHandle, int32_t offset, const plg::string& value, int32_t size, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataCString(entityHandle, offset, value, size, changeState, chainOffset);
  }

  using _GetEntDataVector3D = plg::vec3 (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataVector3D __s2sdk_GetEntDataVector3D;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the vector value at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @return vec3: The vector value at the given memory location.
   */
  inline plg::vec3 GetEntDataVector3D(int32_t entityHandle, int32_t offset) {
    return __s2sdk_GetEntDataVector3D(entityHandle, offset);
  }

  using _SetEntDataVector3D = void (*)(int32_t, int32_t, const plg::vec3&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataVector3D __s2sdk_SetEntDataVector3D;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the vector at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @param value (vec3): The vector value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataVector3D(int32_t entityHandle, int32_t offset, const plg::vec3& value, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataVector3D(entityHandle, offset, value, changeState, chainOffset);
  }

  using _GetEntDataVector4D = plg::vec4 (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataVector4D __s2sdk_GetEntDataVector4D;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the vector value at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @return vec4: The vector value at the given memory location.
   */
  inline plg::vec4 GetEntDataVector4D(int32_t entityHandle, int32_t offset) {
    return __s2sdk_GetEntDataVector4D(entityHandle, offset);
  }

  using _SetEntDataVector4D = void (*)(int32_t, int32_t, const plg::vec4&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataVector4D __s2sdk_SetEntDataVector4D;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the vector at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @param value (vec4): The vector value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataVector4D(int32_t entityHandle, int32_t offset, const plg::vec4& value, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataVector4D(entityHandle, offset, value, changeState, chainOffset);
  }

  using _GetEntDataVector2D = plg::vec2 (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataVector2D __s2sdk_GetEntDataVector2D;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object schema and retrieves the vector value at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @return vec2: The vector value at the given memory location.
   */
  inline plg::vec2 GetEntDataVector2D(int32_t entityHandle, int32_t offset) {
    return __s2sdk_GetEntDataVector2D(entityHandle, offset);
  }

  using _SetEntDataVector2D = void (*)(int32_t, int32_t, const plg::vec2&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataVector2D __s2sdk_SetEntDataVector2D;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the vector at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @param value (vec2): The vector value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataVector2D(int32_t entityHandle, int32_t offset, const plg::vec2& value, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataVector2D(entityHandle, offset, value, changeState, chainOffset);
  }

  using _GetEntDataEnt = int32_t (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataEnt __s2sdk_GetEntDataEnt;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and retrieves the entity handle at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @return int32: The entity handle at the given memory location.
   */
  inline int32_t GetEntDataEnt(int32_t entityHandle, int32_t offset) {
    return __s2sdk_GetEntDataEnt(entityHandle, offset);
  }

  using _SetEntDataEnt = void (*)(int32_t, int32_t, int32_t, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntDataEnt __s2sdk_SetEntDataEnt;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and sets the entity handle at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @param value (int32): The entity handle to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void SetEntDataEnt(int32_t entityHandle, int32_t offset, int32_t value, bool changeState, int32_t chainOffset) {
    return __s2sdk_SetEntDataEnt(entityHandle, offset, value, changeState, chainOffset);
  }

  using _GetEntDataPtr = void* (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntDataPtr __s2sdk_GetEntDataPtr;
namespace s2sdk {
  /**
   * @brief Peeks into an entity's object data and retrieves a pointer to the data at the given offset.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @return ptr64: A pointer to the data at the given memory location.
   */
  inline void* GetEntDataPtr(int32_t entityHandle, int32_t offset) {
    return __s2sdk_GetEntDataPtr(entityHandle, offset);
  }

  using _ChangeEntityState = void (*)(int32_t, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_ChangeEntityState __s2sdk_ChangeEntityState;
namespace s2sdk {
  /**
   * @brief Updates the networked state of a schema field for a given entity handle.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param offset (int32): The offset of the schema to use.
   * @param chainOffset (int32): The offset of the chain entity in the class (-2 for non-entity classes).
   */
  inline void ChangeEntityState(int32_t entityHandle, int32_t offset, int32_t chainOffset) {
    return __s2sdk_ChangeEntityState(entityHandle, offset, chainOffset);
  }

  using _GetEntSchemaArraySize2 = int32_t (*)(void*, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaArraySize2 __s2sdk_GetEntSchemaArraySize2;
namespace s2sdk {
  /**
   * @brief Retrieves the count of values that an entity schema's array can store.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @return int32: Size of array (in elements) or 0 if schema is not an array.
   */
  inline int32_t GetEntSchemaArraySize2(void* entity, const plg::string& className, const plg::string& memberName) {
    return __s2sdk_GetEntSchemaArraySize2(entity, className, memberName);
  }

  using _GetEntSchemaPtr2 = void* (*)(void*, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaPtr2 __s2sdk_GetEntSchemaPtr2;
namespace s2sdk {
  /**
   * @brief Retrieves a pointer to a structure or an array element in an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return ptr64: A pointer to the field or element, or nullptr if the field is not found or element is out of range.
   */
  inline void* GetEntSchemaPtr2(void* entity, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaPtr2(entity, className, memberName, element);
  }

  using _GetEntSchema2 = int64_t (*)(void*, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchema2 __s2sdk_GetEntSchema2;
namespace s2sdk {
  /**
   * @brief Retrieves an integer value from an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return int64: An integer value at the given schema offset.
   */
  inline int64_t GetEntSchema2(void* entity, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchema2(entity, className, memberName, element);
  }

  using _SetEntSchema2 = void (*)(void*, const plg::string&, const plg::string&, int64_t, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchema2 __s2sdk_SetEntSchema2;
namespace s2sdk {
  /**
   * @brief Sets an integer value in an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (int64): The integer value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchema2(void* entity, const plg::string& className, const plg::string& memberName, int64_t value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchema2(entity, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaFloat2 = double (*)(void*, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaFloat2 __s2sdk_GetEntSchemaFloat2;
namespace s2sdk {
  /**
   * @brief Retrieves a float value from an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return double: A float value at the given schema offset.
   */
  inline double GetEntSchemaFloat2(void* entity, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaFloat2(entity, className, memberName, element);
  }

  using _SetEntSchemaFloat2 = void (*)(void*, const plg::string&, const plg::string&, double, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaFloat2 __s2sdk_SetEntSchemaFloat2;
namespace s2sdk {
  /**
   * @brief Sets a float value in an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (double): The float value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaFloat2(void* entity, const plg::string& className, const plg::string& memberName, double value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaFloat2(entity, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaColor2 = plg::vec4 (*)(void*, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaColor2 __s2sdk_GetEntSchemaColor2;
namespace s2sdk {
  /**
   * @brief Retrieves a color value from an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return vec4: A color value at the given schema offset.
   */
  inline plg::vec4 GetEntSchemaColor2(void* entity, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaColor2(entity, className, memberName, element);
  }

  using _SetEntSchemaColor2 = void (*)(void*, const plg::string&, const plg::string&, const plg::vec4&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaColor2 __s2sdk_SetEntSchemaColor2;
namespace s2sdk {
  /**
   * @brief Sets a color value in an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (vec4): The color value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaColor2(void* entity, const plg::string& className, const plg::string& memberName, const plg::vec4& value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaColor2(entity, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaString2 = plg::string (*)(void*, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaString2 __s2sdk_GetEntSchemaString2;
namespace s2sdk {
  /**
   * @brief Retrieves a string value from an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return string: A string value at the given schema offset.
   */
  inline plg::string GetEntSchemaString2(void* entity, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaString2(entity, className, memberName, element);
  }

  using _SetEntSchemaString2 = void (*)(void*, const plg::string&, const plg::string&, const plg::string&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaString2 __s2sdk_SetEntSchemaString2;
namespace s2sdk {
  /**
   * @brief Sets a string value in an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (string): The string value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaString2(void* entity, const plg::string& className, const plg::string& memberName, const plg::string& value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaString2(entity, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaVector3D2 = plg::vec3 (*)(void*, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaVector3D2 __s2sdk_GetEntSchemaVector3D2;
namespace s2sdk {
  /**
   * @brief Retrieves a vector value from an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return vec3: A vector value at the given schema offset.
   */
  inline plg::vec3 GetEntSchemaVector3D2(void* entity, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaVector3D2(entity, className, memberName, element);
  }

  using _SetEntSchemaVector3D2 = void (*)(void*, const plg::string&, const plg::string&, const plg::vec3&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaVector3D2 __s2sdk_SetEntSchemaVector3D2;
namespace s2sdk {
  /**
   * @brief Sets a vector value in an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (vec3): The vector value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaVector3D2(void* entity, const plg::string& className, const plg::string& memberName, const plg::vec3& value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaVector3D2(entity, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaVector2D2 = plg::vec2 (*)(void*, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaVector2D2 __s2sdk_GetEntSchemaVector2D2;
namespace s2sdk {
  /**
   * @brief Retrieves a vector value from an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return vec2: A vector value at the given schema offset.
   */
  inline plg::vec2 GetEntSchemaVector2D2(void* entity, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaVector2D2(entity, className, memberName, element);
  }

  using _SetEntSchemaVector2D2 = void (*)(void*, const plg::string&, const plg::string&, const plg::vec2&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaVector2D2 __s2sdk_SetEntSchemaVector2D2;
namespace s2sdk {
  /**
   * @brief Sets a vector value in an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (vec2): The vector value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaVector2D2(void* entity, const plg::string& className, const plg::string& memberName, const plg::vec2& value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaVector2D2(entity, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaVector4D2 = plg::vec4 (*)(void*, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaVector4D2 __s2sdk_GetEntSchemaVector4D2;
namespace s2sdk {
  /**
   * @brief Retrieves a vector value from an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return vec4: A vector value at the given schema offset.
   */
  inline plg::vec4 GetEntSchemaVector4D2(void* entity, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaVector4D2(entity, className, memberName, element);
  }

  using _SetEntSchemaVector4D2 = void (*)(void*, const plg::string&, const plg::string&, const plg::vec4&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaVector4D2 __s2sdk_SetEntSchemaVector4D2;
namespace s2sdk {
  /**
   * @brief Sets a vector value in an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (vec4): The vector value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaVector4D2(void* entity, const plg::string& className, const plg::string& memberName, const plg::vec4& value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaVector4D2(entity, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaEnt2 = int32_t (*)(void*, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaEnt2 __s2sdk_GetEntSchemaEnt2;
namespace s2sdk {
  /**
   * @brief Retrieves an entity handle from an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return int32: A string value at the given schema offset.
   */
  inline int32_t GetEntSchemaEnt2(void* entity, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaEnt2(entity, className, memberName, element);
  }

  using _SetEntSchemaEnt2 = void (*)(void*, const plg::string&, const plg::string&, int32_t, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaEnt2 __s2sdk_SetEntSchemaEnt2;
namespace s2sdk {
  /**
   * @brief Sets an entity handle in an entity's schema.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (int32): The entity handle to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaEnt2(void* entity, const plg::string& className, const plg::string& memberName, int32_t value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaEnt2(entity, className, memberName, value, changeState, element);
  }

  using _PushEntSchemaEnt2 = void (*)(void*, const plg::string&, const plg::string&, int32_t, bool);
}
extern "C" PLUGIN_API s2sdk::_PushEntSchemaEnt2 __s2sdk_PushEntSchemaEnt2;
namespace s2sdk {
  /**
   * @brief Pushes an entity handle into an entity's schema collection.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be pushed.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (int32): The entity handle to push.
   * @param changeState (bool): If true, change will be sent over the network.
   */
  inline void PushEntSchemaEnt2(void* entity, const plg::string& className, const plg::string& memberName, int32_t value, bool changeState) {
    return __s2sdk_PushEntSchemaEnt2(entity, className, memberName, value, changeState);
  }

  using _EraseEntSchemaEnt2 = void (*)(void*, const plg::string&, const plg::string&, int32_t, bool);
}
extern "C" PLUGIN_API s2sdk::_EraseEntSchemaEnt2 __s2sdk_EraseEntSchemaEnt2;
namespace s2sdk {
  /**
   * @brief Erases an entity handle from an entity's schema collection by index.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be erased.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element index to erase (starting from 0).
   * @param changeState (bool): If true, change will be sent over the network.
   */
  inline void EraseEntSchemaEnt2(void* entity, const plg::string& className, const plg::string& memberName, int32_t element, bool changeState) {
    return __s2sdk_EraseEntSchemaEnt2(entity, className, memberName, element, changeState);
  }

  using _NetworkStateChanged2 = void (*)(void*, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_NetworkStateChanged2 __s2sdk_NetworkStateChanged2;
namespace s2sdk {
  /**
   * @brief Updates the networked state of a schema field for a given entity pointer.
   * @param entity (ptr64): Pointer to the instance of the class where the value is to be set.
   * @param className (string): The name of the class that contains the member.
   * @param memberName (string): The name of the member to be set.
   */
  inline void NetworkStateChanged2(void* entity, const plg::string& className, const plg::string& memberName) {
    return __s2sdk_NetworkStateChanged2(entity, className, memberName);
  }

  using _GetEntSchemaArraySize = int32_t (*)(int32_t, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaArraySize __s2sdk_GetEntSchemaArraySize;
namespace s2sdk {
  /**
   * @brief Retrieves the count of values that an entity schema's array can store.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @return int32: Size of array (in elements) or 0 if schema is not an array.
   */
  inline int32_t GetEntSchemaArraySize(int32_t entityHandle, const plg::string& className, const plg::string& memberName) {
    return __s2sdk_GetEntSchemaArraySize(entityHandle, className, memberName);
  }

  using _GetEntSchemaPtr = void* (*)(int32_t, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaPtr __s2sdk_GetEntSchemaPtr;
namespace s2sdk {
  /**
   * @brief Retrieves a pointer to a structure or an array element in an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return ptr64: A pointer to the field or element, or nullptr if the field is not found or element is out of range.
   */
  inline void* GetEntSchemaPtr(int32_t entityHandle, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaPtr(entityHandle, className, memberName, element);
  }

  using _GetEntSchema = int64_t (*)(int32_t, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchema __s2sdk_GetEntSchema;
namespace s2sdk {
  /**
   * @brief Retrieves an integer value from an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return int64: An integer value at the given schema offset.
   */
  inline int64_t GetEntSchema(int32_t entityHandle, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchema(entityHandle, className, memberName, element);
  }

  using _SetEntSchema = void (*)(int32_t, const plg::string&, const plg::string&, int64_t, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchema __s2sdk_SetEntSchema;
namespace s2sdk {
  /**
   * @brief Sets an integer value in an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (int64): The integer value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchema(int32_t entityHandle, const plg::string& className, const plg::string& memberName, int64_t value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchema(entityHandle, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaFloat = double (*)(int32_t, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaFloat __s2sdk_GetEntSchemaFloat;
namespace s2sdk {
  /**
   * @brief Retrieves a float value from an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return double: A float value at the given schema offset.
   */
  inline double GetEntSchemaFloat(int32_t entityHandle, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaFloat(entityHandle, className, memberName, element);
  }

  using _SetEntSchemaFloat = void (*)(int32_t, const plg::string&, const plg::string&, double, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaFloat __s2sdk_SetEntSchemaFloat;
namespace s2sdk {
  /**
   * @brief Sets a float value in an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (double): The float value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaFloat(int32_t entityHandle, const plg::string& className, const plg::string& memberName, double value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaFloat(entityHandle, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaColor = plg::vec4 (*)(int32_t, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaColor __s2sdk_GetEntSchemaColor;
namespace s2sdk {
  /**
   * @brief Retrieves a color value from an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return vec4: A color value at the given schema offset.
   */
  inline plg::vec4 GetEntSchemaColor(int32_t entityHandle, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaColor(entityHandle, className, memberName, element);
  }

  using _SetEntSchemaColor = void (*)(int32_t, const plg::string&, const plg::string&, const plg::vec4&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaColor __s2sdk_SetEntSchemaColor;
namespace s2sdk {
  /**
   * @brief Sets a color value in an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (vec4): The color value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaColor(int32_t entityHandle, const plg::string& className, const plg::string& memberName, const plg::vec4& value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaColor(entityHandle, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaString = plg::string (*)(int32_t, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaString __s2sdk_GetEntSchemaString;
namespace s2sdk {
  /**
   * @brief Retrieves a string value from an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return string: A string value at the given schema offset.
   */
  inline plg::string GetEntSchemaString(int32_t entityHandle, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaString(entityHandle, className, memberName, element);
  }

  using _SetEntSchemaString = void (*)(int32_t, const plg::string&, const plg::string&, const plg::string&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaString __s2sdk_SetEntSchemaString;
namespace s2sdk {
  /**
   * @brief Sets a string value in an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (string): The string value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaString(int32_t entityHandle, const plg::string& className, const plg::string& memberName, const plg::string& value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaString(entityHandle, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaVector3D = plg::vec3 (*)(int32_t, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaVector3D __s2sdk_GetEntSchemaVector3D;
namespace s2sdk {
  /**
   * @brief Retrieves a vector value from an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return vec3: A string value at the given schema offset.
   */
  inline plg::vec3 GetEntSchemaVector3D(int32_t entityHandle, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaVector3D(entityHandle, className, memberName, element);
  }

  using _SetEntSchemaVector3D = void (*)(int32_t, const plg::string&, const plg::string&, const plg::vec3&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaVector3D __s2sdk_SetEntSchemaVector3D;
namespace s2sdk {
  /**
   * @brief Sets a vector value in an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (vec3): The vector value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaVector3D(int32_t entityHandle, const plg::string& className, const plg::string& memberName, const plg::vec3& value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaVector3D(entityHandle, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaVector2D = plg::vec2 (*)(int32_t, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaVector2D __s2sdk_GetEntSchemaVector2D;
namespace s2sdk {
  /**
   * @brief Retrieves a vector value from an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return vec2: A string value at the given schema offset.
   */
  inline plg::vec2 GetEntSchemaVector2D(int32_t entityHandle, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaVector2D(entityHandle, className, memberName, element);
  }

  using _SetEntSchemaVector2D = void (*)(int32_t, const plg::string&, const plg::string&, const plg::vec2&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaVector2D __s2sdk_SetEntSchemaVector2D;
namespace s2sdk {
  /**
   * @brief Sets a vector value in an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (vec2): The vector value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaVector2D(int32_t entityHandle, const plg::string& className, const plg::string& memberName, const plg::vec2& value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaVector2D(entityHandle, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaVector4D = plg::vec4 (*)(int32_t, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaVector4D __s2sdk_GetEntSchemaVector4D;
namespace s2sdk {
  /**
   * @brief Retrieves a vector value from an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return vec4: A string value at the given schema offset.
   */
  inline plg::vec4 GetEntSchemaVector4D(int32_t entityHandle, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaVector4D(entityHandle, className, memberName, element);
  }

  using _SetEntSchemaVector4D = void (*)(int32_t, const plg::string&, const plg::string&, const plg::vec4&, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaVector4D __s2sdk_SetEntSchemaVector4D;
namespace s2sdk {
  /**
   * @brief Sets a vector value in an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (vec4): The vector value to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaVector4D(int32_t entityHandle, const plg::string& className, const plg::string& memberName, const plg::vec4& value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaVector4D(entityHandle, className, memberName, value, changeState, element);
  }

  using _GetEntSchemaEnt = int32_t (*)(int32_t, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntSchemaEnt __s2sdk_GetEntSchemaEnt;
namespace s2sdk {
  /**
   * @brief Retrieves an entity handle from an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   * @return int32: A string value at the given schema offset.
   */
  inline int32_t GetEntSchemaEnt(int32_t entityHandle, const plg::string& className, const plg::string& memberName, int32_t element) {
    return __s2sdk_GetEntSchemaEnt(entityHandle, className, memberName, element);
  }

  using _SetEntSchemaEnt = void (*)(int32_t, const plg::string&, const plg::string&, int32_t, bool, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntSchemaEnt __s2sdk_SetEntSchemaEnt;
namespace s2sdk {
  /**
   * @brief Sets an entity handle in an entity's schema.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (int32): The entity handle to set.
   * @param changeState (bool): If true, change will be sent over the network.
   * @param element (int32): Element # (starting from 0) if schema is an array.
   */
  inline void SetEntSchemaEnt(int32_t entityHandle, const plg::string& className, const plg::string& memberName, int32_t value, bool changeState, int32_t element) {
    return __s2sdk_SetEntSchemaEnt(entityHandle, className, memberName, value, changeState, element);
  }

  using _PushEntSchemaEnt = void (*)(int32_t, const plg::string&, const plg::string&, int32_t, bool);
}
extern "C" PLUGIN_API s2sdk::_PushEntSchemaEnt __s2sdk_PushEntSchemaEnt;
namespace s2sdk {
  /**
   * @brief Pushes an entity handle into an entity's schema collection.
   * @param entityHandle (int32): The handle of the entity whose schema collection is modified.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param value (int32): The entity handle to push.
   * @param changeState (bool): If true, change will be sent over the network.
   */
  inline void PushEntSchemaEnt(int32_t entityHandle, const plg::string& className, const plg::string& memberName, int32_t value, bool changeState) {
    return __s2sdk_PushEntSchemaEnt(entityHandle, className, memberName, value, changeState);
  }

  using _EraseEntSchemaEnt = void (*)(int32_t, const plg::string&, const plg::string&, int32_t, bool);
}
extern "C" PLUGIN_API s2sdk::_EraseEntSchemaEnt __s2sdk_EraseEntSchemaEnt;
namespace s2sdk {
  /**
   * @brief Erases an entity handle from an entity's schema collection by index.
   * @param entityHandle (int32): The handle of the entity whose schema collection is modified.
   * @param className (string): The name of the class.
   * @param memberName (string): The name of the schema member.
   * @param element (int32): Element index to erase (starting from 0).
   * @param changeState (bool): If true, change will be sent over the network.
   */
  inline void EraseEntSchemaEnt(int32_t entityHandle, const plg::string& className, const plg::string& memberName, int32_t element, bool changeState) {
    return __s2sdk_EraseEntSchemaEnt(entityHandle, className, memberName, element, changeState);
  }

  using _NetworkStateChanged = void (*)(int32_t, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_NetworkStateChanged __s2sdk_NetworkStateChanged;
namespace s2sdk {
  /**
   * @brief Updates the networked state of a schema field for a given entity handle.
   * @param entityHandle (int32): The handle of the entity from which the value is to be retrieved.
   * @param className (string): The name of the class that contains the member.
   * @param memberName (string): The name of the member to be set.
   */
  inline void NetworkStateChanged(int32_t entityHandle, const plg::string& className, const plg::string& memberName) {
    return __s2sdk_NetworkStateChanged(entityHandle, className, memberName);
  }

} // namespace s2sdk
