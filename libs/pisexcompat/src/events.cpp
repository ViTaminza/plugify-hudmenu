#include <pisex/events.hpp>

#include <pisex/output.hpp>

#include <plg/string.hpp>
#include <s2sdk/s2sdk.hpp>

#include <exception>
#include <functional>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

namespace pisex {
namespace {

// Lookup by string_view without building a std::string per event fire.
struct EventNameHash {
	using is_transparent = void;
	size_t operator()(std::string_view text) const noexcept { return std::hash<std::string_view>{}(text); }
};
// Each list is immutable once published: (un)hooking publishes a new list, so an event fire keeps
// iterating its snapshot (a callback may hook/unhook events) without copying the callbacks.
using EventHookList = std::shared_ptr<const std::vector<EventCallback>>;
std::unordered_map<std::string, EventHookList, EventNameHash, std::equal_to<>> g_hooks;

// Map lifecycle (deliberate choice): events are still delivered to plugins while no map is up
// (they arrive as data only - slot numbers and values), because dropping e.g. player_disconnect
// during a changelevel would leave plugin state stale (the admin core's disconnect handling).
// Anything a handler then asks *about* a client/entity goes through the pisexcompat wrappers,
// which are gated on the map state (IsGameReady()/IsClientReady()) and answer with defaults in
// that window - no s2sdk client/entity call is made. Timers and NextFrame callbacks are the other
// way round: they are postponed to the first ready frame (timers.cpp), because a ported callback
// is almost always "do something to the players".
s2sdk::ResultType EventTrampoline(const plg::string& name, void* event, bool dontBroadcast) {
	try {
		if (g_hooks.empty()) {
			return s2sdk::ResultType::Continue;
		}
		const std::string_view eventName(name.data(), name.size());
		const auto found = g_hooks.find(eventName);
		if (found == g_hooks.end() || !found->second) {
			return s2sdk::ResultType::Continue;
		}
		// Snapshot (a refcount, no copy): a callback may hook/unhook events.
		const EventHookList callbacks = found->second;
		IGameEvent handle(event);
		for (const EventCallback& callback : *callbacks) {
			if (!callback) {
				continue;
			}
			callback(eventName.data(), &handle, dontBroadcast);
		}
	} catch (const std::exception& ex) {
		ErrorLog("pisexcompat: event callback threw: %s", ex.what());
	} catch (...) {
		ErrorLog("pisexcompat: event callback threw an unknown exception");
	}
	// Pre hooks cannot veto an event through this API (Pisex's old HookEvent could not either).
	return s2sdk::ResultType::Continue;
}

} // namespace

const char* IGameEvent::GetName() const {
	static thread_local std::string name;
	if (!__s2sdk_GetEventName) {
		return "";
	}
	try {
		const plg::string eventName = s2sdk::GetEventName(event_);
		name.assign(eventName.data(), eventName.size());
	} catch (...) {
		name.clear();
	}
	return name.c_str();
}

bool IGameEvent::GetBool(const char* key, bool def) const {
	if (!event_ || !__s2sdk_GetEventBool) {
		return def;
	}
	try {
		return s2sdk::GetEventBool(event_, plg::string(key ? key : ""));
	} catch (...) {
		return def;
	}
}

float IGameEvent::GetFloat(const char* key, float def) const {
	if (!event_ || !__s2sdk_GetEventFloat) {
		return def;
	}
	try {
		return s2sdk::GetEventFloat(event_, plg::string(key ? key : ""));
	} catch (...) {
		return def;
	}
}

int IGameEvent::GetInt(const char* key, int def) const {
	if (!event_ || !__s2sdk_GetEventInt) {
		return def;
	}
	try {
		return static_cast<int>(s2sdk::GetEventInt(event_, plg::string(key ? key : "")));
	} catch (...) {
		return def;
	}
}

unsigned long long IGameEvent::GetUInt64(const char* key, unsigned long long def) const {
	if (!event_ || !__s2sdk_GetEventUInt64) {
		return def;
	}
	try {
		return static_cast<unsigned long long>(s2sdk::GetEventUInt64(event_, plg::string(key ? key : "")));
	} catch (...) {
		return def;
	}
}

const char* IGameEvent::GetString(const char* key, const char* def) const {
	if (!event_ || !__s2sdk_GetEventString) {
		return def;
	}
	try {
		const plg::string value = s2sdk::GetEventString(event_, plg::string(key ? key : ""));
		const std::string& stored = strings_[key ? key : ""] = std::string(value.data(), value.size());
		return stored.c_str();
	} catch (...) {
		return def;
	}
}

int IGameEvent::GetPlayerSlot(const char* key) const {
	if (!event_ || !__s2sdk_GetEventPlayerSlot) {
		return -1;
	}
	try {
		return s2sdk::GetEventPlayerSlot(event_, plg::string(key ? key : ""));
	} catch (...) {
		return -1;
	}
}

void IGameEvent::SetBool(const char* key, bool value) const {
	if (!event_ || !__s2sdk_SetEventBool) {
		return;
	}
	try {
		s2sdk::SetEventBool(event_, plg::string(key ? key : ""), value);
	} catch (...) {
	}
}

void IGameEvent::SetFloat(const char* key, float value) const {
	if (!event_ || !__s2sdk_SetEventFloat) {
		return;
	}
	try {
		s2sdk::SetEventFloat(event_, plg::string(key ? key : ""), value);
	} catch (...) {
	}
}

void IGameEvent::SetInt(const char* key, int value) const {
	if (!event_ || !__s2sdk_SetEventInt) {
		return;
	}
	try {
		s2sdk::SetEventInt(event_, plg::string(key ? key : ""), value);
	} catch (...) {
	}
}

void IGameEvent::SetUInt64(const char* key, unsigned long long value) const {
	if (!event_ || !__s2sdk_SetEventUInt64) {
		return;
	}
	try {
		s2sdk::SetEventUInt64(event_, plg::string(key ? key : ""), value);
	} catch (...) {
	}
}

void IGameEvent::SetString(const char* key, const char* value) const {
	if (!event_ || !__s2sdk_SetEventString) {
		return;
	}
	try {
		s2sdk::SetEventString(event_, plg::string(key ? key : ""), plg::string(value ? value : ""));
	} catch (...) {
	}
}

void IGameEvent::SetPlayerSlot(const char* key, int slot) const {
	if (!event_ || !__s2sdk_SetEventPlayerSlot) {
		return;
	}
	try {
		s2sdk::SetEventPlayerSlot(event_, plg::string(key ? key : ""), slot);
	} catch (...) {
	}
}

void HookEvent(const char* name, const EventCallback& callback) {
	if (!name || !*name || !callback || !__s2sdk_HookEvent) {
		return;
	}
	try {
		EventHookList& callbacks = g_hooks[std::string(name)];
		const bool first = !callbacks || callbacks->empty();
		auto updated = callbacks ? std::make_shared<std::vector<EventCallback>>(*callbacks)
								 : std::make_shared<std::vector<EventCallback>>();
		updated->push_back(callback);
		callbacks = std::move(updated);
		if (first && s2sdk::HookEvent(plg::string(name), &EventTrampoline, s2sdk::HookMode::Pre) !=
						 s2sdk::EventHookError::Okay) {
			ErrorLog("pisexcompat: HookEvent('%s') was rejected by s2sdk", name);
		}
	} catch (const std::exception& ex) {
		ErrorLog("pisexcompat: HookEvent failed: %s", ex.what());
	} catch (...) {
		ErrorLog("pisexcompat: HookEvent failed with an unknown exception");
	}
}

void UnhookEvent(const char* name) {
	if (!name || !*name) {
		return;
	}
	g_hooks.erase(std::string(name));
	if (__s2sdk_UnhookEvent) {
		try {
			s2sdk::UnhookEvent(plg::string(name), &EventTrampoline, s2sdk::HookMode::Pre);
		} catch (...) {
		}
	}
}

void RemoveAllEvents() {
	for (const auto& entry : g_hooks) {
		if (__s2sdk_UnhookEvent) {
			try {
				s2sdk::UnhookEvent(plg::string(entry.first), &EventTrampoline, s2sdk::HookMode::Pre);
			} catch (...) {
			}
		}
	}
	g_hooks.clear();
}

} // namespace pisex
