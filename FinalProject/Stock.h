#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>


using namespace std; 

class Stock{
    private:
    
  
    public: 
    vector<string> Date;
    vector<double> Open; 
    vector<double> High;
    vector<double> Low;
    vector<double> Close;
    vector<double> AdjClose;
    vector<double> Volume;
    
    string title;
    int counter; // used to change the range of dates
                 //use with other vector to keep information the same
     Stock(string csv, string name);
    ~Stock();
    void setCounter(int ct);
    int getCounter();
    void setTitle(string title);
    string getTitle();
    Stock operator++();
    double typicalPrice();
    double moneyFlow();
    
};

#endif