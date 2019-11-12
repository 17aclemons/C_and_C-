//Program 1

#include <iostream>
#include <fstream>

using namespace std;

typedef char BYTE;

int main()
{
	ifstream inf("1_Created.bmp");
	BYTE b = 0xff;

	if (!inf)
	{
		cerr << "unable to open file for writing!" << endl;
	}

	
	/*while(inf)
	{
		inf >> b;
		std::cout << std::hex << +b;
	}*/

	//1. instead of looping just get the first two unsigned chars and check them
	
	BYTE* c = new BYTE[2];

	inf >> c[0];
	inf >> c[1];

	cout << std::hex << c[0] << " " << +c[0] << " " << c[1] << " " << +c[1] << '\n';
	cout << std::hex << int (c[0]) << " " << int (+c[0]) << " " << c[1] << " " << +c[1] << '\n';

	if (c[0] == 0x42) cout << "TRUE" << endl; 	//here it is compared as a hex value
	if (c[0] == 'B') cout << "TRUE" << endl;	//here it is compared as a char value
	if (c[0] == 66) cout << "TRUE" << endl;		//here it is compared as an int value


	//2. what if we wanted to get a number?
	//why doesn't this work
	/*
	int x = 0;
	inf >> x;
	cout << "Number = " << x << endl;
	*/

	
	BYTE d;
	int x;
	inf >> d;
	x = d;
	cout << x << endl;
	

	
	BYTE * buffer = new char[4];
	inf.read(buffer, 4);
	cout << buffer[0] << endl;
	


	inf.close();

}