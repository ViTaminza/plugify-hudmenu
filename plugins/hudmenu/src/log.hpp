// Logging helpers (plg::Log) and small string conversions shared by the plugin files.
#pragma once

#include <plg/plugin.hpp>
#include <plg/string.hpp>

#include <string>
#include <string_view>

namespace hudmenu {

inline std::string ToString(const plg::string& text) {
	return std::string(std::string_view(text));
}

inline void LogMessage(std::string_view message, plg::Severity severity) {
	if (plg::Log) {
		plg::Log(message, severity, plg::source_location::current());
	}
}

inline void LogTrace(std::string_view message) { LogMessage(message, plg::Severity::Trace); }
inline void LogDebug(std::string_view message) { LogMessage(message, plg::Severity::Debug); }
inline void LogInfo(std::string_view message) { LogMessage(message, plg::Severity::Info); }
inline void LogWarn(std::string_view message) { LogMessage(message, plg::Severity::Warning); }
inline void LogError(std::string_view message) { LogMessage(message, plg::Severity::Error); }

} // namespace hudmenu
