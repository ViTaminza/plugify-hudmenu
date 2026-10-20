// hudmenu — a Plugify C++ plugin adding the s2sdk menu type "hud": a Panorama on-screen menu
// with mouse clicks, the Plugify equivalent of Pisex cs2-menus MenuType::HUD_LAYOUT (3).
//
// Why a new menu type: s2sdk's built-in "button" backend is WASD-driven and is not usable by
// dead/spectating players, while the Pisex HUD layout (a "custom_hud_layout" entity running
// custom_game/menu_ui.vxml) is click-driven and works regardless of life state.
//
// Flow:
//   * The s2sdk menu manager calls the display/close callbacks of the registered "hud" type
//     (mirroring menu_button.cpp's contract): the display callback renders the current menu
//     state (title/items/page/exit-back) into the layout entity with the CCSCustomHudLayout
//     per-player natives, the close callback hides it and releases input capture.
//   * Panorama buttons produce CCSUsrMsg_CustomHudClicked (usermessage 390). The plugin hooks
//     ISource2GameClients::ClientSvcUserMessage with polyhook, decodes the payload by hand and
//     queues the click.
//   * OnPluginUpdate drains the queue and translates DOM ids into the shared s2sdk menu
//     plumbing the way the built-in backends do:
//       utils-item-<n>  -> SelectMenuItem(slot, pageOffset + n)
//       utils-next/prev -> MenuNextPage / MenuPrevPage
//       utils-closeBtn  -> CancelClientMenu(slot, Exit)     (when the menu has an exit option)
//       utils-back      -> CancelClientMenu(slot, ExitBack) (when it has a back option)
//
// Everything runs on the game thread. No s2sdk call is ever made from inside an s2sdk
// callback or from the polyhook hook callback; the render path only reads menu state through
// the documented getters (the menu manager holds its lock while calling us) and writes to the
// layout entity through engine function pointers.
//
// Fail soft: if s2sdk/polyhook bindings, the gamedata signatures, the libtier0 CUtlString
// functions or the hook are unavailable, the plugin logs once and does not register the "hud"
// type (pisexcompat then falls back to "button"); it never returns Failed from OnPluginStart,
// which would stop every other Plugify plugin.

#include <permissions/permissions.hpp>
#include <plg/any.hpp>
#include <plg/plugin.hpp>
#include <plg/string.hpp>
#include <plg/vector.hpp>
#include <plugin_export.h>
#include <s2sdk/s2sdk.hpp>

#include "click_hook.hpp"
#include "hud_layout.hpp"
#include "log.hpp"
#include "phrases.hpp"
#include "wasd_menu.hpp"

#include <array>
#include <cctype>
#include <charconv>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <exception>
#include <filesystem>
#include <fstream>
#include <string>
#include <string_view>
#include <vector>

#include <nlohmann/json.hpp>

namespace {

constexpr int32_t kMaxSlots = 64;
// The registered menu type name; pisexcompat looks for exactly this name.
constexpr const char* kMenuTypeName = "hud";
// Window title of the standalone test menu opened by hudmenu_test.
constexpr const char* kTestMenuTitle = "hudmenu_test";
constexpr int kTestMenuItems = 10;
constexpr int kTestMenuPerPage = 5;
// Cap of deferred console lines (handlers run under the menu manager's lock and must not
// call back into s2sdk, so their output is queued and flushed from OnPluginUpdate).
constexpr std::size_t kMaxDeferredLines = 64;
// Font of the standalone status command.
constexpr int32_t kConsoleContext = static_cast<int32_t>(s2sdk::ConCommandContext::Console);

// Pisex MenuType numbering (cs2-menus) and the s2sdk menu type name of each entry. The
// numbering is what the permissions cookie stores, so it must stay in this order.
constexpr int kTypeChat = 0;
constexpr int kTypeCenter = 1;
constexpr int kTypeWasd = 2;
constexpr int kTypeHud = 3;
constexpr int kTypeCount = 4;
constexpr const char* kTypeNames[kTypeCount] = {"chat", "centerhtml", "button", "hud"};
// Chooser item phrases, one per type (cs2-menus MenuMenusItem0..3).
constexpr const char* kTypePhraseKeys[kTypeCount] = {"MenuMenusItem0", "MenuMenusItem1", "MenuMenusItem2",
													 "MenuMenusItem3"};
// permissions cookie with the player's choice - the same key Pisex cs2-menus used.
constexpr const char* kCookieName = "Utils.MenuType";
// Delay before a pending cookie write (user not loaded yet) is retried.
constexpr auto kPendingChoiceRetry = std::chrono::seconds(5);
// Delay before a failed cookie lookup (permissions user not loaded yet, storage down) is retried:
// the negative result is remembered so a menu show does not re-query the permissions core.
constexpr auto kCookieLookupRetry = std::chrono::seconds(5);

struct Config {
	std::string layoutPath = "panorama/layout/custom_game/menu_ui.xml";
	std::string addonId = "3810810950";
	bool mountAddon = true;
	bool debugLog = false;
	// Server-wide default when a player has no saved choice: "hud" (or "chat"/"centerhtml"/
	// "button"; the Pisex numbers 0..3 are accepted too). "hud" falls back to "button" while
	// the "hud" backend is not registered.
	std::string defaultMenuType = "hud";
	// The "wasd" (Pisex CENTER_WASD) menu type; defaults mirror the Pisex core.cfg:
	// MenuAddon 0 + MenuURL, TimeoutInputMenu 200, StopingUser 0, sound_type 0.
	hudmenu::WasdMenuBackend::Config wasd;
};

// A console/chat line queued by a menu handler (never logged/called with the manager lock held).
struct DeferredLine {
	int32_t replyTo = -1; // player slot to echo to, -1 = log only
	bool toChat = false;  // true: PrintToChat, false: ReplyToCommand (console)
	std::string text;
};

// A chooser selection made inside the menu handler, applied from OnPluginUpdate.
struct PendingChoiceApply {
	int32_t slot = -1;
	int index = -1;
};

// plg::any (permissions cookie value) -> Pisex menu type index. Accepts the int64 this plugin
// writes, the other integral widths, a string ("3" - Metamod-era Pisex cookie stores wrote
// strings) and bool. False when the value is none of those or out of range.
bool CookieValueToTypeIndex(const plg::any& value, int& out) {
	int64_t raw = 0;
	if (plg::holds_alternative<int64_t>(value)) {
		raw = plg::get<int64_t>(value);
	} else if (plg::holds_alternative<int32_t>(value)) {
		raw = plg::get<int32_t>(value);
	} else if (plg::holds_alternative<uint64_t>(value)) {
		raw = static_cast<int64_t>(plg::get<uint64_t>(value));
	} else if (plg::holds_alternative<uint32_t>(value)) {
		raw = plg::get<uint32_t>(value);
	} else if (plg::holds_alternative<int16_t>(value)) {
		raw = plg::get<int16_t>(value);
	} else if (plg::holds_alternative<uint16_t>(value)) {
		raw = plg::get<uint16_t>(value);
	} else if (plg::holds_alternative<int8_t>(value)) {
		raw = plg::get<int8_t>(value);
	} else if (plg::holds_alternative<uint8_t>(value)) {
		raw = plg::get<uint8_t>(value);
	} else if (plg::holds_alternative<bool>(value)) {
		raw = plg::get<bool>(value) ? 1 : 0;
	} else if (plg::holds_alternative<plg::string>(value)) {
		const std::string text = hudmenu::ToString(plg::get<plg::string>(value));
		int64_t parsed = 0;
		const auto [end, error] = std::from_chars(text.data(), text.data() + text.size(), parsed);
		if (error != std::errc() || end != text.data() + text.size()) {
			return false;
		}
		raw = parsed;
	} else {
		return false;
	}
	if (raw < 0 || raw >= kTypeCount) {
		return false;
	}
	out = static_cast<int>(raw);
	return true;
}

class HudMenuPlugin final : public plg::Plugin, public hudmenu::WasdMenuHost {
public:
	plg::PluginResult OnPluginStart() override;
	plg::PluginResult OnPluginUpdate(std::chrono::milliseconds dt) override;
	plg::PluginResult OnPluginEnd() override;

	// --- hudmenu::WasdMenuHost (the "wasd" backend's phrase/debug access) ---
	std::string WasdPhrase(std::string_view key, int32_t slot) const override;
	void WasdDebug(std::string_view message) const override;

	// --- s2sdk menu type backend (called by the menu manager, lock held) ---
	void OnHudDisplay(s2sdk::MenuId id, int32_t slot);
	void OnHudClose(s2sdk::MenuId id, int32_t slot);

	// --- engine listeners ---
	void OnMapStart();
	void OnMapEnd();
	void OnClientDisconnect(int32_t slot, s2sdk::NetworkDisconnectionReason reason);

	// --- permissions listener body (synchronous inside LoadUser) ---
	void OnPermissionsUserLoaded(uint64_t targetId);

	// --- console commands ---
	s2sdk::ResultType OnTestCommand(int32_t caller, s2sdk::ConCommandContext context,
									const plg::vector<plg::string>& args);
	s2sdk::ResultType OnStatusCommand(int32_t caller, s2sdk::ConCommandContext context,
									  const plg::vector<plg::string>& args);
	// '!menu' (chat) / 'mm_menu' (console): opens the menu type chooser for a player.
	s2sdk::ResultType OnMenuCommand(int32_t caller, s2sdk::ConCommandContext context,
									const plg::vector<plg::string>& args);
	// Handler of the standalone test menu (runs under the menu manager's lock).
	void OnTestMenu(s2sdk::MenuId id, s2sdk::MenuAction action, int32_t slot, int32_t param);
	// Handler of the type chooser (runs under the menu manager's lock).
	void OnChooserMenu(s2sdk::MenuId id, s2sdk::MenuAction action, int32_t slot, int32_t param);

	// --- the exported methods (see hudmenu.pplugin) ---
	// Called by other plugins (pisexcompat) on the game thread.
	plg::string ClientMenuType(int32_t playerSlot);
	bool SaveClientMenuType(int32_t playerSlot, std::string_view type);

private:
	bool BindingsAvailable(std::string& error) const;
	void LoadConfig();
	void LoadPhrases();
	bool LoadGamedata(s2sdk::ConfigId& config, std::string& error) const;
	void MountWorkshopAddon();
	void RejectClick(int32_t slot, const std::string& reason);
	void DispatchClick(const hudmenu::PendingClick& click);
	void QueueLine(int32_t replyTo, std::string text, bool toChat = false);
	void FlushDeferred();
	void Teardown();

	// --- menu type choice (Pisex cs2-menus "!menu") ---
	struct SlotChoice {
		uint64_t steamid = 0; // who the cache belongs to
		bool cached = false;  // `type` is known for this steamid (or "no cookie" was confirmed)
		bool hadCookie = false;
		int8_t type = -1; // saved Pisex type index, -1 = none
		// A choice made before the permissions user existed; written once the user loads.
		int8_t pending = -1;
		std::chrono::steady_clock::time_point nextPendingAttempt{};
		// Earliest retry of a failed cookie lookup; the epoch means "on the next lookup".
		std::chrono::steady_clock::time_point nextCookieAttempt{};
	};

	[[nodiscard]] bool HudRegistered() const;
	[[nodiscard]] int DefaultTypeIndex() const { return m_defaultTypeIndex; }
	// The s2sdk type name for a Pisex index ("hud" only while registered).
	[[nodiscard]] const char* TypeNameForIndex(int index) const;
	static int ParseTypeName(std::string_view name); // -1 when unknown
	[[nodiscard]] bool WasdRegistered() const { return m_wasd.Registered(); }
	bool SlotSteamId(int32_t slot, uint64_t& steamid) const;
	int EffectiveSlotTypeIndex(int32_t slot);
	void CacheChoiceFromCookie(int32_t slot);
	// Writes the permissions cookie for an already validated choice (no cache change).
	bool PersistChoice(int32_t slot, int index);
	bool SaveSlotChoiceIndex(int32_t slot, int index);
	void PollPendingChoices();
	bool OpenTypeChooser(int32_t slot);
	[[nodiscard]] std::string PlayerLanguage(int32_t slot) const;
	[[nodiscard]] std::string Phrase(std::string_view key, int32_t slot) const;

	hudmenu::HudLayout m_layout;
	hudmenu::WasdMenuBackend m_wasd{*this};
	Config m_config;
	hudmenu::Phrases m_phrases;
	std::array<SlotChoice, kMaxSlots> m_choices{};
	int m_defaultTypeIndex = kTypeHud;
	s2sdk::ConfigId m_gamedata = 0;
	int32_t m_vtableIndex = 38; // IAppSystem 11 virtuals + 27 before ClientSvcUserMessage
	// Menu handle currently displayed to each slot with the "hud" type (0 = none).
	std::array<s2sdk::MenuId, kMaxSlots> m_displayed{};
	std::vector<DeferredLine> m_deferred;
	std::size_t m_deferredDropped = 0;
	std::vector<PendingChoiceApply> m_pendingChoiceApply;

	bool m_s2sdkListenersRegistered = false;
	bool m_testCommandRegistered = false;
	bool m_statusCommandRegistered = false;
	bool m_menuCommandRegistered = false;
	bool m_menuListenerRegistered = false;
	bool m_mmMenuCommandRegistered = false;
	bool m_menuTypeRegistered = false;
	bool m_permissionsAvailable = false;
	bool m_permissionsListenerRegistered = false;
	bool m_layoutFailureLogged = false;
	int m_rejectLogs = 0;
	bool m_firstClickLogged = false;
	// True only while a map is running: from OnMapStart (or the first update for a plugin loaded
	// into a live map) until OnMapEnd. Between the map end and the next map start s2sdk's client
	// list and entity system are torn down and ANY client/entity query crashes; the same state
	// machine pisexcompat uses.
	bool m_gameReady = false;
	bool m_mapStartSeen = false; // an OnMapStart arrived since the last OnMapEnd
	bool m_mapEndSeen = false;   // an OnMapEnd arrived since the last OnMapStart
	bool m_started = false;
};

HudMenuPlugin g_hudMenuPlugin;

// --- trampolines (nothing may throw into plugify/s2sdk) -----------------------

void OnHudDisplayTrampoline(s2sdk::MenuId id, int32_t slot) {
	try {
		g_hudMenuPlugin.OnHudDisplay(id, slot);
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: exception in display callback: ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: unknown exception in display callback");
	}
}

void OnHudCloseTrampoline(s2sdk::MenuId id, int32_t slot) {
	try {
		g_hudMenuPlugin.OnHudClose(id, slot);
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: exception in close callback: ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: unknown exception in close callback");
	}
}

void OnMapStartTrampoline() {
	try {
		g_hudMenuPlugin.OnMapStart();
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: exception in OnMapStart: ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: unknown exception in OnMapStart");
	}
}

void OnMapEndTrampoline() {
	try {
		g_hudMenuPlugin.OnMapEnd();
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: exception in OnMapEnd: ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: unknown exception in OnMapEnd");
	}
}

void OnClientDisconnectTrampoline(int32_t slot, s2sdk::NetworkDisconnectionReason reason) {
	try {
		g_hudMenuPlugin.OnClientDisconnect(slot, reason);
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: exception in OnClientDisconnect: ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: unknown exception in OnClientDisconnect");
	}
}

void OnTestMenuTrampoline(s2sdk::MenuId id, s2sdk::MenuAction action, int32_t slot, int32_t param) {
	try {
		g_hudMenuPlugin.OnTestMenu(id, action, slot, param);
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: exception in the test menu handler: ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: unknown exception in the test menu handler");
	}
}

s2sdk::ResultType OnTestCommandTrampoline(int32_t caller, s2sdk::ConCommandContext context,
										  const plg::vector<plg::string>& args) {
	try {
		return g_hudMenuPlugin.OnTestCommand(caller, context, args);
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: exception in 'hudmenu_test': ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: unknown exception in 'hudmenu_test'");
	}
	return s2sdk::ResultType::Handled;
}

s2sdk::ResultType OnStatusCommandTrampoline(int32_t caller, s2sdk::ConCommandContext context,
											const plg::vector<plg::string>& args) {
	try {
		return g_hudMenuPlugin.OnStatusCommand(caller, context, args);
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: exception in 'hudmenu_status': ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: unknown exception in 'hudmenu_status'");
	}
	return s2sdk::ResultType::Handled;
}

void OnChooserMenuTrampoline(s2sdk::MenuId id, s2sdk::MenuAction action, int32_t slot, int32_t param) {
	try {
		g_hudMenuPlugin.OnChooserMenu(id, action, slot, param);
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: exception in the type chooser handler: ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: unknown exception in the type chooser handler");
	}
}

s2sdk::ResultType OnMenuCommandTrampoline(int32_t caller, s2sdk::ConCommandContext context,
										  const plg::vector<plg::string>& args) {
	try {
		return g_hudMenuPlugin.OnMenuCommand(caller, context, args);
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: exception in 'mm_menu': ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: unknown exception in 'mm_menu'");
	}
	return s2sdk::ResultType::Handled;
}

void OnPermissionsUserLoadedTrampoline(int64_t pluginID, uint64_t targetId, permissions::PlayerState state) {
	(void)pluginID;
	(void)state;
	try {
		g_hudMenuPlugin.OnPermissionsUserLoaded(targetId);
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: exception in OnUserLoaded: ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: unknown exception in OnUserLoaded");
	}
}

std::string ToLower(std::string_view text) {
	std::string out(text);
	for (char& c : out) {
		c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
	}
	return out;
}

// Config readers that also accept the Pisex core.cfg style (0/1 integers where a bool is
// expected, numbers written as strings where a number is expected).
bool ReadConfigBool(const nlohmann::json& object, const char* key, bool fallback) {
	if (!object.contains(key)) {
		return fallback;
	}
	const nlohmann::json& value = object[key];
	if (value.is_boolean()) {
		return value.get<bool>();
	}
	if (value.is_number_integer()) {
		return value.get<int64_t>() != 0;
	}
	if (value.is_number_float()) {
		return value.get<double>() != 0.0;
	}
	return fallback;
}

int ReadConfigInt(const nlohmann::json& object, const char* key, int fallback) {
	if (!object.contains(key)) {
		return fallback;
	}
	const nlohmann::json& value = object[key];
	if (value.is_number_integer()) {
		return static_cast<int>(value.get<int64_t>());
	}
	if (value.is_number_float()) {
		return static_cast<int>(value.get<double>());
	}
	if (value.is_string()) {
		const std::string text = value.get<std::string>();
		int parsed = 0;
		const auto [end, error] = std::from_chars(text.data(), text.data() + text.size(), parsed);
		if (error == std::errc() && end == text.data() + text.size()) {
			return parsed;
		}
	}
	return fallback;
}

std::string ReadConfigString(const nlohmann::json& object, const char* key, std::string fallback) {
	if (!object.contains(key)) {
		return fallback;
	}
	const nlohmann::json& value = object[key];
	if (value.is_string()) {
		return value.get<std::string>();
	}
	if (value.is_number()) {
		return value.dump(); // tolerate numeric ids/quotes written unquoted
	}
	return fallback;
}

bool ParseSlot(std::string_view text, int32_t& out) {
	if (text.empty()) {
		return false;
	}
	int32_t value = 0;
	const auto [end, error] = std::from_chars(text.data(), text.data() + text.size(), value);
	if (error != std::errc() || end != text.data() + text.size()) {
		return false;
	}
	out = value;
	return true;
}

std::vector<std::string> ToArgv(const plg::vector<plg::string>& args) {
	std::vector<std::string> argv;
	argv.reserve(args.size());
	for (const plg::string& arg : args) {
		argv.push_back(hudmenu::ToString(arg));
	}
	return argv;
}

// --- config -------------------------------------------------------------------

void HudMenuPlugin::LoadConfig() {
	m_config = Config{};
	if (!plg::GetConfigsDir) {
		return;
	}
	try {
		const std::filesystem::path path =
			std::filesystem::path(hudmenu::ToString(plg::GetConfigsDir())) / "hudmenu" / "config.jsonc";
		std::error_code error;
		if (!std::filesystem::exists(path, error)) {
			return; // defaults apply
		}
		std::ifstream in(path, std::ios::binary);
		if (!in) {
			hudmenu::LogWarn("hudmenu: cannot open " + path.string() + " - using built-in defaults");
			return;
		}
		const std::string text((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		const nlohmann::json json =
			nlohmann::json::parse(text, nullptr, /*allow_exceptions=*/true, /*ignore_comments=*/true);
		if (!json.is_object()) {
			hudmenu::LogWarn("hudmenu: " + path.string() + " must contain a JSON object - using built-in defaults");
			return;
		}
		m_config.layoutPath = json.value("layout_path", m_config.layoutPath);
		m_config.addonId = json.value("workshop_addon_id", m_config.addonId);
		m_config.mountAddon = json.value("mount_workshop_addon", m_config.mountAddon);
		m_config.debugLog = json.value("debug_log", m_config.debugLog);
		m_config.defaultMenuType = json.value("default_menu_type", m_config.defaultMenuType);
		if (m_config.layoutPath.empty()) {
			m_config.layoutPath = "panorama/layout/custom_game/menu_ui.xml";
			hudmenu::LogWarn("hudmenu: 'layout_path' must not be empty - using the built-in default");
		}
		// The "wasd" (Pisex CENTER_WASD) menu type. The keys mirror the Pisex core.cfg names so
		// its values can be copied over 1:1.
		if (json.contains("wasd_menu") && json["wasd_menu"].is_object()) {
			const nlohmann::json& wasd = json["wasd_menu"];
			m_config.wasd.enabled = ReadConfigBool(wasd, "enabled", m_config.wasd.enabled);
			m_config.wasd.addonImages = ReadConfigBool(wasd, "menu_addon", m_config.wasd.addonImages);
			m_config.wasd.menuUrl = ReadConfigString(wasd, "menu_url", m_config.wasd.menuUrl);
			m_config.wasd.inputTimeoutMs = ReadConfigInt(wasd, "input_timeout_ms", m_config.wasd.inputTimeoutMs);
			m_config.wasd.freezePlayer = ReadConfigBool(wasd, "stop_player", m_config.wasd.freezePlayer);
			m_config.wasd.htmlDuration = ReadConfigInt(wasd, "html_duration", m_config.wasd.htmlDuration);
			if (m_config.wasd.inputTimeoutMs < 0) {
				m_config.wasd.inputTimeoutMs = 0;
			}
			if (m_config.wasd.menuUrl.empty()) {
				m_config.wasd.menuUrl = "pisex.online/module/buttons";
				hudmenu::LogWarn("hudmenu: 'wasd_menu.menu_url' must not be empty - using the built-in default");
			}
			if (wasd.contains("sounds") && wasd["sounds"].is_object()) {
				const nlohmann::json& sounds = wasd["sounds"];
				m_config.wasd.soundType = ReadConfigInt(sounds, "type", m_config.wasd.soundType);
				m_config.wasd.soundMove = ReadConfigString(sounds, "move", m_config.wasd.soundMove);
				m_config.wasd.soundBack = ReadConfigString(sounds, "back", m_config.wasd.soundBack);
				m_config.wasd.soundNext = ReadConfigString(sounds, "next", m_config.wasd.soundNext);
				m_config.wasd.soundSelect = ReadConfigString(sounds, "select", m_config.wasd.soundSelect);
				m_config.wasd.soundExit = ReadConfigString(sounds, "exit", m_config.wasd.soundExit);
				if (m_config.wasd.soundType < 0 || m_config.wasd.soundType > 2) {
					hudmenu::LogWarn("hudmenu: 'wasd_menu.sounds.type' must be 0 (off), 1 (sound event) or 2 "
									 "(\"play\") - sound_type 0 is used");
					m_config.wasd.soundType = 0;
				}
			}
		}
	} catch (const std::exception& ex) {
		hudmenu::LogWarn(std::string("hudmenu: config unreadable, using built-in defaults: ") + ex.what());
	}
	// Derived after parsing: a missing/broken config still ends up with a valid default.
	m_defaultTypeIndex = ParseTypeName(m_config.defaultMenuType);
	if (m_defaultTypeIndex < 0) {
		hudmenu::LogWarn("hudmenu: 'default_menu_type' must be \"hud\", \"button\", \"centerhtml\" or \"chat\" (got \"" +
						 m_config.defaultMenuType + "\") - using \"hud\"");
		m_config.defaultMenuType = "hud";
		m_defaultTypeIndex = kTypeHud;
	}
}

// --- gamedata -----------------------------------------------------------------

bool HudMenuPlugin::LoadGamedata(s2sdk::ConfigId& config, std::string& error) const {
	if (!__s2sdk_LoadGameConfigFile) {
		error = "s2sdk LoadGameConfigFile binding is not available";
		return false;
	}
	const std::string location = hudmenu::ToString(GetLocation());
	// GetLocation may be the package root or the bin/ directory holding the .so; the package
	// (package.sh) ships gamedata.jsonc in both places.
	std::vector<std::filesystem::path> candidates;
	if (!location.empty()) {
		const std::filesystem::path loc(location);
		candidates.push_back(loc / "gamedata.jsonc");
		candidates.push_back(loc.parent_path() / "gamedata.jsonc");
		candidates.push_back(loc.parent_path().parent_path() / "gamedata.jsonc");
	}
	plg::vector<plg::string> paths;
	std::string checked;
	for (const std::filesystem::path& candidate : candidates) {
		std::error_code existsError;
		if (std::filesystem::exists(candidate, existsError)) {
			paths.push_back(plg::string(candidate.string()));
		}
		if (!checked.empty()) {
			checked += ", ";
		}
		checked += candidate.string();
	}
	if (paths.empty()) {
		error = "gamedata.jsonc not found (looked for: " + checked + ")";
		return false;
	}
	config = s2sdk::LoadGameConfigFile(paths);
	if (config == 0) {
		// s2sdk 2.18.2 answers 0 (not the -1 the older C++ samples test for) on failure; a
		// successfully loaded config never ends up 0 here (s2sdk itself holds the process's first
		// config id), so 0 is only ever the failure - Teardown's `!= 0` guard stays correct.
		error = "s2sdk could not load the hudmenu gamedata from " + hudmenu::ToString(paths.front());
		return false;
	}
	return true;
}

// --- addon mount ---------------------------------------------------------------

void HudMenuPlugin::MountWorkshopAddon() {
	if (!m_config.mountAddon || m_config.addonId.empty()) {
		return;
	}
	if (!__s2sdk_FindConVar || !__s2sdk_GetConVarString) {
		hudmenu::LogWarn("hudmenu: convar bindings are missing - cannot mount workshop addon " + m_config.addonId +
						 " (mount it manually via s2_extra_addons)");
		return;
	}
	try {
		const uint64_t convar = s2sdk::FindConVar("s2_extra_addons");
		if (convar == 0) {
			hudmenu::LogWarn("hudmenu: convar s2_extra_addons not found - mount workshop addon " + m_config.addonId +
							 " manually");
			return;
		}
		const std::string current = hudmenu::ToString(s2sdk::GetConVarString(convar));
		// The convar holds comma-separated workshop ids; tokenized containment check so a
		// substring of a longer id never matches. Whitespace around tokens is tolerated.
		std::size_t begin = 0;
		while (begin <= current.size()) {
			const std::size_t end = current.find(',', begin);
			std::string_view token(current.data() + begin,
								   (end == std::string::npos ? current.size() : end) - begin);
			while (!token.empty() && (token.front() == ' ' || token.front() == '\t')) {
				token.remove_prefix(1);
			}
			while (!token.empty() && (token.back() == ' ' || token.back() == '\t')) {
				token.remove_suffix(1);
			}
			if (token == m_config.addonId) {
				hudmenu::LogDebug("hudmenu: s2_extra_addons already contains " + m_config.addonId);
				return;
			}
			if (end == std::string::npos) {
				break;
			}
			begin = end + 1;
		}
		// Go through s2sdk's own s2_add_addon command: writing the convar string directly does not
		// update the addon manager's internal list, and its OnStartupServer RefreshAddons() then
		// drops the addon again.
		if (!__s2sdk_ServerCommand) {
			hudmenu::LogWarn("hudmenu: ServerCommand binding is missing - mount workshop addon " + m_config.addonId +
							 " manually (s2_add_addon " + m_config.addonId + ")");
			return;
		}
		s2sdk::ServerCommand(plg::string("s2_add_addon " + m_config.addonId));
		hudmenu::LogInfo("hudmenu: queued 's2_add_addon " + m_config.addonId + "' (layout addon)");
	} catch (const std::exception& ex) {
		hudmenu::LogWarn(std::string("hudmenu: mounting the workshop addon failed: ") + ex.what());
	} catch (...) {
		hudmenu::LogWarn("hudmenu: mounting the workshop addon failed with an unknown exception");
	}
}

// --- lifecycle ------------------------------------------------------------------

bool HudMenuPlugin::BindingsAvailable(std::string& error) const {
	const bool core = __s2sdk_RegisterMenuType && __s2sdk_UnregisterMenuType && __s2sdk_IsMenuTypeRegistered &&
					  __s2sdk_CreateMenu && __s2sdk_DestroyMenu && __s2sdk_DisplayMenu && __s2sdk_AddMenuItem &&
					  __s2sdk_SetMenuPagination && __s2sdk_SetMenuExitButton && __s2sdk_SetMenuExitBackButton &&
					  __s2sdk_GetClientMenu && __s2sdk_GetMenuTitle && __s2sdk_GetMenuItemsCount &&
					  __s2sdk_GetMenuItemDisplay && __s2sdk_GetMenuItemStyle && __s2sdk_GetClientMenuOffset &&
					  __s2sdk_ClientMenuHasPrevPage && __s2sdk_ClientMenuHasNextPage && __s2sdk_SelectMenuItem &&
					  __s2sdk_MenuNextPage && __s2sdk_MenuPrevPage && __s2sdk_CancelClientMenu &&
					  __s2sdk_GetMenuExitButton && __s2sdk_GetMenuExitBackButton && __s2sdk_CreateEntityByName &&
					  __s2sdk_DispatchSpawn2 && __s2sdk_EntHandleToEntPointer && __s2sdk_RemoveEntity &&
					  __s2sdk_AddConsoleCommand && __s2sdk_RemoveCommand && __s2sdk_ReplyToCommand &&
					  __s2sdk_IsClientConnected && __s2sdk_IsClientAuthorized && __s2sdk_IsFakeClient &&
					  __s2sdk_GetClientSteamID64 && __s2sdk_OnMapStart_Register && __s2sdk_OnMapStart_Unregister &&
					  __s2sdk_OnMapEnd_Register && __s2sdk_OnMapEnd_Unregister &&
					  __s2sdk_OnClientDisconnect_Register && __s2sdk_OnClientDisconnect_Unregister;
	if (!core) {
		error = "hudmenu: s2sdk bindings are not available (is the s2sdk plugin >= 2.18.2 loaded?)";
		return false;
	}
	return true;
}

plg::PluginResult HudMenuPlugin::OnPluginStart() {
	try {
		std::string error;
		if (!BindingsAvailable(error)) {
			// Fail soft: returning Failed would stop every other Plugify plugin.
			hudmenu::LogError(error);
			return {};
		}

		LoadConfig();
		LoadPhrases();
		MountWorkshopAddon();

		// Menu type choice storage: the permissions plugin cookies (required dependency, but the
		// feature fails soft when its bindings are missing - the "hud" backend still works).
		m_permissionsAvailable = __permissions_GetCookie && __permissions_SetCookie &&
								 __permissions_OnUserLoaded_Register && __permissions_OnUserLoaded_Unregister;
		if (!m_permissionsAvailable) {
			hudmenu::LogWarn("hudmenu: permissions bindings are not available - the per-player menu type "
							 "choice ('!menu') is disabled and every player gets the server default");
		}

		if (!LoadGamedata(m_gamedata, error)) {
			hudmenu::LogError("hudmenu: " + error + " - the 'hud' menu type is not registered; pisexcompat falls "
												   "back to 'button'");
			return {};
		}
		if (!m_layout.ResolveNatives(m_gamedata, error)) {
			hudmenu::LogError("hudmenu: " + error + " - the 'hud' menu type is not registered; pisexcompat falls "
												   "back to 'button'");
			return {};
		}
		m_layout.SetPassthrough("utils-dialog", m_config.layoutPath);

		m_vtableIndex = 38; // counted in the engine's interface header - see assets/gamedata.jsonc
		if (__s2sdk_GetGameConfigOffset) {
			const int32_t configured = s2sdk::GetGameConfigOffset(m_gamedata, "ClientSvcUserMessageVTableIndex");
			if (configured > 0 && configured < 256) {
				m_vtableIndex = configured;
			}
		}

		if (!hudmenu::GlobalClickHook().Install(m_vtableIndex, error)) {
			hudmenu::LogError("hudmenu: " + error + " - the 'hud' menu type is not registered; pisexcompat falls "
												   "back to 'button'");
			return {};
		}

		if (!s2sdk::RegisterMenuType(kMenuTypeName, &OnHudDisplayTrampoline, &OnHudCloseTrampoline, nullptr)) {
			hudmenu::LogError(std::string("hudmenu: RegisterMenuType(\"") + kMenuTypeName +
							  "\") failed (name already taken?) - not registering the backend");
			Teardown();
			return {};
		}
		m_menuTypeRegistered = true;

		// The "wasd" (Pisex CENTER_WASD) backend. Optional: when it cannot register, the
		// "button" type stays the fallback and the "hud" backend keeps working.
		if (m_config.wasd.enabled) {
			std::string wasdError;
			if (m_wasd.Register(m_config.wasd, wasdError)) {
				hudmenu::LogInfo("hudmenu: menu type \"wasd\" registered (CENTER_WASD port; images from " +
								 std::string(m_config.wasd.addonImages ? "the mounted workshop addon"
																	   : m_config.wasd.menuUrl) +
								 (m_config.wasd.freezePlayer ? ", freeze on" : "") + ")");
			} else {
				hudmenu::LogWarn("hudmenu: " + wasdError + " - CENTER_WASD falls back to s2sdk's built-in \"button\"");
			}
		} else {
			hudmenu::LogInfo("hudmenu: the \"wasd\" menu type is disabled in the config "
							 "(wasd_menu.enabled) - CENTER_WASD falls back to \"button\"");
		}

		s2sdk::OnMapStart_Register(&OnMapStartTrampoline);
		s2sdk::OnMapEnd_Register(&OnMapEndTrampoline);
		s2sdk::OnClientDisconnect_Register(&OnClientDisconnectTrampoline);
		m_s2sdkListenersRegistered = true;

		if (m_permissionsAvailable) {
			try {
				const permissions::Status status = permissions::OnUserLoaded_Register(&OnPermissionsUserLoadedTrampoline);
				if (status == permissions::Status::Success) {
					m_permissionsListenerRegistered = true;
				} else {
					hudmenu::LogWarn("hudmenu: registering the permissions OnUserLoaded listener failed (status " +
									 std::to_string(static_cast<int32_t>(status)) +
									 ") - menu type choices refresh on the next lookup instead");
				}
			} catch (...) {
				hudmenu::LogWarn("hudmenu: registering the permissions OnUserLoaded listener failed");
			}
		}

		// '!menu' in chat and 'mm_menu' in the console (Pisex's MenuChangeCommand); both need
		// ClientCanExecute|Release so a client can run them.
		//
		// AddConsoleCommand always attaches the listener, even when the valve-command creation is
		// refused because the name already exists (s2sdk cannot destroy a console command, so our
		// own entry from a previous load keeps its name across `plg reload`). The registration is
		// therefore ours to remove in every case: the "Registered" flags below are set whenever the
		// call was made - only the valve-command part can fail, and that is reported, not fatal.
		const auto chooserFlags =
			static_cast<s2sdk::ConVarFlag>(static_cast<int64_t>(s2sdk::ConVarFlag::ClientCanExecute) |
										   static_cast<int64_t>(s2sdk::ConVarFlag::Release));
		const bool mmMenuAdded = s2sdk::AddConsoleCommand("mm_menu", "Opens the menu type chooser (hud/button/centerhtml/chat)",
														  chooserFlags, &OnMenuCommandTrampoline, s2sdk::HookMode::Pre);
		m_mmMenuCommandRegistered = true;
		if (!mmMenuAdded) {
			hudmenu::LogInfo("hudmenu: 'mm_menu' already exists (a previous load or another plugin); reusing the entry");
		}
		// s2sdk routes chat messages starting with a trigger ('!menu') to the console command of
		// the same name, so 'menu' is registered the same way - also when the name already exists,
		// where AddConsoleCommand turns into a listener on the existing entry.
		const bool menuAdded = s2sdk::AddConsoleCommand("menu", "Opens the menu type chooser (chat '!menu')", chooserFlags,
														&OnMenuCommandTrampoline, s2sdk::HookMode::Pre);
		m_menuCommandRegistered = true;
		if (!menuAdded) {
			hudmenu::LogInfo("hudmenu: the 'menu' command name is already taken; the chooser is hooked onto it");
		}

		const bool testAdded = s2sdk::AddConsoleCommand("hudmenu_test",
														"Opens a 10-item test menu on a slot: hudmenu_test <slot> [back] [wasd]",
														s2sdk::ConVarFlag::None, &OnTestCommandTrampoline, s2sdk::HookMode::Pre);
		m_testCommandRegistered = true;
		if (!testAdded) {
			hudmenu::LogInfo("hudmenu: 'hudmenu_test' already exists (a previous load); reusing the entry");
		}
		const bool statusAdded = s2sdk::AddConsoleCommand("hudmenu_status", "Prints the hudmenu state (hook, natives, displays)",
														  s2sdk::ConVarFlag::None, &OnStatusCommandTrampoline, s2sdk::HookMode::Pre);
		m_statusCommandRegistered = true;
		if (!statusAdded) {
			hudmenu::LogInfo("hudmenu: 'hudmenu_status' already exists (a previous load); reusing the entry");
		}

		m_started = true;
		hudmenu::LogInfo("hudmenu: menu type \"" + std::string(kMenuTypeName) + "\" registered (layout " +
						 m_config.layoutPath + ", click hook on vtable index " + std::to_string(m_vtableIndex) +
						 " via " + hudmenu::GlobalClickHook().InterfaceSource() + ")");
		hudmenu::LogInfo("hudmenu: default menu type " + m_config.defaultMenuType + ", per-player choice via '!menu'/"
						 "mm_menu " + (m_permissionsAvailable ? "(permissions cookies)" : "(disabled: no permissions "
																"bindings)"));
		hudmenu::LogInfo("hudmenu: menu types available: " + std::string(m_menuTypeRegistered ? "\"hud\" " : "") +
						 (m_wasd.Registered() ? "\"wasd\" (CENTER_WASD)" : "\"wasd\" off"));
		return {};
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: OnPluginStart failed: ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: OnPluginStart failed with an unknown exception");
	}
	return {}; // fail soft
}

plg::PluginResult HudMenuPlugin::OnPluginUpdate(std::chrono::milliseconds dt) {
	(void)dt;
	// Map lifecycle gate, the same state machine pisexcompat uses: the host pumps updates from
	// ServerPostSimulate, so the first update means a map is running (a plugin loaded into a live
	// map never saw an OnMapStart) - but the host can keep pumping throughout a changelevel, so
	// after an OnMapEnd only a *new* OnMapStart re-opens the gate.
	if (!m_gameReady && (m_mapStartSeen || !m_mapEndSeen)) {
		m_gameReady = true;
		m_wasd.SetMapReady(true);
	}
	if (!m_started) {
		return {};
	}
	try {
		// 1. Menu-type choices made in the chooser handler (deferred: it runs under the menu
		//    manager's lock, saving goes through the permissions core).
		if (!m_pendingChoiceApply.empty()) {
			std::vector<PendingChoiceApply> apply = std::move(m_pendingChoiceApply);
			m_pendingChoiceApply.clear();
			for (const PendingChoiceApply& choice : apply) {
				if (choice.slot < 0 || choice.slot >= kMaxSlots || choice.index < 0 ||
					choice.index >= kTypeCount) {
					continue;
				}
				const std::string& name = kTypeNames[choice.index];
				const bool saved = SaveSlotChoiceIndex(choice.slot, choice.index);
				const std::string item = Phrase(kTypePhraseKeys[choice.index], choice.slot);
				if (saved) {
					// The task of the chooser: save, reply in chat, close (the menu closes itself).
					QueueLine(choice.slot, hudmenu::FormatPhrase(Phrase("MenuMenusSet", choice.slot), item),
							  /*toChat=*/true);
					QueueLine(-1, "hudmenu: slot " + std::to_string(choice.slot) + " set the menu type to \"" + name +
									  "\"");
				} else {
					QueueLine(choice.slot, "hudmenu: could not save the menu type (see the plugin log)",
							  /*toChat=*/true);
					QueueLine(-1, "hudmenu: saving the menu type \"" + name + "\" for slot " +
									  std::to_string(choice.slot) + " failed");
				}
			}
		}
		// 2. Session choices made before the permissions user existed.
		PollPendingChoices();
		// 3. Clicks decoded by the usermessage hook.
		hudmenu::PendingClick clicks[8];
		std::size_t count = 0;
		while ((count = hudmenu::GlobalClickHook().Drain(clicks, 8)) > 0) {
			for (std::size_t i = 0; i < count; ++i) {
				DispatchClick(clicks[i]);
			}
		}
		// 4. Output queued by handlers that ran under the menu manager's lock.
		FlushDeferred();
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: update failed: ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: update failed with an unknown exception");
	}
	return {};
}

plg::PluginResult HudMenuPlugin::OnPluginEnd() {
	try {
		m_started = false;
		// Cancel open displays first: the manager then calls our close callback while the
		// plugin is still fully alive (and invokes the owners' handlers synchronously). This
		// covers both our menu types - the wasd frame/close callbacks would otherwise point
		// into this library after it is unloaded.
		for (int32_t slot = 0; slot < kMaxSlots; ++slot) {
			if (!__s2sdk_GetClientMenu || !__s2sdk_CancelClientMenu) {
				break;
			}
			const s2sdk::MenuId hudSession = m_displayed[slot];
			const s2sdk::MenuId wasdSession = m_wasd.SessionId(slot);
			if (hudSession == 0 && wasdSession == 0) {
				continue;
			}
			try {
				const s2sdk::MenuId open = s2sdk::GetClientMenu(slot);
				if (open != 0 && (open == hudSession || open == wasdSession)) {
					s2sdk::CancelClientMenu(slot, s2sdk::MenuCancelReason::Destroyed);
				}
			} catch (...) {
			}
			m_displayed[slot] = 0;
		}
		Teardown();
		FlushDeferred();
	} catch (const std::exception& ex) {
		hudmenu::LogError(std::string("hudmenu: OnPluginEnd failed: ") + ex.what());
	} catch (...) {
		hudmenu::LogError("hudmenu: OnPluginEnd failed with an unknown exception");
	}
	return {};
}

void HudMenuPlugin::Teardown() {
	// Order matters: no more callbacks may point into this library once it is unloaded.
	if (m_wasd.Registered()) {
		m_wasd.Unregister();
	}
	if (m_permissionsListenerRegistered) {
		m_permissionsListenerRegistered = false;
		if (__permissions_OnUserLoaded_Unregister) {
			try {
				permissions::OnUserLoaded_Unregister(&OnPermissionsUserLoadedTrampoline);
			} catch (...) {
			}
		}
	}
	if (m_menuCommandRegistered) {
		m_menuCommandRegistered = false;
		if (__s2sdk_RemoveCommand) {
			try {
				s2sdk::RemoveCommand("menu", &OnMenuCommandTrampoline);
			} catch (...) {
			}
		}
	}
	if (m_menuListenerRegistered) {
		m_menuListenerRegistered = false;
		if (__s2sdk_RemoveCommandListener) {
			try {
				s2sdk::RemoveCommandListener("menu", &OnMenuCommandTrampoline, s2sdk::HookMode::Pre);
			} catch (...) {
			}
		}
	}
	if (m_mmMenuCommandRegistered) {
		m_mmMenuCommandRegistered = false;
		if (__s2sdk_RemoveCommand) {
			try {
				s2sdk::RemoveCommand("mm_menu", &OnMenuCommandTrampoline);
			} catch (...) {
			}
		}
	}
	if (m_menuTypeRegistered) {
		m_menuTypeRegistered = false;
		if (__s2sdk_IsMenuTypeRegistered && __s2sdk_UnregisterMenuType) {
			try {
				if (s2sdk::IsMenuTypeRegistered(kMenuTypeName)) {
					s2sdk::UnregisterMenuType(kMenuTypeName);
				}
			} catch (...) {
			}
		}
	}
	hudmenu::GlobalClickHook().Uninstall();
	if (m_s2sdkListenersRegistered) {
		m_s2sdkListenersRegistered = false;
		if (__s2sdk_OnMapStart_Unregister) {
			try {
				s2sdk::OnMapStart_Unregister(&OnMapStartTrampoline);
			} catch (...) {
			}
		}
		if (__s2sdk_OnMapEnd_Unregister) {
			try {
				s2sdk::OnMapEnd_Unregister(&OnMapEndTrampoline);
			} catch (...) {
			}
		}
		if (__s2sdk_OnClientDisconnect_Unregister) {
			try {
				s2sdk::OnClientDisconnect_Unregister(&OnClientDisconnectTrampoline);
			} catch (...) {
			}
		}
	}
	if (m_testCommandRegistered) {
		m_testCommandRegistered = false;
		if (__s2sdk_RemoveCommand) {
			try {
				s2sdk::RemoveCommand("hudmenu_test", &OnTestCommandTrampoline);
			} catch (...) {
			}
		}
	}
	if (m_statusCommandRegistered) {
		m_statusCommandRegistered = false;
		if (__s2sdk_RemoveCommand) {
			try {
				s2sdk::RemoveCommand("hudmenu_status", &OnStatusCommandTrampoline);
			} catch (...) {
			}
		}
	}
	// Hide the layout for every slot and drop the entity while the natives still work.
	m_layout.HideAll();
	if (__s2sdk_CloseGameConfigFile && m_gamedata != 0 && m_gamedata != static_cast<s2sdk::ConfigId>(-1)) {
		try {
			s2sdk::CloseGameConfigFile(m_gamedata);
		} catch (...) {
		}
		m_gamedata = 0;
	}
	m_layout.RemoveEntity();
	m_displayed.fill(0);
	m_pendingChoiceApply.clear();
	m_choices.fill(SlotChoice{});
}

// --- menu type backend ----------------------------------------------------------

void HudMenuPlugin::OnHudDisplay(s2sdk::MenuId id, int32_t slot) {
	// No map: the display would spawn the layout entity against a torn-down entity system.
	if (!m_gameReady || slot < 0 || slot >= kMaxSlots) {
		return;
	}
	m_displayed[slot] = id;
	std::string error;
	if (!m_layout.Ensure(error)) {
		if (!m_layoutFailureLogged) {
			m_layoutFailureLogged = true;
			hudmenu::LogError("hudmenu: cannot show the hud menu: " + error);
		}
		return;
	}
	m_layoutFailureLogged = false; // a later success re-arms the one-time error
	m_layout.RenderMenu(slot, id);
}

void HudMenuPlugin::OnHudClose(s2sdk::MenuId id, int32_t slot) {
	if (slot < 0 || slot >= kMaxSlots) {
		return;
	}
	if (m_displayed[slot] == id) {
		m_displayed[slot] = 0;
	}
	m_layout.HideForSlot(slot);
}

// --- engine listeners ------------------------------------------------------------

void HudMenuPlugin::OnMapStart() {
	// The engine destroyed the layout entity with the old map; forget the handle (it is
	// re-created on the next display) and reset per-slot state.
	m_gameReady = true;
	m_mapStartSeen = true;
	m_mapEndSeen = false;
	m_wasd.SetMapReady(true);
	m_layout.ResetHandle();
	m_displayed.fill(0);
	m_wasd.ResetAll(); // unfreezes anything the wasd menu froze
}

void HudMenuPlugin::OnMapEnd() {
	// From here until the next OnMapStart s2sdk's client list and entity system are torn down:
	// no client or entity call may happen (any such query crashes). This handler
	// therefore only drops state:
	//   * the layout entity died with the map - its handle is forgotten, so EntityPointer() is
	//     null and every layout call (HideForSlot from a disconnect, HideAll at plugin end) is a
	//     silent no-op instead of an s2sdk dereference of a stale handle;
	//   * the wasd sessions/freezes belong to old pawns - ForgetAll drops them without the
	//     SetClientMoveType write of ResetAll/ResetSlot;
	//   * the displayed ids are gone with their clients, the queued chooser applies are stale.
	m_gameReady = false;
	m_mapStartSeen = false;
	m_mapEndSeen = true;
	m_wasd.SetMapReady(false);
	m_layout.ResetHandle();
	m_displayed.fill(0);
	m_wasd.ForgetAll();
	m_pendingChoiceApply.clear();
}

void HudMenuPlugin::OnClientDisconnect(int32_t slot, s2sdk::NetworkDisconnectionReason reason) {
	(void)reason;
	if (slot < 0 || slot >= kMaxSlots) {
		return;
	}
	m_displayed[slot] = 0;
	m_layout.HideForSlot(slot);
	m_wasd.ResetSlot(slot);
	m_choices[slot] = SlotChoice{}; // the next player in this slot starts from the default
}

// --- per-player menu type choice (Pisex cs2-menus "!menu") -------------------------

bool HudMenuPlugin::HudRegistered() const {
	if (!__s2sdk_IsMenuTypeRegistered) {
		return false;
	}
	try {
		return s2sdk::IsMenuTypeRegistered(kMenuTypeName);
	} catch (...) {
		return false;
	}
}

const char* HudMenuPlugin::TypeNameForIndex(int index) const {
	if (index < 0 || index >= kTypeCount) {
		index = kTypeWasd;
	}
	if (index == kTypeHud && !HudRegistered()) {
		return "button"; // the configured/known choice, rendered by s2sdk's WASD backend
	}
	if (index == kTypeWasd && !m_wasd.Registered()) {
		return "button"; // s2sdk's built-in WASD backend is the fallback for CENTER_WASD
	}
	return kTypeNames[index];
}

int HudMenuPlugin::ParseTypeName(std::string_view name) {
	const std::string lowered = ToLower(name);
	if (lowered.empty()) {
		return -1;
	}
	if (lowered == "0" || lowered == "chat") return kTypeChat;
	if (lowered == "1" || lowered == "center" || lowered == "centerhtml") return kTypeCenter;
	if (lowered == "2" || lowered == "wasd" || lowered == "center_wasd" || lowered == "button") return kTypeWasd;
	if (lowered == "3" || lowered == "hud" || lowered == "hud_layout" || lowered == "panorama") return kTypeHud;
	return -1;
}

bool HudMenuPlugin::SlotSteamId(int32_t slot, uint64_t& steamid) const {
	steamid = 0;
	if (!m_gameReady || slot < 0 || slot >= kMaxSlots) {
		return false; // before the first OnPluginUpdate s2sdk client queries can crash
	}
	if (!__s2sdk_IsClientConnected || !__s2sdk_IsClientAuthorized || !__s2sdk_IsFakeClient ||
		!__s2sdk_GetClientSteamID64) {
		return false;
	}
	try {
		if (!s2sdk::IsClientConnected(slot) || !s2sdk::IsClientAuthorized(slot) || s2sdk::IsFakeClient(slot)) {
			return false;
		}
		steamid = s2sdk::GetClientSteamID64(slot);
		return steamid != 0;
	} catch (...) {
		return false;
	}
}

void HudMenuPlugin::CacheChoiceFromCookie(int32_t slot) {
	SlotChoice& choice = m_choices[static_cast<std::size_t>(slot)];
	choice.cached = false;
	choice.hadCookie = false;
	choice.type = -1;
	if (!m_permissionsAvailable || !__permissions_GetCookie || choice.steamid == 0) {
		return;
	}
	try {
		plg::any value;
		const permissions::Status status =
			permissions::GetCookie(choice.steamid, plg::string(kCookieName), value);
		if (status == permissions::Status::Success) {
			int index = -1;
			if (CookieValueToTypeIndex(value, index)) {
				choice.type = static_cast<int8_t>(index);
				choice.hadCookie = true;
			} else {
				hudmenu::LogWarn("hudmenu: user " + std::to_string(choice.steamid) + " has an unusable \"" +
								 kCookieName + "\" cookie - using the server default");
			}
			choice.cached = true; // the user is known and so is its cookie (or its absence)
		} else if (status == permissions::Status::CookieNotFound) {
			choice.cached = true; // no saved choice -> default
		} else {
			// TargetUserNotFound (the permissions user is not loaded yet) / DBNotReady (storage not
			// ready): remember the miss and retry later - a menu show must not repeat the lookup.
			// A load re-arms it immediately (OnPermissionsUserLoaded).
			choice.nextCookieAttempt = std::chrono::steady_clock::now() + kCookieLookupRetry;
		}
	} catch (const std::exception& ex) {
		choice.nextCookieAttempt = std::chrono::steady_clock::now() + kCookieLookupRetry;
		hudmenu::LogWarn(std::string("hudmenu: reading the menu type cookie failed: ") + ex.what());
	} catch (...) {
		choice.nextCookieAttempt = std::chrono::steady_clock::now() + kCookieLookupRetry;
		hudmenu::LogWarn("hudmenu: reading the menu type cookie failed with an unknown exception");
	}
	// A choice made before the permissions user existed is newer than whatever the cookie holds
	// (the pending write may not have run yet): keep showing it.
	if (choice.pending >= 0) {
		choice.type = choice.pending;
		choice.hadCookie = true;
		choice.cached = true;
	}
}

int HudMenuPlugin::EffectiveSlotTypeIndex(int32_t slot) {
	if (slot < 0 || slot >= kMaxSlots) {
		return DefaultTypeIndex();
	}
	uint64_t steamid = 0;
	if (!SlotSteamId(slot, steamid)) {
		return DefaultTypeIndex(); // no live human player (or no map yet)
	}
	SlotChoice& choice = m_choices[static_cast<std::size_t>(slot)];
	if (choice.steamid != steamid) {
		choice = SlotChoice{}; // slot changed hands
		choice.steamid = steamid;
	}
	// A failed lookup is not repeated before its retry time - EffectiveSlotTypeIndex runs on every
	// menu show. A loaded user (OnPermissionsUserLoaded) clears the retry time.
	if (!choice.cached && std::chrono::steady_clock::now() >= choice.nextCookieAttempt) {
		CacheChoiceFromCookie(slot);
	}
	if (choice.type >= 0) {
		return choice.type;
	}
	return DefaultTypeIndex();
}

bool HudMenuPlugin::PersistChoice(int32_t slot, int index) {
	SlotChoice& choice = m_choices[static_cast<std::size_t>(slot)];
	if (!m_permissionsAvailable || !__permissions_SetCookie || choice.steamid == 0) {
		return false;
	}
	try {
		const permissions::Status status =
			permissions::SetCookie(static_cast<int64_t>(GetId()), choice.steamid, plg::string(kCookieName),
								   plg::any(static_cast<int64_t>(index)), /*dontBroadcast=*/false);
		if (status == permissions::Status::Success) {
			choice.pending = -1;
			return true;
		}
		if (status == permissions::Status::TargetUserNotFound) {
			// perm_connector loads the user within ~1 s of connect; write it once it exists.
			choice.pending = static_cast<int8_t>(index);
			choice.nextPendingAttempt = std::chrono::steady_clock::now() + kPendingChoiceRetry;
			hudmenu::LogInfo("hudmenu: user " + std::to_string(choice.steamid) +
							 " is not loaded in the permissions core yet - the menu type choice is written on load");
			return true; // accepted; persisted later
		}
		hudmenu::LogWarn("hudmenu: saving the \"" + std::string(kCookieName) + "\" cookie for user " +
						 std::to_string(choice.steamid) + " returned status " +
						 std::to_string(static_cast<int32_t>(status)) + " - the choice stays session-only");
	} catch (const std::exception& ex) {
		hudmenu::LogWarn(std::string("hudmenu: saving the menu type cookie failed: ") + ex.what());
	} catch (...) {
		hudmenu::LogWarn("hudmenu: saving the menu type cookie failed with an unknown exception");
	}
	return false;
}

bool HudMenuPlugin::SaveSlotChoiceIndex(int32_t slot, int index) {
	if (index < 0 || index >= kTypeCount || slot < 0 || slot >= kMaxSlots) {
		return false;
	}
	if (index == kTypeHud && !HudRegistered()) {
		return false; // nothing to switch to; would silently render as "button"
	}
	if (index == kTypeWasd && !m_wasd.Registered()) {
		return false; // same for the CENTER_WASD backend (s2sdk's "button" would take over)
	}
	if (!m_permissionsAvailable) {
		return false; // the chooser is gated on permissions, this is a defensive check
	}
	uint64_t steamid = 0;
	if (!SlotSteamId(slot, steamid)) {
		return false;
	}
	SlotChoice& choice = m_choices[static_cast<std::size_t>(slot)];
	if (choice.steamid != steamid) {
		choice = SlotChoice{};
		choice.steamid = steamid;
	}
	// Apply immediately (works even while the cookie cannot be written yet).
	choice.cached = true;
	choice.hadCookie = true;
	choice.type = static_cast<int8_t>(index);
	return PersistChoice(slot, index);
}

plg::string HudMenuPlugin::ClientMenuType(int32_t playerSlot) {
	return plg::string(TypeNameForIndex(EffectiveSlotTypeIndex(playerSlot)));
}

bool HudMenuPlugin::SaveClientMenuType(int32_t playerSlot, std::string_view type) {
	const int index = ParseTypeName(type);
	if (index < 0) {
		return false;
	}
	return SaveSlotChoiceIndex(playerSlot, index);
}

void HudMenuPlugin::PollPendingChoices() {
	if (!m_permissionsAvailable) {
		return;
	}
	// No map: SlotSteamId would fail for every slot and the pending choice would be thrown away
	// (and its client query would crash). Keep it; the next map polls again.
	if (!m_gameReady) {
		return;
	}
	const auto now = std::chrono::steady_clock::now();
	for (int32_t slot = 0; slot < kMaxSlots; ++slot) {
		SlotChoice& choice = m_choices[static_cast<std::size_t>(slot)];
		if (choice.pending < 0 || choice.steamid == 0 || now < choice.nextPendingAttempt) {
			continue;
		}
		uint64_t steamid = 0;
		if (!SlotSteamId(slot, steamid) || steamid != choice.steamid) {
			choice = SlotChoice{}; // player gone or slot reused; the choice was never persisted
			continue;
		}
		const int index = choice.pending;
		choice.pending = -1;
		if (!PersistChoice(slot, index)) {
			// PersistChoice re-armed the retry on a soft failure; nothing else to do here.
			choice.pending = static_cast<int8_t>(index);
			choice.nextPendingAttempt = now + kPendingChoiceRetry;
		}
	}
}

void HudMenuPlugin::OnPermissionsUserLoaded(uint64_t targetId) {
	// Runs synchronously inside permissions::LoadUser (game thread, no menu lock involved):
	// only local state is touched. The cookie is read lazily on the next GetClientMenuType and
	// a pending session choice is written from the next OnPluginUpdate (PollPendingChoices).
	for (int32_t slot = 0; slot < kMaxSlots; ++slot) {
		SlotChoice& choice = m_choices[static_cast<std::size_t>(slot)];
		if (choice.steamid != 0 && choice.steamid == targetId) {
			choice.cached = false;
			choice.nextPendingAttempt = std::chrono::steady_clock::time_point{};
			choice.nextCookieAttempt = std::chrono::steady_clock::time_point{}; // read it right away
		}
	}
}

std::string HudMenuPlugin::PlayerLanguage(int32_t slot) const {
	if (m_gameReady && __s2sdk_GetClientLanguageCode && slot >= 0 && slot < kMaxSlots) {
		try {
			const plg::string code = s2sdk::GetClientLanguageCode(slot);
			if (!code.empty()) {
				return hudmenu::ToString(code);
			}
		} catch (...) {
		}
	}
	return "en";
}

std::string HudMenuPlugin::Phrase(std::string_view key, int32_t slot) const {
	return m_phrases.Get(key, PlayerLanguage(slot));
}

// WasdMenuHost: the "wasd" backend draws entirely from the phrase templates.
std::string HudMenuPlugin::WasdPhrase(std::string_view key, int32_t slot) const {
	return m_phrases.Get(key, PlayerLanguage(slot));
}

void HudMenuPlugin::WasdDebug(std::string_view message) const {
	if (m_config.debugLog) {
		hudmenu::LogDebug(message);
	}
}

void HudMenuPlugin::LoadPhrases() {
	m_phrases.LoadBuiltinFallback();
	const std::string location = hudmenu::ToString(GetLocation());
	std::vector<std::filesystem::path> candidates;
	if (!location.empty()) {
		const std::filesystem::path loc(location);
		candidates.push_back(loc / "translations" / "hudmenu.phrases.txt");
		candidates.push_back(loc.parent_path() / "translations" / "hudmenu.phrases.txt");
		candidates.push_back(loc.parent_path().parent_path() / "translations" / "hudmenu.phrases.txt");
	}
	std::string error;
	for (const std::filesystem::path& candidate : candidates) {
		std::error_code existsError;
		if (!std::filesystem::exists(candidate, existsError)) {
			continue;
		}
		if (m_phrases.LoadFromFile(candidate.string(), error)) {
			hudmenu::LogInfo("hudmenu: loaded " + std::to_string(m_phrases.Size()) + " phrases from " +
							 candidate.string());
			return;
		}
		hudmenu::LogWarn("hudmenu: " + error + " - using the built-in phrases");
		return;
	}
	hudmenu::LogWarn("hudmenu: translations/hudmenu.phrases.txt not found next to the plugin - using the built-in "
					 "phrases");
}

void HudMenuPlugin::OnChooserMenu(s2sdk::MenuId id, s2sdk::MenuAction action, int32_t slot, int32_t param) {
	// The menu manager holds its lock while this runs: only queue the change, it is applied from
	// OnPluginUpdate (the reply is queued there too). DestroyMenu in the End case is the one
	// documented exception.
	switch (action) {
	case s2sdk::MenuAction::Select:
		if (param >= 0 && param < kTypeCount && slot >= 0 && slot < kMaxSlots) {
			m_pendingChoiceApply.push_back(PendingChoiceApply{slot, param});
		}
		break;
	case s2sdk::MenuAction::Cancel: {
		const auto reason = static_cast<s2sdk::MenuCancelReason>(param);
		if (reason == s2sdk::MenuCancelReason::Exit || reason == s2sdk::MenuCancelReason::ExitBack) {
			QueueLine(-1, "hudmenu: slot " + std::to_string(slot) + " closed the menu type chooser");
		}
		break;
	}
	case s2sdk::MenuAction::End:
		if (__s2sdk_DestroyMenu) {
			s2sdk::DestroyMenu(id);
		}
		break;
	case s2sdk::MenuAction::Start:
		break;
	}
}

bool HudMenuPlugin::OpenTypeChooser(int32_t slot) {
	if (!m_permissionsAvailable) {
		return false;
	}
	if (!__s2sdk_CreateMenu || !__s2sdk_AddMenuItem || !__s2sdk_DisplayMenu) {
		return false;
	}
	const int current = EffectiveSlotTypeIndex(slot);
	// Always shown as a Panorama "hud" menu when the backend is up (Pisex did the same), so a
	// player who picked an unusable type can switch back from any state; without it, the
	// WASD default is used.
	const char* typeName = HudRegistered() ? kMenuTypeName : "button";
	const s2sdk::MenuId id =
		s2sdk::CreateMenu(plg::string(Phrase("MenuMenusTitle", slot)), &OnChooserMenuTrampoline, plg::string(typeName));
	if (id == 0) {
		return false;
	}
	for (int i = 0; i < kTypeCount; ++i) {
		const bool isCurrent = i == current;
		// The current type is shown disabled, like Pisex's SettingMenu; an entry whose backend
		// is down is disabled too (choosing it would silently fall back to "button").
		const bool backendDown = (i == kTypeHud && !HudRegistered()) || (i == kTypeWasd && !m_wasd.Registered());
		const bool selectable = !isCurrent && !backendDown;
		s2sdk::AddMenuItem(id, plg::string(std::to_string(i)), plg::string(Phrase(kTypePhraseKeys[i], slot)),
						   selectable ? s2sdk::MenuItemStyle::Default : s2sdk::MenuItemStyle::Disabled);
	}
	if (__s2sdk_SetMenuExitButton) {
		s2sdk::SetMenuExitButton(id, true);
	}
	if (!s2sdk::DisplayMenu(id, slot, 0)) { // no timeout: the chooser waits for the player
		if (__s2sdk_DestroyMenu) {
			s2sdk::DestroyMenu(id);
		}
		return false;
	}
	if (m_config.debugLog) {
		hudmenu::LogDebug("hudmenu: opened the menu type chooser on slot " + std::to_string(slot) + " (current " +
						  kTypeNames[current] + ", rendered as " + typeName + ")");
	}
	return true;
}

s2sdk::ResultType HudMenuPlugin::OnMenuCommand(int32_t caller, s2sdk::ConCommandContext context,
											   const plg::vector<plg::string>& args) {
	std::vector<std::string> argv = ToArgv(args);
	// Depending on the host the command name may or may not be part of the arguments.
	if (!argv.empty() && (argv.front() == "mm_menu" || argv.front() == "menu" || argv.front() == "!menu")) {
		argv.erase(argv.begin());
	}
	int32_t slot = caller;
	if (slot < 0 && !argv.empty()) {
		int32_t parsed = -1;
		if (ParseSlot(argv[0], parsed)) {
			slot = parsed; // server console / RCON convenience
		}
	}
	if (slot < 0 || slot >= kMaxSlots) {
		s2sdk::ReplyToCommand(context, caller, "usage: mm_menu [slot] - opens the menu type chooser");
		return s2sdk::ResultType::Handled;
	}
	if (!m_menuTypeRegistered) {
		s2sdk::ReplyToCommand(context, caller,
							  "hudmenu: the \"hud\" backend did not start - the menu type chooser is unavailable "
							  "(see the plugin log)");
		return s2sdk::ResultType::Handled;
	}
	if (!m_permissionsAvailable) {
		s2sdk::ReplyToCommand(context, caller,
							  "hudmenu: the menu type choice needs the permissions plugin (see the plugin log)");
		return s2sdk::ResultType::Handled;
	}
	uint64_t steamid = 0;
	if (!SlotSteamId(slot, steamid)) {
		s2sdk::ReplyToCommand(context, caller,
							  plg::string("hudmenu: slot " + std::to_string(slot) + " has no connected human player"));
		return s2sdk::ResultType::Handled;
	}
	if (!OpenTypeChooser(slot)) {
		s2sdk::ReplyToCommand(context, caller, "hudmenu: could not open the menu type chooser (see the plugin log)");
	}
	return s2sdk::ResultType::Handled;
}

// --- click handling ----------------------------------------------------------------

void HudMenuPlugin::QueueLine(int32_t replyTo, std::string text, bool toChat) {
	if (m_deferred.size() >= kMaxDeferredLines) {
		++m_deferredDropped;
		return;
	}
	m_deferred.push_back(DeferredLine{replyTo, toChat, std::move(text)});
}

void HudMenuPlugin::FlushDeferred() {
	if (m_deferred.empty() && m_deferredDropped == 0) {
		return;
	}
	std::vector<DeferredLine> lines = std::move(m_deferred);
	m_deferred.clear();
	if (m_deferredDropped != 0) {
		lines.insert(lines.begin(), DeferredLine{-1, false, "hudmenu: " + std::to_string(m_deferredDropped) +
															   " menu event line(s) dropped (queue full)"});
		m_deferredDropped = 0;
	}
	for (const DeferredLine& line : lines) {
		if (m_config.debugLog || line.replyTo < 0) {
			hudmenu::LogInfo(line.text);
		}
		if (line.replyTo < 0) {
			continue;
		}
		// A line queued just before the map ended would otherwise be sent into the map-change
		// window (both printers look the slot up in the torn-down client list) - drop it.
		if (!m_gameReady) {
			continue;
		}
		try {
			if (line.toChat && __s2sdk_PrintToChat) {
				s2sdk::PrintToChat(line.replyTo, plg::string(line.text));
			} else if (__s2sdk_ReplyToCommand) {
				s2sdk::ReplyToCommand(s2sdk::ConCommandContext::Console, line.replyTo, plg::string(line.text));
			}
		} catch (...) {
		}
	}
}

void HudMenuPlugin::RejectClick(int32_t slot, const std::string& reason) {
	if (m_rejectLogs >= 50) {
		return; // enough to diagnose; avoid log spam
	}
	++m_rejectLogs;
	hudmenu::LogInfo("hudmenu: click from slot " + std::to_string(slot) + " ignored: " + reason);
}

void HudMenuPlugin::DispatchClick(const hudmenu::PendingClick& click) {
	const int32_t slot = click.slot;
	if (slot < 0 || slot >= kMaxSlots) {
		return;
	}
	// Only clicks aimed at our live layout entity and at a display session the manager still
	// knows about are acted upon.
	// The click carries the layout as a NETWORK-packed handle (CEntityHandle::ToPackedInt:
	// entry index | (serial & 0x3FF) << 14), while s2sdk handles are CEntityHandle::ToInt()
	// (15-bit index, 17-bit serial). Compare in the packed form.
	const uint32_t raw = static_cast<uint32_t>(m_layout.Handle());
	const uint32_t packed = (raw & 0x7FFFu) | ((((raw >> 15) & 0x1FFFFu) & 0x3FFu) << 14);
	if (!m_layout.Alive() || (click.layout != packed && click.layout != raw)) {
		RejectClick(slot, "layout handle mismatch (click " + std::to_string(click.layout) + ", ours packed " +
							  std::to_string(packed) + ")");
		return;
	}
	const s2sdk::MenuId displayed = m_displayed[slot];
	if (displayed == 0 || !__s2sdk_GetClientMenu) {
		RejectClick(slot, "no hud menu displayed for this slot");
		return;
	}
	const s2sdk::MenuId current = s2sdk::GetClientMenu(slot);
	if (current == 0 || current != displayed) {
		RejectClick(slot, "client menu " + std::to_string(current) + " != displayed " + std::to_string(displayed));
		return;
	}

	const char* button = click.button;
	if (!m_firstClickLogged) {
		m_firstClickLogged = true;
		hudmenu::LogInfo("hudmenu: first layout click received (slot " + std::to_string(slot) + ", button \"" +
						 button + "\", layout handle " + std::to_string(m_layout.Handle()) + ")");
	}
	if (m_config.debugLog) {
		hudmenu::LogDebug("hudmenu: click slot " + std::to_string(slot) + " button \"" + button + "\"");
	}
	if (std::strcmp(button, "utils-closeBtn") == 0) {
		if (__s2sdk_GetMenuExitButton && s2sdk::GetMenuExitButton(current) && __s2sdk_CancelClientMenu) {
			s2sdk::CancelClientMenu(slot, s2sdk::MenuCancelReason::Exit);
		}
		return;
	}
	if (std::strcmp(button, "utils-back") == 0) {
		if (__s2sdk_GetMenuExitBackButton && s2sdk::GetMenuExitBackButton(current) && __s2sdk_CancelClientMenu) {
			s2sdk::CancelClientMenu(slot, s2sdk::MenuCancelReason::ExitBack);
		}
		return;
	}
	if (std::strcmp(button, "utils-prev") == 0) {
		if (__s2sdk_MenuPrevPage) {
			s2sdk::MenuPrevPage(slot);
		}
		return;
	}
	if (std::strcmp(button, "utils-next") == 0) {
		if (__s2sdk_MenuNextPage) {
			s2sdk::MenuNextPage(slot);
		}
		return;
	}
	// The row index is relative to the current page; rows past the page are rendered blank and a
	// click on one must not select the first item of the next page.
	int visible = -1;
	if (std::sscanf(button, "utils-item-%d", &visible) == 1 && visible >= 0 && visible < hudmenu::MenuPageSize(current)) {
		if (!__s2sdk_GetClientMenuOffset || !__s2sdk_GetMenuItemsCount || !__s2sdk_SelectMenuItem) {
			return;
		}
		const int32_t index = s2sdk::GetClientMenuOffset(slot) + visible;
		if (index < s2sdk::GetMenuItemsCount(current)) {
			s2sdk::SelectMenuItem(slot, index);
		}
		return;
	}
	if (std::strncmp(button, "utils-opt-", 10) == 0) {
		// Pisex "select" rows (utils-opt-*) have no equivalent in the s2sdk menu model.
		if (m_config.debugLog) {
			hudmenu::LogDebug("hudmenu: select-option click ignored (\"" + std::string(button) + "\")");
		}
		return;
	}
	if (m_config.debugLog) {
		hudmenu::LogDebug("hudmenu: unknown layout button \"" + std::string(button) + "\" ignored");
	}
}

// --- test menu ----------------------------------------------------------------------

void HudMenuPlugin::OnTestMenu(s2sdk::MenuId id, s2sdk::MenuAction action, int32_t slot, int32_t param) {
	// The menu manager holds its lock while this runs: only queue text, never call s2sdk
	// here (DestroyMenu in the End case is the one documented exception).
	switch (action) {
	case s2sdk::MenuAction::Select:
		QueueLine(-1, "hudmenu_test: slot " + std::to_string(slot) + " selected item " + std::to_string(param));
		QueueLine(slot, "hudmenu_test: selected item " + std::to_string(param));
		break;
	case s2sdk::MenuAction::Cancel: {
		const auto reason = static_cast<s2sdk::MenuCancelReason>(param);
		const char* name = "?";
		switch (reason) {
		case s2sdk::MenuCancelReason::Exit: name = "Exit"; break;
		case s2sdk::MenuCancelReason::ExitBack: name = "ExitBack"; break;
		case s2sdk::MenuCancelReason::Timeout: name = "Timeout"; break;
		case s2sdk::MenuCancelReason::Disconnect: name = "Disconnect"; break;
		case s2sdk::MenuCancelReason::Interrupted: name = "Interrupted"; break;
		case s2sdk::MenuCancelReason::Destroyed: name = "Destroyed"; break;
		}
		QueueLine(-1, "hudmenu_test: slot " + std::to_string(slot) + " canceled (" + name + ")");
		break;
	}
	case s2sdk::MenuAction::End:
		QueueLine(-1, "hudmenu_test: slot " + std::to_string(slot) + " menu closed");
		// Destroying the menu from the End case is the documented pattern.
		if (__s2sdk_DestroyMenu) {
			s2sdk::DestroyMenu(id);
		}
		break;
	case s2sdk::MenuAction::Start:
		break;
	}
}

s2sdk::ResultType HudMenuPlugin::OnTestCommand(int32_t caller, s2sdk::ConCommandContext context,
											   const plg::vector<plg::string>& args) {
	std::vector<std::string> argv = ToArgv(args);
	if (!argv.empty() && argv.front() == "hudmenu_test") {
		argv.erase(argv.begin());
	}
	// CreateMenu/DisplayMenu write client state; between the maps there is none (and the lookup
	// would crash). The command stays available, it just cannot do anything yet.
	if (!m_gameReady) {
		s2sdk::ReplyToCommand(context, caller, "hudmenu_test: no map is running yet");
		return s2sdk::ResultType::Handled;
	}
	if (argv.empty()) {
		s2sdk::ReplyToCommand(context, caller, "usage: hudmenu_test <slot> [back] [wasd]");
		return s2sdk::ResultType::Handled;
	}
	int32_t slot = -1;
	if (!ParseSlot(argv[0], slot) || slot < 0 || slot >= kMaxSlots) {
		s2sdk::ReplyToCommand(context, caller, plg::string("hudmenu_test: invalid slot \"" + argv[0] + "\""));
		return s2sdk::ResultType::Handled;
	}
	// Flags (order-free): "back" -> exit-back button, "wasd" -> display with the CENTER_WASD
	// backend instead of the Panorama "hud" one (for trying out both menu types).
	bool back = false;
	bool useWasd = false;
	for (std::size_t i = 1; i < argv.size(); ++i) {
		if (argv[i] == "back") {
			back = true;
		} else if (argv[i] == "wasd") {
			useWasd = true;
		} else if (argv[i] == "hud") {
			useWasd = false;
		} else {
			s2sdk::ReplyToCommand(context, caller, plg::string("hudmenu_test: unknown option \"" + argv[i] + "\""));
			return s2sdk::ResultType::Handled;
		}
	}
	if (useWasd && !m_wasd.Registered()) {
		s2sdk::ReplyToCommand(context, caller,
							  "hudmenu_test: the \"wasd\" menu type is not registered (see the plugin log)");
		return s2sdk::ResultType::Handled;
	}
	const char* menuType = useWasd ? "wasd" : kMenuTypeName;
	if (!m_menuTypeRegistered || !__s2sdk_IsMenuTypeRegistered || !s2sdk::IsMenuTypeRegistered(menuType)) {
		s2sdk::ReplyToCommand(context, caller, plg::string(std::string("hudmenu_test: the \"") + menuType +
														   "\" menu type is not registered (see the plugin log)"));
		return s2sdk::ResultType::Handled;
	}

	const s2sdk::MenuId id = s2sdk::CreateMenu(kTestMenuTitle, &OnTestMenuTrampoline, plg::string(menuType));
	if (id == 0) {
		s2sdk::ReplyToCommand(context, caller, "hudmenu_test: CreateMenu failed");
		return s2sdk::ResultType::Handled;
	}
	for (int i = 1; i <= kTestMenuItems; ++i) {
		const std::string info = "item-" + std::to_string(i);
		const std::string display = "Test item " + std::to_string(i);
		s2sdk::AddMenuItem(id, plg::string(info), plg::string(display), s2sdk::MenuItemStyle::Default);
	}
	s2sdk::SetMenuPagination(id, kTestMenuPerPage);
	if (back) {
		s2sdk::SetMenuExitBackButton(id, true);
	} else {
		s2sdk::SetMenuExitButton(id, true);
	}
	if (!s2sdk::DisplayMenu(id, slot, 0)) {
		s2sdk::ReplyToCommand(context, caller, "hudmenu_test: DisplayMenu failed (is the slot connected?)");
		s2sdk::DestroyMenu(id);
		return s2sdk::ResultType::Handled;
	}
	const std::string reply = std::string("hudmenu_test: opened a ") + std::to_string(kTestMenuItems) + "-item \"" +
							  menuType + "\" menu on slot " + std::to_string(slot) +
							  (back ? " (back button)" : " (exit button)");
	s2sdk::ReplyToCommand(context, caller, plg::string(reply));
	hudmenu::LogInfo("hudmenu_test: opened a \"" + std::string(menuType) + "\" menu on slot " +
					 std::to_string(slot) + (back ? " (back)" : " (exit)"));
	return s2sdk::ResultType::Handled;
}

s2sdk::ResultType HudMenuPlugin::OnStatusCommand(int32_t caller, s2sdk::ConCommandContext context,
												 const plg::vector<plg::string>& args) {
	(void)args;
	const auto& hook = hudmenu::GlobalClickHook();
	std::vector<std::string> lines;
	lines.push_back("hudmenu: --- hudmenu_status begin ---");
	lines.push_back("hudmenu: started=" + std::string(m_started ? "yes" : "no") +
					" type_registered=" + std::string(m_menuTypeRegistered ? "yes" : "no"));
	lines.push_back("hudmenu: gamedata id=" + std::to_string(m_gamedata) + " layout=" + m_config.layoutPath);
	lines.push_back("hudmenu: click hook installed=" + std::string(hook.Installed() ? "yes" : "no") +
					" vtable_index=" + std::to_string(hook.VTableIndex()) +
					" interface=" + (hook.InterfaceSource().empty() ? "-" : hook.InterfaceSource()) +
					" dropped_clicks=" + std::to_string(hook.DroppedClicks()));
	lines.push_back("hudmenu: click hook " + hook.Diagnostics());
	lines.push_back("hudmenu: layout entity handle=" + std::to_string(m_layout.Handle()) +
					" alive=" + std::string(m_layout.Alive() ? "yes" : "no"));
	std::string open;
	for (int32_t slot = 0; slot < kMaxSlots; ++slot) {
		if (m_displayed[slot] != 0) {
			if (!open.empty()) {
				open += ", ";
			}
			open += std::to_string(slot) + "->menu " + std::to_string(m_displayed[slot]);
		}
	}
	lines.push_back("hudmenu: open displays: " + (open.empty() ? std::string("-") : open));
	lines.push_back("hudmenu: default menu type=" + m_config.defaultMenuType + " (hud registered=" +
					std::string(HudRegistered() ? "yes" : "no") + "), permissions=" +
					std::string(m_permissionsAvailable ? "yes" : "no") + ", phrases=" +
					std::string(m_phrases.IsBuiltin() ? "built-in" : "file") + " (" + std::to_string(m_phrases.Size()) +
					" keys), choice commands: menu=" +
					std::string(m_menuCommandRegistered ? "command" : (m_menuListenerRegistered ? "listener" : "no")) +
					" mm_menu=" + std::string(m_mmMenuCommandRegistered ? "yes" : "no"));
	std::string choices;
	for (int32_t slot = 0; slot < kMaxSlots; ++slot) {
		const SlotChoice& choice = m_choices[static_cast<std::size_t>(slot)];
		if (choice.steamid == 0) {
			continue;
		}
		if (!choices.empty()) {
			choices += ", ";
		}
		choices += std::to_string(slot) + "[user " + std::to_string(choice.steamid) +
				   " type=" + (choice.type >= 0 ? kTypeNames[choice.type] : "default") +
				   (choice.cached ? "" : " uncached") + (choice.hadCookie ? "" : " no-cookie") +
				   (choice.pending >= 0 ? " pending-write" : "") + "]";
	}
	lines.push_back("hudmenu: choices: " + (choices.empty() ? std::string("-") : choices));
	lines.push_back("hudmenu: wasd backend=" + std::string(m_wasd.Registered() ? "registered" : "off") +
					" images=" + std::string(m_config.wasd.addonImages ? "addon" : "url") + " (" + m_config.wasd.menuUrl +
					") freeze=" + std::string(m_config.wasd.freezePlayer ? "yes" : "no") +
					" input_timeout=" + std::to_string(m_config.wasd.inputTimeoutMs) + "ms" +
					" html_duration=" + std::to_string(m_config.wasd.htmlDuration) + "s" +
					" sound_type=" + std::to_string(m_config.wasd.soundType));
	std::string wasdOpen;
	for (int32_t slot = 0; slot < kMaxSlots; ++slot) {
		const s2sdk::MenuId session = m_wasd.SessionId(slot);
		if (session == 0) {
			continue;
		}
		if (!wasdOpen.empty()) {
			wasdOpen += ", ";
		}
		wasdOpen += std::to_string(slot) + "->menu " + std::to_string(session);
	}
	lines.push_back("hudmenu: wasd sessions: " + (wasdOpen.empty() ? std::string("-") : wasdOpen));
	lines.push_back("hudmenu: --- hudmenu_status end ---");
	for (const std::string& line : lines) {
		s2sdk::ReplyToCommand(context, caller, plg::string(line));
	}
	return s2sdk::ResultType::Handled;
}

} // namespace

// --- exported methods (hudmenu.pplugin -> sdk/include/hudmenu consumer bindings) ---------------
// No exception may cross the plugify boundary; the plugin methods do not throw, these wrappers
// are the last line of defense.

extern "C" PLUGIN_API plg::string GetClientMenuType(int32_t playerSlot) {
	try {
		return g_hudMenuPlugin.ClientMenuType(playerSlot);
	} catch (...) {
		// "button" is always registered, unlike "hud".
		return plg::string("button");
	}
}

extern "C" PLUGIN_API bool SetClientMenuType(int32_t playerSlot, const plg::string& type) {
	try {
		return g_hudMenuPlugin.SaveClientMenuType(playerSlot, std::string_view(type));
	} catch (...) {
		return false;
	}
}

PLUGIFY_PLUGIN(PLUGIN_API, &g_hudMenuPlugin)
