file(GLOB PLGDB_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(plgdb STATIC ${PLGDB_SOURCES})
target_include_directories(plgdb PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_definitions(plgdb PUBLIC _GLIBCXX_USE_CXX11_ABI=1)
target_compile_options(plgdb PRIVATE -Wall -Wextra -Wshadow -Werror -fvisibility=hidden)

# Everything static: the CS2 runtime (Steam Runtime 3, glibc 2.31) has no libmariadb.
# libmariadbclient.a (MariaDB Connector/C 3.1, Debian 10.5.23) uses OpenSSL 1.1.
set(_L /usr/lib/x86_64-linux-gnu)
target_link_libraries(plgdb PUBLIC
    ${_L}/libmariadbclient.a ${_L}/libsqlite3.a ${_L}/libssl.a ${_L}/libcrypto.a ${_L}/libz.a
    pthread dl m)
