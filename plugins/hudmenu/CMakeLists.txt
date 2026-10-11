# hudmenu — Plugify C++ plugin registering the custom s2sdk menu type "hud": a Panorama
# on-screen menu (mouse clicks) rendered with the "custom_hud_layout" entity, equivalent to
# Pisex cs2-menus MenuType::HUD_LAYOUT (3). Unlike s2sdk's WASD "button" type it is usable by
# dead / spectating players.
#
#   plugify-hudmenu  the plugin shared library (entry "bin/hudmenu" -> bin/libhudmenu.so)

set(HUDMENU_VERSION "1.1.2")

add_library(plugify-hudmenu SHARED
        src/plugin.cpp
        src/click_hook.cpp
        src/hud_layout.cpp
        src/phrases.cpp
        src/wasd_menu.cpp
        # Binding globals (__s2sdk_* / __polyhook_* / __permissions_*) filled by the plugify
        # module from the plugins declared as dependencies.
        $<TARGET_OBJECTS:s2sdk_bindings>
        $<TARGET_OBJECTS:polyhook_bindings>
        $<TARGET_OBJECTS:permissions_bindings>
)
target_include_directories(plugify-hudmenu PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
# SYSTEM: warnings from the generated s2sdk/polyhook/plg headers must not fail -Werror on our sources.
target_include_directories(plugify-hudmenu SYSTEM PRIVATE "${CMAKE_SOURCE_DIR}/sdk/include")
target_link_libraries(plugify-hudmenu PRIVATE
        -static-libstdc++ -static-libgcc
        ${CMAKE_DL_LIBS}
)
target_compile_options(plugify-hudmenu PRIVATE -Wall -Wextra -Werror)
target_compile_definitions(plugify-hudmenu PRIVATE
        _GLIBCXX_USE_CXX11_ABI=1
        PLUGIFY_MODULE="hudmenu"
        PLUGIFY_IS_DEBUG=0
        PLUGIFY_IS_RELEASE=1
)
set_target_properties(plugify-hudmenu PROPERTIES OUTPUT_NAME hudmenu)

if(UNIX AND NOT APPLE)
    target_link_options(plugify-hudmenu PRIVATE
            "-Wl,--version-script,${CMAKE_CURRENT_SOURCE_DIR}/sym/version_script.lds")
endif()

configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/hudmenu.pplugin.in"
        "${CMAKE_CURRENT_BINARY_DIR}/hudmenu.pplugin"
)
