/////////////////////////////////
// Willard Wider               //
// Player.h                    //
// 11/01/16                    //
// Header for Basketball class //
// Last Modified 11/01/16      //
/////////////////////////////////

//C library includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>

//header guard
#ifndef PLAYER_H
#define PLAYER_H

//other definitions
using namespace std;

//method/class prototypes

class Player
{

private:
	string name;
	int number;
	int twoShotAcc;
	int threeShotAcc;

public:
	Player();
	Player(string namee, int numberr, int twoShotAccc, int threeShottAccc);
	int getTwoShotAcc();
	int getThreeShotAcc();
	int takeShot(int twoOrthree);
	string getName();
	int getNumbah();
	~Player();

};

#endif