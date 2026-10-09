// pisexcompat — the IPlayersApi subset the admin core and its modules use, over s2sdk.
//
// Every call is guarded by pisex::IsGameReady(): s2sdk client queries crash when they run before a
// map exists (the Pisex plugins could call them any time because the engine objects always
// existed). Outside of a map the wrappers return the neutral value (false / 0 / -1 / ""), so a
// ported plugin that asks for a player name in OnPluginStart gets an empty string instead of a
// dead server.
//
// GetPlayerName()/GetSteamID()/GetIpAddress() return a pointer into a per-slot cache, so combining
// two of them in one expression is safe (the Pisex ones returned engine-owned strings with the
// same property).

#pragma once

#include <cstdint>
#include <functional>
#include <string>

#include <plg/numerics.hpp>

namespace pisex {

// Pisex's OnClientAuthorizedCallback: (slot, steamid64).
using OnClientAuthorizedCallback = std::function<void(int iSlot, uint64_t iSteamID64)>;

// Pisex's IPlayersApi::HookOnClientAuthorized(), on s2sdk's OnClientAuthenticated listener.
// Note the caveat the rest of this repo learned on the live server: OnClientAuthenticated does not
// fire for every client, so a ported plugin should keep (or add) a once-per-second reconcile like
// plugins/perm_connector has. Registering the first callback installs the s2sdk listener.
void HookOnClientAuthorized(const OnClientAuthorizedCallback& callback);
// Drops every callback and the s2sdk listener (Shutdown() calls this).
void RemoveAllPlayerHooks();

bool IsFakeClient(int iSlot);
bool IsConnected(int iSlot);
bool IsInGame(int iSlot);
bool IsAuthenticated(int iSlot);
bool IsAlive(int iSlot);

// The precondition every s2sdk client/player export needs: a map is up (pisexcompat's map
// lifecycle gate - between a map end and the next map start s2sdk's client list is torn down and
// any client query crashes), the slot is in range, the client is connected and its controller
// entity exists (bots included; a client that is still connecting has no controller yet).
// pisexcompat's own wrappers check this before they call into s2sdk, so porting code can use it
// to loop slots silently - an s2sdk call on a slot that fails it logs
// "invalid player slot/pawn" (or, for SetClientName, crashes).
bool IsClientReady(int iSlot);

// 0 when the slot has no authenticated player (or no map is running).
uint64_t GetSteamID64(int iSlot);
// "STEAM_1:0:..." style auth string.
const char* GetSteamID(int iSlot);
const char* GetPlayerName(int iSlot);
void SetPlayerName(int iSlot, const char* szName);
const char* GetIpAddress(int iSlot);
const char* GetClientLanguage(int iSlot);

// -1 when no player matches. FindPlayer(steamid) is exact, FindPlayer(name) is a case-insensitive
// match (exact first, then substring).
int FindPlayer(uint64_t iSteamID64);
int FindPlayer(const char* szName);

int GetPlayerHealth(int iSlot);
int GetPlayerArmor(int iSlot);
int GetPlayerMoney(int iSlot);
int GetPlayerTeam(int iSlot); // 0 none, 1 spectator, 2 T, 3 CT
bool IsPlayerBot(int iSlot);

void ChangeTeam(int iSlot, int iNewTeam);
void SwitchTeam(int iSlot, int iNewTeam);
void Respawn(int iSlot);
void CommitSuicide(int iSlot, bool bExplode, bool bForce);
void SetMoveType(int iSlot, int moveType);
void Teleport(int iSlot, const plg::vec3* position, const plg::vec3* angles, const plg::vec3* velocity);
void RemoveWeapons(int iSlot);

// Entity index (1-based) of the player's pawn / controller, 0 when there is none.
int GetPawnEntity(int iSlot);
int GetControllerEntity(int iSlot);
// Player slot that owns an entity (its controller), -1 when it is not a player-owned entity.
int GetOwnerSlot(int iEntity);

// Number of player slots on this server (s2sdk GetMaxClients, 64 when unavailable).
int GetMaxPlayers();

} // namespace pisex
