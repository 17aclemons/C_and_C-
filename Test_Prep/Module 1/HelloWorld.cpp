//Basic  Structure Demonstation File
//6/24/19
//Dr. G


//1.  Code Comments

//Code comments are the same as Java
/* This is a C style comment for blocks of code */
// This is a C++ style comment for a single line

//Make sure to start every program you create with a comment block!!


//2. Include preprocessor directives for needed outside libraries with #include <>
//Note: that no ';' is needed for includes. 
//For a HelloWorld program we need the iostream library


//#include <>


//3. Declare and/or create any functions needed in your program other than main. 
//We won't be doing that for this program. 

//4. Create your main function as an int function with no arguments.
//Declaration looks similar to java. Surrond the function body with {}. 
//Note: In C++ we call them functions not methods because they aren't, by default, part
//of a class.

//Start main function
int main(){
	





//5. Use the following to send information out to stdout 

std::cout<<"Hello, World!" << endl;

/* Complete the following for your own notes
std -> is a namespace
:: -> is a scope operator
cout -> prints to command line
<< -> insertion operator
"" -> converts text inside to character array
endl -> jumps to next line in command line
; -> tells compiler you are at the end of a command
*/

//6. Use "return 0;" to end the main. 


//End main function


//7.Compile, run, and test
//Note for now don't worry about the linking. We are going to start with only a single file

//Save the file in a test directory and use this command: 
//g++ HelloWorld.cpp

//What is the name of the resulting executable?

//Try this : g++ -o Hello.exe HelloWorld.cpp

//What is the name of the resulting executable?


//8. An example of C++ weirdness
//Remove the return.
//Compile, run, and test

//What were the results?

//Place another cout statement after the return. 
//Compile, run, and test

//What were the results?



//9. Namespaces

//I wanted you to see what std:: is used for, but now we will simplify things. 
//add "using namespace std;" above main and remove "std::"
//Compile, run, and test

/* 
other things to note

1. Most lines end with a ';'
2. C++ is case sensitive
3. C++ is a strongly typed language
4. Spaces don't matter

*/
