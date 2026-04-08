#include <algorithm>

#include "analysis.h"


int intCalc(const MatchData& matches) {
	int score = 0;

	if (matches.deaths > 6) score += 4;
	if (matches.goldDiff15 < -500) score += 5;
	if (matches.visionScore < 15) score += 4;
	if (matches.damageScore < 15) score += 5;

	if (matches.kda() < 1.5) score += 3;

	return score;
}

void calculateScores(std::vector<MatchData>& matches) {
	for (auto& m : matches) {
		m.intScore = intCalc(m);

	}
}

void sortByScore(std::vector<MatchData>& matches) {
	std::sort(matches.begin(), matches.end(),
		[](const MatchData& a, const MatchData& b) {
			return a.intScore > b.intScore;
		});
}

std::string playerClassification(int score) {
	
	if (score >= 10) {
		return "Certified 0/10 powerspike";
	}
	 if (score >= 5)
		return "Meh, keep improving brotha";
	
	 return "Korean Yasuo (in this match)";
}