// pisexcompat — chat colour tags and the Pisex phrase (translation) store.
//
// Colour tags: cs2-menus/utils.h owns the table the whole Pisex family uses
// ({DEFAULT} {WHITE} {RED} {LIGHTPURPLE} {GREEN} {LIME} {LIGHTGREEN} {DARKRED} {GRAY} {LIGHTOLIVE}
//  {OLIVE} {LIGHTBLUE} {BLUE} {PURPLE} {LIGHTRED} {GRAYBLUE} {\n}); pisex::Colorize() replaces the
// tags with exactly the same bytes (0x01..0x10 and the U+2029 line separator for "\n") so chat
// output is byte-identical to the Metamod server.
//
// Phrases: LoadPhrasesFile() reads a *.phrases.txt (KeyValues: "Key" { "ru" "..." "en" "..." })
// and resolves every key for the selected language with an "en" fallback, which is what
// cs2-menus/admin_system do (they read GetString(GetLanguage()) with no fallback at all).
// The result lands in the caller's map or in the shared pisex::g_translations.

#pragma once

#include <map>
#include <string>
#include <string_view>

namespace pisex {

using PhraseMap = std::map<std::string, std::string>;

// Shared store filled by UtilsApi::LoadTranslations() / pisex::LoadPhrases("name.phrases").
extern PhraseMap g_translations;

// Replaces {TAG} colour tags with the cs2-menus chat colour bytes.
std::string Colorize(std::string_view text);
// The same tags removed (and "\\n" turned into a real newline): for the server console, which
// shows the chat colour bytes as garbage and the tags as literal text.
std::string StripColorTags(std::string_view text);

// Language used when a phrase has no entry for the selected language.
inline constexpr std::string_view kFallbackLanguage = "en";

// Loads <translations dir>/<file> (".txt" is appended when missing) into `out`.
// When `language` is null the current language (pisex::PhrasesLanguage) is used.
// Returns false when the file cannot be read; `out` is left untouched then.
bool LoadPhrasesFile(const char* file, PhraseMap& out, const char* language = nullptr);

// Same, into the shared store (adds to it; Pisex's LoadTranslations has the same additive
// behaviour - the admin core clears its map itself on reload).
bool LoadPhrases(const char* file, const char* language = nullptr);

// Current language ("ru", "en", ...). Defaults to the server language reported by s2sdk,
// normalized to the codes used by the Pisex phrase files, with "en" as the fallback.
void SetPhrasesLanguage(std::string_view language);
const std::string& PhrasesLanguage();

// Maps a Source language name ("russian", "portuguese", ...) to the phrase-file code ("ru",
// "pt-BR", ...). Unknown names are returned unchanged.
std::string NormalizeLanguage(std::string_view name);

// Phrase lookup in the shared store; returns the key itself when it is missing, which is what
// IAdminApi::GetTranslation() does (so missing phrases are visible instead of printing nothing).
const std::string& GetPhrase(const char* key);
const char* GetPhraseCStr(const char* key);

} // namespace pisex
