#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

//Structure with all player data
struct PlayerData {
	int kills,deaths,assists,goldDiff15,visionScore,damageScore;

	double kda() const {
		int safeDeaths = deaths == 0 ? 1 : deaths;
		return static_cast<double>(kills + assists) / safeDeaths;
	}
};
struct Result {
	PlayerData player;
	int pScore;

};
//Int score calculator (higher score=more inting)
int intCalc(const PlayerData &p) {
	int score=0;

	if (p.deaths > 6) score += 4;
	if (p.goldDiff15 < -500) score += 5;
	if (p.visionScore < 15) score += 4;
	if (p.damageScore <15) score += 5;

	if (p.kda() < 1.5) score += 3;

	return score;
}
vector<PlayerData> loadPlayers(const string& filename)
{
	vector<PlayerData> players;
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

		PlayerData p;

		stringstream ss(line);
		string value;

		getline(ss, value, ','); p.kills = stoi(value);
		getline(ss, value, ','); p.deaths = stoi(value);
		getline(ss, value, ','); p.assists = stoi(value);
		getline(ss, value, ','); p.goldDiff15 = stoi(value);
		getline(ss, value, ','); p.visionScore = stoi(value);
		getline(ss, value, ','); p.damageScore = stoi(value);

		players.push_back(p);
	}

	return players;
}


 
int main()
{
	cout << "Yasuo-int-analyzer" << endl;
	

   vector<PlayerData> players = loadPlayers("../../../data/sample1.csv");

	
	if (players.empty()) {
		cout << "No players loaded. Cannot calculate statistics." << endl;
		return 0;
	}
	vector<Result> results;

	long int totalScore = 0;
	int certifiedInt = 0;
	
	cout << "Loaded players: " << players.size() << endl << endl;
	
	//Printing data about players
	for (int i = 0; i < players.size(); i++) {

		cout << "Loading player number: " << i+1 << endl;
		cout << players[i].kills << " " << players[i].deaths << " " << players[i].assists << " " << players[i].goldDiff15 << " " << players[i].visionScore << " " << players[i].damageScore << endl;
		
		int score = intCalc(players[i]);
		totalScore += score;
		Result r;
		r.player = players[i];
		r.pScore = score;

		results.push_back(r);


		cout << "Int score is equal to: " << score << endl;
		
		if (score >= 10){
			cout << "Certified 0/10 Power Spike" << endl;
			certifiedInt++;
		}
		else if (score >= 5){
			cout << "Suspicious" << endl;
		}
		else{
			cout << "Playable" << endl;
		}
		cout << endl << endl;
	}

	sort(results.begin(), results.end(),
		[](const Result& a, const Result& b) {
			return a.pScore > b.pScore;
		});
	cout << endl << endl;
	cout << "Averge int score in database is equal to: " << double(totalScore) / players.size() << endl;
	cout << "Certified inters in database: " << certifiedInt << endl << endl;;
	

	cout << "Top 3 inters:" << endl;;

	for (size_t i = 0; i < 3 && i < results.size(); i++) {

		cout << "#" << i + 1 << " Score: " << results[i].pScore << " KDA: " << results[i].player.kda() << endl;
	}
	

	return 0;



}

