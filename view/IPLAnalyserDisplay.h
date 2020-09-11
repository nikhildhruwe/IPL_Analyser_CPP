#pragma once
#include <iostream>
using namespace std;

class IPLAnalyserDisplay{
    void displayMessage(string message){
        cout << message << endl;
    }
    public:
    void displayWelcomeMessage();
    void displayBatsmanDetails(list<IPLMostRuns>, string);
    void displayBowlersDetails(list<IPLMostWickets>, string);
    int getSortChoice();
};

void IPLAnalyserDisplay ::displayWelcomeMessage(){
    cout << "\n\tWelcome to IPL Analyser program." << endl;
}

void IPLAnalyserDisplay ::displayBatsmanDetails(list<IPLMostRuns> playerList, string message){
    displayMessage(message);
    auto player = playerList.begin();
    for (int i = 0; i < 3; i++, player++)
        cout << "Player Name : " << player->playerName << "\nAverage     : "
        << player->average << "\nStrike Rate : " << player->strikeRate << "\n" << endl;
}

void IPLAnalyserDisplay ::displayBowlersDetails(list<IPLMostWickets> playerList, string message){
    displayMessage(message);
    auto player = playerList.begin();
    for (int i = 0; i < 3; i++, player++)
        cout << "Player Name  : " << player->playerName << "\nAverage      : "
        << player->average << "\nStrike Rate  : " << player->strikeRate << "\nEconomy Rate : " << player->economyRates << "\nWickets      : "
        << player->wickets << "\n" << endl;
}

int IPLAnalyserDisplay ::getSortChoice(){
    int choice;
    cout << " IPL 2019 Top Players with following stats :" << endl;
    cout << "1.Top batting average.\n2.Highest strike rate of batsman.\n3.Highest 6s and 4s.\n4.Best strike rate with highest 6s and 4s."
    "\n5.Best average along with highest strike rate.\n6.Maximum runs with best average.\n7.Top Bowling average."
    "\n8.Top bowling strike rate.\n9.Top bowling economy rate.\n10.Best economy with highest 5 wickets and 4 wickets."
    "\n11.Best bowling average with strike rate.\n12.Exit." << endl;
    cout << "Select choice : ";
    cin >> choice;
    return choice;
}