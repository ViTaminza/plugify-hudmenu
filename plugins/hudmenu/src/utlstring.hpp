// CUtlString marshalling for the CCSCustomHudLayout natives.
//
// The natives take their strings as `const CUtlString&`. CS2's CUtlString, read from the
// exported libtier0.so functions (CUtlString::Set/SetDirect/Purge/SetLength/IsEqual_* all
// load a single `char*` from offset 0 and the string data block comes from the game's global
// IMemAlloc), is exactly:
//
//     class CUtlString { char* m_pString; };   // 8 bytes, nullptr == empty string
//
// Instead of reimplementing its allocator (which would risk freeing game memory with our
// allocator - or leaking), this builds CUtlStrings with the game's own exported functions:
//
//     libtier0.so!CUtlString::Set(const char*)   _ZN10CUtlString3SetEPKc
//     libtier0.so!CUtlString::Purge()            _ZN10CUtlString5PurgeEv
//
// libtier0.so is a NEEDED dependency of libengine2.so (SONAME "libtier0.so"), i.e. it is
// already loaded in the server process, so dlopen(RTLD_NOLOAD) finds it. Set() allocates the
// data block with the game's allocator and frees the previous one; Purge() frees. The pair is
// allocator-consistent by construction, so a string is created before a native call and
// purged right after it: exactly what SwiftlyS2 (C#) does when it marshals a managed string
// into these same natives, which is also the evidence that the natives consume the string
// during the call (copy/tokenize) and do not retain our pointer.
//
// If the functions cannot be resolved, the plugin fails soft: it logs once and does not
// register the "hud" menu type, so pisexcompat falls back to the "button" type.
#pragma once

#include <dlfcn.h>

#include <cstring>

#include <string>

namespace hudmenu {

// ABI-compatible with CS2's CUtlString (a single char*; see the header comment).
struct UtlString {
	const char* p = nullptr;
};

class UtlStringApi {
public:
	bool Resolve() {
		void* tier0 = dlopen("libtier0.so", RTLD_NOW | RTLD_NOLOAD);
		m_set = reinterpret_cast<SetFn>(Lookup(tier0, "_ZN10CUtlString3SetEPKc"));
		m_purge = reinterpret_cast<PurgeFn>(Lookup(tier0, "_ZN10CUtlString5PurgeEv"));
		if (tier0 != nullptr) {
			dlclose(tier0); // RTLD_NOLOAD: just releasing our reference to the existing lib
		}
		return Available();
	}

	[[nodiscard]] bool Available() const { return m_set != nullptr && m_purge != nullptr; }

	// Makes `out` hold a game-allocated copy of `value` (null/empty => CUtlString holding
	// nullptr, which the game treats as an empty string; no allocation happens then).
	// Only ever called on strings this class created (they own game-allocated blocks).
	void Assign(UtlString& out, const char* value) const {
		Free(out); // Set() would free the previous block itself, but keep the contract simple
		if (value == nullptr || *value == '\0') {
			return;
		}
		m_set(&out, value);
	}

	// Frees a string produced by Assign (idempotent).
	void Free(UtlString& string) const {
		if (string.p != nullptr) {
			m_purge(&string);
		}
	}

private:
	using SetFn = void (*)(UtlString*, const char*);
	using PurgeFn = void (*)(UtlString*);

	static void* Lookup(void* module, const char* symbol) {
		void* address = nullptr;
		if (module != nullptr) {
			address = dlsym(module, symbol);
		}
		if (address == nullptr) {
			address = dlsym(RTLD_DEFAULT, symbol);
		}
		return address;
	}

	SetFn m_set = nullptr;
	PurgeFn m_purge = nullptr;
};

// Owns up to kCapacity CUtlStrings for the duration of one native call.
class UtlStringPack {
public:
	explicit UtlStringPack(const UtlStringApi& api) : m_api(api) {}
	~UtlStringPack() { Clear(); }

	UtlStringPack(const UtlStringPack&) = delete;
	UtlStringPack& operator=(const UtlStringPack&) = delete;

	const UtlString* Add(const char* value) {
		UtlString& slot = m_items[m_count < kCapacity ? m_count++ : kCapacity - 1];
		m_api.Assign(slot, value);
		return &slot;
	}

	void Clear() {
		for (std::size_t i = 0; i < m_count; ++i) {
			m_api.Free(m_items[i]);
		}
		m_count = 0;
	}

private:
	static constexpr std::size_t kCapacity = 4;

	const UtlStringApi& m_api;
	UtlString m_items[kCapacity]{};
	std::size_t m_count = 0;
};

} // namespace hudmenu
