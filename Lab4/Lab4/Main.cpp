/////////////////////////////////
// Willard Wider               //
// 09/23/16                    //
// Lab 4                       //
// Last Modified 09/23/16      //
/////////////////////////////////
//basic start to the program
/*#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "LabAPI.h"
#include <cstdlib>
//some constants to help with eliminating magic numbers
char board[3][3];
using namespace std;
const char mySymbol = 'X';
const char enemySymbol = 'O';
int moveNumber = 1;

//the method declaration things so i can make them below main
void move1();
void move2();
void move3();
void move4();
void move5();
void enemyMove(int y, int x);

//main entry point of the application
int mainn()
{
	move1();
	return 0;
}

//
void move1()
{
	//try to take the center, if can't, take the upper right
	char temp = board[1][1];
	/*
	//if it's not in tne center
	if (temp != mySymbol)
	{
		//take the center
	}
	else
	{
		//take the upper right

	}

	//UPDATE: X always goes first
	board[1][1] = mySymbol;
}

//
void move2()
{
	//check which row the enemy took
	if(board[0][0] == enemySymbol || board[0][1] == enemySymbol || board[0][2] == enemySymbol)
	{
		//enemy took top row, take upper right
		if(board[0][0] == enemySymbol)
		{

		}
		//nvm take upper right + 1 LOL
		else
		{

		}
	}
	else if (board[1][0] == enemySymbol || board[1][1] == enemySymbol || board[1][2] == enemySymbol)
	{
		//enemy took middle row
	}
	else
	{
		//enemy took low row
	}
}

//
void move3()
{

}

//
void move4()
{

}

//
void move5()
{

}

//
void enemyMove(int y, int x)
{
	board[y][x] = enemySymbol;
}*/