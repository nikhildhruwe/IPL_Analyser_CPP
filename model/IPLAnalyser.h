#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "IPLMostRunsData.h"
#include "IPLMostWicketsData.h"
#include "IPLAllRounder.h"
#include "../libraries/csv.h"
using namespace std;

enum SortType{
    BATSMAN_AVG = 1, BATTING_STRIKE_RATE, SIX_FOUR, STRIKE_RATE_AND_SIX_FOUR, AVERAGE_AND_STRIKE_RATE,
    MAX_RUNS_AND_AVERAGE, BOWLING_AVG, BOWLING_STRIKE_RATE, BOWLING_ECONOMY_RATE, 
    STRIKE_RATE_5W_AND_4W, BOWLING_AVG_AND_STRIKE_RATE, BOWLING_WICKET_AND_AVG,
    BATTING_AND_BOWLING_AVG, ALLROUNDER_RUNS_AND_WICKETS, HUNDEREDS_AND_AVG, ZERO_100S_50S_AND_AVG
}; 

class IPLAnalyser{
    private :
        vector<vector<string>> readCSVData(string);
    public :   
       vector<IPLMostRuns> loadBatsmanCSVData(string);
       vector<IPLMostWickets> loadBowlersCSVData(string);
       vector<IPLAllRounder> loadAllRounderData(vector<IPLMostRuns>, vector<IPLMostWickets>);
       list<IPLMostRuns> getBatsmanSortedList(vector<IPLMostRuns>, SortType);
       list<IPLMostWickets> getBowlersSortedList(vector<IPLMostWickets>, SortType);
       list<IPLAllRounder> getAllRounderSortedList(vector<IPLAllRounder>, SortType);
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
       bowlersDetails.runs = stoi(csvdatalist[i][5]);
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
        case BATTING_STRIKE_RATE :
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
        case HUNDEREDS_AND_AVG :
            sortedList.sort([](const IPLMostRuns firstBatsman, const IPLMostRuns secondBatsman)
            {return  (firstBatsman.hundreds > secondBatsman.hundreds && 
                    firstBatsman.average > secondBatsman.average);});
            break;
        case ZERO_100S_50S_AND_AVG :
            list<IPLMostRuns> averageList;
            for (auto batsman = sortedList.begin(); batsman != sortedList.end(); batsman++ ){
                if ( batsman->hundreds == 0 && batsman->fifties == 0 ){
                    averageList.push_back(*batsman);
                }
            }
            sortedList = averageList;
            sortedList.sort([](const IPLMostRuns firstBatsman, const IPLMostRuns secondBatsman)
            { return  firstBatsman.average > secondBatsman.average ;});
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
    case BOWLING_STRIKE_RATE :
            sortedList.sort([](const IPLMostWickets firstBowler, const IPLMostWickets secondBowler)
            {if ( firstBowler.strikeRate == 0 )
                return false;
            return firstBowler.strikeRate < secondBowler.strikeRate; });
            break;
    case BOWLING_ECONOMY_RATE :
            sortedList.sort([](const IPLMostWickets firstBowler, const IPLMostWickets secondBowler)
            {if ( firstBowler.economyRates == 0 )
               return false;
            return firstBowler.economyRates < secondBowler.economyRates; });
            break;
    case STRIKE_RATE_5W_AND_4W :
            sortedList.sort([](const IPLMostWickets firstBowler, const IPLMostWickets secondBowler)
            {if ( firstBowler.strikeRate == 0 )
               return false;
            return (firstBowler.strikeRate  < secondBowler.strikeRate) &&
            (firstBowler.fiveWickets + firstBowler.fiveWickets) > (secondBowler.fiveWickets + secondBowler.fourWickets); });
            break;
    case BOWLING_AVG_AND_STRIKE_RATE :
            sortedList.sort([](const IPLMostWickets firstBowler, const IPLMostWickets secondBowler)
            {if ( firstBowler.average == 0 || firstBowler.strikeRate == 0 )
               return false;
            return (firstBowler.average  < secondBowler.average) && (firstBowler.strikeRate < secondBowler.strikeRate); });
            break;
    case BOWLING_WICKET_AND_AVG :
            sortedList.sort([](const IPLMostWickets firstBowler, const IPLMostWickets secondBowler)
            {if ( firstBowler.average == 0)
               return false;
            return (firstBowler.wickets  > secondBowler.wickets) && (firstBowler.average < secondBowler.average); });
            break;
    }
    return sortedList;
}

vector<IPLAllRounder> IPLAnalyser ::loadAllRounderData( vector<IPLMostRuns> battingList, vector<IPLMostWickets> bowlersList){
    vector<IPLAllRounder> allRounderList;
    for (int i = 0; i < battingList.size(); i++){
        for (int j = 0; j < bowlersList.size(); j++){
            if ( bowlersList[j].playerName == battingList[i].playerName ){
                IPLAllRounder allRounderObj;
                allRounderObj.playerName = bowlersList[j].playerName;
                allRounderObj.bowlingAverage = bowlersList[j].average;
                allRounderObj.battingAverage = battingList[i].average;
                allRounderObj.run = bowlersList[j].runs;
                allRounderObj.wicket = bowlersList[j].wickets;
                allRounderList.push_back(allRounderObj);
            }
        }
    }
    return allRounderList;
}

list<IPLAllRounder> IPLAnalyser ::getAllRounderSortedList(vector<IPLAllRounder> allRounderList, SortType sortType){
    list<IPLAllRounder> sortedList(allRounderList.begin(), allRounderList.end());

    switch (sortType){
        case BATTING_AND_BOWLING_AVG :
            sortedList.sort([](const IPLAllRounder firstPlayer, const IPLAllRounder secondPlayer)
            { if (firstPlayer.bowlingAverage == 0 || secondPlayer.bowlingAverage == 0)
                return false;
             return ((firstPlayer.bowlingAverage < secondPlayer.bowlingAverage) &&
                (firstPlayer.battingAverage > secondPlayer.battingAverage)); });
            break;
        case ALLROUNDER_RUNS_AND_WICKETS :
            sortedList.sort([](const IPLAllRounder firstPlayer, const IPLAllRounder secondPlayer)
            {return (firstPlayer.run  > secondPlayer.run  &&  firstPlayer.wicket > secondPlayer.wicket);});
            break;
        }
    return sortedList;
}