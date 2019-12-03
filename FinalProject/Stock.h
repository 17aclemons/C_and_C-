#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>


using namespace std; 

class Stock{
    private:
    vector<string> Date;
    int counter; // used to change the range of dates
                         //use with other vector to keep information the same
    vector<double> Open; 
    vector<double> High;
    vector<double> Low;
    vector<double> Close;
    vector<double> AdjClose;
    vector<double> Volume;
    

    public: 
     Stock(string csv, string name);
    ~Stock();
    void printDate(Stock st);
    void setCounter(int ct);
};

#endif