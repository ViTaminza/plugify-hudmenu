#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: debug)

namespace s2sdk {

  using _DebugBreak = void (*)();
}
extern "C" PLUGIN_API s2sdk::_DebugBreak __s2sdk_DebugBreak;
namespace s2sdk {
  /**
   * @brief Triggers a breakpoint in the debugger.
   */
  inline void DebugBreak() {
    return __s2sdk_DebugBreak();
  }

  using _DebugDrawBox = void (*)(const plg::vec3&, const plg::vec3&, const plg::vec3&, int32_t, int32_t, int32_t, int32_t, float);
}
extern "C" PLUGIN_API s2sdk::_DebugDrawBox __s2sdk_DebugDrawBox;
namespace s2sdk {
  /**
   * @brief Draws a debug overlay box.
   * @param center (vec3): Center of the box in world space.
   * @param mins (vec3): Minimum bounds relative to the center.
   * @param maxs (vec3): Maximum bounds relative to the center.
   * @param r (int32): Red color value.
   * @param g (int32): Green color value.
   * @param b (int32): Blue color value.
   * @param a (int32): Alpha (transparency) value.
   * @param duration (float): Duration (in seconds) to display the box.
   */
  inline void DebugDrawBox(const plg::vec3& center, const plg::vec3& mins, const plg::vec3& maxs, int32_t r, int32_t g, int32_t b, int32_t a, float duration) {
    return __s2sdk_DebugDrawBox(center, mins, maxs, r, g, b, a, duration);
  }

  using _DebugDrawBoxDirection = void (*)(const plg::vec3&, const plg::vec3&, const plg::vec3&, const plg::vec3&, const plg::vec3&, float, float);
}
extern "C" PLUGIN_API s2sdk::_DebugDrawBoxDirection __s2sdk_DebugDrawBoxDirection;
namespace s2sdk {
  /**
   * @brief Draws a debug box oriented in the direction of a forward vector.
   * @param center (vec3): Center of the box.
   * @param mins (vec3): Minimum bounds.
   * @param maxs (vec3): Maximum bounds.
   * @param forward (vec3): Forward direction vector.
   * @param color (vec3): RGB color vector.
   * @param alpha (float): Alpha transparency.
   * @param duration (float): Duration (in seconds) to display the box.
   */
  inline void DebugDrawBoxDirection(const plg::vec3& center, const plg::vec3& mins, const plg::vec3& maxs, const plg::vec3& forward, const plg::vec3& color, float alpha, float duration) {
    return __s2sdk_DebugDrawBoxDirection(center, mins, maxs, forward, color, alpha, duration);
  }

  using _DebugDrawCircle = void (*)(const plg::vec3&, const plg::vec3&, float, float, bool, float);
}
extern "C" PLUGIN_API s2sdk::_DebugDrawCircle __s2sdk_DebugDrawCircle;
namespace s2sdk {
  /**
   * @brief Draws a debug circle.
   * @param center (vec3): Center of the circle.
   * @param color (vec3): RGB color vector.
   * @param alpha (float): Alpha transparency.
   * @param radius (float): Circle radius.
   * @param zTest (bool): Whether to perform depth testing.
   * @param duration (float): Duration (in seconds) to display the circle.
   */
  inline void DebugDrawCircle(const plg::vec3& center, const plg::vec3& color, float alpha, float radius, bool zTest, float duration) {
    return __s2sdk_DebugDrawCircle(center, color, alpha, radius, zTest, duration);
  }

  using _DebugDrawClear = void (*)();
}
extern "C" PLUGIN_API s2sdk::_DebugDrawClear __s2sdk_DebugDrawClear;
namespace s2sdk {
  /**
   * @brief Clears all debug overlays.
   */
  inline void DebugDrawClear() {
    return __s2sdk_DebugDrawClear();
  }

  using _DebugDrawLine = void (*)(const plg::vec3&, const plg::vec3&, int32_t, int32_t, int32_t, bool, float);
}
extern "C" PLUGIN_API s2sdk::_DebugDrawLine __s2sdk_DebugDrawLine;
namespace s2sdk {
  /**
   * @brief Draws a debug overlay line.
   * @param origin (vec3): Start point of the line.
   * @param target (vec3): End point of the line.
   * @param r (int32): Red color value.
   * @param g (int32): Green color value.
   * @param b (int32): Blue color value.
   * @param zTest (bool): Whether to perform depth testing.
   * @param duration (float): Duration (in seconds) to display the line.
   */
  inline void DebugDrawLine(const plg::vec3& origin, const plg::vec3& target, int32_t r, int32_t g, int32_t b, bool zTest, float duration) {
    return __s2sdk_DebugDrawLine(origin, target, r, g, b, zTest, duration);
  }

  using _DebugDrawLine_vCol = void (*)(const plg::vec3&, const plg::vec3&, const plg::vec3&, bool, float);
}
extern "C" PLUGIN_API s2sdk::_DebugDrawLine_vCol __s2sdk_DebugDrawLine_vCol;
namespace s2sdk {
  /**
   * @brief Draws a debug line using a color vector.
   * @param start (vec3): Start point of the line.
   * @param end (vec3): End point of the line.
   * @param color (vec3): RGB color vector.
   * @param zTest (bool): Whether to perform depth testing.
   * @param duration (float): Duration (in seconds) to display the line.
   */
  inline void DebugDrawLine_vCol(const plg::vec3& start, const plg::vec3& end, const plg::vec3& color, bool zTest, float duration) {
    return __s2sdk_DebugDrawLine_vCol(start, end, color, zTest, duration);
  }

  using _DebugDrawScreenTextLine = void (*)(float, float, int32_t, const plg::string&, int32_t, int32_t, int32_t, int32_t, float);
}
extern "C" PLUGIN_API s2sdk::_DebugDrawScreenTextLine __s2sdk_DebugDrawScreenTextLine;
namespace s2sdk {
  /**
   * @brief Draws text at a specified screen position with line offset.
   * @param x (float): X coordinate in screen space.
   * @param y (float): Y coordinate in screen space.
   * @param lineOffset (int32): Line offset value.
   * @param text (string): The text string to display.
   * @param r (int32): Red color value.
   * @param g (int32): Green color value.
   * @param b (int32): Blue color value.
   * @param a (int32): Alpha transparency value.
   * @param duration (float): Duration (in seconds) to display the text.
   */
  inline void DebugDrawScreenTextLine(float x, float y, int32_t lineOffset, const plg::string& text, int32_t r, int32_t g, int32_t b, int32_t a, float duration) {
    return __s2sdk_DebugDrawScreenTextLine(x, y, lineOffset, text, r, g, b, a, duration);
  }

  using _DebugDrawSphere = void (*)(const plg::vec3&, const plg::vec3&, float, float, bool, float);
}
extern "C" PLUGIN_API s2sdk::_DebugDrawSphere __s2sdk_DebugDrawSphere;
namespace s2sdk {
  /**
   * @brief Draws a debug sphere.
   * @param center (vec3): Center of the sphere.
   * @param color (vec3): RGB color vector.
   * @param alpha (float): Alpha transparency.
   * @param radius (float): Radius of the sphere.
   * @param zTest (bool): Whether to perform depth testing.
   * @param duration (float): Duration (in seconds) to display the sphere.
   */
  inline void DebugDrawSphere(const plg::vec3& center, const plg::vec3& color, float alpha, float radius, bool zTest, float duration) {
    return __s2sdk_DebugDrawSphere(center, color, alpha, radius, zTest, duration);
  }

  using _DebugDrawText = void (*)(const plg::vec3&, const plg::string&, bool, float);
}
extern "C" PLUGIN_API s2sdk::_DebugDrawText __s2sdk_DebugDrawText;
namespace s2sdk {
  /**
   * @brief Draws text in 3D space.
   * @param origin (vec3): World-space position to draw the text at.
   * @param text (string): The text string to display.
   * @param viewCheck (bool): If true, only draws when visible to camera.
   * @param duration (float): Duration (in seconds) to display the text.
   */
  inline void DebugDrawText(const plg::vec3& origin, const plg::string& text, bool viewCheck, float duration) {
    return __s2sdk_DebugDrawText(origin, text, viewCheck, duration);
  }

  using _DebugScreenTextPretty = void (*)(float, float, int32_t, const plg::string&, int32_t, int32_t, int32_t, int32_t, float, const plg::string&, int32_t, bool);
}
extern "C" PLUGIN_API s2sdk::_DebugScreenTextPretty __s2sdk_DebugScreenTextPretty;
namespace s2sdk {
  /**
   * @brief Draws styled debug text on screen.
   * @param x (float): X coordinate.
   * @param y (float): Y coordinate.
   * @param lineOffset (int32): Line offset value.
   * @param text (string): Text string.
   * @param r (int32): Red color value.
   * @param g (int32): Green color value.
   * @param b (int32): Blue color value.
   * @param a (int32): Alpha transparency.
   * @param duration (float): Duration (in seconds) to display the text.
   * @param font (string): Font name.
   * @param size (int32): Font size.
   * @param bold (bool): Whether text should be bold.
   */
  inline void DebugScreenTextPretty(float x, float y, int32_t lineOffset, const plg::string& text, int32_t r, int32_t g, int32_t b, int32_t a, float duration, const plg::string& font, int32_t size, bool bold) {
    return __s2sdk_DebugScreenTextPretty(x, y, lineOffset, text, r, g, b, a, duration, font, size, bold);
  }

  using _DebugScriptAssert = void (*)(bool, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_DebugScriptAssert __s2sdk_DebugScriptAssert;
namespace s2sdk {
  /**
   * @brief Performs an assertion and logs a message if the assertion fails.
   * @param assertion (bool): Boolean value to test.
   * @param message (string): Message to display if the assertion fails.
   */
  inline void DebugScriptAssert(bool assertion, const plg::string& message) {
    return __s2sdk_DebugScriptAssert(assertion, message);
  }

} // namespace s2sdk
