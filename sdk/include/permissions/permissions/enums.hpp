#pragma once

#include <cstdint>
// Generated from permissions.pplugin

namespace permissions {

  // Result codes returned by the API. Values after ErrorsStart are errors.
  enum class Status : int32_t {
    Success = 0, // Operation completed successfully.
    Allow = 1, // Permission is allowed.
    Disallow = 2, // Permission is explicitly denied.
    PermNotFound = 3, // Permission is not defined.
    TemporalGroup = 4, // User has the group temporarily.
    PermanentGroup = 5, // User has the group permanently.
    GroupNotDefined = 6, // User doesn't have the group.
    ErrorsStart = 30, // Marker: every value greater than this is an error.
    PermAlreadyGranted = 31, // Permission already exists with the same state, or conflicts with an existing wildcard.
    CookieNotFound = 32, // Cookie (user) or option (group) is not set.
    OptionNotFound = 32, // Cookie (user) or option (group) is not set.
    GroupNotFound = 33, // Group doesn't exist.
    ChildGroupNotFound = 34, // Child group doesn't exist.
    ParentGroupNotFound = 35, // Parent group doesn't exist, or the group has no parent.
    GroupAlreadyExist = 36, // Group already exists, or the user already has it.
    GroupHierarchyCycle = 37, // Setting the parent would create a cycle in the group hierarchy.
    ActorUserNotFound = 38, // Actor user is not loaded.
    TargetUserNotFound = 39, // Target user is not loaded.
    UserAlreadyExist = 40, // User is already loaded.
    CallbackInvalid = 41, // Callback is null.
    CallbackAlreadyExist = 42, // Callback is already registered.
    CallbackNotFound = 43, // Callback is not registered.
    StorageError = 44, // Storage error.
    DBNotReady = 45, // A storage callback rejected the change (storage not ready or failed). The change wasn't applied.
    InvalidPermission = 46, // Permission line is malformed (empty, empty segment, or '*' not as the last segment).
    InvalidGroupName = 47, // Group name is empty.
    InvalidCookieName = 48, // Cookie or option name is empty.
    InvalidOptionName = 48, // Cookie or option name is empty.
    PermConflict = 49, // Permission already exists with the opposite state. Use Set* to change it.
  };

  // Kind of change reported to permission and group callbacks.
  enum class Action : int32_t {
    Add = 0, // Added.
    Remove = 1, // Removed.
    Replace = 2, // Replaced (state or duration changed).
    ReplaceToWC = 3, // A plain permission was replaced with its wildcard ("a" -> "a.*").
  };

  // User presence state.
  enum class PlayerState : uint32_t {
    NotFound = 0, // User is not loaded.
    Online = 1, // User is loaded and on the server.
    Offline = 2, // User is loaded without presence on the server.
  };

  // Where a permission was found.
  enum class PermSource : uint32_t {
    UserTemp = 0, // Temporary user permission.
    User = 1, // Permanent user permission.
    GroupTemp = 2, // From a temporary group.
    Group = 3, // From a permanent group.
    NotFound = 4, // Permission not found.
  };


  /// Ownership type for RAII wrappers
  enum class Ownership : bool { Borrowed, Owned };

} // namespace permissions
