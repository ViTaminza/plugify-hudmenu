#pragma once

#include "enums.hpp"
#include "aliases.hpp"
// Generated from s2sdk.pplugin

namespace s2sdk {

  // Handles the execution of a command triggered by a caller. This function processes the command, interprets its context, and handles any provided arguments.
  using ConCommandCallback = ResultType (*)(int32_t, ConCommandContext, const plg::vector<plg::string>&);


  // Handles changes to a console variable's value. This function is called whenever the value of a specific console variable is modified.
  using ConVarCallback = void (*)(uint64_t, const plg::string&, const plg::string&);


  // Handles changes to a console variable's value. This function is called whenever the value of a specific console variable is modified.
  using CvarValueCallback = void (*)(int32_t, int32_t, CvarValueStatus, const plg::string&, const plg::string&, const plg::vector<plg::any>&);


  // Defines a QueueTask Callback.
  using TaskCallback = void (*)(const plg::vector<plg::any>&);


  // This function is a callback handler for entity output events. It is triggered when a specific output event is activated, and it handles the process by passing the activator, the caller, and a delay parameter for the output.
  using HookEntityOutputCallback = ResultType (*)(int32_t, int32_t, float);


  // Handles events triggered by the game event system. This function processes the event data, determines the necessary action, and optionally prevents event broadcasting.
  using EventCallback = ResultType (*)(const plg::string&, void*, bool);


  // Renders the menu's current state (title/items/page) to the client. Backends read state via the getters below. Renders the menu's current state (title/items/page) to the client. Backends read state via the getters below.
  using MenuDisplayCallback = void (*)(MenuId, int32_t);


  // Hides/cleans up whatever UI the backend showed to the client. Hides/cleans up whatever UI the backend showed to the client.
  using MenuCloseCallback = void (*)(MenuId, int32_t);


  // Optional: called every server frame while the client has a menu of this type open (e.g. for input polling). Optional: called every server frame while the client has a menu of this type open (e.g. for input polling).
  using MenuFrameCallback = void (*)(MenuId, int32_t);


  using MenuHandlerCallback = void (*)(MenuId, MenuAction, int32_t, int32_t);


  // Handles the final result of a Yes/No vote. This function is called when a vote concludes, and is responsible for determining whether the vote passed based on the number of 'yes' and 'no' votes. Also receives context about the clients who participated in the vote.
  using YesNoVoteResult = bool (*)(int32_t, int32_t, int32_t, int32_t, const plg::vector<int32_t>&, const plg::vector<int32_t>&);


  using YesNoVoteHandler = void (*)(VoteAction, int32_t, int32_t);


  // This function is invoked when a timer event occurs. It handles the timer-related logic and performs necessary actions based on the event.
  using TimerCallback = void (*)(uint32_t, const plg::vector<plg::any>&);


  // Called when a client attempts to connect, before a player slot is allocated. Return a disconnect reason other than NETWORK_DISCONNECT_INVALID to reject the connection with it: the client is not created, so no player_connect event, OnClientConnected or OnClientDisconnect will follow. Also called for bots (from CreateFakeClient) with the server's local address and a steamId of 0; rejecting a bot means it is not created. Not called for GOTV.
  using OnClientConnectCallback = NetworkDisconnectionReason (*)(const plg::string&, const plg::string&, uint64_t);


  // Called once a client has connected and got a player slot, for players (after OnClientConnect accepted them) and bots alike, right after the player_connect event and before OnClientPutInServer. This callback is paired with OnClientDisconnect.
  using OnClientConnectedCallback = void (*)(int32_t);


  // Called when a client is entering the game.
  using OnClientPutInServerCallback = void (*)(int32_t);


  // Called when a client is disconnecting from the server, for players and bots, before the player_disconnect event. The client data is still available here and is reset once the callbacks return.
  using OnClientDisconnectCallback = void (*)(int32_t, NetworkDisconnectionReason);


  // Called when a client is activated by the game.
  using OnClientActiveCallback = void (*)(int32_t, bool);


  // Called when the server processes a client's signon state message (CServerSideClient::ProcessSignonStateMsg), with the client's current signon state. The same state may be reported more than once. Not called for bots.
  using OnClientSignonStateChangedCallback = void (*)(int32_t, SignonState, int32_t);


  // Called when a client is fully connected to the game.
  using OnClientFullyConnectCallback = void (*)(int32_t);


  // Called whenever the client's settings are changed.
  using OnClientSettingsChangedCallback = void (*)(int32_t);


  // Called when a client receives an auth ID.
  using OnClientAuthenticatedCallback = void (*)(int32_t, uint64_t);


  // Called right before a round terminates.
  using OnRoundTerminatedCallback = void (*)(float, CSRoundEndReason);


  // Called when an entity is created.
  using OnEntityCreatedCallback = void (*)(int32_t);


  // Called when an entity is spawned.
  using OnEntitySpawnedCallback = void (*)(int32_t);


  // Called when when an entity is destroyed.
  using OnEntityDeletedCallback = void (*)(int32_t);


  // When an entity is reparented to another entity.
  using OnEntityParentChangedCallback = void (*)(int32_t, int32_t);


  // When entities are transmitted to another entities.
  using OnServerCheckTransmitCallback = void (*)(const plg::vector<void*>&);


  // Called on every server startup.
  using OnServerStartupCallback = void (*)();


  // Called before server activation to build game session manifest.
  using OnBuildGameSessionManifestCallback = void (*)();


  // Called on every server activate.
  using OnServerActivateCallback = void (*)();


  // Called on every server spawn.
  using OnServerSpawnCallback = void (*)();


  // Called on every server started only once.
  using OnServerStartedCallback = void (*)();


  // Called on every map start.
  using OnMapStartCallback = void (*)();


  // Called on every map end.
  using OnMapEndCallback = void (*)();


  // Called before every server frame. Note that you should avoid doing expensive computations or declaring large local arrays.
  using OnGameFrameCallback = void (*)(bool, bool, bool);


  // Called when the server is not in game.
  using OnUpdateWhenNotInGameCallback = void (*)(float);


  // Called before every server frame, before entities are updated.
  using OnPreWorldUpdateCallback = void (*)(bool);


  // Called when a net message is sent to a single client (e.g. net_SignonState). Messages that never go through here or PostEventAbstract (e.g. svc_ClearAllStringTables, sent as part of the initial signon bundle) are instead only visible through OnSerializeMessage.
  using OnSendNetMessageCallback = void (*)(int32_t, void*);


  // Called for every outgoing net message as it's serialized, regardless of whether it's also visible through OnSendNetMessage or OnPostEventAbstract - this is a catch-all fallback, filter by message id/name if you only care about a specific one. No recipient/client information is available at this level.
  using OnSerializeMessageCallback = void (*)(void*);


  // Callback function for user messages.
  using UserMessageCallback = ResultType (*)(void*);


} // namespace s2sdk
