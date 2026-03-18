#include "output.h"
#include <iostream>

using namespace std;

void printPlayers(const vector<PlayerScore>& players)
{
    cout << "Loaded players in database: " << players.size() << endl;

    int cerifiedInters=0;
    int totalScore = 0;

    for (size_t i = 0; i < players.size(); i++)
    {
        const auto& p = players[i];

        cout << "Player #" << i + 1 << endl;
        cout << p.data.kills << " "
            << p.data.deaths << " "
            << p.data.assists << " "
            << p.data.goldDiff15 << " "
            << p.data.visionScore << " "
            << p.data.damageScore << endl;

        cout << "Score: " << p.score << endl;
        totalScore += p.score;

        if (p.score >= 10){
            cout << "Certified inter\n";
            cerifiedInters++;
        }
        else if (p.score >= 5)
            cout << "Suspicious\n";
        else
            cout << "Playable\n";

        cout << endl;
    }
    cout << "Certified inters in database: " << cerifiedInters << endl;
    cout << "Averge int score in database is equal to: " << double(totalScore) / players.size() << endl;

}

void printTopPlayers(const vector<PlayerScore>& players, size_t count)
{
    cout << "Top " << count << " inters:\n";

    for (size_t i = 0; i < count && i < players.size(); i++)
    {
        cout << "#" << i + 1
            << " Score: " << players[i].score
            << " KDA: " << players[i].data.kda()
            << endl;
    }
}