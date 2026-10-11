// pisexcompat — umbrella header.
//
//   #include <pisex/pisex.hpp>   // everything + the g_pUtils/g_pMenus/g_pPlayers globals
//
// Usage from a ported plugin:
//
//   plg::PluginResult OnPluginStart() {
//       pisex::Init("admin_system");     // dirs + s2sdk listeners; never fails hard
//       ...register commands/timers...    // safe pre-map: nothing touches clients here
//       return plg::PluginResult::Success;
//   }
//   plg::PluginResult OnPluginUpdate(std::chrono::milliseconds) { pisex::Poll(); return {}; }
//   plg::PluginResult OnPluginEnd() { pisex::Shutdown(); return {}; }
//
// See README.md for the inventory of the emulated Pisex API and for the deliberate differences.

#pragma once

#include <pisex/api.hpp>
#include <pisex/commands.hpp>
#include <pisex/compat.hpp>
#include <pisex/events.hpp>
#include <pisex/keyvalues.hpp>
#include <pisex/menu.hpp>
#include <pisex/output.hpp>
#include <pisex/paths.hpp>
#include <pisex/phrases.hpp>
#include <pisex/players.hpp>
#include <pisex/schema.hpp>
#include <pisex/timers.hpp>
