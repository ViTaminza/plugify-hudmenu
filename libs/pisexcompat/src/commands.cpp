#include <pisex/commands.hpp>

#include <pisex/compat.hpp>
#include <pisex/output.hpp>
#include <pisex/paths.hpp>

#include <s2sdk/s2sdk.hpp>

#include <algorithm>
#include <array>
#include <cctype>
#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace pisex {
namespace {

struct CommandEntry {
	std::string name;	  // lookup key: lowercase, chat trigger stripped
	std::string spelling; // what the callback sees as arg[0]
	bool console = false;
	bool chat = false;
	CommandCallback callback;
};

std::vector<CommandEntry> g_commands;
std::unordered_set<std::string> g_s2sdkNames; // names already handed to AddConsoleCommand
std::vector<CommandCallbackPre> g_chatPre;

// The s2sdk settings ship "!" and "/"; the extra characters cover the common Metamod plugins
// that use "." or "$" and are harmless when the server keeps the default settings.
std::vector<char> g_triggers{'!', '/'};
bool g_triggersLoaded = false;

std::string ToLower(std::string_view text) {
	std::string out(text);
	std::transform(out.begin(), out.end(), out.begin(), [](char c) {
		return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
	});
	return out;
}

// "!ban" -> "ban", "ban" -> "ban"; only a leading trigger character is removed.
std::string StripTrigger(std::string_view name) {
	if (!name.empty() && IsChatTrigger(name.front())) {
		return std::string(name.substr(1));
	}
	return std::string(name);
}

std::string JoinArgs(const plg::vector<plg::string>& args, std::size_t from) {
	std::string out;
	for (std::size_t i = from; i < args.size(); ++i) {
		if (!out.empty()) {
			out.push_back(' ');
		}
		out.append(args[i].data(), args[i].size());
	}
	return out;
}

// The callback sees the command name as it was registered, followed by the arguments
// (Pisex passed CCommand::ArgS(): "mm_kick 3 60" / "!ban 3 60 1h").
std::string BuildContent(std::string_view spelling, const plg::vector<plg::string>& args) {
	std::string out(spelling);
	const std::string rest = JoinArgs(args, 1);
	if (!rest.empty()) {
		out.push_back(' ');
		out.append(rest);
	}
	return out;
}

const CommandEntry* FindEntry(std::string_view name, bool forChat) {
	const std::string lowered = ToLower(name);
	for (auto it = g_commands.rbegin(); it != g_commands.rend(); ++it) {
		if (it->name == lowered && ((forChat && it->chat) || (!forChat && it->console))) {
			return &(*it);
		}
	}
	return nullptr;
}

s2sdk::ResultType CommandTrampoline(int32_t caller, s2sdk::ConCommandContext context,
									const plg::vector<plg::string>& args) {
	try {
		if (args.empty() || args[0].empty()) {
			return s2sdk::ResultType::Continue;
		}
		const std::string_view name(args[0].data(), args[0].size());
		const bool fromChat = context == s2sdk::ConCommandContext::Chat;
		const CommandEntry* entry = FindEntry(name, fromChat);
		if (!entry) {
			// A chat message that does not belong to any registered chat name (for example
			// "!something") is left alone: s2sdk then falls back to the normal say path.
			return s2sdk::ResultType::Continue;
		}
		const std::string content = BuildContent(entry->spelling, args);
		const CommandCallback callback = entry->callback; // copy: the callback may unregister itself
		const bool handled = callback ? callback(caller, content.c_str()) : false;
		return handled ? s2sdk::ResultType::Handled : s2sdk::ResultType::Continue;
	} catch (const std::exception& ex) {
		ErrorLog("pisexcompat: command callback threw: %s", ex.what());
	} catch (...) {
		ErrorLog("pisexcompat: command callback threw an unknown exception");
	}
	// Never propagate: a throwing handler still owns the command.
	return s2sdk::ResultType::Handled;
}

s2sdk::ResultType ChatTrampoline(int32_t caller, s2sdk::ConCommandContext /*context*/,
								 const plg::vector<plg::string>& args) {
	try {
		if (g_chatPre.empty()) {
			return s2sdk::ResultType::Continue;
		}
		const bool isTeam = !args.empty() && args[0] == "say_team";
		const std::string content = JoinArgs(args, 1);
		bool allow = true;
		for (const CommandCallbackPre& callback : g_chatPre) {
			if (!callback) {
				continue;
			}
			if (!callback(caller, content.c_str(), isTeam)) {
				allow = false;
			}
		}
		return allow ? s2sdk::ResultType::Continue : s2sdk::ResultType::Handled;
	} catch (const std::exception& ex) {
		ErrorLog("pisexcompat: chat listener threw: %s", ex.what());
	} catch (...) {
		ErrorLog("pisexcompat: chat listener threw an unknown exception");
	}
	return s2sdk::ResultType::Handled;
}

// Engine commands Pisex plugins hook (e.g. AdminTime hooks "jointeam"). They must only get a
// listener: AddConsoleCommand would create our own command with that name when the game has
// not registered its command yet (seen live: plugins start before the game's "jointeam"
// exists), which shadows the game command and the client gets "not marked
// FCVAR_CLIENT_CAN_EXECUTE". Listeners that cannot attach yet are retried from Poll().
const std::unordered_set<std::string> kGameCommands = {
	"jointeam", "joingame", "spectate", "teammenu", "kill", "explode", "buy", "drop", "use",
	"callvote", "vote", "say", "say_team", "autobuy", "rebuy",
};
std::unordered_set<std::string> g_gameCommandNames; // registered engine-command names we handle
bool g_globalListener = false;

// Engine commands such as "jointeam"/"vote" are not ConCommands in CS2 (the game parses them in
// its ClientCommand path), so neither AddConsoleCommand (creates a shadowing command) nor a named
// AddCommandListener ("Command jointeam is not exists") works. s2sdk's ClientCommand hook runs
// the GLOBAL listeners for every client command, so one global listener dispatches them by name.
s2sdk::ResultType GameCommandTrampoline(int32_t caller, s2sdk::ConCommandContext context,
										const plg::vector<plg::string>& args) {
	// Registered directly with s2sdk (AddCommandListener), and s2sdk does not wrap listener
	// callbacks: nothing may escape into the engine, not even from the lookup below.
	try {
		if (args.empty() || g_gameCommandNames.empty()) {
			return s2sdk::ResultType::Continue;
		}
		if (g_gameCommandNames.count(ToLower(std::string_view(args[0].data(), args[0].size()))) == 0) {
			return s2sdk::ResultType::Continue;
		}
		return CommandTrampoline(caller, context, args);
	} catch (const std::exception& ex) {
		ErrorLog("pisexcompat: game command dispatch threw: %s", ex.what());
	} catch (...) {
		ErrorLog("pisexcompat: game command dispatch threw an unknown exception");
	}
	// Continue: on a failure the engine's own handling of e.g. "jointeam" proceeds as if we had
	// never listened - safer than swallowing the command.
	return s2sdk::ResultType::Continue;
}

void RegisterS2sdkName(const std::string& name) {
	if (name.empty() || g_s2sdkNames.count(name) != 0) {
		return;
	}
	if (kGameCommands.count(name) != 0) {
		g_s2sdkNames.insert(name);
		g_gameCommandNames.insert(name);
		if (!g_globalListener && __s2sdk_AddCommandListener) {
			g_globalListener = s2sdk::AddCommandListener(plg::string(), &GameCommandTrampoline, s2sdk::HookMode::Pre);
		}
		return;
	}
	if (!__s2sdk_AddConsoleCommand) {
		return;
	}
	// Our own commands (mm_*, css_*): client-executable like the Metamod originals
	// (FCVAR_CLIENT_CAN_EXECUTE | FCVAR_RELEASE), Pre hook so Continue lets the engine go on.
	const auto flags = static_cast<s2sdk::ConVarFlag>(static_cast<int64_t>(s2sdk::ConVarFlag::ClientCanExecute) |
													   static_cast<int64_t>(s2sdk::ConVarFlag::Release));
	s2sdk::AddConsoleCommand(name, "pisexcompat", flags, &CommandTrampoline, s2sdk::HookMode::Pre);
	// A false return also covers "already registered" (duplicate registration): not an error.
	g_s2sdkNames.insert(name);
}

} // namespace

void PollCommandRegistrations() {
	// Engine commands are dispatched through one global listener (see GameCommandTrampoline);
	// nothing to retry.
}

void CommandArgs::Tokenize(const char* text) {
	text_.assign(text ? text : "");
	args_.clear();

	std::size_t i = 0;
	const std::size_t size = text_.size();
	while (i < size) {
		while (i < size && std::isspace(static_cast<unsigned char>(text_[i]))) {
			++i;
		}
		if (i >= size) {
			break;
		}
		std::string token;
		if (text_[i] == '"') {
			++i;
			while (i < size && text_[i] != '"') {
				token.push_back(text_[i++]);
			}
			if (i < size) {
				++i; // closing quote
			}
		} else {
			while (i < size && !std::isspace(static_cast<unsigned char>(text_[i]))) {
				token.push_back(text_[i++]);
			}
		}
		args_.push_back(std::move(token));
	}
}

const char* CommandArgs::Arg(int index) const {
	if (index < 0 || static_cast<std::size_t>(index) >= args_.size()) {
		return nullptr;
	}
	return args_[static_cast<std::size_t>(index)].c_str();
}

void CommandArgs::Reset() {
	text_.clear();
	args_.clear();
}

void AddChatTrigger(char trigger) {
	if (!IsChatTrigger(trigger)) {
		g_triggers.push_back(trigger);
	}
}

bool IsChatTrigger(char c) {
	return std::find(g_triggers.begin(), g_triggers.end(), c) != g_triggers.end();
}

void RefreshChatTriggers() {
	if (g_triggersLoaded) {
		return;
	}
	g_triggersLoaded = true;
	// envs/plugins/s2sdk/settings.jsonc sits next to the configs dir:
	//   <game>/addons/plugify/configs   ->   <game>/addons/plugify/envs/plugins/s2sdk/
	const std::string configs = plg::GetConfigsDir ? std::string(plg::GetConfigsDir()) : std::string();
	if (configs.empty()) {
		return;
	}
	const std::string settings = JoinPath(configs, "../envs/plugins/s2sdk/settings.jsonc");
	bool ok = false;
	const std::string text = ReadFile(settings, &ok);
	if (!ok) {
		return;
	}
	// A minimal scan of the two trigger arrays; anything that does not parse leaves the defaults.
	for (const std::string_view key : {"\"PublicChatTrigger\"", "\"SilentChatTrigger\""}) {
		const std::size_t keyPos = text.find(key);
		if (keyPos == std::string::npos) {
			continue;
		}
		const std::size_t open = text.find('[', keyPos);
		const std::size_t close = open == std::string::npos ? std::string::npos : text.find(']', open);
		if (open == std::string::npos || close == std::string::npos) {
			continue;
		}
		for (std::size_t i = open; i < close; ++i) {
			if (text[i] != '"') {
				continue;
			}
			const std::size_t end = text.find('"', i + 1);
			if (end == std::string::npos || end > close) {
				break;
			}
			if (end == i + 2) {
				AddChatTrigger(text[i + 1]); // single-character trigger, all s2sdk supports
			}
			i = end;
		}
	}
}

void RegCommand(const std::vector<std::string>& console, const std::vector<std::string>& chat,
				const CommandCallback& callback) {
	try {
		RefreshChatTriggers();
		for (const std::string& name : console) {
			if (name.empty()) {
				continue;
			}
			CommandEntry entry;
			entry.name = ToLower(name);
			entry.spelling = name;
			entry.console = true;
			entry.callback = callback;
			g_commands.push_back(std::move(entry));
			RegisterS2sdkName(ToLower(name));
		}
		for (const std::string& name : chat) {
			if (name.empty()) {
				continue;
			}
			CommandEntry entry;
			entry.name = ToLower(StripTrigger(name));
			entry.spelling = name;
			entry.chat = true;
			entry.callback = callback;
			const std::string lookup = entry.name;
			g_commands.push_back(std::move(entry));
			RegisterS2sdkName(lookup);
		}
	} catch (const std::exception& ex) {
		ErrorLog("pisexcompat: RegCommand failed: %s", ex.what());
	} catch (...) {
		ErrorLog("pisexcompat: RegCommand failed with an unknown exception");
	}
}

void RegCommand(const char* consoleName, const CommandCallback& callback) {
	std::vector<std::string> names;
	if (consoleName && *consoleName) {
		names.emplace_back(consoleName);
	}
	RegCommand(names, {}, callback);
}

void RegCommand(const std::vector<std::string>& console, const CommandCallback& callback) {
	RegCommand(console, {}, callback);
}

void AddChatListenerPre(const CommandCallbackPre& callback) {
	try {
		const bool first = g_chatPre.empty();
		g_chatPre.push_back(callback);
		if (first && __s2sdk_AddCommandListener) {
			for (const char* name : {"say", "say_team"}) {
				if (!s2sdk::AddCommandListener(name, &ChatTrampoline, s2sdk::HookMode::Pre)) {
					ErrorLog("pisexcompat: could not hook '%s' for chat listeners", name);
				}
			}
		}
	} catch (const std::exception& ex) {
		ErrorLog("pisexcompat: AddChatListenerPre failed: %s", ex.what());
	} catch (...) {
		ErrorLog("pisexcompat: AddChatListenerPre failed with an unknown exception");
	}
}

void RemoveAllCommands() {
	if (__s2sdk_RemoveCommand) {
		for (const std::string& name : g_s2sdkNames) {
			if (g_gameCommandNames.count(name) == 0) {
				s2sdk::RemoveCommand(name, &CommandTrampoline);
			}
		}
	}
	if (__s2sdk_RemoveCommandListener && !g_chatPre.empty()) {
		for (const char* name : {"say", "say_team"}) {
			s2sdk::RemoveCommandListener(name, &ChatTrampoline, s2sdk::HookMode::Pre);
		}
	}
	if (g_globalListener && __s2sdk_RemoveCommandListener) {
		s2sdk::RemoveCommandListener(plg::string(), &GameCommandTrampoline, s2sdk::HookMode::Pre);
	}
	g_globalListener = false;
	g_gameCommandNames.clear();
	g_s2sdkNames.clear();
	g_commands.clear();
	g_chatPre.clear();
}

bool HasChatListeners() {
	return !g_chatPre.empty();
}

bool HasCommands() {
	return !g_commands.empty();
}

} // namespace pisex
