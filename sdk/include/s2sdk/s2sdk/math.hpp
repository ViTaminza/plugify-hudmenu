#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: math)

namespace s2sdk {

  using _AnglesDiff = float (*)(float, float);
}
extern "C" PLUGIN_API s2sdk::_AnglesDiff __s2sdk_AnglesDiff;
namespace s2sdk {
  /**
   * @brief Returns angular difference in degrees
   * @param angle1 (float): First angle in degrees
   * @param angle2 (float): Second angle in degrees
   * @return float: Angular difference in degrees
   */
  inline float AnglesDiff(float angle1, float angle2) {
    return __s2sdk_AnglesDiff(angle1, angle2);
  }

  using _AnglesToVector = plg::vec3 (*)(const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_AnglesToVector __s2sdk_AnglesToVector;
namespace s2sdk {
  /**
   * @brief Converts QAngle to directional Vector
   * @param angles (vec3): The QAngle to convert
   * @return vec3: Directional vector
   */
  inline plg::vec3 AnglesToVector(const plg::vec3& angles) {
    return __s2sdk_AnglesToVector(angles);
  }

  using _AxisAngleToQuaternion = plg::vec4 (*)(const plg::vec3&, float);
}
extern "C" PLUGIN_API s2sdk::_AxisAngleToQuaternion __s2sdk_AxisAngleToQuaternion;
namespace s2sdk {
  /**
   * @brief Converts axis-angle representation to quaternion
   * @param axis (vec3): Rotation axis (should be normalized)
   * @param angle (float): Rotation angle in radians
   * @return vec4: Resulting quaternion
   */
  inline plg::vec4 AxisAngleToQuaternion(const plg::vec3& axis, float angle) {
    return __s2sdk_AxisAngleToQuaternion(axis, angle);
  }

  using _CalcClosestPointOnEntityOBB = plg::vec3 (*)(int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_CalcClosestPointOnEntityOBB __s2sdk_CalcClosestPointOnEntityOBB;
namespace s2sdk {
  /**
   * @brief Computes closest point on an entity's oriented bounding box (OBB)
   * @param entityHandle (int32): Handle of the entity
   * @param position (vec3): Position to find closest point from
   * @return vec3: Closest point on the entity's OBB, or vec3_origin if entity is invalid
   */
  inline plg::vec3 CalcClosestPointOnEntityOBB(int32_t entityHandle, const plg::vec3& position) {
    return __s2sdk_CalcClosestPointOnEntityOBB(entityHandle, position);
  }

  using _CalcDistanceBetweenEntityOBB = float (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_CalcDistanceBetweenEntityOBB __s2sdk_CalcDistanceBetweenEntityOBB;
namespace s2sdk {
  /**
   * @brief Computes distance between two entities' oriented bounding boxes (OBBs)
   * @param entityHandle1 (int32): Handle of the first entity
   * @param entityHandle2 (int32): Handle of the second entity
   * @return float: Distance between OBBs, or -1.0f if either entity is invalid
   */
  inline float CalcDistanceBetweenEntityOBB(int32_t entityHandle1, int32_t entityHandle2) {
    return __s2sdk_CalcDistanceBetweenEntityOBB(entityHandle1, entityHandle2);
  }

  using _CalcDistanceToLineSegment2D = float (*)(const plg::vec3&, const plg::vec3&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_CalcDistanceToLineSegment2D __s2sdk_CalcDistanceToLineSegment2D;
namespace s2sdk {
  /**
   * @brief Computes shortest 2D distance from a point to a line segment
   * @param p (vec3): The point
   * @param vLineA (vec3): First endpoint of the line segment
   * @param vLineB (vec3): Second endpoint of the line segment
   * @return float: Shortest 2D distance
   */
  inline float CalcDistanceToLineSegment2D(const plg::vec3& p, const plg::vec3& vLineA, const plg::vec3& vLineB) {
    return __s2sdk_CalcDistanceToLineSegment2D(p, vLineA, vLineB);
  }

  using _CrossVectors = plg::vec3 (*)(const plg::vec3&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_CrossVectors __s2sdk_CrossVectors;
namespace s2sdk {
  /**
   * @brief Computes cross product of two vectors
   * @param v1 (vec3): First vector
   * @param v2 (vec3): Second vector
   * @return vec3: Cross product vector (v1 × v2)
   */
  inline plg::vec3 CrossVectors(const plg::vec3& v1, const plg::vec3& v2) {
    return __s2sdk_CrossVectors(v1, v2);
  }

  using _ExponentDecay = float (*)(float, float, float);
}
extern "C" PLUGIN_API s2sdk::_ExponentDecay __s2sdk_ExponentDecay;
namespace s2sdk {
  /**
   * @brief Smooth exponential decay function
   * @param decayTo (float): Target value to decay towards
   * @param decayTime (float): Time constant for decay
   * @param dt (float): Delta time
   * @return float: Decay factor
   */
  inline float ExponentDecay(float decayTo, float decayTime, float dt) {
    return __s2sdk_ExponentDecay(decayTo, decayTime, dt);
  }

  using _LerpVectors = plg::vec3 (*)(const plg::vec3&, const plg::vec3&, float);
}
extern "C" PLUGIN_API s2sdk::_LerpVectors __s2sdk_LerpVectors;
namespace s2sdk {
  /**
   * @brief Linear interpolation between two vectors
   * @param start (vec3): Starting vector
   * @param end (vec3): Ending vector
   * @param factor (float): Interpolation factor (0.0 to 1.0)
   * @return vec3: Interpolated vector
   */
  inline plg::vec3 LerpVectors(const plg::vec3& start, const plg::vec3& end, float factor) {
    return __s2sdk_LerpVectors(start, end, factor);
  }

  using _QSlerp = plg::vec3 (*)(const plg::vec3&, const plg::vec3&, float);
}
extern "C" PLUGIN_API s2sdk::_QSlerp __s2sdk_QSlerp;
namespace s2sdk {
  /**
   * @brief Quaternion spherical linear interpolation for angles
   * @param fromAngle (vec3): Starting angle
   * @param toAngle (vec3): Ending angle
   * @param time (float): Interpolation time (0.0 to 1.0)
   * @return vec3: Interpolated angle
   */
  inline plg::vec3 QSlerp(const plg::vec3& fromAngle, const plg::vec3& toAngle, float time) {
    return __s2sdk_QSlerp(fromAngle, toAngle, time);
  }

  using _RotateOrientation = plg::vec3 (*)(const plg::vec3&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_RotateOrientation __s2sdk_RotateOrientation;
namespace s2sdk {
  /**
   * @brief Rotate one QAngle by another
   * @param a1 (vec3): Base orientation
   * @param a2 (vec3): Rotation to apply
   * @return vec3: Rotated orientation
   */
  inline plg::vec3 RotateOrientation(const plg::vec3& a1, const plg::vec3& a2) {
    return __s2sdk_RotateOrientation(a1, a2);
  }

  using _RotatePosition = plg::vec3 (*)(const plg::vec3&, const plg::vec3&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_RotatePosition __s2sdk_RotatePosition;
namespace s2sdk {
  /**
   * @brief Rotate a vector around a point by specified angle
   * @param rotationOrigin (vec3): Origin point of rotation
   * @param rotationAngle (vec3): Angle to rotate by
   * @param vectorToRotate (vec3): Vector to be rotated
   * @return vec3: Rotated vector
   */
  inline plg::vec3 RotatePosition(const plg::vec3& rotationOrigin, const plg::vec3& rotationAngle, const plg::vec3& vectorToRotate) {
    return __s2sdk_RotatePosition(rotationOrigin, rotationAngle, vectorToRotate);
  }

  using _RotateQuaternionByAxisAngle = plg::vec4 (*)(const plg::vec4&, const plg::vec3&, float);
}
extern "C" PLUGIN_API s2sdk::_RotateQuaternionByAxisAngle __s2sdk_RotateQuaternionByAxisAngle;
namespace s2sdk {
  /**
   * @brief Rotates quaternion by axis-angle representation
   * @param q (vec4): Quaternion to rotate
   * @param axis (vec3): Rotation axis
   * @param angle (float): Rotation angle in radians
   * @return vec4: Rotated quaternion
   */
  inline plg::vec4 RotateQuaternionByAxisAngle(const plg::vec4& q, const plg::vec3& axis, float angle) {
    return __s2sdk_RotateQuaternionByAxisAngle(q, axis, angle);
  }

  using _RotationDelta = plg::vec3 (*)(const plg::vec3&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_RotationDelta __s2sdk_RotationDelta;
namespace s2sdk {
  /**
   * @brief Finds angular delta between two QAngles
   * @param src (vec3): Source angle
   * @param dest (vec3): Destination angle
   * @return vec3: Delta angle from src to dest
   */
  inline plg::vec3 RotationDelta(const plg::vec3& src, const plg::vec3& dest) {
    return __s2sdk_RotationDelta(src, dest);
  }

  using _RotationDeltaAsAngularVelocity = plg::vec3 (*)(const plg::vec3&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_RotationDeltaAsAngularVelocity __s2sdk_RotationDeltaAsAngularVelocity;
namespace s2sdk {
  /**
   * @brief Converts delta QAngle to angular velocity vector
   * @param a1 (vec3): First angle
   * @param a2 (vec3): Second angle
   * @return vec3: Angular velocity vector
   */
  inline plg::vec3 RotationDeltaAsAngularVelocity(const plg::vec3& a1, const plg::vec3& a2) {
    return __s2sdk_RotationDeltaAsAngularVelocity(a1, a2);
  }

  using _SplineQuaternions = plg::vec4 (*)(const plg::vec4&, const plg::vec4&, float);
}
extern "C" PLUGIN_API s2sdk::_SplineQuaternions __s2sdk_SplineQuaternions;
namespace s2sdk {
  /**
   * @brief Interpolates between two quaternions using spline
   * @param q0 (vec4): Starting quaternion
   * @param q1 (vec4): Ending quaternion
   * @param t (float): Interpolation parameter (0.0 to 1.0)
   * @return vec4: Interpolated quaternion
   */
  inline plg::vec4 SplineQuaternions(const plg::vec4& q0, const plg::vec4& q1, float t) {
    return __s2sdk_SplineQuaternions(q0, q1, t);
  }

  using _SplineVectors = plg::vec3 (*)(const plg::vec3&, const plg::vec3&, float);
}
extern "C" PLUGIN_API s2sdk::_SplineVectors __s2sdk_SplineVectors;
namespace s2sdk {
  /**
   * @brief Interpolates between two vectors using spline
   * @param v0 (vec3): Starting vector
   * @param v1 (vec3): Ending vector
   * @param t (float): Interpolation parameter (0.0 to 1.0)
   * @return vec3: Interpolated vector
   */
  inline plg::vec3 SplineVectors(const plg::vec3& v0, const plg::vec3& v1, float t) {
    return __s2sdk_SplineVectors(v0, v1, t);
  }

  using _VectorToAngles = plg::vec3 (*)(const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_VectorToAngles __s2sdk_VectorToAngles;
namespace s2sdk {
  /**
   * @brief Converts directional vector to QAngle (no roll)
   * @param input (vec3): Direction vector
   * @return vec3: Angle representation with pitch and yaw (roll is 0)
   */
  inline plg::vec3 VectorToAngles(const plg::vec3& input) {
    return __s2sdk_VectorToAngles(input);
  }

  using _RandomFlt = float (*)(float, float);
}
extern "C" PLUGIN_API s2sdk::_RandomFlt __s2sdk_RandomFlt;
namespace s2sdk {
  /**
   * @brief Returns random float between min and max
   * @param min (float): Minimum value (inclusive)
   * @param max (float): Maximum value (inclusive)
   * @return float: Random float in range [min, max]
   */
  inline float RandomFlt(float min, float max) {
    return __s2sdk_RandomFlt(min, max);
  }

  using _RandomInt = int32_t (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_RandomInt __s2sdk_RandomInt;
namespace s2sdk {
  /**
   * @brief Returns random integer between min and max (inclusive)
   * @param min (int32): Minimum value (inclusive)
   * @param max (int32): Maximum value (inclusive)
   * @return int32: Random integer in range [min, max]
   */
  inline int32_t RandomInt(int32_t min, int32_t max) {
    return __s2sdk_RandomInt(min, max);
  }

} // namespace s2sdk
