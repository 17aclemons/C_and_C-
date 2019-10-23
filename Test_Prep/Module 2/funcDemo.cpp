/*
Demo code for functions in C++
Dr. G
9-2-19
*/

#include <iostream>
#include "funcDemo.h"

using namespace std;

//forward declaration


int main()

{
	
	cout << "Hiya\n" << add() << endl;
}



//1. Compile and test code with no changes
//2. Create an add function above main
//3. Move the function below main and observe the results
//4. Declare the function above main with a function prototype and observe the results
//5. Demonstrate method overload

//returning values and function arguments work the same as Java
//in general variable scope is the same as Java
//white space in C++ is irrelevant 

//6. Place the add function in a separate file, recompile and test. 
//7. Remove the prototype and observe the results. What happens and why?
//8. Restore to working order. 

//9. Use a preprocessor directive to define a CAT as  "NEX." Print and observe the results
//10. Demonstrate the use of #ifdef #ifndef and #endif
	//#ifdef only runs if what comes after has already been defined. 
	//#ifndef only runs if it isn't defined
	//#endif is for the end of your ifdef or ifndef statements
//11. Create a header file for the add function and include it here

//steps 12-13 are in funcDemo.h

//14. include the header file here and observe the results
