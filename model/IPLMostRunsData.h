#pragma once
#include <iostream>
using namespace std;

class IPLMostRuns{
    public :
        string playerName, highScore;
        int matches, innings, runs, hundreds, fifties, fours, sixes;
        double average, strikRate;
    
        IPLMostRuns(string playerName, double average, double strikeRate){
            this->playerName = playerName;
            this->average = average;
            this->strikRate = strikRate;
    }
};