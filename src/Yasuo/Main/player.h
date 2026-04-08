#pragma once
#include <string>

struct MatchData {
    std::string playerName = "";
    std::string playerTag = "";

    int kills=0;
    int deaths=0;
    int assists=0;
    int goldDiff15=0;
    int visionScore=0;
    int damageScore=0;

    int intScore = 0;

    double kda() const;
};

struct PlayerSummary {
    std::string playerName = "";
    std::string playerTag = "";

    int gamesPlayed = 0;

    double avgKills = 0;
    double avgDeaths = 0;
    double avgAssists = 0;
    double avgGoldDiff15 = 0;
    double avgVisionScore = 0;
    double avgDamageScore = 0;
    double  avgIntScore = 0;
};