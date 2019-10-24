/*
Andrew Clemons 
C and C++
Zombies and Pointers
10/23
*/

	
#include <iostream>
#include <cstdlib>

using namespace std;
	
	//function declarations
	void placeZombies(char*, int, char**, int);
	void displayRoom(int);

	//Declare a const global variable to point "stunned" zombies at
	char*  stunned = NULL; 
	
	//1. accept as command line inputs: number of rooms, max number of zombies, and zombie 
	//regeneration rate (done)

	int main(int argc, char* argv[]){
		
		int numOfRooms;
		int maxZom;
		int regenRate;
		
		//2. Gather command line input and verify they entered enough arguments and that there are 
		//more rooms than zombies
		if(argc == 4 && atoi(argv[1]) > atoi(argv[2])){
			numOfRooms = atoi(argv[1]);
			maxZom = atoi(argv[2]);
			regenRate = atoi(argv[3]); 
			
		}else{
			
			cout << "you messed up the inputs, setting to defalut" << endl; 
			//assign default values
			 numOfRooms = 10; 
			 maxZom = 5; 
			 regenRate = 1; 
		}
		//current number of zombies in array
		int currentZomb = maxZom;

	//3. Create a dynamic character area to represent the rooms and initialize the area to 
	//all 'E's
	char* area = new char[numOfRooms];
	for(int i = 0; i < numOfRooms; i++){
		area[i] = 'E'; 
		
	}
	
	//4. Create an array of char pointers to represent the zombies. Array will be the max 
	//number of zombies
	char ** zombies = new char*[maxZom];
	
	//5. Randomly point zombies at rooms array. When a zombie points at a room space change 
	//the letter in the array to Z. Remember, because we are using pointers you can have more than one
	//zombie in a room. 
	placeZombies(area, numOfRooms, zombies, maxZom);
	
	//6. Start game loop
		while(currentZomb >0){
			
		
	//7. Display rooms as '*' place numbers underneath so the user can easily see where they 
	//can shoot. Ex

	//* * * * * * *
	//1 2 3 4 5 6 7
	displayRoom(numOfRooms);
	//8. Prompt user to pick a room to "shoot" in. 
	cout << "Pick a room to shoot" << endl;
	int shoot; 
	cin >> shoot;  
	//9. Reveal the current zombie distribution. Example: E E Z E E Z Z E E. 
	
	bool z = false;
	for(int i = 0; i < numOfRooms; i++){
		for(int j = 0; j < currentZomb; j++){
			if(*(zombies[j]) == area[i]){
				cout << "Z ";
				z = true; 
				break;
			}
		}
		if(!z){
			cout << "E "; 
		}
		z = false; 	
	}
	//10.  Check to see if and how many zombies pointed at that room. Point all zombies that 
	//were in that room to the "stunned" constant. 
	for(int i = 0; i < currentZomb; i++){
		if(*(zombies[i]) == area[shoot]){
			zombies[i] = stunned; 
		}
	}
	//11. Report zombies left and change all rooms to 'E.'

	//12. Cycle through the zombie pointer array. Point each zombie at a new random location 
	//unless it is stunned. For each stunned zombie offer a chance of regeneration based on 
	//the regeneration rate. For example, 3 would indicate a 3% chance it would regenerate. 
	//(You can do this by selecting a random number from 1 to 100.)

	//13. If all zombies are dead, terminate loop

	//14. End game loop
		currentZomb = 0; 
		}
	//15. Report success
	//cout << "Good Fucking job" << endl; 
	}


	//function for zombie placement in rooms
	void placeZombies(char* room, int sizeOfRoom, char** zombies, int numZom){
		for(int i = 0; i < numZom; i++){
			//if(*(zombie[i]) != stunned){
			int rng = rand() % sizeOfRoom; 
			zombies[i] = &room[rng];
			//}
			room[rng] = 'Z'; 
		}	
	}
	//function for displaying field
	void displayRoom(int numOfRooms){
		cout << endl; 
		for(int i = 0; i < numOfRooms; i++){
			cout << "* "; 
		}
		cout << endl; 
		for(int i = 0; i < numOfRooms; i++){
			cout << i+1 << " "; 
		}
		cout << endl;
	}
	//function for counting active zombies
	
	