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

//basic constructor that inits the object with 0 values
Player::Player()
{
	name = "";
	number = 0;
	twoShotAcc = 0;
	threeShotAcc = 0;
}

//advanced constructor that inits the object with the 4 specified values
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
	
	//if doing two point shot calculation
	if (twoOrThree)
	{
		//if the player 2 shot accuracy number is greator than or equal to the rng value, count it.
		if (twoShotAcc >= rng)
		{
			return 2;
		}
		//else, don't
		else
		{
			return 0;
		}
	}
	//else, doing three point shot calculation
	else
	{
		//if the player 3 shot accuracy number is greator than or equal to the rng value, count it.
		if (threeShotAcc >= rng)
		{
			return 3;
		}
		//else, don't
		else
		{
			return 0;
		}
	}
	return 0;
}

//the following 4 methods get each respective private variable
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

//the following 4 methods set each repsective private variable
void Player::setTwoShotAcc(int twoShot)
{
	twoShotAcc = twoShot;
}

void Player::setThreeShotAcc(int threeShot)
{
	threeShotAcc = threeShot;
}

void Player::setName(string nayme)
{
	name = nayme;
}

void Player::setNumbah(int de_numbah)
{
	number = de_numbah;
}

//and a deconstructor
Player::~Player()
{
}
