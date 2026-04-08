#include<iostream>

#include "player.h"
#include "analysis.h"
#include "output.h"
#include "datareader.h"

using namespace std;



 
int main()
{
	cout << "Yasuo-int-analyzer" << endl;
	
	vector<MatchData> matches = loadMatches("../../../data/sample1.csv");

	if (matches.empty()) {
		cout << "No matches loaded. Cannot calculate statistics." << endl;
		return 0;
	}
	calculateScores(matches);
	sortByScore(matches);
	printPlayers(matches);
	printTopPlayers(matches,3);


return 0;



}

