/*Andrew Clemons
C and C++
BMP Assignment
Fall 2019
*/

#include <fstream>
#include <iostream>
#include <cstdlib> // for exit
using namespace std;

typedef char BYTE;

int main(int argc, char *argv[]) {


	ifstream inf("1_Created.bmp");
	//1.Check first two bytes to make sure it is a BMP File
	BYTE* buffer = new BYTE[2];

	inf >> buffer[0];
	inf >> buffer[1];
	
	if(buffer[0] == 'B' && buffer[1] == 'M'){
		cout << "TRUE" << endl;
	}
	//2. Extract and print the size;
	//3. Create a new file 
	//ofstream outf(file + "BW_"); 
	if (!outf)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened for writing!" << endl;
        exit(1);
    }
	//4. Comment Code
	
	if(argv[1] == '1'){
		//lightness method
	}else if(argv[1] == '2'){
		//average method
	}else if(argv[1] == '3'){
		//lumonosity method
	}

}


void lightness(){
	
}

void average(){
	
}

void lumonosity(){
	
}