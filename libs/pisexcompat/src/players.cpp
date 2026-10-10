#include <pisex/players.hpp>
#include <pisex/schema.hpp>

#include <pisex/compat.hpp>
#include <pisex/output.hpp>

#include <plg/numerics.hpp>
#include <plg/string.hpp>
#include <s2sdk/s2sdk.hpp>

#include <array>
#include <cctype>
#include <cstdint>
#include <exception>
#include <string>
#include <string_view>
#include <vector>

namespace pisex {
namespace {

std::vector<OnClientAuthorizedCallback> g_authorizedHooks;
bool g_authorizedListenerRegistered = false;

// s2sdk OnClientAuthenticated listener; must not throw into the engine.
void OnClientAuthorizedListener(int32_t playerSlot, uint64_t steamid64) {
	try {
		const std::vector<OnClientAuthorizedCallback> callbacks = g_authorizedHooks;
		for (const OnClientAuthorizedCallback& callback : callbacks) {
			if (callback) {
				callback(playerSlot, steamid64);
			}
		}
	} catch (const std::exception& ex) {
		ErrorLog("pisexcompat: OnClientAuthorized callback threw: %s", ex.what());
	} catch (...) {
		ErrorLog("pisexcompat: OnClientAuthorized callback threw an unknown exception");
	}
}

// Pisex returned engine-owned strings, so a pointer stayed valid. The wrappers keep one string per
// slot: GetPlayerName(a) and GetPlayerName(b) in the same expression both stay valid, which would
// not hold with a single scratch buffer.
constexpr int kSlots = 64;
std::array<std::string, kSlots> g_nameCache;
std::array<std::string, kSlots> g_ipCache;
std::array<std::string, kSlots> g_authCache;
std::array<std::string, kSlots> g_languageCache;

bool Ready(int slot) {
	return IsGameReady() && slot >= 0 && slot < kSlots;
}

// Layer 1 of the client guard: the slot has a client object and the client is connected.
// s2sdk's Player::GetClient() -> utils::GetClientBySlot() needs the server's client list, which
// only exists with a map up (hence Ready()), and answers nullptr - never a crash - for a slot
// whose controller entity does not exist yet (a client that is still connecting). Bots are real
// connected clients and pass. Used by every wrapper whose s2sdk export touches the client object.
bool ClientExists(int slot) {
	return Ready(slot) && __s2sdk_IsClientConnected && s2sdk::IsClientConnected(slot);
}

// Layer 2: the slot also has a controller entity. Player::SetName (SetClientName) dereferences
// the client *and* the controller without any check - a crash seen right after a map start while
// the bots were being created (Player::SetName -> client->GetPlayerSlot() with a null client).
// Everything that reaches the controller/pawn goes through this.
bool ControllerExists(int slot) {
	return ClientExists(slot) && pisex::GetControllerEntity(slot) != 0;
}

// Layer 3: the controller also has a current pawn. The s2sdk exports implemented with
// helpers::GetController2 (GetClientHealth, GetClientArmor, GetClientTeam, RespawnClient,
// ForcePlayerSuicide, SetClientMoveType, TeleportClient, GetClientAbsOrigin, ...) print
// "Cannot execute '...' on invalid player pawn: N" to the console for a controller without one
// (typically a client that is still connecting) and answer nothing. GetClientPawn
// only needs the controller, so it checks silently.
bool PawnExists(int slot) {
	if (!ControllerExists(slot) || !__s2sdk_GetClientPawn) {
		return false;
	}
	try {
		return s2sdk::GetClientPawn(slot) != nullptr;
	} catch (...) {
		return false;
	}
}

std::string ToLower(std::string_view text) {
	std::string out(text);
	for (char& c : out) {
		c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
	}
	return out;
}

void Assign(plg::string value, std::string& out) {
	out.assign(value.data(), value.size());
}

} // namespace

void HookOnClientAuthorized(const OnClientAuthorizedCallback& callback) {
	if (!callback || !__s2sdk_OnClientAuthenticated_Register) {
		return;
	}
	g_authorizedHooks.push_back(callback);
	if (!g_authorizedListenerRegistered) {
		s2sdk::OnClientAuthenticated_Register(&OnClientAuthorizedListener);
		g_authorizedListenerRegistered = true;
	}
}

void RemoveAllPlayerHooks() {
	if (g_authorizedListenerRegistered && __s2sdk_OnClientAuthenticated_Unregister) {
		s2sdk::OnClientAuthenticated_Unregister(&OnClientAuthorizedListener);
		g_authorizedListenerRegistered = false;
	}
	g_authorizedHooks.clear();
}

bool IsFakeClient(int iSlot) {
	if (!Ready(iSlot) || !__s2sdk_IsFakeClient) {
		return false;
	}
	try {
		return s2sdk::IsFakeClient(iSlot);
	} catch (...) {
		return true; // treat as unavailable rather than as a real player
	}
}

bool IsConnected(int iSlot) {
	if (!Ready(iSlot) || !__s2sdk_IsClientConnected) {
		return false;
	}
	try {
		return s2sdk::IsClientConnected(iSlot);
	} catch (...) {
		return false;
	}
}

bool IsInGame(int iSlot) {
	if (!Ready(iSlot) || !__s2sdk_IsClientInGame) {
		return false;
	}
	try {
		return s2sdk::IsClientInGame(iSlot);
	} catch (...) {
		return false;
	}
}

bool IsAuthenticated(int iSlot) {
	if (!Ready(iSlot) || !__s2sdk_IsClientAuthorized) {
		return false;
	}
	try {
		return s2sdk::IsClientAuthorized(iSlot);
	} catch (...) {
		return false;
	}
}

bool IsAlive(int iSlot) {
	if (!Ready(iSlot) || !__s2sdk_IsClientAlive) {
		return false;
	}
	try {
		return s2sdk::IsClientAlive(iSlot);
	} catch (...) {
		return false;
	}
}

uint64_t GetSteamID64(int iSlot) {
	// The s2sdk call itself is null-safe, but for a slot that is not connected it answers from
	// Player::m_unauthenticatedSteamID - which keeps the *previous* occupant's id after a
	// disconnect. Pisex/Metamod returned 0 for a slot without a client; so do we.
	if (!ClientExists(iSlot) || !__s2sdk_GetClientSteamID64) {
		return 0;
	}
	try {
		return s2sdk::GetClientSteamID64(iSlot);
	} catch (...) {
		return 0;
	}
}

const char* GetSteamID(int iSlot) {
	if (!ClientExists(iSlot) || !__s2sdk_GetClientAuthId) {
		return "";
	}
	try {
		Assign(s2sdk::GetClientAuthId(iSlot), g_authCache[static_cast<std::size_t>(iSlot)]);
	} catch (...) {
		g_authCache[static_cast<std::size_t>(iSlot)].clear();
	}
	return g_authCache[static_cast<std::size_t>(iSlot)].c_str();
}

const char* GetPlayerName(int iSlot) {
	if (!ControllerExists(iSlot) || !__s2sdk_GetClientName) {
		return "";
	}
	try {
		std::string& cached = g_nameCache[static_cast<std::size_t>(iSlot)];
		Assign(s2sdk::GetClientName(iSlot), cached);
		// s2sdk answers "<unknown>" when it cannot resolve the client (Player::GetName); the
		// Pisex API returned an empty string there, and callers treat "" as "no name".
		if (cached == "<unknown>") {
			cached.clear();
		}
	} catch (...) {
		g_nameCache[static_cast<std::size_t>(iSlot)].clear();
	}
	return g_nameCache[static_cast<std::size_t>(iSlot)].c_str();
}

void SetPlayerName(int iSlot, const char* szName) {
	// Player::SetName crashes for a slot without a client or without a controller (both are
	// dereferenced unchecked) - never call SetClientName unless the slot is fully in place.
	if (!ControllerExists(iSlot) || !__s2sdk_SetClientName) {
		return;
	}
	try {
		s2sdk::SetClientName(iSlot, plg::string(szName ? szName : ""));
	} catch (...) {
	}
}

const char* GetIpAddress(int iSlot) {
	// Player::GetIpAddress reads the client's net channel, which is null for bots (and only
	// exists once the client is connected): return "" instead of crashing.
	if (!ClientExists(iSlot) || IsFakeClient(iSlot) || !__s2sdk_GetClientIp) {
		return "";
	}
	try {
		Assign(s2sdk::GetClientIp(iSlot), g_ipCache[static_cast<std::size_t>(iSlot)]);
	} catch (...) {
		g_ipCache[static_cast<std::size_t>(iSlot)].clear();
	}
	return g_ipCache[static_cast<std::size_t>(iSlot)].c_str();
}

const char* GetClientLanguage(int iSlot) {
	// Player::GetLanguage returns a cached member (no client dereference), so the plain map-level
	// gate is enough - and it keeps the language s2sdk already knows for a client that is still
	// connecting.
	if (!Ready(iSlot) || !__s2sdk_GetClientLanguage) {
		return "";
	}
	try {
		Assign(s2sdk::GetClientLanguage(iSlot), g_languageCache[static_cast<std::size_t>(iSlot)]);
	} catch (...) {
		g_languageCache[static_cast<std::size_t>(iSlot)].clear();
	}
	return g_languageCache[static_cast<std::size_t>(iSlot)].c_str();
}

int FindPlayer(uint64_t iSteamID64) {
	if (!IsGameReady() || iSteamID64 == 0) {
		return -1;
	}
	const int maxPlayers = GetMaxPlayers();
	for (int slot = 0; slot < maxPlayers; ++slot) {
		if (!IsConnected(slot) || IsFakeClient(slot)) {
			continue;
		}
		if (GetSteamID64(slot) == iSteamID64) {
			return slot;
		}
	}
	return -1;
}

int FindPlayer(const char* szName) {
	if (!IsGameReady() || !szName || !*szName) {
		return -1;
	}
	const std::string wanted = ToLower(szName);
	if (wanted.empty()) {
		return -1;
	}
	const int maxPlayers = GetMaxPlayers();
	// Exact (case-insensitive) match first - cs2-menus compares the name for equality.
	for (int slot = 0; slot < maxPlayers; ++slot) {
		if (!IsConnected(slot) || IsFakeClient(slot)) {
			continue;
		}
		if (ToLower(GetPlayerName(slot)) == wanted) {
			return slot;
		}
	}
	// Substring match as a convenience (the admin core's "find by name" menu uses prefixes).
	for (int slot = 0; slot < maxPlayers; ++slot) {
		if (!IsConnected(slot) || IsFakeClient(slot)) {
			continue;
		}
		if (ToLower(GetPlayerName(slot)).find(wanted) != std::string::npos) {
			return slot;
		}
	}
	return -1;
}

int GetPlayerHealth(int iSlot) {
	if (!PawnExists(iSlot) || !__s2sdk_GetClientHealth) {
		return 0;
	}
	try {
		return s2sdk::GetClientHealth(iSlot);
	} catch (...) {
		return 0;
	}
}

int GetPlayerArmor(int iSlot) {
	if (!PawnExists(iSlot) || !__s2sdk_GetClientArmor) {
		return 0;
	}
	try {
		return s2sdk::GetClientArmor(iSlot);
	} catch (...) {
		return 0;
	}
}

int GetPlayerMoney(int iSlot) {
	if (!ControllerExists(iSlot) || !__s2sdk_GetClientMoney) {
		return 0;
	}
	try {
		return s2sdk::GetClientMoney(iSlot);
	} catch (...) {
		return 0;
	}
}

int GetPlayerTeam(int iSlot) {
	// The team lives on the controller (CBaseEntity::m_iTeamNum, what Pisex read). s2sdk's
	// GetClientTeam goes through the pawn: it answered 0 - and printed a console warning - for every
	// client without a current pawn, so read the controller's field at the cached offset instead.
	if (!ControllerExists(iSlot)) {
		return 0;
	}
	static int s_teamOffset = -1;
	if (s_teamOffset < 0 && __s2sdk_GetEntData2 && __s2sdk_PlayerSlotToEntPointer) {
		s_teamOffset = SchemaOffset("CBaseEntity", "m_iTeamNum");
	}
	try {
		if (s_teamOffset >= 0) {
			void* controller = s2sdk::PlayerSlotToEntPointer(iSlot);
			return controller ? static_cast<int>(s2sdk::GetEntData2(controller, s_teamOffset, 1) & 0xFF) : 0;
		}
		// No offset/binding: the pawn-based export, asked only when a pawn exists (silent otherwise).
		return PawnExists(iSlot) && __s2sdk_GetClientTeam ? static_cast<int>(s2sdk::GetClientTeam(iSlot)) : 0;
	} catch (...) {
		return 0;
	}
}

bool IsPlayerBot(int iSlot) {
	return IsFakeClient(iSlot);
}

void ChangeTeam(int iSlot, int iNewTeam) {
	if (!ControllerExists(iSlot) || !__s2sdk_ChangeClientTeam) {
		return;
	}
	try {
		s2sdk::ChangeClientTeam(iSlot, static_cast<s2sdk::CSTeam>(iNewTeam));
	} catch (...) {
	}
}

void SwitchTeam(int iSlot, int iNewTeam) {
	if (!ControllerExists(iSlot) || !__s2sdk_SwitchClientTeam) {
		return;
	}
	try {
		s2sdk::SwitchClientTeam(iSlot, static_cast<s2sdk::CSTeam>(iNewTeam));
	} catch (...) {
	}
}

void Respawn(int iSlot) {
	if (!PawnExists(iSlot) || !__s2sdk_RespawnClient) {
		return;
	}
	try {
		s2sdk::RespawnClient(iSlot);
	} catch (...) {
	}
}

void CommitSuicide(int iSlot, bool bExplode, bool bForce) {
	if (!PawnExists(iSlot) || !__s2sdk_ForcePlayerSuicide) {
		return;
	}
	try {
		s2sdk::ForcePlayerSuicide(iSlot, bExplode, bForce);
	} catch (...) {
	}
}

void SetMoveType(int iSlot, int moveType) {
	if (!PawnExists(iSlot) || !__s2sdk_SetClientMoveType) {
		return;
	}
	try {
		s2sdk::SetClientMoveType(iSlot, static_cast<s2sdk::MoveType>(moveType));
	} catch (...) {
	}
}

void Teleport(int iSlot, const plg::vec3* position, const plg::vec3* angles, const plg::vec3* velocity) {
	if (!PawnExists(iSlot) || !__s2sdk_TeleportClient) {
		return;
	}
	try {
		plg::vec3 origin = position ? *position : s2sdk::GetClientAbsOrigin(iSlot);
		const plg::vec3 rot = angles ? *angles : plg::vec3{};
		const plg::vec3 velocityOrZero = velocity ? *velocity : plg::vec3{};
		s2sdk::TeleportClient(iSlot, origin, rot, velocityOrZero);
	} catch (...) {
	}
}

void RemoveWeapons(int iSlot) {
	// RemoveWeapons resolves the pawn's item services (helpers::GetService2): it needs a pawn and
	// warns without one, like the GetController2 exports.
	if (!PawnExists(iSlot) || !__s2sdk_RemoveWeapons) {
		return;
	}
	try {
		s2sdk::RemoveWeapons(iSlot, true);
	} catch (...) {
	}
}

int GetPawnEntity(int iSlot) {
	if (!ControllerExists(iSlot) || !__s2sdk_GetClientPawn || !__s2sdk_EntPointerToEntIndex) {
		return 0;
	}
	try {
		void* pawn = s2sdk::GetClientPawn(iSlot);
		return pawn ? s2sdk::EntPointerToEntIndex(pawn) : 0;
	} catch (...) {
		return 0;
	}
}

int GetControllerEntity(int iSlot) {
	if (!Ready(iSlot) || !__s2sdk_PlayerSlotToEntPointer || !__s2sdk_EntPointerToEntIndex) {
		return 0;
	}
	try {
		void* controller = s2sdk::PlayerSlotToEntPointer(iSlot);
		return controller ? s2sdk::EntPointerToEntIndex(controller) : 0;
	} catch (...) {
		return 0;
	}
}

int GetOwnerSlot(int iEntity) {
	if (!IsGameReady() || !__s2sdk_GetEntityOwner || !__s2sdk_ClientPtrToPlayerSlot || !__s2sdk_EntIndexToEntPointer) {
		return -1;
	}
	try {
		const int handle = EntIndexToEntHandle(iEntity); // s2sdk wants/returns handles, not indices
		if (handle == -1) {
			return -1;
		}
		const int owner = EntHandleToEntIndex(s2sdk::GetEntityOwner(handle));
		if (owner <= 0) {
			return -1;
		}
		void* pointer = s2sdk::EntIndexToEntPointer(owner);
		return pointer ? s2sdk::ClientPtrToPlayerSlot(pointer) : -1;
	} catch (...) {
		return -1;
	}
}

bool IsClientReady(int iSlot) {
	return ControllerExists(iSlot);
}

int GetMaxPlayers() {
	if (!__s2sdk_GetMaxClients) {
		return kSlots;
	}
	try {
		const int maxClients = s2sdk::GetMaxClients();
		return maxClients > 0 && maxClients <= kSlots ? maxClients : kSlots;
	} catch (...) {
		return kSlots;
	}
}

} // namespace pisex
