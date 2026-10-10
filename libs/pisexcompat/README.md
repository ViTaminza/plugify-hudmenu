# pisexcompat — the Pisex utils/menus/players API on top of s2sdk

A static library that re-creates the parts of the Pisex "utils" (`IUtilsApi`), "menus"
(`IMenusApi`) and "players" (`IPlayersApi`) APIs that the Pisex admin core and its 17
modules actually call, so that porting one of them is a near-mechanical edit:

```cpp
#include <pisex/pisex.hpp>
using namespace pisex;                 // g_pUtils / g_pMenus / g_pPlayers

plg::PluginResult OnPluginStart() {
    pisex::Init("admin_system");       // dirs + s2sdk listeners; never fails hard
    g_pUtils->StartupServer(StartupServer);   // runs on the first update with a map
    return plg::PluginResult::Success; // never Failed: that stops every plugify plugin
}
plg::PluginResult OnPluginUpdate(std::chrono::milliseconds) { pisex::Poll(); return plg::PluginResult::Continue; }
plg::PluginResult OnPluginEnd() { pisex::Shutdown(); return plg::PluginResult::Success; }
```

Everything runs on the game thread. No exception escapes into s2sdk callbacks (all of them are
wrapped), and nothing touches a client before a map exists — see *Safety* below.

Files: `src/*.cpp`, `include/pisex/*.hpp`. Tests: `tests/pisexcompat_tests.cpp` (`./test.sh`).

---

## 1. Inventory: which Pisex methods are used, and how often

Counted over the Pisex admin core and its modules (`g_pUtils*`,
`g_pMenus*`, `g_pPlayers*`, including the `…Api` aliases the modules use). "Status" says what
pisexcompat does with it.

### IUtilsApi (`g_pUtils->`)

| Calls | Method | Status in pisexcompat |
|---:|---|---|
| 118 | `PrintToChat(slot, fmt, ...)` | `pisex::PrintToChat` — colour tags, HUD_PRINTTALK |
| 70 | `PrintToConsole(slot, fmt, ...)` | `pisex::PrintToConsole` — negative slot → server console |
| 63 | `ErrorLog(fmt, ...)` | `pisex::ErrorLog` — plugify log + `<logs>/error_MM-DD-YYYY.txt` |
| 56 | `PrintToChatAll(fmt, ...)` | `pisex::PrintToChatAll` |
| 38 | `RegCommand(console, chat, cb)` | `pisex::RegCommand` (plugin id dropped) |
| 18 | `GetCGlobalVars()` | `GetCGlobalVars()` — snapshot struct, refreshed every `Poll()` |
| 18 | `GetCGameEntitySystem()` | returns `nullptr` (no engine layout in s2sdk) — use `pisex/schema.hpp` |
| 18 | `GetCEntitySystem()` | returns `nullptr` (same) |
| 17 | `StartupServer(fn)` | deferred to the first `Poll()` (map up) |
| 14 | `CreateTimer(fl, fn)` | `CreateTimer` over s2sdk timers, return value = next delay |
| 7 | `SetStateChanged(ent, cls, field)` | `pisex::SetStateChanged` (schema network update) |
| 4 | `HookEvent(name, cb)` | `pisex::HookEvent` (s2sdk pre hook) |
| 3 | `TeleportEntity(ent, …)` | not covered — entity work, use s2sdk `TeleportClient`/entity functions |
| 3 | `RemoveEntity(ent)` | not covered — use s2sdk `RemoveEntity` |
| 2 | `PrintToCenter(slot, fmt, …)` | `pisex::PrintToCenter` |
| 2 | `AddChatListenerPre(cb)` | `pisex::AddChatListenerPre` (see the chat caveat in §4) |
| 1 | `PrintToCenterAll`, `PrintToAlert`, `NextFrame`, `LoadTranslations`, `GetLanguage` | all covered |
| 1 | `HookIsHearingClient(cb)` | not covered (voice hook, polyhook territory) |
| 1 | `DispatchSpawn`, `CreateEntityByName`, `AcceptEntityInput` | not covered — s2sdk entity functions |

Modelled but unused by the admin core (kept because cs2-menus exposes them and modules may grow):
`PrintToConsoleAll`, `PrintToCenterHtml{All}`, `PrintToAlertAll`, `LogToFile`, `MapStartHook`,
`MapEndHook`, `RemoveTimer`, `GetVersion`.

### IMenusApi (`g_pMenus->`)

| Calls | Method | Status |
|---:|---|---|
| 133 | `AddItemMenu(menu, back, text, iType)` | `pisex::AddItemMenu` (ITEM_HIDE dropped, ITEM_DISABLED → s2sdk Disabled) |
| 40 | `SetTitleMenu` | covered |
| 40 | `SetExitMenu` | covered → s2sdk exit button (digit 0 / cancel reason Exit) |
| 40 | `DisplayPlayerMenu(menu, slot[, bClose[, bReset]])` | covered (both overloads) |
| 38 | `SetCallback(menu, fn)` | covered — `std::function` kept on our side, keyed per slot |
| 36 | `SetBackMenu` | covered → s2sdk exit-back button (cancel reason ExitBack) |
| 11 | `ClosePlayerMenu(slot)` | covered (no callback, like Pisex) |
| 5 | `escapeString(str)` | covered — byte-identical to cs2-menus |

Not covered (Panorama-only in Pisex): `AddToggleMenu`, `AddSelectMenu`, `AddSelectOption`,
`SetToggleState`/`GetToggleState`, `SetSelectedOption`, `AddSelectMenu` item refs, `ItemKind`
rendering, `SetDescriptionMenu` (stored, never rendered), `AddRawItemMenu` (covered).

**Menu type selection** (`GetMenuType`/`SetMenuType`): each displayed menu resolves its s2sdk
type through `pisex::ResolveS2sdkMenuTypeName` — an explicit `SetMenuType(slot, ...)` override
wins; otherwise, when the hudmenu plugin is installed, its exported `GetClientMenuType(slot)`
(the player's own `!menu` choice from the permissions cookie `Utils.MenuType`, Pisex numbering)
decides; without hudmenu the slot's Pisex `MenuType` is mapped: `HUD_LAYOUT` → `hud` and
`CENTER_WASD` → `wasd` when the matching hudmenu backend is registered, else `button` (or
`chat`/`centerhtml` for the digit types). `SetDefaultMenuType` resets every slot (and clears the
overrides, like the Pisex original that replaced the whole table); `IsMenuTypeForced(slot)`
reports whether a slot carries an override.

### IPlayersApi (`g_pPlayers->`)

| Calls | Method | Status |
|---:|---|---|
| 124 | `GetPlayerName(slot)` | covered (per-slot cache, stable pointer) |
| 37 | `GetSteamID64(slot)` | covered |
| 18 | `IsConnected(slot)` | covered |
| 17 | `IsFakeClient(slot)` | covered |
| 14 | `IsInGame(slot)` | covered |
| 6 | `HookOnClientAuthorized(cb)` | covered (s2sdk `OnClientAuthenticated`) |
| 6 | `CommitSuicide(slot, explode, force)` | covered |
| 6 | `ChangeTeam(slot, team)` | covered |
| 4 | `SetPlayerName(nick)` | covered |
| 4 | `SetMoveType(slot, type)` | covered |
| 4 | `FindPlayer(steamid)` / `FindPlayer(name)` | covered (name: exact then substring) |
| 1 | `SwitchTeam`, `IsAuthenticated` | covered |

Extras in the same header that modules will want next: `IsAlive`, `GetIpAddress`, `GetSteamID`,
`GetClientLanguage`, `GetHealth/Armor/Money/Team`, `Respawn`, `RemoveWeapons`, `Teleport`,
`GetPawnEntity`, `GetControllerEntity`, `GetOwnerSlot`, `GetMaxPlayers`.

Not covered: `SetConVar*` (fake client cvars), `EmitSound`/`StopSoundEvent`, `RayTrace`,
`TakeDamage`, `DropWeapon`, `GetLegacyGameEventListener`, `UseClientCommand`, `AddListener`
(no listener-object API — register s2sdk listeners directly).

---

## 2. Headers and functions

| Header | What it gives you |
|---|---|
| `pisex/pisex.hpp` | umbrella: everything below, plus `g_pUtils` / `g_pMenus` / `g_pPlayers` |
| `pisex/compat.hpp` | `Init`, `Shutdown`, `Poll`, `IsGameReady`, `CurrentMap`, `GlobalVars`, `GetCGlobalVars` |
| `pisex/keyvalues.hpp` | `KeyValues` (KV1 parser), `KeyValues::AutoDelete`, `FOR_EACH_SUBKEY`/`FOR_EACH_VALUE` |
| `pisex/phrases.hpp` | `Colorize`, `LoadPhrasesFile`, `LoadPhrases`, `g_translations`, `GetPhrase[CStr]`, `PhrasesLanguage`, `SetPhrasesLanguage`, `NormalizeLanguage` |
| `pisex/output.hpp` | `PrintToChat[CAll]`, `PrintToConsole[All]`, `PrintToCenter[All]`, `PrintToCenterHtml[All]`, `PrintToAlert[All]`, `LogToFile`, `ErrorLog`, `FormatString`, `PrintToChatRaw` |
| `pisex/commands.hpp` | `RegCommand`, `RegServerCommand` (server console only), `AddChatListenerPre`, `AddChatTrigger`, `IsChatTrigger`, `RefreshChatTriggers`, `CommandArgs` (CCommand stand-in) |
| `pisex/menu.hpp` | `Menu`, `Items`, `MenuType`, `AddItemMenu`, `AddRawItemMenu`, `SetTitle/Exit/Back/Callback/DescriptionMenu`, `DisplayPlayerMenu`, `ClosePlayerMenu`, `CloseAllMenus`, `IsMenuOpen`, `escapeString`, `Get/SetMenuType`, `SetDefaultMenuType`, `IsMenuTypeForced`, `ResolveS2sdkMenuTypeName`, `Set/GetMenuTimeout` |
| `pisex/timers.hpp` | `CTimer`, `CreateTimer`, `RemoveTimer`, `NextFrame` |
| `pisex/events.hpp` | `IGameEvent` (`GetInt/GetString/GetFloat/GetBool/GetUInt64/GetPlayerSlot` + setters), `HookEvent`, `UnhookEvent` |
| `pisex/players.hpp` | the `IPlayersApi` wrappers listed above + `HookOnClientAuthorized` |
| `pisex/schema.hpp` | `SchemaOffset`, `IsValidEntity`, `EntIndexToEntPointer`/`…PointerToEntIndex`/`…Handle`, `GetEntityClassname`, `GetEntInt/Float/Bool/String/Vector/Color/Entity`, `SetEnt*`, `SetStateChanged`, `FindEntityByClassname`, `GetPlayerPawn`, `GetPlayerController`, `GetPawnController` |
| `pisex/paths.hpp` | `SetPluginName`, `SetConfigDir`, `SetTranslationsDir`, `ConfigDir`, `TranslationsDir`, `DataDir`, `JoinPath`, `FileExists`, `ReadFile`, `ResolvePath`, `ResolveTranslationsPath`, `ResolveDataPath` |
| `pisex/api.hpp` | `UtilsApi`, `MenusApi`, `PlayersApi` (the `g_p*` objects) |

`pisex::Init(name)` sets `<configs>/<name>` (and `<configs>/<name>/translations`) as the base
dirs; the resolvers also strip the Metamod spellings (`addons/configs/<x>/…`,
`addons/translations/…`, `addons/data/…`), so ported loaders keep their old paths.

One-line-per-function reference of the free functions (the `*Api` methods are thin forwarders):
see the header comments — every declaration carries a doc comment explaining the Pisex semantics
it preserves.

---

## 3. How the s2sdk side is wired (verified against `libplugify-plugin-s2sdk.so`)

* **Chat commands** — `ConCommandManager::DispatchConCommand` special-cases `say`/`say_team`: a
  first argument starting with a trigger from the s2sdk settings (`PublicChatTrigger` `"!"`,
  `SilentChatTrigger` `"/"`) is stripped, the rest tokenised and dispatched as a *command* with
  `ConCommandContext::Chat`; a silent-trigger message (or one whose handler returns
  `Handled`/`Stop`) is then not broadcast. `args[0]` is the command name, `caller` is `-1` for the
  server console.
  `RegCommand` therefore strips the trigger from the chat names and registers the bare name via
  `AddConsoleCommand`; a console name is only dispatched for console input and a chat name only
  for chat input (like Pisex). `RegServerCommand` registers a console name the same way but
  without `ClientCanExecute` (the Metamod `CON_COMMAND_F(..., FCVAR_NONE)` behaviour): a call from
  any caller slot is swallowed before the callback runs. The callback receives the
  **registered spelling** as `arg[0]`
  (`"!ban 3 60"`, `"mm_admin"`) plus the arguments, space-joined — so ported handlers that
  `Tokenize()` the content and compare `arg[0]` keep working unchanged.
* **Menus** — `MenuHandlerCallback` is a plain function pointer called as
  `(MenuId, MenuAction, playerSlot, param)`: `Select` passes the 0-based item index, `Cancel`
  passes the `MenuCancelReason`, then `End` follows. pisexcompat keeps the `std::function`
  callback and the item list on its side, keyed by the slot, and translates:
  `Select` → Pisex item number `index - GetClientMenuOffset(slot) + 1` (1..5, page size set to 5
  with `SetMenuPagination`), `Cancel(Exit)` → `("exit","exit",9)`, `Cancel(ExitBack)` →
  `("back","back",7)`; timeouts/disconnects drop the menu without calling back (Pisex's own
  behaviour). s2sdk's page turn (digits 8/9) is handled by its backend and does **not** call the
  Pisex callback (Pisex notified `("next","next",8)`/`("back","back",7)` for those).
  **Destroying the menu is our job**: the menus guide ("always destroy your menus … call
  `DestroyMenu(id)` from your handler's `End` case — otherwise every menu you display leaks for
  the lifetime of the plugin") and s2sdk's `EndClientMenu()` (which only clears the client state)
  make a display that ends on its own — exit button, timeout (default 60 s), disconnect — leak its
  `MenuData` for the process lifetime unless we destroy it. Since `DestroyMenu` from inside the handler
  would re-enter the handler (Cancel + End for every viewer while the outer call is still on the
  stack), `Cancel`/`End` only *queue* the id (`QueueMenuDestroy`); `Poll()` →
  `ProcessMenuRequests()` calls `s2sdk::DestroyMenu` outside the lock, exactly once per session
  (Cancel and End both report the same end and are deduped), and only when no other client still
  displays that id (s2sdk menus are shared objects — such an id stays queued and is re-checked, it
  is not dropped). A display that s2sdk refused, and a menu created before an exception, are
  destroyed on the spot. `CloseAllMenus()` (map end / `Shutdown()`) destroys the open *and* the
  queued ids, so `plg reload` leaves neither `MenuData` nor handlers pointing into unloaded code.
* **Timers** — created with `TimerFlag::Repeat`, delayed/rescheduled from `Poll()`. The engine's
  `TimerSystem::RunFrame` invokes the callback while holding its own lock and is not re-entrant,
  so the callback only *records* the delay the Pisex function returned; `Poll()` then calls
  `RescheduleTimer` (or `KillsTimer` for a negative return). A timer that is waiting for that
  reschedule ignores further fires, so a callback never runs twice in one frame.
  **Every delay handed to s2sdk is floored at one server tick** (`pisex::kMinTimerDelay`, 1/64 s,
  see `ClampTimerDelay` in `pisex/timers.hpp`) — at creation *and* on every reschedule. The s2sdk
  backend re-inserts a repeating timer at `universalTime + stored delay` inside a `while` loop, so
  a stored 0 makes it run the callback forever within a single frame ("Server took too long to
  process" FATAL); Pisex's "return 0 = next frame" therefore
  becomes one tick. s2sdk's timer ids start at 0, and id 0 is tracked/killed like any other (the
  "id != 0" guard the old code had broke the first timer of the process). A callback that returns
  a negative value stops the timer: `Poll()` kills the engine timer, so no engine-side zombie
  remains. `RemoveTimer()` is legal from inside the timer's own callback — the object is freed
  after the callback returns, not while it is on the stack. **While no map is up the callback is
  not called at all**: the fire is marked postponed, further engine fires are ignored, and the
  timer is re-armed with one tick on the first ready frame (so the callback runs as early as the
  engine can again, but with a live map). The delay the callback returns then governs the
  following runs, exactly like Pisex's semantics.
  *Map end, checked in cs2-menus:* there is no map-end timer cleanup there at all (the plugin
  clears its menu state per slot, the `g_timers` vector keeps running across map changes) —
  and the admin core's one-second timer that expires punishments/admins relies on that. So
  pisexcompat also leaves timers running across maps (s2sdk's `TimerFlag::NoMapChange` is
  deliberately **not** set) and only `Shutdown()` kills them. `RemoveTimer` on an already-dead
  handle is a safe no-op (Pisex freed the object, so ported cleanup code calls it on dead handles).
* **Events** — `HookEvent(..., HookMode::Pre)` (the engine's pre-fire point, which is where
  cs2-menus' `FireEvent` SourceHook called the plugins). One trampoline fans out by event name.
* **Chat listeners** — `AddCommandListener("say"/"say_team", …, Pre)`.
* **NextFrame** — drained by `Poll()` instead of `QueueTaskForNextFrame`, and only while a map is
  up (a "next frame" during a map change would be a ready frame, like the postponed timers): the
  callback is a
  `std::function` that cannot cross the `plg::vector<plg::any>` boundary of an s2sdk task, and
  the plugin already has one per-frame pump (`OnPluginUpdate`) where its deferred work runs in a
  predictable order (next-frame callbacks first, then timer reschedules, then queued menu
  changes). The practical timing is the same as Pisex's own queue (`Menus::GameFrame`).
* **Map lifecycle** — `OnMapStart`/`OnMapEnd` s2sdk listeners drive `IsGameReady()`. It is false
  from the map end until the **next map start** (`Poll()` alone is not enough: the host can pump
  updates throughout a changelevel), so the whole [map end, next map start] window answers
  defaults. Map-start callbacks run from the first ready `Poll()` after the map starts (so client
  queries inside them are safe); map end only drops our own state (no s2sdk client/entity call
  from a map-end callback). A plugin that was loaded into an already running map (no map end
  seen yet) becomes ready on its first update - the host pumps `OnPluginUpdate` from
  `ServerPostSimulate`, which only runs with a map up. While not ready: timers and `NextFrame`
  callbacks are **postponed** to the first ready frame (see below), events are still delivered
  (data only) but every client/entity lookup they make answers a default.

## 4. Safety rules this library enforces

* **No client query before a map (or during a map change)** — `pisex::IsGameReady()` is false
  until the first ready `Poll()` and again from every `OnMapEnd` until the next `OnMapStart`.
  Every player wrapper and every printer checks it, so a plugin that calls
  `g_pPlayers->GetSteamID64(i)` in `OnPluginStart` gets `0` instead of a dead server, and a timer
  that fires during a map change cannot touch a stale slot. `StartupServer`/`MapStartHook`
  callbacks are deferred for the same reason. s2sdk's client list is *gone* in that window:
  `utils::GetClientBySlot` reads the half-destroyed server and segfaults at address 0 (a crash seen
  in a ported plugin's MapEnd handler), and `Player::SetName` (SetClientName) dereferences a null
  client and a null controller (a crash seen right after a map start), so pisexcompat makes no
  s2sdk client call at all then.
* **Every player wrapper validates the slot** — beyond the map gate they use
  `pisex::IsClientReady(slot)` (public helper): slot in range, `IsClientConnected`, and the
  controller entity exists. `SetPlayerName`/`GetPlayerName` require the controller (the crash
  above); `GetIpAddress` additionally refuses fake clients (`Player::GetIpAddress` dereferences a
  net channel that bots do not have); `GetSteamID64`/`GetSteamID` answer `0`/`""` for a slot
  without a client instead of s2sdk's stale `m_unauthenticatedSteamID`; the pawn/controller
  accessors (`GetPlayerHealth`, `GetPlayerTeam`, `Teleport`, `ChangeTeam`, …) are only called for
  a slot that passes the guard, which also removes their "invalid player slot" log spam. s2sdk's
  `"<unknown>"` name placeholder becomes an empty string, like the Pisex API returned.
* **No entity query before a map either** — every `pisex/schema.hpp` accessor (and
  `FindEntityByClassname`, `DisplayPlayerMenu`) checks `IsGameReady()` as well. s2sdk's entity
  exports dereference `g_pGameEntitySystem` (and the menu path `gpGlobals`) without a null check;
  s2sdk only fills them in on server start, so a pre-map call is a null dereference, i.e. a dead
  server. Before the first map there are no entities to query, so the wrappers return their
  defaults.
* **Schema access stays off the map-start path** (porting rule, not enforced): s2sdk's *typed*
  schema calls can dereference an invalid `CSchemaType*` (-1) for a class whose schema table the
  engine built around a map load; the first typed access of that class, one frame after the map
  load, crashes. Use `pisex::SchemaOffset()` + s2sdk's raw
  `GetEntData2`/`SetEntData2` with the field's real width (as `plugins/fortnite_emotes` does) for
  anything on that path. `pisex::SchemaChainOffset()` normalises "no chainer"/"no binding" to -1
  (never 0, which s2sdk would read as a real chain offset).
* **No exceptions across the boundary** — every s2sdk callback (`CommandTrampoline`,
  `ChatTrampoline`, `MenuHandlerTrampoline`, `EventTrampoline`, timer/next-frame/map/startup/
  callback paths) catches everything and logs through `ErrorLog`.
* **No blocking work on the game thread** — the library never opens a network connection; the
  only I/O is config/phrase reads (which the plugins do at startup) and log appends.
* **Missing bindings degrade to no-ops** — every entry point checks the `__s2sdk_*` pointer
  before calling it, so a server without the s2sdk plugin (or an older one) logs once and keeps
  running.

## 5. Deliberate differences from the Metamod originals (porting notes)

1. **`PluginId` parameters are gone** (`RegCommand`, `StartupServer`, `HookEvent`, …); the
   library owns every registration and drops them all in `Shutdown()`.
2. **Item texts are not escaped.** cs2-menus escapes item text because its Panorama layout is
   XML/printf-formatted; the s2sdk backends take plain text. Porting note: drop
   `g_pMenus->escapeString(...)` around item texts, or the client sees `&lt;` and `%%`.
3. **Page turns don't notify the callback** (see §3); `("back"/"next"/…)` notifications with
   `iItem == 8` are gone, `7` (exit-back) and `9` (exit) remain.
4. **Chat listeners** see every `say`/`say_team` message *except* the ones s2sdk consumes: a
   silent-trigger message, or a chat command whose handler returned `true` (handled). Pisex's
   listeners saw those too. `AddChatListenerPost` does not exist (it needs cs2-menus' own mute
   flag).
5. **`GetCGameEntitySystem()`/`GetCEntitySystem()` return `nullptr`** — s2sdk has no engine
   entity-system object; use `pisex/schema.hpp` / the s2sdk entity functions.
6. **`GetCGlobalVars()` returns a snapshot** refreshed at the start of every `Poll()` (up to one
   frame old) instead of a live engine pointer.
7. **Timers**: same semantics (return value = next delay, negative = stop) but rescheduling
   happens in `Poll()` (≤ one frame later, no double-run), and s2sdk's `TimerFlag::NoMapChange`
   is deliberately not set so timers behave like the Pisex ones across map changes.
8. **`GetTranslation`-style fallback**: `LoadPhrasesFile` resolves each key for the selected
   language, then `"en"`, then any language present. Pisex read `GetString(language)` with no
   fallback (an untranslated key printed an empty line).
9. **Language codes**: the s2sdk server language (`GetServerLanguage`) is normalised
   (`russian`→`ru`, `portuguese`→`pt-BR`, …); override with `pisex::SetPhrasesLanguage("ru")` if
   the server is configured differently.
10. **`KeyValues::LoadFromFile` takes one argument** (the engine filesystem is gone) and the path
    is resolved as described in §2. The parser is KV1 only (no `.kv3`, no `#include` expansion —
    `#base`/`#include`/`#define` lines are skipped).
11. **`RemoveTimer` on a dead handle is safe** (see §3); `CTimer` objects are freed when the
    timer stops.
12. **`escapeString` keeps its Pisex behaviour** (it is still used for Panorama leftovers), but
    `AddItemMenu` no longer calls it (difference 2).
13. **`%llu` must become `%lu` for steam ids.** Metamod's `uint64` is `unsigned long long`; on
    Linux/glibc `uint64_t` is `unsigned long`, so a ported `PrintToChat(slot, "%llu", steamid64)`
    is a format/argument-size mismatch — undefined behaviour in the engine's printf, and a
    `-Wformat` error with the attributes the printers carry. Use `%lu` (or cast to
    `unsigned long long` and keep `%llu`). Same for `std::to_string`.
14. **`CCommand` is gone**: the handlers that split the callback content use `pisex::CommandArgs`
    (`Tokenize`/`ArgC`/`Arg`/`ArgS`/`operator[]`, same behaviour for the admin core's usage).
15. **Menu changes made from inside a menu callback are applied one frame later** (the engine calls
    handlers while holding the menu manager's lock, so `DisplayPlayerMenu`/`ClosePlayerMenu` from a
    callback are queued and run from `Poll()`); global menu state (`IsMenuOpen`, the new menu's
    contents) therefore updates on the next frame, not inside the callback. The item number is
    derived from the item index modulo the page size (5), so it matches Pisex's 1..5 without any
    engine query inside the handler.
16. **Player values for slots without a client are the API defaults, never s2sdk's stale ones**:
    `GetPlayerName` is `""` (s2sdk says `"<unknown>"`), `GetSteamID64`/`GetSteamID` are `0`/`""`
    (s2sdk would answer the *previous* occupant's unauthenticated id), `GetIpAddress` is `""` for
    bots (s2sdk has no net channel for them). Metamod's originals could answer for a connecting
    client as well; the difference only shows in that transient state.
17. **The map-change window is a "no client/entity code" gap**: from `OnMapEnd` until the next
    `OnMapStart` (plus the update that follows it) `IsGameReady()` is false, timers/`NextFrame` are
    postponed to the first ready frame, and events keep being delivered (data only) with every
    client/entity lookup they make answering defaults. Plugins that cache a slot/entity across the
    gap must re-validate (see `IsClientReady`/`IsValidEntity`); the Pisex originals had no such
    window because Metamod kept its client objects alive through a changelevel.

## 6. Not covered at all (port these to s2sdk directly)

Entity work (`CreateEntityByName`, `DispatchSpawn`, `AcceptEntityInput`, `TeleportEntity`,
`RemoveEntity`, `SetEntityModel`), `SetTransmitState`, damage/voice/CanAcquire hooks
(`HookOnTakeDamage*`, `HookIsHearingClient`, `AddCanAcquire*`), Panorama/HUD-layout menus
(toggles, selects, `SetDescriptionMenu` rendering), notifications (`ShowNotify*`), settings menu
hooks, `TerminateRound`, `AddPrecache`, `AddServerListener`/`AddEntityListener`,
`ShowAdminLastCategoryMenu`-style APIs from other Pisex plugins (VIP/LR/Shop APIs are different
libraries, not part of this one), players' `SetConVar*`/sound/`RayTrace`/`TakeDamage`,
`AddListener` listener objects, and the schema-typed entity accessors of `SchemaEntity`.
Everything in that list is a normal s2sdk call or a small helper on top of s2sdk; nothing here
needs Metamod.

## 7. Integration check

`test/smoke_plugin.cpp` is built as a real plugin `.so` (`libpisexcompat_smoke.so`) by
`./build.sh`: it uses Init/Poll/Shutdown, a command with `CommandArgs`, an event hook and a timer
exactly like a ported plugin. It is not packaged; it exists so that the normal build gates cover a
*consumer* of the library — the ABI report shows `max GLIBC_2.25`, `NEEDED: libc, ld-linux` (no
libstdc++/libmariadb), and all 1062 `__s2sdk_*` binding globals plus `Plugify_PluginInit` are
exported from the plugin as the plugify module expects.

## 8. Tests

`tests/pisexcompat_tests.cpp` (run by `./test.sh`) covers the engine-free parts, 210 checks:
KeyValues parsing of the real admin-system `.ini` config files (including the
`flags`/`times_reasons`/`default_permissions` shapes and the malformed-input rejection), phrase
loading with language fallback, the colour table byte-for-byte against cs2-menus, menu builder
bookkeeping (ITEM_HIDE dropped, callback/title/flags/clear, no crash without an engine), path
resolution (incl. the Metamod spellings), `FormatString` and the timer-delay clamp
(`ClampTimerDelay`: 0/negative/sub-tick/NaN all floor to `kMinTimerDelay`).

`libs/pisexcompat/test/timers_engine_test.cpp` (built as `build/tests/pisexcompat_timers_tests`)
drives the *real* timer registry with fake s2sdk timer bindings: the fake s2sdk
`CreateTimer`/`RescheduleTimer`/`KillsTimer` record what the library does, and the test fires the
recorded callback exactly like `TimerSystem::RunFrame()` would. It covers that crash and the
bookkeeping bugs: creation and reschedule delays are always ≥ one tick, a returned `0` is clamped,
s2sdk id 0 is a valid, killable timer, a stopped one-shot kills its engine timer, a callback may
remove its own timer (or another one), `Shutdown()` from inside a callback, a callback never runs
twice in one frame, a recycled `CTimer` address is not mistaken for a dead handle, and a timer
(and `NextFrame`) whose fire falls into a map change is postponed and re-armed with one tick on
the first ready frame.

`libs/pisexcompat/test/players_engine_test.cpp` (built as `build/tests/pisexcompat_players_tests`)
does the same for the player wrappers with fake client bindings. It asserts the two crash
fixes by *call counting*: while no map is up not a single s2sdk client call is made, and
`SetClientName` is never reached for a slot without a client or without a controller yet - while
the happy path (human and bot) still works, `"<unknown>"` becomes
`""`, a bot has no IP, and a disconnected slot answers steamid `0` instead of the previous
occupant's id.

`libs/pisexcompat/test/menu_engine_test.cpp` (built as `build/tests/pisexcompat_menu_tests`) drives
the menu layer with a fake s2sdk menu manager that counts `CreateMenu`/`DestroyMenu` and mimics the
handler dispatch (Cancel then End) and `DestroyMenu`'s own end-of-session callbacks. It proves the
documented destroy rule: a timed-out / exited / disconnected display destroys its menu exactly
once and only from `Poll()` (never inside the handler, where the manager's lock is held), an
explicit close or a refused display destroys immediately without a second destroy later, an id
another client still displays stays alive until that session ends, and map end / `Shutdown()`
destroys everything open or queued.

Everything else that touches s2sdk (events, chat triggers) needs a running server — the bindings
are null pointers in the test process.
