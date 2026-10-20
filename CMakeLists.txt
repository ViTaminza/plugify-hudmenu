cmake_minimum_required(VERSION 3.20)
project(plugify-port LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Shared SDK: plg headers (plugify-module-cpp, API v3), generated s2sdk bindings, plugin_export.h, nlohmann/json
add_library(plugify_sdk INTERFACE)
target_include_directories(plugify_sdk INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/sdk/include")

# s2sdk binding globals (__s2sdk_*), compiled into every plugin that links s2sdk_bindings
add_library(s2sdk_bindings OBJECT "${CMAKE_CURRENT_SOURCE_DIR}/sdk/include/s2sdk/s2sdk.cpp")
target_link_libraries(s2sdk_bindings PUBLIC plugify_sdk)
target_compile_definitions(s2sdk_bindings PUBLIC _GLIBCXX_USE_CXX11_ABI=1)

# permissions (official plugify-plugin-permissions 1.3.1) binding globals (__permissions_*)
add_library(permissions_bindings OBJECT "${CMAKE_CURRENT_SOURCE_DIR}/sdk/include/permissions/permissions.cpp")
target_link_libraries(permissions_bindings PUBLIC plugify_sdk)
target_compile_definitions(permissions_bindings PUBLIC _GLIBCXX_USE_CXX11_ABI=1)

# polyhook (official plugify-plugin-polyhook 2.5.6) binding globals (__polyhook_*)
add_library(polyhook_bindings OBJECT "${CMAKE_CURRENT_SOURCE_DIR}/sdk/include/polyhook/polyhook.cpp")
target_link_libraries(polyhook_bindings PUBLIC plugify_sdk)
target_compile_definitions(polyhook_bindings PUBLIC _GLIBCXX_USE_CXX11_ABI=1)

# hudmenu (plugins/hudmenu) binding globals (__hudmenu_*). pisexcompat resolves every displayed
# menu type through these; it PUBLIC-links this object library, so every pisexcompat consumer
# (plugins/admin_system, plugins/as_*, the tests) gets the globals automatically - the plugin
# .so then exports them (version script "__hudmenu_*") and its manifest declares the optional
# hudmenu dependency, which is what makes the plugify module fill them.
add_library(hudmenu_bindings OBJECT "${CMAKE_CURRENT_SOURCE_DIR}/sdk/include/hudmenu/hudmenu.cpp")
target_link_libraries(hudmenu_bindings PUBLIC plugify_sdk)
target_compile_definitions(hudmenu_bindings PUBLIC _GLIBCXX_USE_CXX11_ABI=1)

add_subdirectory(libs/plgdb)
add_subdirectory(libs/pisexcompat)


# Every plugin directory with a CMakeLists.txt is built (plugins/<name>). A plugin may add test
# executables named *_tests with RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests" (run by test.sh).
file(GLOB _plugin_dirs LIST_DIRECTORIES true "${CMAKE_CURRENT_SOURCE_DIR}/plugins/*")
list(SORT _plugin_dirs)
foreach(_d ${_plugin_dirs})
    if(EXISTS "${_d}/CMakeLists.txt")
        add_subdirectory(${_d})
    endif()
endforeach()

option(PLUGIFY_PORT_TESTS "Build tests" ON)
if(PLUGIFY_PORT_TESTS)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests")
        add_subdirectory(tests)
    endif()
endif()
