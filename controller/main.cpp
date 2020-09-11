#include <iostream>
#include "../model/IPLAnalyser.h"
#include "../view/IPLAnalyserDisplay.h"
using namespace std;

const string MOST_RUNS_CSV_FILE_PATH = "../resources/IPL2019FactsheetMostRuns.csv";
const string MOST_WICKETS_CSV_FILE_PATH = "../resources/IPL2019FactsheetMostWkts.csv";

class IPLController{
    private :
        IPLAnalyserDisplay iplDisplayObj;
        IPLAnalyser iplAnalyserObj;
        vector<IPLMostRuns> batsmanDetailsList;
        vector<IPLMostWickets> bowlersDetailsList;
    public :
        IPLController();
        void displayWelcomeMessage();
        void displayOptionsToSort();
};

IPLController ::IPLController(){
    batsmanDetailsList = iplAnalyserObj.loadBatsmanCSVData(MOST_RUNS_CSV_FILE_PATH);
    bowlersDetailsList = iplAnalyserObj.loadBowlersCSVData(MOST_WICKETS_CSV_FILE_PATH);
}

void IPLController ::displayWelcomeMessage(){
    iplDisplayObj.displayWelcomeMessage();
}

void IPLController ::displayOptionsToSort(){
    bool status = true;
    list<IPLMostRuns> batsmanList;
    list<IPLMostWickets> bowlersList;
    while (status){
        int choice = iplDisplayObj.getSortChoice();
        system("clear");
        switch (choice){
        case  BATSMAN_AVG :
            {
                batsmanList =  iplAnalyserObj.getBatsmanSortedList(batsmanDetailsList, BATSMAN_AVG);
                string message = "Top Batting Average : ";
                iplDisplayObj.displayBatsmanDetails(batsmanList, message);
            }
            break;
        case BATTING_STRIKE_RATE :
            {
                batsmanList =  iplAnalyserObj.getBatsmanSortedList(batsmanDetailsList, BATTING_STRIKE_RATE);
                string message = "Top strike rate : ";
                iplDisplayObj.displayBatsmanDetails(batsmanList, message);
            } 
            break;
        case SIX_FOUR :
            {
                batsmanList =  iplAnalyserObj.getBatsmanSortedList(batsmanDetailsList, SIX_FOUR);
                string message = "Highest 6s and 4s : ";
                iplDisplayObj.displayBatsmanDetails(batsmanList, message);
            }
            break;
        case STRIKE_RATE_AND_SIX_FOUR :
            {
                batsmanList =  iplAnalyserObj.getBatsmanSortedList(batsmanDetailsList, STRIKE_RATE_AND_SIX_FOUR);
                string message = "Top strike rate along with highest 6s and 4s : ";
                iplDisplayObj.displayBatsmanDetails(batsmanList, message);
            }
            break;
        case AVERAGE_AND_STRIKE_RATE :
            {
                batsmanList =  iplAnalyserObj.getBatsmanSortedList(batsmanDetailsList, AVERAGE_AND_STRIKE_RATE);
                string message = "Top average along with strike rate : ";
                iplDisplayObj.displayBatsmanDetails(batsmanList, message);
            }
            break;
        case MAX_RUNS_AND_AVERAGE :
            {
                batsmanList =  iplAnalyserObj.getBatsmanSortedList(batsmanDetailsList, MAX_RUNS_AND_AVERAGE);
                string message = "Maximum runs with best average : ";
                iplDisplayObj.displayBatsmanDetails(batsmanList, message);
            }
            break;
        case BOWLING_AVG :
             {
                bowlersList =  iplAnalyserObj.getBowlersSortedList(bowlersDetailsList, BOWLING_AVG);
                string message = "Top Bowling Average : ";
                iplDisplayObj.displayBowlersDetails(bowlersList, message);
            }
            break;
        case BOWLING_STRIKE_RATE :
             {
                bowlersList =  iplAnalyserObj.getBowlersSortedList(bowlersDetailsList, BOWLING_STRIKE_RATE);
                string message = "Top Bowling Strike Rate : ";
                iplDisplayObj.displayBowlersDetails(bowlersList, message);
            }
            break;
        case BOWLING_ECONOMY_RATE :
             {
                bowlersList =  iplAnalyserObj.getBowlersSortedList(bowlersDetailsList, BOWLING_ECONOMY_RATE);
                string message = "Top Bowling Economy Rate : ";
                iplDisplayObj.displayBowlersDetails(bowlersList, message);
            }
            break;
        case STRIKE_RATE_5W_AND_4W :
             {
                bowlersList =  iplAnalyserObj.getBowlersSortedList(bowlersDetailsList, STRIKE_RATE_5W_AND_4W);
                string message = "Top Bowling Economy Rate : ";
                iplDisplayObj.displayBowlersDetails(bowlersList, message);
            }
            break;
        case 11 :
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