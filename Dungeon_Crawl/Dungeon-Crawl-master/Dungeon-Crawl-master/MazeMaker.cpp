#include "MazeMaker.h"
#include "Combat.h"
#include <iostream>

using namespace std;

enum Room{ Entrance, ExtraCredit, Test, Nothing, Exit };
struct Cell {
	bool Marked;
	bool North;
	bool West;
	bool South;
	bool East;
	int X;
	int Y;
	Room Contains;
};

const int mazeSize = 5;
Player monsters[6];
Player p1;
Player gary;
Player nathan;
Player wallace;
Player kesar;
Player borisova;
Player rodriguez;
Player mary;
bool CheckForBlanks(Cell maze[mazeSize][mazeSize]);
void MazeInfo(Cell maze[mazeSize][mazeSize], int X, int Y);

int main()
{
	int currPath = 1;
	srand(time(NULL));

	Cell path[mazeSize * mazeSize];
	path[(mazeSize * mazeSize) - 1].Marked = false;
	enum Direction { N, W, S, E };


	//Pick character name
	cout << "What is your character name" << endl;
	string playerName;
	cin >> playerName;
	p1.name = playerName;

	//Pick character major
	cout << "Pick a major" << endl;
	cout << "cs, is, eet" << endl;
	string playerClass;
	cin >> playerClass;
	p1.degree = selectDegree(playerClass);
	
	//Other Player stuff
	p1.health = 390;
	p1.strength = 50;
	p1.state = alive;

	//Making a room for the maze
	Cell maze[mazeSize][mazeSize];

	for (int i = 0; i < mazeSize; i++)
	{
		for (int j = 0; j < mazeSize; j++)
		{
			maze[i][j].X = i;
			maze[i][j].Y = j;
			maze[i][j].Marked = false;
			maze[i][j].Contains = (Room)((rand() % 3) + 1);

			maze[i][j].West = true;
			maze[i][j].East = true;
			maze[i][j].North = true;
			maze[i][j].South = true;

			currPath++;
		}
	}

	maze[0][0].Contains = Entrance;
	maze[mazeSize - 1][mazeSize - 1].Contains = Exit;

	currPath = 0;

	//Carving the maze
	Cell current = maze[0][0];
	bool full = false;

	while (!full)
	{
		maze[current.X][current.Y].Marked = true;

		//choose a random direction
		Direction a = (Direction)(rand() % 4);

		if ((current.Y == 0 || maze[current.X][current.Y - 1].Marked) &&      //North is blocked
			(current.Y == mazeSize - 1 || maze[current.X][current.Y + 1].Marked) &&      //South is blocked
			(current.X == 0 || maze[current.X - 1][current.Y].Marked) &&      //West is blocked
			(current.X == mazeSize - 1 || maze[current.X + 1][current.Y].Marked))        //East is blocked
		{
			if (!CheckForBlanks(maze))
				full = true;

			current = path[currPath - 1];
			currPath--;
		}

		else
		{

			//North
			if (a == N && current.Y != 0 && !maze[current.X][current.Y - 1].Marked)
			{
				maze[current.X][current.Y].North = false;
				maze[current.X][current.Y - 1].South = false;
				path[currPath] = current;
				currPath++;
				current = maze[current.X][current.Y - 1];
			}

			//South
			else if (a == S && current.Y != mazeSize - 1 && !maze[current.X][current.Y + 1].Marked)
			{
				maze[current.X][current.Y].South = false;
				maze[current.X][current.Y + 1].North = false;
				path[currPath] = current;
				currPath++;
				current = maze[current.X][current.Y + 1];
			}

			//West
			else if (a == W && current.X != 0 && !maze[current.X - 1][current.Y].Marked)
			{
				maze[current.X][current.Y].West = false;
				maze[current.X - 1][current.Y].East = false;
				path[currPath] = current;
				currPath++;
				current = maze[current.X - 1][current.Y];
			}

			//East
			else if (a == E && current.X != mazeSize - 1 && !maze[current.X + 1][current.Y].Marked)
			{
				maze[current.X][current.Y].East = false;
				maze[current.X + 1][current.Y].West = false;
				path[currPath] = current;
				currPath++;
				current = maze[current.X + 1][current.Y];
			}

			else
			{
				a = (Direction)((int)a + 1);
			}
		}
	}
	
	//Make monsters
		Player monsters[6];

		gary.state = alive;
		gary.name = "Gary Cantrell";
		gary.health = 100;
		gary.strength = 5;
		gary.degree = cs;
		monsters[0] = gary;
		
		nathan.state = alive;
		nathan.name = "Nathan Barker";
		nathan.health = 150;
		nathan.strength = 10;
		nathan.degree = cs;
		monsters[1] = nathan;
		
		wallace.state = alive;
		wallace.name = "Gary Wallace";
		wallace.health = 100;
		wallace.strength = 5;
		wallace.degree = is;
		monsters[2] = wallace;
		
		kesar.state = alive;
		kesar.name = "Shalini Kesar";
		kesar.health = 150;
		kesar.strength = 10;
		kesar.degree = is;
		monsters[3] = kesar;
		
		borisova.state = alive;
		borisova.name = "Isabella Borisova";
		borisova.health = 100;
		borisova.strength = 5;
		borisova.degree = eet;
		monsters[4] = borisova;
		
		rodriguez.state = alive;
		rodriguez.name = "Oscar Rodriguez";
		rodriguez.health = 150;
		rodriguez.strength = 10;
		rodriguez.degree = eet;
		monsters[5] = rodriguez;

	//Printing a maze
	MazeInfo(maze, 0, 0);
}

bool CheckForBlanks(Cell maze[mazeSize][mazeSize])
{
	for (int j = 0; j < mazeSize; j++)
	{
		for (int i = 0; i < mazeSize; i++)
		{
			if (!maze[i][j].Marked)
				return true;
		}
	}

	return false;
}

void MazeInfo(Cell maze[mazeSize][mazeSize], int X, int Y)
{
    bool won = false;
    
	for (int j = 0; j < mazeSize; j++)
	{
		for (int i = 0; i < mazeSize; i++)
		{
		    if (i == X && j == Y)
		    {
		        if (maze[i][j].West)
				    cout << "|";
			    else
				    cout << " ";
				    
				if (maze[i][j].North)
				    cout << "X";
			    else
				    cout << "X";
		    }
		    
		    else
		    {
        		if (maze[i][j].West)
        			cout << "|";
        		else
        			cout << " ";
        
        		if (maze[i][j].North)
        			cout << "¯";
        		else
        			cout << " ";
		    }
		}
		cout << "|" << endl;
	}

	for (int s = 0; s < (mazeSize)+1; s++)
		cout << "¯ ";

    cout << endl;
	
	while (!won)
	{
		//Print Character Info
		
		if (p1.health > 400)
			p1.health = 400;
		
		cout << "GPA: " << p1.health/100 << endl;	//
		//cout << "Study Time: " << p1.strength << endl;
		cout << endl;
		
		//Print Room Info
		if (maze[X][Y].Contains == Nothing)
			cout << "The Room is Empty..." << endl;
		
		if (maze[X][Y].Contains == ExtraCredit)
		{
			cout << "There's a desk in the center of the Room!" << endl;
			cout << "You take a moment to work on an extra credit assignment." << endl;
			double GPAback = (rand() % 5)+1;
			p1.strength++;
			p1.health += GPAback;
			cout << "Your GPA went up! " << GPAback << " Extra Points!" << endl;
		}
		
		if (maze[X][Y].Contains == Test)
		{
			cout << "Pop Quiz!" << endl;
			int rnd; rnd = (rand())%6;
			cout << monsters[0].name << endl;
			p1 = combat(p1, monsters[rnd]);
			cout << "Test2!" << endl;
			
			
			if(p1.state == dead)
			{
				cout << "You have died" << endl;
				exit(0);
			}
		}
		
		//Movement and Win
	    if (maze[X][Y].Contains == Exit)
	    {
	        won = true;
	        cout << "You Won!" << endl;
	        //Print Winning Stuff
	        exit(0);
	    }

	    
    	if (!maze[X][Y].North)
    		cout << "There is a door to the North(w)" << endl;
    	
    	if (!maze[X][Y].West)
    		cout << "There is a door to the West(a)" << endl;
    	
    	if (!maze[X][Y].South)
    		cout << "There is a door to the South(s)" << endl;
    	
    	if (!maze[X][Y].East)
    		cout << "There is a door to the East(d)" << endl;
    		
    	char heading;
    	cin >> heading;
    	
    	if (heading == 'w' && !maze[X][Y].North)
    	    MazeInfo(maze, X, Y-1);
    	    
    	if (heading == 'w' && maze[X][Y].North)
    	    cout << "There's a Wall there..." << endl;
    	    
    	if (heading == 'a' && !maze[X][Y].West)
    	    MazeInfo(maze, X-1, Y);
    	    
    	if (heading == 'a' && maze[X][Y].West)
    	    cout << "There's a Wall there..." << endl;
    	    
    	if (heading == 's' && !maze[X][Y].South)
    	    MazeInfo(maze, X, Y+1);
    	    
    	if (heading == 's' && maze[X][Y].South)
    	    cout << "There's a Wall there..." << endl;
    	    
    	if (heading == 'd' && !maze[X][Y].East)
    	    MazeInfo(maze, X+1, Y);
    	    
    	if (heading == 'd' && maze[X][Y].East)
    	    cout << "There's a Wall there..." << endl;
    	    
    	else
    	    cout << "I don't Understand..." << endl;
	}
}


