/*Andrew Clemons
C and C++
BMP Assignment
Fall 2019
*/

#include <fstream>
#include <iostream>
#include <ostream>
#include <cstdlib> // for exit
#include <string>
#include <algorithm>

using namespace std;


int main(int argc, char* argv[]) {
	//argv[1] will is method
	//argv[2] is file converted
	
	ifstream inf(argv[2]);
	if (!inf)
	{
		cerr << "unable to open file for writing!" << endl;
	}
	
	char* c = new char[2];
	
	inf >> c[0];
	inf >> c[1];
	
	//1. Check if BMP file
	if(c[0] == 'B' && c[1] == 'M'){
		cout << "Is a BMP file" << endl;
	}else {
		cout << "Not a BMP file" << endl; 
	}
	
	//2. Get size of BMP File (still need size check)
	unsigned char* d = new unsigned char[4];
	inf >> d[0];
	inf >> d[1];
	inf >> d[2];
	inf >> d[3];
	
	int size = (uint32_t)d[3] << 24 |
	(uint32_t) d[2] << 16 |
	(uint32_t) d[1] << 8 |
	(uint32_t) d[0];
	
	cout << "file size is: " << size << endl;



	//3. append conversion method to file name
	string a = argv[1];
	int method = stoi(a); 
	
	if(method == 1){
		//lightness method
		string stuff = argv[2];
		string file = "BW_lightnessConversion_" + stuff ;
		
		ofstream outf(argv[2]);
		if (!outf)
		{
			cerr << "unable to open file for writing!" << endl;
		}
	
	}else if(method == 2){
		//average method
	}else if(method == 3){
		//lumonosity method
	}

}
