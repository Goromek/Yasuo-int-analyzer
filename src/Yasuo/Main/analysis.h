#pragma once

#include <vector>
#include "player.h"
using namespace std;

int intCalc(const PlayerData& p);

void calculateScores(vector<PlayerScore>& players);

void sortByScore(vector<PlayerScore>& players);
