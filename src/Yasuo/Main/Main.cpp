#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct playerData {
	int kills,deaths,assists,goldDiff15,visionScore,damageScore;
};

 
int main()
{


	cout << "Yasuo-int-analyzer" << endl;
	string line;
	ifstream data("../../../data/sample1.csv");
	if (!data.is_open()) {
		cout << "Error opening file\n";
		return 1;
	}
	getline(data, line);
	vector<playerData> players;
	playerData p;

	while (getline(data, line)) {
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
	cout << "Loaded players: " << players.size() << endl;
	cout << p.kills << " " << p.deaths << " " << p.assists << " " << p.goldDiff15 << " " << p.visionScore << " " << p.damageScore << endl;

	return 0;



}

