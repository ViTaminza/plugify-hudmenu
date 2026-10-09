// pisexcompat — entity / schema access helpers.
//
// The Pisex modules reach into hl2sdk typed entities (pPawn->m_iHealth(), pController->m_iTeamNum(),
// ...). Plugify has no schema headers, so those accessors become "class + field" string lookups
// through s2sdk's schema functions. These wrappers add the two things the string API lacks:
//   * one cached offset lookup per class+field pair (the lookups are not cheap),
//   * a null-safe, exception-safe call that returns a default when the field does not exist.
//
// Porting note: schema *getters* are cheap; setters that must reach the client need
// changeState=true (s2sdk then sends the network update), which is the equivalent of Pisex's
// SetStateChanged().
//
// MAP-START WARNING (tools/mdump/REPORT.txt, "Signature D"): a crash dump shows a typed call, one
// frame after a map load, receiving a schema field entry whose CSchemaType* is the sentinel -1,
// which s2sdk then dereferences; the *offset* of that entry was fine. Where the -1 originates
// inside s2sdk is not visible in the dump (REPORT.txt says so). Keep schema access (this header, and s2sdk's GetEntSchema*/
// SetEntSchema* directly) off the map-start path: do it from a player/round event, or resolve the
// offset with SchemaOffset() and use s2sdk's raw GetEntData2/SetEntData2 (with the field's real
// width) as plugins/fortnite_emotes does.
//
// Entity ints in this API are ENTITY INDICES (Pisex convention, 0 = none). s2sdk itself works with
// CEntityHandle ints (index | serial << 15); every function here converts internally. Use pisex::EntIndexToEntPointer() /
// pisex::EntPointerToEntIndex() when an API wants the other form.

#pragma once

#include <cstdint>
#include <string>

#include <plg/numerics.hpp>

namespace pisex {

// Cached schema offset of <className>::<fieldName> (-1 when the class or field is unknown).
int SchemaOffset(const char* className, const char* fieldName);
// Chain offset (for fields inside a network var chain): -1 when the class is not chained (or the
// binding is missing) - never 0, which s2sdk's SafeNetworkStateChanged() would read as a real
// offset and dereference the object's vtable as a chainer.
int SchemaChainOffset(const char* className);
bool IsSchemaFieldNetworked(const char* className, const char* fieldName);

// --- entity handles --------------------------------------------------------------------------
bool IsValidEntity(int iEntity);
void* EntIndexToEntPointer(int iEntity);
int EntPointerToEntIndex(void* pointer);
int EntIndexToEntHandle(int iEntity);
int EntHandleToEntIndex(int iHandle);
std::string GetEntityClassname(int iEntity);

// --- typed schema access ---------------------------------------------------------------------
int GetEntInt(int iEntity, const char* className, const char* fieldName, int iDefault = 0, int iElement = 0);
float GetEntFloat(int iEntity, const char* className, const char* fieldName, float flDefault = 0.0f,
				  int iElement = 0);
bool GetEntBool(int iEntity, const char* className, const char* fieldName, bool bDefault = false,
				int iElement = 0);
const char* GetEntString(int iEntity, const char* className, const char* fieldName, const char* szDefault = "",
						 int iElement = 0);
plg::vec3 GetEntVector(int iEntity, const char* className, const char* fieldName, int iElement = 0);
plg::vec4 GetEntColor(int iEntity, const char* className, const char* fieldName, int iElement = 0);
// Entity (index) referenced by a handle field (m_hPawn, m_hController, ...); 0 when empty.
int GetEntEntity(int iEntity, const char* className, const char* fieldName, int iElement = 0);

// changeState=true makes s2sdk send the change to the clients (replaces Pisex's SetStateChanged).
void SetEntInt(int iEntity, const char* className, const char* fieldName, int value, bool bChangeState = true,
			   int iElement = 0);
void SetEntFloat(int iEntity, const char* className, const char* fieldName, float value, bool bChangeState = true,
				 int iElement = 0);
void SetEntBool(int iEntity, const char* className, const char* fieldName, bool value, bool bChangeState = true,
				int iElement = 0);
void SetEntString(int iEntity, const char* className, const char* fieldName, const char* value,
				  bool bChangeState = true, int iElement = 0);
void SetEntVector(int iEntity, const char* className, const char* fieldName, const plg::vec3& value,
				  bool bChangeState = true, int iElement = 0);
void SetEntColor(int iEntity, const char* className, const char* fieldName, const plg::vec4& value,
				 bool bChangeState = true, int iElement = 0);
void SetEntEntity(int iEntity, const char* className, const char* fieldName, int iValue, bool bChangeState = true,
				  int iElement = 0);

// Pisex's SetStateChanged(entity, class, field): marks the field as changed for the clients.
void SetStateChanged(int iEntity, const char* className, const char* fieldName);

// --- common entity queries the admin modules need --------------------------------------------
// First entity of that class (0 when there is none). iStart is the previous result, so the Pisex
// "UTIL_FindEntityByClassname(pStart, name)" loop translates directly (pass -1/0 to start).
int FindEntityByClassname(int iStart, const char* className);
// Entity handle (then index) of the player's pawn / controller, 0 when there is none.
int GetPlayerPawn(int iSlot);
int GetPlayerController(int iSlot);
// Controller that owns a pawn (m_hController), 0 when unknown.
int GetPawnController(int iPawn);

} // namespace pisex
