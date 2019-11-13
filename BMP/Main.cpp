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
#include <algorithm> // for max
#include <vector>

using namespace std;





int main(int argc, char* argv[]) {
	//argv[1] is the method chosen
	//argv[2] is file converted
	
	ifstream inf(argv[2]);
	if (!inf)
	{
		cerr << "unable to open file for writing!" << endl;
		exit(1);
	}
	vector<unsigned char> bmp;

	while(inf){
		unsigned char temp;
		inf >> hex >> temp;
		bmp.push_back(temp);
	}
	inf.close();
	
	//1. Is a BMP file
	if(bmp[0] == 'B' && bmp[1] == 'M'){
		cout << "Is a BMP file" << endl; 
	}else{
		cout << "not a BMP file" << endl;
	}
	
	//2. get the size and check
	// bit shifting
	int size = (uint32_t)bmp[5] << 24 |
	(uint32_t) bmp[4] << 16 |
	(uint32_t) bmp[3] << 8 |
	(uint32_t) bmp[2];
	cout << "file size is: " << size << endl;
	
	if(size != bmp.size()){
		cerr << "File size indicated isn't the amount read in " << endl; exit(1);
	}
	
	//3. append conversion method to file name
	int method = stoi(argv[1]); //convert conversion string to int
	//check for proper input
	if(method > 3 || method < 1){
		method = 1; 
	}
	
	string name = argv[2];
	if(method == 1){ 
		//lightness method  Lightness method: (max(R,G,B) + min (R,G,B)) / 2
		//lightness file name
		string file = "BW_lightnessConversion_" + name ;
		
		ofstream outf(file);
			if (!outf)
			{
				cerr << "unable to open file for writing!" << endl;
				exit(1);
			}
			
			for(int i = 10; i < 20; i++){
				int compare = max(max(bmp[i],bmp[i+1]),bmp[i+2]);
				
				compare = min(bmp[i],bmp[i+1]);
				int min = min(bmp[i+2],compare);
				
				unsigned char output = (max + min)/2;
			}
		
		outf.close();
	}else if(method == 2){
		//average method Average method: (R+G+B)/3
		//average file name
		string file = "BW_AverageConversion_" + name ;
		
		ofstream outf(file);
			if (!outf)
			{
				cerr << "unable to open file for writing!" << endl;
				exit(1);
			}
			
		
	}else if(method == 3){
		//lumonosity method Luminosity method: .21 * R + .72 * G + .07 * B
		
		//lumonosity file name
		string file = "BW_LumonosityConversion_" + name ;
		
		ofstream outf(file);
			if (!outf)
			{
				cerr << "unable to open file for writing!" << endl;
				exit(1);
			}
	}
		
	
}