#include <pisex/schema.hpp>

#include <stdexcept>

#include <pisex/compat.hpp>
#include <pisex/output.hpp>
#include <pisex/players.hpp>

#include <plg/string.hpp>
#include <s2sdk/s2sdk.hpp>

#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>

namespace pisex {
namespace {

std::unordered_map<std::string, int> g_offsetCache;
std::string g_stringCache; // GetEntString() return value, refreshed per call

const char* Safe(const char* text) {
	return text ? text : "";
}

bool ValidEntity(int entity) {
	// Every s2sdk entity export dereferences g_pGameEntitySystem without a null check
	// (ref/s2sdk-src/src/core/sdk/helpers.hpp, src/export/entities.cpp) - it is only assigned in
	// s2sdk's ServerStartup, so an entity query before the first map (or on a server that never
	// started one) is a null dereference, i.e. a dead server. s2sdk's own timer/listener paths
	// never guard this; pisexcompat refuses the call until the first Poll() with a map instead.
	// No entities exist before that point, so every wrapper returns its default.
	return IsGameReady() && entity > 0 && entity < 1 << 15;
}

// s2sdk takes and returns CEntityHandle ints (entry index | serial << 15), NOT entity indices.
// The pisex API keeps Pisex's "int = entity index" convention, so every s2sdk call converts.
// Throws when the entity does not exist: callers' try/catch turn that into the default value
// (and s2sdk never logs "invalid entity handle" for it).
int32_t HandleOf(int iEntity) {
	if (!ValidEntity(iEntity) || !__s2sdk_EntIndexToEntHandle) {
		throw std::runtime_error("pisexcompat: invalid entity index");
	}
	const int32_t handle = s2sdk::EntIndexToEntHandle(iEntity);
	if (handle == -1) {
		throw std::runtime_error("pisexcompat: entity index has no live entity");
	}
	return handle;
}

int IndexOf(int32_t iHandle) {
	if (iHandle == -1 || iHandle == 0 || !__s2sdk_EntHandleToEntIndex) {
		return 0;
	}
	const int index = s2sdk::EntHandleToEntIndex(iHandle);
	return index > 0 ? index : 0;
}

// Builds the cache key in a reused buffer: a by-value key allocated on every lookup (cache hits
// included - "CCSPlayerPawn" + "m_hController" is past the SSO limit), and the typed schema helpers
// are called from per-event and per-slot code. Valid until the next call on the same thread.
const std::string& CacheKey(std::string_view cls, std::string_view field) {
	thread_local std::string key;
	key.clear();
	key.append(cls);
	key.push_back('\0');
	key.append(field);
	return key;
}

// Schema field that links a CCSPlayerPawn back to its controller.
constexpr const char* kPawnClass = "CCSPlayerPawn";

} // namespace

int SchemaOffset(const char* className, const char* fieldName) {
	if (!className || !fieldName || !*className || !*fieldName) {
		return -1;
	}
	const std::string& key = CacheKey(className, fieldName);
	const auto cached = g_offsetCache.find(key);
	if (cached != g_offsetCache.end()) {
		return cached->second;
	}
	int offset = -1;
	if (__s2sdk_GetSchemaOffset) {
		try {
			offset = s2sdk::GetSchemaOffset(plg::string(className), plg::string(fieldName));
		} catch (...) {
			offset = -1;
		}
	}
	if (offset >= 0) {
		// Only successful lookups are cached: before the schema system is initialised (no map yet)
		// every lookup fails, and a cached -1 would poison the field for the rest of the session.
		g_offsetCache.emplace(key, offset);
	}
	return offset;
}

int SchemaChainOffset(const char* className) {
	// s2sdk's SafeNetworkStateChanged() reads a chain offset >= 0 as "the object's
	// __m_pChainEntity sits at object + offset": answering 0 for "no chainer" (or for a missing
	// binding) would make it treat the object's vtable as a chainer. -1 is the "the object itself
	// is the entity" sentinel, so an absent or non-positive offset is normalised to -1.
	if (!className || !__s2sdk_GetSchemaChainOffset) {
		return -1;
	}
	try {
		const int offset = s2sdk::GetSchemaChainOffset(plg::string(className));
		return offset > 0 ? offset : -1;
	} catch (...) {
		return -1;
	}
}

bool IsSchemaFieldNetworked(const char* className, const char* fieldName) {
	if (!className || !fieldName || !__s2sdk_IsSchemaFieldNetworked) {
		return false;
	}
	try {
		return s2sdk::IsSchemaFieldNetworked(plg::string(className), plg::string(fieldName));
	} catch (...) {
		return false;
	}
}

bool IsValidEntity(int iEntity) {
	if (!ValidEntity(iEntity) || !__s2sdk_EntIndexToEntPointer) {
		return false;
	}
	try {
		return s2sdk::EntIndexToEntPointer(iEntity) != nullptr;
	} catch (...) {
		return false;
	}
}

void* EntIndexToEntPointer(int iEntity) {
	if (!ValidEntity(iEntity) || !__s2sdk_EntIndexToEntPointer) {
		return nullptr;
	}
	try {
		return s2sdk::EntIndexToEntPointer(iEntity);
	} catch (...) {
		return nullptr;
	}
}

int EntPointerToEntIndex(void* pointer) {
	if (!pointer || !__s2sdk_EntPointerToEntIndex) {
		return 0;
	}
	try {
		return s2sdk::EntPointerToEntIndex(pointer);
	} catch (...) {
		return 0;
	}
}

int EntIndexToEntHandle(int iEntity) {
	if (!ValidEntity(iEntity) || !__s2sdk_EntIndexToEntHandle) {
		return -1;
	}
	try {
		return s2sdk::EntIndexToEntHandle(iEntity);
	} catch (...) {
		return -1;
	}
}

int EntHandleToEntIndex(int iHandle) {
	// A handle is index | serial << 15 in 32 bits: once the game's serial counter passes 65535 a
	// valid handle is a negative int. Only INVALID_EHANDLE_INDEX (-1) is invalid; 0 (the world) is
	// never an entity a plugin asks about and keeps meaning "none".
	if (iHandle == -1 || iHandle == 0 || !__s2sdk_EntHandleToEntIndex) {
		return 0;
	}
	try {
		return s2sdk::EntHandleToEntIndex(iHandle);
	} catch (...) {
		return 0;
	}
}

std::string GetEntityClassname(int iEntity) {
	if (!ValidEntity(iEntity) || !__s2sdk_GetEntityClassname) {
		return {};
	}
	try {
		const plg::string name = s2sdk::GetEntityClassname(HandleOf(iEntity));
		return std::string(name.data(), name.size());
	} catch (...) {
		return {};
	}
}

int GetEntInt(int iEntity, const char* className, const char* fieldName, int iDefault, int iElement) {
	if (!ValidEntity(iEntity) || !__s2sdk_GetEntSchema) {
		return iDefault;
	}
	try {
		return static_cast<int>(s2sdk::GetEntSchema(HandleOf(iEntity), plg::string(Safe(className)), plg::string(Safe(fieldName)),
													iElement));
	} catch (...) {
		return iDefault;
	}
}

float GetEntFloat(int iEntity, const char* className, const char* fieldName, float flDefault, int iElement) {
	if (!ValidEntity(iEntity) || !__s2sdk_GetEntSchemaFloat) {
		return flDefault;
	}
	try {
		return static_cast<float>(s2sdk::GetEntSchemaFloat(HandleOf(iEntity), plg::string(Safe(className)),
														   plg::string(Safe(fieldName)), iElement));
	} catch (...) {
		return flDefault;
	}
}

bool GetEntBool(int iEntity, const char* className, const char* fieldName, bool bDefault, int iElement) {
	if (!ValidEntity(iEntity) || !__s2sdk_GetEntSchema) {
		return bDefault;
	}
	try {
		return s2sdk::GetEntSchema(HandleOf(iEntity), plg::string(Safe(className)), plg::string(Safe(fieldName)), iElement) != 0;
	} catch (...) {
		return bDefault;
	}
}

const char* GetEntString(int iEntity, const char* className, const char* fieldName, const char* szDefault,
						 int iElement) {
	if (!ValidEntity(iEntity) || !__s2sdk_GetEntSchemaString) {
		return szDefault;
	}
	try {
		const plg::string value = s2sdk::GetEntSchemaString(HandleOf(iEntity), plg::string(Safe(className)),
															plg::string(Safe(fieldName)), iElement);
		g_stringCache.assign(value.data(), value.size());
		return g_stringCache.c_str();
	} catch (...) {
		return szDefault;
	}
}

plg::vec3 GetEntVector(int iEntity, const char* className, const char* fieldName, int iElement) {
	if (!ValidEntity(iEntity) || !__s2sdk_GetEntSchemaVector3D) {
		return {};
	}
	try {
		return s2sdk::GetEntSchemaVector3D(HandleOf(iEntity), plg::string(Safe(className)), plg::string(Safe(fieldName)),
										   iElement);
	} catch (...) {
		return {};
	}
}

plg::vec4 GetEntColor(int iEntity, const char* className, const char* fieldName, int iElement) {
	if (!ValidEntity(iEntity) || !__s2sdk_GetEntSchemaColor) {
		return {};
	}
	try {
		return s2sdk::GetEntSchemaColor(HandleOf(iEntity), plg::string(Safe(className)), plg::string(Safe(fieldName)), iElement);
	} catch (...) {
		return {};
	}
}

int GetEntEntity(int iEntity, const char* className, const char* fieldName, int iElement) {
	if (!ValidEntity(iEntity) || !__s2sdk_GetEntSchemaEnt) {
		return 0;
	}
	try {
		return IndexOf(s2sdk::GetEntSchemaEnt(HandleOf(iEntity), plg::string(Safe(className)), plg::string(Safe(fieldName)), iElement));
	} catch (...) {
		return 0;
	}
}

void SetEntInt(int iEntity, const char* className, const char* fieldName, int value, bool bChangeState, int iElement) {
	if (!ValidEntity(iEntity) || !__s2sdk_SetEntSchema) {
		return;
	}
	try {
		s2sdk::SetEntSchema(HandleOf(iEntity), plg::string(Safe(className)), plg::string(Safe(fieldName)), value, bChangeState,
							iElement);
	} catch (...) {
	}
}

void SetEntFloat(int iEntity, const char* className, const char* fieldName, float value, bool bChangeState,
				 int iElement) {
	if (!ValidEntity(iEntity) || !__s2sdk_SetEntSchemaFloat) {
		return;
	}
	try {
		s2sdk::SetEntSchemaFloat(HandleOf(iEntity), plg::string(Safe(className)), plg::string(Safe(fieldName)), value,
								 bChangeState, iElement);
	} catch (...) {
	}
}

void SetEntBool(int iEntity, const char* className, const char* fieldName, bool value, bool bChangeState, int iElement) {
	SetEntInt(iEntity, className, fieldName, value ? 1 : 0, bChangeState, iElement);
}

void SetEntString(int iEntity, const char* className, const char* fieldName, const char* value, bool bChangeState,
				  int iElement) {
	if (!ValidEntity(iEntity) || !__s2sdk_SetEntSchemaString) {
		return;
	}
	try {
		s2sdk::SetEntSchemaString(HandleOf(iEntity), plg::string(Safe(className)), plg::string(Safe(fieldName)),
								  plg::string(Safe(value)), bChangeState, iElement);
	} catch (...) {
	}
}

void SetEntVector(int iEntity, const char* className, const char* fieldName, const plg::vec3& value,
				  bool bChangeState, int iElement) {
	if (!ValidEntity(iEntity) || !__s2sdk_SetEntSchemaVector3D) {
		return;
	}
	try {
		s2sdk::SetEntSchemaVector3D(HandleOf(iEntity), plg::string(Safe(className)), plg::string(Safe(fieldName)), value,
									bChangeState, iElement);
	} catch (...) {
	}
}

void SetEntColor(int iEntity, const char* className, const char* fieldName, const plg::vec4& value,
				 bool bChangeState, int iElement) {
	if (!ValidEntity(iEntity) || !__s2sdk_SetEntSchemaColor) {
		return;
	}
	try {
		s2sdk::SetEntSchemaColor(HandleOf(iEntity), plg::string(Safe(className)), plg::string(Safe(fieldName)), value,
								 bChangeState, iElement);
	} catch (...) {
	}
}

void SetEntEntity(int iEntity, const char* className, const char* fieldName, int iValue, bool bChangeState,
				  int iElement) {
	if (!ValidEntity(iEntity) || !__s2sdk_SetEntSchemaEnt) {
		return;
	}
	try {
		s2sdk::SetEntSchemaEnt(HandleOf(iEntity), plg::string(Safe(className)), plg::string(Safe(fieldName)), iValue > 0 ? HandleOf(iValue) : -1,
							   bChangeState, iElement);
	} catch (...) {
	}
}

void SetStateChanged(int iEntity, const char* className, const char* fieldName) {
	if (!ValidEntity(iEntity) || !__s2sdk_NetworkStateChanged) {
		return;
	}
	try {
		s2sdk::NetworkStateChanged(HandleOf(iEntity), plg::string(Safe(className)), plg::string(Safe(fieldName)));
	} catch (...) {
	}
}

int FindEntityByClassname(int iStart, const char* className) {
	// IsGameReady() is required, not just for the entity system pointer: the export dereferences it
	// before it even looks at the arguments. EntIndexToEntHandle is called for the start index, so
	// its binding is required as well.
	if (!IsGameReady() || !className || !*className || !__s2sdk_FindEntityByClassname ||
		(iStart > 0 && !__s2sdk_EntIndexToEntHandle)) {
		return 0;
	}
	try {
		const int32_t start = iStart > 0 ? s2sdk::EntIndexToEntHandle(iStart) : -1;
		return IndexOf(s2sdk::FindEntityByClassname(start, plg::string(className)));
	} catch (...) {
		return 0;
	}
}

int GetPlayerPawn(int iSlot) {
	// GetClientPawn logs "invalid player slot" (helpers::GetController) for an empty slot; the
	// client guard keeps loops over all 64 slots silent and matches s2sdk's own result (0).
	if (!IsClientReady(iSlot) || !__s2sdk_GetClientPawn) {
		return 0;
	}
	try {
		void* pawn = s2sdk::GetClientPawn(iSlot);
		return pawn ? EntPointerToEntIndex(pawn) : 0;
	} catch (...) {
		return 0;
	}
}

int GetPlayerController(int iSlot) {
	if (!IsGameReady() || iSlot < 0 || iSlot >= GetMaxPlayers() || !__s2sdk_PlayerSlotToEntPointer) {
		return 0;
	}
	try {
		void* controller = s2sdk::PlayerSlotToEntPointer(iSlot);
		return controller ? EntPointerToEntIndex(controller) : 0;
	} catch (...) {
		return 0;
	}
}

int GetPawnController(int iPawn) {
	const int controller = GetEntEntity(iPawn, kPawnClass, "m_hController");
	if (controller != 0) {
		return controller;
	}
	// Some maps/versions keep the link only as a raw entity component; the schema name is stable
	// across the CS2 builds we target, so an empty result simply means "no controller".
	return 0;
}

} // namespace pisex
