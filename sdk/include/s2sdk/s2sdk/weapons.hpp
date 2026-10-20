#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: weapons)

namespace s2sdk {

  using _GetWeaponVDataFromKey = void* (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetWeaponVDataFromKey __s2sdk_GetWeaponVDataFromKey;
namespace s2sdk {
  /**
   * @brief Retrieves the weapon VData for a given weapon name.
   * @param name (string): The name of the weapon.
   * @return ptr64: A pointer to the `CCSWeaponBaseVData` if the entity handle is valid and represents a player weapon; otherwise, nullptr.
   */
  inline void* GetWeaponVDataFromKey(const plg::string& name) {
    return __s2sdk_GetWeaponVDataFromKey(name);
  }

  using _GetWeaponVData = void* (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetWeaponVData __s2sdk_GetWeaponVData;
namespace s2sdk {
  /**
   * @brief Retrieves the weapon VData for a given weapon.
   * @param entityHandle (int32): The handle of the entity from which to retrieve the weapon VData.
   * @return ptr64: A pointer to the `CCSWeaponBaseVData` if the entity handle is valid and represents a player weapon; otherwise, nullptr.
   */
  inline void* GetWeaponVData(int32_t entityHandle) {
    return __s2sdk_GetWeaponVData(entityHandle);
  }

  using _GetWeaponType = CSWeaponType (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetWeaponType __s2sdk_GetWeaponType;
namespace s2sdk {
  /**
   * @brief Retrieves the weapon type of a given entity.
   * @param entityHandle (int32): The handle of the entity (weapon).
   * @return uint32: The type of the weapon, or WEAPONTYPE_UNKNOWN if the entity is invalid.
   */
  inline CSWeaponType GetWeaponType(int32_t entityHandle) {
    return __s2sdk_GetWeaponType(entityHandle);
  }

  using _GetWeaponCategory = CSWeaponCategory (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetWeaponCategory __s2sdk_GetWeaponCategory;
namespace s2sdk {
  /**
   * @brief Retrieves the weapon category of a given entity.
   * @param entityHandle (int32): The handle of the entity (weapon).
   * @return uint32: The category of the weapon, or WEAPONCATEGORY_OTHER if the entity is invalid.
   */
  inline CSWeaponCategory GetWeaponCategory(int32_t entityHandle) {
    return __s2sdk_GetWeaponCategory(entityHandle);
  }

  using _GetWeaponGearSlot = GearSlot (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetWeaponGearSlot __s2sdk_GetWeaponGearSlot;
namespace s2sdk {
  /**
   * @brief Retrieves the gear slot of a given weapon entity.
   * @param entityHandle (int32): The handle of the entity (weapon).
   * @return uint32: The gear slot of the weapon, or GEAR_SLOT_INVALID if the entity is invalid.
   */
  inline GearSlot GetWeaponGearSlot(int32_t entityHandle) {
    return __s2sdk_GetWeaponGearSlot(entityHandle);
  }

  using _GetWeaponItemDefinition = WeaponDefIndex (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetWeaponItemDefinition __s2sdk_GetWeaponItemDefinition;
namespace s2sdk {
  /**
   * @brief Retrieves the weapon definition index for a given entity handle.
   * @param entityHandle (int32): The handle of the entity from which to retrieve the weapon def index.
   * @return uint16: The weapon definition index as a `uint16_t`, or 0 if the entity handle is invalid.
   */
  inline WeaponDefIndex GetWeaponItemDefinition(int32_t entityHandle) {
    return __s2sdk_GetWeaponItemDefinition(entityHandle);
  }

  using _GetWeaponItemDefinitionByName = WeaponDefIndex (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetWeaponItemDefinitionByName __s2sdk_GetWeaponItemDefinitionByName;
namespace s2sdk {
  /**
   * @brief Retrieves the item definition index associated with a given item name.
   * @param itemName (string): The name of the item.
   * @return uint16: The weapon definition index as a `uint16_t`, or 0 if the entity handle is invalid.
   */
  inline WeaponDefIndex GetWeaponItemDefinitionByName(const plg::string& itemName) {
    return __s2sdk_GetWeaponItemDefinitionByName(itemName);
  }

} // namespace s2sdk
