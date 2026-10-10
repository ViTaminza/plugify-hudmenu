#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: gameconfig)

namespace s2sdk {

  using _CloseGameConfigFile = void (*)(ConfigId);
}
extern "C" PLUGIN_API s2sdk::_CloseGameConfigFile __s2sdk_CloseGameConfigFile;
namespace s2sdk {
  /**
   * @brief Closes a game configuration file.
   * @param id (uint32): An id to the game configuration to be closed.
   */
  inline void CloseGameConfigFile(ConfigId id) {
    return __s2sdk_CloseGameConfigFile(id);
  }

  using _LoadGameConfigFile = ConfigId (*)(const plg::vector<plg::string>&);
}
extern "C" PLUGIN_API s2sdk::_LoadGameConfigFile __s2sdk_LoadGameConfigFile;
namespace s2sdk {
  /**
   * @brief Loads a game configuration file.
   * @param paths (string[]): The paths to the game configuration file to be loaded.
   * @return uint32: A id to the loaded game configuration object, or -1 if loading fails.
   */
  inline ConfigId LoadGameConfigFile(const plg::vector<plg::string>& paths) {
    return __s2sdk_LoadGameConfigFile(paths);
  }

  using _GetGameConfigPatch = plg::string (*)(ConfigId, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetGameConfigPatch __s2sdk_GetGameConfigPatch;
namespace s2sdk {
  /**
   * @brief Retrieves a patch associated with the game configuration.
   * @param id (uint32): An id to the game configuration from which to retrieve the patch.
   * @param name (string): The name of the patch to be retrieved.
   * @return string: A string where the patch will be stored.
   */
  inline plg::string GetGameConfigPatch(ConfigId id, const plg::string& name) {
    return __s2sdk_GetGameConfigPatch(id, name);
  }

  using _GetGameConfigOffset = int32_t (*)(ConfigId, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetGameConfigOffset __s2sdk_GetGameConfigOffset;
namespace s2sdk {
  /**
   * @brief Retrieves the offset associated with a name from the game configuration.
   * @param id (uint32): An id to the game configuration from which to retrieve the offset.
   * @param name (string): The name whose offset is to be retrieved.
   * @return int32: The offset associated with the specified name.
   */
  inline int32_t GetGameConfigOffset(ConfigId id, const plg::string& name) {
    return __s2sdk_GetGameConfigOffset(id, name);
  }

  using _GetGameConfigAddress = void* (*)(ConfigId, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetGameConfigAddress __s2sdk_GetGameConfigAddress;
namespace s2sdk {
  /**
   * @brief Retrieves the address associated with a name from the game configuration.
   * @param id (uint32): An id to the game configuration from which to retrieve the address.
   * @param name (string): The name whose address is to be retrieved.
   * @return ptr64: A pointer to the address associated with the specified name.
   */
  inline void* GetGameConfigAddress(ConfigId id, const plg::string& name) {
    return __s2sdk_GetGameConfigAddress(id, name);
  }

  using _GetGameConfigVTable = void* (*)(ConfigId, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetGameConfigVTable __s2sdk_GetGameConfigVTable;
namespace s2sdk {
  /**
   * @brief Retrieves a vtable associated with the game configuration.
   * @param id (uint32): An id to the game configuration from which to retrieve the vtable.
   * @param name (string): The name of the vtable to be retrieved.
   * @return ptr64: A pointer to the vtable associated with the specified name
   */
  inline void* GetGameConfigVTable(ConfigId id, const plg::string& name) {
    return __s2sdk_GetGameConfigVTable(id, name);
  }

  using _GetGameConfigSignature = void* (*)(ConfigId, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetGameConfigSignature __s2sdk_GetGameConfigSignature;
namespace s2sdk {
  /**
   * @brief Retrieves the signature associated with a name from the game configuration.
   * @param id (uint32): An id to the game configuration from which to retrieve the signature.
   * @param name (string): The name whose signature is to be resolved and retrieved.
   * @return ptr64: A pointer to the signature associated with the specified name.
   */
  inline void* GetGameConfigSignature(ConfigId id, const plg::string& name) {
    return __s2sdk_GetGameConfigSignature(id, name);
  }

  using _GetGameConfigPatchAll = plg::string (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetGameConfigPatchAll __s2sdk_GetGameConfigPatchAll;
namespace s2sdk {
  /**
   * @brief Retrieves a patch by scanning all loaded game configurations.
   * @param name (string): The name of the patch to be retrieved.
   * @return string: A string containing the patch, or an empty string if not found.
   */
  inline plg::string GetGameConfigPatchAll(const plg::string& name) {
    return __s2sdk_GetGameConfigPatchAll(name);
  }

  using _GetGameConfigOffsetAll = int32_t (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetGameConfigOffsetAll __s2sdk_GetGameConfigOffsetAll;
namespace s2sdk {
  /**
   * @brief Retrieves an offset by scanning all loaded game configurations.
   * @param name (string): The name whose offset is to be retrieved.
   * @return int32: The offset associated with the specified name, or -1 if not found.
   */
  inline int32_t GetGameConfigOffsetAll(const plg::string& name) {
    return __s2sdk_GetGameConfigOffsetAll(name);
  }

  using _GetGameConfigAddressAll = void* (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetGameConfigAddressAll __s2sdk_GetGameConfigAddressAll;
namespace s2sdk {
  /**
   * @brief Retrieves an address by scanning all loaded game configurations.
   * @param name (string): The name whose address is to be retrieved.
   * @return ptr64: A pointer to the address associated with the specified name, or nullptr if not found.
   */
  inline void* GetGameConfigAddressAll(const plg::string& name) {
    return __s2sdk_GetGameConfigAddressAll(name);
  }

  using _GetGameConfigVTableAll = void* (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetGameConfigVTableAll __s2sdk_GetGameConfigVTableAll;
namespace s2sdk {
  /**
   * @brief Retrieves a vtable by scanning all loaded game configurations.
   * @param name (string): The name of the vtable to be retrieved.
   * @return ptr64: A pointer to the vtable associated with the specified name, or nullptr if not found.
   */
  inline void* GetGameConfigVTableAll(const plg::string& name) {
    return __s2sdk_GetGameConfigVTableAll(name);
  }

  using _GetGameConfigSignatureAll = void* (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_GetGameConfigSignatureAll __s2sdk_GetGameConfigSignatureAll;
namespace s2sdk {
  /**
   * @brief Retrieves a signature by scanning all loaded game configurations.
   * @param name (string): The name whose signature is to be resolved and retrieved.
   * @return ptr64: A pointer to the signature associated with the specified name, or nullptr if not found.
   */
  inline void* GetGameConfigSignatureAll(const plg::string& name) {
    return __s2sdk_GetGameConfigSignatureAll(name);
  }

  /**
   * @brief RAII wrapper for GameConfig handle.
   * @return 
   */
  class GameConfig final {
  public:
    GameConfig() = default;

    /**
     * @brief Loads a game configuration file.
     * @param paths (string[]): The paths to the game configuration file to be loaded.
     * @return 
     */
    explicit GameConfig(const plg::vector<plg::string>& paths)
      : GameConfig(LoadGameConfigFile(paths), Ownership::Owned) {}

    ~GameConfig() {
      destroy();
    }

    GameConfig(const GameConfig&) = delete;
    GameConfig& operator=(const GameConfig&) = delete;

    GameConfig(GameConfig&& other) noexcept
      : _handle(other._handle)
      , _ownership(other._ownership) {
      other.nullify();
    }

    GameConfig& operator=(GameConfig&& other) noexcept {
      if (this != &other) {
        destroy();
        _handle = other._handle;
        _ownership = other._ownership;
        other.nullify();
      }
      return *this;
    }

    GameConfig(ConfigId handle, Ownership ownership = Ownership::Borrowed) : _handle(handle), _ownership(ownership) {}

    [[nodiscard]] auto get() const noexcept { return _handle; }

    [[nodiscard]] auto release() noexcept {
      auto handle = _handle;
      nullify();
      return handle;
    }

    void reset() noexcept {
      destroy();
      nullify();
    }

    void swap(GameConfig& other) noexcept {
      using std::swap;
      swap(_handle, other._handle);
      swap(_ownership, other._ownership);
    }

    friend void swap(GameConfig& lhs, GameConfig& rhs) noexcept { lhs.swap(rhs); }

    explicit operator bool() const noexcept { return _handle != 0; }
    [[nodiscard]] auto operator<=>(const GameConfig& other) const noexcept { return _handle <=> other._handle; }
    [[nodiscard]] bool operator==(const GameConfig& other) const noexcept { return _handle == other._handle; }

    /**
     * @brief Retrieves a patch associated with the game configuration.
     * @param name (string): The name of the patch to be retrieved.
     * @return string: A string where the patch will be stored.
     */
    plg::string GetPatch(const plg::string& name) {
      if (_handle == 0) throw std::runtime_error("GameConfig: empty handle");
      return s2sdk::GetGameConfigPatch(_handle, name);
    }

    /**
     * @brief Retrieves the offset associated with a name from the game configuration.
     * @param name (string): The name whose offset is to be retrieved.
     * @return int32: The offset associated with the specified name.
     */
    int32_t GetOffset(const plg::string& name) {
      if (_handle == 0) throw std::runtime_error("GameConfig: empty handle");
      return s2sdk::GetGameConfigOffset(_handle, name);
    }

    /**
     * @brief Retrieves the address associated with a name from the game configuration.
     * @param name (string): The name whose address is to be retrieved.
     * @return ptr64: A pointer to the address associated with the specified name.
     */
    void* GetAddress(const plg::string& name) {
      if (_handle == 0) throw std::runtime_error("GameConfig: empty handle");
      return s2sdk::GetGameConfigAddress(_handle, name);
    }

    /**
     * @brief Retrieves a vtable associated with the game configuration.
     * @param name (string): The name of the vtable to be retrieved.
     * @return ptr64: A pointer to the vtable associated with the specified name
     */
    void* GetVTable(const plg::string& name) {
      if (_handle == 0) throw std::runtime_error("GameConfig: empty handle");
      return s2sdk::GetGameConfigVTable(_handle, name);
    }

    /**
     * @brief Retrieves the signature associated with a name from the game configuration.
     * @param name (string): The name whose signature is to be resolved and retrieved.
     * @return ptr64: A pointer to the signature associated with the specified name.
     */
    void* GetSignature(const plg::string& name) {
      if (_handle == 0) throw std::runtime_error("GameConfig: empty handle");
      return s2sdk::GetGameConfigSignature(_handle, name);
    }

  private:
    void destroy() const noexcept {
      if (_handle != 0 && _ownership == Ownership::Owned) {
        CloseGameConfigFile(_handle);
      }
    }

    void nullify() noexcept {
      _handle = 0;
      _ownership = Ownership::Borrowed;
    }

    ConfigId _handle{0};
    Ownership _ownership{Ownership::Borrowed};
  };


} // namespace s2sdk
