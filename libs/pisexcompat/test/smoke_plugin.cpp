// pisexcompat smoke plugin — a minimal Plugify plugin that uses pisexcompat the way a ported
// Pisex plugin does, built as a real shared object by ./build.sh so that the integration points
// are checked by the normal build gates:
//   * the static library links into a plugin (.so) and pulls in the s2sdk binding globals,
//   * PLUGIFY_PLUGIN (the plugin's own plg::* globals) and the library's references to them agree,
//   * the ABI report for a plugin that uses pisexcompat stays inside GLIBC 2.31 with no
//     libstdc++/libmariadb NEEDED entries.
//
// It is part of the build on purpose and is not meant to be installed (see
// libs/pisexcompat/CMakeLists.txt). The handler bodies are the porting template: Init in
// OnPluginStart, Poll in OnPluginUpdate, Shutdown in OnPluginEnd.

#include <plg/plugin.hpp>
#include <plg/string.hpp>
#include <plugin_export.h>

#include <pisex/pisex.hpp>

#include <cstdint>
#include <string>

namespace {

class SmokePlugin final : public plg::Plugin {
public:
	plg::PluginResult OnPluginStart() override {
		// Never returns Failed: that stops every plugify plugin on the server.
		pisex::Init("pisexcompat_smoke");
		pisex::g_pUtils->StartupServer([] { pisex::g_pUtils->PrintToConsole(-1, "startup"); });
		pisex::g_pUtils->RegCommand({"pix_smoke"}, {"!smoke"}, [](int iSlot, const char* content) {
			pisex::CommandArgs args;
			args.Tokenize(content);
			pisex::g_pUtils->PrintToChat(iSlot, "%s from %s", args.Arg(0) ? args.Arg(0) : "", "smoke");
			return true;
		});
		pisex::g_pUtils->HookEvent("player_death", [](const char* name, pisex::IGameEvent* event, bool broadcast) {
			(void)name;
			(void)broadcast;
			pisex::g_pUtils->PrintToConsole(event->GetPlayerSlot("userid"), "died");
		});
		pisex::g_pUtils->CreateTimer(5.0f, [] {
			return -1.0f; // stop after the first run
		});
		return plg::PluginResult{};
	}

	plg::PluginResult OnPluginUpdate(std::chrono::milliseconds) override {
		pisex::Poll();
		return plg::PluginResult{};
	}

	plg::PluginResult OnPluginEnd() override {
		pisex::Shutdown();
		return plg::PluginResult{};
	}
};

SmokePlugin g_smokePlugin;

} // namespace

PLUGIFY_PLUGIN(PLUGIN_API, &g_smokePlugin)
