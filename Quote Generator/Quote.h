#ifndef QUOTE_H
#define QUOTE_H

#include <string> 
using namespace std; 

class Quote{
    public: 
    
     Quote(string sentance);

    string getQuote();
   
    ~Quote();
    private:
     string quote;
};

#endif