// pisexcompat — RegCommand / chat listeners over s2sdk.
//
// Pisex registers console names and chat names separately:
//
//   g_pUtils->RegCommand(g_PLID, {"mm_admin", "css_admin"}, {"!admin"}, OnAdminMenu);
//
// and the callback gets the raw argument string, so the ported handlers keep parsing it with
// CCommand::Tokenize and comparing arg[0] against the registered spelling ("!admin", "mm_admin").
// pisexcompat preserves that: the command name is handed back exactly as it was registered,
// followed by the arguments (space-joined), no matter which trigger the player used.
//
// How the s2sdk side works (verified against libplugify-plugin-s2sdk.so):
//   * ConCommandManager::DispatchConCommand() special-cases "say"/"say_team": when the first
//     argument starts with a trigger from the s2sdk settings (PublicChatTrigger "!", silent "/"),
//     it strips the trigger, tokenizes the rest and dispatches it as a *command* with
//     ConCommandContext::Chat - a silent-trigger message (or one whose command returns
//     Handled/Stop) is then not broadcast at all.
//   * Every command (registered or existing) reaches a callback registered with
//     AddConsoleCommand/AddCommandListener; args[0] is the command name, caller is -1 for the
//     server console.
//   * The chat commands therefore share the console command namespace: chat names are registered
//     with their trigger stripped ("!ban" -> "ban"), and a chat name is dispatched only for chat
//     input while a console name is dispatched only for console input (like Pisex).
//
// Callback contract (unchanged from Pisex):
//   CommandCallback    -> return true  = handled, the engine must not process the command/chat
//                                      message any further (Pisex's MRES_SUPERCEDE)
//                         return false = let the engine continue
//   CommandCallbackPre -> return true  = allow the chat message
//                         return false = block it (Pisex's SendChatListenerPreCallback)

#pragma once

#include <functional>
#include <string>
#include <string_view>
#include <vector>

namespace pisex {

using CommandCallback = std::function<bool(int iSlot, const char* szContent)>;
using CommandCallbackPre = std::function<bool(int iSlot, const char* szContent, bool bTeam)>;

// A stand-in for the engine's CCommand, which the Pisex command handlers use to split the content
// they get handed:
//
//   g_pUtils->RegCommand(..., [](int iSlot, const char* szContent) {
//       CommandArgs arg;
//       arg.Tokenize(szContent);
//       if (strcmp(arg[0], "!ban") == 0 && arg.ArgC() > 3) { ... atoi(arg.Arg(3)) ... }
//       return true;
//   });
//
// Same API as the subset of CCommand the admin core uses: ArgC(), Arg(i), ArgS(), operator[].
// Whitespace separated, double quotes group a token and are removed (the content built by
// RegCommand joins the engine tokens with single spaces, so quoting round-trips).
class CommandArgs {
public:
	CommandArgs() = default;
	explicit CommandArgs(const char* text) { Tokenize(text); }

	// Keeps the raw text (ArgS()) and the parsed tokens.
	void Tokenize(const char* text);
	void Tokenize(std::string_view text) { Tokenize(std::string(text).c_str()); }

	int ArgC() const { return static_cast<int>(args_.size()); }
	// nullptr when the index is out of range (CCommand would read past the end).
	const char* Arg(int index) const;
	const char* operator[](int index) const { return Arg(index); }
	// The whole (unparsed) string, as it was passed to Tokenize().
	const char* ArgS() const { return text_.c_str(); }
	void Reset();

private:
	std::string text_;
	std::vector<std::string> args_;
};

// Registers the console and chat names. Empty vectors are fine; a name may be registered twice
// (the most recently registered handler wins, like Pisex's std::map overwrite). A name that is
// also registered with RegServerCommand stays server-only.
void RegCommand(const std::vector<std::string>& console, const std::vector<std::string>& chat,
				const CommandCallback& callback);
// Convenience overloads for the one-name cases.
void RegCommand(const char* consoleName, const CommandCallback& callback);
void RegCommand(const std::vector<std::string>& console, const CommandCallback& callback);

// Server-console-only variant: registers console names without ClientCanExecute and ignores every
// call from a slot (client console or chat), like the Metamod CON_COMMAND_F(..., FCVAR_NONE)
// commands it replaces.
void RegServerCommand(const std::vector<std::string>& console, const CommandCallback& callback);
void RegServerCommand(const char* consoleName, const CommandCallback& callback);

// Called for every chat message the engine lets through (see README for the three cases s2sdk
// consumes before this point). Pisex's "post" variant cannot be implemented: it needs the mute
// flag of cs2-menus' own chat hook, which s2sdk does not expose.
void AddChatListenerPre(const CommandCallbackPre& callback);

// Extra trigger characters recognised when a chat name is registered ("!" and "/" are built in).
void AddChatTrigger(char trigger);
// Looks up the s2sdk settings (PublicChatTrigger / SilentChatTrigger) by parsing
// envs/plugins/s2sdk/settings.jsonc when it can be found; falls back to the built-in set.
void RefreshChatTriggers();
bool IsChatTrigger(char c);

// Drops every registration (Shutdown() calls this). s2sdk commands are removed with RemoveCommand.
void RemoveAllCommands();
// Internal: retries listeners for engine commands that did not exist yet (called by Poll()).
void PollCommandRegistrations();

// True when at least one command or chat listener is registered (used by IsChatListenerActive).
bool HasChatListeners();
bool HasCommands();

} // namespace pisex
