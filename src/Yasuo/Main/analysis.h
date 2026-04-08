#pragma once
#include <vector>
#include <string>

#include "player.h"


int intCalc(const MatchData& matches);

void calculateScores(std::vector<MatchData>& matches);

void sortByScore(std::vector<MatchData>& matches);

std::string playerClassification(int score);