#pragma once

#include "enums.hpp"
#include "aliases.hpp"
// Generated from polyhook.pplugin

namespace polyhook {

  // Callback function
  using CallbackHandler = ResultType (*)(HookHandle, ParametersHandle, int32_t, ReturnHandle, CallbackType);


} // namespace polyhook
