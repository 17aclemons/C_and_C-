// Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

#include <iostream>
#include <fstream> 
#include <ostream>
#include <cstdlib> //for exit
#include "Stock.h"

using namespace std;
int main() {
    cout << "Enter file name of Historical stock data" << endl; 
    string file; 
    cin >> file; 
	cout << "Whats the name of the organization" << endl;
    string name;
    cin >> name; 
    Stock  one (file,name);

}

/*
Rubric
Create an application in C++ complex enough to demonstrate the majority of presented concepts.

Project must demonstrate basic concepts.

Project must demonstrate object oriented programming.

Project must demonstration operator overloading with a unique class type.

Project must include C++ exception handling.

Project must demonstrate a concept not reviewed in class.
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
