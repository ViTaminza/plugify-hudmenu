#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: engine)

namespace s2sdk {

  using _QueryInterface = void* (*)(const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_QueryInterface __s2sdk_QueryInterface;
namespace s2sdk {
  /**
   * @brief Queries an interface from a specified module.
   * @param module (string): The name of the module to query the interface from.
   * @param name (string): The name of the interface to find.
   * @return ptr64: A pointer to the queried interface.
   */
  inline void* QueryInterface(const plg::string& module, const plg::string& name) {
    return __s2sdk_QueryInterface(module, name);
  }

  using _GetGameDirectory = plg::string (*)();
}
extern "C" PLUGIN_API s2sdk::_GetGameDirectory __s2sdk_GetGameDirectory;
namespace s2sdk {
  /**
   * @brief Returns the path of the game's directory.
   * @return string: A reference to a string where the game directory path will be stored.
   */
  inline plg::string GetGameDirectory() {
    return __s2sdk_GetGameDirectory();
  }

  using _GetCurrentMap = plg::string (*)();
}
extern "C" PLUGIN_API s2sdk::_GetCurrentMap __s2sdk_GetCurrentMap;
namespace s2sdk {
  /**
   * @brief Returns the current map name.
   * @return string: A reference to a string where the current map name will be stored.
   */
  inline plg::string GetCurrentMap() {
    return __s2sdk_GetCurrentMap();
  }

  using _IsMapValid = bool (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_IsMapValid __s2sdk_IsMapValid;
namespace s2sdk {
  /**
   * @brief Returns whether a specified map is valid or not.
   * @param mapname (string): The name of the map to check for validity.
   * @return bool: True if the map is valid, false otherwise.
   */
  inline bool IsMapValid(const plg::string& mapname) {
    return __s2sdk_IsMapValid(mapname);
  }

  using _GetGameTime = float (*)();
}
extern "C" PLUGIN_API s2sdk::_GetGameTime __s2sdk_GetGameTime;
namespace s2sdk {
  /**
   * @brief Returns the game time based on the game tick.
   * @return float: The current game time.
   */
  inline float GetGameTime() {
    return __s2sdk_GetGameTime();
  }

  using _GetGameTickCount = int32_t (*)();
}
extern "C" PLUGIN_API s2sdk::_GetGameTickCount __s2sdk_GetGameTickCount;
namespace s2sdk {
  /**
   * @brief Returns the game's internal tick count.
   * @return int32: The current tick count of the game.
   */
  inline int32_t GetGameTickCount() {
    return __s2sdk_GetGameTickCount();
  }

  using _GetGameFrameTime = float (*)();
}
extern "C" PLUGIN_API s2sdk::_GetGameFrameTime __s2sdk_GetGameFrameTime;
namespace s2sdk {
  /**
   * @brief Returns the time the game took processing the last frame.
   * @return float: The frame time of the last processed frame.
   */
  inline float GetGameFrameTime() {
    return __s2sdk_GetGameFrameTime();
  }

  using _GetEngineTime = double (*)();
}
extern "C" PLUGIN_API s2sdk::_GetEngineTime __s2sdk_GetEngineTime;
namespace s2sdk {
  /**
   * @brief Returns a high-precision time value for profiling the engine.
   * @return double: A high-precision time value.
   */
  inline double GetEngineTime() {
    return __s2sdk_GetEngineTime();
  }

  using _GetMaxClients = int32_t (*)();
}
extern "C" PLUGIN_API s2sdk::_GetMaxClients __s2sdk_GetMaxClients;
namespace s2sdk {
  /**
   * @brief Returns the maximum number of clients that can connect to the server.
   * @return int32: The maximum client count, or -1 if global variables are not initialized.
   */
  inline int32_t GetMaxClients() {
    return __s2sdk_GetMaxClients();
  }

  using _Precache = void (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_Precache __s2sdk_Precache;
namespace s2sdk {
  /**
   * @brief Precaches a given file.
   * @param resource (string): The name of the resource to be precached.
   */
  inline void Precache(const plg::string& resource) {
    return __s2sdk_Precache(resource);
  }

  using _IsPrecached = bool (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_IsPrecached __s2sdk_IsPrecached;
namespace s2sdk {
  /**
   * @brief Checks if a specified file is precached.
   * @param resource (string): The name of the file to check.
   * @return bool
   */
  inline bool IsPrecached(const plg::string& resource) {
    return __s2sdk_IsPrecached(resource);
  }

  using _GetEconItemSystem = void* (*)();
}
extern "C" PLUGIN_API s2sdk::_GetEconItemSystem __s2sdk_GetEconItemSystem;
namespace s2sdk {
  /**
   * @brief Returns a pointer to the Economy Item System.
   * @return ptr64: A pointer to the Econ Item System.
   */
  inline void* GetEconItemSystem() {
    return __s2sdk_GetEconItemSystem();
  }

  using _IsServerPaused = bool (*)();
}
extern "C" PLUGIN_API s2sdk::_IsServerPaused __s2sdk_IsServerPaused;
namespace s2sdk {
  /**
   * @brief Checks if the server is currently paused.
   * @return bool: True if the server is paused, false otherwise.
   */
  inline bool IsServerPaused() {
    return __s2sdk_IsServerPaused();
  }

  using _QueueTaskForNextFrame = void (*)(TaskCallback, const plg::vector<plg::any>&);
}
extern "C" PLUGIN_API s2sdk::_QueueTaskForNextFrame __s2sdk_QueueTaskForNextFrame;
namespace s2sdk {
  /**
   * @brief Queues a task to be executed on the next frame.
   * @param callback (function): A callback function to be executed on the next frame.
   * @param userData (any[]): An array intended to hold user-related data, allowing for elements of any type.
   */
  inline void QueueTaskForNextFrame(TaskCallback callback, const plg::vector<plg::any>& userData) {
    return __s2sdk_QueueTaskForNextFrame(callback, userData);
  }

  using _QueueTaskForNextWorldUpdate = void (*)(TaskCallback, const plg::vector<plg::any>&);
}
extern "C" PLUGIN_API s2sdk::_QueueTaskForNextWorldUpdate __s2sdk_QueueTaskForNextWorldUpdate;
namespace s2sdk {
  /**
   * @brief Queues a task to be executed on the next world update.
   * @param callback (function): A callback function to be executed on the next world update.
   * @param userData (any[]): An array intended to hold user-related data, allowing for elements of any type.
   */
  inline void QueueTaskForNextWorldUpdate(TaskCallback callback, const plg::vector<plg::any>& userData) {
    return __s2sdk_QueueTaskForNextWorldUpdate(callback, userData);
  }

  using _GetSoundDuration = float (*)(const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetSoundDuration __s2sdk_GetSoundDuration;
namespace s2sdk {
  /**
   * @brief Returns the duration of a specified sound.
   * @param name (string): The name of the sound to check.
   * @param actorModel (string): The name of the sound to check.
   * @return float: The duration of the sound in seconds.
   */
  inline float GetSoundDuration(const plg::string& name, const plg::string& actorModel) {
    return __s2sdk_GetSoundDuration(name, actorModel);
  }

  using _EmitSound = void (*)(int32_t, const plg::string&, int32_t, float, float);
}
extern "C" PLUGIN_API s2sdk::_EmitSound __s2sdk_EmitSound;
namespace s2sdk {
  /**
   * @brief Emits a sound from a specified entity.
   * @param entityHandle (int32): The handle of the entity that will emit the sound.
   * @param sound (string): The name of the sound to emit.
   * @param pitch (int32): The pitch of the sound.
   * @param volume (float): The volume of the sound.
   * @param delay (float): The delay before the sound is played.
   */
  inline void EmitSound(int32_t entityHandle, const plg::string& sound, int32_t pitch, float volume, float delay) {
    return __s2sdk_EmitSound(entityHandle, sound, pitch, volume, delay);
  }

  using _StopSound = void (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_StopSound __s2sdk_StopSound;
namespace s2sdk {
  /**
   * @brief Stops a sound from a specified entity.
   * @param entityHandle (int32): The handle of the entity that will stop the sound.
   * @param sound (string): The name of the sound to stop.
   */
  inline void StopSound(int32_t entityHandle, const plg::string& sound) {
    return __s2sdk_StopSound(entityHandle, sound);
  }

  using _EmitSoundToClient = void (*)(int32_t, const plg::vector<int32_t>&, const plg::string&, float, float);
}
extern "C" PLUGIN_API s2sdk::_EmitSoundToClient __s2sdk_EmitSoundToClient;
namespace s2sdk {
  /**
   * @brief Emits a sound to one or more clients.
   * @param entityHandle (int32): The handle of the entity that emits the sound.
   * @param playersSlot (int32[]): Player slot indices that will hear the sound.
   * @param sound (string): The name of the sound to emit.
   * @param volume (float): The volume of the sound.
   * @param pitch (float): The pitch of the sound.
   */
  inline void EmitSoundToClient(int32_t entityHandle, const plg::vector<int32_t>& playersSlot, const plg::string& sound, float volume, float pitch) {
    return __s2sdk_EmitSoundToClient(entityHandle, playersSlot, sound, volume, pitch);
  }

} // namespace s2sdk
