/////////////////////////////////
// Willard Wider               //
// 10/01/16                    //
// Mini Lab 5                  //
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
#define LIMIT 1000

//constants


//method stub things
void part1();
bool part2(int input);

//other
using namespace std;

//the main entry point of the application
int main()
{
	print("Mini Lab 5: Functions");
	print("");
	print("Part 1: Pass by value vs. Pass by Refrence");
	part1();
	print("");
	print("Part 2: Running total");
	//keeps adding 50 untill it's over 1000
	while (part2(50))
	{
		print("Adding 50 to running total..");
	}
	print ("over 1000 reached, exiting...");
	//run_complete();
	//exit the application now that it's over 1000
	//personally i think you should have set it at 9000 so i could say "it's over 9000!"
	exit(0);
	return 0;
}

//explains my answers to part 1
void part1()
{
	print("Passing by value encourages scope/encapsulation, provides a copy, and is easier to keep track of in the program.");
	print("Pasing by refrence can be more dangerous in terms of memory address and memory faults, but uses less memory because");
	print("it uses the origional and encourages efficient coding where it might be necessary on systems with limited rescources.");
}

//function that adds a running total via a static int, and returns false when it is over 1000
bool part2(int input)
{
	static int total = 0;
	total += input;
	if (total > LIMIT)
	{
		return false;
	}
	else
	{
		return true;
	}
}