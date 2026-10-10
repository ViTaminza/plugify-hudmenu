// pisexcompat — path resolution for configs / translations / data files.
//
// The Pisex plugins hard-code Metamod paths ("addons/configs/admin_system/core.ini",
// "addons/translations/admin_system.phrases.txt", "addons/data/..."). Plugify gives each plugin
// its own config and data directory instead, so pisexcompat resolves relative paths through a
// small candidate list, which keeps the ported loaders free of layout knowledge:
//
//   file.txt                          -> cwd, then <configs>/<plugin>/file.txt, then <configs>/file.txt
//   addons/configs/<x>/file.txt       -> the "addons/configs/<x>/" prefix is stripped
//   addons/translations/file.txt      -> resolved in the translations dir
//   addons/data/file.txt              -> resolved in the data dir
//
// Any path that already exists as given (absolute or relative to the server working directory)
// wins, so a ported plugin can also be pointed at a hand-written file.

#pragma once

#include <string>
#include <string_view>

namespace pisex {

// Names the ported plugin; sets <GetConfigsDir()>/<name> and <GetDataDir()>/<name> as base dirs.
// Called by pisex::Init(), or directly before loading a config outside of a plugin.
void SetPluginName(std::string_view name);
const std::string& PluginName();

// Explicit overrides (empty string = derive from the plugify dirs / plugin name).
void SetConfigDir(std::string_view dir);
void SetTranslationsDir(std::string_view dir);

const std::string& ConfigDir();       // <GetConfigsDir()>/<plugin>
const std::string& TranslationsDir(); // <ConfigDir()>/translations
const std::string& DataDir();         // <GetDataDir()>/<plugin>

std::string JoinPath(std::string_view a, std::string_view b);
bool FileExists(std::string_view path);
// Reads a whole file; returns an empty string and sets *ok=false when it cannot be opened.
std::string ReadFile(std::string_view path, bool* ok = nullptr);

// Candidate search described above; returns the first existing path, or "" when nothing matched.
std::string ResolvePath(std::string_view path);
// Same, but always resolved against the translations dir first (phrases files).
std::string ResolveTranslationsPath(std::string_view path);
// Same, resolved against the data dir first.
std::string ResolveDataPath(std::string_view path);

} // namespace pisex
