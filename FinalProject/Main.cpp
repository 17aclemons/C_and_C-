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
        cout << "Stock " << name << "was created" << endl;
        cout << "" << endl; 
        cout << "Press zero if you want to quit or press 1 make a new stock" << endl;

        one.typicalPrice();
    }
}

/*
Rubric
Create an application in C++ complex enough to demonstrate the majority of presented concepts.

Project must include C++ exception handling. not done

Project must demonstrate a concept not reviewed in class. not done
*/
