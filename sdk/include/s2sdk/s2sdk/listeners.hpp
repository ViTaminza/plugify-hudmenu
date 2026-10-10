#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: listeners)

namespace s2sdk {

  using _OnClientConnect_Register = void (*)(OnClientConnectCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientConnect_Register __s2sdk_OnClientConnect_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientConnect_Register(OnClientConnectCallback callback) {
    return __s2sdk_OnClientConnect_Register(callback);
  }

  using _OnClientConnect_Unregister = void (*)(OnClientConnectCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientConnect_Unregister __s2sdk_OnClientConnect_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientConnect_Unregister(OnClientConnectCallback callback) {
    return __s2sdk_OnClientConnect_Unregister(callback);
  }

  using _OnClientConnect_Post_Register = void (*)(OnClientConnect_PostCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientConnect_Post_Register __s2sdk_OnClientConnect_Post_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientConnect_Post_Register(OnClientConnect_PostCallback callback) {
    return __s2sdk_OnClientConnect_Post_Register(callback);
  }

  using _OnClientConnect_Post_Unregister = void (*)(OnClientConnect_PostCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientConnect_Post_Unregister __s2sdk_OnClientConnect_Post_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientConnect_Post_Unregister(OnClientConnect_PostCallback callback) {
    return __s2sdk_OnClientConnect_Post_Unregister(callback);
  }

  using _OnClientConnected_Register = void (*)(OnClientConnectedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientConnected_Register __s2sdk_OnClientConnected_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientConnected_Register(OnClientConnectedCallback callback) {
    return __s2sdk_OnClientConnected_Register(callback);
  }

  using _OnClientConnected_Unregister = void (*)(OnClientConnectedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientConnected_Unregister __s2sdk_OnClientConnected_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientConnected_Unregister(OnClientConnectedCallback callback) {
    return __s2sdk_OnClientConnected_Unregister(callback);
  }

  using _OnClientPutInServer_Register = void (*)(OnClientPutInServerCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientPutInServer_Register __s2sdk_OnClientPutInServer_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientPutInServer_Register(OnClientPutInServerCallback callback) {
    return __s2sdk_OnClientPutInServer_Register(callback);
  }

  using _OnClientPutInServer_Unregister = void (*)(OnClientPutInServerCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientPutInServer_Unregister __s2sdk_OnClientPutInServer_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientPutInServer_Unregister(OnClientPutInServerCallback callback) {
    return __s2sdk_OnClientPutInServer_Unregister(callback);
  }

  using _OnClientDisconnect_Register = void (*)(OnClientDisconnectCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientDisconnect_Register __s2sdk_OnClientDisconnect_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientDisconnect_Register(OnClientDisconnectCallback callback) {
    return __s2sdk_OnClientDisconnect_Register(callback);
  }

  using _OnClientDisconnect_Unregister = void (*)(OnClientDisconnectCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientDisconnect_Unregister __s2sdk_OnClientDisconnect_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientDisconnect_Unregister(OnClientDisconnectCallback callback) {
    return __s2sdk_OnClientDisconnect_Unregister(callback);
  }

  using _OnClientDisconnect_Post_Register = void (*)(OnClientDisconnect_PostCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientDisconnect_Post_Register __s2sdk_OnClientDisconnect_Post_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientDisconnect_Post_Register(OnClientDisconnect_PostCallback callback) {
    return __s2sdk_OnClientDisconnect_Post_Register(callback);
  }

  using _OnClientDisconnect_Post_Unregister = void (*)(OnClientDisconnect_PostCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientDisconnect_Post_Unregister __s2sdk_OnClientDisconnect_Post_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientDisconnect_Post_Unregister(OnClientDisconnect_PostCallback callback) {
    return __s2sdk_OnClientDisconnect_Post_Unregister(callback);
  }

  using _OnClientActive_Register = void (*)(OnClientActiveCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientActive_Register __s2sdk_OnClientActive_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientActive_Register(OnClientActiveCallback callback) {
    return __s2sdk_OnClientActive_Register(callback);
  }

  using _OnClientActive_Unregister = void (*)(OnClientActiveCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientActive_Unregister __s2sdk_OnClientActive_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientActive_Unregister(OnClientActiveCallback callback) {
    return __s2sdk_OnClientActive_Unregister(callback);
  }

  using _OnClientFullyConnect_Register = void (*)(OnClientFullyConnectCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientFullyConnect_Register __s2sdk_OnClientFullyConnect_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientFullyConnect_Register(OnClientFullyConnectCallback callback) {
    return __s2sdk_OnClientFullyConnect_Register(callback);
  }

  using _OnClientFullyConnect_Unregister = void (*)(OnClientFullyConnectCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientFullyConnect_Unregister __s2sdk_OnClientFullyConnect_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientFullyConnect_Unregister(OnClientFullyConnectCallback callback) {
    return __s2sdk_OnClientFullyConnect_Unregister(callback);
  }

  using _OnClientSettingsChanged_Register = void (*)(OnClientSettingsChangedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientSettingsChanged_Register __s2sdk_OnClientSettingsChanged_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientSettingsChanged_Register(OnClientSettingsChangedCallback callback) {
    return __s2sdk_OnClientSettingsChanged_Register(callback);
  }

  using _OnClientSettingsChanged_Unregister = void (*)(OnClientSettingsChangedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientSettingsChanged_Unregister __s2sdk_OnClientSettingsChanged_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientSettingsChanged_Unregister(OnClientSettingsChangedCallback callback) {
    return __s2sdk_OnClientSettingsChanged_Unregister(callback);
  }

  using _OnClientAuthenticated_Register = void (*)(OnClientAuthenticatedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientAuthenticated_Register __s2sdk_OnClientAuthenticated_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientAuthenticated_Register(OnClientAuthenticatedCallback callback) {
    return __s2sdk_OnClientAuthenticated_Register(callback);
  }

  using _OnClientAuthenticated_Unregister = void (*)(OnClientAuthenticatedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnClientAuthenticated_Unregister __s2sdk_OnClientAuthenticated_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnClientAuthenticated_Unregister(OnClientAuthenticatedCallback callback) {
    return __s2sdk_OnClientAuthenticated_Unregister(callback);
  }

  using _OnRoundTerminated_Register = void (*)(OnRoundTerminatedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnRoundTerminated_Register __s2sdk_OnRoundTerminated_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnRoundTerminated_Register(OnRoundTerminatedCallback callback) {
    return __s2sdk_OnRoundTerminated_Register(callback);
  }

  using _OnRoundTerminated_Unregister = void (*)(OnRoundTerminatedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnRoundTerminated_Unregister __s2sdk_OnRoundTerminated_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnRoundTerminated_Unregister(OnRoundTerminatedCallback callback) {
    return __s2sdk_OnRoundTerminated_Unregister(callback);
  }

  using _OnEntityCreated_Register = void (*)(OnEntityCreatedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnEntityCreated_Register __s2sdk_OnEntityCreated_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnEntityCreated_Register(OnEntityCreatedCallback callback) {
    return __s2sdk_OnEntityCreated_Register(callback);
  }

  using _OnEntityCreated_Unregister = void (*)(OnEntityCreatedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnEntityCreated_Unregister __s2sdk_OnEntityCreated_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnEntityCreated_Unregister(OnEntityCreatedCallback callback) {
    return __s2sdk_OnEntityCreated_Unregister(callback);
  }

  using _OnEntitySpawned_Register = void (*)(OnEntitySpawnedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnEntitySpawned_Register __s2sdk_OnEntitySpawned_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnEntitySpawned_Register(OnEntitySpawnedCallback callback) {
    return __s2sdk_OnEntitySpawned_Register(callback);
  }

  using _OnEntitySpawned_Unregister = void (*)(OnEntitySpawnedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnEntitySpawned_Unregister __s2sdk_OnEntitySpawned_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnEntitySpawned_Unregister(OnEntitySpawnedCallback callback) {
    return __s2sdk_OnEntitySpawned_Unregister(callback);
  }

  using _OnEntityDeleted_Register = void (*)(OnEntityDeletedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnEntityDeleted_Register __s2sdk_OnEntityDeleted_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnEntityDeleted_Register(OnEntityDeletedCallback callback) {
    return __s2sdk_OnEntityDeleted_Register(callback);
  }

  using _OnEntityDeleted_Unregister = void (*)(OnEntityDeletedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnEntityDeleted_Unregister __s2sdk_OnEntityDeleted_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnEntityDeleted_Unregister(OnEntityDeletedCallback callback) {
    return __s2sdk_OnEntityDeleted_Unregister(callback);
  }

  using _OnEntityParentChanged_Register = void (*)(OnEntityParentChangedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnEntityParentChanged_Register __s2sdk_OnEntityParentChanged_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnEntityParentChanged_Register(OnEntityParentChangedCallback callback) {
    return __s2sdk_OnEntityParentChanged_Register(callback);
  }

  using _OnEntityParentChanged_Unregister = void (*)(OnEntityParentChangedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnEntityParentChanged_Unregister __s2sdk_OnEntityParentChanged_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnEntityParentChanged_Unregister(OnEntityParentChangedCallback callback) {
    return __s2sdk_OnEntityParentChanged_Unregister(callback);
  }

  using _OnServerCheckTransmit_Register = void (*)(OnServerCheckTransmitCallback);
}
extern "C" PLUGIN_API s2sdk::_OnServerCheckTransmit_Register __s2sdk_OnServerCheckTransmit_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnServerCheckTransmit_Register(OnServerCheckTransmitCallback callback) {
    return __s2sdk_OnServerCheckTransmit_Register(callback);
  }

  using _OnServerCheckTransmit_Unregister = void (*)(OnServerCheckTransmitCallback);
}
extern "C" PLUGIN_API s2sdk::_OnServerCheckTransmit_Unregister __s2sdk_OnServerCheckTransmit_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnServerCheckTransmit_Unregister(OnServerCheckTransmitCallback callback) {
    return __s2sdk_OnServerCheckTransmit_Unregister(callback);
  }

  using _OnServerStartup_Register = void (*)(OnServerStartupCallback);
}
extern "C" PLUGIN_API s2sdk::_OnServerStartup_Register __s2sdk_OnServerStartup_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnServerStartup_Register(OnServerStartupCallback callback) {
    return __s2sdk_OnServerStartup_Register(callback);
  }

  using _OnServerStartup_Unregister = void (*)(OnServerStartupCallback);
}
extern "C" PLUGIN_API s2sdk::_OnServerStartup_Unregister __s2sdk_OnServerStartup_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnServerStartup_Unregister(OnServerStartupCallback callback) {
    return __s2sdk_OnServerStartup_Unregister(callback);
  }

  using _OnBuildGameSessionManifest_Register = void (*)(OnBuildGameSessionManifestCallback);
}
extern "C" PLUGIN_API s2sdk::_OnBuildGameSessionManifest_Register __s2sdk_OnBuildGameSessionManifest_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnBuildGameSessionManifest_Register(OnBuildGameSessionManifestCallback callback) {
    return __s2sdk_OnBuildGameSessionManifest_Register(callback);
  }

  using _OnBuildGameSessionManifest_Unregister = void (*)(OnBuildGameSessionManifestCallback);
}
extern "C" PLUGIN_API s2sdk::_OnBuildGameSessionManifest_Unregister __s2sdk_OnBuildGameSessionManifest_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnBuildGameSessionManifest_Unregister(OnBuildGameSessionManifestCallback callback) {
    return __s2sdk_OnBuildGameSessionManifest_Unregister(callback);
  }

  using _OnServerActivate_Register = void (*)(OnServerActivateCallback);
}
extern "C" PLUGIN_API s2sdk::_OnServerActivate_Register __s2sdk_OnServerActivate_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnServerActivate_Register(OnServerActivateCallback callback) {
    return __s2sdk_OnServerActivate_Register(callback);
  }

  using _OnServerActivate_Unregister = void (*)(OnServerActivateCallback);
}
extern "C" PLUGIN_API s2sdk::_OnServerActivate_Unregister __s2sdk_OnServerActivate_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnServerActivate_Unregister(OnServerActivateCallback callback) {
    return __s2sdk_OnServerActivate_Unregister(callback);
  }

  using _OnServerSpawn_Register = void (*)(OnServerSpawnCallback);
}
extern "C" PLUGIN_API s2sdk::_OnServerSpawn_Register __s2sdk_OnServerSpawn_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnServerSpawn_Register(OnServerSpawnCallback callback) {
    return __s2sdk_OnServerSpawn_Register(callback);
  }

  using _OnServerSpawn_Unregister = void (*)(OnServerSpawnCallback);
}
extern "C" PLUGIN_API s2sdk::_OnServerSpawn_Unregister __s2sdk_OnServerSpawn_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnServerSpawn_Unregister(OnServerSpawnCallback callback) {
    return __s2sdk_OnServerSpawn_Unregister(callback);
  }

  using _OnServerStarted_Register = void (*)(OnServerStartedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnServerStarted_Register __s2sdk_OnServerStarted_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnServerStarted_Register(OnServerStartedCallback callback) {
    return __s2sdk_OnServerStarted_Register(callback);
  }

  using _OnServerStarted_Unregister = void (*)(OnServerStartedCallback);
}
extern "C" PLUGIN_API s2sdk::_OnServerStarted_Unregister __s2sdk_OnServerStarted_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnServerStarted_Unregister(OnServerStartedCallback callback) {
    return __s2sdk_OnServerStarted_Unregister(callback);
  }

  using _OnMapStart_Register = void (*)(OnMapStartCallback);
}
extern "C" PLUGIN_API s2sdk::_OnMapStart_Register __s2sdk_OnMapStart_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnMapStart_Register(OnMapStartCallback callback) {
    return __s2sdk_OnMapStart_Register(callback);
  }

  using _OnMapStart_Unregister = void (*)(OnMapStartCallback);
}
extern "C" PLUGIN_API s2sdk::_OnMapStart_Unregister __s2sdk_OnMapStart_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnMapStart_Unregister(OnMapStartCallback callback) {
    return __s2sdk_OnMapStart_Unregister(callback);
  }

  using _OnMapEnd_Register = void (*)(OnMapEndCallback);
}
extern "C" PLUGIN_API s2sdk::_OnMapEnd_Register __s2sdk_OnMapEnd_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnMapEnd_Register(OnMapEndCallback callback) {
    return __s2sdk_OnMapEnd_Register(callback);
  }

  using _OnMapEnd_Unregister = void (*)(OnMapEndCallback);
}
extern "C" PLUGIN_API s2sdk::_OnMapEnd_Unregister __s2sdk_OnMapEnd_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnMapEnd_Unregister(OnMapEndCallback callback) {
    return __s2sdk_OnMapEnd_Unregister(callback);
  }

  using _OnGameFrame_Register = void (*)(OnGameFrameCallback);
}
extern "C" PLUGIN_API s2sdk::_OnGameFrame_Register __s2sdk_OnGameFrame_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnGameFrame_Register(OnGameFrameCallback callback) {
    return __s2sdk_OnGameFrame_Register(callback);
  }

  using _OnGameFrame_Unregister = void (*)(OnGameFrameCallback);
}
extern "C" PLUGIN_API s2sdk::_OnGameFrame_Unregister __s2sdk_OnGameFrame_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnGameFrame_Unregister(OnGameFrameCallback callback) {
    return __s2sdk_OnGameFrame_Unregister(callback);
  }

  using _OnUpdateWhenNotInGame_Register = void (*)(OnUpdateWhenNotInGameCallback);
}
extern "C" PLUGIN_API s2sdk::_OnUpdateWhenNotInGame_Register __s2sdk_OnUpdateWhenNotInGame_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnUpdateWhenNotInGame_Register(OnUpdateWhenNotInGameCallback callback) {
    return __s2sdk_OnUpdateWhenNotInGame_Register(callback);
  }

  using _OnUpdateWhenNotInGame_Unregister = void (*)(OnUpdateWhenNotInGameCallback);
}
extern "C" PLUGIN_API s2sdk::_OnUpdateWhenNotInGame_Unregister __s2sdk_OnUpdateWhenNotInGame_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnUpdateWhenNotInGame_Unregister(OnUpdateWhenNotInGameCallback callback) {
    return __s2sdk_OnUpdateWhenNotInGame_Unregister(callback);
  }

  using _OnPreWorldUpdate_Register = void (*)(OnPreWorldUpdateCallback);
}
extern "C" PLUGIN_API s2sdk::_OnPreWorldUpdate_Register __s2sdk_OnPreWorldUpdate_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnPreWorldUpdate_Register(OnPreWorldUpdateCallback callback) {
    return __s2sdk_OnPreWorldUpdate_Register(callback);
  }

  using _OnPreWorldUpdate_Unregister = void (*)(OnPreWorldUpdateCallback);
}
extern "C" PLUGIN_API s2sdk::_OnPreWorldUpdate_Unregister __s2sdk_OnPreWorldUpdate_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnPreWorldUpdate_Unregister(OnPreWorldUpdateCallback callback) {
    return __s2sdk_OnPreWorldUpdate_Unregister(callback);
  }

  using _OnSendNetMessage_Register = void (*)(OnSendNetMessageCallback);
}
extern "C" PLUGIN_API s2sdk::_OnSendNetMessage_Register __s2sdk_OnSendNetMessage_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnSendNetMessage_Register(OnSendNetMessageCallback callback) {
    return __s2sdk_OnSendNetMessage_Register(callback);
  }

  using _OnSendNetMessage_Unregister = void (*)(OnSendNetMessageCallback);
}
extern "C" PLUGIN_API s2sdk::_OnSendNetMessage_Unregister __s2sdk_OnSendNetMessage_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnSendNetMessage_Unregister(OnSendNetMessageCallback callback) {
    return __s2sdk_OnSendNetMessage_Unregister(callback);
  }

  using _OnSerializeMessage_Register = void (*)(OnSerializeMessageCallback);
}
extern "C" PLUGIN_API s2sdk::_OnSerializeMessage_Register __s2sdk_OnSerializeMessage_Register;
namespace s2sdk {
  /**
   * @brief Register callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnSerializeMessage_Register(OnSerializeMessageCallback callback) {
    return __s2sdk_OnSerializeMessage_Register(callback);
  }

  using _OnSerializeMessage_Unregister = void (*)(OnSerializeMessageCallback);
}
extern "C" PLUGIN_API s2sdk::_OnSerializeMessage_Unregister __s2sdk_OnSerializeMessage_Unregister;
namespace s2sdk {
  /**
   * @brief Unregister callback to event.
   * @param callback (function): Function callback.
   */
  inline void OnSerializeMessage_Unregister(OnSerializeMessageCallback callback) {
    return __s2sdk_OnSerializeMessage_Unregister(callback);
  }

} // namespace s2sdk
