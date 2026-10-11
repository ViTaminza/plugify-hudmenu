#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: trace)

namespace s2sdk {

  using _TraceCollideable = bool (*)(const plg::vec3&, const plg::vec3&, int32_t, plg::vec3&, double&, bool&, bool&, plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_TraceCollideable __s2sdk_TraceCollideable;
namespace s2sdk {
  /**
   * @brief Performs a collideable trace using the VScript-compatible table call, exposing it through C++ exports.
   * @param start (vec3): Trace start position (world space)
   * @param end (vec3): Trace end position (world space)
   * @param entityHandle (int32): Entity handle of the collideable
   * @param outPos (vec3&): Output: position of impact
   * @param outFraction (double&): Output: fraction of trace completed
   * @param outHit (bool&): Output: whether a hit occurred
   * @param outStartSolid (bool&): Output: whether trace started inside solid
   * @param outNormal (vec3&): Output: surface normal at impact
   * @return bool: True if trace hit something, false otherwise
   */
  inline bool TraceCollideable(const plg::vec3& start, const plg::vec3& end, int32_t entityHandle, plg::vec3& outPos, double& outFraction, bool& outHit, bool& outStartSolid, plg::vec3& outNormal) {
    return __s2sdk_TraceCollideable(start, end, entityHandle, outPos, outFraction, outHit, outStartSolid, outNormal);
  }

  using _TraceCollideable2 = bool (*)(const plg::vec3&, const plg::vec3&, int32_t, void*, void*, plg::vec3&, double&, bool&, bool&, plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_TraceCollideable2 __s2sdk_TraceCollideable2;
namespace s2sdk {
  /**
   * @brief Performs a collideable trace using the VScript-compatible table call, exposing it through C++ exports.
   * @param start (vec3): Trace start position (world space)
   * @param end (vec3): Trace end position (world space)
   * @param entityHandle (int32): Entity handle of the collideable
   * @param mins (ptr64): Bounding box minimums
   * @param maxs (ptr64): Bounding box maximums
   * @param outPos (vec3&): Output: position of impact
   * @param outFraction (double&): Output: fraction of trace completed
   * @param outHit (bool&): Output: whether a hit occurred
   * @param outStartSolid (bool&): Output: whether trace started inside solid
   * @param outNormal (vec3&): Output: surface normal at impact
   * @return bool: True if trace hit something, false otherwise
   */
  inline bool TraceCollideable2(const plg::vec3& start, const plg::vec3& end, int32_t entityHandle, void* mins, void* maxs, plg::vec3& outPos, double& outFraction, bool& outHit, bool& outStartSolid, plg::vec3& outNormal) {
    return __s2sdk_TraceCollideable2(start, end, entityHandle, mins, maxs, outPos, outFraction, outHit, outStartSolid, outNormal);
  }

  using _TraceHull = bool (*)(const plg::vec3&, const plg::vec3&, const plg::vec3&, const plg::vec3&, int32_t, int32_t, plg::vec3&, double&, bool&, int32_t&, bool&);
}
extern "C" PLUGIN_API s2sdk::_TraceHull __s2sdk_TraceHull;
namespace s2sdk {
  /**
   * @brief Performs a hull trace with specified dimensions and mask.
   * @param start (vec3): Trace start position
   * @param end (vec3): Trace end position
   * @param min (vec3): Local bounding box minimums
   * @param max (vec3): Local bounding box maximums
   * @param mask (int32): Trace mask
   * @param ignoreHandle (int32): Entity handle to ignore during trace
   * @param outPos (vec3&): Output: position of impact
   * @param outFraction (double&): Output: fraction of trace completed
   * @param outHit (bool&): Output: whether a hit occurred
   * @param outEntHit (int32&): Output: handle of entity hit
   * @param outStartSolid (bool&): Output: whether trace started inside solid
   * @return bool: True if trace hit something, false otherwise
   */
  inline bool TraceHull(const plg::vec3& start, const plg::vec3& end, const plg::vec3& min, const plg::vec3& max, int32_t mask, int32_t ignoreHandle, plg::vec3& outPos, double& outFraction, bool& outHit, int32_t& outEntHit, bool& outStartSolid) {
    return __s2sdk_TraceHull(start, end, min, max, mask, ignoreHandle, outPos, outFraction, outHit, outEntHit, outStartSolid);
  }

  using _TraceLine = bool (*)(const plg::vec3&, const plg::vec3&, int32_t, int32_t, plg::vec3&, double&, bool&, int32_t&, bool&);
}
extern "C" PLUGIN_API s2sdk::_TraceLine __s2sdk_TraceLine;
namespace s2sdk {
  /**
   * @brief Performs a line trace between two points.
   * @param startPos (vec3): Trace start position
   * @param endPos (vec3): Trace end position
   * @param mask (int32): Trace mask
   * @param ignoreHandle (int32): Entity handle to ignore during trace
   * @param outPos (vec3&): Output: position of impact
   * @param outFraction (double&): Output: fraction of trace completed
   * @param outHit (bool&): Output: whether a hit occurred
   * @param outEntHit (int32&): Output: handle of entity hit
   * @param outStartSolid (bool&): Output: whether trace started inside solid
   * @return bool: True if trace hit something, false otherwise
   */
  inline bool TraceLine(const plg::vec3& startPos, const plg::vec3& endPos, int32_t mask, int32_t ignoreHandle, plg::vec3& outPos, double& outFraction, bool& outHit, int32_t& outEntHit, bool& outStartSolid) {
    return __s2sdk_TraceLine(startPos, endPos, mask, ignoreHandle, outPos, outFraction, outHit, outEntHit, outStartSolid);
  }

} // namespace s2sdk
