/////////////////////////////////
// Willard Wider               //
// Player.cpp                  //
// 11/01/16                    //
// Basketball player class     //
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


//constants


//structs


//typedefs


//other definitions
using namespace std;


Player::Player()
{
	name = "";
	number = 0;
	twoShotAcc = 0;
	threeShotAcc = 0;
}

Player::Player(string namee, int numberr, int twoShotAccc, int threeShottAccc)
{
	name = namee;
	number = numberr;
	twoShotAcc = twoShotAccc;
	threeShotAcc = threeShottAccc;
}

int Player::takeShot(int twoOrThree)
{
	//get an rng number from 1 to 100
	int rng = rand() %100 +1;
	//if the player number is greator than or equal to the rng value, count it.
	//else, don't
	if (twoOrThree)
	{
		//two point calculation
		if (twoShotAcc >= rng)
		{
			//count it
			return 2;
		}
		else
		{
			//don't
			return 0;
		}
	}
	else
	{
		//three point calculation
		if (threeShotAcc >= rng)
		{
			//count it
			return 3;
		}
		else
		{
			//don't
			return 0;
		}
	}
	return 0;
}

int Player::getTwoShotAcc()
{
	return twoShotAcc;
}

int Player::getThreeShotAcc()
{
	return threeShotAcc;
}

string Player::getName()
{
	return name;
}

int Player::getNumbah()
{
	return number;
}

Player::~Player()
{
}
