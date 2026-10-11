// The Panorama menu entity ("custom_hud_layout") and the CCSCustomHudLayout natives.
//
// One global entity per map, exactly like Pisex cs2-menus (LayoutApi::CreateGlobal with the
// name "utils-dialog", layout panorama/layout/custom_game/menu_ui.xml). The entity is created
// lazily on the first display (safe once a map exists) and re-created after a map change.
// Everything is per-player: classes and dialog variables are set with the *ForPlayer natives
// for the viewing slot, so a single entity serves every player at once.
//
// All s2sdk/engine access happens on the game thread. Rendering only reads s2sdk menu state
// (the display callback is documented to use exactly these getters) and writes to the
// layout entity through the natives; it never calls back into the s2sdk menu manager, which
// keeps the manager's lock out of the picture.
#pragma once

#include <s2sdk/s2sdk.hpp>

#include <cstdint>
#include <string>

#include "utlstring.hpp"

namespace hudmenu {

// Item rows of the layout (the utils-item-0 .. utils-item-5 panels of menu_ui.xml).
constexpr int32_t kMaxItemPanels = 6;

// Rows of one page of `id` as the layout renders them: the menu's pagination, capped at
// kMaxItemPanels; a menu without pagination gets one page of kMaxItemPanels rows. The renderer
// draws exactly this many rows and blanks the remaining panels, so a click on a row past the
// page belongs to no item of it and must be ignored.
int32_t MenuPageSize(s2sdk::MenuId id);

class HudLayout {
public:
	// Resolves the CCSCustomHudLayout natives from the loaded game configuration. The three
	// per-player functions used for rendering are required; the two global variants are
	// resolved too but only reported as missing.
	bool ResolveNatives(s2sdk::ConfigId config, std::string& error);
	[[nodiscard]] bool NativesAvailable() const { return m_setHasClassForPlayer != nullptr && m_setDialogVarForPlayer != nullptr && m_setInputCapture != nullptr; }

	void SetPassthrough(const std::string& layoutName, const std::string& layoutPath) {
		m_layoutName = layoutName;
		m_layoutPath = layoutPath;
	}

	// Creates + spawns the layout entity when needed. Returns true when a live entity exists.
	bool Ensure(std::string& error);
	// The engine destroyed the entity (map change): drop the stale handle.
	void ResetHandle() { m_handle = 0; }
	// Removes the entity (plugin unload).
	void RemoveEntity();

	[[nodiscard]] bool Alive() const;
	[[nodiscard]] int32_t Handle() const { return m_handle; }

	// Renders one s2sdk menu for one player (idempotent; also called on every page turn).
	void RenderMenu(int32_t slot, s2sdk::MenuId id);
	// Hides the menu and releases input capture for one player.
	void HideForSlot(int32_t slot);
	// Hides the menu and releases input capture for every slot.
	void HideAll();

private:
	void* EntityPointer() const;
	void SetClass(int32_t slot, const char* panel, const char* className, bool on);
	// Sets exactly one of the item kind classes (k-empty/k-value/k-submenu/k-toggle/k-select).
	void SetItemKindClasses(int32_t slot, const char* panel, const char* kind);
	void SetVariable(int32_t slot, const char* panel, const char* variable, const char* value);
	void SetCapture(int32_t slot, bool on);

	// Game ABI (see assets/gamedata.jsonc); CUtlString is represented by UtlString.
	using SetHasClassForPlayerFn = void (*)(void*, int32_t, const UtlString*, const UtlString*, int32_t);
	using SetHasClassGlobalFn = void (*)(void*, const UtlString*, const UtlString*, int32_t);
	using SetDialogVariableForPlayerFn = void (*)(void*, int32_t, const UtlString*, const UtlString*, const UtlString*);
	using SetDialogVariableGlobalFn = void (*)(void*, const UtlString*, const UtlString*, const UtlString*);
	using SetInputCaptureEnabledFn = void (*)(void*, int32_t, bool);

	static constexpr int32_t kHasClass = 1;
	static constexpr int32_t kDoesNotHaveClass = 0;

	SetHasClassForPlayerFn m_setHasClassForPlayer = nullptr;
	SetDialogVariableForPlayerFn m_setDialogVarForPlayer = nullptr;
	SetInputCaptureEnabledFn m_setInputCapture = nullptr;
	SetHasClassGlobalFn m_setHasClassGlobal = nullptr;
	SetDialogVariableGlobalFn m_setDialogVarGlobal = nullptr;

	UtlStringApi m_strings;
	// The layout entity handle (packed CEntityHandle as s2sdk uses it), 0 until created.
	int32_t m_handle = 0;
	// Entity name / panel id of the content panel (Pisex: "utils-dialog").
	std::string m_layoutName = "utils-dialog";
	// Panorama layout file the entity is spawned with.
	std::string m_layoutPath = "panorama/layout/custom_game/menu_ui.xml";
};

} // namespace hudmenu
