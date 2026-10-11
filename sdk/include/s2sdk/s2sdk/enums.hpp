#pragma once

#include <cstdint>
// Generated from s2sdk.pplugin

namespace s2sdk {

  // Enum representing various movement types for entities.
  enum class MoveType : int32_t {
    None = 0, // Never moves.
    Isometric = 1, // Previously isometric movement type.
    Walk = 2, // Player only - moving on the ground.
    Fly = 3, // No gravity, but still collides with stuff.
    Flygravity = 4, // Flies through the air and is affected by gravity.
    Vphysics = 5, // Uses VPHYSICS for simulation.
    Push = 6, // No clip to world, push and crush.
    Noclip = 7, // No gravity, no collisions, still has velocity/avelocity.
    Ladder = 8, // Used by players only when going onto a ladder.
    Observer = 9, // Observer movement, depends on player's observer mode.
    Custom = 10, // Allows the entity to describe its own physics.
  };

  // Enum representing rendering modes for materials.
  enum class RenderMode : uint8_t {
    Normal = 0, // Standard rendering mode (src).
    TransColor = 1, // Composite: c*a + dest*(1-a).
    TransTexture = 2, // Composite: src*a + dest*(1-a).
    Glow = 3, // Composite: src*a + dest -- No Z buffer checks -- Fixed size in screen space.
    TransAlpha = 4, // Composite: src*srca + dest*(1-srca).
    TransAdd = 5, // Composite: src*a + dest.
    Environmental = 6, // Not drawn, used for environmental effects.
    TransAddFrameBlend = 7, // Uses a fractional frame value to blend between animation frames.
    TransAlphaAdd = 8, // Composite: src + dest*(1-a).
    WorldGlow = 9, // Same as Glow but not fixed size in screen space.
    None = 10, // No rendering.
    DevVisualizer = 11, // Developer visualizer rendering mode.
  };

  // Enum representing the possible teams in Counter-Strike.
  enum class CSTeam : int32_t {
    None = 0, // No team.
    Spectator = 1, // Spectator team.
    T = 2, // Terrorist team.
    CT = 3, // Counter-Terrorist team.
  };

  // Represents the possible types of data that can be passed as a value in input actions.
  enum class FieldType : int32_t {
    Auto = 0, // Automatically detect the type of the value.
    Float32 = 1, // A 32-bit floating-point number.
    Float64 = 2, // A 64-bit floating-point number.
    Int32 = 3, // A 32-bit signed integer.
    UInt32 = 4, // A 32-bit unsigned integer.
    Int64 = 5, // A 64-bit signed integer.
    UInt64 = 6, // A 64-bit unsigned integer.
    Boolean = 7, // A boolean value (true or false).
    Character = 8, // A single character.
    String = 9, // A managed string object.
    CString = 10, // A null-terminated C-style string.
    HScript = 11, // A script handle, typically for scripting integration.
    EHandle = 12, // An entity handle, used to reference an entity within the system.
    Resource = 13, // A resource handle, such as a file or asset reference.
    Vector3d = 14, // A 3D vector, typically representing position or direction.
    Vector2d = 15, // A 2D vector, for planar data or coordinates.
    Vector4d = 16, // A 4D vector, often used for advanced mathematical representations.
    Color32 = 17, // A 32-bit color value (RGBA).
    QAngle = 18, // A quaternion-based angle representation.
    Quaternion = 19, // A quaternion, used for rotation and orientation calculations.
  };

  // Enum representing various damage types.
  enum class DamageTypes : int32_t {
    DMG_GENERIC = 0, // Generic damage.
    DMG_CRUSH = 1, // Crush damage.
    DMG_BULLET = 2, // Bullet damage.
    DMG_SLASH = 4, // Slash damage.
    DMG_BURN = 8, // Burn damage.
    DMG_VEHICLE = 16, // Vehicle damage.
    DMG_FALL = 32, // Fall damage.
    DMG_BLAST = 64, // Blast damage.
    DMG_CLUB = 128, // Club damage.
    DMG_SHOCK = 256, // Shock damage.
    DMG_SONIC = 512, // Sonic damage.
    DMG_ENERGYBEAM = 1024, // Energy beam damage.
    DMG_DROWN = 16384, // Drowning damage.
    DMG_POISON = 32768, // Poison damage.
    DMG_RADIATION = 65536, // Radiation damage.
    DMG_DROWNRECOVER = 131072, // Recovering from drowning damage.
    DMG_ACID = 262144, // Acid damage.
    DMG_PHYSGUN = 1048576, // Physgun damage.
    DMG_DISSOLVE = 2097152, // Dissolve damage.
    DMG_BLAST_SURFACE = 4194304, // Surface blast damage.
    DMG_BUCKSHOT = 16777216, // Buckshot damage.
    DMG_LASTGENERICFLAG = 16777216, // Last generic flag damage.
    DMG_HEADSHOT = 33554432, // Headshot damage.
    DMG_DANGERZONE = 67108864, // Danger zone damage.
  };

  // Enum representing reasons for network disconnection.
  enum class NetworkDisconnectionReason : int32_t {
    Invalid = 0, // Invalid.
    Shutdown = 1, // Shutdown.
    DisconnectByUser = 2, // Disconnect by user.
    DisconnectByServer = 3, // Disconnect by server.
    Lost = 4, // Lost.
    Overflow = 5, // Overflow.
    SteamBanned = 6, // Steam banned.
    SteamInuse = 7, // Steam inuse.
    SteamTicket = 8, // Steam ticket.
    SteamLogon = 9, // Steam logon.
    SteamAuthcancelled = 10, // Steam authcancelled.
    SteamAuthalreadyused = 11, // Steam authalreadyused.
    SteamAuthinvalid = 12, // Steam authinvalid.
    SteamVacbanstate = 13, // Steam vacbanstate.
    SteamLoggedInElsewhere = 14, // Steam logged in elsewhere.
    SteamVacCheckTimedout = 15, // Steam vac check timedout.
    SteamDropped = 16, // Steam dropped.
    SteamOwnership = 17, // Steam ownership.
    ServerinfoOverflow = 18, // Serverinfo overflow.
    TickmsgOverflow = 19, // Tickmsg overflow.
    StringtablemsgOverflow = 20, // Stringtablemsg overflow.
    DeltaentmsgOverflow = 21, // Deltaentmsg overflow.
    TempentmsgOverflow = 22, // Tempentmsg overflow.
    SoundsmsgOverflow = 23, // Soundsmsg overflow.
    Snapshotoverflow = 24, // Snapshotoverflow.
    Snapshoterror = 25, // Snapshoterror.
    Reliableoverflow = 26, // Reliableoverflow.
    Baddeltatick = 27, // Baddeltatick.
    Nomoresplits = 28, // Nomoresplits.
    Timedout = 29, // Timedout.
    Disconnected = 30, // Disconnected.
    Leavingsplit = 31, // Leavingsplit.
    Differentclasstables = 32, // Differentclasstables.
    Badrelaypassword = 33, // Badrelaypassword.
    Badspectatorpassword = 34, // Badspectatorpassword.
    Hltvrestricted = 35, // Hltvrestricted.
    Nospectators = 36, // Nospectators.
    Hltvunavailable = 37, // Hltvunavailable.
    Hltvstop = 38, // Hltvstop.
    Kicked = 39, // Kicked.
    Banadded = 40, // Banadded.
    Kickbanadded = 41, // Kickbanadded.
    Hltvdirect = 42, // Hltvdirect.
    PureserverClientextra = 43, // Pureserver clientextra.
    PureserverMismatch = 44, // Pureserver mismatch.
    Usercmd = 45, // Usercmd.
    RejectedByGame = 46, // Rejected by game.
    MessageParseError = 47, // Message parse error.
    InvalidMessageError = 48, // Invalid message error.
    BadServerPassword = 49, // Bad server password.
    DirectConnectReservation = 50, // Direct connect reservation.
    ConnectionFailure = 51, // Connection failure.
    NoPeerGroupHandlers = 52, // No peer group handlers.
    Reconnection = 53, // Reconnection.
    Loopshutdown = 54, // Loopshutdown.
    Loopdeactivate = 55, // Loopdeactivate.
    HostEndgame = 56, // Host endgame.
    LoopLevelloadActivate = 57, // Loop levelload activate.
    CreateServerFailed = 58, // Create server failed.
    Exiting = 59, // Exiting.
    RequestHoststateIdle = 60, // Request hoststate idle.
    RequestHoststateHltvrelay = 61, // Request hoststate hltvrelay.
    ClientConsistencyFail = 62, // Client consistency fail.
    ClientUnableToCrcMap = 63, // Client unable to crc map.
    ClientNoMap = 64, // Client no map.
    ClientDifferentMap = 65, // Client different map.
    ServerRequiresSteam = 66, // Server requires steam.
    SteamDenyMisc = 67, // Steam deny misc.
    SteamDenyBadAntiCheat = 68, // Steam deny bad anti cheat.
    ServerShutdown = 69, // Server shutdown.
    ReplayIncompatible = 71, // Replay incompatible.
    ConnectRequestTimedout = 72, // Connect request timedout.
    ServerIncompatible = 73, // Server incompatible.
    LocalproblemManyrelays = 74, // Localproblem manyrelays.
    LocalproblemHostedserverprimaryrelay = 75, // Localproblem hostedserverprimaryrelay.
    LocalproblemNetworkconfig = 76, // Localproblem networkconfig.
    LocalproblemOther = 77, // Localproblem other.
    RemoteTimeout = 79, // Remote timeout.
    RemoteTimeoutConnecting = 80, // Remote timeout connecting.
    RemoteOther = 81, // Remote other.
    RemoteBadcrypt = 82, // Remote badcrypt.
    RemoteCertnottrusted = 83, // Remote certnottrusted.
    Unusual = 84, // Unusual.
    InternalError = 85, // Internal error.
    RejectBadchallenge = 128, // Reject badchallenge.
    RejectNolobby = 129, // Reject nolobby.
    RejectBackgroundMap = 130, // Reject background map.
    RejectSinglePlayer = 131, // Reject single player.
    RejectHiddenGame = 132, // Reject hidden game.
    RejectLanrestrict = 133, // Reject lanrestrict.
    RejectBadpassword = 134, // Reject badpassword.
    RejectServerfull = 135, // Reject serverfull.
    RejectInvalidreservation = 136, // Reject invalidreservation.
    RejectFailedchannel = 137, // Reject failedchannel.
    RejectConnectFromLobby = 138, // Reject connect from lobby.
    RejectReservedForLobby = 139, // Reject reserved for lobby.
    RejectInvalidkeylength = 140, // Reject invalidkeylength.
    RejectOldprotocol = 141, // Reject oldprotocol.
    RejectNewprotocol = 142, // Reject newprotocol.
    RejectInvalidconnection = 143, // Reject invalidconnection.
    RejectInvalidcertlen = 144, // Reject invalidcertlen.
    RejectInvalidsteamcertlen = 145, // Reject invalidsteamcertlen.
    RejectSteam = 146, // Reject steam.
    RejectServerauthdisabled = 147, // Reject serverauthdisabled.
    RejectServercdkeyauthinvalid = 148, // Reject servercdkeyauthinvalid.
    RejectBanned = 149, // Reject banned.
    KickedTeamkilling = 150, // Kicked teamkilling.
    KickedTkStart = 151, // Kicked tk start.
    KickedUntrustedaccount = 152, // Kicked untrustedaccount.
    KickedConvictedaccount = 153, // Kicked convictedaccount.
    KickedCompetitivecooldown = 154, // Kicked competitivecooldown.
    KickedTeamhurting = 155, // Kicked teamhurting.
    KickedHostagekilling = 156, // Kicked hostagekilling.
    KickedVotedoff = 157, // Kicked votedoff.
    KickedIdle = 158, // Kicked idle.
    KickedSuicide = 159, // Kicked suicide.
    KickedNosteamlogin = 160, // Kicked nosteamlogin.
    KickedNosteamticket = 161, // Kicked nosteamticket.
    KickedInputautomation = 162, // Kicked inputautomation.
    KickedVacnetabnormalbehavior = 163, // Kicked vacnetabnormalbehavior.
    KickedInsecureclient = 164, // Kicked insecureclient.
  };

  // Enum representing various flags for ConVars and ConCommands.
  enum class ConVarFlag : int64_t {
    None = 0, // The default, no flags at all.
    LinkedConcommand = 1, // Linked to a ConCommand.
    DevelopmentOnly = 2, // Hidden in released products. Automatically removed if ALLOW_DEVELOPMENT_CVARS is defined.
    GameDll = 4, // Defined by the game DLL.
    ClientDll = 8, // Defined by the client DLL.
    Hidden = 16, // Hidden. Doesn't appear in find or auto-complete. Like DEVELOPMENTONLY but cannot be compiled out.
    Protected = 32, // Server cvar; data is not sent since it's sensitive (e.g., passwords).
    SpOnly = 64, // This cvar cannot be changed by clients connected to a multiplayer server.
    Archive = 128, // Saved to vars.rc.
    Notify = 256, // Notifies players when changed.
    UserInfo = 512, // Changes the client's info string.
    Missing0 = 1024, // Hides the cvar from lookups.
    Unlogged = 2048, // If this is a server cvar, changes are not logged to the file or console.
    Missing1 = 4096, // Hides the cvar from lookups.
    Replicated = 8192, // Server-enforced setting on clients.
    Cheat = 16384, // Only usable in singleplayer/debug or multiplayer with sv_cheats.
    PerUser = 32768, // Causes auto-generated varnameN for splitscreen slots.
    Demo = 65536, // Records this cvar when starting a demo file.
    DontRecord = 131072, // Excluded from demo files.
    Missing2 = 262144, // Reserved for future use.
    Release = 524288, // Cvars tagged with this are available to customers.
    MenuBarItem = 1048576, // Marks the cvar as a menu bar item.
    Missing3 = 2097152, // Reserved for future use.
    NotConnected = 4194304, // Cannot be changed by a client connected to a server.
    VconsoleFuzzyMatching = 8388608, // Enables fuzzy matching for vconsole.
    ServerCanExecute = 16777216, // The server can execute this command on clients.
    ClientCanExecute = 33554432, // Allows clients to execute this command.
    ServerCannotQuery = 67108864, // The server cannot query this cvar's value.
    VconsoleSetFocus = 134217728, // Sets focus in the vconsole.
    ClientCmdCanExecute = 268435456, // IVEngineClient::ClientCmd can execute this command.
    ExecutePerTick = 536870912, // Executes the cvar every tick.
  };

  // Enum representing the possible results of an operation.
  enum class ResultType : int32_t {
    Continue = 0, // The action continues to be processed without interruption.
    Changed = 1, // Indicates that the action has altered the state or behavior during execution.
    Handled = 2, // The action has been successfully handled, and no further action is required.
    Stop = 3, // The action processing is halted, and no further steps will be executed.
  };

  // The command execution context.
  enum class ConCommandContext : int32_t {
    Console = 0, // The command execute from the client's console.
    Chat = 1, // The command execute from the client's chat.
  };

  // Enum representing the type of callback.
  enum class HookMode : uint8_t {
    Pre = 0, // Callback will be executed before the original function
    Post = 1, // Callback will be executed after the original function
  };

  enum class ConVarType : int16_t {
    Invalid = -1, // Invalid type
    Bool = 0, // Boolean type
    Int16 = 1, // 16-bit signed integer
    UInt16 = 2, // 16-bit unsigned integer
    Int32 = 3, // 32-bit signed integer
    UInt32 = 4, // 32-bit unsigned integer
    Int64 = 5, // 64-bit signed integer
    UInt64 = 6, // 64-bit unsigned integer
    Float32 = 7, // 32-bit floating point
    Float64 = 8, // 64-bit floating point (double)
    String = 9, // String type
    Color = 10, // Color type
    Vector2 = 11, // 2D vector
    Vector3 = 12, // 3D vector
    Vector4 = 13, // 4D vector
    Qangle = 14, // Quaternion angle
    Max = 15, // Maximum value (used for bounds checking)
  };

  // Enum representing various flags for ConVars and ConCommands.
  enum class CvarValueStatus : int32_t {
    ValueIntact = 0, // It got the value fine.
    CvarNotFound = 1, // It did not found the value.
    NotACvar = 2, // There's a ConCommand, but it's not a ConVar.
    CvarProtected = 3, // The cvar was marked with FCVAR_SERVER_CAN_NOT_QUERY, so the server is not allowed to have its value.
  };

  // Enum representing the type of callback.
  enum class EventHookError : int32_t {
    Okay = 0, // Indicates that the event hook was successfully created.
    InvalidEvent = 1, // Indicates that the event name provided is invalid or does not exist.
    NotActive = 2, // Indicates that the event system is not currently active or initialized.
    InvalidCallback = 3, // Indicates that the callback function provided is invalid or not compatible with the event system.
  };

  // Enum representing the possible verbosity of a logger.
  enum class LoggingVerbosity : int32_t {
    Off = 0, // Turns off all spew.
    Essential = 1, // Turns on vital logs.
    Default = 2, // Turns on most messages.
    Detailed = 3, // Allows for walls of text that are usually useful.
    Max = 4, // Allows everything.
  };

  // Enum representing the possible verbosity of a logger.
  enum class LoggingSeverity : int32_t {
    Off = 0, // Turns off all spew.
    Detailed = 1, // A debug message.
    Message = 2, // An informative logging message.
    Warning = 3, // A warning, typically non-fatal.
    Assert = 4, // A message caused by an Assert**() operation.
    Error = 5, // An error, typically fatal/unrecoverable.
  };

  // Logging channel behavior flags, set on channel creation.
  enum class LoggingChannelFlags : int32_t {
    ConsoleOnly = 1, // Indicates that the spew is only relevant to interactive consoles.
    DoNotEcho = 2, // Indicates that spew should not be echoed to any output devices.
  };

  // Action passed to a menu's handler callback.
  enum class MenuAction : int32_t {
    Start = 0,
    Select = 1,
    Cancel = 2,
    End = 3
  };

  // Draw style for an individual menu item.
  enum class MenuItemStyle : int32_t {
    Default = 0,
    Disabled = 1,
    Spacer = 2
  };

  // Reason a menu display session was cancelled, passed as `param` on MenuAction::Cancel.
  enum class MenuCancelReason : int32_t {
    Exit = 0,
    Timeout = 1,
    Disconnect = 2,
    Interrupted = 3,
    Destroyed = 4,
    ExitBack = 5
  };

  // Enum representing the possible reasons a vote creation or processing has failed.
  enum class VoteCreateFailed : int32_t {
    Generic = 0, // Generic vote failure.
    TransitioningPlayers = 1, // Vote failed due to players transitioning.
    RateExceeded = 2, // Vote failed because vote rate limit was exceeded.
    YesMustExceedNo = 3, // Vote failed because Yes votes must exceed No votes.
    QuorumFailure = 4, // Vote failed due to quorum not being met.
    IssueDisabled = 5, // Vote failed because the issue is disabled.
    MapNotFound = 6, // Vote failed because the map was not found.
    MapNameRequired = 7, // Vote failed because map name is required.
    FailedRecently = 8, // Vote failed because a similar vote failed recently.
    FailedRecentKick = 9, // Vote to kick failed recently.
    FailedRecentChangeMap = 10, // Vote to change map failed recently.
    FailedRecentSwapTeams = 11, // Vote to swap teams failed recently.
    FailedRecentScrambleTeams = 12, // Vote to scramble teams failed recently.
    FailedRecentRestart = 13, // Vote to restart failed recently.
    TeamCantCall = 14, // Team is not allowed to call vote.
    WaitingForPlayers = 15, // Vote failed because game is waiting for players.
    PlayerNotFound = 16, // Target player was not found.
    CannotKickAdmin = 17, // Cannot kick an admin.
    ScrambleInProgress = 18, // Scramble is currently in progress.
    SwapInProgress = 19, // Swap is currently in progress.
    Spectator = 20, // Spectators are not allowed to vote.
    Disabled = 21, // Voting is disabled.
    NextLevelSet = 22, // Next level is already set.
    Rematch = 23, // Rematch vote failed.
    TooEarlySurrender = 24, // Vote to surrender failed due to being too early.
    Continue = 25, // Vote to continue failed.
    MatchPaused = 26, // Vote failed because match is already paused.
    MatchNotPaused = 27, // Vote failed because match is not paused.
    NotInWarmup = 28, // Vote failed because game is not in warmup.
    Not10Players = 29, // Vote failed because there are not 10 players.
    TimeoutActive = 30, // Vote failed due to an active timeout.
    TimeoutInactive = 31, // Vote failed because timeout is inactive.
    TimeoutExhausted = 32, // Vote failed because timeout has been exhausted.
    CantRoundEnd = 33, // Vote failed because the round can't end now.
    Max = 34, // Sentinel value. Not a real failure reason.
  };

  // Enum representing the possible types of a vote actions.
  enum class VoteAction : int32_t {
    Start = 0, // Triggered when the vote begins. No additional parameters are used.
    Vote = 1, // Triggered when a player casts a vote. 'clientSlot' holds the voter's slot and 'choice' is the selected option (e.g., VOTE_OPTION1 for yes, VOTE_OPTION2 for no).
    End = 2, // Triggered when the vote concludes. 'clientSlot' is typically -1. 'choice' contains the reason the vote ended (from YesNoVoteEndReason).
  };

  // Enum representing the possible types of a vote.
  enum class VoteEndReason : int32_t {
    AllVotes = 0, // All possible votes were cast.
    TimeUp = 1, // Time ran out.
    Cancelled = 2, // The vote got cancelled.
  };

  // Enum representing the possible flags of a timer.
  enum class TimerFlag : int32_t {
    Default = 0, // Timer with no unique properties.
    Repeat = 1, // Timer will repeat until stopped.
    NoMapChange = 2, // Timer will not carry over mapchanges.
  };

  // Enum representing the possible reasons for a round ending in Counter-Strike.
  enum class CSRoundEndReason : int32_t {
    TargetBombed = 1, // Target successfully bombed.
    VIPEscaped = 2, // The VIP has escaped (not present in CS:GO).
    VIPKilled = 3, // VIP has been assassinated (not present in CS:GO).
    TerroristsEscaped = 4, // The terrorists have escaped.
    CTStoppedEscape = 5, // The CTs have prevented most of the terrorists from escaping.
    TerroristsStopped = 6, // Escaping terrorists have all been neutralized.
    BombDefused = 7, // The bomb has been defused.
    CTWin = 8, // Counter-Terrorists win.
    TerroristWin = 9, // Terrorists win.
    Draw = 10, // Round draw.
    HostagesRescued = 11, // All hostages have been rescued.
    TargetSaved = 12, // Target has been saved.
    HostagesNotRescued = 13, // Hostages have not been rescued.
    TerroristsNotEscaped = 14, // Terrorists have not escaped.
    VIPNotEscaped = 15, // VIP has not escaped (not present in CS:GO).
    GameStart = 16, // Game commencing.
    TerroristsSurrender = 17, // Terrorists surrender.
    CTSurrender = 18, // CTs surrender.
    TerroristsPlanted = 19, // Terrorists planted the bomb.
    CTsReachedHostage = 20, // CTs reached the hostage.
    SurvivalWin = 21, // Survival mode win.
    SurvivalDraw = 22, // Survival mode draw.
  };

  // Enum representing different weapon types.
  enum class CSWeaponType : uint32_t {
    Knife = 0,
    Pistol = 1,
    SubmachineGun = 2,
    Rifle = 3,
    Shotgun = 4,
    SniperRifle = 5,
    MachineGun = 6,
    C4 = 7,
    Taser = 8,
    Grenade = 9,
    Equipment = 10,
    StackableItem = 11,
    Unknown = 12
  };

  // Enum representing different weapon categories.
  enum class CSWeaponCategory : uint32_t {
    Other = 0,
    Melee = 1,
    Secondary = 2,
    SMG = 3,
    Rifle = 4,
    Heavy = 5,
    Count = 6
  };

  // Enum representing different gear slots.
  enum class GearSlot : uint32_t {
    Invalid = 4294967295,
    Rifle = 0,
    Pistol = 1,
    Knife = 2,
    Grenades = 3,
    C4 = 4,
    ReservedSlot6 = 5,
    ReservedSlot7 = 6,
    ReservedSlot8 = 7,
    ReservedSlot9 = 8,
    ReservedSlot10 = 9,
    ReservedSlot11 = 10,
    Boosts = 11,
    Utility = 12,
    Count = 13,
    First = 0,
    Last = 12
  };

  // Enum representing different weapon definition indices.
  enum class WeaponDefIndex : uint16_t {
    Invalid = 0,
    Deagle = 1,
    Elite = 2,
    FiveSeven = 3,
    Glock = 4,
    AK47 = 7,
    AUG = 8,
    AWP = 9,
    FAMAS = 10,
    G3SG1 = 11,
    GalilAR = 13,
    M249 = 14,
    M4A1 = 16,
    MAC10 = 17,
    P90 = 19,
    MP5SD = 23,
    UMP45 = 24,
    XM1014 = 25,
    Bizon = 26,
    MAG7 = 27,
    Negev = 28,
    SawedOff = 29,
    Tec9 = 30,
    Taser = 31,
    HKP2000 = 32,
    MP7 = 33,
    MP9 = 34,
    Nova = 35,
    P250 = 36,
    SCAR20 = 38,
    SG556 = 39,
    SSG08 = 40,
    KnifeGG = 41,
    Knife = 42,
    Flashbang = 43,
    HEGrenade = 44,
    SmokeGrenade = 45,
    Molotov = 46,
    Decoy = 47,
    IncGrenade = 48,
    C4 = 49,
    Kevlar = 50,
    AssaultSuit = 51,
    HeavyAssaultSuit = 52,
    Defuser = 55,
    KnifeT = 59,
    M4A1Silencer = 60,
    USPSilencer = 61,
    CZ75A = 63,
    Revolver = 64,
    Bayonet = 500,
    KnifeCSS = 503,
    KnifeFlip = 505,
    KnifeGut = 506,
    KnifeKarambit = 507,
    KnifeM9Bayonet = 508,
    KnifeTactical = 509,
    KnifeFalchion = 512,
    KnifeBowie = 514,
    KnifeButterfly = 515,
    KnifePush = 516,
    KnifeCord = 517,
    KnifeCanis = 518,
    KnifeUrsus = 519,
    KnifeGypsyJackknife = 520,
    KnifeOutdoor = 521,
    KnifeStiletto = 522,
    KnifeWidowmaker = 523,
    KnifeSkeleton = 525,
    KnifeKukri = 526
  };


  /// Ownership type for RAII wrappers
  enum class Ownership : bool { Borrowed, Owned };

} // namespace s2sdk
