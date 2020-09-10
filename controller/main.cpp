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
        IPLController();
        void displayWelcomeMessage();
        void displayOptionsToSort();
};

IPLController ::IPLController(){
    batsmanDetailsList = iplAnalyserObj.loadCSVData(MOST_RUNS_CSV_FILE_PATH);
}

void IPLController ::displayWelcomeMessage(){
    iplDisplayObj.displayWelcomeMessage();
}

void IPLController ::displayOptionsToSort(){
    bool status = true;
    list<IPLMostRuns> batsmanList;
    while (status){
        int choice = iplDisplayObj.getSortChoice();
        switch (choice){
        case  AVERAGE :
            {
                system("clear");
                batsmanList =  iplAnalyserObj.getSortedList(batsmanDetailsList, AVERAGE);
                string message = "Top Batting Average : ";
                iplDisplayObj.displayBatsmanDetails(batsmanList, message);
            }
            break;
        case STRIKE_RATE :
            {
                system("clear");
                batsmanList =  iplAnalyserObj.getSortedList(batsmanDetailsList, STRIKE_RATE);
                string message = "Top strike rate : ";
                iplDisplayObj.displayBatsmanDetails(batsmanList, message);

            } 
            break;
        case SIX_FOUR :
            {
                system("clear");
                batsmanList =  iplAnalyserObj.getSortedList(batsmanDetailsList, SIX_FOUR);
                string message = "Highest 6s and 4s : ";
                iplDisplayObj.displayBatsmanDetails(batsmanList, message);
            }
            break;
        case STRIKE_RATE_AND_SIX_FOUR :
            {
                system("clear");
                batsmanList =  iplAnalyserObj.getSortedList(batsmanDetailsList, STRIKE_RATE_AND_SIX_FOUR);
                string message = "Top strike rate along with highest 6s and 4s.: ";
                iplDisplayObj.displayBatsmanDetails(batsmanList, message);
            }
            break;
         case AVERAGE_AND_STRIKE_RATE :
            {
                system("clear");
                batsmanList =  iplAnalyserObj.getSortedList(batsmanDetailsList, AVERAGE_AND_STRIKE_RATE);
                string message = "Top average along with strike rate: ";
                iplDisplayObj.displayBatsmanDetails(batsmanList, message);
            }
            break;
        case 6 :
            status = false;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

int main(){
   IPLController controller;
   controller.displayWelcomeMessage();
   controller.displayOptionsToSort();

   return 0;
}