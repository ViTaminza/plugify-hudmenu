#pragma once
#if defined(_WIN32)
#  define PLUGIN_API __declspec(dllexport)
#else
#  define PLUGIN_API __attribute__((visibility("default")))
#endif
