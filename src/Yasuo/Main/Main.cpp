#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

#include "player.h"
#include "analysis.h"

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

	int totalScore = 0;
	int certifiedInt = 0;
	
	cout << "Loaded players: " << players.size() << endl << endl;
	
	//Printing data about players
	for (int i = 0; i < players.size(); i++) {

		cout << "Loading player number: " << i+1 << endl;
		cout << players[i].data.kills << " " << players[i].data.deaths << " " << players[i].data.assists << " " << players[i].data.goldDiff15 << " " << players[i].data.visionScore << " " << players[i].data.damageScore << endl;
		
		totalScore += players[i].score;

		cout << "Int score is equal to: " << players[i].score << endl;
		
		if (players[i].score >= 10){
			cout << "Certified 0/10 Power Spike" << endl;
			certifiedInt++;
		}
		else if (players[i].score >= 5){
			cout << "Suspicious" << endl;
		}
		else{
			cout << "Playable" << endl;
		}
		cout << endl << endl;

	
	}

	
	cout << endl << endl;
	cout << "Averge int score in database is equal to: " << double(totalScore) / players.size() << endl;
	cout << "Certified inters in database: " << certifiedInt << endl << endl;;
	
	

	cout << "Top 3 inters:" << endl;;

	for (size_t i = 0; i < 3 && i < players.size(); i++) {

		cout << "#" << i + 1 << " Score: " << players[i].score << " KDA: " << players[i].data.kda() << endl;
	}
	

	return 0;



}

