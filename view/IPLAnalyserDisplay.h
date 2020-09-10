#pragma once
#include <iostream>
using namespace std;

class IPLAnalyserDisplay{
    void displayMessage(string message){
        cout << message << endl;
    }
    public:
        void displayWelcomeMessage(){
            cout << "\n\tWelcome to IPL Analyser program." << endl;
        }

        void displayBatsmanDetails(vector<IPLMostRuns> batsmanList, string message){
            displayMessage(message);
            for (int i = 0; i < 3; i++)
                cout << "Player Name : " << batsmanList[i].playerName << "\nAverage     : "
                 << batsmanList[i].average << "\nStrike Rate : " << batsmanList[i].strikeRate << "\n" << endl;
        }
};