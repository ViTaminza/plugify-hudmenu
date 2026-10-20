#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: bodies)

namespace s2sdk {

  using _AddBodyImpulseAtPosition = void (*)(int32_t, const plg::vec3&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_AddBodyImpulseAtPosition __s2sdk_AddBodyImpulseAtPosition;
namespace s2sdk {
  /**
   * @brief Applies an impulse to an entity at a specific world position.
   * @param entityHandle (int32): The handle of the entity.
   * @param position (vec3): The world position where the impulse will be applied.
   * @param impulse (vec3): The impulse vector to apply.
   */
  inline void AddBodyImpulseAtPosition(int32_t entityHandle, const plg::vec3& position, const plg::vec3& impulse) {
    return __s2sdk_AddBodyImpulseAtPosition(entityHandle, position, impulse);
  }

  using _AddBodyVelocity = void (*)(int32_t, const plg::vec3&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_AddBodyVelocity __s2sdk_AddBodyVelocity;
namespace s2sdk {
  /**
   * @brief Adds linear and angular velocity to the entity's physics object.
   * @param entityHandle (int32): The handle of the entity.
   * @param linearVelocity (vec3): The linear velocity vector to add.
   * @param angularVelocity (vec3): The angular velocity vector to add.
   */
  inline void AddBodyVelocity(int32_t entityHandle, const plg::vec3& linearVelocity, const plg::vec3& angularVelocity) {
    return __s2sdk_AddBodyVelocity(entityHandle, linearVelocity, angularVelocity);
  }

  using _DetachBodyFromParent = void (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_DetachBodyFromParent __s2sdk_DetachBodyFromParent;
namespace s2sdk {
  /**
   * @brief Detaches the entity from its parent.
   * @param entityHandle (int32): The handle of the entity.
   */
  inline void DetachBodyFromParent(int32_t entityHandle) {
    return __s2sdk_DetachBodyFromParent(entityHandle);
  }

  using _GetBodySequence = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetBodySequence __s2sdk_GetBodySequence;
namespace s2sdk {
  /**
   * @brief Retrieves the currently active sequence of the entity.
   * @param entityHandle (int32): The handle of the entity.
   * @return int32: The sequence ID of the active sequence, or -1 if invalid.
   */
  inline int32_t GetBodySequence(int32_t entityHandle) {
    return __s2sdk_GetBodySequence(entityHandle);
  }

  using _IsBodyAttachedToParent = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_IsBodyAttachedToParent __s2sdk_IsBodyAttachedToParent;
namespace s2sdk {
  /**
   * @brief Checks whether the entity is attached to a parent.
   * @param entityHandle (int32): The handle of the entity.
   * @return bool: True if attached to a parent, false otherwise.
   */
  inline bool IsBodyAttachedToParent(int32_t entityHandle) {
    return __s2sdk_IsBodyAttachedToParent(entityHandle);
  }

  using _LookupBodySequence = int32_t (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_LookupBodySequence __s2sdk_LookupBodySequence;
namespace s2sdk {
  /**
   * @brief Looks up a sequence ID by its name.
   * @param entityHandle (int32): The handle of the entity.
   * @param name (string): The name of the sequence.
   * @return int32: The sequence ID, or -1 if not found.
   */
  inline int32_t LookupBodySequence(int32_t entityHandle, const plg::string& name) {
    return __s2sdk_LookupBodySequence(entityHandle, name);
  }

  using _SetBodySequenceDuration = float (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetBodySequenceDuration __s2sdk_SetBodySequenceDuration;
namespace s2sdk {
  /**
   * @brief Retrieves the duration of a specified sequence.
   * @param entityHandle (int32): The handle of the entity.
   * @param sequenceName (string): The name of the sequence.
   * @return float: The duration of the sequence in seconds, or 0 if invalid.
   */
  inline float SetBodySequenceDuration(int32_t entityHandle, const plg::string& sequenceName) {
    return __s2sdk_SetBodySequenceDuration(entityHandle, sequenceName);
  }

  using _SetBodyAngularVelocity = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetBodyAngularVelocity __s2sdk_SetBodyAngularVelocity;
namespace s2sdk {
  /**
   * @brief Sets the angular velocity of the entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param angVelocity (vec3): The new angular velocity vector.
   */
  inline void SetBodyAngularVelocity(int32_t entityHandle, const plg::vec3& angVelocity) {
    return __s2sdk_SetBodyAngularVelocity(entityHandle, angVelocity);
  }

  using _SetBodyMaterialGroup = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetBodyMaterialGroup __s2sdk_SetBodyMaterialGroup;
namespace s2sdk {
  /**
   * @brief Sets the material group of the entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param materialGroup (string): The material group token to assign.
   */
  inline void SetBodyMaterialGroup(int32_t entityHandle, const plg::string& materialGroup) {
    return __s2sdk_SetBodyMaterialGroup(entityHandle, materialGroup);
  }

  using _SetBodyVelocity = void (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetBodyVelocity __s2sdk_SetBodyVelocity;
namespace s2sdk {
  /**
   * @brief Sets the linear velocity of the entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param velocity (vec3): The new velocity vector.
   */
  inline void SetBodyVelocity(int32_t entityHandle, const plg::vec3& velocity) {
    return __s2sdk_SetBodyVelocity(entityHandle, velocity);
  }

} // namespace s2sdk
