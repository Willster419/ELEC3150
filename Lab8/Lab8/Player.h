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
	int takeShot(int twoOrthree);
	int getTwoShotAcc();
	int getThreeShotAcc();
	string getName();
	int getNumbah();
	void setTwoShotAcc(int twoShot);
	void setThreeShotAcc(int threeShot);
	void setName(string nayme);
	void setNumbah(int de_numbah);
	~Player();

};

#endif