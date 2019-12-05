

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
    if (csv == "")
    {
        cerr << "CSV file not included" << endl;
        exit(1);
    }
    else if (name == "")
    {
        cerr << "Name was left null" << endl;
        exit(1);
    }
    else
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
            getline(ss, token, ',');
            Date.push_back(token);

            //rest of the token is doubles
            double temp[5];
            double dTemp;
            //fill a temp array
            for (int i = 0; i < 5; i++)
            {
                getline(ss, token, ',');
                temp[i] = dTemp;
            }
            //use the temp array to push the data onto vectors
            Open.push_back(temp[0]);
            High.push_back(temp[1]);
            Low.push_back(temp[2]);
            Close.push_back(temp[3]);
            AdjClose.push_back(temp[4]);
            Volume.push_back(temp[5]);

            setCounter(1);
            //initialize the counter, ignore the header
            //so when referenceing values in the vector
            //it starts at the beginning of the data that
            //has been read in
        }
    }
}

void Stock::setCounter(int ct)
{
    counter = ct;
}

int Stock::getCounter()
{
    return counter;
}

void Stock::setTitle(string name)
{
    title = name;
}

string Stock::getTitle()
{
    return title;
}

//increment the counter to shorten the amount of data looked at
Stock Stock::operator++()
{
    ++counter;
    return *this;
}

double Stock::typicalPrice()
{

    vector<double> tp;
    double temp = 0;
    double total;
    double smallest;
    double highest;
    //fill the vector with the average price per day
    for (int i = counter; i < Date.size(); i++)
    {
        temp = (High[i] + Low[i] + Close[i] / 3);
        total += temp;
    }
    int days = Date.size() - counter;
    double typicalPrice = (temp / days);

    cout << "the typical price over " << days << " days is " << typicalPrice << " dollars" << endl;
    return typicalPrice;
}

double Stock::moneyFlow(){
    double tp = typicalPrice();
    double totalVolume;
    int days = Date.size() - counter; 
    for(int i = counter; i < Date.size(); i++){
        totalVolume += Volume[i];
    }
    double avgVolume = (totalVolume / Date.size());

    cout << "the Money Flow price over "<< days << " days is " << tp*avgVolume << " dollars" << endl; 
    return tp*avgVolume;
}

Stock::~Stock() {}

int main(){
    Stock one("test.csv", "test");
    one.typicalPrice();
    cout << one.High[1] << endl;
    cout << one.Low[1] << endl;
}
