#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: models)

namespace s2sdk {

  using _GetEntityAttachmentAngles = plg::vec3 (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityAttachmentAngles __s2sdk_GetEntityAttachmentAngles;
namespace s2sdk {
  /**
   * @brief Retrieves the attachment angles of an entity.
   * @param entityHandle (int32): The handle of the entity whose attachment angles are to be retrieved.
   * @param attachmentIndex (int32): The attachment index.
   * @return vec3: A vector representing the attachment angles (pitch, yaw, roll).
   */
  inline plg::vec3 GetEntityAttachmentAngles(int32_t entityHandle, int32_t attachmentIndex) {
    return __s2sdk_GetEntityAttachmentAngles(entityHandle, attachmentIndex);
  }

  using _GetEntityAttachmentForward = plg::vec3 (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityAttachmentForward __s2sdk_GetEntityAttachmentForward;
namespace s2sdk {
  /**
   * @brief Retrieves the forward vector of an entity's attachment.
   * @param entityHandle (int32): The handle of the entity whose attachment forward vector is to be retrieved.
   * @param attachmentIndex (int32): The attachment index.
   * @return vec3: A vector representing the forward direction of the attachment.
   */
  inline plg::vec3 GetEntityAttachmentForward(int32_t entityHandle, int32_t attachmentIndex) {
    return __s2sdk_GetEntityAttachmentForward(entityHandle, attachmentIndex);
  }

  using _GetEntityAttachmentOrigin = plg::vec3 (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityAttachmentOrigin __s2sdk_GetEntityAttachmentOrigin;
namespace s2sdk {
  /**
   * @brief Retrieves the origin vector of an entity's attachment.
   * @param entityHandle (int32): The handle of the entity whose attachment origin is to be retrieved.
   * @param attachmentIndex (int32): The attachment index.
   * @return vec3: A vector representing the origin of the attachment.
   */
  inline plg::vec3 GetEntityAttachmentOrigin(int32_t entityHandle, int32_t attachmentIndex) {
    return __s2sdk_GetEntityAttachmentOrigin(entityHandle, attachmentIndex);
  }

  using _GetEntityMaterialGroupHash = uint32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityMaterialGroupHash __s2sdk_GetEntityMaterialGroupHash;
namespace s2sdk {
  /**
   * @brief Retrieves the material group hash of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @return uint32: The material group hash.
   */
  inline uint32_t GetEntityMaterialGroupHash(int32_t entityHandle) {
    return __s2sdk_GetEntityMaterialGroupHash(entityHandle);
  }

  using _GetEntityMaterialGroupMask = uint64_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityMaterialGroupMask __s2sdk_GetEntityMaterialGroupMask;
namespace s2sdk {
  /**
   * @brief Retrieves the material group mask of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @return uint64: The mesh group mask.
   */
  inline uint64_t GetEntityMaterialGroupMask(int32_t entityHandle) {
    return __s2sdk_GetEntityMaterialGroupMask(entityHandle);
  }

  using _GetEntityModelScale = float (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityModelScale __s2sdk_GetEntityModelScale;
namespace s2sdk {
  /**
   * @brief Retrieves the model scale of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @return float: The model scale factor.
   */
  inline float GetEntityModelScale(int32_t entityHandle) {
    return __s2sdk_GetEntityModelScale(entityHandle);
  }

  using _GetEntityRenderAlpha = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityRenderAlpha __s2sdk_GetEntityRenderAlpha;
namespace s2sdk {
  /**
   * @brief Retrieves the render alpha of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @return int32: The alpha modulation value.
   */
  inline int32_t GetEntityRenderAlpha(int32_t entityHandle) {
    return __s2sdk_GetEntityRenderAlpha(entityHandle);
  }

  using _GetEntityRenderColor2 = plg::vec3 (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_GetEntityRenderColor2 __s2sdk_GetEntityRenderColor2;
namespace s2sdk {
  /**
   * @brief Retrieves the render color of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @return vec3: A vector representing the render color (R, G, B).
   */
  inline plg::vec3 GetEntityRenderColor2(int32_t entityHandle) {
    return __s2sdk_GetEntityRenderColor2(entityHandle);
  }

  using _ScriptLookupAttachment = int32_t (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_ScriptLookupAttachment __s2sdk_ScriptLookupAttachment;
namespace s2sdk {
  /**
   * @brief Retrieves an attachment index by name.
   * @param entityHandle (int32): The handle of the entity.
   * @param attachmentName (string): The name of the attachment.
   * @return int32: The attachment index, or -1 if not found.
   */
  inline int32_t ScriptLookupAttachment(int32_t entityHandle, const plg::string& attachmentName) {
    return __s2sdk_ScriptLookupAttachment(entityHandle, attachmentName);
  }

  using _SetEntityBodygroup = void (*)(int32_t, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityBodygroup __s2sdk_SetEntityBodygroup;
namespace s2sdk {
  /**
   * @brief Sets a bodygroup value by index.
   * @param entityHandle (int32): The handle of the entity.
   * @param group (int32): The bodygroup index.
   * @param value (int32): The new value to set for the bodygroup.
   */
  inline void SetEntityBodygroup(int32_t entityHandle, int32_t group, int32_t value) {
    return __s2sdk_SetEntityBodygroup(entityHandle, group, value);
  }

  using _SetEntityBodygroupByName = void (*)(int32_t, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityBodygroupByName __s2sdk_SetEntityBodygroupByName;
namespace s2sdk {
  /**
   * @brief Sets a bodygroup value by name.
   * @param entityHandle (int32): The handle of the entity.
   * @param name (string): The bodygroup name.
   * @param value (int32): The new value to set for the bodygroup.
   */
  inline void SetEntityBodygroupByName(int32_t entityHandle, const plg::string& name, int32_t value) {
    return __s2sdk_SetEntityBodygroupByName(entityHandle, name, value);
  }

  using _SetEntityLightGroup = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityLightGroup __s2sdk_SetEntityLightGroup;
namespace s2sdk {
  /**
   * @brief Sets the light group of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param lightGroup (string): The light group name.
   */
  inline void SetEntityLightGroup(int32_t entityHandle, const plg::string& lightGroup) {
    return __s2sdk_SetEntityLightGroup(entityHandle, lightGroup);
  }

  using _SetEntityMaterialGroup = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetEntityMaterialGroup __s2sdk_SetEntityMaterialGroup;
namespace s2sdk {
  /**
   * @brief Sets the material group of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param materialGroup (string): The material group name.
   */
  inline void SetEntityMaterialGroup(int32_t entityHandle, const plg::string& materialGroup) {
    return __s2sdk_SetEntityMaterialGroup(entityHandle, materialGroup);
  }

  using _SetEntityMaterialGroupHash = void (*)(int32_t, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityMaterialGroupHash __s2sdk_SetEntityMaterialGroupHash;
namespace s2sdk {
  /**
   * @brief Sets the material group hash of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param hash (uint32): The new material group hash to set.
   */
  inline void SetEntityMaterialGroupHash(int32_t entityHandle, uint32_t hash) {
    return __s2sdk_SetEntityMaterialGroupHash(entityHandle, hash);
  }

  using _SetEntityMaterialGroupMask = void (*)(int32_t, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityMaterialGroupMask __s2sdk_SetEntityMaterialGroupMask;
namespace s2sdk {
  /**
   * @brief Sets the material group mask of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param mask (uint64): The new mesh group mask to set.
   */
  inline void SetEntityMaterialGroupMask(int32_t entityHandle, uint64_t mask) {
    return __s2sdk_SetEntityMaterialGroupMask(entityHandle, mask);
  }

  using _SetEntityModelScale = void (*)(int32_t, float);
}
extern "C" PLUGIN_API s2sdk::_SetEntityModelScale __s2sdk_SetEntityModelScale;
namespace s2sdk {
  /**
   * @brief Sets the model scale of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param scale (float): The new scale factor.
   */
  inline void SetEntityModelScale(int32_t entityHandle, float scale) {
    return __s2sdk_SetEntityModelScale(entityHandle, scale);
  }

  using _SetEntityRenderAlpha = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityRenderAlpha __s2sdk_SetEntityRenderAlpha;
namespace s2sdk {
  /**
   * @brief Sets the render alpha of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param alpha (int32): The new alpha value (0-255).
   */
  inline void SetEntityRenderAlpha(int32_t entityHandle, int32_t alpha) {
    return __s2sdk_SetEntityRenderAlpha(entityHandle, alpha);
  }

  using _SetEntityRenderColor2 = void (*)(int32_t, int32_t, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityRenderColor2 __s2sdk_SetEntityRenderColor2;
namespace s2sdk {
  /**
   * @brief Sets the render color of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param r (int32): The red component (0-255).
   * @param g (int32): The green component (0-255).
   * @param b (int32): The blue component (0-255).
   */
  inline void SetEntityRenderColor2(int32_t entityHandle, int32_t r, int32_t g, int32_t b) {
    return __s2sdk_SetEntityRenderColor2(entityHandle, r, g, b);
  }

  using _SetEntityRenderMode2 = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntityRenderMode2 __s2sdk_SetEntityRenderMode2;
namespace s2sdk {
  /**
   * @brief Sets the render mode of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param mode (int32): The new render mode value.
   */
  inline void SetEntityRenderMode2(int32_t entityHandle, int32_t mode) {
    return __s2sdk_SetEntityRenderMode2(entityHandle, mode);
  }

  using _SetEntitySingleMeshGroup = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetEntitySingleMeshGroup __s2sdk_SetEntitySingleMeshGroup;
namespace s2sdk {
  /**
   * @brief Sets a single mesh group for an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param meshGroupName (string): The name of the mesh group.
   */
  inline void SetEntitySingleMeshGroup(int32_t entityHandle, const plg::string& meshGroupName) {
    return __s2sdk_SetEntitySingleMeshGroup(entityHandle, meshGroupName);
  }

  using _SetEntitySize = void (*)(int32_t, const plg::vec3&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_SetEntitySize __s2sdk_SetEntitySize;
namespace s2sdk {
  /**
   * @brief Sets the size (bounding box) of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param mins (vec3): The minimum bounding box vector.
   * @param maxs (vec3): The maximum bounding box vector.
   */
  inline void SetEntitySize(int32_t entityHandle, const plg::vec3& mins, const plg::vec3& maxs) {
    return __s2sdk_SetEntitySize(entityHandle, mins, maxs);
  }

  using _SetEntitySkin = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEntitySkin __s2sdk_SetEntitySkin;
namespace s2sdk {
  /**
   * @brief Sets the skin of an entity.
   * @param entityHandle (int32): The handle of the entity.
   * @param skin (int32): The new skin index.
   */
  inline void SetEntitySkin(int32_t entityHandle, int32_t skin) {
    return __s2sdk_SetEntitySkin(entityHandle, skin);
  }

} // namespace s2sdk
