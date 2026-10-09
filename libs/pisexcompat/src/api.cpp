#include <pisex/api.hpp>

#include <pisex/compat.hpp>
#include <pisex/paths.hpp>

#include <cstdarg>
#include <cstdio>
#include <string>
#include <utility>

namespace pisex {

namespace {

UtilsApi g_utils;
MenusApi g_menus;
PlayersApi g_players;

} // namespace

UtilsApi* const g_pUtils = &g_utils;
MenusApi* const g_pMenus = &g_menus;
PlayersApi* const g_pPlayers = &g_players;

UtilsApi& Utils() {
	return g_utils;
}

MenusApi& Menus() {
	return g_menus;
}

PlayersApi& Players() {
	return g_players;
}

// --- UtilsApi: messages ----------------------------------------------------------------------

void UtilsApi::PrintToChat(int iSlot, const char* msg, ...) {
	va_list args;
	va_start(args, msg);
	std::array<char, 2048> buffer{};
	std::vsnprintf(buffer.data(), buffer.size(), msg ? msg : "", args);
	va_end(args);
	PrintToChatRaw(iSlot, Colorize(buffer.data()));
}

void UtilsApi::PrintToChatAll(const char* msg, ...) {
	va_list args;
	va_start(args, msg);
	std::array<char, 2048> buffer{};
	std::vsnprintf(buffer.data(), buffer.size(), msg ? msg : "", args);
	va_end(args);
	pisex::PrintToChatAll("%s", Colorize(buffer.data()).c_str());
}

void UtilsApi::PrintToConsole(int iSlot, const char* msg, ...) {
	va_list args;
	va_start(args, msg);
	std::array<char, 2048> buffer{};
	std::vsnprintf(buffer.data(), buffer.size(), msg ? msg : "", args);
	va_end(args);
	pisex::PrintToConsole(iSlot, "%s", buffer.data());
}

void UtilsApi::PrintToConsoleAll(const char* msg, ...) {
	va_list args;
	va_start(args, msg);
	std::array<char, 2048> buffer{};
	std::vsnprintf(buffer.data(), buffer.size(), msg ? msg : "", args);
	va_end(args);
	pisex::PrintToConsoleAll("%s", buffer.data());
}

void UtilsApi::PrintToCenter(int iSlot, const char* msg, ...) {
	va_list args;
	va_start(args, msg);
	std::array<char, 2048> buffer{};
	std::vsnprintf(buffer.data(), buffer.size(), msg ? msg : "", args);
	va_end(args);
	pisex::PrintToCenter(iSlot, "%s", buffer.data());
}

void UtilsApi::PrintToCenterAll(const char* msg, ...) {
	va_list args;
	va_start(args, msg);
	std::array<char, 2048> buffer{};
	std::vsnprintf(buffer.data(), buffer.size(), msg ? msg : "", args);
	va_end(args);
	pisex::PrintToCenterAll("%s", buffer.data());
}

void UtilsApi::PrintToCenterHtml(int iSlot, int iDuration, const char* msg, ...) {
	va_list args;
	va_start(args, msg);
	std::array<char, 2048> buffer{};
	std::vsnprintf(buffer.data(), buffer.size(), msg ? msg : "", args);
	va_end(args);
	pisex::PrintToCenterHtml(iSlot, iDuration, "%s", buffer.data());
}

void UtilsApi::PrintToCenterHtmlAll(int iDuration, const char* msg, ...) {
	va_list args;
	va_start(args, msg);
	std::array<char, 2048> buffer{};
	std::vsnprintf(buffer.data(), buffer.size(), msg ? msg : "", args);
	va_end(args);
	pisex::PrintToCenterHtmlAll(iDuration, "%s", buffer.data());
}

void UtilsApi::PrintToAlert(int iSlot, const char* msg, ...) {
	va_list args;
	va_start(args, msg);
	std::array<char, 2048> buffer{};
	std::vsnprintf(buffer.data(), buffer.size(), msg ? msg : "", args);
	va_end(args);
	pisex::PrintToAlert(iSlot, "%s", buffer.data());
}

void UtilsApi::PrintToAlertAll(const char* msg, ...) {
	va_list args;
	va_start(args, msg);
	std::array<char, 2048> buffer{};
	std::vsnprintf(buffer.data(), buffer.size(), msg ? msg : "", args);
	va_end(args);
	pisex::PrintToAlertAll("%s", buffer.data());
}

void UtilsApi::ErrorLog(const char* msg, ...) {
	va_list args;
	va_start(args, msg);
	std::array<char, 2048> buffer{};
	std::vsnprintf(buffer.data(), buffer.size(), msg ? msg : "", args);
	va_end(args);
	pisex::ErrorLog("%s", buffer.data());
}

void UtilsApi::LogToFile(const char* szFile, const char* szText, ...) {
	va_list args;
	va_start(args, szText);
	std::array<char, 2048> buffer{};
	std::vsnprintf(buffer.data(), buffer.size(), szText ? szText : "", args);
	va_end(args);
	pisex::LogToFile(szFile, "%s", buffer.data());
}

// --- UtilsApi: commands / events -------------------------------------------------------------

void UtilsApi::RegCommand(const std::vector<std::string>& console, const std::vector<std::string>& chat,
						  const CommandCallback& callback) {
	pisex::RegCommand(console, chat, callback);
}

void UtilsApi::AddChatListenerPre(const CommandCallbackPre& callback) {
	pisex::AddChatListenerPre(callback);
}

void UtilsApi::HookEvent(const char* sName, const EventCallback& callback) {
	pisex::HookEvent(sName, callback);
}

// --- UtilsApi: timers ------------------------------------------------------------------------

CTimer* UtilsApi::CreateTimer(float flInterval, std::function<float()> func) {
	return pisex::CreateTimer(flInterval, std::move(func));
}

void UtilsApi::RemoveTimer(CTimer* timer) {
	pisex::RemoveTimer(timer);
}

void UtilsApi::NextFrame(std::function<void()> fn) {
	pisex::NextFrame(std::move(fn));
}

// --- UtilsApi: lifecycle ---------------------------------------------------------------------

void UtilsApi::StartupServer(StartupCallback fn) {
	RegisterStartupCallback(std::move(fn));
}

void UtilsApi::MapStartHook(MapStartCallback fn) {
	RegisterMapStartCallback(std::move(fn));
}

void UtilsApi::MapEndHook(StartupCallback fn) {
	RegisterMapEndCallback(std::move(fn));
}

void UtilsApi::LoadTranslations(const char* file) {
	pisex::LoadPhrases(file);
}

const char* UtilsApi::GetLanguage() {
	return PhrasesLanguage().c_str();
}

const char* UtilsApi::GetVersion() {
	return "1.0.0-pisexcompat";
}

GlobalVars* UtilsApi::GetCGlobalVars() {
	return pisex::GetCGlobalVars();
}

void* UtilsApi::GetCGameEntitySystem() {
	return nullptr;
}

void* UtilsApi::GetCEntitySystem() {
	return nullptr;
}

std::string UtilsApi::Colorize(const std::string& text) {
	return pisex::Colorize(text);
}

// --- MenusApi --------------------------------------------------------------------------------

void MenusApi::AddItemMenu(Menu& hMenu, const char* sBack, const char* sText, int iType) {
	pisex::AddItemMenu(hMenu, sBack, sText, iType);
}

void MenusApi::AddRawItemMenu(Menu& hMenu, const char* sBack, const char* sText, int iType) {
	pisex::AddRawItemMenu(hMenu, sBack, sText, iType);
}

void MenusApi::SetTitleMenu(Menu& hMenu, const char* szTitle) {
	pisex::SetTitleMenu(hMenu, szTitle);
}

void MenusApi::SetExitMenu(Menu& hMenu, bool bExit) {
	pisex::SetExitMenu(hMenu, bExit);
}

void MenusApi::SetBackMenu(Menu& hMenu, bool bBack) {
	pisex::SetBackMenu(hMenu, bBack);
}

void MenusApi::SetCallback(Menu& hMenu, MenuCallbackFunc func) {
	pisex::SetCallback(hMenu, std::move(func));
}

void MenusApi::SetDescriptionMenu(Menu& hMenu, const char* szDescription) {
	pisex::SetDescriptionMenu(hMenu, szDescription);
}

void MenusApi::DisplayPlayerMenu(Menu& hMenu, int iSlot, bool bClose) {
	pisex::DisplayPlayerMenu(hMenu, iSlot, bClose);
}

void MenusApi::DisplayPlayerMenu(Menu& hMenu, int iSlot, bool bClose, bool bReset) {
	pisex::DisplayPlayerMenu(hMenu, iSlot, bClose, bReset);
}

void MenusApi::ClosePlayerMenu(int iSlot) {
	pisex::ClosePlayerMenu(iSlot);
}

bool MenusApi::IsMenuOpen(int iSlot) {
	return pisex::IsMenuOpen(iSlot);
}

std::string MenusApi::escapeString(const std::string& input) {
	return pisex::escapeString(input);
}

MenuType MenusApi::GetMenuType(int iSlot) {
	return pisex::GetMenuType(iSlot);
}

void MenusApi::SetMenuType(int iSlot, MenuType type) {
	pisex::SetMenuType(iSlot, type);
}

void MenusApi::SetMenuTimeout(int iSeconds) {
	pisex::SetMenuTimeout(iSeconds);
}

// --- PlayersApi ------------------------------------------------------------------------------

bool PlayersApi::IsFakeClient(int iSlot) {
	return pisex::IsFakeClient(iSlot);
}

bool PlayersApi::IsConnected(int iSlot) {
	return pisex::IsConnected(iSlot);
}

bool PlayersApi::IsInGame(int iSlot) {
	return pisex::IsInGame(iSlot);
}

bool PlayersApi::IsAuthenticated(int iSlot) {
	return pisex::IsAuthenticated(iSlot);
}

bool PlayersApi::IsAlive(int iSlot) {
	return pisex::IsAlive(iSlot);
}

void PlayersApi::HookOnClientAuthorized(const OnClientAuthorizedCallback& callback) {
	pisex::HookOnClientAuthorized(callback);
}

uint64_t PlayersApi::GetSteamID64(int iSlot) {
	return pisex::GetSteamID64(iSlot);
}

const char* PlayersApi::GetSteamID(int iSlot) {
	return pisex::GetSteamID(iSlot);
}

const char* PlayersApi::GetIpAddress(int iSlot) {
	return pisex::GetIpAddress(iSlot);
}

const char* PlayersApi::GetPlayerName(int iSlot) {
	return pisex::GetPlayerName(iSlot);
}

void PlayersApi::SetPlayerName(int iSlot, const char* szName) {
	pisex::SetPlayerName(iSlot, szName);
}

const char* PlayersApi::GetClientLanguage(int iSlot) {
	return pisex::GetClientLanguage(iSlot);
}

int PlayersApi::FindPlayer(uint64_t iSteamID64) {
	return pisex::FindPlayer(iSteamID64);
}

int PlayersApi::FindPlayer(const char* szName) {
	return pisex::FindPlayer(szName);
}

int PlayersApi::GetHealth(int iSlot) {
	return pisex::GetPlayerHealth(iSlot);
}

int PlayersApi::GetArmor(int iSlot) {
	return pisex::GetPlayerArmor(iSlot);
}

int PlayersApi::GetMoney(int iSlot) {
	return pisex::GetPlayerMoney(iSlot);
}

int PlayersApi::GetTeam(int iSlot) {
	return pisex::GetPlayerTeam(iSlot);
}

void PlayersApi::ChangeTeam(int iSlot, int iNewTeam) {
	pisex::ChangeTeam(iSlot, iNewTeam);
}

void PlayersApi::SwitchTeam(int iSlot, int iNewTeam) {
	pisex::SwitchTeam(iSlot, iNewTeam);
}

void PlayersApi::Respawn(int iSlot) {
	pisex::Respawn(iSlot);
}

void PlayersApi::CommitSuicide(int iSlot, bool bExplode, bool bForce) {
	pisex::CommitSuicide(iSlot, bExplode, bForce);
}

void PlayersApi::SetMoveType(int iSlot, int moveType) {
	pisex::SetMoveType(iSlot, moveType);
}

void PlayersApi::RemoveWeapons(int iSlot) {
	pisex::RemoveWeapons(iSlot);
}

} // namespace pisex
