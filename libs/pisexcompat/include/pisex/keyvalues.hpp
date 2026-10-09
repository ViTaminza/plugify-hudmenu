// pisexcompat — Valve KeyValues (KV1) text parser.
//
// The Pisex plugins read their .ini / .cfg / .phrases.txt files with hl2sdk's KeyValues
// (LoadFromFile -> FindKey -> GetString/GetInt/... and FOR_EACH_SUBKEY/FOR_EACH_VALUE loops).
// This is the same thing without the engine: a small, dependency-free KV1 reader whose API covers
// the subset that Pisex actually uses (see README.md), so porting a config loader is a matter of
// replacing `new KeyValues("X")`/`kv->LoadFromFile(g_pFullFileSystem, path)` with
// `pisex::KeyValues` / `kv.LoadFromFile(path)`.
//
// Supported syntax (everything the live Pisex configs contain):
//   * quoted ("key" "value") and unquoted (key value) tokens,
//   * nested blocks: "key" { ... },
//   * // line comments (and /* */ block comments), trailing comments after a value,
//   * escape sequences inside quoted strings: \" \\ \n \r \t,
//   * the #base/#include/#define directives are parsed and dropped (no file inclusion),
//   * a key may carry both a value and a block, like Valve's KV1.
//
// Deliberate differences from hl2sdk's KeyValues:
//   * memory is owned by std::unique_ptr (no refcount, no leak on early return),
//   * no .kv3/.kv binary formats, no #include expansion, no localized tokens (the $ prefix),
//   * FindKey is case-insensitive (like Valve's), GetName keeps the original spelling.

#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace pisex {

class KeyValues {
public:
	// RAII wrapper so `KeyValues::AutoDelete kv("Phrases"); kv->LoadFromFile(...)` (the Pisex
	// spelling) keeps compiling.
	class AutoDelete {
	public:
		explicit AutoDelete(std::string_view name) : ptr_(std::make_unique<KeyValues>(name)) {}
		AutoDelete(const AutoDelete&) = delete;
		AutoDelete& operator=(const AutoDelete&) = delete;

		KeyValues* operator->() const { return ptr_.get(); }
		KeyValues& operator*() const { return *ptr_; }
		KeyValues* get() const { return ptr_.get(); }

	private:
		std::unique_ptr<KeyValues> ptr_;
	};

	explicit KeyValues(std::string_view name);
	KeyValues(const KeyValues&) = delete;
	KeyValues& operator=(const KeyValues&) = delete;
	~KeyValues();

	// --- loading -----------------------------------------------------------------------------
	// Path resolution is delegated to pisex::ResolvePath (config/translations dirs, see compat.hpp).
	// Returns false when the file is missing or malformed; the tree is then left empty.
	bool LoadFromFile(std::string_view path);
	// Same parser over an in-memory buffer (used by the unit tests).
	bool LoadFromBuffer(std::string_view text);

	// --- identity ----------------------------------------------------------------------------
	const char* GetName() const { return name_.c_str(); }
	void SetName(std::string_view name) { name_ = std::string(name); }
	bool IsEmpty(std::string_view key) const;

	// --- lookup ------------------------------------------------------------------------------
	// Returns the first child with that name (case-insensitive). bCreate adds an empty child when
	// the key is missing, exactly like Valve's KeyValues.
	KeyValues* FindKey(const char* key, bool bCreate = false);
	const KeyValues* FindKey(const char* key) const;
	// Same, but only matches children that have a value (Valve's FindKey + GetFirstValue chain).
	KeyValues* FindKeyWithValue(const char* key);

	// --- values ------------------------------------------------------------------------------
	// A null/empty key reads the node's own value. All getters return the default when the key is
	// missing or the stored text cannot be converted.
	std::string_view GetStringValue(const char* key = nullptr, std::string_view def = {}) const;
	const char* GetString(const char* key = nullptr, const char* def = "") const;
	int GetInt(const char* key = nullptr, int def = 0) const;
	float GetFloat(const char* key = nullptr, float def = 0.0f) const;
	bool GetBool(const char* key = nullptr, bool def = false) const;

	void SetString(std::string_view key, std::string_view value);
	void SetInt(std::string_view key, int value);

	// True when this node is a block (has children). Pisex's FOR_EACH_SUBKEY loops need this.
	bool HasChildren() const { return !children_.empty(); }
	bool HasValue() const { return hasValue_; }
	std::size_t GetSubKeyCount() const { return children_.size(); }

	KeyValues* AddSubKey(std::string_view name);
	// Insertion-ordered child access (used by the tests and by callers that index by position).
	KeyValues* GetSubKey(std::size_t index);
	const KeyValues* GetSubKey(std::size_t index) const;

	// --- iteration (Valve's naming; loop with the FOR_EACH_* macros below) --------------------
	KeyValues* GetFirstSubKey();
	const KeyValues* GetFirstSubKey() const;
	KeyValues* GetNextKey();
	const KeyValues* GetNextKey() const;

	KeyValues* GetFirstTrueSubKey();
	const KeyValues* GetFirstTrueSubKey() const;
	KeyValues* GetNextTrueSubKey();
	const KeyValues* GetNextTrueSubKey() const;

	KeyValues* GetFirstValue();
	const KeyValues* GetFirstValue() const;
	KeyValues* GetNextValue();
	const KeyValues* GetNextValue() const;

	std::vector<KeyValues*> GetSubKeyList();
	// Drops every child and the own value (Pisex calls KeyValues::deleteAllSubkeys on reload).
	void Clear();

private:
	// A child is a "true sub key" when it is a block, and a "value" when it carries a scalar.
	bool IsValueNode() const;
	bool IsBlockNode() const;

	std::string name_;
	std::string value_;
	bool hasValue_ = false;
	KeyValues* parent_ = nullptr;
	std::vector<std::unique_ptr<KeyValues>> children_;
};

// Pisex (hl2sdk) iteration macros, kept verbatim so ported loops compile unchanged.
#define FOR_EACH_SUBKEY(kvParent, kvName) \
	for (pisex::KeyValues* kvName = (kvParent)->GetFirstTrueSubKey(); kvName; kvName = kvName->GetNextTrueSubKey())

#define FOR_EACH_VALUE(kvParent, kvName) \
	for (pisex::KeyValues* kvName = (kvParent)->GetFirstValue(); kvName; kvName = kvName->GetNextValue())

} // namespace pisex
