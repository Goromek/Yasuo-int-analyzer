#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//Structure with all player data
struct PlayerData {
	int kills,deaths,assists,goldDiff15,visionScore,damageScore;

	double kda() const {
		int safeDeaths = deaths == 0 ? 1 : deaths;
		return static_cast<double>(kills + assists) / safeDeaths;
	}
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


 
int main()
{
	cout << "Yasuo-int-analyzer" << endl;
	string line;
	ifstream data("../../../data/sample1.csv");
	if (!data.is_open()) {
		cout << "Error opening file" << endl;;
		return 1;
	}
	getline(data, line);
	vector<PlayerData> players;
	
	//Adding data to specific player
	while (getline(data, line)) {
		PlayerData p;
		if (line.empty()) {
			continue;
		}
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

	data.close();
	
	if (players.empty()) {
		cout << "No players loaded. Cannot calculate statistics." << endl;
		return 0;
	}

	int totalScore = 0;
	int certifiedInt = 0;
	
	cout << "Loaded players: " << players.size() << endl << endl;
	
	//Printing data about players
	for (int i = 0; i < players.size(); i++) {

		cout << "Loading player number: " << i+1 << endl;
		cout << players[i].kills << " " << players[i].deaths << " " << players[i].assists << " " << players[i].goldDiff15 << " " << players[i].visionScore << " " << players[i].damageScore << endl;
		
		int score = intCalc(players[i]);
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
		totalScore += score;
		cout << endl << endl;
	}
	cout << endl << endl;
	cout << "Averge int score in database is equal to: " << double(totalScore) / players.size() << endl;
	cout << "Certified inters in database: " << certifiedInt << endl;
	

	return 0;



}

