#include <pisex/keyvalues.hpp>

#include <pisex/paths.hpp>

#include <charconv>
#include <cctype>
#include <cstdlib>
#include <string>
#include <utility>

namespace pisex {
namespace {

char Lower(char c) {
	return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
}

bool EqualNoCase(std::string_view a, std::string_view b) {
	if (a.size() != b.size()) {
		return false;
	}
	for (std::size_t i = 0; i < a.size(); ++i) {
		if (Lower(a[i]) != Lower(b[i])) {
			return false;
		}
	}
	return true;
}

std::string_view Trim(std::string_view text) {
	std::size_t begin = 0;
	std::size_t end = text.size();
	while (begin < end && std::isspace(static_cast<unsigned char>(text[begin]))) {
		++begin;
	}
	while (end > begin && std::isspace(static_cast<unsigned char>(text[end - 1]))) {
		--end;
	}
	return text.substr(begin, end - begin);
}

// --- tokenizer -------------------------------------------------------------------------------
//
// Grammar (the KV1 subset the Pisex files use):
//
//   file    := node* EOF
//   node    := token [ value ] [ '{' node* '}' ]
//   value   := token
//   token   := '"' escaped '"' | raw
//
class Parser {
public:
	explicit Parser(std::string_view text) : text_(text) {}

	bool Parse(KeyValues& root) {
		ok_ = true;
		ParseNodes(root, false);
		return ok_ && !failed_;
	}

private:
	void SkipSpace() {
		while (pos_ < text_.size()) {
			const char c = text_[pos_];
			if (std::isspace(static_cast<unsigned char>(c))) {
				++pos_;
				continue;
			}
			if (c == '/' && pos_ + 1 < text_.size() && text_[pos_ + 1] == '/') {
				pos_ += 2;
				while (pos_ < text_.size() && text_[pos_] != '\n') {
					++pos_;
				}
				continue;
			}
			if (c == '/' && pos_ + 1 < text_.size() && text_[pos_ + 1] == '*') {
				pos_ += 2;
				while (pos_ + 1 < text_.size() && !(text_[pos_] == '*' && text_[pos_ + 1] == '/')) {
					++pos_;
				}
				pos_ = (pos_ + 1 < text_.size()) ? pos_ + 2 : text_.size();
				continue;
			}
			break;
		}
	}

	// Reads one token. Returns false at end of input (out stays untouched).
	bool ReadToken(std::string& out) {
		SkipSpace();
		if (pos_ >= text_.size() || text_[pos_] == '}') {
			return false;
		}
		out.clear();
		if (text_[pos_] == '"') {
			++pos_;
			while (pos_ < text_.size()) {
				const char c = text_[pos_++];
				if (c == '\\' && pos_ < text_.size()) {
					const char esc = text_[pos_++];
					switch (esc) {
					case 'n': out.push_back('\n'); break;
					case 'r': out.push_back('\r'); break;
					case 't': out.push_back('\t'); break;
					case '"': out.push_back('"'); break;
					case '\\': out.push_back('\\'); break;
					default:
						out.push_back('\\');
						out.push_back(esc);
						break;
					}
					continue;
				}
				if (c == '"') {
					return true;
				}
				out.push_back(c);
			}
			// Unterminated string: keep what we have, the caller decides.
			failed_ = true;
			return true;
		}
		while (pos_ < text_.size()) {
			const char c = text_[pos_];
			if (std::isspace(static_cast<unsigned char>(c)) || c == '{' || c == '}' || c == '"') {
				break;
			}
			if (c == '/' && pos_ + 1 < text_.size() && (text_[pos_ + 1] == '/' || text_[pos_ + 1] == '*')) {
				break;
			}
			out.push_back(c);
			++pos_;
		}
		return true;
	}

	bool PeekIs(char c) {
		SkipSpace();
		return pos_ < text_.size() && text_[pos_] == c;
	}

	void ParseNodes(KeyValues& parent, bool insideBlock) {
		while (true) {
			SkipSpace();
			if (pos_ >= text_.size()) {
				if (insideBlock) {
					// Missing '}' — accept, Valve is equally forgiving with truncated configs.
					failed_ = true;
				}
				return;
			}
			if (text_[pos_] == '}') {
				if (!insideBlock) {
					failed_ = true;
				}
				++pos_;
				return;
			}

			std::string key;
			if (!ReadToken(key)) {
				return;
			}

			// #base / #include / #define: no file inclusion, just skip the line.
			if (!key.empty() && key[0] == '#') {
				while (pos_ < text_.size() && text_[pos_] != '\n') {
					++pos_;
				}
				continue;
			}

			KeyValues* node = parent.AddSubKey(key);

			// An optional value, then an optional block (KV1 allows both on one key).
			if (!PeekIs('{')) {
				std::string value;
				if (ReadToken(value)) {
					node->SetString({}, value);
				}
			}
			if (PeekIs('{')) {
				++pos_;
				ParseNodes(*node, true);
			}
		}
	}

	std::string_view text_;
	std::size_t pos_ = 0;
	bool ok_ = true;
	bool failed_ = false;
};

} // namespace

// --- KeyValues -------------------------------------------------------------------------------

KeyValues::KeyValues(std::string_view name) : name_(name) {}

KeyValues::~KeyValues() = default;

bool KeyValues::LoadFromFile(std::string_view path) {
	Clear();
	const std::string resolved = ResolvePath(path);
	bool ok = false;
	const std::string content = ReadFile(resolved, &ok);
	if (!ok) {
		return false;
	}
	return LoadFromBuffer(content);
}

bool KeyValues::LoadFromBuffer(std::string_view text) {
	Clear();
	Parser parser(text);
	if (!parser.Parse(*this)) {
		// A malformed file must not leave a half-parsed tree behind: the Pisex loaders check the
		// return value and use defaults, and a partial tree would silently override them.
		Clear();
		return false;
	}

	// KV1 files are "RootName" { ... }: Valve's loader merges that single top-level block into the
	// object it parses into, which is why `KeyValues kv("Config"); kv.LoadFromFile(...);
	// kv.GetString("key")` reads a key *inside* the block. Same here (the root name is kept, it is
	// only used for logging/diagnostics).
	if (children_.size() == 1 && children_.front()->HasChildren()) {
		std::unique_ptr<KeyValues> top = std::move(children_.front());
		children_.clear();
		name_ = top->name_;
		if (top->hasValue_) {
			value_ = top->value_;
			hasValue_ = true;
		}
		children_ = std::move(top->children_);
		for (auto& child : children_) {
			child->parent_ = this;
		}
	}
	return true;
}

bool KeyValues::IsEmpty(std::string_view key) const {
	const KeyValues* found = key.empty() ? this : FindKey(std::string(key).c_str());
	if (!found) {
		return true;
	}
	return !found->HasValue() || found->value_.empty();
}

KeyValues* KeyValues::FindKey(const char* key, bool bCreate) {
	if (!key || !*key) {
		return nullptr;
	}
	for (auto& child : children_) {
		if (EqualNoCase(child->name_, key)) {
			return child.get();
		}
	}
	if (bCreate) {
		return AddSubKey(key);
	}
	return nullptr;
}

const KeyValues* KeyValues::FindKey(const char* key) const {
	return const_cast<KeyValues*>(this)->FindKey(key, false);
}

KeyValues* KeyValues::FindKeyWithValue(const char* key) {
	KeyValues* found = FindKey(key, false);
	return (found && found->HasValue()) ? found : nullptr;
}

std::string_view KeyValues::GetStringValue(const char* key, std::string_view def) const {
	if (!key || !*key) {
		return hasValue_ ? std::string_view(value_) : def;
	}
	const KeyValues* found = FindKey(key);
	if (!found || !found->HasValue()) {
		return def;
	}
	return std::string_view(found->value_);
}

const char* KeyValues::GetString(const char* key, const char* def) const {
	if (!key || !*key) {
		return hasValue_ ? value_.c_str() : def;
	}
	const KeyValues* found = FindKey(key);
	if (!found || !found->HasValue()) {
		return def;
	}
	return found->value_.c_str();
}

int KeyValues::GetInt(const char* key, int def) const {
	const std::string_view text = Trim(GetStringValue(key, {}));
	if (text.empty()) {
		return def;
	}
	int value = 0;
	const auto* begin = text.data();
	const auto* end = text.data() + text.size();
	const auto result = std::from_chars(begin, end, value);
	if (result.ec != std::errc{}) {
		// Valve falls back to atoi semantics ("5 // comment", "1.5", "abc" -> 0/partial).
		return std::atoi(std::string(text).c_str());
	}
	return value;
}

float KeyValues::GetFloat(const char* key, float def) const {
	const std::string_view text = Trim(GetStringValue(key, {}));
	if (text.empty()) {
		return def;
	}
	const std::string copy(text);
	char* end = nullptr;
	const float value = std::strtof(copy.c_str(), &end);
	if (end == copy.c_str()) {
		return def;
	}
	return value;
}

bool KeyValues::GetBool(const char* key, bool def) const {
	const std::string_view text = Trim(GetStringValue(key, {}));
	if (text.empty()) {
		return def;
	}
	if (EqualNoCase(text, "true") || EqualNoCase(text, "yes") || EqualNoCase(text, "on")) {
		return true;
	}
	if (EqualNoCase(text, "false") || EqualNoCase(text, "no") || EqualNoCase(text, "off")) {
		return false;
	}
	return GetInt(key, def ? 1 : 0) != 0;
}

void KeyValues::SetString(std::string_view key, std::string_view value) {
	if (key.empty()) {
		value_.assign(value);
		hasValue_ = true;
		return;
	}
	AddSubKey(key)->SetString({}, value);
}

void KeyValues::SetInt(std::string_view key, int value) {
	SetString(key, std::to_string(value));
}

KeyValues* KeyValues::AddSubKey(std::string_view name) {
	auto child = std::make_unique<KeyValues>(name);
	child->parent_ = this;
	children_.push_back(std::move(child));
	return children_.back().get();
}

KeyValues* KeyValues::GetSubKey(std::size_t index) {
	return index < children_.size() ? children_[index].get() : nullptr;
}

const KeyValues* KeyValues::GetSubKey(std::size_t index) const {
	return index < children_.size() ? children_[index].get() : nullptr;
}

bool KeyValues::IsValueNode() const {
	return hasValue_;
}

bool KeyValues::IsBlockNode() const {
	return !children_.empty();
}

KeyValues* KeyValues::GetFirstSubKey() {
	return children_.empty() ? nullptr : children_.front().get();
}

const KeyValues* KeyValues::GetFirstSubKey() const {
	return children_.empty() ? nullptr : children_.front().get();
}

KeyValues* KeyValues::GetNextKey() {
	if (!parent_) {
		return nullptr;
	}
	bool found = false;
	for (auto& sibling : parent_->children_) {
		if (found) {
			return sibling.get();
		}
		if (sibling.get() == this) {
			found = true;
		}
	}
	return nullptr;
}

const KeyValues* KeyValues::GetNextKey() const {
	return const_cast<KeyValues*>(this)->GetNextKey();
}

KeyValues* KeyValues::GetFirstTrueSubKey() {
	for (auto& child : children_) {
		if (child->IsBlockNode()) {
			return child.get();
		}
	}
	return nullptr;
}

const KeyValues* KeyValues::GetFirstTrueSubKey() const {
	return const_cast<KeyValues*>(this)->GetFirstTrueSubKey();
}

KeyValues* KeyValues::GetNextTrueSubKey() {
	if (!parent_) {
		return nullptr;
	}
	bool found = false;
	for (auto& sibling : parent_->children_) {
		if (found && sibling->IsBlockNode()) {
			return sibling.get();
		}
		if (sibling.get() == this) {
			found = true;
		}
	}
	return nullptr;
}

const KeyValues* KeyValues::GetNextTrueSubKey() const {
	return const_cast<KeyValues*>(this)->GetNextTrueSubKey();
}

KeyValues* KeyValues::GetFirstValue() {
	for (auto& child : children_) {
		if (child->IsValueNode()) {
			return child.get();
		}
	}
	return nullptr;
}

const KeyValues* KeyValues::GetFirstValue() const {
	return const_cast<KeyValues*>(this)->GetFirstValue();
}

KeyValues* KeyValues::GetNextValue() {
	if (!parent_) {
		return nullptr;
	}
	bool found = false;
	for (auto& sibling : parent_->children_) {
		if (found && sibling->IsValueNode()) {
			return sibling.get();
		}
		if (sibling.get() == this) {
			found = true;
		}
	}
	return nullptr;
}

const KeyValues* KeyValues::GetNextValue() const {
	return const_cast<KeyValues*>(this)->GetNextValue();
}

std::vector<KeyValues*> KeyValues::GetSubKeyList() {
	std::vector<KeyValues*> out;
	out.reserve(children_.size());
	for (auto& child : children_) {
		out.push_back(child.get());
	}
	return out;
}

void KeyValues::Clear() {
	children_.clear();
	value_.clear();
	hasValue_ = false;
}

} // namespace pisex
