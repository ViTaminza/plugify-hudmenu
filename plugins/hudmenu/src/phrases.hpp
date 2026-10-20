// Minimal Pisex phrase table for the menu-type chooser.
//
// The file is Pisex's KeyValues phrase format (translations/hudmenu.phrases.txt, the keys copied
// from cs2-menus' menus.phrases.txt):
//
//     "Phrases"
//     {
//         "MenuMenusTitle"
//         {
//             "ru"    "Выберите тип меню"
//             "en"    "Choose menu type"
//         }
//     }
//
// hudmenu must not link pisexcompat (pisexcompat resolves menu types through this plugin's
// exported methods - a link would be a cycle), so this is a small purpose-built reader for
// exactly that shape, with a built-in fallback table so the chooser works even when the file
// is missing. Nothing here may throw at the call sites: LoadFromFile() reports failures through
// its return value.
#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

namespace hudmenu {

class Phrases {
public:
	using Table = std::unordered_map<std::string, std::unordered_map<std::string, std::string>>;

	Phrases();

	// Parses a phrase file. On any error the table is left as it was (the built-in fallback),
	// `error` is filled and false is returned.
	bool LoadFromFile(const std::string& path, std::string& error);

	// Restores the built-in (en/ru) copies of the chooser phrases.
	void LoadBuiltinFallback();

	// Phrase for `language` (an ISO code like "en"/"ru"); falls back to "en", then to any
	// translation the file provides, then to the key itself.
	[[nodiscard]] std::string Get(std::string_view key, std::string_view language) const;
	[[nodiscard]] bool Has(std::string_view key) const;
	[[nodiscard]] std::size_t Size() const;
	[[nodiscard]] bool IsBuiltin() const { return m_builtin; }

private:
	void Set(std::string key, std::string language, std::string value);

	Table m_table;
	bool m_builtin = true;
};

// Replaces every "%s" in `phrase` with `value` (Pisex's phrases pass through one argument).
std::string FormatPhrase(const std::string& phrase, std::string_view value);

} // namespace hudmenu
