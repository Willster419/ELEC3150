/////////////////////////////////
// Willard Wider               //
// Main.cpp                    //
// 11/01/16                    //
// Lab 8                       //
// Last Modified 11/01/16      //
/////////////////////////////////

//C library includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>

//user includes
#include "LabAPI.h"
#include "Player.h"

//defines
#define TEAM_LENGTH 5

//constants


//structs and typedefs


//method prototypes if no header
bool withinRange(Player team[],bool twoOrThree);
int takeTheShot(Player team[]);

//other definitions
using namespace std;


//the main entry point of the application
int main()
{
	int totalPoints = 0;//int ot keep track of total points
	Player team[5];//array of players
	Player p1 = *new Player("xXx_Willster420NoScope_xXx",69,40,35);
	Player p2 = *new Player("Bryon",42,95,60);
	Player p3 = *new Player("Brandon",12,40,10);
	Player p4 = *new Player("Dooooon",0,45,45);
	Player p5 = *new Player("Mike",27,80,50);
	team[0] = p1;
	team[1] = p2;
	team[2] = p3;
	team[3] = p4;
	team[4] = p5;
	//check to make sure all 5 player's total 2 and 3 point percentages are within range
	if (!withinRange(team,true))
	{
		print("200 point is not withen range");
		return -1;
	}
	if (!withinRange(team,false))
	{
		print("300 point is not withen range");
		return -1;
	}
	//taking 100 shots from random people in the list
	for (int i = 0; i < 100; i++)
	{
		totalPoints+=takeTheShot(team);
	}
	print("total points in the end is ",totalPoints);
	return 0;
}

//determins if the arraylist of players' two or three shot percentages are withen the allowed limit
//true = withen range, false = outside of range
bool withinRange(Player team[], bool twoOrThree)
{
	int counter = 0;
	int limit = 0;
	if (twoOrThree)
	{
		//two point calculation
		limit = 300;
		for (int i = 0; i < TEAM_LENGTH; i++)
		{
			counter+=team[i].getTwoShotAcc();
		}

	}
	else
	{
		//three point calculation
		limit = 200;
		for (int i = 0; i < TEAM_LENGTH; i++)
		{
			counter+=team[i].getThreeShotAcc();
		}
	}
	if (counter < limit)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//takes a shot of a random player on the team of a random type eithor 2 or 3 point
//returns the value, 0 meaning no shot made, 2 meaning 2 point shot made, or 3 meaning 3 point shot made
int takeTheShot(Player team[])
{
	ostringstream temp;
	int selectedIndex = rand() % TEAM_LENGTH;
	int result = team[selectedIndex].takeShot(rand() %2);
	temp << "index " << selectedIndex << ", " << team[selectedIndex].getName() << " shot for " << result << " points";
	print(temp.str());
	return result;
}