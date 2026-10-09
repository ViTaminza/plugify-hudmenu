#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: transmit)

namespace s2sdk {

  using _SetTransmitInfoEntity = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetTransmitInfoEntity __s2sdk_SetTransmitInfoEntity;
namespace s2sdk {
  /**
   * @brief Sets a bit in the TransmitEntity bitvec, marking an entity as transmittable.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param entityHandle (int32): The handle of the entity to mark as transmittable.
   */
  inline void SetTransmitInfoEntity(void* info, int32_t entityHandle) {
    return __s2sdk_SetTransmitInfoEntity(info, entityHandle);
  }

  using _ClearTransmitInfoEntity = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_ClearTransmitInfoEntity __s2sdk_ClearTransmitInfoEntity;
namespace s2sdk {
  /**
   * @brief Clears a bit in the TransmitEntity bitvec, marking an entity as not transmittable.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param entityHandle (int32): The handle of the entity to mark as not transmittable.
   */
  inline void ClearTransmitInfoEntity(void* info, int32_t entityHandle) {
    return __s2sdk_ClearTransmitInfoEntity(info, entityHandle);
  }

  using _IsTransmitInfoEntitySet = bool (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsTransmitInfoEntitySet __s2sdk_IsTransmitInfoEntitySet;
namespace s2sdk {
  /**
   * @brief Checks if a bit is set in the TransmitEntity bitvec.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param entityHandle (int32): The handle of the entity to check.
   * @return bool: True if the entity is marked as transmittable, false otherwise.
   */
  inline bool IsTransmitInfoEntitySet(void* info, int32_t entityHandle) {
    return __s2sdk_IsTransmitInfoEntitySet(info, entityHandle);
  }

  using _SetTransmitInfoEntityAll = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_SetTransmitInfoEntityAll __s2sdk_SetTransmitInfoEntityAll;
namespace s2sdk {
  /**
   * @brief Sets all bits in the TransmitEntity bitvec, marking all entities as transmittable.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   */
  inline void SetTransmitInfoEntityAll(void* info) {
    return __s2sdk_SetTransmitInfoEntityAll(info);
  }

  using _ClearTransmitInfoEntityAll = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_ClearTransmitInfoEntityAll __s2sdk_ClearTransmitInfoEntityAll;
namespace s2sdk {
  /**
   * @brief Clears all bits in the TransmitEntity bitvec, marking all entities as not transmittable.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   */
  inline void ClearTransmitInfoEntityAll(void* info) {
    return __s2sdk_ClearTransmitInfoEntityAll(info);
  }

  using _SetTransmitInfoNonPlayer = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetTransmitInfoNonPlayer __s2sdk_SetTransmitInfoNonPlayer;
namespace s2sdk {
  /**
   * @brief Sets a bit in the TransmitNonPlayers bitvec, marking a non-player entity as transmittable.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param entityHandle (int32): The index of the non-player entity to mark as transmittable.
   */
  inline void SetTransmitInfoNonPlayer(void* info, int32_t entityHandle) {
    return __s2sdk_SetTransmitInfoNonPlayer(info, entityHandle);
  }

  using _ClearTransmitInfoNonPlayer = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_ClearTransmitInfoNonPlayer __s2sdk_ClearTransmitInfoNonPlayer;
namespace s2sdk {
  /**
   * @brief Clears a bit in the TransmitNonPlayers bitvec, marking a non-player entity as not transmittable.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param entityHandle (int32): The index of the non-player entity to mark as not transmittable.
   */
  inline void ClearTransmitInfoNonPlayer(void* info, int32_t entityHandle) {
    return __s2sdk_ClearTransmitInfoNonPlayer(info, entityHandle);
  }

  using _IsTransmitInfoNonPlayerSet = bool (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsTransmitInfoNonPlayerSet __s2sdk_IsTransmitInfoNonPlayerSet;
namespace s2sdk {
  /**
   * @brief Checks if a bit is set in the TransmitNonPlayers bitvec.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param entityHandle (int32): The index of the non-player entity to check.
   * @return bool: True if the entity is marked as transmittable, false otherwise.
   */
  inline bool IsTransmitInfoNonPlayerSet(void* info, int32_t entityHandle) {
    return __s2sdk_IsTransmitInfoNonPlayerSet(info, entityHandle);
  }

  using _SetTransmitInfoNonPlayerAll = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_SetTransmitInfoNonPlayerAll __s2sdk_SetTransmitInfoNonPlayerAll;
namespace s2sdk {
  /**
   * @brief Sets all bits in the TransmitNonPlayers bitvec, marking all non-player entities as transmittable.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   */
  inline void SetTransmitInfoNonPlayerAll(void* info) {
    return __s2sdk_SetTransmitInfoNonPlayerAll(info);
  }

  using _ClearTransmitInfoNonPlayerAll = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_ClearTransmitInfoNonPlayerAll __s2sdk_ClearTransmitInfoNonPlayerAll;
namespace s2sdk {
  /**
   * @brief Clears all bits in the TransmitNonPlayers bitvec, marking all non-player entities as not transmittable.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   */
  inline void ClearTransmitInfoNonPlayerAll(void* info) {
    return __s2sdk_ClearTransmitInfoNonPlayerAll(info);
  }

  using _SetTransmitInfoOutOfPVS = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetTransmitInfoOutOfPVS __s2sdk_SetTransmitInfoOutOfPVS;
namespace s2sdk {
  /**
   * @brief Sets a bit in the TransmitOutOfPVS bitvec, marking an entity to always transmit.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param entityHandle (int32): The handle of the entity to mark as always transmittable.
   */
  inline void SetTransmitInfoOutOfPVS(void* info, int32_t entityHandle) {
    return __s2sdk_SetTransmitInfoOutOfPVS(info, entityHandle);
  }

  using _ClearTransmitInfoOutOfPVS = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_ClearTransmitInfoOutOfPVS __s2sdk_ClearTransmitInfoOutOfPVS;
namespace s2sdk {
  /**
   * @brief Clears a bit in the TransmitOutOfPVS bitvec, unmarking an entity from always transmit.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param entityHandle (int32): The handle of the entity to unmark from always transmit.
   */
  inline void ClearTransmitInfoOutOfPVS(void* info, int32_t entityHandle) {
    return __s2sdk_ClearTransmitInfoOutOfPVS(info, entityHandle);
  }

  using _IsTransmitInfoOutOfPVSSet = bool (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsTransmitInfoOutOfPVSSet __s2sdk_IsTransmitInfoOutOfPVSSet;
namespace s2sdk {
  /**
   * @brief Checks if a bit is set in the TransmitOutOfPVS bitvec.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param entityHandle (int32): The handle of the entity to check.
   * @return bool: True if the entity is marked to always transmit, false otherwise.
   */
  inline bool IsTransmitInfoOutOfPVSSet(void* info, int32_t entityHandle) {
    return __s2sdk_IsTransmitInfoOutOfPVSSet(info, entityHandle);
  }

  using _SetTransmitInfoOutOfPVSAll = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_SetTransmitInfoOutOfPVSAll __s2sdk_SetTransmitInfoOutOfPVSAll;
namespace s2sdk {
  /**
   * @brief Sets all bits in the TransmitOutOfPVS bitvec, marking all entities to always transmit.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   */
  inline void SetTransmitInfoOutOfPVSAll(void* info) {
    return __s2sdk_SetTransmitInfoOutOfPVSAll(info);
  }

  using _ClearTransmitInfoOutOfPVSAll = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_ClearTransmitInfoOutOfPVSAll __s2sdk_ClearTransmitInfoOutOfPVSAll;
namespace s2sdk {
  /**
   * @brief Clears all bits in the TransmitOutOfPVS bitvec, unmarking all entities from always transmit.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   */
  inline void ClearTransmitInfoOutOfPVSAll(void* info) {
    return __s2sdk_ClearTransmitInfoOutOfPVSAll(info);
  }

  using _SetTransmitInfoAlways = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetTransmitInfoAlways __s2sdk_SetTransmitInfoAlways;
namespace s2sdk {
  /**
   * @brief Sets a bit in the TransmitAlways bitvec, marking an entity to always transmit.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param entityHandle (int32): The handle of the entity to mark as always transmittable.
   */
  inline void SetTransmitInfoAlways(void* info, int32_t entityHandle) {
    return __s2sdk_SetTransmitInfoAlways(info, entityHandle);
  }

  using _ClearTransmitInfoAlways = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_ClearTransmitInfoAlways __s2sdk_ClearTransmitInfoAlways;
namespace s2sdk {
  /**
   * @brief Clears a bit in the TransmitAlways bitvec, unmarking an entity from always transmit.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param entityHandle (int32): The handle of the entity to unmark from always transmit.
   */
  inline void ClearTransmitInfoAlways(void* info, int32_t entityHandle) {
    return __s2sdk_ClearTransmitInfoAlways(info, entityHandle);
  }

  using _IsTransmitInfoAlwaysSet = bool (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsTransmitInfoAlwaysSet __s2sdk_IsTransmitInfoAlwaysSet;
namespace s2sdk {
  /**
   * @brief Checks if a bit is set in the TransmitAlways bitvec.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param entityHandle (int32): The handle of the entity to check.
   * @return bool: True if the entity is marked to always transmit, false otherwise.
   */
  inline bool IsTransmitInfoAlwaysSet(void* info, int32_t entityHandle) {
    return __s2sdk_IsTransmitInfoAlwaysSet(info, entityHandle);
  }

  using _SetTransmitInfoAlwaysAll = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_SetTransmitInfoAlwaysAll __s2sdk_SetTransmitInfoAlwaysAll;
namespace s2sdk {
  /**
   * @brief Sets all bits in the TransmitAlways bitvec, marking all entities to always transmit.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   */
  inline void SetTransmitInfoAlwaysAll(void* info) {
    return __s2sdk_SetTransmitInfoAlwaysAll(info);
  }

  using _ClearTransmitInfoAlwaysAll = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_ClearTransmitInfoAlwaysAll __s2sdk_ClearTransmitInfoAlwaysAll;
namespace s2sdk {
  /**
   * @brief Clears all bits in the TransmitAlways bitvec, unmarking all entities from always transmit.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   */
  inline void ClearTransmitInfoAlwaysAll(void* info) {
    return __s2sdk_ClearTransmitInfoAlwaysAll(info);
  }

  using _GetTransmitInfoTargetSlotsCount = int32_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_GetTransmitInfoTargetSlotsCount __s2sdk_GetTransmitInfoTargetSlotsCount;
namespace s2sdk {
  /**
   * @brief Gets the count of target player slots.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @return int32: The number of target player slots, or 0 if the info pointer is null.
   */
  inline int32_t GetTransmitInfoTargetSlotsCount(void* info) {
    return __s2sdk_GetTransmitInfoTargetSlotsCount(info);
  }

  using _GetTransmitInfoTargetSlot = int32_t (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetTransmitInfoTargetSlot __s2sdk_GetTransmitInfoTargetSlot;
namespace s2sdk {
  /**
   * @brief Gets a player slot value at a specific index in the target slots vector.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param index (int32): The index in the target slots vector.
   * @return int32: The player slot value, or -1 if the index is invalid or info is null.
   */
  inline int32_t GetTransmitInfoTargetSlot(void* info, int32_t index) {
    return __s2sdk_GetTransmitInfoTargetSlot(info, index);
  }

  using _AddTransmitInfoTargetSlot = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_AddTransmitInfoTargetSlot __s2sdk_AddTransmitInfoTargetSlot;
namespace s2sdk {
  /**
   * @brief Adds a player slot to the target slots vector.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param playerSlot (int32): The player slot value to add.
   */
  inline void AddTransmitInfoTargetSlot(void* info, int32_t playerSlot) {
    return __s2sdk_AddTransmitInfoTargetSlot(info, playerSlot);
  }

  using _RemoveTransmitInfoTargetSlot = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_RemoveTransmitInfoTargetSlot __s2sdk_RemoveTransmitInfoTargetSlot;
namespace s2sdk {
  /**
   * @brief Removes a player slot from the target slots vector.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param index (int32): Index within the target slots vector to remove.
   */
  inline void RemoveTransmitInfoTargetSlot(void* info, int32_t index) {
    return __s2sdk_RemoveTransmitInfoTargetSlot(info, index);
  }

  using _GetTransmitInfoTargetSlotsAll = plg::vector<int32_t> (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_GetTransmitInfoTargetSlotsAll __s2sdk_GetTransmitInfoTargetSlotsAll;
namespace s2sdk {
  /**
   * @brief Gets the target slots vector.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @return int32[]: The player slots array.
   */
  inline plg::vector<int32_t> GetTransmitInfoTargetSlotsAll(void* info) {
    return __s2sdk_GetTransmitInfoTargetSlotsAll(info);
  }

  using _RemoveTransmitInfoTargetSlotsAll = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_RemoveTransmitInfoTargetSlotsAll __s2sdk_RemoveTransmitInfoTargetSlotsAll;
namespace s2sdk {
  /**
   * @brief Clears all target player slots from the vector.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   */
  inline void RemoveTransmitInfoTargetSlotsAll(void* info) {
    return __s2sdk_RemoveTransmitInfoTargetSlotsAll(info);
  }

  using _GetTransmitInfoPlayerSlot = int32_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_GetTransmitInfoPlayerSlot __s2sdk_GetTransmitInfoPlayerSlot;
namespace s2sdk {
  /**
   * @brief Gets the player slot value from the CCheckTransmitInfo.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @return int32: The player slot value, or -1 if info is null.
   */
  inline int32_t GetTransmitInfoPlayerSlot(void* info) {
    return __s2sdk_GetTransmitInfoPlayerSlot(info);
  }

  using _SetTransmitInfoPlayerSlot = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetTransmitInfoPlayerSlot __s2sdk_SetTransmitInfoPlayerSlot;
namespace s2sdk {
  /**
   * @brief Sets the player slot value in the CCheckTransmitInfo.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param playerSlot (int32): The player slot value to set.
   */
  inline void SetTransmitInfoPlayerSlot(void* info, int32_t playerSlot) {
    return __s2sdk_SetTransmitInfoPlayerSlot(info, playerSlot);
  }

  using _GetTransmitInfoFullUpdate = bool (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_GetTransmitInfoFullUpdate __s2sdk_GetTransmitInfoFullUpdate;
namespace s2sdk {
  /**
   * @brief Gets the full update flag from the CCheckTransmitInfo.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @return bool: True if full update is enabled, false otherwise.
   */
  inline bool GetTransmitInfoFullUpdate(void* info) {
    return __s2sdk_GetTransmitInfoFullUpdate(info);
  }

  using _SetTransmitInfoFullUpdate = void (*)(void*, bool);
}
extern "C" PLUGIN_API s2sdk::_SetTransmitInfoFullUpdate __s2sdk_SetTransmitInfoFullUpdate;
namespace s2sdk {
  /**
   * @brief Sets the full update flag in the CCheckTransmitInfo.
   * @param info (ptr64): Pointer to the CCheckTransmitInfo structure.
   * @param fullUpdate (bool): The full update flag value to set.
   */
  inline void SetTransmitInfoFullUpdate(void* info, bool fullUpdate) {
    return __s2sdk_SetTransmitInfoFullUpdate(info, fullUpdate);
  }

  using _HideTransmitEntities = void (*)(int32_t, const plg::vector<int32_t>&);
}
extern "C" PLUGIN_API s2sdk::_HideTransmitEntities __s2sdk_HideTransmitEntities;
namespace s2sdk {
  /**
   * @brief Hides entities from a player's transmit list.
   * @param playerSlot (int32): The player slot to hide entities from.
   * @param entHandles (int32[]): Entity handles to hide.
   */
  inline void HideTransmitEntities(int32_t playerSlot, const plg::vector<int32_t>& entHandles) {
    return __s2sdk_HideTransmitEntities(playerSlot, entHandles);
  }

  using _ShowTransmitEntities = void (*)(int32_t, const plg::vector<int32_t>&);
}
extern "C" PLUGIN_API s2sdk::_ShowTransmitEntities __s2sdk_ShowTransmitEntities;
namespace s2sdk {
  /**
   * @brief Shows previously hidden entities to a player.
   * @param playerSlot (int32): The player slot to show entities to.
   * @param entHandles (int32[]): Entity handles to show.
   */
  inline void ShowTransmitEntities(int32_t playerSlot, const plg::vector<int32_t>& entHandles) {
    return __s2sdk_ShowTransmitEntities(playerSlot, entHandles);
  }

  using _GetHiddenTransmitEntities = plg::vector<int32_t> (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetHiddenTransmitEntities __s2sdk_GetHiddenTransmitEntities;
namespace s2sdk {
  /**
   * @brief Gets all hidden entity handles for a player.
   * @param playerSlot (int32): The player slot to query.
   * @return int32[]: Array of hidden entity handles.
   */
  inline plg::vector<int32_t> GetHiddenTransmitEntities(int32_t playerSlot) {
    return __s2sdk_GetHiddenTransmitEntities(playerSlot);
  }

  using _HideTransmitEntity = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_HideTransmitEntity __s2sdk_HideTransmitEntity;
namespace s2sdk {
  /**
   * @brief Hides a single entity from a player's transmit list.
   * @param playerSlot (int32): The player slot to hide the entity from.
   * @param entityHandle (int32): Entity handle to hide.
   */
  inline void HideTransmitEntity(int32_t playerSlot, int32_t entityHandle) {
    return __s2sdk_HideTransmitEntity(playerSlot, entityHandle);
  }

  using _ShowTransmitEntity = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_ShowTransmitEntity __s2sdk_ShowTransmitEntity;
namespace s2sdk {
  /**
   * @brief Shows a previously hidden entity to a player.
   * @param playerSlot (int32): The player slot to show the entity to.
   * @param entityHandle (int32): Entity handle to show.
   */
  inline void ShowTransmitEntity(int32_t playerSlot, int32_t entityHandle) {
    return __s2sdk_ShowTransmitEntity(playerSlot, entityHandle);
  }

  using _HideTransmitEntityFromOtherPlayers = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_HideTransmitEntityFromOtherPlayers __s2sdk_HideTransmitEntityFromOtherPlayers;
namespace s2sdk {
  /**
   * @brief Hides an entity from all players except the owner.
   * @param playerSlot (int32): The owner player slot who will still see the entity.
   * @param entityHandle (int32): Entity handle to hide from other players.
   */
  inline void HideTransmitEntityFromOtherPlayers(int32_t playerSlot, int32_t entityHandle) {
    return __s2sdk_HideTransmitEntityFromOtherPlayers(playerSlot, entityHandle);
  }

  using _ShowTransmitEntityToOtherPlayers = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_ShowTransmitEntityToOtherPlayers __s2sdk_ShowTransmitEntityToOtherPlayers;
namespace s2sdk {
  /**
   * @brief Shows a previously hidden entity to all players except the owner.
   * @param playerSlot (int32): The owner player slot who was excluded from hiding.
   * @param entityHandle (int32): Entity handle to show to other players.
   */
  inline void ShowTransmitEntityToOtherPlayers(int32_t playerSlot, int32_t entityHandle) {
    return __s2sdk_ShowTransmitEntityToOtherPlayers(playerSlot, entityHandle);
  }

  /**
   * @brief RAII wrapper for CheckTransmitInfo pointer.
   * @return 
   */
  class CheckTransmitInfo final {
  public:
    CheckTransmitInfo() = default;

    CheckTransmitInfo(const CheckTransmitInfo&) = default;
    CheckTransmitInfo& operator=(const CheckTransmitInfo&) = default;
    CheckTransmitInfo(CheckTransmitInfo&&) noexcept = default;
    CheckTransmitInfo& operator=(CheckTransmitInfo&&) noexcept = default;
    ~CheckTransmitInfo() = default;

    explicit CheckTransmitInfo(void* handle) : _handle(handle) {}

    [[nodiscard]] auto get() const noexcept { return _handle; }

    [[nodiscard]] auto release() noexcept {
      auto handle = _handle;
      _handle = nullptr;
      return handle;
    }

    void reset() noexcept {
      _handle = nullptr;
    }

    void swap(CheckTransmitInfo& other) noexcept {
      using std::swap;
      swap(_handle, other._handle);
    }

    friend void swap(CheckTransmitInfo& lhs, CheckTransmitInfo& rhs) noexcept { lhs.swap(rhs); }

    explicit operator bool() const noexcept { return _handle != nullptr; }
    [[nodiscard]] auto operator<=>(const CheckTransmitInfo& other) const noexcept { return _handle <=> other._handle; }
    [[nodiscard]] bool operator==(const CheckTransmitInfo& other) const noexcept { return _handle == other._handle; }

    /**
     * @brief Sets a bit in the TransmitEntity bitvec, marking an entity as transmittable.
     * @param entityHandle (int32): The handle of the entity to mark as transmittable.
     */
    void SetEntity(int32_t entityHandle) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::SetTransmitInfoEntity(_handle, entityHandle);
    }

    /**
     * @brief Clears a bit in the TransmitEntity bitvec, marking an entity as not transmittable.
     * @param entityHandle (int32): The handle of the entity to mark as not transmittable.
     */
    void ClearEntity(int32_t entityHandle) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::ClearTransmitInfoEntity(_handle, entityHandle);
    }

    /**
     * @brief Checks if a bit is set in the TransmitEntity bitvec.
     * @param entityHandle (int32): The handle of the entity to check.
     * @return bool: True if the entity is marked as transmittable, false otherwise.
     */
    bool IsEntitySet(int32_t entityHandle) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      return s2sdk::IsTransmitInfoEntitySet(_handle, entityHandle);
    }

    /**
     * @brief Sets all bits in the TransmitEntity bitvec, marking all entities as transmittable.
     */
    void SetEntityAll() {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::SetTransmitInfoEntityAll(_handle);
    }

    /**
     * @brief Clears all bits in the TransmitEntity bitvec, marking all entities as not transmittable.
     */
    void ClearEntityAll() {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::ClearTransmitInfoEntityAll(_handle);
    }

    /**
     * @brief Sets a bit in the TransmitNonPlayers bitvec, marking a non-player entity as transmittable.
     * @param entityHandle (int32): The index of the non-player entity to mark as transmittable.
     */
    void SetNonPlayer(int32_t entityHandle) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::SetTransmitInfoNonPlayer(_handle, entityHandle);
    }

    /**
     * @brief Clears a bit in the TransmitNonPlayers bitvec, marking a non-player entity as not transmittable.
     * @param entityHandle (int32): The index of the non-player entity to mark as not transmittable.
     */
    void ClearNonPlayer(int32_t entityHandle) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::ClearTransmitInfoNonPlayer(_handle, entityHandle);
    }

    /**
     * @brief Checks if a bit is set in the TransmitNonPlayers bitvec.
     * @param entityHandle (int32): The index of the non-player entity to check.
     * @return bool: True if the entity is marked as transmittable, false otherwise.
     */
    bool IsNonPlayerSet(int32_t entityHandle) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      return s2sdk::IsTransmitInfoNonPlayerSet(_handle, entityHandle);
    }

    /**
     * @brief Sets all bits in the TransmitNonPlayers bitvec, marking all non-player entities as transmittable.
     */
    void SetNonPlayerAll() {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::SetTransmitInfoNonPlayerAll(_handle);
    }

    /**
     * @brief Clears all bits in the TransmitNonPlayers bitvec, marking all non-player entities as not transmittable.
     */
    void ClearNonPlayerAll() {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::ClearTransmitInfoNonPlayerAll(_handle);
    }

    /**
     * @brief Sets a bit in the TransmitOutOfPVS bitvec, marking an entity to always transmit.
     * @param entityHandle (int32): The handle of the entity to mark as always transmittable.
     */
    void SetOutOfPVS(int32_t entityHandle) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::SetTransmitInfoOutOfPVS(_handle, entityHandle);
    }

    /**
     * @brief Clears a bit in the TransmitOutOfPVS bitvec, unmarking an entity from always transmit.
     * @param entityHandle (int32): The handle of the entity to unmark from always transmit.
     */
    void ClearOutOfPVS(int32_t entityHandle) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::ClearTransmitInfoOutOfPVS(_handle, entityHandle);
    }

    /**
     * @brief Checks if a bit is set in the TransmitOutOfPVS bitvec.
     * @param entityHandle (int32): The handle of the entity to check.
     * @return bool: True if the entity is marked to always transmit, false otherwise.
     */
    bool IsOutOfPVSSet(int32_t entityHandle) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      return s2sdk::IsTransmitInfoOutOfPVSSet(_handle, entityHandle);
    }

    /**
     * @brief Sets all bits in the TransmitOutOfPVS bitvec, marking all entities to always transmit.
     */
    void SetOutOfPVSAll() {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::SetTransmitInfoOutOfPVSAll(_handle);
    }

    /**
     * @brief Clears all bits in the TransmitOutOfPVS bitvec, unmarking all entities from always transmit.
     */
    void ClearOutOfPVSAll() {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::ClearTransmitInfoOutOfPVSAll(_handle);
    }

    /**
     * @brief Sets a bit in the TransmitAlways bitvec, marking an entity to always transmit.
     * @param entityHandle (int32): The handle of the entity to mark as always transmittable.
     */
    void SetHLTV(int32_t entityHandle) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::SetTransmitInfoAlways(_handle, entityHandle);
    }

    /**
     * @brief Clears a bit in the TransmitAlways bitvec, unmarking an entity from always transmit.
     * @param entityHandle (int32): The handle of the entity to unmark from always transmit.
     */
    void ClearHLTV(int32_t entityHandle) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::ClearTransmitInfoAlways(_handle, entityHandle);
    }

    /**
     * @brief Checks if a bit is set in the TransmitAlways bitvec.
     * @param entityHandle (int32): The handle of the entity to check.
     * @return bool: True if the entity is marked to always transmit, false otherwise.
     */
    bool IsHLTVSet(int32_t entityHandle) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      return s2sdk::IsTransmitInfoAlwaysSet(_handle, entityHandle);
    }

    /**
     * @brief Sets all bits in the TransmitAlways bitvec, marking all entities to always transmit.
     */
    void SetHLTVAll() {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::SetTransmitInfoAlwaysAll(_handle);
    }

    /**
     * @brief Clears all bits in the TransmitAlways bitvec, unmarking all entities from always transmit.
     */
    void ClearHLTVAll() {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::ClearTransmitInfoAlwaysAll(_handle);
    }

    /**
     * @brief Gets the count of target player slots.
     * @return int32: The number of target player slots, or 0 if the info pointer is null.
     */
    int32_t GetTargetSlotsCount() {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      return s2sdk::GetTransmitInfoTargetSlotsCount(_handle);
    }

    /**
     * @brief Gets a player slot value at a specific index in the target slots vector.
     * @param index (int32): The index in the target slots vector.
     * @return int32: The player slot value, or -1 if the index is invalid or info is null.
     */
    int32_t GetTargetSlot(int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      return s2sdk::GetTransmitInfoTargetSlot(_handle, index);
    }

    /**
     * @brief Adds a player slot to the target slots vector.
     * @param playerSlot (int32): The player slot value to add.
     */
    void AddTargetSlot(int32_t playerSlot) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::AddTransmitInfoTargetSlot(_handle, playerSlot);
    }

    /**
     * @brief Removes a player slot from the target slots vector.
     * @param index (int32): Index within the target slots vector to remove.
     */
    void RemoveTargetSlot(int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::RemoveTransmitInfoTargetSlot(_handle, index);
    }

    /**
     * @brief Gets the target slots vector.
     * @return int32[]: The player slots array.
     */
    plg::vector<int32_t> GetTargetSlotsAll() {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      return s2sdk::GetTransmitInfoTargetSlotsAll(_handle);
    }

    /**
     * @brief Clears all target player slots from the vector.
     */
    void RemoveTargetSlotsAll() {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::RemoveTransmitInfoTargetSlotsAll(_handle);
    }

    /**
     * @brief Gets the player slot value from the CCheckTransmitInfo.
     * @return int32: The player slot value, or -1 if info is null.
     */
    int32_t GetPlayerSlot() {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      return s2sdk::GetTransmitInfoPlayerSlot(_handle);
    }

    /**
     * @brief Sets the player slot value in the CCheckTransmitInfo.
     * @param playerSlot (int32): The player slot value to set.
     */
    void SetPlayerSlot(int32_t playerSlot) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::SetTransmitInfoPlayerSlot(_handle, playerSlot);
    }

    /**
     * @brief Gets the full update flag from the CCheckTransmitInfo.
     * @return bool: True if full update is enabled, false otherwise.
     */
    bool GetFullUpdate() {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      return s2sdk::GetTransmitInfoFullUpdate(_handle);
    }

    /**
     * @brief Sets the full update flag in the CCheckTransmitInfo.
     * @param fullUpdate (bool): The full update flag value to set.
     */
    void SetFullUpdate(bool fullUpdate) {
      if (_handle == nullptr) throw std::runtime_error("CheckTransmitInfo: empty handle");
      s2sdk::SetTransmitInfoFullUpdate(_handle, fullUpdate);
    }

  private:
    void* _handle{nullptr};
  };


} // namespace s2sdk
