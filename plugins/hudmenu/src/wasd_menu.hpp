// The "wasd" s2sdk menu type: a port of Pisex cs2-menus MenuType::CENTER_WASD (2).
//
// Look & feel is reproduced from Pisex's GetMenuText renderer:
// the title, the item rows of the current page (plain text, disabled rows greyed), the "E"
// select image appended to the cursor row, the W/S/A/D control images (pressed variants while
// a key is held) and the F/empty spacer images, all assembled from the Html* templates - the
// images come either from the mounted workshop addon (s2r://resource/menus/*.vsvg) or from
// the configured site URL (core.cfg MenuAddon / MenuURL).
//
// Input is read every server frame from the menu-type "frame" callback, exactly like Pisex's
// per-frame CTimer: s2sdk::GetClientButtons() gives the same movement button bitfield Pisex
// read, and the same key mapping / 200 ms repeat throttle / freeze (StopingUser) / sounds
// (sound_type) apply.
//
// Anti-flicker (the important difference from s2sdk's built-in "button" type): Pisex re-sends
// the whole HTML every game frame with a 5 s alert duration - a zero-duration center-HTML
// print, which shows through the show_survival_respawn_status event (html as the loc token,
// the slot as the userid, duration 5 when the requested one is <= 0) - so the panel is
// refreshed long before it could expire and the identical text makes the engine update it in
// place (no re-flash). s2sdk's button backend instead redraws only every
// MenuButtonRefreshInterval (default 1.5 s) with MenuButtonHtmlDuration = 2 s: every keep-alive
// redraw re-arms the alert (visible re-flash) and any frame hitch longer than the 0.5 s margin
// lets the panel vanish in between. This backend uses s2sdk::PrintCentreHtml(), which fires
// the exact same per-player event.
//
// Movement keys only make sense for a player whose movement input reaches the server, so the
// type is alive-players-only by nature (a dead/spectating player cannot move the cursor);
// players keep the other types for that case - this is documented, not enforced.
#pragma once

#include <s2sdk/s2sdk.hpp>

#include <array>
#include <chrono>
#include <cstdint>
#include <string>
#include <string_view>

namespace hudmenu {

// The plugin side of the backend: localized phrases + an optional debug sink.
class WasdMenuHost {
public:
	virtual ~WasdMenuHost() = default;
	// Localized phrase for `key` (falls back to the key itself), `slot` = the viewing player.
	[[nodiscard]] virtual std::string WasdPhrase(std::string_view key, int32_t slot) const = 0;
	virtual void WasdDebug(std::string_view message) const = 0;
};

class WasdMenuBackend {
public:
	struct Config {
		bool enabled = true;    // register the "wasd" menu type at all
		bool addonImages = false; // core.cfg MenuAddon: true = s2r://resource/menus (workshop addon), false = web URL
		std::string menuUrl = "pisex.online/module/buttons"; // core.cfg MenuURL (used when addonImages is false)
		int inputTimeoutMs = 200; // core.cfg TimeoutInputMenu: repeat delay between menu key presses
		bool freezePlayer = false; // core.cfg StopingUser: freeze the player while the menu is open
		// core.cfg sound_type: 0 = none, 1 = sound event (EmitSound on the player), 2 = "play <sound>".
		int soundType = 0;
		std::string soundMove;   // core.cfg sound_move
		std::string soundBack;   // core.cfg sound_back
		std::string soundNext;   // core.cfg sound_next
		std::string soundSelect; // core.cfg sound_select
		std::string soundExit;   // core.cfg sound_exit
		int htmlDuration = 5;    // seconds per send; Pisex's PrintToCenterHtml(..., 0) maps to 5
	};

	explicit WasdMenuBackend(const WasdMenuHost& host);

	// Registers the "wasd" s2sdk menu type. On failure nothing is registered and `error` is set.
	bool Register(const Config& config, std::string& error);
	void Unregister();
	[[nodiscard]] bool Registered() const { return m_registered; }

	// Session bookkeeping for map start / disconnect: unfreezes a frozen player and forgets the slot.
	void ResetSlot(int32_t slot);
	void ResetAll();

	// Map lifecycle gate (set by the plugin from OnMapEnd / OnMapStart / the first ready update).
	// While it is false - i.e. between the map end and the next map start, when s2sdk's client
	// list and entity system are torn down - every client/entity call (GetClientButtons,
	// PrintCentreHtml, SetClientMoveType) would be a crash, so
	// the menu callbacks become no-ops and an unfreeze only drops the flag.
	void SetMapReady(bool ready) { m_mapReady = ready; }
	// Forgets every slot without the unfreeze write: the frozen pawns died with the old map.
	void ForgetAll();

	// The menu this backend currently displays to the slot (0 = none); used by the plugin's
	// teardown to cancel open sessions before the library unloads.
	[[nodiscard]] s2sdk::MenuId SessionId(int32_t slot) const;
	[[nodiscard]] bool AnySession() const;

private:
	static constexpr int32_t kMaxSlots = 64;
	// IN_* bit values Pisex reads from the movement button bitfield.
	static constexpr uint64_t kInForward = 1ull << 3;   // W - cursor up
	static constexpr uint64_t kInBack = 1ull << 4;      // S - cursor down
	static constexpr uint64_t kInUse = 1ull << 5;       // E - select
	static constexpr uint64_t kInMoveLeft = 1ull << 9;  // A - previous page / back
	static constexpr uint64_t kInMoveRight = 1ull << 10; // D - next page
	static constexpr uint64_t kInReload = 1ull << 13;   // R - exit
	// MoveType_t: the "frozen" value the ported modules use (MOVETYPE_OBSOLETE = 1; s2sdk names
	// it Isometric) and WALK = 2. Pisex cs2-menus froze with MOVETYPE_NONE; this port uses 1.
	static constexpr int32_t kMoveTypeFrozen = 1;
	static constexpr int32_t kMoveTypeWalk = 2;

	struct SlotState {
		s2sdk::MenuId session = 0;
		bool frozen = false;
		std::chrono::steady_clock::time_point nextInput{}; // input repeat throttle (Pisex TimeoutInputMenu)
	};

	// Held-key flags for one frame (pressed-image state, Pisex bUp/bDown/bLeft/bRight/bEnter).
	struct KeyFlags {
		bool up = false;
		bool down = false;
		bool left = false;
		bool right = false;
		bool enter = false;
		bool exit = false;
	};

	// s2sdk menu-type callbacks (called by the menu manager; its mutex is recursive, and
	// calling the manager's own getters/navigation from here is the sanctioned backend model -
	// s2sdk's own button backend does exactly that).
	static void DisplayTrampoline(s2sdk::MenuId id, int32_t slot);
	static void CloseTrampoline(s2sdk::MenuId id, int32_t slot);
	static void FrameTrampoline(s2sdk::MenuId id, int32_t slot);
	void OnDisplay(s2sdk::MenuId id, int32_t slot);
	void OnClose(s2sdk::MenuId id, int32_t slot);
	void OnFrame(s2sdk::MenuId id, int32_t slot);

	// Pisex GetMenuText(): builds the full center HTML for the current page/cursor.
	[[nodiscard]] std::string BuildHtml(s2sdk::MenuId id, int32_t slot, const KeyFlags& keys) const;
	// Pisex's control image (Html<Base>Buttons / Html<Base>_PButtons, _Web when URL images).
	[[nodiscard]] std::string Image(std::string_view base, bool pressed, int32_t slot) const;
	[[nodiscard]] bool PageTurn(int32_t slot, bool forward); // A/D; returns true when the page changed
	void PlaySound(int32_t slot, const std::string& sound) const;
	void Freeze(int32_t slot);
	void Unfreeze(int32_t slot);

	const WasdMenuHost& m_host;
	Config m_config;
	bool m_registered = false;
	// True only while a map is running (see SetMapReady); false at plugin start and in the
	// map-change window, so no client call can happen there.
	bool m_mapReady = false;
	std::array<SlotState, kMaxSlots> m_slots{};
};

} // namespace hudmenu
