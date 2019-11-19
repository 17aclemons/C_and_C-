#ifndef QUOTE_H
#define QUOTE_H
#include <string>

using namespace std; 

class Quote {
    public: 
    string quote; 

    Quote(string sentance){ // constructor
        quote = sentance; 
    }

    ~Quote (); // destructor
};

#endif