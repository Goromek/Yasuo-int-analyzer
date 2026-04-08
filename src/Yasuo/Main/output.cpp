#include <iostream>

#include "analysis.h"
#include "output.h"

void printPlayers(const std::vector<MatchData>&matches)
{
    std::cout << "Loaded matches in database: " << matches.size() << std::endl;

    
    int totalScore = 0;

    for (size_t i = 0; i < matches.size(); i++)
    {
        const auto& p = matches[i];

        std::cout << "Match #" << i + 1 << std::endl;
        std::cout << "By player: " << p.playerName << "#" << p.playerTag << std::endl;
        std::cout << p.kills << " "
            << p.deaths << " "
            << p.assists << " "
            << p.goldDiff15 << " "
            << p.visionScore << " "
            << p.damageScore << std::endl;

        std::cout << "Score: " << p.intScore << std::endl;
        totalScore += p.intScore;

        std::cout << playerClassification(p.intScore) << std::endl;

        std::cout << std::endl;
    }

    std::cout << "Averge int score in database is equal to: " << double(totalScore) / matches.size() << std::endl;

}

void printTopPlayers(const std::vector<MatchData>& matches, size_t count)
{
    std::cout << "Top " << count << " inters:\n";

    for (size_t i = 0; i < count && i < matches.size(); i++)
    {
        std::cout << "#" << i + 1
            << " Score: " << matches[i].intScore
            << " KDA: " << matches[i].kda()
            << std::endl;
    }
}