#include "player.h"

double PlayerData::kda() const
{
    int safeDeaths = deaths == 0 ? 1 : deaths;
    return static_cast<double>(kills + assists) / safeDeaths;
}