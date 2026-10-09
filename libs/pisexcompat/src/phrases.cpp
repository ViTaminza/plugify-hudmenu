#include <pisex/phrases.hpp>

#include <pisex/compat.hpp>
#include <pisex/keyvalues.hpp>
#include <pisex/paths.hpp>

#include <plg/plugin.hpp>
#include <s2sdk/s2sdk.hpp>

#include <array>
#include <cstddef>
#include <string>
#include <utility>

namespace pisex {

PhraseMap g_translations;

namespace {

// cs2-menus/utils.h: colors_text[] / colors_hex[], same order, same bytes. The last entry is the
// chat line break: "\n" -> U+2029 (e2 80 a9), which the CS2 chat renderer shows as a new line.
struct ColorTag {
	std::string_view tag;
	std::string_view bytes;
};

constexpr std::array<ColorTag, 17> kColorTags = {{{"{DEFAULT}", "\x01"},
												  {"{WHITE}", "\x01"},
												  {"{RED}", "\x02"},
												  {"{LIGHTPURPLE}", "\x03"},
												  {"{GREEN}", "\x04"},
												  {"{LIME}", "\x05"},
												  {"{LIGHTGREEN}", "\x06"},
												  {"{DARKRED}", "\x07"},
												  {"{GRAY}", "\x08"},
												  {"{LIGHTOLIVE}", "\x09"},
												  {"{OLIVE}", "\x10"},
												  {"{LIGHTBLUE}", "\x0B"},
												  {"{BLUE}", "\x0C"},
												  {"{PURPLE}", "\x0E"},
												  {"{LIGHTRED}", "\x0F"},
												  {"{GRAYBLUE}", "\x0A"},
												  {"\\n", "\xe2\x80\xa9"}}};

std::string g_language;
bool g_languageDetected = false;

// The Pisex server language: cs2-menus read "ServerLang" from addons/configs/core.cfg
// (ref/pisex/cs2-menus/utils.cpp:734, the production file says "ru"). The Plugify equivalent of
// that shared file is <configs>/core.cfg; empty when there is none.
std::string CoreConfigLanguage() {
	if (!plg::GetConfigsDir) {
		return {};
	}
	std::string path(plg::GetConfigsDir());
	if (path.empty()) {
		return {};
	}
	if (path.back() != '/') {
		path.push_back('/');
	}
	path += "core.cfg";
	KeyValues core("Core");
	if (!FileExists(path) || !core.LoadFromFile(path.c_str())) {
		return {};
	}
	const char* language = core.GetString("ServerLang", "");
	return language != nullptr ? std::string(language) : std::string();
}

// One language for every phrase of the plugin, like Pisex: core.cfg "ServerLang" first, then
// s2sdk's ServerLanguage (envs/plugins/s2sdk/settings.jsonc). Both are plain config reads, so
// this works at plugin start (the phrases are loaded there) - no map is needed.
std::string DetectLanguage() {
	if (const std::string core = CoreConfigLanguage(); !core.empty()) {
		return NormalizeLanguage(core);
	}
	if (!__s2sdk_GetServerLanguage) {
		return std::string(kFallbackLanguage);
	}
	try {
		const plg::string serverLanguage = s2sdk::GetServerLanguage();
		if (serverLanguage.empty()) {
			return std::string(kFallbackLanguage);
		}
		return NormalizeLanguage(std::string_view(serverLanguage));
	} catch (...) {
		return std::string(kFallbackLanguage);
	}
}

} // namespace

std::string StripColorTags(std::string_view text) {
	std::string out(text);
	for (const ColorTag& color : kColorTags) {
		const std::string_view replacement = color.tag == "\\n" ? std::string_view("\n") : std::string_view();
		std::size_t pos = 0;
		while ((pos = out.find(color.tag, pos)) != std::string::npos) {
			out.replace(pos, color.tag.size(), replacement);
			pos += replacement.size();
		}
	}
	return out;
}

std::string Colorize(std::string_view text) {
	std::string out(text);
	for (const ColorTag& color : kColorTags) {
		std::size_t pos = 0;
		while ((pos = out.find(color.tag, pos)) != std::string::npos) {
			out.replace(pos, color.tag.size(), color.bytes);
			pos += color.bytes.size();
		}
	}
	return out;
}

std::string NormalizeLanguage(std::string_view name) {
	std::string lower;
	lower.reserve(name.size());
	for (const char c : name) {
		lower.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(c))));
	}
	// Source language names -> the codes used by the Pisex phrase files.
	if (lower == "russian" || lower == "ru") return "ru";
	if (lower == "english" || lower == "en") return "en";
	if (lower == "ukrainian" || lower == "ua" || lower == "uk") return "ua";
	if (lower == "portuguese" || lower == "pt-br" || lower == "brazilian") return "pt-BR";
	if (lower == "spanish" || lower == "es") return "es";
	if (lower == "german" || lower == "de") return "de";
	if (lower == "french" || lower == "fr") return "fr";
	if (lower == "polish" || lower == "pl") return "pl";
	if (lower == "turkish" || lower == "tr") return "tr";
	if (lower == "schinese" || lower == "zh-cn") return "zh-CN";
	return std::string(name);
}

bool LoadPhrasesFile(const char* file, PhraseMap& out, const char* language) {
	if (!file || !*file) {
		return false;
	}
	KeyValues root("Phrases");
	if (!root.LoadFromFile(ResolveTranslationsPath(file))) {
		return false;
	}

	if (!language || !*language) {
		language = PhrasesLanguage().c_str();
	}
	const std::string fallback(kFallbackLanguage);

	for (KeyValues* key = root.GetFirstTrueSubKey(); key; key = key->GetNextTrueSubKey()) {
		std::string text;
		if (const KeyValues* localized = key->FindKey(language); localized && localized->HasValue()) {
			text = std::string(localized->GetStringValue());
		}
		if (text.empty() && std::string_view(language) != fallback) {
			if (const KeyValues* english = key->FindKey(fallback.data()); english && english->HasValue()) {
				text = std::string(english->GetStringValue());
			}
		}
		if (text.empty()) {
			// Last resort: any language the file has, so a partially translated file still shows
			// something instead of an empty chat line.
			for (KeyValues* candidate = key->GetFirstValue(); candidate; candidate = candidate->GetNextValue()) {
				if (candidate->HasValue()) {
					text = std::string(candidate->GetStringValue());
					break;
				}
			}
		}
		out[key->GetName()] = std::move(text);
	}
	return true;
}

bool LoadPhrases(const char* file, const char* language) {
	return LoadPhrasesFile(file, g_translations, language);
}

void SetPhrasesLanguage(std::string_view language) {
	g_language.assign(language);
	g_languageDetected = true;
}

const std::string& PhrasesLanguage() {
	if (!g_languageDetected) {
		g_language = DetectLanguage();
	}
	return g_language;
}

const std::string& GetPhrase(const char* key) {
	static const std::string empty;
	if (!key) {
		return empty;
	}
	const auto found = g_translations.find(key);
	return found == g_translations.end() ? empty : found->second;
}

const char* GetPhraseCStr(const char* key) {
	if (!key) {
		return "";
	}
	const auto found = g_translations.find(key);
	return found == g_translations.end() ? key : found->second.c_str();
}

} // namespace pisex
