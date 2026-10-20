#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: gamerules)

namespace s2sdk {

  using _GetGameRulesProxy = void* (*)();
}
extern "C" PLUGIN_API s2sdk::_GetGameRulesProxy __s2sdk_GetGameRulesProxy;
namespace s2sdk {
  /**
   * @brief Retrieves the pointer to the current game rules proxy instance.
   * @return ptr64: A pointer to the game rules entity instance.
   */
  inline void* GetGameRulesProxy() {
    return __s2sdk_GetGameRulesProxy();
  }

  using _GetGameRules = void* (*)();
}
extern "C" PLUGIN_API s2sdk::_GetGameRules __s2sdk_GetGameRules;
namespace s2sdk {
  /**
   * @brief Retrieves the pointer to the current game rules instance.
   * @return ptr64: A pointer to the game rules object.
   */
  inline void* GetGameRules() {
    return __s2sdk_GetGameRules();
  }

  using _GetGameTeamManager = void* (*)(CSTeam);
}
extern "C" PLUGIN_API s2sdk::_GetGameTeamManager __s2sdk_GetGameTeamManager;
namespace s2sdk {
  /**
   * @brief Retrieves the team manager instance for a specified team.
   * @param team (int32): The numeric identifier of the team.
   * @return ptr64: A pointer to the corresponding CTeam instance, or nullptr if the team was not found.
   */
  inline void* GetGameTeamManager(CSTeam team) {
    return __s2sdk_GetGameTeamManager(team);
  }

  using _GetGameTeamScore = int32_t (*)(CSTeam);
}
extern "C" PLUGIN_API s2sdk::_GetGameTeamScore __s2sdk_GetGameTeamScore;
namespace s2sdk {
  /**
   * @brief Retrieves the current score of a specified team.
   * @param team (int32): The numeric identifier of the team.
   * @return int32: The current score of the team, or -1 if the team could not be found.
   */
  inline int32_t GetGameTeamScore(CSTeam team) {
    return __s2sdk_GetGameTeamScore(team);
  }

  using _GetGamePlayerCount = int32_t (*)(CSTeam);
}
extern "C" PLUGIN_API s2sdk::_GetGamePlayerCount __s2sdk_GetGamePlayerCount;
namespace s2sdk {
  /**
   * @brief Retrieves the number of players on a specified team.
   * @param team (int32): The numeric identifier of the team (e.g., CS_TEAM_T, CS_TEAM_CT, CS_TEAM_SPECTATOR).
   * @return int32: The number of players on the team, or -1 if game rules are unavailable.
   */
  inline int32_t GetGamePlayerCount(CSTeam team) {
    return __s2sdk_GetGamePlayerCount(team);
  }

  using _GetGameTotalRoundsPlayed = int32_t (*)();
}
extern "C" PLUGIN_API s2sdk::_GetGameTotalRoundsPlayed __s2sdk_GetGameTotalRoundsPlayed;
namespace s2sdk {
  /**
   * @brief Returns the total number of rounds played in the current match.
   * @return int32: The total number of rounds played, or -1 if the game rules are unavailable.
   */
  inline int32_t GetGameTotalRoundsPlayed() {
    return __s2sdk_GetGameTotalRoundsPlayed();
  }

  using _TerminateRound = void (*)(float, CSRoundEndReason);
}
extern "C" PLUGIN_API s2sdk::_TerminateRound __s2sdk_TerminateRound;
namespace s2sdk {
  /**
   * @brief Forces the round to end with a specified reason and delay.
   * @param delay (float): Time (in seconds) to delay before the next round starts.
   * @param reason (int32): The reason for ending the round, defined by the CSRoundEndReason enum.
   */
  inline void TerminateRound(float delay, CSRoundEndReason reason) {
    return __s2sdk_TerminateRound(delay, reason);
  }

} // namespace s2sdk
