/*Andrew Clemons
C and C++
BMP Assignment
Fall 2019
*/

#include <fstream>
#include <iostream>

using namespace std;

typedef char BYTE;

int main() {

	ifstream inf("1_Created.bmp");
	BYTE b = 0xff; 

	BYTE* c = new BYTE[2];

	inf >> c[0];
	inf >> c[1];
	
	if(c[0] == 'B' && c[1] == 'M'){
		cout << "TRUE";
	}
	
	BYTE * buffer = new char[4];
	inf.read(buffer, 4);
	cout << hex << buffer[0];
	cout << hex << buffer[1];
	cout << hex << buffer[2];
	cout << hex << buffer[3];
	//cout << std::hex << c[0] << " " << +c[0] << " " << c[1] << " " << +c[1] << '\n';
	//cout << std::hex << int (c[0]) << " " << int (+c[0]) << " " << c[1] << " " << +c[1] << '\n';
	//if (c[0] == 0x42) cout << "TRUE" << endl; 	//here it is compared as a hex value
	//if (c[0] == 'B') cout << "TRUE" << endl;	//here it is compared as a char value
	//if (c[0] == 66) cout << "TRUE" << endl;		//here it is compared as an int value
}