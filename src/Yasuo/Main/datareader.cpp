#include <sstream>
#include <fstream>
#include <iostream>

#include "datareader.h"


bool readIntField(std::stringstream& ss, int& target)
{
	std::string value;
	size_t idx=0;

	if (!std::getline(ss, value, ','))
		return false;

	if (value.empty())
		return false;

	try {
		target = std::stoi(value,&idx);
		return idx == value.length();
	}
	catch (...)/*catch- z³ap jakikolwiek wyj¹tek i zwróæ w tym przypadku false*/ {
		return false;
	}
}

bool readStringField(std::stringstream& ss, std::string& target) {

	std::string value;

	if (!std::getline(ss, value, ','))
		return false;

	if (value.empty())
		return false;

	target = value;
	return true;
	


}

bool parsePlayerLine(const std::string& line, MatchData& out)
{
	std::stringstream ss(line);
	MatchData temp{};

	if (!readStringField(ss, temp.playerName)) return false;
	if (!readStringField(ss, temp.playerTag)) return false;
	if (!readIntField(ss, temp.kills)) return false;
	if (!readIntField(ss, temp.deaths)) return false;
	if (!readIntField(ss, temp.assists)) return false;
	if (!readIntField(ss, temp.goldDiff15)) return false;
	if (!readIntField(ss, temp.visionScore)) return false;
	if (!readIntField(ss, temp.damageScore)) return false;
	if (!ss.eof()) return false;

	out = temp;
	return true;
}

std::vector<MatchData> loadMatches(const std::string& filename)
{
	std::vector<MatchData> players;
	std::ifstream data(filename);

	if (!data.is_open()) {
		std::cerr << "Error opening file " << filename << std::endl;
		return players;
	}
	std::string line;
	int lineNumber=0;

	std::getline(data, line);
	lineNumber++;

	while (std::getline(data, line)) {
	lineNumber++;
	if (line.empty())
		continue;
	
	MatchData p{};

		
	if (parsePlayerLine(line, p)) 
		players.push_back(p);
	
	else
		std::cerr << "Invalid data in line " << lineNumber << ": " << line << std::endl;
	 
	}
	return players;
}
