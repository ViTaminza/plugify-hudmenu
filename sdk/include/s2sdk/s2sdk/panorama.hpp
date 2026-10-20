#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: panorama)

namespace s2sdk {

  using _PanoramaSendYesNoVote = bool (*)(double, int32_t, const plg::string&, const plg::string&, const plg::string&, const plg::string&, VoteCreateFailed, uint64_t, YesNoVoteResult, YesNoVoteHandler);
}
extern "C" PLUGIN_API s2sdk::_PanoramaSendYesNoVote __s2sdk_PanoramaSendYesNoVote;
namespace s2sdk {
  /**
   * @brief Start a new Yes/No vote
   * @param duration (double): Maximum time to leave vote active for
   * @param caller (int32): Player slot of the vote caller. Use VOTE_CALLER_SERVER for 'Server'.
   * @param voteTitle (string): Translation string to use as the vote message. (Only '#SFUI_vote' or '#Panorama_vote' strings)
   * @param detailStr (string): Extra string used in some vote translation strings.
   * @param votePassTitle (string): Translation string to use as the vote message. (Only '#SFUI_vote' or '#Panorama_vote' strings)
   * @param detailPassStr (string): Extra string used in some vote translation strings when the vote passes.
   * @param failReason (int32): Reason for the vote to fail, used in some translation strings.
   * @param filter (uint64): Recipient filter with all the clients who are allowed to participate in the vote.
   * @param result (function): Called when a menu action is completed.
   * @param handler (function): Called when the vote has finished.
   * @return bool
   */
  inline bool PanoramaSendYesNoVote(double duration, int32_t caller, const plg::string& voteTitle, const plg::string& detailStr, const plg::string& votePassTitle, const plg::string& detailPassStr, VoteCreateFailed failReason, uint64_t filter, YesNoVoteResult result, YesNoVoteHandler handler) {
    return __s2sdk_PanoramaSendYesNoVote(duration, caller, voteTitle, detailStr, votePassTitle, detailPassStr, failReason, filter, result, handler);
  }

  using _PanoramaSendYesNoVoteToAll = bool (*)(double, int32_t, const plg::string&, const plg::string&, const plg::string&, const plg::string&, VoteCreateFailed, YesNoVoteResult, YesNoVoteHandler);
}
extern "C" PLUGIN_API s2sdk::_PanoramaSendYesNoVoteToAll __s2sdk_PanoramaSendYesNoVoteToAll;
namespace s2sdk {
  /**
   * @brief Start a new Yes/No vote with all players included
   * @param duration (double): Maximum time to leave vote active for
   * @param caller (int32): Player slot of the vote caller. Use VOTE_CALLER_SERVER for 'Server'.
   * @param voteTitle (string): Translation string to use as the vote message. (Only '#SFUI_vote' or '#Panorama_vote' strings)
   * @param detailStr (string): Extra string used in some vote translation strings.
   * @param votePassTitle (string): Translation string to use as the vote message. (Only '#SFUI_vote' or '#Panorama_vote' strings)
   * @param detailPassStr (string): Extra string used in some vote translation strings when the vote passes.
   * @param failReason (int32): Reason for the vote to fail, used in some translation strings.
   * @param result (function): Called when a menu action is completed.
   * @param handler (function): Called when the vote has finished.
   * @return bool
   */
  inline bool PanoramaSendYesNoVoteToAll(double duration, int32_t caller, const plg::string& voteTitle, const plg::string& detailStr, const plg::string& votePassTitle, const plg::string& detailPassStr, VoteCreateFailed failReason, YesNoVoteResult result, YesNoVoteHandler handler) {
    return __s2sdk_PanoramaSendYesNoVoteToAll(duration, caller, voteTitle, detailStr, votePassTitle, detailPassStr, failReason, result, handler);
  }

  using _PanoramaRemovePlayerFromVote = void (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_PanoramaRemovePlayerFromVote __s2sdk_PanoramaRemovePlayerFromVote;
namespace s2sdk {
  /**
   * @brief Removes a player from the current vote.
   * @param playerSlot (int32): The slot/index of the player to remove from the vote.
   */
  inline void PanoramaRemovePlayerFromVote(int32_t playerSlot) {
    return __s2sdk_PanoramaRemovePlayerFromVote(playerSlot);
  }

  using _PanoramaIsPlayerInVotePool = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_PanoramaIsPlayerInVotePool __s2sdk_PanoramaIsPlayerInVotePool;
namespace s2sdk {
  /**
   * @brief Checks if a player is in the vote pool.
   * @param playerSlot (int32): The slot/index of the player to check.
   * @return bool: true if the player is in the vote pool, false otherwise.
   */
  inline bool PanoramaIsPlayerInVotePool(int32_t playerSlot) {
    return __s2sdk_PanoramaIsPlayerInVotePool(playerSlot);
  }

  using _PanoramaRedrawVoteToClient = bool (*)(int32_t);
}
extern "C" PLUGIN_API s2sdk::_PanoramaRedrawVoteToClient __s2sdk_PanoramaRedrawVoteToClient;
namespace s2sdk {
  /**
   * @brief Redraws the vote UI to a specific player client.
   * @param playerSlot (int32): The slot/index of the player to update.
   * @return bool: true if the vote UI was successfully redrawn, false otherwise.
   */
  inline bool PanoramaRedrawVoteToClient(int32_t playerSlot) {
    return __s2sdk_PanoramaRedrawVoteToClient(playerSlot);
  }

  using _PanoramaIsVoteInProgress = bool (*)();
}
extern "C" PLUGIN_API s2sdk::_PanoramaIsVoteInProgress __s2sdk_PanoramaIsVoteInProgress;
namespace s2sdk {
  /**
   * @brief Checks if a vote is currently in progress.
   * @return bool: true if a vote is active, false otherwise.
   */
  inline bool PanoramaIsVoteInProgress() {
    return __s2sdk_PanoramaIsVoteInProgress();
  }

  using _PanoramaEndVote = void (*)(VoteEndReason);
}
extern "C" PLUGIN_API s2sdk::_PanoramaEndVote __s2sdk_PanoramaEndVote;
namespace s2sdk {
  /**
   * @brief Ends the current vote with a specified reason.
   * @param reason (int32): The reason for ending the vote.
   */
  inline void PanoramaEndVote(VoteEndReason reason) {
    return __s2sdk_PanoramaEndVote(reason);
  }

} // namespace s2sdk
