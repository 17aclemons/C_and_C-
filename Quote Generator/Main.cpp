/* Andrew Clemons
Quote Generator Lab
*/
#include "Quote.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> //for exit

using namespace std; 

vector<Quote> createVector(string fileName);
void addQuote(vector<Quote> quoteVector); 
void randomQuote(vector<Quote> quoteVector);
void removeQuote(vector<Quote> quoteVector);
void specificQuote(vector<Quote> quoteVector);
void numberOfQuotes(vector<Quote> quoteVector);

int main(int argc, char* argv[]){
    
    if(argc == 2){
        
        vector<Quote> option1 = createVector(argv[1]);
        randomQuote(option1); 

    }else if(argc == 1){
        vector<Quote> option2 = createVector(""); 

        cout << "1. Get random quote" << endl;
        cout << "2. Add quote" << endl;
        cout << "3. Remove quote by line"<< endl; 
        cout << "4. Get specific quote by line" << endl; 
        cout << "5. Get number of current quotes" << endl;

        int input;
        cin >> input;

        if(input == 1){
            randomQuote(option2); 
        }else if(input == 2){
            addQuote(option2); 
        }else if(input == 3){
            removeQuote(option2);
        }else if(input == 4){
            specificQuote(option2);
        }else if(input == 5){
            numberOfQuotes(option2);
        }else {
            cout << "invalid input" << endl;
        }
        delete option2; 
    }
    delete option1; 
}

vector<Quote> createVector(string fileName = ""){
    if(fileName == ""){
        cout << "input a file name" << endl;
        cin >> fileName; 
    }
    //create a vector of quote objects
    vector<Quote> allQuotes;
    ifstream inf(fileName.c_str());

    if(!inf){
        cerr << "file is broke" << endl; 
        exit(1); 
    }

    string quote;
    while(getline(inf, quote)){
        Quote test(quote); 

        allQuotes.push_back(test);  

    }
    inf.close();

    return allQuotes;  
}


void randomQuote(vector<Quote> quoteVector){
    int random = rand() % quoteVector.size();   
    string temp = quoteVector[random].getQuote();
    cout << temp << endl; 
}

void addQuote(vector<Quote> quoteVector){
    cout << "input the new quote" << endl; 

    string newQuote;
    cin >> newQuote; 
    Quote test(newQuote);
    quoteVector.push_back(test); 

    cout << "Quote was added" << endl; 
}

void removeQuote(vector<Quote> quoteVector){
    for(int i = 0; i < quoteVector.size(); i ++){
        cout << i << "." << quoteVector[i].getQuote() << endl; 
    }

    cout << "What line do you want to delete" << endl; 
    int remove; 
    cin >> remove; 

    quoteVector.erase(quoteVector.begin() + remove); 

    cout << "line " << remove << " was deleted" << endl; 
}

void specificQuote(vector<Quote> quoteVector){
    for(int i = 0; i < quoteVector.size(); i ++){
        cout << i << "." << quoteVector[i].getQuote() << endl; 
    }

    cout << "What specific line do you want" << endl; 
    int get;
    cin >> get;

    cout << "Requested Quote" << endl; 
    cout << quoteVector[get].getQuote() << endl; 
}

void numberOfQuotes(vector<Quote> quoteVector){
    cout << quoteVector.size() << endl; 
}
