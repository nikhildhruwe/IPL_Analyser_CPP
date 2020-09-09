#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "IPLMostRunsData.h"
#include "../libraries/csv.h"
using namespace std;

class IPLAnalyser{
    private :
        vector<vector<string>> readCSVData(string);
    public :  
      vector<IPLMostRuns> loadCSVData(string);
      IPLMostRuns getBatsmanWithHighestAverage(vector<IPLMostRuns>);
};

#include "IPLAnalyser.h"

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

IPLMostRuns IPLAnalyser ::getBatsmanWithHighestAverage(vector<IPLMostRuns> batsmanList){
    vector<IPLMostRuns> sortedList = batsmanList;

     for (int i = 0; i < sortedList.size()- 1; i++ ){
        for (int j = 0; j < sortedList.size() - i - 1; j++){
            if ( sortedList[j].average < sortedList[j + 1].average)
                swap(sortedList[j], sortedList[j+1]);
        }
    }

    return sortedList[0];
}

