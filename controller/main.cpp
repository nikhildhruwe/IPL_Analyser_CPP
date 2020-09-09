#include <iostream>
#include "../model/IPLAnalyser.h"
#include "../view/IPLAnalyserDisplay.h"
using namespace std;

int main(){
    const string MOST_RUNS_CSV_FILE_PATH = "../resources/IPL2019FactsheetMostRuns.csv";
    IPLAnalyserDisplay displayObj;
    displayObj.displayWelcomeMessage();

    IPLAnalyser analyser;
    vector<IPLMostRuns> batsmanDetailsList = analyser.loadCSVData(MOST_RUNS_CSV_FILE_PATH);
    IPLMostRuns batsman =  analyser.getBatsmanWithHighestAverage(batsmanDetailsList);
    displayObj.displayBatsmanWithHighestAverage(batsman);
}