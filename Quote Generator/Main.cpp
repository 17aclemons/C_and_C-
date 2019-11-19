/* Andrew Clemons
Quote Generator Lab
*/
#include "Quote.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> //for exit

using namespace std; 

int main(int argc, char* argv[]){
    //create a vector of quote objects
    vector<Quote> allQuotes;
    int count = 0; 
    
    ifstream inf(argv[1]);

    if(!inf){
        cerr << "file is broke" << endl; 
        exit(1); 
    }

    while(inf){
        
        string quote; 
        getline(inf, quote); 
        cout << quote << endl; 
        Quote test(quote); 

        allQuotes[count] = test; 
        count++; 
    }
}