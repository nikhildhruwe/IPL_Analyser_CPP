#pragma once
#include <iostream>
using namespace std;

class IPLAnalyserDisplay{
    public:
        void displayWelcomeMessage(){
            cout << "\n\tWelcome to IPL Analyser program." << endl;
        }

        void displayBatsmanWithHighestAverage(IPLMostRuns batsman){
            cout << "Highest Average : " << endl;
            cout << "Player Name : " << batsman.playerName << "\nAverage     : " << batsman.average << endl;
        }
};
