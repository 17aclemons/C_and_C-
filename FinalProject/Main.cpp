/*
Andrew Clemons
C and C++
Final Project
*/

/*
1. read in a csv
2. store the csv in a object
3. develop trade functions for csv  options
4. cout trade probability
*/

#include "Stock.h"
#include <iostream>
using namespace std;
int main()
{
    cout << "Download the csv files you want from Yahoo Finance" << endl;
    cout <<" and put it in the same folder as the executable" << endl;
    int stopCondition;
    while (stopCondition != 0)
    {
        cout << "" << endl; 
        cout << "Enter file name of Historical stock data" << endl;
        string file;
        cin >> file;
        cout << "Whats the name of the organization" << endl;
        string name;
        cin >> name;
        Stock one(file, name);
        cout << "Stock " << name << " was created" << endl;
        cout << "" << endl;
            while(stopCondition != 0){
                int choice;
                cout << "1.get Counter" << endl;
                cout << "2. set Counter" << endl;
                cout << "3. get the average Typical Price of " << one.getTitle() << endl;
                cout << "4. get the average Money Flow of " << one.getTitle() << endl; 
                cin >> choice;
                if(choice =1){
                    one.getCounter();
                }else if(choice = 2){
                    cout << "How many days do back do you want to look at" << endl;
                    int days;
                    cin >> days;
                    one.setCounter(days);
                }else if(choice = 3){
                    one.typicalPrice();
                }else if(choice = 4){
                    one.moneyFlow();
                }else if(choice = 0){
                    break;
                }
            }
        cout << "Press zero if you want to quit or press 1 make a new stock" << endl;
        cin >> stopCondition;
    }
}

/*
Rubric
Create an application in C++ complex enough to demonstrate the majority of presented concepts.

Project must demonstrate a concept not reviewed in class. not done
*/
