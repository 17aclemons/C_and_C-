//Basic  Structure Demonstation File
//8/28/19
//Dr. G

//Preprocessor directives
#include <iostream>

//Defining namespace
using namespace std;


//main function
int main()
	{
	
	//1. Declare an int variable x
	
	/*
	Ways to initialize: 
	int x, y; 
	int x = 0;
	int x(0);
	int x{};
	int x{4};
	
	What is direct vs indirect assignment?
	What happens behind the scenes when you declare a variable?
		The compiler allocates memomory for that variable.
	What happens if you don't initialize a variable?
		the variable has the value of what is already located in that spot in memory
	*/
	
	//2. Prompt the user for an integer value
	int x = 0; 
	cout << "Integer Value" << endl;
	cin >> x; 
	cout << x << endl; 
	/*
	What does cout stand for?
		character output
	What is the difference in endl and \n?
	What is the << called and what does it do?
		insertion operator
	*/
	
	
	//3. Save that input into a variable
	
	/*
	What does cin stand for?
		character input
	What's a common mistake with cin and cout?
	using insertion (<<) vs extraction (>>) operators
	*/
	
	//4. Print that variable and that variable + 10
	
	return 0;
	}
