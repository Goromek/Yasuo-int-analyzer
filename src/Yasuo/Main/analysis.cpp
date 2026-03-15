#include <algorithm>
#include "analysis.h"
using namespace std;

int intCalc(const PlayerData& p) {
	int score = 0;

	if (p.deaths > 6) score += 4;
	if (p.goldDiff15 < -500) score += 5;
	if (p.visionScore < 15) score += 4;
	if (p.damageScore < 15) score += 5;

	if (p.kda() < 1.5) score += 3;

	return score;
}

void calculateScores(vector<PlayerScore>& players) {
	for (auto& p : players) {
		p.score = intCalc(p.data);

	}
}

void sortByScore(vector<PlayerScore>& players) {
	sort(players.begin(), players.end(),
		[](const PlayerScore& a, const PlayerScore& b) {
			return a.score > b.score;
		});
}