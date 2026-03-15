#pragma once

struct PlayerData {
    int kills;
    int deaths;
    int assists;
    int goldDiff15;
    int visionScore;
    int damageScore;

    double kda() const;
};

struct PlayerScore {
    PlayerData data;
    int score;
};