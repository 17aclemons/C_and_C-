

#include "Stock.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <cstdlib>
#include <sstream>
#include <cstdlib> //for exit

using namespace std;

Stock::Stock(string csv, string name) // constructor
    {

        ifstream inf(csv.c_str());

        if (!inf)
        {
            cerr << "File couldn't be read" << endl;
            exit(1);
        }

        string line;
        while (getline(inf, line))
        {
            istringstream ss(line);
            //First part of a line is a string
            string token;
            getline(ss,token,',');
            Date.push_back(token);

            //rest of the token is doubles
            double temp [5];
            double dTemp;
            for(int i = 0; i < 5; i++){
                getline(ss,token,',');
                temp[i] = dTemp; 
            }
            Open.push_back(temp[0]);
            High.push_back(temp[1]);
            Low.push_back(temp[2]);
            Close.push_back(temp[3]);
            AdjClose.push_back(temp[4]);
            Volume.push_back(temp[5]);

            
                        //initialize the counter
                        //so when referenceing values in the vector
                        //it starts at the beginning of the data that
                        //has been read in
        }
    }

    

Stock::~Stock (){}

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