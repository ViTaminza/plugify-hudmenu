#include "hud_layout.hpp"

#include "log.hpp"

#include <cstdio>
#include <cstring>
#include <string>

namespace hudmenu {
namespace {

// Panel ids of the menu layout (ref/pisex/cs2-menus/custom_menu/panorama/layout/custom_game/menu_ui.xml,
// shipped by the workshop addon).
constexpr const char* kDialogPanel = "utils-dialog";
constexpr const char* kPagePanel = "utils-page";
constexpr const char* kPrevPanel = "utils-prev";
constexpr const char* kNextPanel = "utils-next";
constexpr const char* kBackAnchor = "utils-back-anchor";
// Item kind classes (Pisex UTIL_SetLayoutItemKind).
constexpr const char* kItemKinds[] = {"k-empty", "k-value", "k-submenu", "k-toggle", "k-select"};

} // namespace

bool HudLayout::ResolveNatives(s2sdk::ConfigId config, std::string& error) {
	if (!__s2sdk_GetGameConfigSignature) {
		error = "s2sdk GetGameConfigSignature binding is not available";
		return false;
	}
	const auto fetch = [config](const char* name) -> void* {
		try {
			return s2sdk::GetGameConfigSignature(config, plg::string(name));
		} catch (...) {
			return nullptr;
		}
	};

	m_setHasClassForPlayer = reinterpret_cast<SetHasClassForPlayerFn>(fetch("CCSCustomHudLayout_SetHasClassForPlayer"));
	m_setDialogVarForPlayer =
		reinterpret_cast<SetDialogVariableForPlayerFn>(fetch("CCSCustomHudLayout_SetDialogVariableStringForPlayer"));
	m_setInputCapture = reinterpret_cast<SetInputCaptureEnabledFn>(fetch("CCSCustomHudLayout_SetInputCaptureEnabled"));
	m_setHasClassGlobal = reinterpret_cast<SetHasClassGlobalFn>(fetch("CCSCustomHudLayout_SetHasClass"));
	m_setDialogVarGlobal =
		reinterpret_cast<SetDialogVariableGlobalFn>(fetch("CCSCustomHudLayout_SetDialogVariableString"));

	std::string missing;
	if (m_setHasClassForPlayer == nullptr) {
		missing += " CCSCustomHudLayout_SetHasClassForPlayer";
	}
	if (m_setDialogVarForPlayer == nullptr) {
		missing += " CCSCustomHudLayout_SetDialogVariableStringForPlayer";
	}
	if (m_setInputCapture == nullptr) {
		missing += " CCSCustomHudLayout_SetInputCaptureEnabled";
	}
	if (!missing.empty()) {
		error = "CCSCustomHudLayout native signature(s) not found in libserver.so:" + missing;
		return false;
	}
	if (m_setHasClassGlobal == nullptr) {
		LogWarn("hudmenu: optional signature CCSCustomHudLayout_SetHasClass is missing (not used by the renderer)");
	}
	if (m_setDialogVarGlobal == nullptr) {
		LogWarn("hudmenu: optional signature CCSCustomHudLayout_SetDialogVariableString is missing (not used by the renderer)");
	}
	if (!m_strings.Resolve()) {
		error = "libtier0.so does not export CUtlString::Set/Purge (needed to pass strings to the natives)";
		return false;
	}
	return true;
}

void* HudLayout::EntityPointer() const {
	if (m_handle == 0 || !__s2sdk_EntHandleToEntPointer) {
		return nullptr;
	}
	try {
		return s2sdk::EntHandleToEntPointer(m_handle);
	} catch (...) {
		return nullptr;
	}
}

bool HudLayout::Alive() const {
	return EntityPointer() != nullptr;
}

bool HudLayout::Ensure(std::string& error) {
	if (Alive()) {
		return true;
	}
	if (!NativesAvailable()) {
		error = "layout natives are not resolved";
		return false;
	}
	if (!__s2sdk_CreateEntityByName || !__s2sdk_DispatchSpawn2) {
		error = "s2sdk entity bindings are not available";
		return false;
	}
	try {
		const int32_t handle = s2sdk::CreateEntityByName("custom_hud_layout");
		if (handle == 0 || handle == -1) {
			error = "CreateEntityByName(\"custom_hud_layout\") failed";
			return false;
		}
		// Same keyvalues Pisex sets with CEntityKeyValues before DispatchSpawn: the entity
		// name and the Panorama layout file to load.
		plg::vector<plg::string> keys;
		keys.push_back(plg::string("targetname"));
		keys.push_back(plg::string("layout"));
		plg::vector<plg::any> values;
		values.push_back(plg::any(plg::string(m_layoutName)));
		values.push_back(plg::any(plg::string(m_layoutPath)));
		s2sdk::DispatchSpawn2(handle, keys, values);

		m_handle = handle;
		if (!Alive()) {
			error = "the custom_hud_layout entity did not spawn";
			m_handle = 0;
			return false;
		}
		LogInfo("hudmenu: custom_hud_layout entity created (handle " + std::to_string(handle) + ", layout " +
				m_layoutPath + ")");
		return true;
	} catch (const std::exception& ex) {
		error = std::string("creating the custom_hud_layout entity failed: ") + ex.what();
		m_handle = 0;
		return false;
	} catch (...) {
		error = "creating the custom_hud_layout entity failed with an unknown exception";
		m_handle = 0;
		return false;
	}
}

void HudLayout::RemoveEntity() {
	if (m_handle == 0) {
		return;
	}
	try {
		if (Alive() && __s2sdk_RemoveEntity) {
			s2sdk::RemoveEntity(m_handle);
		}
	} catch (...) {
	}
	m_handle = 0;
}

void HudLayout::SetClass(int32_t slot, const char* panel, const char* className, bool on) {
	void* entity = EntityPointer();
	if (entity == nullptr || m_setHasClassForPlayer == nullptr) {
		return;
	}
	UtlStringPack strings(m_strings);
	const UtlString* panelId = strings.Add(panel);
	const UtlString* classId = strings.Add(className);
	m_setHasClassForPlayer(entity, slot, panelId, classId, on ? kHasClass : kDoesNotHaveClass);
}

void HudLayout::SetVariable(int32_t slot, const char* panel, const char* variable, const char* value) {
	void* entity = EntityPointer();
	if (entity == nullptr || m_setDialogVarForPlayer == nullptr) {
		return;
	}
	UtlStringPack strings(m_strings);
	const UtlString* panelId = strings.Add(panel);
	const UtlString* variableId = strings.Add(variable);
	const UtlString* valueId = strings.Add(value);
	m_setDialogVarForPlayer(entity, slot, panelId, variableId, valueId);
}

void HudLayout::SetItemKindClasses(int32_t slot, const char* panel, const char* kind) {
	for (const char* itemKind : kItemKinds) {
		SetClass(slot, panel, itemKind, std::strcmp(itemKind, kind) == 0);
	}
}

void HudLayout::SetCapture(int32_t slot, bool on) {
	void* entity = EntityPointer();
	if (entity == nullptr || m_setInputCapture == nullptr) {
		return;
	}
	m_setInputCapture(entity, slot, on);
}

void HudLayout::RenderMenu(int32_t slot, s2sdk::MenuId id) {
	// The s2sdk menu manager calls this with its lock held: only read menu state through the
	// documented getters and only write to the layout entity; never call back into the
	// manager (no SelectMenuItem/DisplayMenu/etc. here).
	if (EntityPointer() == nullptr || !__s2sdk_GetMenuTitle || !__s2sdk_GetMenuItemsCount ||
		!__s2sdk_GetClientMenuOffset || !__s2sdk_GetMenuItemDisplay || !__s2sdk_GetMenuItemStyle) {
		return;
	}
	try {
		const std::string title = ToString(s2sdk::GetMenuTitle(id));
		const int32_t itemCount = s2sdk::GetMenuItemsCount(id);
		const int32_t pagination = __s2sdk_GetMenuPagination ? s2sdk::GetMenuPagination(id) : 0;
		const bool paginated = pagination > 0;
		int32_t perPage = paginated ? pagination : kMaxItemPanels;
		if (perPage > kMaxItemPanels) {
			// The layout has a fixed six rows; a page larger than that shows its first six
			// items (consumers like pisexcompat always paginate at five).
			perPage = kMaxItemPanels;
		}
		const int32_t offset = s2sdk::GetClientMenuOffset(slot);
		// Without pagination the manager keeps everything on one page (offset 0, no
		// prev/next), so the label must not pretend the clamped rows are real pages.
		const int32_t pages = !paginated || itemCount <= 0 ? 1 : (itemCount + perPage - 1) / perPage;
		const int32_t page = !paginated || offset < 0 ? 0 : offset / perPage;

		SetVariable(slot, kDialogPanel, "title", title.c_str());
		SetVariable(slot, kDialogPanel, "desc", "");
		char pageText[32];
		std::snprintf(pageText, sizeof(pageText), "%d / %d", page + 1, pages);
		SetVariable(slot, kPagePanel, "page", pageText);

		const bool hasPrev = __s2sdk_ClientMenuHasPrevPage && s2sdk::ClientMenuHasPrevPage(slot);
		const bool hasNext = __s2sdk_ClientMenuHasNextPage && s2sdk::ClientMenuHasNextPage(slot);
		SetClass(slot, kPrevPanel, "utils-disabled", !hasPrev);
		SetClass(slot, kNextPanel, "utils-disabled", !hasNext);

		const bool hasBack = __s2sdk_GetMenuExitBackButton && s2sdk::GetMenuExitBackButton(id);
		SetClass(slot, kBackAnchor, "utils-hide", !hasBack);

		for (int32_t i = 0; i < kMaxItemPanels; ++i) {
			char panel[32];
			std::snprintf(panel, sizeof(panel), "utils-item-%d", i);
			const int32_t index = offset + i;
			if (index < 0 || index >= itemCount) {
				// Pisex's empty row: blank, not disabled, plain kind.
				SetItemKindClasses(slot, panel, "k-empty");
				SetClass(slot, panel, "is-disabled", false);
				SetClass(slot, panel, "is-on", false);
				SetClass(slot, panel, "is-open", false);
				SetClass(slot, panel, "is-up", false);
				SetVariable(slot, panel, "label", "");
				SetVariable(slot, panel, "value", "");
				continue;
			}
			const s2sdk::MenuItemStyle style = s2sdk::GetMenuItemStyle(id, index);
			const std::string label = ToString(s2sdk::GetMenuItemDisplay(id, index));
			SetItemKindClasses(slot, panel, style == s2sdk::MenuItemStyle::Spacer ? "k-empty" : "k-submenu");
			SetClass(slot, panel, "is-disabled", style == s2sdk::MenuItemStyle::Disabled);
			SetClass(slot, panel, "is-on", false);
			SetClass(slot, panel, "is-open", false);
			SetClass(slot, panel, "is-up", false);
			SetVariable(slot, panel, "label", label.c_str());
			SetVariable(slot, panel, "value", "");
		}

		SetClass(slot, kDialogPanel, "utils-dismissed", false);
		SetCapture(slot, true);
	} catch (const std::exception& ex) {
		LogError(std::string("hudmenu: render failed for slot ") + std::to_string(slot) + ": " + ex.what());
	} catch (...) {
		LogError(std::string("hudmenu: render failed for slot ") + std::to_string(slot) + " with an unknown exception");
	}
}

void HudLayout::HideForSlot(int32_t slot) {
	try {
		if (EntityPointer() == nullptr) {
			return;
		}
		SetClass(slot, kDialogPanel, "utils-dismissed", true);
		SetCapture(slot, false);
	} catch (...) {
	}
}

void HudLayout::HideAll() {
	try {
		if (EntityPointer() == nullptr) {
			return;
		}
		for (int32_t slot = 0; slot < 64; ++slot) {
			SetClass(slot, kDialogPanel, "utils-dismissed", true);
			SetCapture(slot, false);
		}
	} catch (...) {
	}
}

} // namespace hudmenu
