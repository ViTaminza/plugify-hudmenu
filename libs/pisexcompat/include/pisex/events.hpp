// pisexcompat — game event hooks over s2sdk.
//
//   g_pUtils->HookEvent("player_death", [](const char* szName, IGameEvent* pEvent, bool bDontBroadcast) {
//       const int victim = pEvent->GetInt("userid");
//   });
//
// Pisex's HookEvent is a *pre* hook: cs2-menus installs a SourceHook on IGameEventManager2::FireEvent
// and calls the plugin callbacks before the engine processes the event, with the event pointer and
// the current broadcast flag. s2sdk::HookEvent(..., HookMode::Pre) is the same point, so the ported
// callbacks keep their signature and their behaviour (they may read and even change values; the
// engine honours the changes made in a pre hook).
//
// The value accessors mirror the IGameEvent getters the Pisex modules use. GetString() stores the
// engine string in a per-handle cache, so the returned pointer stays valid as long as the event
// does (IGameEvent::GetString() had the same guarantee for the event's lifetime).
//
// Event hooks survive map changes (like the Pisex ones) and are removed by Shutdown().

#pragma once

#include <functional>
#include <map>
#include <string>
#include <string_view>
#include <vector>

namespace pisex {

// Thin wrapper around the s2sdk event pointer (IGameEvent* in the Metamod code).
class IGameEvent {
public:
	IGameEvent() = default;
	explicit IGameEvent(void* event) : event_(event) {}

	bool IsValid() const { return event_ != nullptr; }
	void* Native() const { return event_; }

	const char* GetName() const;

	bool GetBool(const char* key, bool def = false) const;
	float GetFloat(const char* key, float def = 0.0f) const;
	int GetInt(const char* key, int def = 0) const;
	unsigned long long GetUInt64(const char* key, unsigned long long def = 0) const;
	const char* GetString(const char* key, const char* def = "") const;
	// Player slot of a "userid"/"attacker"/... key (-1 when the key holds no valid player).
	int GetPlayerSlot(const char* key) const;

	void SetBool(const char* key, bool value) const;
	void SetFloat(const char* key, float value) const;
	void SetInt(const char* key, int value) const;
	void SetUInt64(const char* key, unsigned long long value) const;
	void SetString(const char* key, const char* value) const;
	void SetPlayerSlot(const char* key, int slot) const;

private:
	// GetString() hands out a pointer into this cache (map nodes are stable across insertions).
	mutable std::map<std::string, std::string> strings_;
	void* event_ = nullptr;
};

using EventHandle = IGameEvent;

// Pisex's EventCallback: szName, the event, and whether it is broadcast to clients.
using EventCallback = std::function<void(const char* szName, IGameEvent* pEvent, bool bDontBroadcast)>;

// Registers a pre hook for the event (multiple callbacks per event are fine).
void HookEvent(const char* name, const EventCallback& callback);
void UnhookEvent(const char* name);
// Drops every hook (Shutdown()).
void RemoveAllEvents();

} // namespace pisex
