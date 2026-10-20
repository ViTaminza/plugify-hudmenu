#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: entities)

namespace s2sdk {

  using _GetPublicAddress = plg::string (*)(bool);
}
extern "C" PLUGIN_API s2sdk::_GetPublicAddress __s2sdk_GetPublicAddress;
namespace s2sdk {
  /**
   * @brief Returns the public network address of the host.
   * @param onlyBase (bool): If true, omits port, otherwise returning only the base address.
   * @return string: A string representation of the public address.
   */
  inline plg::string GetPublicAddress(bool onlyBase) {
    return __s2sdk_GetPublicAddress(onlyBase);
  }

  using _GetLocalAddress = plg::string (*)(bool);
}
extern "C" PLUGIN_API s2sdk::_GetLocalAddress __s2sdk_GetLocalAddress;
namespace s2sdk {
  /**
   * @brief Returns the local network address of the host.
   * @param onlyBase (bool): If true, omits port, otherwise returning only the base address.
   * @return string: A string representation of the local address.
   */
  inline plg::string GetLocalAddress(bool onlyBase) {
    return __s2sdk_GetLocalAddress(onlyBase);
  }

  using _EntIndexToEntPointer = void* (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_EntIndexToEntPointer __s2sdk_EntIndexToEntPointer;
namespace s2sdk {
  /**
   * @brief Converts an entity index into an entity pointer.
   * @param entityIndex (int32): The index of the entity to convert.
   * @return ptr64: A pointer to the entity instance, or nullptr if the entity does not exist.
   */
  inline void* EntIndexToEntPointer(int32_t entityIndex) {
    return __s2sdk_EntIndexToEntPointer(entityIndex);
  }

  using _EntPointerToEntIndex = int32_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_EntPointerToEntIndex __s2sdk_EntPointerToEntIndex;
namespace s2sdk {
  /**
   * @brief Retrieves the entity index from an entity pointer.
   * @param entity (ptr64): A pointer to the entity whose index is to be retrieved.
   * @return int32: The index of the entity, or -1 if the entity is nullptr.
   */
  inline int32_t EntPointerToEntIndex(void* entity) {
    return __s2sdk_EntPointerToEntIndex(entity);
  }

  using _EntPointerToEntHandle = int32_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_EntPointerToEntHandle __s2sdk_EntPointerToEntHandle;
namespace s2sdk {
  /**
   * @brief Converts an entity pointer into an entity handle.
   * @param entity (ptr64): A pointer to the entity to convert.
   * @return int32: The entity handle as an integer, or INVALID_EHANDLE_INDEX if the entity is nullptr.
   */
  inline int32_t EntPointerToEntHandle(void* entity) {
    return __s2sdk_EntPointerToEntHandle(entity);
  }

  using _EntHandleToEntPointer = void* (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_EntHandleToEntPointer __s2sdk_EntHandleToEntPointer;
namespace s2sdk {
  /**
   * @brief Retrieves the entity pointer from an entity handle.
   * @param entityHandle (int32): The entity handle to convert.
   * @return ptr64: A pointer to the entity instance, or nullptr if the handle is invalid.
   */
  inline void* EntHandleToEntPointer(int32_t entityHandle) {
    return __s2sdk_EntHandleToEntPointer(entityHandle);
  }

  using _EntIndexToEntHandle = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_EntIndexToEntHandle __s2sdk_EntIndexToEntHandle;
namespace s2sdk {
  /**
   * @brief Converts an entity index into an entity handle.
   * @param entityIndex (int32): The index of the entity to convert.
   * @return int32: The entity handle as an integer, or -1 if the entity index is invalid.
   */
  inline int32_t EntIndexToEntHandle(int32_t entityIndex) {
    return __s2sdk_EntIndexToEntHandle(entityIndex);
  }

  using _EntHandleToEntIndex = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_EntHandleToEntIndex __s2sdk_EntHandleToEntIndex;
namespace s2sdk {
  /**
   * @brief Retrieves the entity index from an entity handle.
   * @param entityHandle (int32): The entity handle from which to retrieve the index.
   * @return int32: The index of the entity, or -1 if the handle is invalid.
   */
  inline int32_t EntHandleToEntIndex(int32_t entityHandle) {
    return __s2sdk_EntHandleToEntIndex(entityHandle);
  }

  using _IsValidEntHandle = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsValidEntHandle __s2sdk_IsValidEntHandle;
namespace s2sdk {
  /**
   * @brief Checks if the provided entity handle is valid.
   * @param entityHandle (int32): The entity handle to check.
   * @return bool: True if the entity handle is valid, false otherwise.
   */
  inline bool IsValidEntHandle(int32_t entityHandle) {
    return __s2sdk_IsValidEntHandle(entityHandle);
  }

  using _IsValidEntPointer = bool (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_IsValidEntPointer __s2sdk_IsValidEntPointer;
namespace s2sdk {
  /**
   * @brief Checks if the provided entity pointer is valid.
   * @param entity (ptr64): The entity pointer to check.
   * @return bool: True if the entity pointer is valid, false otherwise.
   */
  inline bool IsValidEntPointer(void* entity) {
    return __s2sdk_IsValidEntPointer(entity);
  }

  using _GetFirstActiveEntity = int32_t (*)();
}
extern "C" PLUGIN_API s2sdk::_GetFirstActiveEntity __s2sdk_GetFirstActiveEntity;
namespace s2sdk {
  /**
   * @brief Retrieves the pointer to the first active entity.
   * @return int32: A handle to the first active entity.
   */
  inline int32_t GetFirstActiveEntity() {
    return __s2sdk_GetFirstActiveEntity();
  }

  using _GetPrevActiveEntity = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetPrevActiveEntity __s2sdk_GetPrevActiveEntity;
namespace s2sdk {
  /**
   * @brief Retrieves the previous active entity.
   * @param entityHandle (int32)
   * @return int32: Handle to the previous entity.
   */
  inline int32_t GetPrevActiveEntity(int32_t entityHandle) {
    return __s2sdk_GetPrevActiveEntity(entityHandle);
  }

  using _GetNextActiveEntity = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetNextActiveEntity __s2sdk_GetNextActiveEntity;
namespace s2sdk {
  /**
   * @brief Retrieves the next active entity.
   * @param entityHandle (int32)
   * @return int32: Handle to the next entity.
   */
  inline int32_t GetNextActiveEntity(int32_t entityHandle) {
    return __s2sdk_GetNextActiveEntity(entityHandle);
  }

  using _GetPointScriptHandle = int32_t (*)();
}
extern "C" PLUGIN_API s2sdk::_GetPointScriptHandle __s2sdk_GetPointScriptHandle;
namespace s2sdk {
  /**
   * @brief Retrieves the handle of the point_script entity created by s2sdk.
   * @return int32: The entity handle as an integer, or INVALID_EHANDLE_INDEX if the entity does not exist.
   */
  inline int32_t GetPointScriptHandle() {
    return __s2sdk_GetPointScriptHandle();
  }

  using _HookEntityOutput = bool (*)(const plg::string&, const plg::string&, HookEntityOutputCallback, HookMode);
}
extern "C" PLUGIN_API s2sdk::_HookEntityOutput __s2sdk_HookEntityOutput;
namespace s2sdk {
  /**
   * @brief Adds an entity output hook on a specified entity class name.
   * @param classname (string): The class name of the entity to hook the output for.
   * @param output (string): The output event name to hook.
   * @param callback (function): The callback function to invoke when the output is fired.
   * @param type (uint8): Whether the hook was in post mode (after processing) or pre mode (before processing).
   * @return bool: True if the hook was successfully added, false otherwise.
   */
  inline bool HookEntityOutput(const plg::string& classname, const plg::string& output, HookEntityOutputCallback callback, HookMode type) {
    return __s2sdk_HookEntityOutput(classname, output, callback, type);
  }

  using _UnhookEntityOutput = bool (*)(const plg::string&, const plg::string&, HookEntityOutputCallback, HookMode);
}
extern "C" PLUGIN_API s2sdk::_UnhookEntityOutput __s2sdk_UnhookEntityOutput;
namespace s2sdk {
  /**
   * @brief Removes an entity output hook.
   * @param classname (string): The class name of the entity from which to unhook the output.
   * @param output (string): The output event name to unhook.
   * @param callback (function): The callback function that was previously hooked.
   * @param type (uint8): Whether the hook was in post mode (after processing) or pre mode (before processing).
   * @return bool: True if the hook was successfully removed, false otherwise.
   */
  inline bool UnhookEntityOutput(const plg::string& classname, const plg::string& output, HookEntityOutputCallback callback, HookMode type) {
    return __s2sdk_UnhookEntityOutput(classname, output, callback, type);
  }

  using _FindEntityByClassname = int32_t (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_FindEntityByClassname __s2sdk_FindEntityByClassname;
namespace s2sdk {
  /**
   * @brief Finds an entity by classname with iteration.
   * @param startFrom (int32): The handle of the entity to start from, or INVALID_EHANDLE_INDEX to start fresh.
   * @param classname (string): The class name to search for.
   * @return int32: The handle of the found entity, or INVALID_EHANDLE_INDEX if none found.
   */
  inline int32_t FindEntityByClassname(int32_t startFrom, const plg::string& classname) {
    return __s2sdk_FindEntityByClassname(startFrom, classname);
  }

  using _FindEntityByClassnameNearest = int32_t (*)(const plg::string&, const plg::vec3&, float);
}
extern "C" PLUGIN_API s2sdk::_FindEntityByClassnameNearest __s2sdk_FindEntityByClassnameNearest;
namespace s2sdk {
  /**
   * @brief Finds the nearest entity by classname to a point.
   * @param classname (string): The class name to search for.
   * @param origin (vec3): The center point to search around.
   * @param maxRadius (float): Maximum search radius.
   * @return int32: The handle of the found entity, or INVALID_EHANDLE_INDEX if none found.
   */
  inline int32_t FindEntityByClassnameNearest(const plg::string& classname, const plg::vec3& origin, float maxRadius) {
    return __s2sdk_FindEntityByClassnameNearest(classname, origin, maxRadius);
  }

  using _FindEntityByClassnameWithin = int32_t (*)(int32_t, const plg::string&, const plg::vec3&, float);
}
extern "C" PLUGIN_API s2sdk::_FindEntityByClassnameWithin __s2sdk_FindEntityByClassnameWithin;
namespace s2sdk {
  /**
   * @brief Finds an entity by classname within a radius with iteration.
   * @param startFrom (int32): The handle of the entity to start from, or INVALID_EHANDLE_INDEX to start fresh.
   * @param classname (string): The class name to search for.
   * @param origin (vec3): The center of the search sphere.
   * @param radius (float): The search radius.
   * @return int32: The handle of the found entity, or INVALID_EHANDLE_INDEX if none found.
   */
  inline int32_t FindEntityByClassnameWithin(int32_t startFrom, const plg::string& classname, const plg::vec3& origin, float radius) {
    return __s2sdk_FindEntityByClassnameWithin(startFrom, classname, origin, radius);
  }

  using _FindEntityByName = int32_t (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_FindEntityByName __s2sdk_FindEntityByName;
namespace s2sdk {
  /**
   * @brief Finds an entity by name with iteration.
   * @param startFrom (int32): The handle of the entity to start from, or INVALID_EHANDLE_INDEX to start fresh.
   * @param name (string): The targetname to search for.
   * @return int32: The handle of the found entity, or INVALID_EHANDLE_INDEX if none found.
   */
  inline int32_t FindEntityByName(int32_t startFrom, const plg::string& name) {
    return __s2sdk_FindEntityByName(startFrom, name);
  }

  using _FindEntityByNameNearest = int32_t (*)(const plg::string&, const plg::vec3&, float);
}
extern "C" PLUGIN_API s2sdk::_FindEntityByNameNearest __s2sdk_FindEntityByNameNearest;
namespace s2sdk {
  /**
   * @brief Finds the nearest entity by name to a point.
   * @param name (string): The targetname to search for.
   * @param origin (vec3): The point to search around.
   * @param maxRadius (float): Maximum search radius.
   * @return int32: The handle of the nearest entity, or INVALID_EHANDLE_INDEX if none found.
   */
  inline int32_t FindEntityByNameNearest(const plg::string& name, const plg::vec3& origin, float maxRadius) {
    return __s2sdk_FindEntityByNameNearest(name, origin, maxRadius);
  }

  using _FindEntityByNameWithin = int32_t (*)(int32_t, const plg::string&, const plg::vec3&, float);
}
extern "C" PLUGIN_API s2sdk::_FindEntityByNameWithin __s2sdk_FindEntityByNameWithin;
namespace s2sdk {
  /**
   * @brief Finds an entity by name within a radius with iteration.
   * @param startFrom (int32): The handle of the entity to start from, or INVALID_EHANDLE_INDEX to start fresh.
   * @param name (string): The targetname to search for.
   * @param origin (vec3): The center of the search sphere.
   * @param radius (float): The search radius.
   * @return int32: The handle of the found entity, or INVALID_EHANDLE_INDEX if none found.
   */
  inline int32_t FindEntityByNameWithin(int32_t startFrom, const plg::string& name, const plg::vec3& origin, float radius) {
    return __s2sdk_FindEntityByNameWithin(startFrom, name, origin, radius);
  }

  using _FindEntityByTarget = int32_t (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_FindEntityByTarget __s2sdk_FindEntityByTarget;
namespace s2sdk {
  /**
   * @brief Finds an entity by targetname with iteration.
   * @param startFrom (int32): The handle of the entity to start from, or INVALID_EHANDLE_INDEX to start fresh.
   * @param name (string): The targetname to search for.
   * @return int32: The handle of the found entity, or INVALID_EHANDLE_INDEX if none found.
   */
  inline int32_t FindEntityByTarget(int32_t startFrom, const plg::string& name) {
    return __s2sdk_FindEntityByTarget(startFrom, name);
  }

  using _FindEntityInSphere = int32_t (*)(int32_t, const plg::vec3&, float);
}
extern "C" PLUGIN_API s2sdk::_FindEntityInSphere __s2sdk_FindEntityInSphere;
namespace s2sdk {
  /**
   * @brief Finds an entity within a sphere with iteration.
   * @param startFrom (int32): The handle of the entity to start from, or INVALID_EHANDLE_INDEX to start fresh.
   * @param origin (vec3): The center of the search sphere.
   * @param radius (float): The search radius.
   * @return int32: The handle of the found entity, or INVALID_EHANDLE_INDEX if none found.
   */
  inline int32_t FindEntityInSphere(int32_t startFrom, const plg::vec3& origin, float radius) {
    return __s2sdk_FindEntityInSphere(startFrom, origin, radius);
  }

  using _SpawnEntityByName = int32_t (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SpawnEntityByName __s2sdk_SpawnEntityByName;
namespace s2sdk {
  /**
   * @brief Creates an entity by classname.
   * @param className (string): The class name of the entity to create.
   * @return int32: The handle of the created entity, or INVALID_EHANDLE_INDEX if creation failed.
   */
  inline int32_t SpawnEntityByName(const plg::string& className) {
    return __s2sdk_SpawnEntityByName(className);
  }

  using _CreateEntityByName = int32_t (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_CreateEntityByName __s2sdk_CreateEntityByName;
namespace s2sdk {
  /**
   * @brief Creates an entity by string name but does not spawn it.
   * @param className (string): The class name of the entity to create.
   * @return int32: The entity handle of the created entity, or INVALID_EHANDLE_INDEX if the entity could not be created.
   */
  inline int32_t CreateEntityByName(const plg::string& className) {
    return __s2sdk_CreateEntityByName(className);
  }

  using _DispatchSpawn = void (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_DispatchSpawn __s2sdk_DispatchSpawn;
namespace s2sdk {
  /**
   * @brief Spawns an entity into the game.
   * @param entityHandle (int32): The handle of the entity to spawn.
   */
  inline void DispatchSpawn(int32_t entityHandle) {
    return __s2sdk_DispatchSpawn(entityHandle);
  }

  using _DispatchSpawn2 = void (*)(int32_t, const plg::vector<plg::string>&, const plg::vector<plg::any>&);
}
extern "C" PLUGIN_API s2sdk::_DispatchSpawn2 __s2sdk_DispatchSpawn2;
namespace s2sdk {
  /**
   * @brief Spawns an entity into the game with key-value properties.
   * @param entityHandle (int32): The handle of the entity to spawn.
   * @param keys (string[]): A vector of keys representing the property names to set on the entity.
   * @param values (any[]): A vector of values corresponding to the keys, representing the property values to set on the entity.
   */
  inline void DispatchSpawn2(int32_t entityHandle, const plg::vector<plg::string>& keys, const plg::vector<plg::any>& values) {
    return __s2sdk_DispatchSpawn2(entityHandle, keys, values);
  }

  using _RemoveEntity = void (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_RemoveEntity __s2sdk_RemoveEntity;
namespace s2sdk {
  /**
   * @brief Marks an entity for deletion.
   * @param entityHandle (int32): The handle of the entity to be deleted.
   */
  inline void RemoveEntity(int32_t entityHandle) {
    return __s2sdk_RemoveEntity(entityHandle);
  }

  using _IsEntityPlayerController = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsEntityPlayerController __s2sdk_IsEntityPlayerController;
namespace s2sdk {
  /**
   * @brief Checks if an entity is a player controller.
   * @param entityHandle (int32): The handle of the entity.
   * @return bool: True if the entity is a player controller, false otherwise.
   */
  inline bool IsEntityPlayerController(int32_t entityHandle) {
    return __s2sdk_IsEntityPlayerController(entityHandle);
  }

  using _IsEntityPlayerPawn = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsEntityPlayerPawn __s2sdk_IsEntityPlayerPawn;
namespace s2sdk {
  /**
   * @brief Checks if an entity is a player pawn.
   * @param entityHandle (int32): The handle of the entity.
   * @return bool: True if the entity is a player pawn, false otherwise.
   */
  inline bool IsEntityPlayerPawn(int32_t entityHandle) {
    return __s2sdk_IsEntityPlayerPawn(entityHandle);
  }

  using _GetEntityClassname = plg::string (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityClassname __s2sdk_GetEntityClassname;
namespace s2sdk {
  /**
   * @brief Retrieves the class name of an entity.
   * @param entityHandle (int32): The handle of the entity whose class name is to be retrieved.
   * @return string: A string where the class name will be stored.
   */
  inline plg::string GetEntityClassname(int32_t entityHandle) {
    return __s2sdk_GetEntityClassname(entityHandle);
  }

  using _GetEntityName = plg::string (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityName __s2sdk_GetEntityName;
namespace s2sdk {
  /**
   * @brief Retrieves the name of an entity.
   * @param entityHandle (int32): The handle of the entity whose name is to be retrieved.
   * @return string
   */
  inline plg::string GetEntityName(int32_t entityHandle) {
    return __s2sdk_GetEntityName(entityHandle);
  }

  using _SetEntityName = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityName __s2sdk_SetEntityName;
namespace s2sdk {
  /**
   * @brief Sets the name of an entity.
   * @param entityHandle (int32): The handle of the entity whose name is to be set.
   * @param name (string): The new name to set for the entity.
   */
  inline void SetEntityName(int32_t entityHandle, const plg::string& name) {
    return __s2sdk_SetEntityName(entityHandle, name);
  }

  using _GetEntityMoveType = MoveType (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityMoveType __s2sdk_GetEntityMoveType;
namespace s2sdk {
  /**
   * @brief Retrieves the movement type of an entity.
   * @param entityHandle (int32): The handle of the entity whose movement type is to be retrieved.
   * @return int32: The movement type of the entity, or 0 if the entity is invalid.
   */
  inline MoveType GetEntityMoveType(int32_t entityHandle) {
    return __s2sdk_GetEntityMoveType(entityHandle);
  }

  using _SetEntityMoveType = void (*)(int32_t, MoveType);
}
extern "C" PLUGIN_API s2sdk::_SetEntityMoveType __s2sdk_SetEntityMoveType;
namespace s2sdk {
  /**
   * @brief Sets the movement type of an entity.
   * @param entityHandle (int32): The handle of the entity whose movement type is to be set.
   * @param moveType (int32): The new movement type to set for the entity.
   */
  inline void SetEntityMoveType(int32_t entityHandle, MoveType moveType) {
    return __s2sdk_SetEntityMoveType(entityHandle, moveType);
  }

  using _GetEntityGravity = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityGravity __s2sdk_GetEntityGravity;
namespace s2sdk {
  /**
   * @brief Retrieves the gravity scale of an entity.
   * @param entityHandle (int32): The handle of the entity whose gravity scale is to be retrieved.
   * @return float: The gravity scale of the entity, or 0.0f if the entity is invalid.
   */
  inline float GetEntityGravity(int32_t entityHandle) {
    return __s2sdk_GetEntityGravity(entityHandle);
  }

  using _SetEntityGravity = void (*)(int32_t, float);
}
extern "C" PLUGIN_API s2sdk::_SetEntityGravity __s2sdk_SetEntityGravity;
namespace s2sdk {
  /**
   * @brief Sets the gravity scale of an entity.
   * @param entityHandle (int32): The handle of the entity whose gravity scale is to be set.
   * @param gravity (float): The new gravity scale to set for the entity.
   */
  inline void SetEntityGravity(int32_t entityHandle, float gravity) {
    return __s2sdk_SetEntityGravity(entityHandle, gravity);
  }

  using _GetEntityFlags = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityFlags __s2sdk_GetEntityFlags;
namespace s2sdk {
  /**
   * @brief Retrieves the flags of an entity.
   * @param entityHandle (int32): The handle of the entity whose flags are to be retrieved.
   * @return int32: The flags of the entity, or 0 if the entity is invalid.
   */
  inline int32_t GetEntityFlags(int32_t entityHandle) {
    return __s2sdk_GetEntityFlags(entityHandle);
  }

  using _SetEntityFlags = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityFlags __s2sdk_SetEntityFlags;
namespace s2sdk {
  /**
   * @brief Sets the flags of an entity.
   * @param entityHandle (int32): The handle of the entity whose flags are to be set.
   * @param flags (int32): The new flags to set for the entity.
   */
  inline void SetEntityFlags(int32_t entityHandle, int32_t flags) {
    return __s2sdk_SetEntityFlags(entityHandle, flags);
  }

  using _GetEntityRenderColor = plg::vec4 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityRenderColor __s2sdk_GetEntityRenderColor;
namespace s2sdk {
  /**
   * @brief Retrieves the render color of an entity.
   * @param entityHandle (int32): The handle of the entity whose render color is to be retrieved.
   * @return vec4: The raw color value of the entity's render color, or 0 if the entity is invalid.
   */
  inline plg::vec4 GetEntityRenderColor(int32_t entityHandle) {
    return __s2sdk_GetEntityRenderColor(entityHandle);
  }

  using _SetEntityRenderColor = void (*)(int32_t, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityRenderColor __s2sdk_SetEntityRenderColor;
namespace s2sdk {
  /**
   * @brief Sets the render color of an entity.
   * @param entityHandle (int32): The handle of the entity whose render color is to be set.
   * @param color (vec4): The new raw color value to set for the entity's render color.
   */
  inline void SetEntityRenderColor(int32_t entityHandle, const plg::vec4& color) {
    return __s2sdk_SetEntityRenderColor(entityHandle, color);
  }

  using _GetEntityRenderMode = RenderMode (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityRenderMode __s2sdk_GetEntityRenderMode;
namespace s2sdk {
  /**
   * @brief Retrieves the render mode of an entity.
   * @param entityHandle (int32): The handle of the entity whose render mode is to be retrieved.
   * @return uint8: The render mode of the entity, or 0 if the entity is invalid.
   */
  inline RenderMode GetEntityRenderMode(int32_t entityHandle) {
    return __s2sdk_GetEntityRenderMode(entityHandle);
  }

  using _SetEntityRenderMode = void (*)(int32_t, RenderMode);
}
extern "C" PLUGIN_API s2sdk::_SetEntityRenderMode __s2sdk_SetEntityRenderMode;
namespace s2sdk {
  /**
   * @brief Sets the render mode of an entity.
   * @param entityHandle (int32): The handle of the entity whose render mode is to be set.
   * @param renderMode (uint8): The new render mode to set for the entity.
   */
  inline void SetEntityRenderMode(int32_t entityHandle, RenderMode renderMode) {
    return __s2sdk_SetEntityRenderMode(entityHandle, renderMode);
  }

  using _GetEntityMass = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityMass __s2sdk_GetEntityMass;
namespace s2sdk {
  /**
   * @brief Retrieves the mass of an entity.
   * @param entityHandle (int32): The handle of the entity whose mass is to be retrieved.
   * @return int32: The mass of the entity, or 0 if the entity is invalid.
   */
  inline int32_t GetEntityMass(int32_t entityHandle) {
    return __s2sdk_GetEntityMass(entityHandle);
  }

  using _SetEntityMass = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityMass __s2sdk_SetEntityMass;
namespace s2sdk {
  /**
   * @brief Sets the mass of an entity.
   * @param entityHandle (int32): The handle of the entity whose mass is to be set.
   * @param mass (int32): The new mass value to set for the entity.
   */
  inline void SetEntityMass(int32_t entityHandle, int32_t mass) {
    return __s2sdk_SetEntityMass(entityHandle, mass);
  }

  using _GetEntityFriction = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityFriction __s2sdk_GetEntityFriction;
namespace s2sdk {
  /**
   * @brief Retrieves the friction of an entity.
   * @param entityHandle (int32): The handle of the entity whose friction is to be retrieved.
   * @return float: The friction of the entity, or 0 if the entity is invalid.
   */
  inline float GetEntityFriction(int32_t entityHandle) {
    return __s2sdk_GetEntityFriction(entityHandle);
  }

  using _SetEntityFriction = void (*)(int32_t, float);
}
extern "C" PLUGIN_API s2sdk::_SetEntityFriction __s2sdk_SetEntityFriction;
namespace s2sdk {
  /**
   * @brief Sets the friction of an entity.
   * @param entityHandle (int32): The handle of the entity whose friction is to be set.
   * @param friction (float): The new friction value to set for the entity.
   */
  inline void SetEntityFriction(int32_t entityHandle, float friction) {
    return __s2sdk_SetEntityFriction(entityHandle, friction);
  }

  using _GetEntityHealth = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityHealth __s2sdk_GetEntityHealth;
namespace s2sdk {
  /**
   * @brief Retrieves the health of an entity.
   * @param entityHandle (int32): The handle of the entity whose health is to be retrieved.
   * @return int32: The health of the entity, or 0 if the entity is invalid.
   */
  inline int32_t GetEntityHealth(int32_t entityHandle) {
    return __s2sdk_GetEntityHealth(entityHandle);
  }

  using _SetEntityHealth = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityHealth __s2sdk_SetEntityHealth;
namespace s2sdk {
  /**
   * @brief Sets the health of an entity.
   * @param entityHandle (int32): The handle of the entity whose health is to be set.
   * @param health (int32): The new health value to set for the entity.
   */
  inline void SetEntityHealth(int32_t entityHandle, int32_t health) {
    return __s2sdk_SetEntityHealth(entityHandle, health);
  }

  using _GetEntityMaxHealth = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityMaxHealth __s2sdk_GetEntityMaxHealth;
namespace s2sdk {
  /**
   * @brief Retrieves the max health of an entity.
   * @param entityHandle (int32): The handle of the entity whose max health is to be retrieved.
   * @return int32: The max health of the entity, or 0 if the entity is invalid.
   */
  inline int32_t GetEntityMaxHealth(int32_t entityHandle) {
    return __s2sdk_GetEntityMaxHealth(entityHandle);
  }

  using _SetEntityMaxHealth = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityMaxHealth __s2sdk_SetEntityMaxHealth;
namespace s2sdk {
  /**
   * @brief Sets the max health of an entity.
   * @param entityHandle (int32): The handle of the entity whose max health is to be set.
   * @param maxHealth (int32): The new max health value to set for the entity.
   */
  inline void SetEntityMaxHealth(int32_t entityHandle, int32_t maxHealth) {
    return __s2sdk_SetEntityMaxHealth(entityHandle, maxHealth);
  }

  using _GetEntityTeam = CSTeam (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityTeam __s2sdk_GetEntityTeam;
namespace s2sdk {
  /**
   * @brief Retrieves the team number of an entity.
   * @param entityHandle (int32): The handle of the entity whose team number is to be retrieved.
   * @return int32: The team number of the entity, or 0 if the entity is invalid.
   */
  inline CSTeam GetEntityTeam(int32_t entityHandle) {
    return __s2sdk_GetEntityTeam(entityHandle);
  }

  using _SetEntityTeam = void (*)(int32_t, CSTeam);
}
extern "C" PLUGIN_API s2sdk::_SetEntityTeam __s2sdk_SetEntityTeam;
namespace s2sdk {
  /**
   * @brief Sets the team number of an entity.
   * @param entityHandle (int32): The handle of the entity whose team number is to be set.
   * @param team (int32): The new team number to set for the entity.
   */
  inline void SetEntityTeam(int32_t entityHandle, CSTeam team) {
    return __s2sdk_SetEntityTeam(entityHandle, team);
  }

  using _GetEntityOwner = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityOwner __s2sdk_GetEntityOwner;
namespace s2sdk {
  /**
   * @brief Retrieves the owner of an entity.
   * @param entityHandle (int32): The handle of the entity whose owner is to be retrieved.
   * @return int32: The handle of the owner entity, or INVALID_EHANDLE_INDEX if the entity is invalid.
   */
  inline int32_t GetEntityOwner(int32_t entityHandle) {
    return __s2sdk_GetEntityOwner(entityHandle);
  }

  using _SetEntityOwner = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityOwner __s2sdk_SetEntityOwner;
namespace s2sdk {
  /**
   * @brief Sets the owner of an entity.
   * @param entityHandle (int32): The handle of the entity whose owner is to be set.
   * @param ownerHandle (int32): The handle of the new owner entity.
   */
  inline void SetEntityOwner(int32_t entityHandle, int32_t ownerHandle) {
    return __s2sdk_SetEntityOwner(entityHandle, ownerHandle);
  }

  using _GetEntityParent = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityParent __s2sdk_GetEntityParent;
namespace s2sdk {
  /**
   * @brief Retrieves the parent of an entity.
   * @param entityHandle (int32): The handle of the entity whose parent is to be retrieved.
   * @return int32: The handle of the parent entity, or INVALID_EHANDLE_INDEX if the entity is invalid.
   */
  inline int32_t GetEntityParent(int32_t entityHandle) {
    return __s2sdk_GetEntityParent(entityHandle);
  }

  using _SetEntityParent = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityParent __s2sdk_SetEntityParent;
namespace s2sdk {
  /**
   * @brief Sets the parent of an entity.
   * @param entityHandle (int32): The handle of the entity whose parent is to be set.
   * @param parentHandle (int32): The handle of the new parent entity. (Can be invalid to clean parent)
   */
  inline void SetEntityParent(int32_t entityHandle, int32_t parentHandle) {
    return __s2sdk_SetEntityParent(entityHandle, parentHandle);
  }

  using _SetEntityParentAttachment = void (*)(int32_t, int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityParentAttachment __s2sdk_SetEntityParentAttachment;
namespace s2sdk {
  /**
   * @brief Sets the parent of an entity to attachment by name.
   * @param entityHandle (int32): The handle of the entity whose parent is to be set.
   * @param parentHandle (int32): The handle of the new parent entity.
   * @param attachmentName (string): The name of the entity's attachment.
   */
  inline void SetEntityParentAttachment(int32_t entityHandle, int32_t parentHandle, const plg::string& attachmentName) {
    return __s2sdk_SetEntityParentAttachment(entityHandle, parentHandle, attachmentName);
  }

  using _GetEntityAbsOrigin = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityAbsOrigin __s2sdk_GetEntityAbsOrigin;
namespace s2sdk {
  /**
   * @brief Retrieves the absolute origin of an entity.
   * @param entityHandle (int32): The handle of the entity whose absolute origin is to be retrieved.
   * @return vec3: A vector where the absolute origin will be stored.
   */
  inline plg::vec3 GetEntityAbsOrigin(int32_t entityHandle) {
    return __s2sdk_GetEntityAbsOrigin(entityHandle);
  }

  using _SetEntityAbsOrigin = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityAbsOrigin __s2sdk_SetEntityAbsOrigin;
namespace s2sdk {
  /**
   * @brief Sets the absolute origin of an entity.
   * @param entityHandle (int32): The handle of the entity whose absolute origin is to be set.
   * @param origin (vec3): The new absolute origin to set for the entity.
   */
  inline void SetEntityAbsOrigin(int32_t entityHandle, const plg::vec3& origin) {
    return __s2sdk_SetEntityAbsOrigin(entityHandle, origin);
  }

  using _GetEntityAbsScale = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityAbsScale __s2sdk_GetEntityAbsScale;
namespace s2sdk {
  /**
   * @brief Retrieves the absolute scale of an entity.
   * @param entityHandle (int32): The handle of the entity whose absolute scale is to be retrieved.
   * @return float: A vector where the absolute scale will be stored.
   */
  inline float GetEntityAbsScale(int32_t entityHandle) {
    return __s2sdk_GetEntityAbsScale(entityHandle);
  }

  using _SetEntityAbsScale = void (*)(int32_t, float);
}
extern "C" PLUGIN_API s2sdk::_SetEntityAbsScale __s2sdk_SetEntityAbsScale;
namespace s2sdk {
  /**
   * @brief Sets the absolute scale of an entity.
   * @param entityHandle (int32): The handle of the entity whose absolute scale is to be set.
   * @param scale (float): The new absolute scale to set for the entity.
   */
  inline void SetEntityAbsScale(int32_t entityHandle, float scale) {
    return __s2sdk_SetEntityAbsScale(entityHandle, scale);
  }

  using _GetEntityAbsAngles = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityAbsAngles __s2sdk_GetEntityAbsAngles;
namespace s2sdk {
  /**
   * @brief Retrieves the angular rotation of an entity.
   * @param entityHandle (int32): The handle of the entity whose angular rotation is to be retrieved.
   * @return vec3: A QAngle where the angular rotation will be stored.
   */
  inline plg::vec3 GetEntityAbsAngles(int32_t entityHandle) {
    return __s2sdk_GetEntityAbsAngles(entityHandle);
  }

  using _SetEntityAbsAngles = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityAbsAngles __s2sdk_SetEntityAbsAngles;
namespace s2sdk {
  /**
   * @brief Sets the angular rotation of an entity.
   * @param entityHandle (int32): The handle of the entity whose angular rotation is to be set.
   * @param angle (vec3): The new angular rotation to set for the entity.
   */
  inline void SetEntityAbsAngles(int32_t entityHandle, const plg::vec3& angle) {
    return __s2sdk_SetEntityAbsAngles(entityHandle, angle);
  }

  using _GetEntityLocalOrigin = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityLocalOrigin __s2sdk_GetEntityLocalOrigin;
namespace s2sdk {
  /**
   * @brief Retrieves the local origin of an entity.
   * @param entityHandle (int32): The handle of the entity whose local origin is to be retrieved.
   * @return vec3: A vector where the local origin will be stored.
   */
  inline plg::vec3 GetEntityLocalOrigin(int32_t entityHandle) {
    return __s2sdk_GetEntityLocalOrigin(entityHandle);
  }

  using _SetEntityLocalOrigin = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityLocalOrigin __s2sdk_SetEntityLocalOrigin;
namespace s2sdk {
  /**
   * @brief Sets the local origin of an entity.
   * @param entityHandle (int32): The handle of the entity whose local origin is to be set.
   * @param origin (vec3): The new local origin to set for the entity.
   */
  inline void SetEntityLocalOrigin(int32_t entityHandle, const plg::vec3& origin) {
    return __s2sdk_SetEntityLocalOrigin(entityHandle, origin);
  }

  using _GetEntityLocalScale = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityLocalScale __s2sdk_GetEntityLocalScale;
namespace s2sdk {
  /**
   * @brief Retrieves the local scale of an entity.
   * @param entityHandle (int32): The handle of the entity whose local scale is to be retrieved.
   * @return float: A vector where the local scale will be stored.
   */
  inline float GetEntityLocalScale(int32_t entityHandle) {
    return __s2sdk_GetEntityLocalScale(entityHandle);
  }

  using _SetEntityLocalScale = void (*)(int32_t, float);
}
extern "C" PLUGIN_API s2sdk::_SetEntityLocalScale __s2sdk_SetEntityLocalScale;
namespace s2sdk {
  /**
   * @brief Sets the local scale of an entity.
   * @param entityHandle (int32): The handle of the entity whose local scale is to be set.
   * @param scale (float): The new local scale to set for the entity.
   */
  inline void SetEntityLocalScale(int32_t entityHandle, float scale) {
    return __s2sdk_SetEntityLocalScale(entityHandle, scale);
  }

  using _GetEntityLocalAngles = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityLocalAngles __s2sdk_GetEntityLocalAngles;
namespace s2sdk {
  /**
   * @brief Retrieves the angular rotation of an entity.
   * @param entityHandle (int32): The handle of the entity whose angular rotation is to be retrieved.
   * @return vec3: A QAngle where the angular rotation will be stored.
   */
  inline plg::vec3 GetEntityLocalAngles(int32_t entityHandle) {
    return __s2sdk_GetEntityLocalAngles(entityHandle);
  }

  using _SetEntityLocalAngles = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityLocalAngles __s2sdk_SetEntityLocalAngles;
namespace s2sdk {
  /**
   * @brief Sets the angular rotation of an entity.
   * @param entityHandle (int32): The handle of the entity whose angular rotation is to be set.
   * @param angle (vec3): The new angular rotation to set for the entity.
   */
  inline void SetEntityLocalAngles(int32_t entityHandle, const plg::vec3& angle) {
    return __s2sdk_SetEntityLocalAngles(entityHandle, angle);
  }

  using _GetEntityAbsVelocity = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityAbsVelocity __s2sdk_GetEntityAbsVelocity;
namespace s2sdk {
  /**
   * @brief Retrieves the absolute velocity of an entity.
   * @param entityHandle (int32): The handle of the entity whose absolute velocity is to be retrieved.
   * @return vec3: A vector where the absolute velocity will be stored.
   */
  inline plg::vec3 GetEntityAbsVelocity(int32_t entityHandle) {
    return __s2sdk_GetEntityAbsVelocity(entityHandle);
  }

  using _SetEntityAbsVelocity = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityAbsVelocity __s2sdk_SetEntityAbsVelocity;
namespace s2sdk {
  /**
   * @brief Sets the absolute velocity of an entity.
   * @param entityHandle (int32): The handle of the entity whose absolute velocity is to be set.
   * @param velocity (vec3): The new absolute velocity to set for the entity.
   */
  inline void SetEntityAbsVelocity(int32_t entityHandle, const plg::vec3& velocity) {
    return __s2sdk_SetEntityAbsVelocity(entityHandle, velocity);
  }

  using _GetEntityBaseVelocity = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityBaseVelocity __s2sdk_GetEntityBaseVelocity;
namespace s2sdk {
  /**
   * @brief Retrieves the base velocity of an entity.
   * @param entityHandle (int32): The handle of the entity whose base velocity is to be retrieved.
   * @return vec3: A vector where the base velocity will be stored.
   */
  inline plg::vec3 GetEntityBaseVelocity(int32_t entityHandle) {
    return __s2sdk_GetEntityBaseVelocity(entityHandle);
  }

  using _GetEntityLocalAngVelocity = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityLocalAngVelocity __s2sdk_GetEntityLocalAngVelocity;
namespace s2sdk {
  /**
   * @brief Retrieves the local angular velocity of an entity.
   * @param entityHandle (int32): The handle of the entity whose local angular velocity is to be retrieved.
   * @return vec3: A vector where the local angular velocity will be stored.
   */
  inline plg::vec3 GetEntityLocalAngVelocity(int32_t entityHandle) {
    return __s2sdk_GetEntityLocalAngVelocity(entityHandle);
  }

  using _GetEntityAngVelocity = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityAngVelocity __s2sdk_GetEntityAngVelocity;
namespace s2sdk {
  /**
   * @brief Retrieves the angular velocity of an entity.
   * @param entityHandle (int32): The handle of the entity whose angular velocity is to be retrieved.
   * @return vec3: A vector where the angular velocity will be stored.
   */
  inline plg::vec3 GetEntityAngVelocity(int32_t entityHandle) {
    return __s2sdk_GetEntityAngVelocity(entityHandle);
  }

  using _SetEntityAngVelocity = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityAngVelocity __s2sdk_SetEntityAngVelocity;
namespace s2sdk {
  /**
   * @brief Sets the angular velocity of an entity.
   * @param entityHandle (int32): The handle of the entity whose angular velocity is to be set.
   * @param velocity (vec3): The new angular velocity to set for the entity.
   */
  inline void SetEntityAngVelocity(int32_t entityHandle, const plg::vec3& velocity) {
    return __s2sdk_SetEntityAngVelocity(entityHandle, velocity);
  }

  using _GetEntityLocalVelocity = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityLocalVelocity __s2sdk_GetEntityLocalVelocity;
namespace s2sdk {
  /**
   * @brief Retrieves the local velocity of an entity.
   * @param entityHandle (int32): The handle of the entity whose local velocity is to be retrieved.
   * @return vec3: A vector where the local velocity will be stored.
   */
  inline plg::vec3 GetEntityLocalVelocity(int32_t entityHandle) {
    return __s2sdk_GetEntityLocalVelocity(entityHandle);
  }

  using _GetEntityAngRotation = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityAngRotation __s2sdk_GetEntityAngRotation;
namespace s2sdk {
  /**
   * @brief Retrieves the angular rotation of an entity.
   * @param entityHandle (int32): The handle of the entity whose angular rotation is to be retrieved.
   * @return vec3: A vector where the angular rotation will be stored.
   */
  inline plg::vec3 GetEntityAngRotation(int32_t entityHandle) {
    return __s2sdk_GetEntityAngRotation(entityHandle);
  }

  using _SetEntityAngRotation = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityAngRotation __s2sdk_SetEntityAngRotation;
namespace s2sdk {
  /**
   * @brief Sets the angular rotation of an entity.
   * @param entityHandle (int32): The handle of the entity whose angular rotation is to be set.
   * @param rotation (vec3): The new angular rotation to set for the entity.
   */
  inline void SetEntityAngRotation(int32_t entityHandle, const plg::vec3& rotation) {
    return __s2sdk_SetEntityAngRotation(entityHandle, rotation);
  }

  using _TransformPointEntityToWorld = plg::vec3 (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_TransformPointEntityToWorld __s2sdk_TransformPointEntityToWorld;
namespace s2sdk {
  /**
   * @brief Returns the input Vector transformed from entity to world space.
   * @param entityHandle (int32): The handle of the entity
   * @param point (vec3): Point in entity local space to transform
   * @return vec3: The point transformed to world space coordinates
   */
  inline plg::vec3 TransformPointEntityToWorld(int32_t entityHandle, const plg::vec3& point) {
    return __s2sdk_TransformPointEntityToWorld(entityHandle, point);
  }

  using _TransformPointWorldToEntity = plg::vec3 (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_TransformPointWorldToEntity __s2sdk_TransformPointWorldToEntity;
namespace s2sdk {
  /**
   * @brief Returns the input Vector transformed from world to entity space.
   * @param entityHandle (int32): The handle of the entity
   * @param point (vec3): Point in world space to transform
   * @return vec3: The point transformed to entity local space coordinates
   */
  inline plg::vec3 TransformPointWorldToEntity(int32_t entityHandle, const plg::vec3& point) {
    return __s2sdk_TransformPointWorldToEntity(entityHandle, point);
  }

  using _GetEntityEyePosition = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityEyePosition __s2sdk_GetEntityEyePosition;
namespace s2sdk {
  /**
   * @brief Get vector to eye position - absolute coords.
   * @param entityHandle (int32): The handle of the entity
   * @return vec3: Eye position in absolute/world coordinates
   */
  inline plg::vec3 GetEntityEyePosition(int32_t entityHandle) {
    return __s2sdk_GetEntityEyePosition(entityHandle);
  }

  using _GetEntityEyeAngles = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityEyeAngles __s2sdk_GetEntityEyeAngles;
namespace s2sdk {
  /**
   * @brief Get the qangles that this entity is looking at.
   * @param entityHandle (int32): The handle of the entity
   * @return vec3: Eye angles as a vector (pitch, yaw, roll)
   */
  inline plg::vec3 GetEntityEyeAngles(int32_t entityHandle) {
    return __s2sdk_GetEntityEyeAngles(entityHandle);
  }

  using _SetEntityForwardVector = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityForwardVector __s2sdk_SetEntityForwardVector;
namespace s2sdk {
  /**
   * @brief Sets the forward velocity of an entity.
   * @param entityHandle (int32): The handle of the entity whose forward velocity is to be set.
   * @param forward (vec3)
   */
  inline void SetEntityForwardVector(int32_t entityHandle, const plg::vec3& forward) {
    return __s2sdk_SetEntityForwardVector(entityHandle, forward);
  }

  using _GetEntityForwardVector = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityForwardVector __s2sdk_GetEntityForwardVector;
namespace s2sdk {
  /**
   * @brief Get the forward vector of the entity.
   * @param entityHandle (int32): The handle of the entity to query
   * @return vec3: Forward-facing direction vector of the entity
   */
  inline plg::vec3 GetEntityForwardVector(int32_t entityHandle) {
    return __s2sdk_GetEntityForwardVector(entityHandle);
  }

  using _GetEntityLeftVector = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityLeftVector __s2sdk_GetEntityLeftVector;
namespace s2sdk {
  /**
   * @brief Get the left vector of the entity.
   * @param entityHandle (int32): The handle of the entity to query
   * @return vec3: Left-facing direction vector of the entity (aligned with the y axis)
   */
  inline plg::vec3 GetEntityLeftVector(int32_t entityHandle) {
    return __s2sdk_GetEntityLeftVector(entityHandle);
  }

  using _GetEntityRightVector = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityRightVector __s2sdk_GetEntityRightVector;
namespace s2sdk {
  /**
   * @brief Get the right vector of the entity.
   * @param entityHandle (int32): The handle of the entity to query
   * @return vec3: Right-facing direction vector of the entity
   */
  inline plg::vec3 GetEntityRightVector(int32_t entityHandle) {
    return __s2sdk_GetEntityRightVector(entityHandle);
  }

  using _GetEntityUpVector = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityUpVector __s2sdk_GetEntityUpVector;
namespace s2sdk {
  /**
   * @brief Get the up vector of the entity.
   * @param entityHandle (int32): The handle of the entity to query
   * @return vec3: Up-facing direction vector of the entity
   */
  inline plg::vec3 GetEntityUpVector(int32_t entityHandle) {
    return __s2sdk_GetEntityUpVector(entityHandle);
  }

  using _GetEntityTransform = plg::mat4x4 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityTransform __s2sdk_GetEntityTransform;
namespace s2sdk {
  /**
   * @brief Get the entity-to-world transformation matrix.
   * @param entityHandle (int32): The handle of the entity to query
   * @return mat4x4: 4x4 transformation matrix representing entity's position, rotation, and scale in world space
   */
  inline plg::mat4x4 GetEntityTransform(int32_t entityHandle) {
    return __s2sdk_GetEntityTransform(entityHandle);
  }

  using _GetEntityModel = plg::string (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityModel __s2sdk_GetEntityModel;
namespace s2sdk {
  /**
   * @brief Retrieves the model name of an entity.
   * @param entityHandle (int32): The handle of the entity whose model name is to be retrieved.
   * @return string: A string where the model name will be stored.
   */
  inline plg::string GetEntityModel(int32_t entityHandle) {
    return __s2sdk_GetEntityModel(entityHandle);
  }

  using _SetEntityModel = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityModel __s2sdk_SetEntityModel;
namespace s2sdk {
  /**
   * @brief Sets the model name of an entity.
   * @param entityHandle (int32): The handle of the entity whose model name is to be set.
   * @param model (string): The new model name to set for the entity.
   */
  inline void SetEntityModel(int32_t entityHandle, const plg::string& model) {
    return __s2sdk_SetEntityModel(entityHandle, model);
  }

  using _GetEntityWaterLevel = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityWaterLevel __s2sdk_GetEntityWaterLevel;
namespace s2sdk {
  /**
   * @brief Retrieves the water level of an entity.
   * @param entityHandle (int32): The handle of the entity whose water level is to be retrieved.
   * @return float: The water level of the entity, or 0.0f if the entity is invalid.
   */
  inline float GetEntityWaterLevel(int32_t entityHandle) {
    return __s2sdk_GetEntityWaterLevel(entityHandle);
  }

  using _GetEntityGroundEntity = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityGroundEntity __s2sdk_GetEntityGroundEntity;
namespace s2sdk {
  /**
   * @brief Retrieves the ground entity of an entity.
   * @param entityHandle (int32): The handle of the entity whose ground entity is to be retrieved.
   * @return int32: The handle of the ground entity, or INVALID_EHANDLE_INDEX if the entity is invalid.
   */
  inline int32_t GetEntityGroundEntity(int32_t entityHandle) {
    return __s2sdk_GetEntityGroundEntity(entityHandle);
  }

  using _GetEntityEffects = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityEffects __s2sdk_GetEntityEffects;
namespace s2sdk {
  /**
   * @brief Retrieves the effects of an entity.
   * @param entityHandle (int32): The handle of the entity whose effects are to be retrieved.
   * @return int32: The effect flags of the entity, or 0 if the entity is invalid.
   */
  inline int32_t GetEntityEffects(int32_t entityHandle) {
    return __s2sdk_GetEntityEffects(entityHandle);
  }

  using _AddEntityEffects = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_AddEntityEffects __s2sdk_AddEntityEffects;
namespace s2sdk {
  /**
   * @brief Adds the render effect flag to an entity.
   * @param entityHandle (int32): The handle of the entity to modify
   * @param effects (int32): Render effect flags to add
   */
  inline void AddEntityEffects(int32_t entityHandle, int32_t effects) {
    return __s2sdk_AddEntityEffects(entityHandle, effects);
  }

  using _RemoveEntityEffects = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_RemoveEntityEffects __s2sdk_RemoveEntityEffects;
namespace s2sdk {
  /**
   * @brief Removes the render effect flag from an entity.
   * @param entityHandle (int32): The handle of the entity to modify
   * @param effects (int32): Render effect flags to remove
   */
  inline void RemoveEntityEffects(int32_t entityHandle, int32_t effects) {
    return __s2sdk_RemoveEntityEffects(entityHandle, effects);
  }

  using _GetEntityBoundingMaxs = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityBoundingMaxs __s2sdk_GetEntityBoundingMaxs;
namespace s2sdk {
  /**
   * @brief Get a vector containing max bounds, centered on object.
   * @param entityHandle (int32): The handle of the entity to query
   * @return vec3: Vector containing the maximum bounds of the entity's bounding box
   */
  inline plg::vec3 GetEntityBoundingMaxs(int32_t entityHandle) {
    return __s2sdk_GetEntityBoundingMaxs(entityHandle);
  }

  using _GetEntityBoundingMins = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityBoundingMins __s2sdk_GetEntityBoundingMins;
namespace s2sdk {
  /**
   * @brief Get a vector containing min bounds, centered on object.
   * @param entityHandle (int32): The handle of the entity to query
   * @return vec3: Vector containing the minimum bounds of the entity's bounding box
   */
  inline plg::vec3 GetEntityBoundingMins(int32_t entityHandle) {
    return __s2sdk_GetEntityBoundingMins(entityHandle);
  }

  using _GetEntityCenter = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityCenter __s2sdk_GetEntityCenter;
namespace s2sdk {
  /**
   * @brief Get vector to center of object - absolute coords.
   * @param entityHandle (int32): The handle of the entity to query
   * @return vec3: Vector pointing to the center of the entity in absolute/world coordinates
   */
  inline plg::vec3 GetEntityCenter(int32_t entityHandle) {
    return __s2sdk_GetEntityCenter(entityHandle);
  }

  using _TeleportEntity = void (*)(int32_t, const plg::vec3&, const plg::vec3&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_TeleportEntity __s2sdk_TeleportEntity;
namespace s2sdk {
  /**
   * @brief Teleports an entity to a specified location and orientation.
   * @param entityHandle (int32): The handle of the entity to teleport.
   * @param origin (vec3): A pointer to a Vector representing the new absolute position. Use nan vector to not set.
   * @param angles (vec3): A pointer to a QAngle representing the new orientation. Use nan vector to not set.
   * @param velocity (vec3): A pointer to a Vector representing the new velocity. Use nan vector to not set.
   */
  inline void TeleportEntity(int32_t entityHandle, const plg::vec3& origin, const plg::vec3& angles, const plg::vec3& velocity) {
    return __s2sdk_TeleportEntity(entityHandle, origin, angles, velocity);
  }

  using _ApplyAbsVelocityImpulseToEntity = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_ApplyAbsVelocityImpulseToEntity __s2sdk_ApplyAbsVelocityImpulseToEntity;
namespace s2sdk {
  /**
   * @brief Apply an absolute velocity impulse to an entity.
   * @param entityHandle (int32): The handle of the entity to apply impulse to
   * @param vecImpulse (vec3): Velocity impulse vector to apply
   */
  inline void ApplyAbsVelocityImpulseToEntity(int32_t entityHandle, const plg::vec3& vecImpulse) {
    return __s2sdk_ApplyAbsVelocityImpulseToEntity(entityHandle, vecImpulse);
  }

  using _ApplyLocalAngularVelocityImpulseToEntity = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_ApplyLocalAngularVelocityImpulseToEntity __s2sdk_ApplyLocalAngularVelocityImpulseToEntity;
namespace s2sdk {
  /**
   * @brief Apply a local angular velocity impulse to an entity.
   * @param entityHandle (int32): The handle of the entity to apply impulse to
   * @param angImpulse (vec3): Angular velocity impulse vector to apply
   */
  inline void ApplyLocalAngularVelocityImpulseToEntity(int32_t entityHandle, const plg::vec3& angImpulse) {
    return __s2sdk_ApplyLocalAngularVelocityImpulseToEntity(entityHandle, angImpulse);
  }

  using _AcceptEntityInput = void (*)(int32_t, const plg::string&, int32_t, int32_t, const plg::any&, FieldType, int32_t);
}
extern "C" PLUGIN_API s2sdk::_AcceptEntityInput __s2sdk_AcceptEntityInput;
namespace s2sdk {
  /**
   * @brief Invokes a named input method on a specified entity.
   * @param entityHandle (int32): The handle of the target entity that will receive the input.
   * @param inputName (string): The name of the input action to invoke.
   * @param activatorHandle (int32): The handle of the entity that initiated the sequence of actions.
   * @param callerHandle (int32): The handle of the entity sending this event.
   * @param value (any): The value associated with the input action.
   * @param type (int32): The type or classification of the value.
   * @param outputId (int32): An identifier for tracking the output of this operation.
   */
  inline void AcceptEntityInput(int32_t entityHandle, const plg::string& inputName, int32_t activatorHandle, int32_t callerHandle, const plg::any& value, FieldType type, int32_t outputId) {
    return __s2sdk_AcceptEntityInput(entityHandle, inputName, activatorHandle, callerHandle, value, type, outputId);
  }

  using _ConnectEntityOutput = void (*)(int32_t, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_ConnectEntityOutput __s2sdk_ConnectEntityOutput;
namespace s2sdk {
  /**
   * @brief Connects a script function to an entity output.
   * @param entityHandle (int32): The handle of the entity.
   * @param output (string): The name of the output to connect to.
   * @param functionName (string): The name of the script function to call.
   */
  inline void ConnectEntityOutput(int32_t entityHandle, const plg::string& output, const plg::string& functionName) {
    return __s2sdk_ConnectEntityOutput(entityHandle, output, functionName);
  }

  using _DisconnectEntityOutput = void (*)(int32_t, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_DisconnectEntityOutput __s2sdk_DisconnectEntityOutput;
namespace s2sdk {
  /**
   * @brief Disconnects a script function from an entity output.
   * @param entityHandle (int32): The handle of the entity.
   * @param output (string): The name of the output.
   * @param functionName (string): The name of the script function to disconnect.
   */
  inline void DisconnectEntityOutput(int32_t entityHandle, const plg::string& output, const plg::string& functionName) {
    return __s2sdk_DisconnectEntityOutput(entityHandle, output, functionName);
  }

  using _DisconnectEntityRedirectedOutput = void (*)(int32_t, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_DisconnectEntityRedirectedOutput __s2sdk_DisconnectEntityRedirectedOutput;
namespace s2sdk {
  /**
   * @brief Disconnects a script function from an I/O event on a different entity.
   * @param entityHandle (int32): The handle of the calling entity.
   * @param output (string): The name of the output.
   * @param functionName (string): The function name to disconnect.
   * @param targetHandle (int32): The handle of the entity whose output is being disconnected.
   */
  inline void DisconnectEntityRedirectedOutput(int32_t entityHandle, const plg::string& output, const plg::string& functionName, int32_t targetHandle) {
    return __s2sdk_DisconnectEntityRedirectedOutput(entityHandle, output, functionName, targetHandle);
  }

  using _FireEntityOutput = void (*)(int32_t, const plg::string&, int32_t, int32_t, const plg::any&, FieldType, float);
}
extern "C" PLUGIN_API s2sdk::_FireEntityOutput __s2sdk_FireEntityOutput;
namespace s2sdk {
  /**
   * @brief Fires an entity output.
   * @param entityHandle (int32): The handle of the entity firing the output.
   * @param outputName (string): The name of the output to fire.
   * @param activatorHandle (int32): The entity activating the output.
   * @param callerHandle (int32): The entity that called the output.
   * @param value (any): The value associated with the input action.
   * @param type (int32): The type or classification of the value.
   * @param delay (float): Delay in seconds before firing the output.
   */
  inline void FireEntityOutput(int32_t entityHandle, const plg::string& outputName, int32_t activatorHandle, int32_t callerHandle, const plg::any& value, FieldType type, float delay) {
    return __s2sdk_FireEntityOutput(entityHandle, outputName, activatorHandle, callerHandle, value, type, delay);
  }

  using _RedirectEntityOutput = void (*)(int32_t, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_RedirectEntityOutput __s2sdk_RedirectEntityOutput;
namespace s2sdk {
  /**
   * @brief Redirects an entity output to call a function on another entity.
   * @param entityHandle (int32): The handle of the entity whose output is being redirected.
   * @param output (string): The name of the output to redirect.
   * @param functionName (string): The function name to call on the target entity.
   * @param targetHandle (int32): The handle of the entity that will receive the output call.
   */
  inline void RedirectEntityOutput(int32_t entityHandle, const plg::string& output, const plg::string& functionName, int32_t targetHandle) {
    return __s2sdk_RedirectEntityOutput(entityHandle, output, functionName, targetHandle);
  }

  using _FollowEntity = void (*)(int32_t, int32_t, bool);
}
extern "C" PLUGIN_API s2sdk::_FollowEntity __s2sdk_FollowEntity;
namespace s2sdk {
  /**
   * @brief Makes an entity follow another entity with optional bone merging.
   * @param entityHandle (int32): The handle of the entity that will follow
   * @param attachmentHandle (int32): The handle of the entity to follow
   * @param boneMerge (bool): If true, bones will be merged between entities
   */
  inline void FollowEntity(int32_t entityHandle, int32_t attachmentHandle, bool boneMerge) {
    return __s2sdk_FollowEntity(entityHandle, attachmentHandle, boneMerge);
  }

  using _FollowEntityMerge = void (*)(int32_t, int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_FollowEntityMerge __s2sdk_FollowEntityMerge;
namespace s2sdk {
  /**
   * @brief Makes an entity follow another entity and merge with a specific bone or attachment.
   * @param entityHandle (int32): The handle of the entity that will follow
   * @param attachmentHandle (int32): The handle of the entity to follow
   * @param boneOrAttachName (string): Name of the bone or attachment point to merge with
   */
  inline void FollowEntityMerge(int32_t entityHandle, int32_t attachmentHandle, const plg::string& boneOrAttachName) {
    return __s2sdk_FollowEntityMerge(entityHandle, attachmentHandle, boneOrAttachName);
  }

  using _TakeEntityDamage = int32_t (*)(int32_t, int32_t, int32_t, const plg::vec3&, const plg::vec3&, float, DamageTypes);
}
extern "C" PLUGIN_API s2sdk::_TakeEntityDamage __s2sdk_TakeEntityDamage;
namespace s2sdk {
  /**
   * @brief Apply damage to an entity.
   * @param entityHandle (int32): The handle of the entity receiving damage
   * @param inflictorHandle (int32): The handle of the entity inflicting damage (e.g., projectile)
   * @param attackerHandle (int32): The handle of the attacking entity
   * @param force (vec3): Direction and magnitude of force to apply
   * @param hitPos (vec3): Position where the damage hit occurred
   * @param damage (float): Amount of damage to apply
   * @param damageTypes (int32): Bitfield of damage type flags
   * @return int32: Amount of damage actually applied to the entity
   */
  inline int32_t TakeEntityDamage(int32_t entityHandle, int32_t inflictorHandle, int32_t attackerHandle, const plg::vec3& force, const plg::vec3& hitPos, float damage, DamageTypes damageTypes) {
    return __s2sdk_TakeEntityDamage(entityHandle, inflictorHandle, attackerHandle, force, hitPos, damage, damageTypes);
  }

  using _GetEntityAttributeFloatValue = float (*)(int32_t, const plg::string&, float);
}
extern "C" PLUGIN_API s2sdk::_GetEntityAttributeFloatValue __s2sdk_GetEntityAttributeFloatValue;
namespace s2sdk {
  /**
   * @brief Retrieves a float attribute value from an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param name (string): The name of the attribute.
   * @param defaultValue (float): The default value to return if the attribute does not exist.
   * @return float: The float value of the attribute, or the default value if missing or invalid.
   */
  inline float GetEntityAttributeFloatValue(int32_t entityHandle, const plg::string& name, float defaultValue) {
    return __s2sdk_GetEntityAttributeFloatValue(entityHandle, name, defaultValue);
  }

  using _GetEntityAttributeIntValue = int32_t (*)(int32_t, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityAttributeIntValue __s2sdk_GetEntityAttributeIntValue;
namespace s2sdk {
  /**
   * @brief Retrieves an integer attribute value from an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param name (string): The name of the attribute.
   * @param defaultValue (int32): The default value to return if the attribute does not exist.
   * @return int32: The integer value of the attribute, or the default value if missing or invalid.
   */
  inline int32_t GetEntityAttributeIntValue(int32_t entityHandle, const plg::string& name, int32_t defaultValue) {
    return __s2sdk_GetEntityAttributeIntValue(entityHandle, name, defaultValue);
  }

  using _SetEntityAttributeFloatValue = void (*)(int32_t, const plg::string&, float);
}
extern "C" PLUGIN_API s2sdk::_SetEntityAttributeFloatValue __s2sdk_SetEntityAttributeFloatValue;
namespace s2sdk {
  /**
   * @brief Sets a float attribute value on an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param name (string): The name of the attribute.
   * @param value (float): The float value to assign to the attribute.
   */
  inline void SetEntityAttributeFloatValue(int32_t entityHandle, const plg::string& name, float value) {
    return __s2sdk_SetEntityAttributeFloatValue(entityHandle, name, value);
  }

  using _SetEntityAttributeIntValue = void (*)(int32_t, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityAttributeIntValue __s2sdk_SetEntityAttributeIntValue;
namespace s2sdk {
  /**
   * @brief Sets an integer attribute value on an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param name (string): The name of the attribute.
   * @param value (int32): The integer value to assign to the attribute.
   */
  inline void SetEntityAttributeIntValue(int32_t entityHandle, const plg::string& name, int32_t value) {
    return __s2sdk_SetEntityAttributeIntValue(entityHandle, name, value);
  }

  using _DeleteEntityAttribute = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_DeleteEntityAttribute __s2sdk_DeleteEntityAttribute;
namespace s2sdk {
  /**
   * @brief Deletes an attribute from an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param name (string): The name of the attribute to delete.
   */
  inline void DeleteEntityAttribute(int32_t entityHandle, const plg::string& name) {
    return __s2sdk_DeleteEntityAttribute(entityHandle, name);
  }

  using _HasEntityAttribute = bool (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_HasEntityAttribute __s2sdk_HasEntityAttribute;
namespace s2sdk {
  /**
   * @brief Checks if an entity has a specific attribute.
   * @param entityHandle (int32): The handle of the entity.
   * @param name (string): The name of the attribute to check.
   * @return bool: True if the attribute exists, false otherwise.
   */
  inline bool HasEntityAttribute(int32_t entityHandle, const plg::string& name) {
    return __s2sdk_HasEntityAttribute(entityHandle, name);
  }

} // namespace s2sdk
