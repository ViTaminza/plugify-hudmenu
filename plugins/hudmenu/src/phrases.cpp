#include "phrases.hpp"

#include <cstddef>
#include <fstream>
#include <iterator>
#include <utility>
#include <vector>

namespace hudmenu {
namespace {

// Bounds for the reader (a malformed or hostile file must not grow the table without limit).
constexpr std::size_t kMaxFileSize = 1u << 20; // 1 MiB
constexpr std::size_t kMaxEntries = 4096;
constexpr std::size_t kMaxValueLength = 8u << 10;

// The chooser phrases, copied verbatim from cs2-menus/translations/menus.phrases.txt
// (MenuMenus*), plus the confirmation line (Pisex re-opened the menu; this port replies).
// { key, ru, en }
constexpr const char* kBuiltin[][3] = {
	{"MenuMenusTitle", "Выберите тип меню", "Choose menu type"},
	{"MenuMenusItem0", "Чат меню", "Chat Menu"},
	{"MenuMenusItem1", "Чат + Центр меню", "Chat + Center Menu"},
	{"MenuMenusItem2", "WASD меню", "WASD Menu"},
	{"MenuMenusItem3", "Panorama меню", "Panorama Menu"},
	{"MenuMenusSet", "Тип меню: %s", "Menu type: %s"},
};

// The "wasd" (CENTER_WASD) templates, copied verbatim from the production
// ref/prod-27016/addons/translations/menus.phrases.txt. The same template is used for every
// language there, so ru and en get identical text. { key, ru, en }
constexpr const char* kBuiltinHtml[][3] = {
	{"HtmlTitle", "<font color='yellow' class='fontSize-ml'>%s</font><br/>", "<font color='yellow' class='fontSize-ml'>%s</font><br/>"},
	{"HtmlButton", "%s", "%s"},
	{"HtmlButtonBlock", "<font class='fontSize-sm' color='gray'>%s</font>", "<font class='fontSize-sm' color='gray'>%s</font>"},
	{"HtmlButtonBR", "<br/>", "<br/>"},
	{"HtmlEButtons", "<img src='s2r://resource/menus/e.vsvg' width='52' height='35' />", "<img src='s2r://resource/menus/e.vsvg' width='52' height='35' />"},
	{"HtmlE_PButtons", "<img src='s2r://resource/menus/e-p.vsvg' width='52' height='35' />", "<img src='s2r://resource/menus/e-p.vsvg' width='52' height='35' />"},
	{"HtmlWButtons", "<img src='s2r://resource/menus/w.vsvg' width='52' height='35' /> ", "<img src='s2r://resource/menus/w.vsvg' width='52' height='35' /> "},
	{"HtmlW_PButtons", "<img src='s2r://resource/menus/w-p.vsvg' width='52' height='35' /> ", "<img src='s2r://resource/menus/w-p.vsvg' width='52' height='35' /> "},
	{"HtmlSButtons", "<img src='s2r://resource/menus/s.vsvg' width='52' height='35' /> ", "<img src='s2r://resource/menus/s.vsvg' width='52' height='35' /> "},
	{"HtmlS_PButtons", "<img src='s2r://resource/menus/s-p.vsvg' width='52' height='35' /> ", "<img src='s2r://resource/menus/s-p.vsvg' width='52' height='35' /> "},
	{"HtmlAButtons", "<img src='s2r://resource/menus/a.vsvg' width='52' height='35' /> ", "<img src='s2r://resource/menus/a.vsvg' width='52' height='35' /> "},
	{"HtmlA_PButtons", "<img src='s2r://resource/menus/a-p.vsvg' width='52' height='35' /> ", "<img src='s2r://resource/menus/a-p.vsvg' width='52' height='35' /> "},
	{"HtmlDButtons", "<img src='s2r://resource/menus/d.vsvg' width='52' height='35' /> ", "<img src='s2r://resource/menus/d.vsvg' width='52' height='35' /> "},
	{"HtmlD_PButtons", "<img src='s2r://resource/menus/d-p.vsvg' width='52' height='35' /> ", "<img src='s2r://resource/menus/d-p.vsvg' width='52' height='35' /> "},
	{"HtmlFButtons", "<img src='s2r://resource/menus/f.vsvg' width='52' height='35' /> ", "<img src='s2r://resource/menus/f.vsvg' width='52' height='35' /> "},
	{"HtmlSpaceButtons", "<img src='s2r://resource/menus/empty.vsvg' width='52' height='35' /> ", "<img src='s2r://resource/menus/empty.vsvg' width='52' height='35' /> "},
	{"HtmlSpaceShortButtons", "<img src='s2r://resource/menus/empty_half.vsvg' width='52' height='35' /> ", "<img src='s2r://resource/menus/empty_half.vsvg' width='52' height='35' /> "},
	{"HtmlEButtons_Web", "<img src='https://%s/e.svg' width='52' height='35' />", "<img src='https://%s/e.svg' width='52' height='35' />"},
	{"HtmlE_PButtons_Web", "<img src='https://%s/e-p.svg' width='52' height='35' />", "<img src='https://%s/e-p.svg' width='52' height='35' />"},
	{"HtmlWButtons_Web", "<img src='https://%s/w.svg' width='52' height='35' /> ", "<img src='https://%s/w.svg' width='52' height='35' /> "},
	{"HtmlW_PButtons_Web", "<img src='https://%s/w-p.svg' width='52' height='35' /> ", "<img src='https://%s/w-p.svg' width='52' height='35' /> "},
	{"HtmlSButtons_Web", "<img src='https://%s/s.svg' width='52' height='35' /> ", "<img src='https://%s/s.svg' width='52' height='35' /> "},
	{"HtmlS_PButtons_Web", "<img src='https://%s/s-p.svg' width='52' height='35' /> ", "<img src='https://%s/s-p.svg' width='52' height='35' /> "},
	{"HtmlAButtons_Web", "<img src='https://%s/a.svg' width='52' height='35' /> ", "<img src='https://%s/a.svg' width='52' height='35' /> "},
	{"HtmlA_PButtons_Web", "<img src='https://%s/a-p.svg' width='52' height='35' /> ", "<img src='https://%s/a-p.svg' width='52' height='35' /> "},
	{"HtmlDButtons_Web", "<img src='https://%s/d.svg' width='52' height='35' /> ", "<img src='https://%s/d.svg' width='52' height='35' /> "},
	{"HtmlD_PButtons_Web", "<img src='https://%s/d-p.svg' width='52' height='35' /> ", "<img src='https://%s/d-p.svg' width='52' height='35' /> "},
	{"HtmlFButtons_Web", "<img src='https://%s/f.svg' width='52' height='35' /> ", "<img src='https://%s/f.svg' width='52' height='35' /> "},
	{"HtmlSpaceButtons_Web", "<img src='https://%s/empty.svg' width='52' height='35' /> ", "<img src='https://%s/empty.svg' width='52' height='35' /> "},
	{"HtmlSpaceShortButtons_Web", "<img src='https://%s/empty_half.svg' width='52' height='35' /> ", "<img src='https://%s/empty_half.svg' width='52' height='35' /> "},
};

enum class TokenKind { End, Open, Close, String, Error };

struct Token {
	TokenKind kind = TokenKind::End;
	std::string text;
};

// Tokenizer for the (KV1-ish) phrase format: braces, quoted strings with \" / \\ / \n escapes
// and // comments. Strings may span lines the way the Pisex files do.
class Tokenizer {
public:
	explicit Tokenizer(std::string_view text) : m_text(text) {}

	Token Next() {
		SkipSpaceAndComments();
		if (m_pos >= m_text.size()) {
			return {TokenKind::End, {}};
		}
		const char c = m_text[m_pos];
		if (c == '{') {
			++m_pos;
			return {TokenKind::Open, {}};
		}
		if (c == '}') {
			++m_pos;
			return {TokenKind::Close, {}};
		}
		if (c == '"') {
			return ReadString();
		}
		// Unquoted token: tolerate it as a bare string (the format also uses bare words).
		std::size_t end = m_pos;
		while (end < m_text.size() && m_text[end] != '{' && m_text[end] != '}' && m_text[end] != '"' &&
			   m_text[end] != ' ' && m_text[end] != '\t' && m_text[end] != '\r' && m_text[end] != '\n') {
			++end;
		}
		if (end == m_pos) {
			++m_pos;
			return {TokenKind::Error, {}};
		}
		std::string word(m_text.substr(m_pos, end - m_pos));
		m_pos = end;
		return {TokenKind::String, std::move(word)};
	}

private:
	void SkipSpaceAndComments() {
		while (m_pos < m_text.size()) {
			const char c = m_text[m_pos];
			if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
				++m_pos;
				continue;
			}
			if (c == '/' && m_pos + 1 < m_text.size() && m_text[m_pos + 1] == '/') {
				while (m_pos < m_text.size() && m_text[m_pos] != '\n') {
					++m_pos;
				}
				continue;
			}
			break;
		}
	}

	Token ReadString() {
		++m_pos; // opening quote
		std::string out;
		while (m_pos < m_text.size()) {
			const char c = m_text[m_pos++];
			if (c == '"') {
				return {TokenKind::String, std::move(out)};
			}
			if (c == '\\' && m_pos < m_text.size()) {
				const char esc = m_text[m_pos++];
				switch (esc) {
				case 'n': out.push_back('\n'); break;
				case 't': out.push_back('\t'); break;
				case 'r': out.push_back('\r'); break;
				default: out.push_back(esc); break; // \" \\ and anything else: literal
				}
				continue;
			}
			if (out.size() >= kMaxValueLength) {
				return {TokenKind::Error, {}};
			}
			out.push_back(c);
		}
		return {TokenKind::Error, {}}; // unterminated
	}

	std::string_view m_text;
	std::size_t m_pos = 0;
};

} // namespace

Phrases::Phrases() {
	LoadBuiltinFallback();
}

void Phrases::Set(std::string key, std::string language, std::string value) {
	if (m_table.size() >= kMaxEntries && m_table.find(key) == m_table.end()) {
		return;
	}
	m_table[std::move(key)][std::move(language)] = std::move(value);
}

void Phrases::LoadBuiltinFallback() {
	m_table.clear();
	for (const auto& entry : kBuiltin) {
		Set(entry[0], "ru", entry[1]);
		Set(entry[0], "en", entry[2]);
	}
	for (const auto& entry : kBuiltinHtml) {
		Set(entry[0], "ru", entry[1]);
		Set(entry[0], "en", entry[2]);
	}
	m_builtin = true;
}

bool Phrases::LoadFromFile(const std::string& path, std::string& error) {
	std::ifstream in(path, std::ios::binary);
	if (!in) {
		error = "cannot open " + path;
		return false;
	}
	std::string text((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	if (text.size() > kMaxFileSize) {
		error = path + " is too large";
		return false;
	}

	Tokenizer tokenizer(text);
	Token token = tokenizer.Next();

	// Optional root name ("Phrases") followed by the opening brace.
	if (token.kind == TokenKind::String) {
		token = tokenizer.Next();
	}
	if (token.kind != TokenKind::Open) {
		error = path + ": expected an opening '{'";
		return false;
	}

	Table parsed;
	bool sawEntry = false;
	while (true) {
		token = tokenizer.Next();
		if (token.kind == TokenKind::Close || token.kind == TokenKind::End) {
			break;
		}
		if (token.kind != TokenKind::String) {
			error = path + ": expected a phrase key";
			return false;
		}
		const std::string key = token.text;
		token = tokenizer.Next();
		if (token.kind == TokenKind::Open) {
			// Language map.
			auto& languages = parsed[key];
			while (true) {
				Token lang = tokenizer.Next();
				if (lang.kind == TokenKind::Close || lang.kind == TokenKind::End) {
					break;
				}
				if (lang.kind != TokenKind::String) {
					error = path + ": expected a language name for key '" + key + "'";
					return false;
				}
				Token value = tokenizer.Next();
				if (value.kind != TokenKind::String) {
					error = path + ": expected a value for key '" + key + "'";
					return false;
				}
				languages[lang.text] = value.text;
			}
		} else if (token.kind == TokenKind::String) {
			parsed[key]["en"] = token.text; // bare value: treat as English
		} else {
			error = path + ": expected a value for key '" + key + "'";
			return false;
		}
		sawEntry = true;
	}

	if (!sawEntry) {
		error = path + ": no phrases found";
		return false;
	}
	m_table = std::move(parsed);
	m_builtin = false;
	return true;
}

std::string Phrases::Get(std::string_view key, std::string_view language) const {
	const auto entry = m_table.find(std::string(key));
	if (entry == m_table.end()) {
		return std::string(key);
	}
	const auto& languages = entry->second;
	if (auto it = languages.find(std::string(language)); it != languages.end() && !it->second.empty()) {
		return it->second;
	}
	if (auto it = languages.find("en"); it != languages.end() && !it->second.empty()) {
		return it->second;
	}
	for (const auto& [lang, value] : languages) {
		(void)lang;
		if (!value.empty()) {
			return value;
		}
	}
	return std::string(key);
}

bool Phrases::Has(std::string_view key) const {
	return m_table.find(std::string(key)) != m_table.end();
}

std::size_t Phrases::Size() const {
	return m_table.size();
}

std::string FormatPhrase(const std::string& phrase, std::string_view value) {
	std::string out;
	out.reserve(phrase.size() + value.size());
	std::size_t pos = 0;
	while (true) {
		const std::size_t marker = phrase.find("%s", pos);
		if (marker == std::string::npos) {
			out.append(phrase, pos, std::string::npos);
			break;
		}
		out.append(phrase, pos, marker - pos);
		out.append(value);
		pos = marker + 2;
	}
	return out;
}

} // namespace hudmenu
