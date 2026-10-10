#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: events)

namespace s2sdk {

  using _HookEvent = EventHookError (*)(const plg::string&, EventCallback, HookMode);
}
extern "C" PLUGIN_API s2sdk::_HookEvent __s2sdk_HookEvent;
namespace s2sdk {
  /**
   * @brief Creates a hook for when a game event is fired.
   * @param name (string): The name of the event to hook.
   * @param callback (function): The callback function to call when the event is fired.
   * @param type (uint8): Whether the hook was in post mode (after processing) or pre mode (before processing).
   * @return int32: An integer indicating the result of the hook operation.
   */
  inline EventHookError HookEvent(const plg::string& name, EventCallback callback, HookMode type) {
    return __s2sdk_HookEvent(name, callback, type);
  }

  using _UnhookEvent = EventHookError (*)(const plg::string&, EventCallback, HookMode);
}
extern "C" PLUGIN_API s2sdk::_UnhookEvent __s2sdk_UnhookEvent;
namespace s2sdk {
  /**
   * @brief Removes a hook for when a game event is fired.
   * @param name (string): The name of the event to unhook.
   * @param callback (function): The callback function to remove.
   * @param type (uint8): Whether the hook was in post mode (after processing) or pre mode (before processing).
   * @return int32: An integer indicating the result of the unhook operation.
   */
  inline EventHookError UnhookEvent(const plg::string& name, EventCallback callback, HookMode type) {
    return __s2sdk_UnhookEvent(name, callback, type);
  }

  using _CreateEvent = void* (*)(const plg::string&, bool);
}
extern "C" PLUGIN_API s2sdk::_CreateEvent __s2sdk_CreateEvent;
namespace s2sdk {
  /**
   * @brief Creates a game event to be fired later.
   * @param name (string): The name of the event to create.
   * @param force (bool): A boolean indicating whether to force the creation of the event.
   * @return ptr64: A pointer to the created IGameEvent object.
   */
  inline void* CreateEvent(const plg::string& name, bool force) {
    return __s2sdk_CreateEvent(name, force);
  }

  using _FireEvent = void (*)(void*, bool);
}
extern "C" PLUGIN_API s2sdk::_FireEvent __s2sdk_FireEvent;
namespace s2sdk {
  /**
   * @brief Fires a game event.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param dontBroadcast (bool): A boolean indicating whether to broadcast the event.
   */
  inline void FireEvent(void* event, bool dontBroadcast) {
    return __s2sdk_FireEvent(event, dontBroadcast);
  }

  using _FireEventToClient = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_FireEventToClient __s2sdk_FireEventToClient;
namespace s2sdk {
  /**
   * @brief Fires a game event to a specific client.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param playerSlot (int32): The index of the client to fire the event to.
   */
  inline void FireEventToClient(void* event, int32_t playerSlot) {
    return __s2sdk_FireEventToClient(event, playerSlot);
  }

  using _CancelCreatedEvent = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_CancelCreatedEvent __s2sdk_CancelCreatedEvent;
namespace s2sdk {
  /**
   * @brief Cancels a previously created game event that has not been fired.
   * @param event (ptr64): A pointer to the IGameEvent object of the event to cancel.
   */
  inline void CancelCreatedEvent(void* event) {
    return __s2sdk_CancelCreatedEvent(event);
  }

  using _GetEventBool = bool (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEventBool __s2sdk_GetEventBool;
namespace s2sdk {
  /**
   * @brief Retrieves the boolean value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to retrieve the boolean value.
   * @return bool: The boolean value associated with the key.
   */
  inline bool GetEventBool(void* event, const plg::string& key) {
    return __s2sdk_GetEventBool(event, key);
  }

  using _GetEventFloat = float (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEventFloat __s2sdk_GetEventFloat;
namespace s2sdk {
  /**
   * @brief Retrieves the float value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to retrieve the float value.
   * @return float: The float value associated with the key.
   */
  inline float GetEventFloat(void* event, const plg::string& key) {
    return __s2sdk_GetEventFloat(event, key);
  }

  using _GetEventInt = int32_t (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEventInt __s2sdk_GetEventInt;
namespace s2sdk {
  /**
   * @brief Retrieves the integer value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to retrieve the integer value.
   * @return int32: The integer value associated with the key.
   */
  inline int32_t GetEventInt(void* event, const plg::string& key) {
    return __s2sdk_GetEventInt(event, key);
  }

  using _GetEventUInt64 = uint64_t (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEventUInt64 __s2sdk_GetEventUInt64;
namespace s2sdk {
  /**
   * @brief Retrieves the long integer value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to retrieve the long integer value.
   * @return uint64: The long integer value associated with the key.
   */
  inline uint64_t GetEventUInt64(void* event, const plg::string& key) {
    return __s2sdk_GetEventUInt64(event, key);
  }

  using _GetEventString = plg::string (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEventString __s2sdk_GetEventString;
namespace s2sdk {
  /**
   * @brief Retrieves the string value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to retrieve the string value.
   * @return string: A string where the result will be stored.
   */
  inline plg::string GetEventString(void* event, const plg::string& key) {
    return __s2sdk_GetEventString(event, key);
  }

  using _GetEventPtr = void* (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEventPtr __s2sdk_GetEventPtr;
namespace s2sdk {
  /**
   * @brief Retrieves the pointer value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to retrieve the pointer value.
   * @return ptr64: The pointer value associated with the key.
   */
  inline void* GetEventPtr(void* event, const plg::string& key) {
    return __s2sdk_GetEventPtr(event, key);
  }

  using _GetEventPlayerController = void* (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEventPlayerController __s2sdk_GetEventPlayerController;
namespace s2sdk {
  /**
   * @brief Retrieves the player controller address of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to retrieve the player controller address.
   * @return ptr64: A pointer to the player controller associated with the key.
   */
  inline void* GetEventPlayerController(void* event, const plg::string& key) {
    return __s2sdk_GetEventPlayerController(event, key);
  }

  using _GetEventPlayerIndex = int32_t (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEventPlayerIndex __s2sdk_GetEventPlayerIndex;
namespace s2sdk {
  /**
   * @brief Retrieves the player index of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to retrieve the player index.
   * @return int32: The player index associated with the key.
   */
  [[deprecated("Use GetEventPlayerSlot instead. Will be removed soon")]]
  inline int32_t GetEventPlayerIndex(void* event, const plg::string& key) {
    return __s2sdk_GetEventPlayerIndex(event, key);
  }

  using _GetEventPlayerSlot = int32_t (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEventPlayerSlot __s2sdk_GetEventPlayerSlot;
namespace s2sdk {
  /**
   * @brief Retrieves the player slot of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to retrieve the player index.
   * @return int32: The player slot associated with the key.
   */
  inline int32_t GetEventPlayerSlot(void* event, const plg::string& key) {
    return __s2sdk_GetEventPlayerSlot(event, key);
  }

  using _GetEventPlayerPawn = void* (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEventPlayerPawn __s2sdk_GetEventPlayerPawn;
namespace s2sdk {
  /**
   * @brief Retrieves the player pawn address of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to retrieve the player pawn address.
   * @return ptr64: A pointer to the player pawn associated with the key.
   */
  inline void* GetEventPlayerPawn(void* event, const plg::string& key) {
    return __s2sdk_GetEventPlayerPawn(event, key);
  }

  using _GetEventEntity = void* (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEventEntity __s2sdk_GetEventEntity;
namespace s2sdk {
  /**
   * @brief Retrieves the entity address of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to retrieve the entity address.
   * @return ptr64: A pointer to the entity associated with the key.
   */
  inline void* GetEventEntity(void* event, const plg::string& key) {
    return __s2sdk_GetEventEntity(event, key);
  }

  using _GetEventEntityIndex = int32_t (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEventEntityIndex __s2sdk_GetEventEntityIndex;
namespace s2sdk {
  /**
   * @brief Retrieves the entity index of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to retrieve the entity index.
   * @return int32: The entity index associated with the key.
   */
  inline int32_t GetEventEntityIndex(void* event, const plg::string& key) {
    return __s2sdk_GetEventEntityIndex(event, key);
  }

  using _GetEventEntityHandle = int32_t (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetEventEntityHandle __s2sdk_GetEventEntityHandle;
namespace s2sdk {
  /**
   * @brief Retrieves the entity handle of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to retrieve the entity handle.
   * @return int32: The entity handle associated with the key.
   */
  inline int32_t GetEventEntityHandle(void* event, const plg::string& key) {
    return __s2sdk_GetEventEntityHandle(event, key);
  }

  using _GetEventName = plg::string (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_GetEventName __s2sdk_GetEventName;
namespace s2sdk {
  /**
   * @brief Retrieves the name of a game event.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @return string: A string where the result will be stored.
   */
  inline plg::string GetEventName(void* event) {
    return __s2sdk_GetEventName(event);
  }

  using _SetEventBool = void (*)(void*, const plg::string&, bool);
}
extern "C" PLUGIN_API s2sdk::_SetEventBool __s2sdk_SetEventBool;
namespace s2sdk {
  /**
   * @brief Sets the boolean value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to set the boolean value.
   * @param value (bool): The boolean value to set.
   */
  inline void SetEventBool(void* event, const plg::string& key, bool value) {
    return __s2sdk_SetEventBool(event, key, value);
  }

  using _SetEventFloat = void (*)(void*, const plg::string&, float);
}
extern "C" PLUGIN_API s2sdk::_SetEventFloat __s2sdk_SetEventFloat;
namespace s2sdk {
  /**
   * @brief Sets the floating point value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to set the float value.
   * @param value (float): The float value to set.
   */
  inline void SetEventFloat(void* event, const plg::string& key, float value) {
    return __s2sdk_SetEventFloat(event, key, value);
  }

  using _SetEventInt = void (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEventInt __s2sdk_SetEventInt;
namespace s2sdk {
  /**
   * @brief Sets the integer value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to set the integer value.
   * @param value (int32): The integer value to set.
   */
  inline void SetEventInt(void* event, const plg::string& key, int32_t value) {
    return __s2sdk_SetEventInt(event, key, value);
  }

  using _SetEventUInt64 = void (*)(void*, const plg::string&, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_SetEventUInt64 __s2sdk_SetEventUInt64;
namespace s2sdk {
  /**
   * @brief Sets the long integer value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to set the long integer value.
   * @param value (uint64): The long integer value to set.
   */
  inline void SetEventUInt64(void* event, const plg::string& key, uint64_t value) {
    return __s2sdk_SetEventUInt64(event, key, value);
  }

  using _SetEventString = void (*)(void*, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_SetEventString __s2sdk_SetEventString;
namespace s2sdk {
  /**
   * @brief Sets the string value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to set the string value.
   * @param value (string): The string value to set.
   */
  inline void SetEventString(void* event, const plg::string& key, const plg::string& value) {
    return __s2sdk_SetEventString(event, key, value);
  }

  using _SetEventPtr = void (*)(void*, const plg::string&, void*);
}
extern "C" PLUGIN_API s2sdk::_SetEventPtr __s2sdk_SetEventPtr;
namespace s2sdk {
  /**
   * @brief Sets the pointer value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to set the pointer value.
   * @param value (ptr64): The pointer value to set.
   */
  inline void SetEventPtr(void* event, const plg::string& key, void* value) {
    return __s2sdk_SetEventPtr(event, key, value);
  }

  using _SetEventPlayerController = void (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEventPlayerController __s2sdk_SetEventPlayerController;
namespace s2sdk {
  /**
   * @brief Sets the player controller address of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to set the player controller address.
   * @param value (int32): A handle to the player controller to set.
   */
  inline void SetEventPlayerController(void* event, const plg::string& key, int32_t value) {
    return __s2sdk_SetEventPlayerController(event, key, value);
  }

  using _SetEventPlayerIndex = void (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEventPlayerIndex __s2sdk_SetEventPlayerIndex;
namespace s2sdk {
  /**
   * @brief Sets the player index value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to set the player index value.
   * @param value (int32): The player index value to set.
   */
  inline void SetEventPlayerIndex(void* event, const plg::string& key, int32_t value) {
    return __s2sdk_SetEventPlayerIndex(event, key, value);
  }

  using _SetEventPlayerSlot = void (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEventPlayerSlot __s2sdk_SetEventPlayerSlot;
namespace s2sdk {
  /**
   * @brief Sets the player slot value of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to set the player slot value.
   * @param value (int32): The player slot value to set.
   */
  inline void SetEventPlayerSlot(void* event, const plg::string& key, int32_t value) {
    return __s2sdk_SetEventPlayerSlot(event, key, value);
  }

  using _SetEventEntity = void (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEventEntity __s2sdk_SetEventEntity;
namespace s2sdk {
  /**
   * @brief Sets the entity address of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to set the entity address.
   * @param value (int32): A handle to the entity to set.
   */
  inline void SetEventEntity(void* event, const plg::string& key, int32_t value) {
    return __s2sdk_SetEventEntity(event, key, value);
  }

  using _SetEventEntityIndex = void (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEventEntityIndex __s2sdk_SetEventEntityIndex;
namespace s2sdk {
  /**
   * @brief Sets the entity index of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to set the entity index.
   * @param value (int32): The entity index value to set.
   */
  inline void SetEventEntityIndex(void* event, const plg::string& key, int32_t value) {
    return __s2sdk_SetEventEntityIndex(event, key, value);
  }

  using _SetEventEntityHandle = void (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_SetEventEntityHandle __s2sdk_SetEventEntityHandle;
namespace s2sdk {
  /**
   * @brief Sets the entity handle of a game event's key.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param key (string): The key for which to set the entity handle.
   * @param value (int32): The entity handle value to set.
   */
  inline void SetEventEntityHandle(void* event, const plg::string& key, int32_t value) {
    return __s2sdk_SetEventEntityHandle(event, key, value);
  }

  using _SetEventBroadcast = void (*)(void*, bool);
}
extern "C" PLUGIN_API s2sdk::_SetEventBroadcast __s2sdk_SetEventBroadcast;
namespace s2sdk {
  /**
   * @brief Sets whether an event's broadcasting will be disabled or not.
   * @param event (ptr64): A pointer to the IGameEvent object containing event data.
   * @param dontBroadcast (bool): A boolean indicating whether to disable broadcasting.
   */
  inline void SetEventBroadcast(void* event, bool dontBroadcast) {
    return __s2sdk_SetEventBroadcast(event, dontBroadcast);
  }

  using _LoadEventsFromFile = int32_t (*)(const plg::string&, bool);
}
extern "C" PLUGIN_API s2sdk::_LoadEventsFromFile __s2sdk_LoadEventsFromFile;
namespace s2sdk {
  /**
   * @brief Load game event descriptions from a file (e.g., "resource/gameevents.res").
   * @param path (string): The path to the file containing event descriptions.
   * @param searchAll (bool): A boolean indicating whether to search all paths for the file.
   * @return int32: An integer indicating the result of the loading operation.
   */
  inline int32_t LoadEventsFromFile(const plg::string& path, bool searchAll) {
    return __s2sdk_LoadEventsFromFile(path, searchAll);
  }

  /**
   * @brief RAII wrapper for EventInfo pointer.
   * @return 
   */
  class EventInfo final {
  public:
    EventInfo() = default;

    /**
     * @brief Creates a game event to be fired later.
     * @param name (string): The name of the event to create.
     * @param force (bool): A boolean indicating whether to force the creation of the event.
     * @return 
     */
    explicit EventInfo(const plg::string& name, bool force)
      : EventInfo(CreateEvent(name, force), Ownership::Owned) {}

    EventInfo(const EventInfo&) = default;
    EventInfo& operator=(const EventInfo&) = default;
    EventInfo(EventInfo&&) noexcept = default;
    EventInfo& operator=(EventInfo&&) noexcept = default;
    ~EventInfo() = default;

    explicit EventInfo(void* handle, [[maybe_unused]] Ownership ownership = Ownership::Borrowed) : _handle(handle) {}

    [[nodiscard]] auto get() const noexcept { return _handle; }

    [[nodiscard]] auto release() noexcept {
      auto handle = _handle;
      _handle = nullptr;
      return handle;
    }

    void reset() noexcept {
      _handle = nullptr;
    }

    void swap(EventInfo& other) noexcept {
      using std::swap;
      swap(_handle, other._handle);
    }

    friend void swap(EventInfo& lhs, EventInfo& rhs) noexcept { lhs.swap(rhs); }

    explicit operator bool() const noexcept { return _handle != nullptr; }
    [[nodiscard]] auto operator<=>(const EventInfo& other) const noexcept { return _handle <=> other._handle; }
    [[nodiscard]] bool operator==(const EventInfo& other) const noexcept { return _handle == other._handle; }

    /**
     * @brief Fires a game event.
     * @param dontBroadcast (bool): A boolean indicating whether to broadcast the event.
     */
    void Fire(bool dontBroadcast) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::FireEvent(_handle, dontBroadcast);
    }

    /**
     * @brief Fires a game event to a specific client.
     * @param playerSlot (int32): The index of the client to fire the event to.
     */
    void FireToClient(int32_t playerSlot) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::FireEventToClient(_handle, playerSlot);
    }

    /**
     * @brief Cancels a previously created game event that has not been fired.
     */
    void Cancel() {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::CancelCreatedEvent(_handle);
    }

    /**
     * @brief Retrieves the boolean value of a game event's key.
     * @param key (string): The key for which to retrieve the boolean value.
     * @return bool: The boolean value associated with the key.
     */
    bool GetBool(const plg::string& key) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventBool(_handle, key);
    }

    /**
     * @brief Retrieves the float value of a game event's key.
     * @param key (string): The key for which to retrieve the float value.
     * @return float: The float value associated with the key.
     */
    float GetFloat(const plg::string& key) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventFloat(_handle, key);
    }

    /**
     * @brief Retrieves the integer value of a game event's key.
     * @param key (string): The key for which to retrieve the integer value.
     * @return int32: The integer value associated with the key.
     */
    int32_t GetInt(const plg::string& key) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventInt(_handle, key);
    }

    /**
     * @brief Retrieves the long integer value of a game event's key.
     * @param key (string): The key for which to retrieve the long integer value.
     * @return uint64: The long integer value associated with the key.
     */
    uint64_t GetUInt64(const plg::string& key) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventUInt64(_handle, key);
    }

    /**
     * @brief Retrieves the string value of a game event's key.
     * @param key (string): The key for which to retrieve the string value.
     * @return string: A string where the result will be stored.
     */
    plg::string GetString(const plg::string& key) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventString(_handle, key);
    }

    /**
     * @brief Retrieves the pointer value of a game event's key.
     * @param key (string): The key for which to retrieve the pointer value.
     * @return ptr64: The pointer value associated with the key.
     */
    void* GetPtr(const plg::string& key) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventPtr(_handle, key);
    }

    /**
     * @brief Retrieves the player controller address of a game event's key.
     * @param key (string): The key for which to retrieve the player controller address.
     * @return ptr64: A pointer to the player controller associated with the key.
     */
    void* GetPlayerController(const plg::string& key) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventPlayerController(_handle, key);
    }

    /**
     * @brief Retrieves the player index of a game event's key.
     * @param key (string): The key for which to retrieve the player index.
     * @return int32: The player index associated with the key.
     */
    [[deprecated("Use GetEventPlayerSlot instead. Will be removed soon")]]
    int32_t GetPlayerIndex(const plg::string& key) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventPlayerIndex(_handle, key);
    }

    /**
     * @brief Retrieves the player slot of a game event's key.
     * @param key (string): The key for which to retrieve the player index.
     * @return int32: The player slot associated with the key.
     */
    int32_t GetPlayerSlot(const plg::string& key) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventPlayerSlot(_handle, key);
    }

    /**
     * @brief Retrieves the player pawn address of a game event's key.
     * @param key (string): The key for which to retrieve the player pawn address.
     * @return ptr64: A pointer to the player pawn associated with the key.
     */
    void* GetPlayerPawn(const plg::string& key) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventPlayerPawn(_handle, key);
    }

    /**
     * @brief Retrieves the entity address of a game event's key.
     * @param key (string): The key for which to retrieve the entity address.
     * @return ptr64: A pointer to the entity associated with the key.
     */
    void* GetEntity(const plg::string& key) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventEntity(_handle, key);
    }

    /**
     * @brief Retrieves the entity index of a game event's key.
     * @param key (string): The key for which to retrieve the entity index.
     * @return int32: The entity index associated with the key.
     */
    int32_t GetEntityIndex(const plg::string& key) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventEntityIndex(_handle, key);
    }

    /**
     * @brief Retrieves the entity handle of a game event's key.
     * @param key (string): The key for which to retrieve the entity handle.
     * @return int32: The entity handle associated with the key.
     */
    int32_t GetEntityHandle(const plg::string& key) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventEntityHandle(_handle, key);
    }

    /**
     * @brief Retrieves the name of a game event.
     * @return string: A string where the result will be stored.
     */
    plg::string GetName() {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      return s2sdk::GetEventName(_handle);
    }

    /**
     * @brief Sets the boolean value of a game event's key.
     * @param key (string): The key for which to set the boolean value.
     * @param value (bool): The boolean value to set.
     */
    void SetBool(const plg::string& key, bool value) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::SetEventBool(_handle, key, value);
    }

    /**
     * @brief Sets the floating point value of a game event's key.
     * @param key (string): The key for which to set the float value.
     * @param value (float): The float value to set.
     */
    void SetFloat(const plg::string& key, float value) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::SetEventFloat(_handle, key, value);
    }

    /**
     * @brief Sets the integer value of a game event's key.
     * @param key (string): The key for which to set the integer value.
     * @param value (int32): The integer value to set.
     */
    void SetInt(const plg::string& key, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::SetEventInt(_handle, key, value);
    }

    /**
     * @brief Sets the long integer value of a game event's key.
     * @param key (string): The key for which to set the long integer value.
     * @param value (uint64): The long integer value to set.
     */
    void SetUInt64(const plg::string& key, uint64_t value) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::SetEventUInt64(_handle, key, value);
    }

    /**
     * @brief Sets the string value of a game event's key.
     * @param key (string): The key for which to set the string value.
     * @param value (string): The string value to set.
     */
    void SetString(const plg::string& key, const plg::string& value) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::SetEventString(_handle, key, value);
    }

    /**
     * @brief Sets the pointer value of a game event's key.
     * @param key (string): The key for which to set the pointer value.
     * @param value (ptr64): The pointer value to set.
     */
    void SetPtr(const plg::string& key, void* value) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::SetEventPtr(_handle, key, value);
    }

    /**
     * @brief Sets the player controller address of a game event's key.
     * @param key (string): The key for which to set the player controller address.
     * @param value (int32): A handle to the player controller to set.
     */
    void SetPlayerController(const plg::string& key, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::SetEventPlayerController(_handle, key, value);
    }

    /**
     * @brief Sets the player index value of a game event's key.
     * @param key (string): The key for which to set the player index value.
     * @param value (int32): The player index value to set.
     */
    void SetPlayerIndex(const plg::string& key, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::SetEventPlayerIndex(_handle, key, value);
    }

    /**
     * @brief Sets the player slot value of a game event's key.
     * @param key (string): The key for which to set the player slot value.
     * @param value (int32): The player slot value to set.
     */
    void SetPlayerSlot(const plg::string& key, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::SetEventPlayerSlot(_handle, key, value);
    }

    /**
     * @brief Sets the entity address of a game event's key.
     * @param key (string): The key for which to set the entity address.
     * @param value (int32): A handle to the entity to set.
     */
    void SetEntity(const plg::string& key, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::SetEventEntity(_handle, key, value);
    }

    /**
     * @brief Sets the entity index of a game event's key.
     * @param key (string): The key for which to set the entity index.
     * @param value (int32): The entity index value to set.
     */
    void SetEntityIndex(const plg::string& key, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::SetEventEntityIndex(_handle, key, value);
    }

    /**
     * @brief Sets the entity handle of a game event's key.
     * @param key (string): The key for which to set the entity handle.
     * @param value (int32): The entity handle value to set.
     */
    void SetEntityHandle(const plg::string& key, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::SetEventEntityHandle(_handle, key, value);
    }

    /**
     * @brief Sets whether an event's broadcasting will be disabled or not.
     * @param dontBroadcast (bool): A boolean indicating whether to disable broadcasting.
     */
    void SetBroadcast(bool dontBroadcast) {
      if (_handle == nullptr) throw std::runtime_error("EventInfo: empty handle");
      s2sdk::SetEventBroadcast(_handle, dontBroadcast);
    }

  private:
    void* _handle{nullptr};
  };


} // namespace s2sdk
