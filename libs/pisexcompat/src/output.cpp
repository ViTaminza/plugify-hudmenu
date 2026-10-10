#include <pisex/output.hpp>

#include <pisex/compat.hpp>
#include <pisex/paths.hpp>
#include <pisex/phrases.hpp>

#include <plg/plugin.hpp>
#include <s2sdk/s2sdk.hpp>

#include <array>
#include <cstdarg>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <string>
#include <string_view>

namespace pisex {
namespace {

// Pisex formats into char[512]; the admin core occasionally appends a player name and a reason,
// so a little headroom avoids silent truncation. Anything longer is cut here, never in the engine.
constexpr std::size_t kBufferSize = 2048;

bool ValidSlot(int slot) {
	return slot >= 0 && slot < 64;
}

// s2sdk print helpers touch client state, which only exists with a running map.
bool CanPrint() {
	return IsGameReady();
}

std::string Timestamp(const char* format) {
	const std::time_t now = std::time(nullptr);
	std::tm tm{};
	localtime_r(&now, &tm);
	char buffer[64] = {};
	std::strftime(buffer, sizeof(buffer), format, &tm);
	return std::string(buffer);
}

void AppendLogFile(const std::string& file, const std::string& line) {
	const std::string dir = plg::GetLogsDir ? std::string(plg::GetLogsDir()) : std::string();
	if (dir.empty()) {
		return;
	}
	std::ofstream out(JoinPath(dir, file), std::ios::app);
	if (out) {
		out << line;
	}
}

} // namespace

std::string FormatString(const char* format, ...) {
	std::array<char, kBufferSize> buffer{};
	va_list args;
	va_start(args, format);
	const int written = std::vsnprintf(buffer.data(), buffer.size(), format ? format : "", args);
	va_end(args);
	if (written <= 0) {
		return {};
	}
	return std::string(buffer.data(), static_cast<std::size_t>(written) < buffer.size() - 1
										  ? static_cast<std::size_t>(written)
										  : buffer.size() - 1);
}

void PrintToChatRaw(int iSlot, std::string_view message) {
	if (!CanPrint() || !ValidSlot(iSlot) || !__s2sdk_PrintToChat) {
		return;
	}
	try {
		s2sdk::PrintToChat(iSlot, plg::string(message));
	} catch (...) {
	}
}

void PrintToChat(int iSlot, const char* format, ...) {
	std::array<char, kBufferSize> buffer{};
	va_list args;
	va_start(args, format);
	std::vsnprintf(buffer.data(), buffer.size(), format ? format : "", args);
	va_end(args);
	PrintToChatRaw(iSlot, Colorize(buffer.data()));
}

void PrintToChatAll(const char* format, ...) {
	std::array<char, kBufferSize> buffer{};
	va_list args;
	va_start(args, format);
	std::vsnprintf(buffer.data(), buffer.size(), format ? format : "", args);
	va_end(args);
	if (!CanPrint() || !__s2sdk_PrintToChatAll) {
		return;
	}
	try {
		s2sdk::PrintToChatAll(plg::string(Colorize(buffer.data())));
	} catch (...) {
	}
}

void PrintToConsole(int iSlot, const char* format, ...) {
	std::array<char, kBufferSize> buffer{};
	va_list args;
	va_start(args, format);
	std::vsnprintf(buffer.data(), buffer.size(), format ? format : "", args);
	va_end(args);

	if (!ValidSlot(iSlot)) {
		// Pisex: an out-of-range slot means "server console" (META_CONPRINT). Chat colour tags
		// in a phrase mean nothing there and were printed literally ("{LIGHTRED}mm_kick").
		if (plg::Log) {
			plg::Log(StripColorTags(buffer.data()), plg::Severity::Info, plg::source_location::current());
		}
		return;
	}
	if (!CanPrint() || !__s2sdk_PrintToConsole) {
		return;
	}
	try {
		s2sdk::PrintToConsole(iSlot, plg::string(buffer.data()));
	} catch (...) {
	}
}

void PrintToConsoleAll(const char* format, ...) {
	std::array<char, kBufferSize> buffer{};
	va_list args;
	va_start(args, format);
	std::vsnprintf(buffer.data(), buffer.size(), format ? format : "", args);
	va_end(args);
	if (!CanPrint() || !__s2sdk_PrintToConsoleAll) {
		return;
	}
	try {
		s2sdk::PrintToConsoleAll(plg::string(buffer.data()));
	} catch (...) {
	}
}

void PrintToCenter(int iSlot, const char* format, ...) {
	std::array<char, kBufferSize> buffer{};
	va_list args;
	va_start(args, format);
	std::vsnprintf(buffer.data(), buffer.size(), format ? format : "", args);
	va_end(args);
	if (!CanPrint() || !ValidSlot(iSlot) || !__s2sdk_PrintCenterText) {
		return;
	}
	try {
		s2sdk::PrintCenterText(iSlot, plg::string(buffer.data()));
	} catch (...) {
	}
}

void PrintToCenterAll(const char* format, ...) {
	std::array<char, kBufferSize> buffer{};
	va_list args;
	va_start(args, format);
	std::vsnprintf(buffer.data(), buffer.size(), format ? format : "", args);
	va_end(args);
	if (!CanPrint() || !__s2sdk_PrintCenterTextAll) {
		return;
	}
	try {
		s2sdk::PrintCenterTextAll(plg::string(buffer.data()));
	} catch (...) {
	}
}

void PrintToCenterHtml(int iSlot, int iDuration, const char* format, ...) {
	std::array<char, kBufferSize> buffer{};
	va_list args;
	va_start(args, format);
	std::vsnprintf(buffer.data(), buffer.size(), format ? format : "", args);
	va_end(args);
	if (!CanPrint() || !ValidSlot(iSlot) || !__s2sdk_PrintCentreHtml) {
		return;
	}
	try {
		s2sdk::PrintCentreHtml(iSlot, plg::string(buffer.data()), iDuration);
	} catch (...) {
	}
}

void PrintToCenterHtmlAll(int iDuration, const char* format, ...) {
	std::array<char, kBufferSize> buffer{};
	va_list args;
	va_start(args, format);
	std::vsnprintf(buffer.data(), buffer.size(), format ? format : "", args);
	va_end(args);
	if (!CanPrint() || !__s2sdk_PrintCentreHtmlAll) {
		return;
	}
	try {
		s2sdk::PrintCentreHtmlAll(plg::string(buffer.data()), iDuration);
	} catch (...) {
	}
}

void PrintToAlert(int iSlot, const char* format, ...) {
	std::array<char, kBufferSize> buffer{};
	va_list args;
	va_start(args, format);
	std::vsnprintf(buffer.data(), buffer.size(), format ? format : "", args);
	va_end(args);
	if (!CanPrint() || !ValidSlot(iSlot) || !__s2sdk_PrintAlertText) {
		return;
	}
	try {
		s2sdk::PrintAlertText(iSlot, plg::string(buffer.data()));
	} catch (...) {
	}
}

void PrintToAlertAll(const char* format, ...) {
	std::array<char, kBufferSize> buffer{};
	va_list args;
	va_start(args, format);
	std::vsnprintf(buffer.data(), buffer.size(), format ? format : "", args);
	va_end(args);
	if (!CanPrint() || !__s2sdk_PrintAlertTextAll) {
		return;
	}
	try {
		s2sdk::PrintAlertTextAll(plg::string(buffer.data()));
	} catch (...) {
	}
}

void LogToFile(const char* file, const char* format, ...) {
	std::array<char, kBufferSize> buffer{};
	va_list args;
	va_start(args, format);
	std::vsnprintf(buffer.data(), buffer.size(), format ? format : "", args);
	va_end(args);

	const std::string line = "L " + Timestamp("%m/%d/%Y - %H:%M:%S") + ": " + buffer.data();
	if (plg::Log) {
		plg::Log(std::string_view(line), plg::Severity::Info, plg::source_location::current());
	}
	const std::string name = std::string(file ? file : "log") + ".txt";
	AppendLogFile(name, line + "\n");
}

void ErrorLog(const char* format, ...) {
	std::array<char, kBufferSize> buffer{};
	va_list args;
	va_start(args, format);
	std::vsnprintf(buffer.data(), buffer.size(), format ? format : "", args);
	va_end(args);

	const std::string message = std::string("[Error] ") + buffer.data();
	if (plg::Log) {
		plg::Log(std::string_view(message), plg::Severity::Error, plg::source_location::current());
	}
	const std::string line = "L " + Timestamp("%m/%d/%Y - %H:%M:%S") + ": " + buffer.data();
	AppendLogFile(Timestamp("error_%m-%d-%Y") + ".txt", line + "\n");
}

} // namespace pisex
