

#include "Quote.h"
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

