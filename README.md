# hudmenu (Plugify)

Registers two custom s2sdk menu types. 'hud': a Panorama on-screen menu with mouse clicks, rendered with the 'custom_hud_layout' entity (the same mechanism as Pisex cs2-menus MenuType::HUD_LAYOUT/3), usable by dead/spectating players; maps menu title/items/exit/back/pagination through the s2sdk menu accessors, hooks ISource2GameClients::ClientSvcUserMessage (polyhook) for CCSUsrMsg_CustomHudClicked (390) clicks and reports selections back to the s2sdk menu manager via SelectMenuItem/MenuNextPage/MenuPrevPage/CancelClientMenu. 'wasd': a port of Pisex cs2-menus MenuType::CENTER_WASD/2 (W/S cursor, A/D page, E select, R exit or back), rendering the Pisex menus.phrases.txt Html* templates (title, rows with the E select image on the cursor row, W/S/A/D pressed-state control images, F/spacer images; images from the workshop addon or the configured site URL) into the center HUD, with Pisex's 200 ms key repeat, optional freeze (StopingUser) and menu sounds. The center HTML is re-sent every server frame with a 5 s alert duration exactly like Pisex's per-frame CTimer, which is flicker-free (s2sdk's built-in 'button' type only keeps the alert alive at 1.5 s intervals with a 2 s duration). 'wasd' needs the movement keys, so it is alive-players-only by nature. Appends workshop addon 3810810950 (the client-side Panorama assets) to s2_extra_addons. Also owns the per-player menu type choice like Pisex cs2-menus: the '!menu' (chat) and 'mm_menu' (console) commands open a Panorama type chooser, the choice is persisted in the permissions cookie 'Utils.MenuType' (int64, Pisex numbering 0=chat 1=centerhtml 2=wasd 3=hud) and exposed to other plugins through GetClientMenuType/SetClientMenuType (pisexcompat resolves every displayed menu with it). Adds the console commands 'hudmenu_test' (opens a 10-item test menu) and 'hudmenu_status'.

Plugify port (fork) of **cs2-menus (HUD layout + WASD menu types)** by Pisex (Metamod (C++)).
Original: https://github.com/Pisex/cs2-menus
The code was rewritten for Plugify / s2sdk; behaviour follows the original.

## Requirements
- [Plugify](https://github.com/untrustedmodders/plugify) with [s2sdk](https://github.com/untrustedmodders/plugify-plugin-s2sdk)
- Plugify dependencies: s2sdk, polyhook, permissions (optional)

## Installation
Download `hudmenu-1.1.2.zip` from Releases and extract it into `game/csgo/`.

## Building
Requires Docker. `./build.sh` builds in the Steam Runtime 3 (sniper) SDK image; the package
is written to `build/package/hudmenu`.

## License
GPL-3.0, see LICENSE.

