# pisexcompat — re-creates the subset of the Pisex "utils" (IUtilsApi), "menus" (IMenusApi) and
# "players" (IPlayersApi) APIs that the cs2-admin_system core its modules use, on top of s2sdk.
#
# Static library: linked into each ported plugin together with the s2sdk binding globals, so the
# plugin itself only has to link `pisexcompat`.
#
# See README.md for the inventory table (which Pisex method is used how often) and for the list of
# behaviours that are intentionally different from the Metamod originals.

file(GLOB PISEXCOMPAT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(pisexcompat STATIC ${PISEXCOMPAT_SOURCES})

target_include_directories(pisexcompat PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
# hudmenu_bindings: the library resolves each displayed menu's s2sdk type name through
# __hudmenu_GetClientMenuType when the hudmenu plugin is installed; PUBLIC so every consumer
# (and the tests) gets the globals exactly like s2sdk_bindings.
target_link_libraries(pisexcompat PUBLIC plugify_sdk s2sdk_bindings hudmenu_bindings)
target_compile_definitions(pisexcompat PUBLIC _GLIBCXX_USE_CXX11_ABI=1)
# The generated plg/s2sdk headers are not ours to fix; keep their warnings out of -Werror.
target_include_directories(pisexcompat SYSTEM PRIVATE "${CMAKE_SOURCE_DIR}/sdk/include")
target_compile_options(pisexcompat PRIVATE -Wall -Wextra -Wshadow -Werror -fvisibility=hidden)

# Timer-registry test: installs fake s2sdk timer bindings (the globals are only null until a fake
# is assigned) and drives the real Create/Remove/Process/OnFire code - the paths whose bugs made
# the live server watchdog-fatal (a repeat timer with delay 0 loops forever inside one RunFrame
# call) or leaked/use-after-freed timers. Lives under build/tests so ./test.sh picks it up.
add_executable(pisexcompat_timers_tests test/timers_engine_test.cpp)
target_link_libraries(pisexcompat_timers_tests PRIVATE pisexcompat s2sdk_bindings -static-libstdc++ -static-libgcc)
target_include_directories(pisexcompat_timers_tests SYSTEM PRIVATE "${CMAKE_SOURCE_DIR}/sdk/include")
target_compile_options(pisexcompat_timers_tests PRIVATE -Wall -Wextra -Werror)
set_target_properties(pisexcompat_timers_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests")

# Player-wrapper test: fake client bindings + the map lifecycle gate. Covers the live crashes
# (SetClientName on a clientless slot, any client query during the map shutdown) and asserts that
# a slot without a client/controller never reaches s2sdk. Runs from ../test.sh.
add_executable(pisexcompat_players_tests test/players_engine_test.cpp)
target_link_libraries(pisexcompat_players_tests PRIVATE pisexcompat s2sdk_bindings -static-libstdc++ -static-libgcc)
target_include_directories(pisexcompat_players_tests SYSTEM PRIVATE "${CMAKE_SOURCE_DIR}/sdk/include")
target_compile_options(pisexcompat_players_tests PRIVATE -Wall -Wextra -Werror)
set_target_properties(pisexcompat_players_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests")

# Menu test: fake s2sdk menu manager, counts CreateMenu/DestroyMenu. Covers the documented rule
# "always destroy your menus from the handler's End case" (deferred out of the handler, exactly
# once, never while another client still shows the menu). Runs from ../test.sh.
add_executable(pisexcompat_menu_tests test/menu_engine_test.cpp)
target_link_libraries(pisexcompat_menu_tests PRIVATE pisexcompat s2sdk_bindings -static-libstdc++ -static-libgcc)
target_include_directories(pisexcompat_menu_tests SYSTEM PRIVATE "${CMAKE_SOURCE_DIR}/sdk/include")
target_compile_options(pisexcompat_menu_tests PRIVATE -Wall -Wextra -Werror)
set_target_properties(pisexcompat_menu_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests")

# Integration check: build one real plugin .so against the library, so ./build.sh's ABI report
# covers a consumer of pisexcompat (GLIBC <= 2.31, no libstdc++/libmariadb NEEDED). It is not part
# of any package - the file name makes that obvious.
option(PISEXCOMPAT_SMOKE_PLUGIN "Build the pisexcompat link/ABI smoke plugin" ON)
if(PISEXCOMPAT_SMOKE_PLUGIN)
    add_library(pisexcompat_smoke_plugin SHARED test/smoke_plugin.cpp)
    target_link_libraries(pisexcompat_smoke_plugin PRIVATE pisexcompat -static-libstdc++ -static-libgcc)
    target_compile_options(pisexcompat_smoke_plugin PRIVATE -Wall -Wextra -Werror)
    # Same definitions a real plugin sets (see plugins/perm_connector/CMakeLists.txt).
    target_compile_definitions(pisexcompat_smoke_plugin PRIVATE
        _GLIBCXX_USE_CXX11_ABI=1 PLUGIFY_MODULE="pisexcompat_smoke" PLUGIFY_IS_DEBUG=0 PLUGIFY_IS_RELEASE=1)
    set_target_properties(pisexcompat_smoke_plugin PROPERTIES OUTPUT_NAME pisexcompat_smoke)
endif()
