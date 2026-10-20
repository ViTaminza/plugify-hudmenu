#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: filesystem)

namespace s2sdk {

  using _ReadFileVPK = plg::string (*)(const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_ReadFileVPK __s2sdk_ReadFileVPK;
namespace s2sdk {
  /**
   * @brief Reads a file and returns its contents as a string.
   * @param localFileName (string): The relative path of the file to read.
   * @param pathId (string): The filesystem search path ID (e.g., "GAME"). If empty, uses "GAME".
   * @return string: The file contents, or an empty string on failure.
   */
  inline plg::string ReadFileVPK(const plg::string& localFileName, const plg::string& pathId) {
    return __s2sdk_ReadFileVPK(localFileName, pathId);
  }

  using _FindFileAbsoluteList = plg::vector<plg::string> (*)(const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_FindFileAbsoluteList __s2sdk_FindFileAbsoluteList;
namespace s2sdk {
  /**
   * @brief Finds all files matching the given wildcard and path ID.
   * @param wildcard (string): The wildcard pattern to match.
   * @param pathId (string): The filesystem search path ID (e.g., "GAME"). If empty, uses "GAME".
   * @return string[]: The list of absolute file paths matching the wildcard.
   */
  inline plg::vector<plg::string> FindFileAbsoluteList(const plg::string& wildcard, const plg::string& pathId) {
    return __s2sdk_FindFileAbsoluteList(wildcard, pathId);
  }

} // namespace s2sdk
