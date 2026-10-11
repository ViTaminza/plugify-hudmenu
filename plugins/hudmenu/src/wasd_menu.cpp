#include "wasd_menu.hpp"

#include "log.hpp"
#include "phrases.hpp"

#include <algorithm>
#include <cstddef>

namespace hudmenu {

namespace {

// The backend the C trampolines dispatch to (one instance, set while the type is registered).
WasdMenuBackend* g_active = nullptr;

// Pisex's page is a hard five rows: the cursor never leaves them,
// whatever page size the menu itself requested.
constexpr int32_t kRowsPerPage = 5;

} // namespace

WasdMenuBackend::WasdMenuBackend(const WasdMenuHost& host) : m_host(host) {}

// --- trampolines ------------------------------------------------------------------

void WasdMenuBackend::DisplayTrampoline(s2sdk::MenuId id, int32_t slot) {
	if (g_active == nullptr) {
		return;
	}
	try {
		g_active->OnDisplay(id, slot);
	} catch (const std::exception& ex) {
		LogError(std::string("hudmenu: exception in the wasd display callback: ") + ex.what());
	} catch (...) {
		LogError("hudmenu: unknown exception in the wasd display callback");
	}
}

void WasdMenuBackend::CloseTrampoline(s2sdk::MenuId id, int32_t slot) {
	if (g_active == nullptr) {
		return;
	}
	try {
		g_active->OnClose(id, slot);
	} catch (const std::exception& ex) {
		LogError(std::string("hudmenu: exception in the wasd close callback: ") + ex.what());
	} catch (...) {
		LogError("hudmenu: unknown exception in the wasd close callback");
	}
}

void WasdMenuBackend::FrameTrampoline(s2sdk::MenuId id, int32_t slot) {
	if (g_active == nullptr) {
		return;
	}
	try {
		g_active->OnFrame(id, slot);
	} catch (const std::exception& ex) {
		LogError(std::string("hudmenu: exception in the wasd frame callback: ") + ex.what());
	} catch (...) {
		LogError("hudmenu: unknown exception in the wasd frame callback");
	}
}

// --- registration -------------------------------------------------------------------

bool WasdMenuBackend::Register(const Config& config, std::string& error) {
	if (m_registered) {
		return true;
	}
	if (!__s2sdk_RegisterMenuType) {
		error = "s2sdk RegisterMenuType binding is not available";
		return false;
	}
	m_config = config;
	try {
		if (!s2sdk::RegisterMenuType(plg::string("wasd"), &WasdMenuBackend::DisplayTrampoline,
									 &WasdMenuBackend::CloseTrampoline, &WasdMenuBackend::FrameTrampoline)) {
			error = "RegisterMenuType(\"wasd\") failed (name already taken?)";
			return false;
		}
	} catch (const std::exception& ex) {
		error = std::string("RegisterMenuType(\"wasd\") failed: ") + ex.what();
		return false;
	} catch (...) {
		error = "RegisterMenuType(\"wasd\") failed with an unknown exception";
		return false;
	}
	g_active = this;
	m_registered = true;
	return true;
}

void WasdMenuBackend::Unregister() {
	if (!m_registered) {
		return;
	}
	// Stop dispatching first: after this no callback can point into the (possibly unloaded) code.
	g_active = nullptr;
	m_registered = false;
	if (__s2sdk_IsMenuTypeRegistered && __s2sdk_UnregisterMenuType) {
		try {
			if (s2sdk::IsMenuTypeRegistered(plg::string("wasd"))) {
				s2sdk::UnregisterMenuType(plg::string("wasd"));
			}
		} catch (...) {
		}
	}
	ResetAll();
}

void WasdMenuBackend::ResetSlot(int32_t slot) {
	if (slot < 0 || slot >= kMaxSlots) {
		return;
	}
	SlotState& state = m_slots[static_cast<std::size_t>(slot)];
	if (state.frozen) {
		Unfreeze(slot);
	}
	state = SlotState{};
}

void WasdMenuBackend::ResetAll() {
	for (int32_t slot = 0; slot < kMaxSlots; ++slot) {
		ResetSlot(slot);
	}
}

void WasdMenuBackend::ForgetAll() {
	// No Unfreeze: the frozen pawns belonged to the map that just ended (there is nothing to
	// write to anymore, and a client write in the map-change window crashes).
	for (SlotState& state : m_slots) {
		state = SlotState{};
	}
}

s2sdk::MenuId WasdMenuBackend::SessionId(int32_t slot) const {
	if (slot < 0 || slot >= kMaxSlots) {
		return 0;
	}
	return m_slots[static_cast<std::size_t>(slot)].session;
}

bool WasdMenuBackend::AnySession() const {
	for (const SlotState& state : m_slots) {
		if (state.session != 0) {
			return true;
		}
	}
	return false;
}

// --- rendering (Pisex GetMenuText) ---------------------------------------------------

std::string WasdMenuBackend::Image(std::string_view base, bool pressed, int32_t slot) const {
	// Pisex phrase names: Html<Base>Buttons / Html<Base>_PButtons, plus the _Web variants that
	// take the MenuURL as %s.
	std::string key(base);
	key += pressed ? "_PButtons" : "Buttons";
	if (!m_config.addonImages) {
		key += "_Web";
	}
	std::string image = m_host.WasdPhrase(key, slot);
	if (!m_config.addonImages) {
		image = FormatPhrase(image, m_config.menuUrl);
	}
	return image;
}

std::string WasdMenuBackend::BuildHtml(s2sdk::MenuId id, int32_t slot, const KeyFlags& keys) const {
	std::string out;

	// Title line (the HtmlTitle template carries the title as %s).
	out += FormatPhrase(m_host.WasdPhrase("HtmlTitle", slot), ToString(s2sdk::GetMenuTitle(id)));

	const int32_t itemCount = s2sdk::GetMenuItemsCount(id);
	int32_t offset = s2sdk::GetClientMenuOffset(slot);
	if (offset < 0) {
		offset = 0;
	}
	int32_t perPage = s2sdk::GetMenuPagination(id);
	if (perPage <= 0) {
		perPage = itemCount; // pagination disabled: one page with everything
	}
	if (perPage <= 0) {
		perPage = 1;
	}
	const int32_t pageEnd = std::min(offset + perPage, itemCount);
	// The marker only ever lands on the five rendered rows; a cursor left elsewhere (older
	// session, another backend) falls back to the page start.
	int32_t cursor = s2sdk::GetClientMenuCursor(slot);
	if (cursor < offset || cursor >= pageEnd || cursor >= offset + kRowsPerPage) {
		cursor = offset;
	}

	const bool hasBack = __s2sdk_GetMenuExitBackButton && s2sdk::GetMenuExitBackButton(id);
	const bool hasExit = __s2sdk_GetMenuExitButton && s2sdk::GetMenuExitButton(id);
	const bool hasNext = __s2sdk_ClientMenuHasNextPage && s2sdk::ClientMenuHasNextPage(slot);
	const bool hasPrevPage = offset > 0;

	// Item rows (Pisex's renderer): every item from the page start; the cursor row
	// gets the E image appended (its pressed variant while E is held), then the row break. After
	// the fifth row (or the last item) the control row is emitted and the loop stops - the same
	// early break Pisex used, which is also why more than five rows only ever shows on one page.
	int32_t row = 0;
	for (int32_t index = offset; index < itemCount; ++index) {
		const s2sdk::MenuItemStyle style = s2sdk::GetMenuItemStyle(id, index);
		const std::string text = ToString(s2sdk::GetMenuItemDisplay(id, index));
		// Pisex: case 1 (default) -> HtmlButton, case 2 (disabled) -> HtmlButtonBlock (grey).
		out += FormatPhrase(m_host.WasdPhrase(style == s2sdk::MenuItemStyle::Default ? "HtmlButton" : "HtmlButtonBlock",
											  slot),
							text);
		if (cursor == offset + row) {
			out += Image("HtmlE", keys.enter, slot);
		}
		out += m_host.WasdPhrase("HtmlButtonBR", slot);
		++row;

		if (row == 5 || index == itemCount - 1) {
			// Control row (as Pisex lays it out).
			out += Image("HtmlW", keys.up, slot);
			out += Image("HtmlS", keys.down, slot);
			if (hasPrevPage || hasBack) {
				out += Image("HtmlA", keys.left, slot);
				if (!hasNext) {
					out += Image("HtmlSpaceShort", false, slot);
				} else {
					out += Image("HtmlD", keys.right, slot);
				}
			} else if (hasNext) {
				out += Image("HtmlSpaceShort", false, slot);
				out += Image("HtmlD", keys.right, slot);
			} else if (hasExit) {
				out += Image("HtmlSpace", false, slot);
			}
			if (hasExit) {
				out += Image("HtmlF", false, slot);
			}
			break;
		}
	}
	return out;
}

// --- input ---------------------------------------------------------------------------

void WasdMenuBackend::PlaySound(int32_t slot, const std::string& sound) const {
	if (m_config.soundType == 0 || sound.empty()) {
		return;
	}
	try {
		if (m_config.soundType == 1) {
			// core.cfg sound_type 1: sound event on the player.
			if (__s2sdk_GetClientPawn && __s2sdk_EmitSound && __s2sdk_EntPointerToEntHandle) {
				void* pawn = s2sdk::GetClientPawn(slot);
				if (pawn != nullptr) {
					// pitch 100 = PITCH_NORM (core.cfg's sound_type 1 of the original).
					s2sdk::EmitSound(s2sdk::EntPointerToEntHandle(pawn), plg::string(sound), /*pitch=*/100,
									 /*volume=*/1.0f, /*delay=*/0.0f);
				}
			}
		} else if (m_config.soundType == 2 && __s2sdk_ClientCommand) {
			// core.cfg sound_type 2: "play <sound>".
			s2sdk::ClientCommand(slot, plg::string("play " + sound));
		}
	} catch (...) {
	}
}

void WasdMenuBackend::Freeze(int32_t slot) {
	if (!m_config.freezePlayer) {
		return;
	}
	SlotState& state = m_slots[static_cast<std::size_t>(slot)];
	if (state.frozen) {
		return;
	}
	if (!__s2sdk_IsClientAlive || !__s2sdk_GetClientMoveType || !__s2sdk_SetClientMoveType) {
		return;
	}
	try {
		// Pisex: only a living, walking pawn gets frozen.
		if (!s2sdk::IsClientAlive(slot) ||
			static_cast<int32_t>(s2sdk::GetClientMoveType(slot)) != kMoveTypeWalk) {
			return;
		}
		s2sdk::SetClientMoveType(slot, static_cast<s2sdk::MoveType>(kMoveTypeFrozen));
		state.frozen = true;
	} catch (...) {
	}
}

void WasdMenuBackend::Unfreeze(int32_t slot) {
	SlotState& state = m_slots[static_cast<std::size_t>(slot)];
	if (!state.frozen) {
		return;
	}
	state.frozen = false;
	// Map end to next map start: s2sdk's client list is gone and SetClientMoveType's lookup
	// crashes; the flag is dropped without the write (the frozen pawn died with the old map).
	if (!m_mapReady || !__s2sdk_SetClientMoveType) {
		return;
	}
	// No current pawn (s2sdk's "invalid player pawn" warning appears for a
	// client still connecting): there is nothing to thaw, and SetClientMoveType would log
	// "Cannot execute 'SetClientMoveType' on invalid player pawn: N" (GetClientPawn resolves the
	// same pawn the export would).
	if (__s2sdk_GetClientPawn && s2sdk::GetClientPawn(slot) == nullptr) {
		return;
	}
	try {
		s2sdk::SetClientMoveType(slot, static_cast<s2sdk::MoveType>(kMoveTypeWalk));
	} catch (...) {
	}
}

bool WasdMenuBackend::PageTurn(int32_t slot, bool forward) {
	bool changed = false;
	try {
		if (forward) {
			changed = __s2sdk_MenuNextPage && s2sdk::MenuNextPage(slot);
		} else {
			changed = __s2sdk_MenuPrevPage && s2sdk::MenuPrevPage(slot);
		}
	} catch (...) {
		return false;
	}
	if (changed && __s2sdk_GetClientMenuOffset && __s2sdk_SetClientMenuCursor) {
		// Pisex reset its per-page cursor to the first row on every page change.
		try {
			s2sdk::SetClientMenuCursor(slot, s2sdk::GetClientMenuOffset(slot));
		} catch (...) {
		}
	}
	return changed;
}

// --- menu-type callbacks --------------------------------------------------------------

void WasdMenuBackend::OnDisplay(s2sdk::MenuId id, int32_t slot) {
	// No map: the display would print center HTML to a slot of a torn-down client list. Ignore it
	// (the manager drops the session on the client's disconnect anyway).
	if (!m_mapReady || slot < 0 || slot >= kMaxSlots) {
		return;
	}
	// This type renders kRowsPerPage rows per page. The s2sdk menu guide says not to assume a
	// fixed page size but to respect whatever GetMenuPagination reports, so a menu
	// paged wider (or unpaged: 0) is clamped to what this type can show, exactly like s2sdk's own
	// cursor type does (its MenuButtonMaxItems clamp);
	// otherwise the rows past the fifth of a page could never be reached.
	if (__s2sdk_GetMenuPagination && __s2sdk_SetMenuPagination && __s2sdk_GetMenuItemsCount) {
		try {
			const int32_t perPage = s2sdk::GetMenuPagination(id);
			const int32_t items = s2sdk::GetMenuItemsCount(id);
			if (perPage <= 0 ? items > kRowsPerPage : perPage > kRowsPerPage) {
				s2sdk::SetMenuPagination(id, kRowsPerPage);
			}
		} catch (...) {
		}
	}
	SlotState& state = m_slots[static_cast<std::size_t>(slot)];
	state.session = id;
	state.nextInput = std::chrono::steady_clock::now(); // the first key may act immediately

	if (!__s2sdk_PrintCentreHtml) {
		return;
	}
	try {
		const KeyFlags none;
		const std::string html = BuildHtml(id, slot, none);
		if (!html.empty()) {
			s2sdk::PrintCentreHtml(slot, plg::string(html),
								   m_config.htmlDuration > 0 ? m_config.htmlDuration : 5);
		}
	} catch (...) {
	}
}

void WasdMenuBackend::OnClose(s2sdk::MenuId id, int32_t slot) {
	if (slot < 0 || slot >= kMaxSlots) {
		return;
	}
	SlotState& state = m_slots[static_cast<std::size_t>(slot)];
	if (state.session == id) {
		state.session = 0;
	}
	if (state.frozen) {
		Unfreeze(slot);
	}
	// Pisex leaves the panel to run out its 5 s duration on close (its per-frame timer simply
	// stops) - the next menu overwrites it. Kept as-is.
}

void WasdMenuBackend::OnFrame(s2sdk::MenuId id, int32_t slot) {
	// The frame callback keeps being called for a session the manager still knows about, including
	// in the map-change window (s2sdk's client list is gone then - GetClientButtons/PrintCentreHtml
	// would crash). Do nothing until the next map is up; MenuManager re-arms the session via this
	// same callback once it is.
	if (!m_mapReady || slot < 0 || slot >= kMaxSlots) {
		return;
	}
	SlotState& state = m_slots[static_cast<std::size_t>(slot)];
	if (state.session != id) {
		state.session = id; // (re)entered without our display callback having run
		state.nextInput = std::chrono::steady_clock::now();
	}
	if (!__s2sdk_GetClientButtons) {
		return;
	}

	// Pisex read the raw button bitfield every call; the held keys also drive the pressed
	// variants of the control images, so they are collected whether or not the repeat throttle
	// lets the action through.
	//
	// GetClientButtons resolves the controller's current pawn and the pawn's movement services;
	// s2sdk logs a WARNING - "Cannot execute 'GetClientButtons' on invalid player pawn: N" - for
	// every call that finds none, which would repeat once per frame for as long as the menu stays
	// open for a slot without a current pawn (e.g. a client still connecting). Pisex skipped the read
	// in exactly that case (no controller, pawn or movement services -> no text) and s2sdk's own
	// button backend bails out when the pawn is gone. The skipped call can only have returned 0,
	// so the frame behaves as before - without the warning. The wasd type is alive-players-only
	// by nature (see the header); a fallback keeps the old behaviour should the binding be missing.
	uint64_t buttons = 0;
	try {
		if (!__s2sdk_GetClientPawn || s2sdk::GetClientPawn(slot) != nullptr) {
			buttons = s2sdk::GetClientButtons(slot, 0);
		}
	} catch (...) {
		return;
	}
	KeyFlags keys;
	if (buttons != 0) {
		keys.up = (buttons & kInForward) != 0;
		keys.down = (buttons & kInBack) != 0;
		keys.left = (buttons & kInMoveLeft) != 0;
		keys.right = (buttons & kInMoveRight) != 0;
		keys.enter = (buttons & kInUse) != 0;
		keys.exit = (buttons & kInReload) != 0;
	}

	// Pisex: freeze a walking player while the menu is open.
	Freeze(slot);

	const auto now = std::chrono::steady_clock::now();
	if (buttons != 0 && now >= state.nextInput) {
		const int32_t timeout = m_config.inputTimeoutMs > 0 ? m_config.inputTimeoutMs : 200;
		state.nextInput = now + std::chrono::milliseconds(timeout);

		// Pisex's action priority: W, S, A, D, E, R - first match wins.
		try {
			const int32_t itemCount = s2sdk::GetMenuItemsCount(id);
			int32_t offset = s2sdk::GetClientMenuOffset(slot);
			if (offset < 0) {
				offset = 0;
			}
			int32_t perPage = s2sdk::GetMenuPagination(id);
			if (perPage <= 0) {
				perPage = itemCount;
			}
			const int32_t pageEnd = std::min(offset + (perPage > 0 ? perPage : 1), itemCount);
			// Pisex's cursor stays within the five rendered rows.
			const int32_t cursorMax = std::min(pageEnd, offset + kRowsPerPage);
			int32_t cursor = s2sdk::GetClientMenuCursor(slot);
			if (cursor < offset || cursor >= cursorMax) {
				cursor = offset;
			}

			if (keys.up) {
				if (cursor > offset) {
					PlaySound(slot, m_config.soundMove);
					if (__s2sdk_SetClientMenuCursor) {
						s2sdk::SetClientMenuCursor(slot, cursor - 1);
					}
				}
			} else if (keys.down) {
				if (cursor + 1 < cursorMax) {
					PlaySound(slot, m_config.soundMove);
					if (__s2sdk_SetClientMenuCursor) {
						s2sdk::SetClientMenuCursor(slot, cursor + 1);
					}
				}
			} else if (keys.left) {
				const bool hasBack = __s2sdk_GetMenuExitBackButton && s2sdk::GetMenuExitBackButton(id);
				if (offset > 0) {
					if (PageTurn(slot, /*forward=*/false)) {
						PlaySound(slot, m_config.soundBack);
					}
				} else if (hasBack) {
					// Page 0 with a back option: the A key is the "back" action (Pisex called the
					// callback with item 7; here that is the ExitBack cancel reason).
					PlaySound(slot, m_config.soundBack);
					if (__s2sdk_CancelClientMenu) {
						s2sdk::CancelClientMenu(slot, s2sdk::MenuCancelReason::ExitBack);
					}
					return;
				}
			} else if (keys.right) {
				if (PageTurn(slot, /*forward=*/true)) {
					PlaySound(slot, m_config.soundNext);
				}
			} else if (keys.enter) {
				bool selected = false;
				if (__s2sdk_SelectMenuItem) {
					selected = s2sdk::SelectMenuItem(slot, cursor);
				}
				if (selected) {
					PlaySound(slot, m_config.soundSelect);
				}
			} else if (keys.exit) {
				const bool hasBack = __s2sdk_GetMenuExitBackButton && s2sdk::GetMenuExitBackButton(id);
				const bool hasExit = __s2sdk_GetMenuExitButton && s2sdk::GetMenuExitButton(id);
				if (hasBack || hasExit) {
					PlaySound(slot, m_config.soundExit);
					if (__s2sdk_CancelClientMenu) {
						s2sdk::CancelClientMenu(slot, hasBack ? s2sdk::MenuCancelReason::ExitBack
															  : s2sdk::MenuCancelReason::Exit);
					}
					return; // Pisex skipped the redraw on the exit frame (GetMenuText returned "")
				}
			}
		} catch (...) {
			// never let a menu action take the frame callback down
		}
	}

	// Anti-flicker: send the full HTML every frame with a duration that never runs out between
	// frames (Pisex sent it with a zero-duration print, i.e. 5 s).
	if (!__s2sdk_PrintCentreHtml) {
		return;
	}
	try {
		const std::string html = BuildHtml(id, slot, keys);
		if (!html.empty()) {
			s2sdk::PrintCentreHtml(slot, plg::string(html),
								   m_config.htmlDuration > 0 ? m_config.htmlDuration : 5);
		}
	} catch (...) {
	}
}

} // namespace hudmenu
