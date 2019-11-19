

#include "Quote.h"
#include <string>

using namespace std; 

    Quote::Quote(string sentance){ // constructor
        quote = sentance; 
    }

    string Quote::getQuote(){
       return quote;
    }

    Quote::~Quote (){} // destructor

