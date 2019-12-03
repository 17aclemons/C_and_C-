

#include "Stock.h"
#include <iostream>
#include <fstream> 
#include <ostream>
#include <cstdlib>

using namespace std; 

    Stock::Stock(string csv, string name){ // constructor
        ifstream inf(csv.c_str());

            if (!inf) {
		    cerr << "File couldn't be read" << endl;
		    exit(1);
	        }

            string line;
            ofstream outf("test.txt");
            stringstream ss
            while(getline(inf,line)) {
                
                outf << line;
            }
        }

    Stock::~Stock(){} // destructor

//each stock has a day vector
//open vector
//close vector
//volume vector
//high vector
//volume vecotor

/*
ofstream outf("test.txt");
	
	if (!outf) {
		cerr << "Failed" << endl; 
	}
     string day; 
    while(getline(inf, day)){
        outf << day << endl; 
    }
    */