#include <atomic>
#include <dlfcn.h>
#include "click_hook.hpp"

#include <polyhook/polyhook.hpp>
#include <s2sdk/s2sdk.hpp>

#include <dlfcn.h>
#include <link.h> // dl_iterate_phdr

#include <cstring>

namespace hudmenu {
namespace {

// The CCSUsrMsg_CustomHudClicked usermessage id.
constexpr int32_t kCustomHudClickedUm = 390;
// Max player slots (CPlayerSlot range).
constexpr int32_t kMaxSlots = 64;
// A sane upper bound for the usermessage payload (button ids are short).
constexpr uint32_t kMaxPayload = 1024;
// How many argument slots the callback scans for the um_type constant.
constexpr int32_t kMaxArgumentScan = 8;

// --- protobuf (proto2) minimal reader ----------------------------------------

class ProtoReader {
public:
	ProtoReader(const uint8_t* data, std::size_t size) : m_cursor(data), m_end(data + size) {}

	[[nodiscard]] bool Eof() const { return m_cursor >= m_end; }

	bool Varint(uint64_t& value) {
		value = 0;
		for (int shift = 0; shift <= 63; shift += 7) {
			if (m_cursor >= m_end) {
				return false;
			}
			const uint8_t byte = *m_cursor++;
			value |= static_cast<uint64_t>(byte & 0x7f) << shift;
			if ((byte & 0x80) == 0) {
				return true;
			}
		}
		return false;
	}

	bool Bytes(const uint8_t*& data, std::size_t& length) {
		uint64_t size = 0;
		if (!Varint(size) || size > static_cast<uint64_t>(m_end - m_cursor)) {
			return false;
		}
		data = m_cursor;
		length = static_cast<std::size_t>(size);
		m_cursor += size;
		return true;
	}

	bool Skip(uint32_t wireType) {
		switch (wireType) {
		case 0: { // varint
			uint64_t ignored = 0;
			return Varint(ignored);
		}
		case 1: // fixed64
			if (m_end - m_cursor < 8) {
				return false;
			}
			m_cursor += 8;
			return true;
		case 2: { // length-delimited
			const uint8_t* ignoredData = nullptr;
			std::size_t ignoredLength = 0;
			return Bytes(ignoredData, ignoredLength);
		}
		case 5: // fixed32
			if (m_end - m_cursor < 4) {
				return false;
			}
			m_cursor += 4;
			return true;
		default: // groups (3/4) are not used by this message
			return false;
		}
	}

private:
	const uint8_t* m_cursor;
	const uint8_t* m_end;
};

// --- ISource2GameClients resolution ------------------------------------------

struct ModuleSearch {
	const char* needle = nullptr;
	void* handle = nullptr;
};

int FindModuleCallback(struct dl_phdr_info* info, size_t /*size*/, void* data) {
	auto& search = *static_cast<ModuleSearch*>(data);
	if (info->dlpi_name != nullptr && search.needle != nullptr &&
		std::strstr(info->dlpi_name, search.needle) != nullptr) {
		// RTLD_NOLOAD: only reference the copy the process already has.
		search.handle = dlopen(info->dlpi_name, RTLD_NOW | RTLD_NOLOAD);
		return 1; // stop iteration
	}
	return 0;
}

void* FindLoadedModule(const char* needle) {
	ModuleSearch search{needle, nullptr};
	dl_iterate_phdr(&FindModuleCallback, &search);
	return search.handle;
}

// Fallback for s2sdk::QueryInterface: the game's libserver factory.
void* CreateInterfaceFromServerModule(std::string& source) {
	using CreateInterfaceFn = void* (*)(const char* name, int* returnCode);

	void* module = dlopen("libserver.so", RTLD_NOW | RTLD_NOLOAD);
	if (module == nullptr) {
		module = FindLoadedModule("libserver.so");
	}
	if (module == nullptr) {
		return nullptr;
	}
	auto createInterface = reinterpret_cast<CreateInterfaceFn>(dlsym(module, "CreateInterface"));
	if (createInterface == nullptr) {
		dlclose(module);
		return nullptr;
	}
	int returnCode = 0;
	void* iface = createInterface("Source2GameClients001", &returnCode);
	if (iface == nullptr) {
		dlclose(module);
		return nullptr;
	}
	source = "dlopen(libserver.so)+CreateInterface(\"Source2GameClients001\")";
	return iface; // module stays loaded; the interface outlives the plugin
}

// Diagnostics for hudmenu_status: how often the hook fired and the first int args seen.
std::atomic<uint64_t> g_hookCalls{0};
std::atomic<int32_t> g_lastArgs[4];
std::atomic<int32_t> g_lastCount{0};

// polyhook callback (game thread, inside the engine's client message dispatch).
polyhook::ResultType OnClientSvcUserMessage(polyhook::HookHandle hook, polyhook::ParametersHandle params,
											int32_t count, polyhook::ReturnHandle ret, polyhook::CallbackType type) {
	(void)hook;
	(void)ret;
	(void)type;
	// No exception may escape into the engine; nothing here logs, allocates or calls out.
	try {
		g_hookCalls.fetch_add(1, std::memory_order_relaxed);
		g_lastCount.store(count, std::memory_order_relaxed);
		if (params == nullptr || count <= 0) {
			return polyhook::ResultType::Ignored;
		}
		for (int32_t i = 0; i < 4 && i < count; ++i) {
			g_lastArgs[i].store(polyhook::GetArgumentInt32(params, static_cast<uint64_t>(i)), std::memory_order_relaxed);
		}
		// Locate um_type by its value instead of trusting an index: polyhook may or may not
		// include `this` in the captured arguments (see the header of this file).
		const int32_t scan = count < kMaxArgumentScan ? count : kMaxArgumentScan;
		int32_t umIndex = -1;
		for (int32_t i = 0; i < scan; ++i) {
			if (polyhook::GetArgumentInt32(params, static_cast<uint64_t>(i)) == kCustomHudClickedUm) {
				umIndex = i;
				break;
			}
		}
		// Need the client slot before um_type and size + buffer after it.
		if (umIndex < 1 || umIndex + 2 >= count) {
			return polyhook::ResultType::Ignored;
		}
		const int32_t slot = polyhook::GetArgumentInt32(params, static_cast<uint64_t>(umIndex - 1));
		const uint32_t size = polyhook::GetArgumentUInt32(params, static_cast<uint64_t>(umIndex + 1));
		const void* buffer = polyhook::GetArgumentPointer(params, static_cast<uint64_t>(umIndex + 2));
		if (slot < 0 || slot >= kMaxSlots || buffer == nullptr || size == 0 || size > kMaxPayload) {
			return polyhook::ResultType::Ignored;
		}
		uint32_t layout = 0;
		char button[64];
		if (!ParseCustomHudClicked(static_cast<const uint8_t*>(buffer), size, layout, button, sizeof(button))) {
			return polyhook::ResultType::Ignored;
		}
		GlobalClickHook().Push(slot, layout, button);
	} catch (...) {
		// swallowed: a throw here would unwind into the engine's message pump
	}
	return polyhook::ResultType::Ignored; // always let the original handler run
}

} // namespace

bool ParseCustomHudClicked(const uint8_t* data, std::size_t size, uint32_t& layout,
						   char* button, std::size_t buttonCapacity) {
	layout = 0xFFFFFF; // proto2 default of custom_hud_layout
	button[0] = '\0';
	if (data == nullptr || size == 0 || buttonCapacity == 0) {
		return false;
	}
	ProtoReader reader(data, size);
	bool sawLayout = false;
	bool sawButton = false;
	while (!reader.Eof()) {
		uint64_t tag = 0;
		if (!reader.Varint(tag)) {
			return false;
		}
		const uint32_t field = static_cast<uint32_t>(tag >> 3);
		const uint32_t wireType = static_cast<uint32_t>(tag & 0x7);
		if (field == 1 && wireType == 0) {
			uint64_t value = 0;
			if (!reader.Varint(value)) {
				return false;
			}
			layout = static_cast<uint32_t>(value);
			sawLayout = true;
		} else if (field == 2 && wireType == 2) {
			const uint8_t* bytes = nullptr;
			std::size_t length = 0;
			if (!reader.Bytes(bytes, length)) {
				return false;
			}
			const std::size_t copy = length < buttonCapacity - 1 ? length : buttonCapacity - 1;
			std::memcpy(button, bytes, copy);
			button[copy] = '\0';
			sawButton = true;
		} else if (!reader.Skip(wireType)) {
			return false;
		}
	}
	(void)sawLayout;
	(void)sawButton;
	return true;
}

ClickHook& GlobalClickHook() {
	static ClickHook instance;
	return instance;
}

void ClickHook::Push(int32_t slot, uint32_t layout, const char* button) noexcept {
	const std::size_t next = (m_tail + 1) % kQueueCapacity;
	if (next == m_head) {
		++m_dropped; // full: drop rather than block the engine
		return;
	}
	PendingClick& click = m_queue[m_tail];
	click.slot = slot;
	click.layout = layout;
	std::strncpy(click.button, button != nullptr ? button : "", sizeof(click.button) - 1);
	click.button[sizeof(click.button) - 1] = '\0';
	m_tail = next;
}

std::size_t ClickHook::Drain(PendingClick* out, std::size_t max) {
	std::size_t count = 0;
	while (count < max && m_head != m_tail) {
		out[count++] = m_queue[m_head];
		m_head = (m_head + 1) % kQueueCapacity;
	}
	return count;
}

bool ClickHook::Install(int32_t vtableIndex, std::string& error) {
	if (Installed()) {
		return true;
	}
	if (!__polyhook_HookVirtualTable || !__polyhook_AddCallback || !__polyhook_UnhookVirtualTable ||
		!__polyhook_GetArgumentInt32 || !__polyhook_GetArgumentUInt32 || !__polyhook_GetArgumentPointer) {
		error = "polyhook bindings are not available (is the polyhook plugin >= 2.5.2 installed?)";
		return false;
	}

	void* iface = nullptr;
	// Primary: s2sdk's own module provider (their gamedata "library" name for libserver.so).
	if (__s2sdk_QueryInterface) {
		try {
			iface = s2sdk::QueryInterface("server", "Source2GameClients001");
			if (iface != nullptr) {
				m_interfaceSource = "s2sdk::QueryInterface(\"server\", \"Source2GameClients001\")";
			}
		} catch (...) {
			iface = nullptr;
		}
	}
	if (iface == nullptr) {
		iface = CreateInterfaceFromServerModule(m_interfaceSource);
	}
	if (iface == nullptr) {
		error = "ISource2GameClients (Source2GameClients001) could not be resolved from libserver.so";
		return false;
	}
	if (vtableIndex < 0) {
		error = "invalid ClientSvcUserMessage vtable index";
		return false;
	}

	plg::vector<polyhook::DataType> arguments;
	arguments.reserve(6);
	arguments.push_back(polyhook::DataType::Pointer); // this (only present for the member call)
	arguments.push_back(polyhook::DataType::Int32);   // CPlayerSlot slot
	arguments.push_back(polyhook::DataType::Int32);   // int um_type
	arguments.push_back(polyhook::DataType::UInt32);  // uint32 size
	arguments.push_back(polyhook::DataType::Pointer); // const void* buf
	// One spare declared slot: whether polyhook counts `this` among the declared arguments
	// (and which registers it therefore captures) is not part of the binding docs; the extra
	// slot keeps slot/um_type/size/buf inside the captured array under either convention, and
	// the callback finds um_type by value anyway.
	arguments.push_back(polyhook::DataType::Pointer);

	polyhook::HookHandle hook = nullptr;
	try {
		hook = polyhook::HookVirtualTable(iface, vtableIndex, polyhook::DataType::Void, arguments, -1,
										  "hudmenu_ClientSvcUserMessage");
	} catch (...) {
		hook = nullptr;
	}
	if (hook == nullptr) {
		std::string polyhookError;
		try {
			if (__polyhook_GetError) {
				polyhookError = std::string(std::string_view(polyhook::GetError()));
			}
		} catch (...) {
		}
		error = "polyhook::HookVirtualTable failed on index " + std::to_string(vtableIndex);
		if (!polyhookError.empty()) {
			error += ": " + polyhookError;
		}
		return false;
	}

	bool callbackAdded = false;
	try {
		callbackAdded = polyhook::AddCallback(hook, polyhook::CallbackType::Pre, &OnClientSvcUserMessage);
	} catch (...) {
		callbackAdded = false;
	}
	if (!callbackAdded) {
		// Nothing of ours is attached to the hook. UnhookVirtualTable(object, index) removes that
		// index's callback for every hooker of the shared hook object, so it must only be called
		// when no callback is registered on the index anymore.
		if (__polyhook_AreCallbacksRegistered) {
			try {
				if (!polyhook::AreCallbacksRegistered(hook)) {
					polyhook::UnhookVirtualTable(iface, vtableIndex);
				}
			} catch (...) {
			}
		}
		error = "polyhook::AddCallback failed for the ClientSvcUserMessage hook";
		return false;
	}

	m_interface = iface;
	m_hook = hook;
	m_vtableIndex = vtableIndex;
	return true;
}

void ClickHook::Uninstall() {
	if (m_hook == nullptr) {
		return;
	}
	const polyhook::HookHandle hook = m_hook;
	void* iface = m_interface;
	const int32_t index = m_vtableIndex;
	m_hook = nullptr;
	m_interface = nullptr;
	try {
		polyhook::RemoveCallback(hook, polyhook::CallbackType::Pre, &OnClientSvcUserMessage);
	} catch (...) {
	}
	// UnhookVirtualTable(object, index) removes that index's callback for every hooker of the
	// shared hook object (s2sdk hooks other indices of ISource2GameClients): drop our index only
	// once nothing is registered on it anymore - and never use UnhookAllVirtual.
	if (__polyhook_AreCallbacksRegistered && __polyhook_UnhookVirtualTable) {
		try {
			if (!polyhook::AreCallbacksRegistered(hook)) {
				polyhook::UnhookVirtualTable(iface, index);
			}
		} catch (...) {
		}
	}
}

} // namespace hudmenu

namespace hudmenu {
std::string ClickHook::Diagnostics() const {
	std::string out = "calls=" + std::to_string(g_hookCalls.load()) + " last_count=" + std::to_string(g_lastCount.load()) + " last_args=[";
	for (int i = 0; i < 4; ++i) {
		out += (i ? "," : "") + std::to_string(g_lastArgs[i].load());
	}
	out += "]";
	if (m_interface != nullptr) {
		void** vtable = *reinterpret_cast<void***>(m_interface);
		void* fn = vtable[m_vtableIndex];
		Dl_info info{};
		if (dladdr(fn, &info) != 0 && info.dli_fbase != nullptr) {
			char buf[160];
			std::snprintf(buf, sizeof(buf), " vfunc[%d]=%s+0x%zx", m_vtableIndex, info.dli_fname ? info.dli_fname : "?",
						  static_cast<std::size_t>(reinterpret_cast<uintptr_t>(fn) - reinterpret_cast<uintptr_t>(info.dli_fbase)));
			out += buf;
		}
	}
	return out;
}
} // namespace hudmenu
