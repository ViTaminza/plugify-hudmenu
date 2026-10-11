#include <pisex/paths.hpp>

#include <plg/plugin.hpp>

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace pisex {
namespace {

std::string g_pluginName;
std::string g_configDirOverride;
std::string g_translationsDirOverride;
std::string g_configDir;       // cache, valid while the overrides do not change
std::string g_translationsDir;
std::string g_dataDir;
bool g_dirsCached = false;

std::string CfgRoot() {
	return plg::GetConfigsDir ? std::string(plg::GetConfigsDir()) : std::string();
}

std::string DataRoot() {
	return plg::GetDataDir ? std::string(plg::GetDataDir()) : std::string();
}

void InvalidateCaches() {
	g_dirsCached = false;
	g_configDir.clear();
	g_translationsDir.clear();
	g_dataDir.clear();
}

bool StartsWith(std::string_view text, std::string_view prefix) {
	return text.size() >= prefix.size() && text.compare(0, prefix.size(), prefix) == 0;
}

std::string_view StripPrefix(std::string_view text, std::string_view prefix) {
	return StartsWith(text, prefix) ? text.substr(prefix.size()) : std::string_view{};
}

// Tries the candidates in order and returns the first one that exists on disk.
std::string FirstExisting(const std::vector<std::string>& candidates) {
	for (const std::string& candidate : candidates) {
		if (!candidate.empty() && FileExists(candidate)) {
			return candidate;
		}
	}
	return {};
}

std::vector<std::string> Candidates(std::string_view path, const std::string& preferredDir) {
	std::vector<std::string> out;
	if (path.empty()) {
		return out;
	}
	const std::string raw(path);
	const bool absolute = !raw.empty() && raw.front() == '/';
	out.push_back(raw); // as given (absolute, or relative to the server working directory)

	if (absolute) {
		return out;
	}

	// "addons/configs/<plugin>/x.ini" / "addons/translations/x.phrases.txt" / "addons/data/x"
	// are the Metamod spellings; strip the fixed prefix and treat the rest as a relative path.
	std::string_view relative = path;
	bool fromTranslations = false;
	bool fromData = false;
	if (auto rest = StripPrefix(path, "addons/configs/"); !rest.empty()) {
		relative = rest;
		// "admin_system/core.ini" -> "core.ini" when it is our own config dir.
		if (!g_pluginName.empty() && StartsWith(rest, g_pluginName + "/")) {
			relative = rest.substr(g_pluginName.size() + 1);
		}
	} else if (auto rest2 = StripPrefix(path, "addons/translations/"); !rest2.empty()) {
		relative = rest2;
		fromTranslations = true;
	} else if (auto rest3 = StripPrefix(path, "addons/data/"); !rest3.empty()) {
		relative = rest3;
		fromData = true;
	} else if (auto rest4 = StripPrefix(path, "addons/"); !rest4.empty()) {
		relative = rest4;
	}

	const std::string rel(relative);
	const std::string& configDir = preferredDir.empty() ? ConfigDir() : preferredDir;
	const std::string& translations = preferredDir.empty() ? TranslationsDir() : preferredDir;

	if (fromTranslations) {
		out.push_back(JoinPath(translations, rel));
	} else if (fromData) {
		out.push_back(JoinPath(DataDir(), rel));
	} else {
		out.push_back(JoinPath(configDir, rel));
		out.push_back(JoinPath(translations, rel));
		out.push_back(JoinPath(DataDir(), rel));
	}
	return out;
}

} // namespace

void SetPluginName(std::string_view name) {
	g_pluginName.assign(name);
	InvalidateCaches();
}

const std::string& PluginName() {
	return g_pluginName;
}

void SetConfigDir(std::string_view dir) {
	g_configDirOverride.assign(dir);
	InvalidateCaches();
}

void SetTranslationsDir(std::string_view dir) {
	g_translationsDirOverride.assign(dir);
	InvalidateCaches();
}

const std::string& ConfigDir() {
	if (!g_dirsCached) {
		g_configDir = !g_configDirOverride.empty()
						  ? g_configDirOverride
						  : (g_pluginName.empty() ? CfgRoot() : JoinPath(CfgRoot(), g_pluginName));
		g_translationsDir = !g_translationsDirOverride.empty()
								? g_translationsDirOverride
								: JoinPath(g_configDir, "translations");
		g_dataDir = g_pluginName.empty() ? DataRoot() : JoinPath(DataRoot(), g_pluginName);
		g_dirsCached = true;
	}
	return g_configDir;
}

const std::string& TranslationsDir() {
	(void)ConfigDir(); // fills every cache
	return g_translationsDir;
}

const std::string& DataDir() {
	(void)ConfigDir();
	return g_dataDir;
}

std::string JoinPath(std::string_view a, std::string_view b) {
	if (a.empty()) {
		return std::string(b);
	}
	if (b.empty()) {
		return std::string(a);
	}
	std::string out(a);
	if (out.back() != '/') {
		out.push_back('/');
	}
	if (b.front() == '/') {
		b.remove_prefix(1);
	}
	out.append(b);
	return out;
}

bool FileExists(std::string_view path) {
	if (path.empty()) {
		return false;
	}
	std::ifstream file(std::string(path), std::ios::binary);
	return file.good();
}

std::string ReadFile(std::string_view path, bool* ok) {
	std::string content;
	std::ifstream file(std::string(path), std::ios::binary);
	if (!file) {
		if (ok) {
			*ok = false;
		}
		return content;
	}
	std::ostringstream buffer;
	buffer << file.rdbuf();
	content = buffer.str();
	if (ok) {
		*ok = true;
	}
	return content;
}

std::string ResolvePath(std::string_view path) {
	if (path.empty()) {
		return {};
	}
	std::string resolved = FirstExisting(Candidates(path, {}));
	if (resolved.empty()) {
		// Nothing on disk: hand back the most likely location so callers can log a useful path.
		const auto candidates = Candidates(path, {});
		if (!candidates.empty()) {
			resolved = candidates.size() > 1 ? candidates[1] : candidates.front();
		}
	}
	return resolved;
}

std::string ResolveTranslationsPath(std::string_view path) {
	if (path.empty()) {
		return {};
	}
	std::string file(path);
	if (file.size() < 4 || file.compare(file.size() - 4, 4, ".txt") != 0) {
		file += ".txt"; // Pisex's LoadTranslations() takes "menus.phrases" and appends ".txt"
	}
	const std::string direct = FirstExisting({file, JoinPath(TranslationsDir(), file), JoinPath(ConfigDir(), file)});
	if (!direct.empty()) {
		return direct;
	}
	// "addons/translations/admin_system.phrases.txt" and friends.
	std::string_view relative = file;
	if (auto rest = StripPrefix(file, "addons/translations/"); !rest.empty()) {
		relative = rest;
	}
	const std::string candidate = JoinPath(TranslationsDir(), relative);
	if (FileExists(candidate)) {
		return candidate;
	}
	return candidate;
}

std::string ResolveDataPath(std::string_view path) {
	if (path.empty()) {
		return {};
	}
	std::string file(path);
	if (auto rest = StripPrefix(file, "addons/data/"); !rest.empty()) {
		file = std::string(rest);
	}
	const std::string candidate = JoinPath(DataDir(), file);
	return FileExists(candidate) ? candidate : candidate;
}

} // namespace pisex
