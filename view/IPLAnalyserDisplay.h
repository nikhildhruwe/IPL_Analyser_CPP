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
    int getSortChoice();
};

void IPLAnalyserDisplay::displayWelcomeMessage(){
    cout << "\n\tWelcome to IPL Analyser program." << endl;
}

void IPLAnalyserDisplay::displayBatsmanDetails(list<IPLMostRuns> batsmanList, string message){
    displayMessage(message);
    auto batsman = batsmanList.begin();
    for (int i = 0; i < 3; i++, batsman++)
        cout << "Player Name : " << batsman->playerName << "\nAverage     : "
        << batsman->average << "\nStrike Rate : " << batsman->strikeRate << "\n" << endl;
}

int IPLAnalyserDisplay ::getSortChoice(){
    int choice;
    cout << " Top Players in following stats :" << endl;
    cout << "1.Highest average.\n2.Highest strike rate.\n3.Highest 6s and 4s.\n4.Best strike rate with 6s and 4s.\n5.Exit" << endl;
    cout << "Select choice : ";
    cin >> choice;
    return choice;
}