#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "IPLMostRunsData.h"
#include "../libraries/csv.h"
using namespace std;

enum SortType{
            AVERAGE = 1, STRIKE_RATE, SIX_FOUR, STRIKE_RATE_AND_SIX_FOUR
        }; 

class IPLAnalyser{
    private :
        vector<vector<string>> readCSVData(string);
    public :   
       vector<IPLMostRuns> loadCSVData(string);
       list<IPLMostRuns> getSortedList(vector<IPLMostRuns>, SortType);
       list<IPLMostRuns> getBatsmanWithTopStrikeRate(vector<IPLMostRuns>);    
};

vector<vector<string>> IPLAnalyser :: readCSVData(string filePath){
    CSVOperations csvObj;
    return csvObj.readFile(filePath);    
}

vector<IPLMostRuns> IPLAnalyser ::loadCSVData(string filePath){
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

list<IPLMostRuns> IPLAnalyser ::getSortedList(vector<IPLMostRuns> batsmanList, SortType sortType){
    list<IPLMostRuns> sortedList(batsmanList.begin(), batsmanList.end());

    switch (sortType){
        case AVERAGE :
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
            {return  (firstBatsman.strikeRate> secondBatsman.strikeRate && 
                    firstBatsman.sixes + firstBatsman.fours > secondBatsman.sixes + secondBatsman.fours);});
            break;
    }
    
    return sortedList;
}

