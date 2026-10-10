// pisexcompat command-registration test — drives the real CommandTrampoline with a fake s2sdk
// command manager. The global binding __s2sdk_AddConsoleCommand is assigned a fake that records
// every registration (name, flags, callback), and the test then calls the recorded callback the
// way the engine does: caller -1 = the server console, caller >= 0 = a player (from the client
// console or from chat, see ConCommandContext).
//
// The rule under test: RegServerCommand registers a console name without ClientCanExecute and no
// caller slot may reach its handler — a privileged command (vip_give, mm_lvl_reset, …) must only
// run from the server console, like the Metamod CON_COMMAND_F(..., FCVAR_NONE) originals.
// Run by ../test.sh.

#include <pisex/commands.hpp>
#include <pisex/compat.hpp>

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

// --- the fake engine ---------------------------------------------------------------------------

struct FakeCommand {
	std::string name;
	s2sdk::ConVarFlag flags = s2sdk::ConVarFlag::None;
	s2sdk::ConCommandCallback callback = nullptr;
};

std::vector<FakeCommand> g_registered;

bool FakeAddConsoleCommand(const plg::string& name, const plg::string& /*description*/, s2sdk::ConVarFlag flags,
						   s2sdk::ConCommandCallback callback, s2sdk::HookMode /*type*/) {
	g_registered.push_back(FakeCommand{std::string(name.data(), name.size()), flags, callback});
	return true;
}

// The callback s2sdk would invoke for `name` (the first registration wins: duplicate registrations
// only attach a listener to the existing command).
const FakeCommand* FindRegistered(const std::string& name) {
	for (const FakeCommand& command : g_registered) {
		if (command.name == name) {
			return &command;
		}
	}
	return nullptr;
}

s2sdk::ResultType Dispatch(const FakeCommand& command, int32_t caller, s2sdk::ConCommandContext context,
						   std::initializer_list<const char*> args) {
	plg::vector<plg::string> argv;
	for (const char* arg : args) {
		argv.push_back(plg::string(arg));
	}
	return command.callback(caller, context, argv);
}

bool HasFlag(s2sdk::ConVarFlag flags, s2sdk::ConVarFlag flag) {
	return (static_cast<int64_t>(flags) & static_cast<int64_t>(flag)) != 0;
}

// --- tests -------------------------------------------------------------------------------------

void TestFlags() {
	pisex::RegCommand(std::vector<std::string>{"pix_client"}, std::vector<std::string>{},
					  [](int, const char*) { return true; });
	pisex::RegServerCommand(std::vector<std::string>{"pix_server"}, [](int, const char*) { return true; });

	const FakeCommand* client = FindRegistered("pix_client");
	const FakeCommand* server = FindRegistered("pix_server");
	Check(client != nullptr && server != nullptr, "both registrations reach s2sdk");
	if (client == nullptr || server == nullptr) {
		return;
	}
	Check(HasFlag(client->flags, s2sdk::ConVarFlag::ClientCanExecute),
		  "RegCommand keeps ClientCanExecute (players may run it)");
	Check(HasFlag(client->flags, s2sdk::ConVarFlag::Release), "RegCommand keeps Release");
	Check(!HasFlag(server->flags, s2sdk::ConVarFlag::ClientCanExecute),
		  "RegServerCommand drops ClientCanExecute");
	Check(HasFlag(server->flags, s2sdk::ConVarFlag::Release), "RegServerCommand keeps Release");
}

void TestServerOnlyDispatch() {
	int serverCalls = 0;
	int clientCalls = 0;
	int lastSlot = -2;
	std::string serverContent;
	pisex::RegServerCommand(std::vector<std::string>{"pix_give"}, [&](int slot, const char* content) {
		++serverCalls;
		lastSlot = slot;
		serverContent = content ? content : "";
		return true;
	});
	pisex::RegCommand({}, std::vector<std::string>{"!pix_vip"}, [&](int, const char*) {
		++clientCalls;
		return true;
	});

	const FakeCommand* command = FindRegistered("pix_give");
	Check(command != nullptr, "pix_give is registered");
	if (command == nullptr) {
		return;
	}

	// The server console (slot -1) runs the handler and sees the registered spelling + arguments.
	Check(Dispatch(*command, -1, s2sdk::ConCommandContext::Console, {"pix_give", "3", "60", "vip"}) ==
			  s2sdk::ResultType::Handled,
		  "the server console call is handled");
	Check(serverCalls == 1 && lastSlot == -1 && serverContent == "pix_give 3 60 vip",
		  "the server console runs the handler");

	// A player (client console) must not reach it; the call is swallowed, not run.
	serverCalls = 0;
	Check(Dispatch(*command, 3, s2sdk::ConCommandContext::Console, {"pix_give", "3", "60", "vip"}) ==
			  s2sdk::ResultType::Handled,
		  "a client-console call is swallowed (Handled)");
	Check(serverCalls == 0, "a client-console call never runs the handler");

	// Chat cannot reach it either: the name has no chat registration, and the guard covers the
	// call even if a chat dispatch finds it.
	Check(Dispatch(*command, 3, s2sdk::ConCommandContext::Chat, {"pix_give"}) ==
			  s2sdk::ResultType::Continue,
		  "a chat call does not match the console-only name");
	Check(serverCalls == 0, "a chat call never runs the server-only handler");

	// Names are matched case-insensitively (the engine lowercases some inputs).
	Check(Dispatch(*command, -1, s2sdk::ConCommandContext::Console, {"PIX_GIVE"}) ==
			  s2sdk::ResultType::Handled,
		  "the name matches case-insensitively");
	Check(serverCalls == 1, "the case-insensitive server-console call runs the handler");

	// The chat path itself still works for a normal chat command.
	const FakeCommand* chat = FindRegistered("pix_vip");
	Check(chat != nullptr, "the chat name is registered");
	if (chat != nullptr) {
		Check(Dispatch(*chat, 3, s2sdk::ConCommandContext::Chat, {"pix_vip"}) == s2sdk::ResultType::Handled,
			  "a chat command is dispatched to its handler");
		Check(clientCalls == 1, "the chat handler ran");
	}
}

void TestServerOnlyWinsOverRegCommand() {
	int clientHandlerCalls = 0;
	int serverHandlerCalls = 0;
	// The same console name registered both ways: no matter the order, the server-only
	// registration must win for the console path.
	pisex::RegCommand(std::vector<std::string>{"pix_dual"}, std::vector<std::string>{},
					  [&](int, const char*) { ++clientHandlerCalls; return true; });
	pisex::RegServerCommand(std::vector<std::string>{"pix_dual"}, [&](int, const char*) {
		++serverHandlerCalls;
		return true;
	});
	// And the other order, under a second name.
	pisex::RegServerCommand(std::vector<std::string>{"pix_dual2"}, [&](int, const char*) {
		++serverHandlerCalls;
		return true;
	});
	pisex::RegCommand(std::vector<std::string>{"pix_dual2"}, std::vector<std::string>{},
					  [&](int, const char*) { ++clientHandlerCalls; return true; });

	const FakeCommand* dual = FindRegistered("pix_dual");
	const FakeCommand* dual2 = FindRegistered("pix_dual2");
	Check(dual != nullptr && dual2 != nullptr, "both dual registrations reach s2sdk");
	if (dual == nullptr || dual2 == nullptr) {
		return;
	}

	Check(Dispatch(*dual, 3, s2sdk::ConCommandContext::Console, {"pix_dual"}) == s2sdk::ResultType::Handled,
		  "the client call on a dual name is swallowed");
	Check(Dispatch(*dual2, 3, s2sdk::ConCommandContext::Console, {"pix_dual2"}) == s2sdk::ResultType::Handled,
		  "the client call is swallowed in either registration order");
	Check(clientHandlerCalls == 0, "no client handler ran for a dual name");
	Check(Dispatch(*dual, -1, s2sdk::ConCommandContext::Console, {"pix_dual"}) == s2sdk::ResultType::Handled,
		  "the server console call on a dual name is handled");
	Check(Dispatch(*dual2, -1, s2sdk::ConCommandContext::Console, {"pix_dual2"}) == s2sdk::ResultType::Handled,
		  "the server console call is handled in either order");
	Check(serverHandlerCalls == 2 && clientHandlerCalls == 0, "the server-only handler won both times");
}

void TestLastRegistrationWins() {
	int firstCalls = 0;
	int secondCalls = 0;
	pisex::RegCommand(std::vector<std::string>{"pix_dup"}, std::vector<std::string>{},
					  [&](int, const char*) { ++firstCalls; return true; });
	pisex::RegCommand(std::vector<std::string>{"pix_dup"}, std::vector<std::string>{},
					  [&](int, const char*) { ++secondCalls; return true; });

	const FakeCommand* command = FindRegistered("pix_dup");
	Check(command != nullptr, "a duplicate name is registered with s2sdk once");
	if (command != nullptr) {
		Dispatch(*command, -1, s2sdk::ConCommandContext::Console, {"pix_dup"});
	}
	Check(secondCalls == 1 && firstCalls == 0, "the most recently registered handler wins (Pisex map overwrite)");
}

} // namespace

int main() {
	__s2sdk_AddConsoleCommand = &FakeAddConsoleCommand;

	TestFlags();
	TestServerOnlyDispatch();
	TestServerOnlyWinsOverRegCommand();
	TestLastRegistrationWins();

	// Leave the process in the state the other objects of a test binary expect (no s2sdk binding),
	// and drop the registrations again.
	__s2sdk_AddConsoleCommand = nullptr;
	pisex::Shutdown();

	std::printf("%d checks, %d failures\n", g_checks, g_failures);
	return g_failures == 0 ? 0 : 1;
}
