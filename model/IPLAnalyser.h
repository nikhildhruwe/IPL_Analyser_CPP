#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "IPLMostRunsData.h"
#include "IPLMostWicketsData.h"
#include "../libraries/csv.h"
using namespace std;

enum SortType{
    BATSMAN_AVG = 1, STRIKE_RATE, SIX_FOUR, STRIKE_RATE_AND_SIX_FOUR, AVERAGE_AND_STRIKE_RATE,
    MAX_RUNS_AND_AVERAGE, BOWLING_AVG
}; 

class IPLAnalyser{
    private :
        vector<vector<string>> readCSVData(string);
    public :   
       vector<IPLMostRuns> loadBatsmanCSVData(string);
       vector<IPLMostWickets> loadBowlersCSVData(string);
       list<IPLMostRuns> getBatsmanSortedList(vector<IPLMostRuns>, SortType);
       list<IPLMostWickets> getBowlersSortedList(vector<IPLMostWickets>, SortType);
};

vector<vector<string>> IPLAnalyser :: readCSVData(string filePath){
    CSVOperations csvObj;
    return csvObj.readFile(filePath);    
}

vector<IPLMostRuns> IPLAnalyser ::loadBatsmanCSVData(string filePath){
   vector<vector<string>> csvdatalist =  readCSVData(filePath);
   vector<IPLMostRuns> batsmanList;
   for (int i = 0; i < csvdatalist.size(); i++){
       IPLMostRuns batsmanDetails(csvdatalist[i][1], stod(csvdatalist[i][7]), stod(csvdatalist[i][9]));
       batsmanDetails.fifties = stoi(csvdatalist[i][11]);
       batsmanDetails.fours = stoi(csvdatalist[i][12]);
       batsmanDetails.hundreds = stoi(csvdatalist[i][10]);
       batsmanDetails.sixes = stoi(csvdatalist[i][13]);
       batsmanDetails.runs = stoi(csvdatalist[i][5]);
       batsmanDetails.highScore = csvdatalist[i][6];
       batsmanList.push_back(batsmanDetails);
   }

   return batsmanList;
}

vector<IPLMostWickets> IPLAnalyser ::loadBowlersCSVData(string filePath){
   vector<vector<string>> csvdatalist =  readCSVData(filePath);
   vector<IPLMostWickets> bowlersList;
   for (int i = 0; i < csvdatalist.size(); i++){
       IPLMostWickets bowlersDetails;
       bowlersDetails.average = stod(csvdatalist[i][8]);
       bowlersDetails.economyRates = stod(csvdatalist[i][9]);
       bowlersDetails.fiveWickets = stoi(csvdatalist[i][12]);
       bowlersDetails.fourWickets = stoi(csvdatalist[i][11]);
       bowlersDetails.playerName = csvdatalist[i][1];
       bowlersDetails.strikeRate = stod(csvdatalist[i][10]);
       bowlersDetails.wickets = stoi(csvdatalist[i][6]);
       bowlersList.push_back(bowlersDetails);
   }

   return bowlersList;
}

list<IPLMostRuns> IPLAnalyser ::getBatsmanSortedList(vector<IPLMostRuns> batsmanList, SortType sortType){
    list<IPLMostRuns> sortedList(batsmanList.begin(), batsmanList.end());

    switch (sortType){
        case BATSMAN_AVG :
            sortedList.sort([](const IPLMostRuns firstBatsman, const IPLMostRuns secondBatsman)
            {return  firstBatsman.average > secondBatsman.average; });
            break;
        case STRIKE_RATE :
            sortedList.sort([](const IPLMostRuns firstBatsman, const IPLMostRuns secondBatsman)
            {return  firstBatsman.strikeRate > secondBatsman.strikeRate;});
            break;
        case SIX_FOUR :
             sortedList.sort([](const IPLMostRuns firstBatsman, const IPLMostRuns secondBatsman)
            {return  firstBatsman.sixes + firstBatsman.fours > secondBatsman.sixes + secondBatsman.fours;});
            break;
        case STRIKE_RATE_AND_SIX_FOUR :
            sortedList.sort([](const IPLMostRuns firstBatsman, const IPLMostRuns secondBatsman)
            {return  (firstBatsman.strikeRate > secondBatsman.strikeRate && 
                    firstBatsman.sixes + firstBatsman.fours > secondBatsman.sixes + secondBatsman.fours);});
            break;
        case AVERAGE_AND_STRIKE_RATE :
            sortedList.sort([](const IPLMostRuns firstBatsman, const IPLMostRuns secondBatsman)
            {return  (firstBatsman.average > secondBatsman.average && 
                    firstBatsman.strikeRate > secondBatsman.strikeRate);});
            break;
        case MAX_RUNS_AND_AVERAGE :
            sortedList.sort([](const IPLMostRuns firstBatsman, const IPLMostRuns secondBatsman)
            {return  (firstBatsman.runs > secondBatsman.runs && 
                    firstBatsman.average > secondBatsman.average);});
            break;
    }
    
    return sortedList;
}

list<IPLMostWickets> IPLAnalyser ::getBowlersSortedList(vector<IPLMostWickets> bowlersList, SortType sortType){
    list<IPLMostWickets> sortedList(bowlersList.begin(), bowlersList.end());

    switch (sortType){
    case BOWLING_AVG :
            sortedList.sort([](const IPLMostWickets firstBowler, const IPLMostWickets secondBowler)
            {if ( firstBowler.average == 0 )
                return false;
                return firstBowler.average < secondBowler.average; });
            break;
        break;
    }

    return sortedList;
}


