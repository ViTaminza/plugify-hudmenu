#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: clients)

namespace s2sdk {

  using _EntPointerToPlayerSlot = int32_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_EntPointerToPlayerSlot __s2sdk_EntPointerToPlayerSlot;
namespace s2sdk {
  /**
   * @brief Retrieves the player slot from a given entity pointer.
   * @param entity (ptr64): A pointer to the entity (CBaseEntity*).
   * @return int32: The player slot if valid, otherwise -1.
   */
  inline int32_t EntPointerToPlayerSlot(void* entity) {
    return __s2sdk_EntPointerToPlayerSlot(entity);
  }

  using _PlayerSlotToEntPointer = void* (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_PlayerSlotToEntPointer __s2sdk_PlayerSlotToEntPointer;
namespace s2sdk {
  /**
   * @brief Returns a pointer to the entity instance by player slot index.
   * @param playerSlot (int32): Index of the player slot.
   * @return ptr64: Pointer to the entity instance, or nullptr if the slot is invalid.
   */
  inline void* PlayerSlotToEntPointer(int32_t playerSlot) {
    return __s2sdk_PlayerSlotToEntPointer(playerSlot);
  }

  using _PlayerSlotToEntHandle = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_PlayerSlotToEntHandle __s2sdk_PlayerSlotToEntHandle;
namespace s2sdk {
  /**
   * @brief Returns the entity handle associated with a player slot index.
   * @param playerSlot (int32): Index of the player slot.
   * @return int32: The index of the entity, or -1 if the handle is invalid.
   */
  inline int32_t PlayerSlotToEntHandle(int32_t playerSlot) {
    return __s2sdk_PlayerSlotToEntHandle(playerSlot);
  }

  using _PlayerSlotToClientPtr = void* (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_PlayerSlotToClientPtr __s2sdk_PlayerSlotToClientPtr;
namespace s2sdk {
  /**
   * @brief Retrieves the client object from a given player slot.
   * @param playerSlot (int32): The index of the player's slot (0-based).
   * @return ptr64: A pointer to the client object if found, otherwise nullptr.
   */
  inline void* PlayerSlotToClientPtr(int32_t playerSlot) {
    return __s2sdk_PlayerSlotToClientPtr(playerSlot);
  }

  using _ClientPtrToPlayerSlot = int32_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_ClientPtrToPlayerSlot __s2sdk_ClientPtrToPlayerSlot;
namespace s2sdk {
  /**
   * @brief Retrieves the index of a given client object.
   * @param client (ptr64): A pointer to the client object (CServerSideClient*).
   * @return int32: The player slot if found, otherwise -1.
   */
  inline int32_t ClientPtrToPlayerSlot(void* client) {
    return __s2sdk_ClientPtrToPlayerSlot(client);
  }

  using _PlayerSlotToClientIndex = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_PlayerSlotToClientIndex __s2sdk_PlayerSlotToClientIndex;
namespace s2sdk {
  /**
   * @brief Returns the entity index for a given player slot.
   * @param playerSlot (int32): The index of the player's slot.
   * @return int32: The entity index if valid, otherwise 0.
   */
  inline int32_t PlayerSlotToClientIndex(int32_t playerSlot) {
    return __s2sdk_PlayerSlotToClientIndex(playerSlot);
  }

  using _ClientIndexToPlayerSlot = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_ClientIndexToPlayerSlot __s2sdk_ClientIndexToPlayerSlot;
namespace s2sdk {
  /**
   * @brief Retrieves the player slot from a given client index.
   * @param clientIndex (int32): The index of the client.
   * @return int32: The player slot if valid, otherwise -1.
   */
  inline int32_t ClientIndexToPlayerSlot(int32_t clientIndex) {
    return __s2sdk_ClientIndexToPlayerSlot(clientIndex);
  }

  using _PlayerServicesToPlayerSlot = int32_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_PlayerServicesToPlayerSlot __s2sdk_PlayerServicesToPlayerSlot;
namespace s2sdk {
  /**
   * @brief Retrieves the player slot from a given player service.
   * @param service (ptr64): The service pointer. Like CCSPlayer_ItemServices, CCSPlayer_WeaponServices ect.
   * @return int32: The player slot if valid, otherwise -1.
   */
  inline int32_t PlayerServicesToPlayerSlot(void* service) {
    return __s2sdk_PlayerServicesToPlayerSlot(service);
  }

  using _GetClientAuthId = plg::string (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientAuthId __s2sdk_GetClientAuthId;
namespace s2sdk {
  /**
   * @brief Retrieves a client's authentication string (SteamID).
   * @param playerSlot (int32): The index of the player's slot whose authentication string is being retrieved.
   * @return string: The authentication string.
   */
  inline plg::string GetClientAuthId(int32_t playerSlot) {
    return __s2sdk_GetClientAuthId(playerSlot);
  }

  using _GetClientAccountId = uint32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientAccountId __s2sdk_GetClientAccountId;
namespace s2sdk {
  /**
   * @brief Returns the client's Steam account ID, a unique number identifying a given Steam account.
   * @param playerSlot (int32): The index of the player's slot.
   * @return uint32: uint32_t The client's steam account ID.
   */
  inline uint32_t GetClientAccountId(int32_t playerSlot) {
    return __s2sdk_GetClientAccountId(playerSlot);
  }

  using _GetClientSteamID64 = uint64_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientSteamID64 __s2sdk_GetClientSteamID64;
namespace s2sdk {
  /**
   * @brief Returns the client's SteamID64 - a unique 64-bit identifier of a Steam account.
   * @param playerSlot (int32): The index of the player's slot.
   * @return uint64: uint64_t The client's SteamID64.
   */
  inline uint64_t GetClientSteamID64(int32_t playerSlot) {
    return __s2sdk_GetClientSteamID64(playerSlot);
  }

  using _GetClientIp = plg::string (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientIp __s2sdk_GetClientIp;
namespace s2sdk {
  /**
   * @brief Retrieves a client's IP address.
   * @param playerSlot (int32): The index of the player's slot.
   * @return string: The client's IP address.
   */
  inline plg::string GetClientIp(int32_t playerSlot) {
    return __s2sdk_GetClientIp(playerSlot);
  }

  using _GetClientLanguage = plg::string (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientLanguage __s2sdk_GetClientLanguage;
namespace s2sdk {
  /**
   * @brief Retrieves a client's language.
   * @param playerSlot (int32): The index of the player's slot.
   * @return string: The client's language.
   */
  inline plg::string GetClientLanguage(int32_t playerSlot) {
    return __s2sdk_GetClientLanguage(playerSlot);
  }

  using _GetClientLanguageCode = plg::string (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientLanguageCode __s2sdk_GetClientLanguageCode;
namespace s2sdk {
  /**
   * @brief Retrieves a client's language as an ISO code. Unlike GetClientLanguage, which returns the raw cl_language value ("english", "schinese"), this returns the code translation files are keyed by ("en", "zh-CN"). Falls back to the server language when the client's language is not known.
   * @param playerSlot (int32): The index of the player's slot.
   * @return string: The client's ISO language code.
   */
  inline plg::string GetClientLanguageCode(int32_t playerSlot) {
    return __s2sdk_GetClientLanguageCode(playerSlot);
  }

  using _GetClientOS = plg::string (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientOS __s2sdk_GetClientOS;
namespace s2sdk {
  /**
   * @brief Retrieves a client's operating system.
   * @param playerSlot (int32): The index of the player's slot.
   * @return string: The client's operating system.
   */
  inline plg::string GetClientOS(int32_t playerSlot) {
    return __s2sdk_GetClientOS(playerSlot);
  }

  using _GetClientName = plg::string (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientName __s2sdk_GetClientName;
namespace s2sdk {
  /**
   * @brief Returns the client's name.
   * @param playerSlot (int32): The index of the player's slot.
   * @return string: The client's name.
   */
  inline plg::string GetClientName(int32_t playerSlot) {
    return __s2sdk_GetClientName(playerSlot);
  }

  using _SetClientName = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetClientName __s2sdk_SetClientName;
namespace s2sdk {
  /**
   * @brief Set client's name.
   * @param playerSlot (int32): The index of the player's slot.
   * @param name (string): The client's name.
   */
  inline void SetClientName(int32_t playerSlot, const plg::string& name) {
    return __s2sdk_SetClientName(playerSlot, name);
  }

  using _GetClientTime = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientTime __s2sdk_GetClientTime;
namespace s2sdk {
  /**
   * @brief Returns the client's connection time in seconds.
   * @param playerSlot (int32): The index of the player's slot.
   * @return float: float Connection time in seconds.
   */
  inline float GetClientTime(int32_t playerSlot) {
    return __s2sdk_GetClientTime(playerSlot);
  }

  using _GetClientLatency = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientLatency __s2sdk_GetClientLatency;
namespace s2sdk {
  /**
   * @brief Returns the client's current latency (RTT).
   * @param playerSlot (int32): The index of the player's slot.
   * @return float: float Latency value.
   */
  inline float GetClientLatency(int32_t playerSlot) {
    return __s2sdk_GetClientLatency(playerSlot);
  }

  using _GetUserFlagBits = uint64_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetUserFlagBits __s2sdk_GetUserFlagBits;
namespace s2sdk {
  /**
   * @brief Returns the client's access flags.
   * @param playerSlot (int32): The index of the player's slot.
   * @return uint64: uint64 Access flags as a bitmask.
   */
  inline uint64_t GetUserFlagBits(int32_t playerSlot) {
    return __s2sdk_GetUserFlagBits(playerSlot);
  }

  using _SetUserFlagBits = void (*)(int32_t, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_SetUserFlagBits __s2sdk_SetUserFlagBits;
namespace s2sdk {
  /**
   * @brief Sets the access flags on a client using a bitmask.
   * @param playerSlot (int32): The index of the player's slot.
   * @param flags (uint64): Bitmask representing the flags to be set.
   */
  inline void SetUserFlagBits(int32_t playerSlot, uint64_t flags) {
    return __s2sdk_SetUserFlagBits(playerSlot, flags);
  }

  using _AddUserFlags = void (*)(int32_t, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_AddUserFlags __s2sdk_AddUserFlags;
namespace s2sdk {
  /**
   * @brief Adds access flags to a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @param flags (uint64): Bitmask representing the flags to be added.
   */
  inline void AddUserFlags(int32_t playerSlot, uint64_t flags) {
    return __s2sdk_AddUserFlags(playerSlot, flags);
  }

  using _RemoveUserFlags = void (*)(int32_t, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_RemoveUserFlags __s2sdk_RemoveUserFlags;
namespace s2sdk {
  /**
   * @brief Removes access flags from a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @param flags (uint64): Bitmask representing the flags to be removed.
   */
  inline void RemoveUserFlags(int32_t playerSlot, uint64_t flags) {
    return __s2sdk_RemoveUserFlags(playerSlot, flags);
  }

  using _IsClientAuthorized = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsClientAuthorized __s2sdk_IsClientAuthorized;
namespace s2sdk {
  /**
   * @brief Checks if a certain player has been authenticated.
   * @param playerSlot (int32): The index of the player's slot.
   * @return bool: true if the player is authenticated, false otherwise.
   */
  inline bool IsClientAuthorized(int32_t playerSlot) {
    return __s2sdk_IsClientAuthorized(playerSlot);
  }

  using _IsClientConnected = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsClientConnected __s2sdk_IsClientConnected;
namespace s2sdk {
  /**
   * @brief Checks if a certain player is connected.
   * @param playerSlot (int32): The index of the player's slot.
   * @return bool: true if the player is connected, false otherwise.
   */
  inline bool IsClientConnected(int32_t playerSlot) {
    return __s2sdk_IsClientConnected(playerSlot);
  }

  using _IsClientInGame = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsClientInGame __s2sdk_IsClientInGame;
namespace s2sdk {
  /**
   * @brief Checks if a certain player has entered the game.
   * @param playerSlot (int32): The index of the player's slot.
   * @return bool: true if the player is in the game, false otherwise.
   */
  inline bool IsClientInGame(int32_t playerSlot) {
    return __s2sdk_IsClientInGame(playerSlot);
  }

  using _IsClientSourceTV = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsClientSourceTV __s2sdk_IsClientSourceTV;
namespace s2sdk {
  /**
   * @brief Checks if a certain player is the SourceTV bot.
   * @param playerSlot (int32): The index of the player's slot.
   * @return bool: true if the client is the SourceTV bot, false otherwise.
   */
  inline bool IsClientSourceTV(int32_t playerSlot) {
    return __s2sdk_IsClientSourceTV(playerSlot);
  }

  using _IsClientAlive = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsClientAlive __s2sdk_IsClientAlive;
namespace s2sdk {
  /**
   * @brief Checks if the client is alive or dead.
   * @param playerSlot (int32): The index of the player's slot.
   * @return bool: true if the client is alive, false if dead.
   */
  inline bool IsClientAlive(int32_t playerSlot) {
    return __s2sdk_IsClientAlive(playerSlot);
  }

  using _IsFakeClient = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsFakeClient __s2sdk_IsFakeClient;
namespace s2sdk {
  /**
   * @brief Checks if a certain player is a fake client.
   * @param playerSlot (int32): The index of the player's slot.
   * @return bool: true if the client is a fake client, false otherwise.
   */
  inline bool IsFakeClient(int32_t playerSlot) {
    return __s2sdk_IsFakeClient(playerSlot);
  }

  using _GetClientMoveType = MoveType (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientMoveType __s2sdk_GetClientMoveType;
namespace s2sdk {
  /**
   * @brief Retrieves the movement type of an client.
   * @param playerSlot (int32): The index of the player's slot whose movement type is to be retrieved.
   * @return int32: The movement type of the entity, or 0 if the entity is invalid.
   */
  inline MoveType GetClientMoveType(int32_t playerSlot) {
    return __s2sdk_GetClientMoveType(playerSlot);
  }

  using _SetClientMoveType = void (*)(int32_t, MoveType);
}
extern "C" PLUGIN_API s2sdk::_SetClientMoveType __s2sdk_SetClientMoveType;
namespace s2sdk {
  /**
   * @brief Sets the movement type of an client.
   * @param playerSlot (int32): The index of the player's slot whose movement type is to be set.
   * @param moveType (int32): The movement type of the entity, or 0 if the entity is invalid.
   */
  inline void SetClientMoveType(int32_t playerSlot, MoveType moveType) {
    return __s2sdk_SetClientMoveType(playerSlot, moveType);
  }

  using _GetClientGravity = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientGravity __s2sdk_GetClientGravity;
namespace s2sdk {
  /**
   * @brief Retrieves the gravity scale of an client.
   * @param playerSlot (int32): The index of the player's slot whose gravity scale is to be retrieved.
   * @return float: The gravity scale of the client, or 0.0f if the client is invalid.
   */
  inline float GetClientGravity(int32_t playerSlot) {
    return __s2sdk_GetClientGravity(playerSlot);
  }

  using _SetClientGravity = void (*)(int32_t, float);
}
extern "C" PLUGIN_API s2sdk::_SetClientGravity __s2sdk_SetClientGravity;
namespace s2sdk {
  /**
   * @brief Sets the gravity scale of an client.
   * @param playerSlot (int32): The index of the player's slot whose gravity scale is to be set.
   * @param gravity (float): The new gravity scale to set for the client.
   */
  inline void SetClientGravity(int32_t playerSlot, float gravity) {
    return __s2sdk_SetClientGravity(playerSlot, gravity);
  }

  using _GetClientFlags = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientFlags __s2sdk_GetClientFlags;
namespace s2sdk {
  /**
   * @brief Retrieves the flags of an client.
   * @param playerSlot (int32): The index of the player's slot whose flags are to be retrieved.
   * @return int32: The flags of the client, or 0 if the client is invalid.
   */
  inline int32_t GetClientFlags(int32_t playerSlot) {
    return __s2sdk_GetClientFlags(playerSlot);
  }

  using _SetClientFlags = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetClientFlags __s2sdk_SetClientFlags;
namespace s2sdk {
  /**
   * @brief Sets the flags of an client.
   * @param playerSlot (int32): The index of the player's slot whose flags are to be set.
   * @param flags (int32): The new flags to set for the client.
   */
  inline void SetClientFlags(int32_t playerSlot, int32_t flags) {
    return __s2sdk_SetClientFlags(playerSlot, flags);
  }

  using _GetClientRenderColor = plg::vec4 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientRenderColor __s2sdk_GetClientRenderColor;
namespace s2sdk {
  /**
   * @brief Retrieves the render color of an client.
   * @param playerSlot (int32): The index of the player's slot whose render color is to be retrieved.
   * @return vec4: The raw color value of the client's render color, or 0 if the client is invalid.
   */
  inline plg::vec4 GetClientRenderColor(int32_t playerSlot) {
    return __s2sdk_GetClientRenderColor(playerSlot);
  }

  using _SetClientRenderColor = void (*)(int32_t, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_SetClientRenderColor __s2sdk_SetClientRenderColor;
namespace s2sdk {
  /**
   * @brief Sets the render color of an client.
   * @param playerSlot (int32): The index of the player's slot whose render color is to be set.
   * @param color (vec4): The new raw color value to set for the client's render color.
   */
  inline void SetClientRenderColor(int32_t playerSlot, const plg::vec4& color) {
    return __s2sdk_SetClientRenderColor(playerSlot, color);
  }

  using _GetClientRenderMode = RenderMode (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientRenderMode __s2sdk_GetClientRenderMode;
namespace s2sdk {
  /**
   * @brief Retrieves the render mode of an client.
   * @param playerSlot (int32): The index of the player's slot whose render mode is to be retrieved.
   * @return uint8: The render mode of the client, or 0 if the client is invalid.
   */
  inline RenderMode GetClientRenderMode(int32_t playerSlot) {
    return __s2sdk_GetClientRenderMode(playerSlot);
  }

  using _SetClientRenderMode = void (*)(int32_t, RenderMode);
}
extern "C" PLUGIN_API s2sdk::_SetClientRenderMode __s2sdk_SetClientRenderMode;
namespace s2sdk {
  /**
   * @brief Sets the render mode of an client.
   * @param playerSlot (int32): The index of the player's slot whose render mode is to be set.
   * @param renderMode (uint8): The new render mode to set for the client.
   */
  inline void SetClientRenderMode(int32_t playerSlot, RenderMode renderMode) {
    return __s2sdk_SetClientRenderMode(playerSlot, renderMode);
  }

  using _GetClientMass = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientMass __s2sdk_GetClientMass;
namespace s2sdk {
  /**
   * @brief Retrieves the mass of an client.
   * @param playerSlot (int32): The index of the player's slot whose mass is to be retrieved.
   * @return int32: The mass of the client, or 0 if the client is invalid.
   */
  inline int32_t GetClientMass(int32_t playerSlot) {
    return __s2sdk_GetClientMass(playerSlot);
  }

  using _SetClientMass = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetClientMass __s2sdk_SetClientMass;
namespace s2sdk {
  /**
   * @brief Sets the mass of an client.
   * @param playerSlot (int32): The index of the player's slot whose mass is to be set.
   * @param mass (int32): The new mass value to set for the client.
   */
  inline void SetClientMass(int32_t playerSlot, int32_t mass) {
    return __s2sdk_SetClientMass(playerSlot, mass);
  }

  using _GetClientFriction = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientFriction __s2sdk_GetClientFriction;
namespace s2sdk {
  /**
   * @brief Retrieves the friction of an client.
   * @param playerSlot (int32): The index of the player's slot whose friction is to be retrieved.
   * @return float: The friction of the client, or 0 if the client is invalid.
   */
  inline float GetClientFriction(int32_t playerSlot) {
    return __s2sdk_GetClientFriction(playerSlot);
  }

  using _SetClientFriction = void (*)(int32_t, float);
}
extern "C" PLUGIN_API s2sdk::_SetClientFriction __s2sdk_SetClientFriction;
namespace s2sdk {
  /**
   * @brief Sets the friction of an client.
   * @param playerSlot (int32): The index of the player's slot whose friction is to be set.
   * @param friction (float): The new friction value to set for the client.
   */
  inline void SetClientFriction(int32_t playerSlot, float friction) {
    return __s2sdk_SetClientFriction(playerSlot, friction);
  }

  using _GetClientHealth = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientHealth __s2sdk_GetClientHealth;
namespace s2sdk {
  /**
   * @brief Retrieves the health of an client.
   * @param playerSlot (int32): The index of the player's slot whose health is to be retrieved.
   * @return int32: The health of the client, or 0 if the client is invalid.
   */
  inline int32_t GetClientHealth(int32_t playerSlot) {
    return __s2sdk_GetClientHealth(playerSlot);
  }

  using _SetClientHealth = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetClientHealth __s2sdk_SetClientHealth;
namespace s2sdk {
  /**
   * @brief Sets the health of an client.
   * @param playerSlot (int32): The index of the player's slot whose health is to be set.
   * @param health (int32): The new health value to set for the client.
   */
  inline void SetClientHealth(int32_t playerSlot, int32_t health) {
    return __s2sdk_SetClientHealth(playerSlot, health);
  }

  using _GetClientMaxHealth = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientMaxHealth __s2sdk_GetClientMaxHealth;
namespace s2sdk {
  /**
   * @brief Retrieves the max health of an client.
   * @param playerSlot (int32): The index of the player's slot whose max health is to be retrieved.
   * @return int32: The max health of the client, or 0 if the client is invalid.
   */
  inline int32_t GetClientMaxHealth(int32_t playerSlot) {
    return __s2sdk_GetClientMaxHealth(playerSlot);
  }

  using _SetClientMaxHealth = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetClientMaxHealth __s2sdk_SetClientMaxHealth;
namespace s2sdk {
  /**
   * @brief Sets the max health of an client.
   * @param playerSlot (int32): The index of the player's slot whose max health is to be set.
   * @param maxHealth (int32): The new max health value to set for the client.
   */
  inline void SetClientMaxHealth(int32_t playerSlot, int32_t maxHealth) {
    return __s2sdk_SetClientMaxHealth(playerSlot, maxHealth);
  }

  using _GetClientTeam = CSTeam (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientTeam __s2sdk_GetClientTeam;
namespace s2sdk {
  /**
   * @brief Retrieves the team number of an client.
   * @param playerSlot (int32): The index of the player's slot whose team number is to be retrieved.
   * @return int32: The team number of the client, or 0 if the client is invalid.
   */
  inline CSTeam GetClientTeam(int32_t playerSlot) {
    return __s2sdk_GetClientTeam(playerSlot);
  }

  using _SetClientTeam = void (*)(int32_t, CSTeam);
}
extern "C" PLUGIN_API s2sdk::_SetClientTeam __s2sdk_SetClientTeam;
namespace s2sdk {
  /**
   * @brief Sets the team number of an client.
   * @param playerSlot (int32): The index of the player's slot whose team number is to be set.
   * @param team (int32): The new team number to set for the client.
   */
  inline void SetClientTeam(int32_t playerSlot, CSTeam team) {
    return __s2sdk_SetClientTeam(playerSlot, team);
  }

  using _GetClientAbsOrigin = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientAbsOrigin __s2sdk_GetClientAbsOrigin;
namespace s2sdk {
  /**
   * @brief Retrieves the absolute origin of an client.
   * @param playerSlot (int32): The index of the player's slot whose absolute origin is to be retrieved.
   * @return vec3: A vector where the absolute origin will be stored.
   */
  inline plg::vec3 GetClientAbsOrigin(int32_t playerSlot) {
    return __s2sdk_GetClientAbsOrigin(playerSlot);
  }

  using _SetClientAbsOrigin = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetClientAbsOrigin __s2sdk_SetClientAbsOrigin;
namespace s2sdk {
  /**
   * @brief Sets the absolute origin of an client.
   * @param playerSlot (int32): The index of the player's slot whose absolute origin is to be set.
   * @param origin (vec3): The new absolute origin to set for the client.
   */
  inline void SetClientAbsOrigin(int32_t playerSlot, const plg::vec3& origin) {
    return __s2sdk_SetClientAbsOrigin(playerSlot, origin);
  }

  using _GetClientAbsScale = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientAbsScale __s2sdk_GetClientAbsScale;
namespace s2sdk {
  /**
   * @brief Retrieves the absolute scale of an client.
   * @param playerSlot (int32): The index of the player's slot whose absolute scale is to be retrieved.
   * @return float: A vector where the absolute scale will be stored.
   */
  inline float GetClientAbsScale(int32_t playerSlot) {
    return __s2sdk_GetClientAbsScale(playerSlot);
  }

  using _SetClientAbsScale = void (*)(int32_t, float);
}
extern "C" PLUGIN_API s2sdk::_SetClientAbsScale __s2sdk_SetClientAbsScale;
namespace s2sdk {
  /**
   * @brief Sets the absolute scale of an client.
   * @param playerSlot (int32): The index of the player's slot whose absolute scale is to be set.
   * @param scale (float): The new absolute scale to set for the client.
   */
  inline void SetClientAbsScale(int32_t playerSlot, float scale) {
    return __s2sdk_SetClientAbsScale(playerSlot, scale);
  }

  using _GetClientAbsAngles = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientAbsAngles __s2sdk_GetClientAbsAngles;
namespace s2sdk {
  /**
   * @brief Retrieves the angular rotation of an client.
   * @param playerSlot (int32): The index of the player's slot whose angular rotation is to be retrieved.
   * @return vec3: A QAngle where the angular rotation will be stored.
   */
  inline plg::vec3 GetClientAbsAngles(int32_t playerSlot) {
    return __s2sdk_GetClientAbsAngles(playerSlot);
  }

  using _SetClientAbsAngles = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetClientAbsAngles __s2sdk_SetClientAbsAngles;
namespace s2sdk {
  /**
   * @brief Sets the angular rotation of an client.
   * @param playerSlot (int32): The index of the player's slot whose angular rotation is to be set.
   * @param angle (vec3): The new angular rotation to set for the client.
   */
  inline void SetClientAbsAngles(int32_t playerSlot, const plg::vec3& angle) {
    return __s2sdk_SetClientAbsAngles(playerSlot, angle);
  }

  using _GetClientLocalOrigin = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientLocalOrigin __s2sdk_GetClientLocalOrigin;
namespace s2sdk {
  /**
   * @brief Retrieves the local origin of an client.
   * @param playerSlot (int32): The index of the player's slot whose local origin is to be retrieved.
   * @return vec3: A vector where the local origin will be stored.
   */
  inline plg::vec3 GetClientLocalOrigin(int32_t playerSlot) {
    return __s2sdk_GetClientLocalOrigin(playerSlot);
  }

  using _SetClientLocalOrigin = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetClientLocalOrigin __s2sdk_SetClientLocalOrigin;
namespace s2sdk {
  /**
   * @brief Sets the local origin of an client.
   * @param playerSlot (int32): The index of the player's slot whose local origin is to be set.
   * @param origin (vec3): The new local origin to set for the client.
   */
  inline void SetClientLocalOrigin(int32_t playerSlot, const plg::vec3& origin) {
    return __s2sdk_SetClientLocalOrigin(playerSlot, origin);
  }

  using _GetClientLocalScale = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientLocalScale __s2sdk_GetClientLocalScale;
namespace s2sdk {
  /**
   * @brief Retrieves the local scale of an client.
   * @param playerSlot (int32): The index of the player's slot whose local scale is to be retrieved.
   * @return float: A vector where the local scale will be stored.
   */
  inline float GetClientLocalScale(int32_t playerSlot) {
    return __s2sdk_GetClientLocalScale(playerSlot);
  }

  using _SetClientLocalScale = void (*)(int32_t, float);
}
extern "C" PLUGIN_API s2sdk::_SetClientLocalScale __s2sdk_SetClientLocalScale;
namespace s2sdk {
  /**
   * @brief Sets the local scale of an client.
   * @param playerSlot (int32): The index of the player's slot whose local scale is to be set.
   * @param scale (float): The new local scale to set for the client.
   */
  inline void SetClientLocalScale(int32_t playerSlot, float scale) {
    return __s2sdk_SetClientLocalScale(playerSlot, scale);
  }

  using _GetClientLocalAngles = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientLocalAngles __s2sdk_GetClientLocalAngles;
namespace s2sdk {
  /**
   * @brief Retrieves the angular rotation of an client.
   * @param playerSlot (int32): The index of the player's slot whose angular rotation is to be retrieved.
   * @return vec3: A QAngle where the angular rotation will be stored.
   */
  inline plg::vec3 GetClientLocalAngles(int32_t playerSlot) {
    return __s2sdk_GetClientLocalAngles(playerSlot);
  }

  using _SetClientLocalAngles = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetClientLocalAngles __s2sdk_SetClientLocalAngles;
namespace s2sdk {
  /**
   * @brief Sets the angular rotation of an client.
   * @param playerSlot (int32): The index of the player's slot whose angular rotation is to be set.
   * @param angle (vec3): The new angular rotation to set for the client.
   */
  inline void SetClientLocalAngles(int32_t playerSlot, const plg::vec3& angle) {
    return __s2sdk_SetClientLocalAngles(playerSlot, angle);
  }

  using _GetClientAbsVelocity = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientAbsVelocity __s2sdk_GetClientAbsVelocity;
namespace s2sdk {
  /**
   * @brief Retrieves the absolute velocity of an client.
   * @param playerSlot (int32): The index of the player's slot whose absolute velocity is to be retrieved.
   * @return vec3: A vector where the absolute velocity will be stored.
   */
  inline plg::vec3 GetClientAbsVelocity(int32_t playerSlot) {
    return __s2sdk_GetClientAbsVelocity(playerSlot);
  }

  using _SetClientAbsVelocity = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetClientAbsVelocity __s2sdk_SetClientAbsVelocity;
namespace s2sdk {
  /**
   * @brief Sets the absolute velocity of an client.
   * @param playerSlot (int32): The index of the player's slot whose absolute velocity is to be set.
   * @param velocity (vec3): The new absolute velocity to set for the client.
   */
  inline void SetClientAbsVelocity(int32_t playerSlot, const plg::vec3& velocity) {
    return __s2sdk_SetClientAbsVelocity(playerSlot, velocity);
  }

  using _GetClientBaseVelocity = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientBaseVelocity __s2sdk_GetClientBaseVelocity;
namespace s2sdk {
  /**
   * @brief Retrieves the base velocity of an client.
   * @param playerSlot (int32): The index of the player's slot whose base velocity is to be retrieved.
   * @return vec3: A vector where the base velocity will be stored.
   */
  inline plg::vec3 GetClientBaseVelocity(int32_t playerSlot) {
    return __s2sdk_GetClientBaseVelocity(playerSlot);
  }

  using _GetClientLocalAngVelocity = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientLocalAngVelocity __s2sdk_GetClientLocalAngVelocity;
namespace s2sdk {
  /**
   * @brief Retrieves the local angular velocity of an client.
   * @param playerSlot (int32): The index of the player's slot whose local angular velocity is to be retrieved.
   * @return vec3: A vector where the local angular velocity will be stored.
   */
  inline plg::vec3 GetClientLocalAngVelocity(int32_t playerSlot) {
    return __s2sdk_GetClientLocalAngVelocity(playerSlot);
  }

  using _GetClientAngVelocity = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientAngVelocity __s2sdk_GetClientAngVelocity;
namespace s2sdk {
  /**
   * @brief Retrieves the angular velocity of an client.
   * @param playerSlot (int32): The index of the player's slot whose angular velocity is to be retrieved.
   * @return vec3: A vector where the angular velocity will be stored.
   */
  inline plg::vec3 GetClientAngVelocity(int32_t playerSlot) {
    return __s2sdk_GetClientAngVelocity(playerSlot);
  }

  using _SetClientAngVelocity = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetClientAngVelocity __s2sdk_SetClientAngVelocity;
namespace s2sdk {
  /**
   * @brief Sets the angular velocity of an client.
   * @param playerSlot (int32): The index of the player's slot whose angular velocity is to be set.
   * @param velocity (vec3): The new angular velocity to set for the client.
   */
  inline void SetClientAngVelocity(int32_t playerSlot, const plg::vec3& velocity) {
    return __s2sdk_SetClientAngVelocity(playerSlot, velocity);
  }

  using _GetClientLocalVelocity = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientLocalVelocity __s2sdk_GetClientLocalVelocity;
namespace s2sdk {
  /**
   * @brief Retrieves the local velocity of an client.
   * @param playerSlot (int32): The index of the player's slot whose local velocity is to be retrieved.
   * @return vec3: A vector where the local velocity will be stored.
   */
  inline plg::vec3 GetClientLocalVelocity(int32_t playerSlot) {
    return __s2sdk_GetClientLocalVelocity(playerSlot);
  }

  using _GetClientAngRotation = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientAngRotation __s2sdk_GetClientAngRotation;
namespace s2sdk {
  /**
   * @brief Retrieves the angular rotation of an client.
   * @param playerSlot (int32): The index of the player's slot whose angular rotation is to be retrieved.
   * @return vec3: A vector where the angular rotation will be stored.
   */
  inline plg::vec3 GetClientAngRotation(int32_t playerSlot) {
    return __s2sdk_GetClientAngRotation(playerSlot);
  }

  using _SetClientAngRotation = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetClientAngRotation __s2sdk_SetClientAngRotation;
namespace s2sdk {
  /**
   * @brief Sets the angular rotation of an client.
   * @param playerSlot (int32): The index of the player's slot whose angular rotation is to be set.
   * @param rotation (vec3): The new angular rotation to set for the client.
   */
  inline void SetClientAngRotation(int32_t playerSlot, const plg::vec3& rotation) {
    return __s2sdk_SetClientAngRotation(playerSlot, rotation);
  }

  using _TransformPointClientToWorld = plg::vec3 (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_TransformPointClientToWorld __s2sdk_TransformPointClientToWorld;
namespace s2sdk {
  /**
   * @brief Returns the input Vector transformed from client to world space.
   * @param playerSlot (int32): The index of the player's slot
   * @param point (vec3): Point in client local space to transform
   * @return vec3: The point transformed to world space coordinates
   */
  inline plg::vec3 TransformPointClientToWorld(int32_t playerSlot, const plg::vec3& point) {
    return __s2sdk_TransformPointClientToWorld(playerSlot, point);
  }

  using _TransformPointWorldToClient = plg::vec3 (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_TransformPointWorldToClient __s2sdk_TransformPointWorldToClient;
namespace s2sdk {
  /**
   * @brief Returns the input Vector transformed from world to client space.
   * @param playerSlot (int32): The index of the player's slot
   * @param point (vec3): Point in world space to transform
   * @return vec3: The point transformed to client local space coordinates
   */
  inline plg::vec3 TransformPointWorldToClient(int32_t playerSlot, const plg::vec3& point) {
    return __s2sdk_TransformPointWorldToClient(playerSlot, point);
  }

  using _GetClientEyePosition = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientEyePosition __s2sdk_GetClientEyePosition;
namespace s2sdk {
  /**
   * @brief Get vector to eye position - absolute coords.
   * @param playerSlot (int32): The index of the player's slot
   * @return vec3: Eye position in absolute/world coordinates
   */
  inline plg::vec3 GetClientEyePosition(int32_t playerSlot) {
    return __s2sdk_GetClientEyePosition(playerSlot);
  }

  using _GetClientEyeAngles = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientEyeAngles __s2sdk_GetClientEyeAngles;
namespace s2sdk {
  /**
   * @brief Get the qangles that this client is looking at.
   * @param playerSlot (int32): The index of the player's slot
   * @return vec3: Eye angles as a vector (pitch, yaw, roll)
   */
  inline plg::vec3 GetClientEyeAngles(int32_t playerSlot) {
    return __s2sdk_GetClientEyeAngles(playerSlot);
  }

  using _SetClientForwardVector = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetClientForwardVector __s2sdk_SetClientForwardVector;
namespace s2sdk {
  /**
   * @brief Sets the forward velocity of an client.
   * @param playerSlot (int32): The index of the player's slot whose forward velocity is to be set.
   * @param forward (vec3)
   */
  inline void SetClientForwardVector(int32_t playerSlot, const plg::vec3& forward) {
    return __s2sdk_SetClientForwardVector(playerSlot, forward);
  }

  using _GetClientForwardVector = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientForwardVector __s2sdk_GetClientForwardVector;
namespace s2sdk {
  /**
   * @brief Get the forward vector of the client.
   * @param playerSlot (int32): The index of the player's slot to query
   * @return vec3: Forward-facing direction vector of the client
   */
  inline plg::vec3 GetClientForwardVector(int32_t playerSlot) {
    return __s2sdk_GetClientForwardVector(playerSlot);
  }

  using _GetClientLeftVector = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientLeftVector __s2sdk_GetClientLeftVector;
namespace s2sdk {
  /**
   * @brief Get the left vector of the client.
   * @param playerSlot (int32): The index of the player's slot to query
   * @return vec3: Left-facing direction vector of the client (aligned with the y axis)
   */
  inline plg::vec3 GetClientLeftVector(int32_t playerSlot) {
    return __s2sdk_GetClientLeftVector(playerSlot);
  }

  using _GetClientRightVector = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientRightVector __s2sdk_GetClientRightVector;
namespace s2sdk {
  /**
   * @brief Get the right vector of the client.
   * @param playerSlot (int32): The index of the player's slot to query
   * @return vec3: Right-facing direction vector of the client
   */
  inline plg::vec3 GetClientRightVector(int32_t playerSlot) {
    return __s2sdk_GetClientRightVector(playerSlot);
  }

  using _GetClientUpVector = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientUpVector __s2sdk_GetClientUpVector;
namespace s2sdk {
  /**
   * @brief Get the up vector of the client.
   * @param playerSlot (int32): The index of the player's slot to query
   * @return vec3: Up-facing direction vector of the client
   */
  inline plg::vec3 GetClientUpVector(int32_t playerSlot) {
    return __s2sdk_GetClientUpVector(playerSlot);
  }

  using _GetClientTransform = plg::mat4x4 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientTransform __s2sdk_GetClientTransform;
namespace s2sdk {
  /**
   * @brief Get the client-to-world transformation matrix.
   * @param playerSlot (int32): The index of the player's slot to query
   * @return mat4x4: 4x4 transformation matrix representing client's position, rotation, and scale in world space
   */
  inline plg::mat4x4 GetClientTransform(int32_t playerSlot) {
    return __s2sdk_GetClientTransform(playerSlot);
  }

  using _GetClientModel = plg::string (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientModel __s2sdk_GetClientModel;
namespace s2sdk {
  /**
   * @brief Retrieves the model name of an client.
   * @param playerSlot (int32): The index of the player's slot whose model name is to be retrieved.
   * @return string: A string where the model name will be stored.
   */
  inline plg::string GetClientModel(int32_t playerSlot) {
    return __s2sdk_GetClientModel(playerSlot);
  }

  using _SetClientModel = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetClientModel __s2sdk_SetClientModel;
namespace s2sdk {
  /**
   * @brief Sets the model name of an client.
   * @param playerSlot (int32): The index of the player's slot whose model name is to be set.
   * @param model (string): The new model name to set for the client.
   */
  inline void SetClientModel(int32_t playerSlot, const plg::string& model) {
    return __s2sdk_SetClientModel(playerSlot, model);
  }

  using _GetClientWaterLevel = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientWaterLevel __s2sdk_GetClientWaterLevel;
namespace s2sdk {
  /**
   * @brief Retrieves the water level of an client.
   * @param playerSlot (int32): The index of the player's slot whose water level is to be retrieved.
   * @return float: The water level of the client, or 0.0f if the client is invalid.
   */
  inline float GetClientWaterLevel(int32_t playerSlot) {
    return __s2sdk_GetClientWaterLevel(playerSlot);
  }

  using _GetClientGroundEntity = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientGroundEntity __s2sdk_GetClientGroundEntity;
namespace s2sdk {
  /**
   * @brief Retrieves the ground client of an client.
   * @param playerSlot (int32): The index of the player's slot whose ground client is to be retrieved.
   * @return int32: The handle of the ground client, or INVALID_EHANDLE_INDEX if the client is invalid.
   */
  inline int32_t GetClientGroundEntity(int32_t playerSlot) {
    return __s2sdk_GetClientGroundEntity(playerSlot);
  }

  using _GetClientEffects = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientEffects __s2sdk_GetClientEffects;
namespace s2sdk {
  /**
   * @brief Retrieves the effects of an client.
   * @param playerSlot (int32): The index of the player's slot whose effects are to be retrieved.
   * @return int32: The effect flags of the client, or 0 if the client is invalid.
   */
  inline int32_t GetClientEffects(int32_t playerSlot) {
    return __s2sdk_GetClientEffects(playerSlot);
  }

  using _AddClientEffects = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_AddClientEffects __s2sdk_AddClientEffects;
namespace s2sdk {
  /**
   * @brief Adds the render effect flag to an client.
   * @param playerSlot (int32): The index of the player's slot to modify
   * @param effects (int32): Render effect flags to add
   */
  inline void AddClientEffects(int32_t playerSlot, int32_t effects) {
    return __s2sdk_AddClientEffects(playerSlot, effects);
  }

  using _RemoveClientEffects = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_RemoveClientEffects __s2sdk_RemoveClientEffects;
namespace s2sdk {
  /**
   * @brief Removes the render effect flag from an client.
   * @param playerSlot (int32): The index of the player's slot to modify
   * @param effects (int32): Render effect flags to remove
   */
  inline void RemoveClientEffects(int32_t playerSlot, int32_t effects) {
    return __s2sdk_RemoveClientEffects(playerSlot, effects);
  }

  using _GetClientBoundingMaxs = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientBoundingMaxs __s2sdk_GetClientBoundingMaxs;
namespace s2sdk {
  /**
   * @brief Get a vector containing max bounds, centered on object.
   * @param playerSlot (int32): The index of the player's slot to query
   * @return vec3: Vector containing the maximum bounds of the client's bounding box
   */
  inline plg::vec3 GetClientBoundingMaxs(int32_t playerSlot) {
    return __s2sdk_GetClientBoundingMaxs(playerSlot);
  }

  using _GetClientBoundingMins = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientBoundingMins __s2sdk_GetClientBoundingMins;
namespace s2sdk {
  /**
   * @brief Get a vector containing min bounds, centered on object.
   * @param playerSlot (int32): The index of the player's slot to query
   * @return vec3: Vector containing the minimum bounds of the client's bounding box
   */
  inline plg::vec3 GetClientBoundingMins(int32_t playerSlot) {
    return __s2sdk_GetClientBoundingMins(playerSlot);
  }

  using _GetClientCenter = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientCenter __s2sdk_GetClientCenter;
namespace s2sdk {
  /**
   * @brief Get vector to center of object - absolute coords.
   * @param playerSlot (int32): The index of the player's slot to query
   * @return vec3: Vector pointing to the center of the client in absolute/world coordinates
   */
  inline plg::vec3 GetClientCenter(int32_t playerSlot) {
    return __s2sdk_GetClientCenter(playerSlot);
  }

  using _TeleportClient = void (*)(int32_t, const plg::vec3&, const plg::vec3&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_TeleportClient __s2sdk_TeleportClient;
namespace s2sdk {
  /**
   * @brief Teleports an client to a specified location and orientation.
   * @param playerSlot (int32): The index of the player's slot to teleport.
   * @param origin (vec3): A pointer to a Vector representing the new absolute position. Use nan vector to not set.
   * @param angles (vec3): A pointer to a QAngle representing the new orientation. Use nan vector to not set.
   * @param velocity (vec3): A pointer to a Vector representing the new velocity. Use nan vector to not set.
   */
  inline void TeleportClient(int32_t playerSlot, const plg::vec3& origin, const plg::vec3& angles, const plg::vec3& velocity) {
    return __s2sdk_TeleportClient(playerSlot, origin, angles, velocity);
  }

  using _ApplyAbsVelocityImpulseToClient = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_ApplyAbsVelocityImpulseToClient __s2sdk_ApplyAbsVelocityImpulseToClient;
namespace s2sdk {
  /**
   * @brief Apply an absolute velocity impulse to an client.
   * @param playerSlot (int32): The index of the player's slot to apply impulse to
   * @param vecImpulse (vec3): Velocity impulse vector to apply
   */
  inline void ApplyAbsVelocityImpulseToClient(int32_t playerSlot, const plg::vec3& vecImpulse) {
    return __s2sdk_ApplyAbsVelocityImpulseToClient(playerSlot, vecImpulse);
  }

  using _ApplyLocalAngularVelocityImpulseToClient = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_ApplyLocalAngularVelocityImpulseToClient __s2sdk_ApplyLocalAngularVelocityImpulseToClient;
namespace s2sdk {
  /**
   * @brief Apply a local angular velocity impulse to an client.
   * @param playerSlot (int32): The index of the player's slot to apply impulse to
   * @param angImpulse (vec3): Angular velocity impulse vector to apply
   */
  inline void ApplyLocalAngularVelocityImpulseToClient(int32_t playerSlot, const plg::vec3& angImpulse) {
    return __s2sdk_ApplyLocalAngularVelocityImpulseToClient(playerSlot, angImpulse);
  }

  using _AcceptClientInput = void (*)(int32_t, const plg::string&, int32_t, int32_t, const plg::any&, FieldType, int32_t);
}
extern "C" PLUGIN_API s2sdk::_AcceptClientInput __s2sdk_AcceptClientInput;
namespace s2sdk {
  /**
   * @brief Invokes a named input method on a specified client.
   * @param playerSlot (int32): The handle of the target client that will receive the input.
   * @param inputName (string): The name of the input action to invoke.
   * @param activatorHandle (int32): The index of the player's slot that initiated the sequence of actions.
   * @param callerHandle (int32): The index of the player's slot sending this event. Use -1 to specify
   * @param value (any): The value associated with the input action.
   * @param type (int32): The type or classification of the value.
   * @param outputId (int32): An identifier for tracking the output of this operation.
   */
  inline void AcceptClientInput(int32_t playerSlot, const plg::string& inputName, int32_t activatorHandle, int32_t callerHandle, const plg::any& value, FieldType type, int32_t outputId) {
    return __s2sdk_AcceptClientInput(playerSlot, inputName, activatorHandle, callerHandle, value, type, outputId);
  }

  using _ConnectClientOutput = void (*)(int32_t, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_ConnectClientOutput __s2sdk_ConnectClientOutput;
namespace s2sdk {
  /**
   * @brief Connects a script function to an player output.
   * @param playerSlot (int32): The handle of the player.
   * @param output (string): The name of the output to connect to.
   * @param functionName (string): The name of the script function to call.
   */
  inline void ConnectClientOutput(int32_t playerSlot, const plg::string& output, const plg::string& functionName) {
    return __s2sdk_ConnectClientOutput(playerSlot, output, functionName);
  }

  using _DisconnectClientOutput = void (*)(int32_t, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_DisconnectClientOutput __s2sdk_DisconnectClientOutput;
namespace s2sdk {
  /**
   * @brief Disconnects a script function from an player output.
   * @param playerSlot (int32): The handle of the player.
   * @param output (string): The name of the output.
   * @param functionName (string): The name of the script function to disconnect.
   */
  inline void DisconnectClientOutput(int32_t playerSlot, const plg::string& output, const plg::string& functionName) {
    return __s2sdk_DisconnectClientOutput(playerSlot, output, functionName);
  }

  using _DisconnectClientRedirectedOutput = void (*)(int32_t, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_DisconnectClientRedirectedOutput __s2sdk_DisconnectClientRedirectedOutput;
namespace s2sdk {
  /**
   * @brief Disconnects a script function from an I/O event on a different player.
   * @param playerSlot (int32): The handle of the calling player.
   * @param output (string): The name of the output.
   * @param functionName (string): The function name to disconnect.
   * @param targetHandle (int32): The handle of the entity whose output is being disconnected.
   */
  inline void DisconnectClientRedirectedOutput(int32_t playerSlot, const plg::string& output, const plg::string& functionName, int32_t targetHandle) {
    return __s2sdk_DisconnectClientRedirectedOutput(playerSlot, output, functionName, targetHandle);
  }

  using _FireClientOutput = void (*)(int32_t, const plg::string&, int32_t, int32_t, const plg::any&, FieldType, float);
}
extern "C" PLUGIN_API s2sdk::_FireClientOutput __s2sdk_FireClientOutput;
namespace s2sdk {
  /**
   * @brief Fires an player output.
   * @param playerSlot (int32): The handle of the player firing the output.
   * @param outputName (string): The name of the output to fire.
   * @param activatorHandle (int32): The entity activating the output.
   * @param callerHandle (int32): The entity that called the output.
   * @param value (any): The value associated with the input action.
   * @param type (int32): The type or classification of the value.
   * @param delay (float): Delay in seconds before firing the output.
   */
  inline void FireClientOutput(int32_t playerSlot, const plg::string& outputName, int32_t activatorHandle, int32_t callerHandle, const plg::any& value, FieldType type, float delay) {
    return __s2sdk_FireClientOutput(playerSlot, outputName, activatorHandle, callerHandle, value, type, delay);
  }

  using _RedirectClientOutput = void (*)(int32_t, const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_RedirectClientOutput __s2sdk_RedirectClientOutput;
namespace s2sdk {
  /**
   * @brief Redirects an player output to call a function on another player.
   * @param playerSlot (int32): The handle of the player whose output is being redirected.
   * @param output (string): The name of the output to redirect.
   * @param functionName (string): The function name to call on the target player.
   * @param targetHandle (int32): The handle of the entity that will receive the output call.
   */
  inline void RedirectClientOutput(int32_t playerSlot, const plg::string& output, const plg::string& functionName, int32_t targetHandle) {
    return __s2sdk_RedirectClientOutput(playerSlot, output, functionName, targetHandle);
  }

  using _FollowClient = void (*)(int32_t, int32_t, bool);
}
extern "C" PLUGIN_API s2sdk::_FollowClient __s2sdk_FollowClient;
namespace s2sdk {
  /**
   * @brief Makes an client follow another client with optional bone merging.
   * @param playerSlot (int32): The index of the player's slot that will follow
   * @param attachmentHandle (int32): The index of the player's slot to follow
   * @param boneMerge (bool): If true, bones will be merged between entities
   */
  inline void FollowClient(int32_t playerSlot, int32_t attachmentHandle, bool boneMerge) {
    return __s2sdk_FollowClient(playerSlot, attachmentHandle, boneMerge);
  }

  using _FollowClientMerge = void (*)(int32_t, int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_FollowClientMerge __s2sdk_FollowClientMerge;
namespace s2sdk {
  /**
   * @brief Makes an client follow another client and merge with a specific bone or attachment.
   * @param playerSlot (int32): The index of the player's slot that will follow
   * @param attachmentHandle (int32): The index of the player's slot to follow
   * @param boneOrAttachName (string): Name of the bone or attachment point to merge with
   */
  inline void FollowClientMerge(int32_t playerSlot, int32_t attachmentHandle, const plg::string& boneOrAttachName) {
    return __s2sdk_FollowClientMerge(playerSlot, attachmentHandle, boneOrAttachName);
  }

  using _TakeClientDamage = int32_t (*)(int32_t, int32_t, int32_t, const plg::vec3&, const plg::vec3&, float, DamageTypes);
}
extern "C" PLUGIN_API s2sdk::_TakeClientDamage __s2sdk_TakeClientDamage;
namespace s2sdk {
  /**
   * @brief Apply damage to an client.
   * @param playerSlot (int32): The index of the player's slot receiving damage
   * @param inflictorSlot (int32): The index of the player's slot inflicting damage (e.g., projectile)
   * @param attackerSlot (int32): The index of the attacking client
   * @param force (vec3): Direction and magnitude of force to apply
   * @param hitPos (vec3): Position where the damage hit occurred
   * @param damage (float): Amount of damage to apply
   * @param damageTypes (int32): Bitfield of damage type flags
   * @return int32: Amount of damage actually applied to the client
   */
  inline int32_t TakeClientDamage(int32_t playerSlot, int32_t inflictorSlot, int32_t attackerSlot, const plg::vec3& force, const plg::vec3& hitPos, float damage, DamageTypes damageTypes) {
    return __s2sdk_TakeClientDamage(playerSlot, inflictorSlot, attackerSlot, force, hitPos, damage, damageTypes);
  }

  using _GetClientPawn = void* (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientPawn __s2sdk_GetClientPawn;
namespace s2sdk {
  /**
   * @brief Retrieves the pawn entity pointer associated with a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @return ptr64: A pointer to the client's pawn entity, or nullptr if the client or controller is invalid.
   */
  inline void* GetClientPawn(int32_t playerSlot) {
    return __s2sdk_GetClientPawn(playerSlot);
  }

  using _ProcessTargetString = plg::vector<int32_t> (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_ProcessTargetString __s2sdk_ProcessTargetString;
namespace s2sdk {
  /**
   * @brief Processes the target string to determine if one user can target another.
   * @param caller (int32): The index of the player's slot making the target request.
   * @param target (string): The target string specifying the player or players to be targeted.
   * @return int32[]: A vector where the result of the targeting operation will be stored.
   */
  inline plg::vector<int32_t> ProcessTargetString(int32_t caller, const plg::string& target) {
    return __s2sdk_ProcessTargetString(caller, target);
  }

  using _SwitchClientTeam = void (*)(int32_t, CSTeam);
}
extern "C" PLUGIN_API s2sdk::_SwitchClientTeam __s2sdk_SwitchClientTeam;
namespace s2sdk {
  /**
   * @brief Switches the player's team.
   * @param playerSlot (int32): The index of the player's slot.
   * @param team (int32): The team index to switch the client to.
   */
  inline void SwitchClientTeam(int32_t playerSlot, CSTeam team) {
    return __s2sdk_SwitchClientTeam(playerSlot, team);
  }

  using _ChangeClientTeam = void (*)(int32_t, CSTeam);
}
extern "C" PLUGIN_API s2sdk::_ChangeClientTeam __s2sdk_ChangeClientTeam;
namespace s2sdk {
  /**
   * @brief Changes the player's team.
   * @param playerSlot (int32): The index of the player's slot.
   * @param team (int32): The team index to change the client to.
   */
  inline void ChangeClientTeam(int32_t playerSlot, CSTeam team) {
    return __s2sdk_ChangeClientTeam(playerSlot, team);
  }

  using _RespawnClient = void (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_RespawnClient __s2sdk_RespawnClient;
namespace s2sdk {
  /**
   * @brief Respawns a player.
   * @param playerSlot (int32): The index of the player's slot to respawn.
   */
  inline void RespawnClient(int32_t playerSlot) {
    return __s2sdk_RespawnClient(playerSlot);
  }

  using _ForcePlayerSuicide = void (*)(int32_t, bool, bool);
}
extern "C" PLUGIN_API s2sdk::_ForcePlayerSuicide __s2sdk_ForcePlayerSuicide;
namespace s2sdk {
  /**
   * @brief Forces a player to commit suicide.
   * @param playerSlot (int32): The index of the player's slot.
   * @param explode (bool): If true, the client will explode upon death.
   * @param force (bool): If true, the suicide will be forced.
   */
  inline void ForcePlayerSuicide(int32_t playerSlot, bool explode, bool force) {
    return __s2sdk_ForcePlayerSuicide(playerSlot, explode, force);
  }

  using _KickClient = void (*)(int32_t, NetworkDisconnectionReason, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_KickClient __s2sdk_KickClient;
namespace s2sdk {
  /**
   * @brief Disconnects a client from the server as soon as the next frame starts.
   * @param playerSlot (int32): The index of the player's slot to be kicked.
   * @param reason (int32): The network-level reason code describing why the client is being disconnected.
   * @param message (string): The optional internal diagnostic message. If empty, no message is passed to the engine.
   */
  inline void KickClient(int32_t playerSlot, NetworkDisconnectionReason reason, const plg::string& message) {
    return __s2sdk_KickClient(playerSlot, reason, message);
  }

  using _BanClient = void (*)(int32_t, float, bool);
}
extern "C" PLUGIN_API s2sdk::_BanClient __s2sdk_BanClient;
namespace s2sdk {
  /**
   * @brief Bans a client for a specified duration.
   * @param playerSlot (int32): The index of the player's slot to be banned.
   * @param duration (float): Duration of the ban in seconds.
   * @param kick (bool): If true, the client will be kicked immediately after being banned.
   */
  inline void BanClient(int32_t playerSlot, float duration, bool kick) {
    return __s2sdk_BanClient(playerSlot, duration, kick);
  }

  using _BanIdentity = void (*)(uint64_t, float, bool);
}
extern "C" PLUGIN_API s2sdk::_BanIdentity __s2sdk_BanIdentity;
namespace s2sdk {
  /**
   * @brief Bans an identity (either an IP address or a Steam authentication string).
   * @param steamId (uint64): The Steam ID to ban.
   * @param duration (float): Duration of the ban in seconds.
   * @param kick (bool): If true, the client will be kicked immediately after being banned.
   */
  inline void BanIdentity(uint64_t steamId, float duration, bool kick) {
    return __s2sdk_BanIdentity(steamId, duration, kick);
  }

  using _GetClientActiveWeapon = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientActiveWeapon __s2sdk_GetClientActiveWeapon;
namespace s2sdk {
  /**
   * @brief Retrieves the handle of the client's currently active weapon.
   * @param playerSlot (int32): The index of the player's slot.
   * @return int32: The entity handle of the active weapon, or INVALID_EHANDLE_INDEX if the client is invalid or has no active weapon.
   */
  inline int32_t GetClientActiveWeapon(int32_t playerSlot) {
    return __s2sdk_GetClientActiveWeapon(playerSlot);
  }

  using _GetClientWeapons = plg::vector<int32_t> (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientWeapons __s2sdk_GetClientWeapons;
namespace s2sdk {
  /**
   * @brief Retrieves a list of weapon handles owned by the client.
   * @param playerSlot (int32): The index of the player's slot.
   * @return int32[]: A vector of entity handles for the client's weapons, or an empty vector if the client is invalid or has no weapons.
   */
  inline plg::vector<int32_t> GetClientWeapons(int32_t playerSlot) {
    return __s2sdk_GetClientWeapons(playerSlot);
  }

  using _RemoveWeapons = void (*)(int32_t, bool);
}
extern "C" PLUGIN_API s2sdk::_RemoveWeapons __s2sdk_RemoveWeapons;
namespace s2sdk {
  /**
   * @brief Removes all weapons from a client, with an option to remove the suit as well.
   * @param playerSlot (int32): The index of the player's slot.
   * @param removeSuit (bool): A boolean indicating whether to also remove the client's suit.
   */
  inline void RemoveWeapons(int32_t playerSlot, bool removeSuit) {
    return __s2sdk_RemoveWeapons(playerSlot, removeSuit);
  }

  using _DropWeapon = void (*)(int32_t, int32_t, const plg::vec3&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_DropWeapon __s2sdk_DropWeapon;
namespace s2sdk {
  /**
   * @brief Forces a player to drop their weapon.
   * @param playerSlot (int32): The index of the player's slot.
   * @param weaponHandle (int32): The handle of weapon to drop.
   * @param target (vec3): Target direction.
   * @param velocity (vec3): Velocity to toss weapon or zero to just drop weapon.
   */
  inline void DropWeapon(int32_t playerSlot, int32_t weaponHandle, const plg::vec3& target, const plg::vec3& velocity) {
    return __s2sdk_DropWeapon(playerSlot, weaponHandle, target, velocity);
  }

  using _SelectWeapon = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SelectWeapon __s2sdk_SelectWeapon;
namespace s2sdk {
  /**
   * @brief Selects a player's weapon.
   * @param playerSlot (int32): The index of the player's slot.
   * @param weaponHandle (int32): The handle of weapon to bump.
   */
  inline void SelectWeapon(int32_t playerSlot, int32_t weaponHandle) {
    return __s2sdk_SelectWeapon(playerSlot, weaponHandle);
  }

  using _SwitchWeapon = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SwitchWeapon __s2sdk_SwitchWeapon;
namespace s2sdk {
  /**
   * @brief Switches a player's weapon.
   * @param playerSlot (int32): The index of the player's slot.
   * @param weaponHandle (int32): The handle of weapon to switch.
   */
  inline void SwitchWeapon(int32_t playerSlot, int32_t weaponHandle) {
    return __s2sdk_SwitchWeapon(playerSlot, weaponHandle);
  }

  using _RemoveWeapon = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_RemoveWeapon __s2sdk_RemoveWeapon;
namespace s2sdk {
  /**
   * @brief Removes a player's weapon.
   * @param playerSlot (int32): The index of the player's slot.
   * @param weaponHandle (int32): The handle of weapon to remove.
   */
  inline void RemoveWeapon(int32_t playerSlot, int32_t weaponHandle) {
    return __s2sdk_RemoveWeapon(playerSlot, weaponHandle);
  }

  using _GiveNamedItem = int32_t (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GiveNamedItem __s2sdk_GiveNamedItem;
namespace s2sdk {
  /**
   * @brief Gives a named item (e.g., weapon) to a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @param itemName (string): The name of the item to give.
   * @return int32: The entity handle of the created item, or INVALID_EHANDLE_INDEX if the client or item is invalid.
   */
  inline int32_t GiveNamedItem(int32_t playerSlot, const plg::string& itemName) {
    return __s2sdk_GiveNamedItem(playerSlot, itemName);
  }

  using _GetClientButtons = uint64_t (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientButtons __s2sdk_GetClientButtons;
namespace s2sdk {
  /**
   * @brief Retrieves the state of a specific button for a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @param buttonIndex (int32): The index of the button (0-2).
   * @return uint64: uint64_t The state of the specified button, or 0 if the client or button index is invalid.
   */
  inline uint64_t GetClientButtons(int32_t playerSlot, int32_t buttonIndex) {
    return __s2sdk_GetClientButtons(playerSlot, buttonIndex);
  }

  using _GetClientArmor = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientArmor __s2sdk_GetClientArmor;
namespace s2sdk {
  /**
   * @brief Returns the client's armor value.
   * @param playerSlot (int32): The index of the player's slot.
   * @return int32: The armor value of the client.
   */
  inline int32_t GetClientArmor(int32_t playerSlot) {
    return __s2sdk_GetClientArmor(playerSlot);
  }

  using _SetClientArmor = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetClientArmor __s2sdk_SetClientArmor;
namespace s2sdk {
  /**
   * @brief Sets the client's armor value.
   * @param playerSlot (int32): The index of the player's slot.
   * @param armor (int32): The armor value to set.
   */
  inline void SetClientArmor(int32_t playerSlot, int32_t armor) {
    return __s2sdk_SetClientArmor(playerSlot, armor);
  }

  using _GetClientSpeed = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientSpeed __s2sdk_GetClientSpeed;
namespace s2sdk {
  /**
   * @brief Returns the client's speed value.
   * @param playerSlot (int32): The index of the player's slot.
   * @return float: The speed value of the client.
   */
  inline float GetClientSpeed(int32_t playerSlot) {
    return __s2sdk_GetClientSpeed(playerSlot);
  }

  using _SetClientSpeed = void (*)(int32_t, float);
}
extern "C" PLUGIN_API s2sdk::_SetClientSpeed __s2sdk_SetClientSpeed;
namespace s2sdk {
  /**
   * @brief Sets the client's speed value.
   * @param playerSlot (int32): The index of the player's slot.
   * @param speed (float): The speed value to set.
   */
  inline void SetClientSpeed(int32_t playerSlot, float speed) {
    return __s2sdk_SetClientSpeed(playerSlot, speed);
  }

  using _GetClientMoney = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientMoney __s2sdk_GetClientMoney;
namespace s2sdk {
  /**
   * @brief Retrieves the amount of money a client has.
   * @param playerSlot (int32): The index of the player's slot.
   * @return int32: The amount of money the client has, or 0 if the player slot is invalid.
   */
  inline int32_t GetClientMoney(int32_t playerSlot) {
    return __s2sdk_GetClientMoney(playerSlot);
  }

  using _SetClientMoney = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetClientMoney __s2sdk_SetClientMoney;
namespace s2sdk {
  /**
   * @brief Sets the amount of money for a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @param money (int32): The amount of money to set.
   */
  inline void SetClientMoney(int32_t playerSlot, int32_t money) {
    return __s2sdk_SetClientMoney(playerSlot, money);
  }

  using _GetClientKills = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientKills __s2sdk_GetClientKills;
namespace s2sdk {
  /**
   * @brief Retrieves the number of kills for a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @return int32: The number of kills the client has, or 0 if the player slot is invalid.
   */
  inline int32_t GetClientKills(int32_t playerSlot) {
    return __s2sdk_GetClientKills(playerSlot);
  }

  using _SetClientKills = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetClientKills __s2sdk_SetClientKills;
namespace s2sdk {
  /**
   * @brief Sets the number of kills for a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @param kills (int32): The number of kills to set.
   */
  inline void SetClientKills(int32_t playerSlot, int32_t kills) {
    return __s2sdk_SetClientKills(playerSlot, kills);
  }

  using _GetClientDeaths = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientDeaths __s2sdk_GetClientDeaths;
namespace s2sdk {
  /**
   * @brief Retrieves the number of deaths for a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @return int32: The number of deaths the client has, or 0 if the player slot is invalid.
   */
  inline int32_t GetClientDeaths(int32_t playerSlot) {
    return __s2sdk_GetClientDeaths(playerSlot);
  }

  using _SetClientDeaths = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetClientDeaths __s2sdk_SetClientDeaths;
namespace s2sdk {
  /**
   * @brief Sets the number of deaths for a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @param deaths (int32): The number of deaths to set.
   */
  inline void SetClientDeaths(int32_t playerSlot, int32_t deaths) {
    return __s2sdk_SetClientDeaths(playerSlot, deaths);
  }

  using _GetClientAssists = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientAssists __s2sdk_GetClientAssists;
namespace s2sdk {
  /**
   * @brief Retrieves the number of assists for a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @return int32: The number of assists the client has, or 0 if the player slot is invalid.
   */
  inline int32_t GetClientAssists(int32_t playerSlot) {
    return __s2sdk_GetClientAssists(playerSlot);
  }

  using _SetClientAssists = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetClientAssists __s2sdk_SetClientAssists;
namespace s2sdk {
  /**
   * @brief Sets the number of assists for a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @param assists (int32): The number of assists to set.
   */
  inline void SetClientAssists(int32_t playerSlot, int32_t assists) {
    return __s2sdk_SetClientAssists(playerSlot, assists);
  }

  using _GetClientDamage = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetClientDamage __s2sdk_GetClientDamage;
namespace s2sdk {
  /**
   * @brief Retrieves the total damage dealt by a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @return int32: The total damage dealt by the client, or 0 if the player slot is invalid.
   */
  inline int32_t GetClientDamage(int32_t playerSlot) {
    return __s2sdk_GetClientDamage(playerSlot);
  }

  using _SetClientDamage = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetClientDamage __s2sdk_SetClientDamage;
namespace s2sdk {
  /**
   * @brief Sets the total damage dealt by a client.
   * @param playerSlot (int32): The index of the player's slot.
   * @param damage (int32): The amount of damage to set.
   */
  inline void SetClientDamage(int32_t playerSlot, int32_t damage) {
    return __s2sdk_SetClientDamage(playerSlot, damage);
  }

} // namespace s2sdk
