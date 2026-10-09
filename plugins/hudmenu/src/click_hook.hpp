// Click intake: ISource2GameClients::ClientSvcUserMessage hook + CCSUsrMsg_CustomHudClicked
// parsing + a small click queue (game thread only).
//
// The Panorama buttons of a "custom_hud_layout" entity make the client send user message 390
// (CS_UM_CustomHudClicked, see ref/pisex/cs2-menus/utils.h) with the layout entity handle
// packed as a CEntityHandle and the clicked panel's DOM id:
//
//     message CCSUsrMsg_CustomHudClicked {
//         optional uint32 custom_hud_layout = 1 [default = 16777215];  // varint
//         optional string button_id = 2;                               // length-delimited
//     }
//
// The payload is parsed by hand (varint / length-delimited) - no libprotobuf.
//
// The hook is installed with the polyhook plugin on the interface's vtable (index from the
// gamedata file, default 38 = 11 IAppSystem virtuals + 27 ISource2GameClients virtuals before
// ClientSvcUserMessage - see the derivation next to the value in assets/gamedata.jsonc).
// Nothing in the hook callback calls into s2sdk: clicks are queued and consumed from the
// plugin's OnPluginUpdate, which keeps the engine callback free of re-entrancy and exceptions.
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>

namespace hudmenu {

// One queued click, as decoded from the usermessage.
struct PendingClick {
	int32_t slot = -1;    // CPlayerSlot that sent the message
	uint32_t layout = 0;  // custom_hud_layout (packed CEntityHandle of the layout entity)
	char button[64]{};    // button_id (DOM id of the clicked Panorama panel)
};

// Decodes CCSUsrMsg_CustomHudClicked (hand-rolled, no libprotobuf).
// Returns false when the payload is malformed.
bool ParseCustomHudClicked(const uint8_t* data, std::size_t size, uint32_t& layout,
						   char* button, std::size_t buttonCapacity);

class ClickHook {
public:
	// Resolves ISource2GameClients, hooks ClientSvcUserMessage at `vtableIndex` and registers
	// the queueing callback. On failure returns false with `error` set and installs nothing.
	bool Install(int32_t vtableIndex, std::string& error);

	// Removes the callback and unhooks. Safe to call when not installed.
	void Uninstall();

	[[nodiscard]] bool Installed() const { return m_hook != nullptr; }

	// How the interface was obtained (for hudmenu_status).
	[[nodiscard]] const std::string& InterfaceSource() const { return m_interfaceSource; }
	[[nodiscard]] int32_t VTableIndex() const { return m_vtableIndex; }

	// Appends one decoded click. Called by the polyhook trampoline (game thread). Never
	// allocates, never throws; drops when the queue is full.
	void Push(int32_t slot, uint32_t layout, const char* button) noexcept;

	// Pops up to `max` queued clicks preserving order. Game thread only.
	std::size_t Drain(PendingClick* out, std::size_t max);

	[[nodiscard]] uint64_t DroppedClicks() const { return m_dropped; }
	// Hook call counter, last captured int args and the hooked vfunc address (module+offset).
	[[nodiscard]] std::string Diagnostics() const;

private:
	static constexpr std::size_t kQueueCapacity = 32;

	// Ring buffer; only touched on the game thread (the engine dispatches client messages
	// there, and Drain runs from OnPluginUpdate on the same thread).
	PendingClick m_queue[kQueueCapacity]{};
	std::size_t m_head = 0;
	std::size_t m_tail = 0;
	uint64_t m_dropped = 0;

	void* m_interface = nullptr;
	void* m_hook = nullptr;
	int32_t m_vtableIndex = 0;
	std::string m_interfaceSource;
};

// The single hook instance used by the plugin (polyhook callbacks are plain function
// pointers and need a global sink).
ClickHook& GlobalClickHook();

} // namespace hudmenu
