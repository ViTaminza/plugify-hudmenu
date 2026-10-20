#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: timers)

namespace s2sdk {

  using _CreateTimer = TimerId (*)(double, TimerCallback, TimerFlag, const plg::vector<plg::any>&);
}
extern "C" PLUGIN_API s2sdk::_CreateTimer __s2sdk_CreateTimer;
namespace s2sdk {
  /**
   * @brief Creates a new timer that executes a callback function at specified delays.
   * @param delay (double): The time delay in seconds between each callback execution.
   * @param callback (function): The function to be called when the timer expires.
   * @param flags (int32): Flags that modify the behavior of the timer (e.g., no-map change, repeating).
   * @param userData (any[]): An array intended to hold user-related data, allowing for elements of any type.
   * @return uint32: A id to the newly created Timer object, or -1 if the timer could not be created.
   */
  inline TimerId CreateTimer(double delay, TimerCallback callback, TimerFlag flags, const plg::vector<plg::any>& userData) {
    return __s2sdk_CreateTimer(delay, callback, flags, userData);
  }

  using _KillsTimer = void (*)(TimerId);
}
extern "C" PLUGIN_API s2sdk::_KillsTimer __s2sdk_KillsTimer;
namespace s2sdk {
  /**
   * @brief Stops and removes an existing timer.
   * @param timer (uint32): A id of the Timer object to be stopped and removed.
   */
  inline void KillsTimer(TimerId timer) {
    return __s2sdk_KillsTimer(timer);
  }

  using _RescheduleTimer = void (*)(TimerId, double);
}
extern "C" PLUGIN_API s2sdk::_RescheduleTimer __s2sdk_RescheduleTimer;
namespace s2sdk {
  /**
   * @brief Reschedules an existing timer with a new delay.
   * @param timer (uint32): A id of the Timer object to be stopped and removed.
   * @param newDaly (double): The new delay in seconds between each callback execution.
   */
  inline void RescheduleTimer(TimerId timer, double newDaly) {
    return __s2sdk_RescheduleTimer(timer, newDaly);
  }

  using _GetTickInterval = double (*)();
}
extern "C" PLUGIN_API s2sdk::_GetTickInterval __s2sdk_GetTickInterval;
namespace s2sdk {
  /**
   * @brief Returns the number of seconds in between game server ticks.
   * @return double: The tick interval value.
   */
  inline double GetTickInterval() {
    return __s2sdk_GetTickInterval();
  }

  using _GetTickedTime = double (*)();
}
extern "C" PLUGIN_API s2sdk::_GetTickedTime __s2sdk_GetTickedTime;
namespace s2sdk {
  /**
   * @brief Returns the simulated game time.
   * @return double: The ticked time value.
   */
  inline double GetTickedTime() {
    return __s2sdk_GetTickedTime();
  }

} // namespace s2sdk
