// pisexcompat — chat / console / centre output and logging (IUtilsApi's print family).
//
// All printers take a printf-style format (Pisex passes a format plus arguments) and go through
// s2sdk's HUD destinations, which use the same CUserMessageTextMsg the Metamod plugin used, so
// the colour bytes produced by pisex::Colorize() arrive untouched:
//
//   PrintToChat(slot, "%s joined", name)      -> HUD_PRINTTALK   (coloured, 1 client)
//   PrintToChatAll(...)                       -> HUD_PRINTTALK   (all real players)
//   PrintToConsole(slot, ...)                 -> HUD_PRINTCONSOLE (a negative slot prints to the
//                                                server console, like Pisex's META_CONPRINT)
//   PrintToCenter / PrintToAlert              -> HUD_PRINTCENTER / HUD_PRINTALERT
//   PrintToCenterHtml(slot, duration, ...)    -> HTML centre message (s2sdk's PrintCentreHtml)
//
// Every printer is a no-op while no map is running (pisex::IsGameReady() == false), because the
// s2sdk print helpers reach for client state; they are called from plugin start in Pisex and must
// not crash there. Use "%s" style formats only - Pisex's own format strings (%i, %llu) work.

#pragma once

#include <string>
#include <string_view>

namespace pisex {

void PrintToChat(int iSlot, const char* format, ...) __attribute__((format(printf, 2, 3)));
void PrintToChatAll(const char* format, ...) __attribute__((format(printf, 1, 2)));
void PrintToChatRaw(int iSlot, std::string_view message);

void PrintToConsole(int iSlot, const char* format, ...) __attribute__((format(printf, 2, 3)));
void PrintToConsoleAll(const char* format, ...) __attribute__((format(printf, 1, 2)));

void PrintToCenter(int iSlot, const char* format, ...) __attribute__((format(printf, 2, 3)));
void PrintToCenterAll(const char* format, ...) __attribute__((format(printf, 1, 2)));

void PrintToCenterHtml(int iSlot, int iDuration, const char* format, ...) __attribute__((format(printf, 3, 4)));
void PrintToCenterHtmlAll(int iDuration, const char* format, ...) __attribute__((format(printf, 2, 3)));

void PrintToAlert(int iSlot, const char* format, ...) __attribute__((format(printf, 2, 3)));
void PrintToAlertAll(const char* format, ...) __attribute__((format(printf, 1, 2)));

// Timestamped line to the server console + <logs dir>/<file>.txt (Pisex: addons/logs/<file>.txt).
void LogToFile(const char* file, const char* format, ...) __attribute__((format(printf, 2, 3)));
// Red "[Error] ..." line on the server console + <logs dir>/error_MM-DD-YYYY.txt.
void ErrorLog(const char* format, ...) __attribute__((format(printf, 1, 2)));

// printf into a std::string (the shared formatter behind the printers).
std::string FormatString(const char* format, ...) __attribute__((format(printf, 1, 2)));

} // namespace pisex
