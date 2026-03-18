#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

#include "player.h"
#include "analysis.h"
#include "output.h"

using namespace std;

vector<PlayerScore> loadPlayers(const string& filename)
{
	vector<PlayerScore> players;
	string line;

	ifstream data(filename);

	if (!data.is_open()) {
		cout << "Error opening file\n";
		return players;
	}

	getline(data, line);

	while (getline(data, line)) {

		if (line.empty())
			continue;

		PlayerScore p;

		stringstream ss(line);
		string value;

		getline(ss, value, ','); p.data.kills = stoi(value);
		getline(ss, value, ','); p.data.deaths = stoi(value);
		getline(ss, value, ','); p.data.assists = stoi(value);
		getline(ss, value, ','); p.data.goldDiff15 = stoi(value);
		getline(ss, value, ','); p.data.visionScore = stoi(value);
		getline(ss, value, ','); p.data.damageScore = stoi(value);

		players.push_back(p);
	}
	return players;
}


 
int main()
{
	cout << "Yasuo-int-analyzer" << endl;
	
	vector<PlayerScore> players = loadPlayers("../../../data/sample1.csv");

	if (players.empty()) {
		cout << "No players loaded. Cannot calculate statistics." << endl;
		return 0;
	}
	sortByScore(players);
	calculateScores(players);
	printPlayers(players);
	printTopPlayers(players,3);


return 0;



}

