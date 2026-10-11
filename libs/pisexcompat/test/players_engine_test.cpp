// pisexcompat player-wrapper test — drives the real wrappers with fake s2sdk client bindings.
//
// Background (the crash cases this guards against):
//   * pisex::SetPlayerName -> SetClientName -> Player::SetName dereferences a *null client* (and a
//     null controller) -> SIGSEGV at address 0x48 right after a map start, while the bots were
//     being created.
//   * any client query during the map shutdown (MapEnd dispatch) -> utils::GetClientBySlot reads
//     the half-destroyed server's client list -> SIGSEGV at address 0.
//   * s2sdk's Player::GetIpAddress dereferences the net channel, which is null for bots.
// Nothing in this file touches the engine: the __s2sdk_* globals are plain variables, so the test
// installs fakes and counts every call the library makes. Run by ../test.sh.

#include <pisex/compat.hpp> // Poll()/OnMapEndNotify()/OnMapStartNotify(): the map lifecycle gate
#include <pisex/players.hpp>
#include <pisex/schema.hpp> // GetPlayerPawn()

#include <plg/plugin.hpp>

#include <s2sdk/s2sdk.hpp>

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

// A real plugin gets these from PLUGIFY_PLUGIN; the test leaves them null (no plugify module).
namespace plg {
GetBaseDirFn GetBaseDir{nullptr};
GetExtensionsDirFn GetExtensionsDir{nullptr};
GetConfigsDirFn GetConfigsDir{nullptr};
GetDataDirFn GetDataDir{nullptr};
GetLogsDirFn GetLogsDir{nullptr};
GetCacheDirFn GetCacheDir{nullptr};
IsLoadedFn IsLoaded{nullptr};
LogFn Log{nullptr};
BeginZoneFn BeginZone{nullptr};
EndZoneFn EndZone{nullptr};
} // namespace plg

namespace {

int g_checks = 0;
int g_failures = 0;

void Check(bool condition, const std::string& what) {
	++g_checks;
	if (!condition) {
		++g_failures;
		std::printf("FAIL: %s\n", what.c_str());
	}
}

// --- the fake client layer ---------------------------------------------------------------------

struct FakeClient {
	bool connected = false;
	bool fake = false;
	bool controller = false; // PlayerSlotToEntPointer() answers a non-null entity
	bool pawn = true;		 // with a controller: GetClientPawn() answers a non-null pawn
	std::string name;
	uint64_t steamid64 = 0;
	int health = 100;
};

std::vector<FakeClient> g_clients(64);
int g_clientCalls = 0; // every fake below counts into this
int g_setNameCalls = 0;
int g_getNameCalls = 0;
int g_getIpCalls = 0;
int g_getSteamIdCalls = 0;
int g_getHealthCalls = 0;

bool ValidSlot(int32_t slot) {
	return slot >= 0 && slot < static_cast<int32_t>(g_clients.size());
}

const FakeClient& Slot(int32_t slot) {
	static const FakeClient empty;
	return ValidSlot(slot) ? g_clients[static_cast<std::size_t>(slot)] : empty;
}

void ResetClients() {
	g_clients.assign(64, FakeClient{});
	g_clientCalls = g_setNameCalls = g_getNameCalls = g_getIpCalls = g_getSteamIdCalls = g_getHealthCalls = 0;
}

bool FakeIsClientConnected(int32_t slot) {
	++g_clientCalls;
	return Slot(slot).connected;
}

bool FakeIsClientInGame(int32_t slot) {
	++g_clientCalls;
	return Slot(slot).connected;
}

bool FakeIsFakeClient(int32_t slot) {
	++g_clientCalls;
	return Slot(slot).fake;
}

plg::string FakeGetClientName(int32_t slot) {
	++g_clientCalls;
	++g_getNameCalls;
	// s2sdk answers "<unknown>" when it cannot resolve the client (Player::GetName).
	return plg::string(Slot(slot).name.empty() ? "<unknown>" : Slot(slot).name);
}

void FakeSetClientName(int32_t slot, const plg::string& name) {
	++g_clientCalls;
	++g_setNameCalls;
	if (ValidSlot(slot)) {
		g_clients[static_cast<std::size_t>(slot)].name = std::string(name.data(), name.size());
	}
}

plg::string FakeGetClientIp(int32_t slot) {
	(void)slot;
	++g_clientCalls;
	++g_getIpCalls;
	return plg::string("1.2.3.4");
}

uint64_t FakeGetClientSteamID64(int32_t slot) {
	++g_clientCalls;
	++g_getSteamIdCalls;
	return Slot(slot).steamid64;
}

int32_t FakeGetClientHealth(int32_t slot) {
	++g_clientCalls;
	++g_getHealthCalls;
	return Slot(slot).health;
}

void* FakePlayerSlotToEntPointer(int32_t slot) {
	++g_clientCalls;
	// The controller entity index is slot + 1 (like the engine's).
	return Slot(slot).controller ? reinterpret_cast<void*>(static_cast<uintptr_t>(0x1000 + slot + 1)) : nullptr;
}

void* FakeGetClientPawn(int32_t slot) {
	++g_clientCalls;
	const FakeClient& client = Slot(slot);
	return client.controller && client.pawn ? reinterpret_cast<void*>(static_cast<uintptr_t>(0x2000 + slot + 1)) : nullptr;
}

int32_t FakeEntPointerToEntIndex(void* pointer) {
	++g_clientCalls;
	return pointer ? static_cast<int32_t>(reinterpret_cast<uintptr_t>(pointer) - 0x1000) : 0;
}

void InstallFakes() {
	__s2sdk_IsClientConnected = &FakeIsClientConnected;
	__s2sdk_IsClientInGame = &FakeIsClientInGame;
	__s2sdk_IsFakeClient = &FakeIsFakeClient;
	__s2sdk_GetClientName = &FakeGetClientName;
	__s2sdk_SetClientName = &FakeSetClientName;
	__s2sdk_GetClientIp = &FakeGetClientIp;
	__s2sdk_GetClientSteamID64 = &FakeGetClientSteamID64;
	__s2sdk_GetClientHealth = &FakeGetClientHealth;
	__s2sdk_PlayerSlotToEntPointer = &FakePlayerSlotToEntPointer;
	__s2sdk_EntPointerToEntIndex = &FakeEntPointerToEntIndex;
	__s2sdk_GetClientPawn = &FakeGetClientPawn;
}

// --- tests -------------------------------------------------------------------------------------

// The map lifecycle gate: from a map end until the *next* map start (not just the next update)
// no client query may reach s2sdk - its client list is torn down in that window.
void TestMapLifecycleGate() {
	pisex::OnMapEndNotify();
	pisex::Poll();
	Check(!pisex::IsGameReady(), "a map end disables the library until a new map start");
	pisex::OnMapStartNotify();
	Check(!pisex::IsGameReady(), "the map start alone is not enough (the host pumps the updates)");
	pisex::Poll();
	Check(pisex::IsGameReady(), "the first update after a map start is ready");

	// A map with players, then the map ends.
	ResetClients();
	g_clients[3] = FakeClient{.connected = true, .controller = true, .name = "Alice", .steamid64 = 76561198000000001ULL};
	const int before = g_clientCalls;

	pisex::OnMapEndNotify();
	Check(!pisex::IsGameReady(), "the map end disables the library");
	pisex::Poll();
	Check(!pisex::IsGameReady(), "a Poll during the map change does not re-enable it");

	Check(std::string(pisex::GetPlayerName(3)).empty(), "GetPlayerName is empty while no map is up");
	Check(pisex::GetSteamID64(3) == 0, "GetSteamID64 is 0 while no map is up");
	Check(std::string(pisex::GetIpAddress(3)).empty(), "GetIpAddress is empty while no map is up");
	Check(std::string(pisex::GetClientLanguage(3)).empty(), "GetClientLanguage is empty while no map is up");
	Check(!pisex::IsConnected(3), "IsConnected is false while no map is up");
	Check(!pisex::IsInGame(3), "IsInGame is false while no map is up");
	Check(!pisex::IsAuthenticated(3), "IsAuthenticated is false while no map is up");
	Check(!pisex::IsAlive(3), "IsAlive is false while no map is up");
	Check(!pisex::IsFakeClient(3), "IsFakeClient is false while no map is up");
	Check(!pisex::IsClientReady(3), "IsClientReady is false while no map is up");
	Check(pisex::GetPlayerHealth(3) == 0, "health is 0 while no map is up");
	Check(pisex::GetPlayerPawn(3) == 0, "the pawn is 0 while no map is up");
	Check(pisex::GetPawnEntity(3) == 0, "the pawn entity is 0 while no map is up");
	Check(pisex::FindPlayer(76561198000000001ULL) == -1, "FindPlayer finds nobody while no map is up");
	pisex::SetPlayerName(3, "Bob");
	pisex::ChangeTeam(3, 2);
	pisex::Respawn(3);
	Check(g_clientCalls == before, "not one s2sdk client call is made while no map is up");

	// The new map is up: the same calls work again.
	pisex::OnMapStartNotify();
	pisex::Poll();
	Check(pisex::IsGameReady(), "ready again after the new map start");
	Check(std::string(pisex::GetPlayerName(3)) == "Alice", "the client is reachable again");
}

// A slot without a client (or without a controller yet) must never reach SetClientName (the
// crash above), and the read-only wrappers must answer their defaults silently.
void TestClientlessSlotGuards() {
	ResetClients();

	// No client at all.
	pisex::SetPlayerName(5, "x");
	Check(g_setNameCalls == 0, "SetClientName is not called for a slot without a client");
	Check(std::string(pisex::GetPlayerName(5)).empty(), "a slot without a client has an empty name");
	Check(g_getNameCalls == 0, "GetClientName is not called without a client");
	Check(std::string(pisex::GetIpAddress(5)).empty(), "a slot without a client has no IP");
	Check(g_getIpCalls == 0, "GetClientIp is not called without a client");
	Check(pisex::GetPlayerHealth(5) == 0, "health is 0 for a slot without a client");
	Check(g_getHealthCalls == 0, "GetClientHealth is not called without a client");

	// Connected, but the controller entity does not exist yet (a client that is still connecting -
	// exactly the state right after a map start, while the bots are being created).
	g_clients[5].connected = true;
	Check(!pisex::IsClientReady(5), "a connecting client is not client-ready");
	pisex::SetPlayerName(5, "x");
	Check(g_setNameCalls == 0, "SetClientName is not called while the controller does not exist yet");
	Check(std::string(pisex::GetPlayerName(5)).empty(), "a connecting client has an empty name");

	// Fully in place: the writes and reads go through.
	g_clients[5].controller = true;
	Check(pisex::IsClientReady(5), "a connected client with a controller is client-ready");
	pisex::SetPlayerName(5, "Charlie");
	Check(g_setNameCalls == 1, "SetClientName is called once the client and controller exist");
	Check(std::string(pisex::GetPlayerName(5)) == "Charlie", "the name round-trips");
	Check(pisex::GetSteamID64(5) == 0, "a slot without a steam id answers 0");

	// s2sdk's "<unknown>" placeholder becomes an empty name (the Pisex API never returned it).
	g_clients[5].name.clear();
	Check(std::string(pisex::GetPlayerName(5)).empty(), "s2sdk's \"<unknown>\" becomes an empty name");
	Check(g_getNameCalls == 2, "GetClientName was called (and its placeholder normalised)");

	// Bots: GetIpAddress would dereference a null net channel - never call it for a fake client.
	g_clients[5].name = "Bot";
	g_clients[5].fake = true;
	Check(std::string(pisex::GetIpAddress(5)).empty(), "a bot has no IP");
	Check(g_getIpCalls == 0, "GetClientIp is not called for a fake client");
	g_clients[5].fake = false;
	Check(std::string(pisex::GetIpAddress(5)) == "1.2.3.4", "a human's IP is returned");
	Check(g_getIpCalls == 1, "GetClientIp is called for a connected human");

	// Steam ids must not go stale: the s2sdk implementation keeps the previous occupant's
	// unauthenticated id, so a disconnected slot has to answer 0 (Pisex semantics).
	g_clients[5].steamid64 = 76561198000000009ULL;
	Check(pisex::GetSteamID64(5) == 76561198000000009ULL, "a connected client's steam id is returned");
	g_clients[5].connected = false;
	Check(pisex::GetSteamID64(5) == 0, "a disconnected slot answers 0, not the previous occupant's id");

	// Out-of-range slots.
	Check(!pisex::IsClientReady(-1) && !pisex::IsClientReady(64), "out-of-range slots are not client-ready");
	pisex::SetPlayerName(64, "x");
	Check(g_setNameCalls == 1, "an out-of-range slot never reaches SetClientName");
}

// The heap of guards must not break the happy path: a fully connected human and a bot both work.
void TestHappyPath() {
	ResetClients();
	pisex::OnMapStartNotify();
	pisex::Poll();
	Check(pisex::IsGameReady(), "the test map is up");

	g_clients[2] = FakeClient{.connected = true, .controller = true, .name = "Dana", .steamid64 = 76561198000000002ULL,
							  .health = 77};
	g_clients[4] = FakeClient{.connected = true, .fake = true, .controller = true, .name = "BOT Rick"};

	Check(pisex::IsConnected(2) && pisex::IsClientReady(2), "a connected human is ready");
	Check(std::string(pisex::GetPlayerName(2)) == "Dana", "the human's name");
	Check(pisex::GetSteamID64(2) == 76561198000000002ULL, "the human's steam id");
	Check(pisex::GetPlayerHealth(2) == 77, "the human's health");
	// A controller without a pawn (connecting, spectator before the first spawn): s2sdk's
	// GetClientHealth would print "invalid player pawn" - the wrapper answers 0 without calling it.
	g_clients[2].pawn = false;
	const int healthCallsBefore = g_getHealthCalls;
	Check(pisex::GetPlayerHealth(2) == 0 && g_getHealthCalls == healthCallsBefore,
		  "no pawn: health is 0 and GetClientHealth is not called");
	g_clients[2].pawn = true;
	Check(pisex::IsFakeClient(4) && pisex::IsClientReady(4), "a bot is a ready client");
	Check(std::string(pisex::GetPlayerName(4)) == "BOT Rick", "the bot's name");
	Check(pisex::FindPlayer(76561198000000002ULL) == 2, "FindPlayer finds the human");
	Check(pisex::FindPlayer("dana") == 2, "FindPlayer by name is case-insensitive");
	Check(pisex::FindPlayer("rick") == -1, "FindPlayer skips bots");
	pisex::SetPlayerName(4, "BOT Morty");
	Check(std::string(pisex::GetPlayerName(4)) == "BOT Morty", "a bot's name can be set");
}

// The fake bindings are restored to the no-s2sdk state (the other checks rely on it).
void TestWithoutBindings() {
	ResetClients();
	__s2sdk_IsClientConnected = nullptr;
	__s2sdk_IsClientInGame = nullptr;
	__s2sdk_IsFakeClient = nullptr;
	__s2sdk_GetClientName = nullptr;
	__s2sdk_SetClientName = nullptr;
	__s2sdk_GetClientIp = nullptr;
	__s2sdk_GetClientSteamID64 = nullptr;
	__s2sdk_GetClientHealth = nullptr;
	__s2sdk_PlayerSlotToEntPointer = nullptr;
	__s2sdk_EntPointerToEntIndex = nullptr;
	__s2sdk_GetClientPawn = nullptr;

	pisex::OnMapStartNotify();
	pisex::Poll();
	Check(std::string(pisex::GetPlayerName(0)).empty(), "no bindings: an empty name");
	Check(pisex::GetSteamID64(0) == 0, "no bindings: steam id 0");
	Check(!pisex::IsClientReady(0), "no bindings: nothing is client-ready");
	pisex::SetPlayerName(0, "x");
	Check(true, "no bindings: the wrappers stay no-ops");
}

// Handles are index | serial << 15: past serial 65535 a valid handle is a negative int (a real
// pawn handle was -921534371 = index 93, serial 102949). Only -1 is invalid; 0 means "none".
int g_lastIndexQuery = 0;
int32_t FakeEntHandleToEntIndex(int32_t handle) {
	g_lastIndexQuery = handle;
	return static_cast<int32_t>(static_cast<uint32_t>(handle) & 0x7FFFu);
}

void TestNegativeHandles() {
	__s2sdk_EntHandleToEntIndex = &FakeEntHandleToEntIndex;
	Check(pisex::EntHandleToEntIndex(-921534371) == 93, "a negative (high-serial) handle resolves to its index");
	Check(g_lastIndexQuery == -921534371, "the negative handle reaches s2sdk unchanged");
	g_lastIndexQuery = 12345;
	Check(pisex::EntHandleToEntIndex(-1) == 0, "INVALID_EHANDLE_INDEX (-1) is none");
	Check(pisex::EntHandleToEntIndex(0) == 0, "0 is none");
	Check(g_lastIndexQuery == 12345, "-1 and 0 never reach s2sdk");
	__s2sdk_EntHandleToEntIndex = nullptr;
}

} // namespace

int main() {
	std::printf("pisexcompat player-wrapper engine tests (fake s2sdk client bindings)\n");

	InstallFakes();
	pisex::Poll(); // first update: a plugin loaded into a running map becomes ready
	Check(pisex::IsGameReady(), "the first update with no map end seen is ready (mid-map load)");

	TestMapLifecycleGate();
	TestClientlessSlotGuards();
	TestHappyPath();
	TestWithoutBindings();
	TestNegativeHandles();

	std::printf("%d checks, %d failures\n", g_checks, g_failures);
	return g_failures == 0 ? 0 : 1;
}
