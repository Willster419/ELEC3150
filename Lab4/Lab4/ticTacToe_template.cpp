/////////////////////////////////
// Willard Wider               //
// 09/23/16                    //
// Lab 4                       //
// Last Modified 10/01/16      //
/////////////////////////////////

//includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "LabAPI.h"
#include <cstdlib>

//defines

//constants
const char mySymbol = 'X';
const char enemySymbol = 'O';

//method stub things
void insertX(char (TTTarray[])[3], bool &isOver);
void insertO(char (TTTarray[])[3]);
void checkForWin(char (TTTarray[])[3]); // IGNORE THIS FOR NOW
void printTTT(char (TTTarray[])[3]);
bool react(char (TTTarray[])[3]);
bool checkRows(bool me,char (TTTarray[])[3]);
bool checkColumns(bool me,char (TTTarray[])[3]);
bool checkDiags(bool me,char (TTTarray[])[3]);
bool firstAvailableMove(char (TTTarray[])[3]);
bool checkForWinner(char (TTTarray[])[3], char theSym);

//other
using namespace std;

int main( )
{
	bool isOver = false;
	char TTTarray[3][3] = { {'-','-','-'},
							{'-','-','-'},
							{'-','-','-'}};
	while (!isOver)
	{
		//char TTTarray[3][3] = { {'-','X','-'},
		//                        {'-','X','-'},
		//                        {'-','-','O'}};

		//char TTTarray[3][3] = { {'-','-','-'},
		//                        {'-','X','-'},
		//                        {'-','O','-'}};

		//char TTTarray[3][3] = { {'X','-','X'},
		//                        {'-','-','-'},
		//                        {'O','-','-'}};

		//char TTTarray[3][3] = { {'X','-','X'},
		//                        {'O','X','-'},
		//                        {'O','-','O'}};


		insertX(TTTarray,isOver);
		//OR

		printTTT(TTTarray);

		bool xWon = checkForWinner(TTTarray,'X');
		bool yWon = checkForWinner(TTTarray,'O');

		if (isOver || xWon || yWon)
		{
			print("gg no re");
			break;
		}
		insertO(TTTarray);
	}
	/*****************
	I have included the declaratoin of the array, initialized to - for each spot.
	The '-' represents an empty position.  You should fill it with either a 
	capital 'O' or a capital 'X'. I have also included a number of initialized arrays 
	to test; just comment out the ones you don't want for that moment
	*****************/
	//ok
	return 0;   
}

//prints the board to the console nicely
void printTTT(char (TTTarray[])[3])
{
	print("");
	print("   |   |   ");
	oss << " " << TTTarray[0][0] << " | " << TTTarray[0][1] << " | " << TTTarray[0][2];
	print(oss.str());
	print("___|___|___");
	print("   |   |   ");
	oss <<" " <<  TTTarray[1][0] << " | " << TTTarray[1][1] << " | " << TTTarray[1][2];
	print(oss.str());
	print("___|___|___");
	print("   |   |   ");
	oss << " " << TTTarray[2][0] << " | " << TTTarray[2][1] << " | " << TTTarray[2][2];
	print(oss.str());
	print("   |   |   ");
}

//default given method to insert an x into an array
void insertX(char (TTTarray[])[3], bool &isOver)
{
	static int moveNum = 1;//static int to create move 1 for the switch statement below
	//since tic-tac-toe only has 5 maximum moves, seperating into case statements allows
	//it to be programmed for each move, as you will see below
	switch (moveNum)
	{
		//since I am X and X goes first, first thing to do is in move 1, take the middle
	case 1://= move 1, etc.
		//take the middle
		TTTarray[1][1] = mySymbol;
		break;

	case 2:
		//check which row the enemy took and take the left most one of that row, unless he took that one,
		//in which case the right most one. It can be done since he has onlt one O on the board at this time
		if(TTTarray[0][0] == enemySymbol || TTTarray[0][1] == enemySymbol || TTTarray[0][2] == enemySymbol)
		{
			//enemy took top row, take upper left
			if(TTTarray[0][0] != enemySymbol)
			{
				TTTarray[0][0] = mySymbol;
			}
			//nvm take upper right middle LOL
			else
			{
				TTTarray[0][2] = mySymbol;
			}
		}
		else if (TTTarray[1][0] == enemySymbol || TTTarray[1][1] == enemySymbol || TTTarray[1][2] == enemySymbol)
		{
			//enemy took middle row
			if(TTTarray[1][0] != enemySymbol)
			{
				TTTarray[0][2] = mySymbol;
			}
			//nvm take upper right middle LOL
			else
			{
				TTTarray[2][2] = mySymbol;
			}
		}
		else
		{
			//enemy took low row
			if(TTTarray[2][0] != enemySymbol)
			{
				TTTarray[2][0] = mySymbol;
			}
			//nvm take upper right middle LOL
			else
			{
				TTTarray[2][2] = mySymbol;
			}
		}
		break;
		//moves 3-5 are the same, use reactionary algorithim
	case 3:
		if(react(TTTarray))
		{

		}
		else
		{
			isOver = true;
		}
		break;

	case 4:
		if(react(TTTarray))
		{

		}
		else
		{
			isOver = true;
		}
		break;

	case 5:
		if(react(TTTarray))
		{

		}
		else
		{
			isOver = true;
		}
		break;

	default:
		print("errorLOL");
		break;
	}

	moveNum++;
}

//method for the enemy to put his/her algorithem. currently is for user input for testing and playing
void insertO(char (TTTarray[])[3])
{
	bool done = false;
	int y = -5, x = -5;
	while (!done)
	{
		//while input is not valid ask for input
		print("Type the y of the board, 0-2");
		cin >> y;
		print("Type the x of the board, 0-2");
		cin >> x;
		if ((-1<y && y < 3)&&(-1<x && x < 3)&&(TTTarray[y][x] == '-'))
		{
			done = true;
		}
		else
		{
			print("invalid input");
			cin.clear();
			cin.ignore();
			continue;
		}
	}
	//when it makes it here, the input is valid and the O is placed on the specified part on the array
	TTTarray[y][x] = 'O';
}

//method for checking for 2 X's or O's in a row, and eithor stop or complete it.
bool react(char (TTTarray[])[3])
{
	//check if he will win first by looking for 2 O's next to each other in any point on the board
	if (checkRows(false,TTTarray))
		return true;
	if (checkColumns(false,TTTarray))
		return true;
	if (checkDiags(false,TTTarray))
		return true;

	//then check if i can win by doing the same as above but for X's
	if (checkRows(true,TTTarray))
		return true;
	if (checkColumns(true,TTTarray))
		return true;
	if (checkDiags(true,TTTarray))
		return true;

	//if we get to here it means there is no direct way for eithor of us to win
	//so make the first move available from upper left to lower right
	if (firstAvailableMove(TTTarray))
		return true;
	//if we get there the game is over
	return false;
}

//True=checking for me
bool checkRows(bool me,char (TTTarray[])[3])
{
	char checkingFor, placing = 'X', none = '-';
	//if checking for me winnig
	if (me)
	{
		checkingFor = 'X';
	}
	//else checking if enemy will win
	else
	{
		checkingFor = 'O';
	}

	/*
	//DEBUG
	char temp20 = TTTarray[2][0];
	char temp21 = TTTarray[2][1];
	char temp22 = TTTarray[2][2];
	if ((temp20 == checkingFor) && (temp21 == none) && (temp22 == checkingFor))
	{
	TTTarray[2][0] = placing;
	return true;
	}
	*/

	for (int i = 0; i < 3; i++)
	{
		//for each row starting from top to bottom, check for each possible place 2 X's or O's could be
		if ((TTTarray[i][0] == checkingFor) && (TTTarray[i][1] == checkingFor) && (TTTarray[i][2] == none))
		{
			//place an X at the one spot that is not full
			TTTarray[i][2] = placing;
			return true;
		}

		if ((TTTarray[i][0] == checkingFor) && (TTTarray[i][1] == none) && (TTTarray[i][2] == checkingFor))
		{
			TTTarray[i][1] = placing;
			return true;
		}

		if ((TTTarray[i][0] == none) && (TTTarray[i][1] == checkingFor) && (TTTarray[i][2] == checkingFor))
		{
			TTTarray[i][0] = placing;
			return true;
		}
	}

	//if we get here we have not moved yet, return false
	return false;
}

//True=checking for me
bool checkColumns(bool me,char (TTTarray[])[3])
{
	char checkingFor, placing = 'X', none = '-';
	//if checking for me winnig
	if (me)
	{
		checkingFor = 'X';
	}
	//else checking if enemy will win
	else
	{
		checkingFor = 'O';
	}

	for (int i = 0; i < 3; i++)
	{
		//for each columns starting from left to right, check for each possible place 2 X's or O's could be
		if ((TTTarray[0][i] == checkingFor) && (TTTarray[1][i] == checkingFor) && (TTTarray[2][i] == none))
		{
			//place an X at the empty spot
			TTTarray[2][i] = placing;
			return true;
		}

		if ((TTTarray[0][i] == checkingFor) && (TTTarray[1][i] == none) && (TTTarray[2][i] == checkingFor))
		{
			TTTarray[1][i] = placing;
			return true;
		}

		if ((TTTarray[0][i] == none) && (TTTarray[1][i] == checkingFor) && (TTTarray[2][i] == checkingFor))
		{
			TTTarray[0][i] = placing;
			return true;
		}
	}
	//if we get here we have not moved yet, return false
	return false;
}

//True=checking for me
bool checkDiags(bool me,char (TTTarray[])[3])
{
	char checkingFor, placing = 'X', none = '-';
	//if checking for me winnig
	if (me)
	{
		checkingFor = 'X';
	}
	//else checking if enemy will win
	else
	{
		checkingFor = 'O';
	}

	//upper-left to lower right
	if ((TTTarray[0][0] == checkingFor) && (TTTarray[1][1] == checkingFor) && (TTTarray[2][2] == none))
	{
		TTTarray[2][2] = placing;
		return true;
	}
	if ((TTTarray[0][0] == checkingFor) && (TTTarray[1][1] == none) && (TTTarray[2][2] == checkingFor))
	{
		TTTarray[1][1] = placing;
		return true;
	}
	if ((TTTarray[0][0] == none) && (TTTarray[1][1] == checkingFor) && (TTTarray[2][2] == checkingFor))
	{
		TTTarray[0][0] = placing;
		return true;
	}

	//lower-left to upper right
	if ((TTTarray[2][0] == checkingFor) && (TTTarray[1][1] == checkingFor) && (TTTarray[0][2] == none))
	{
		TTTarray[0][2] = placing;
		return true;
	}
	if ((TTTarray[2][0] == checkingFor) && (TTTarray[1][1] == none) && (TTTarray[0][2] == checkingFor))
	{
		TTTarray[1][1] = placing;
		return true;
	}
	if ((TTTarray[2][0] == none) && (TTTarray[1][1] == checkingFor) && (TTTarray[0][2] == checkingFor))
	{
		TTTarray[2][0] = placing;
		return true;
	}

	//if we get here we have not moved yet, return false
	return false;
}

//method to find the first available move and make it
bool firstAvailableMove(char (TTTarray[])[3])
{
	//find the first possible place to fill from and fill it
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//check to make sure it's empty before it's taken
			if (TTTarray[i][j] == '-')
			{
				TTTarray[i][j] = 'X';
				return true;
			}
		}
	}
}

//method to check for a winner, similar to the algorithems for checking for two symbols in a row
//false means there is no winner
bool checkForWinner(char (TTTarray[])[3], char theSym)
{
	char checkingFor = theSym;
	char none = theSym;

	//rows
	for (int i = 0; i < 3; i++)
	{
		if ((TTTarray[i][0] == checkingFor) && (TTTarray[i][1] == checkingFor) && (TTTarray[i][2] == none))
		{
			return true;
		}

		if ((TTTarray[i][0] == checkingFor) && (TTTarray[i][1] == none) && (TTTarray[i][2] == checkingFor))
		{
			return true;
		}

		if ((TTTarray[i][0] == none) && (TTTarray[i][1] == checkingFor) && (TTTarray[i][2] == checkingFor))
		{
			return true;
		}
	}

	//columns
	for (int i = 0; i < 3; i++)
	{
		if ((TTTarray[0][i] == checkingFor) && (TTTarray[1][i] == checkingFor) && (TTTarray[2][i] == none))
		{
			return true;
		}

		if ((TTTarray[0][i] == checkingFor) && (TTTarray[1][i] == none) && (TTTarray[2][i] == checkingFor))
		{
			return true;
		}

		if ((TTTarray[0][i] == none) && (TTTarray[1][i] == checkingFor) && (TTTarray[2][i] == checkingFor))
		{
			return true;
		}
	}

	//upper-left to lower right
	if ((TTTarray[0][0] == checkingFor) && (TTTarray[1][1] == checkingFor) && (TTTarray[2][2] == none))
	{
		return true;
	}

	//lower-left to upper right
	if ((TTTarray[2][0] == checkingFor) && (TTTarray[1][1] == checkingFor) && (TTTarray[0][2] == none))
	{
		return true;
	}
	return false;
}