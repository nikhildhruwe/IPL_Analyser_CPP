#include <iostream>
#include "../model/IPLAnalyser.h"
#include "../view/IPLAnalyserDisplay.h"
using namespace std;

const string MOST_RUNS_CSV_FILE_PATH = "../resources/IPL2019FactsheetMostRuns.csv";

class IPLController{
    private :
        IPLAnalyserDisplay iplDisplayObj;
        IPLAnalyser iplAnalyserObj;
        vector<IPLMostRuns> batsmanDetailsList;
    public :
        IPLController(){
            batsmanDetailsList = iplAnalyserObj.loadCSVData(MOST_RUNS_CSV_FILE_PATH);
        }

        void displayWelcomeMessage(){
            iplDisplayObj.displayWelcomeMessage();
        }

        void displayBatsmanWithHighestAverage(){
            vector<IPLMostRuns> batsmanList =  iplAnalyserObj.getBatsmanWithHighestAverage(batsmanDetailsList);
            string message = "Top BAtting Average : ";
            iplDisplayObj.displayBatsmanDetails(batsmanList, message);
        }

        void displayBatsmanWithTopStrikingRates(){
            vector<IPLMostRuns> batsmanList =  iplAnalyserObj.getBatsmanWithTopStrikeRate(batsmanDetailsList);
            string message = "Top Strike Rate :";
            iplDisplayObj.displayBatsmanDetails(batsmanList, message);
        }
};

int main(){
   IPLController controller;
   controller.displayWelcomeMessage();
   controller.displayBatsmanWithHighestAverage();
   controller.displayBatsmanWithTopStrikingRates();

   return 0;
}