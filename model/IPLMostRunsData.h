#pragma once
using namespace std;

class IPLMostRuns{
    public :
        string playerName, highScore;
        int matches, innings, runs, hundreds, fifties, fours, sixes;
        double average, strikeRate;
    
        IPLMostRuns(string playerName, double average, double strikeRate){
            this->playerName = playerName;
            this->average = average;
            this->strikeRate = strikeRate;
    }
};