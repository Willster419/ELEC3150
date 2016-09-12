/////////////////////////////////
// Willard Wider               //
// 09/09/16                    //
// Mini Lab 1                  //
/////////////////////////////////

//Answer 1:
/*
// AN UNSCRABBLED PROGRAM //comments about the file go on top about the author, file, version history, etc.
#include <iostream> //preprocessor command that must be done first
using namespace std; //declaring the namespace for this class
int main()//declaring the method. Only 1 main
{//starting bracket goes after the methond declaration			
	cout << "Q"; //lines of code go here
	return 0; //return statement goes at the end of the method's code
}//ending bracket goes at the end of the method code, after the return statement
*/

//defining static variables of the program as to avoid the use of magic numbers
#define CELCIUS_FARENHEIGHT_CONSTANT 1.8
#define C_F_32_CONSTANT 32
#define KNOT_MPH_CONSTANT 1.15077945
//including required libraries for this project
#include <iostream>
//using the standard namespace
using namespace std;

//declaring varaibles to use for this project
float celcius;
float farenheight;
float knots;
float mph;
//Part 2 of the lab
void maine()
{
	cout << "Part 2: Holla al Mundo\n";
}
//Part 3 of the lab
void mane()
{
	cout << "Part 3: \" \' \\ $\t\t() \\n\n";
}
//part 4 of the lab
void mayne()
{
	cout << "Part 4:\n";
	cout << "Enter a speed in knots:\n";
	cin >> knots;
	mph = knots * KNOT_MPH_CONSTANT;
	cout << "Speed is " << mph << " mph\n";
	cout << "Enter a tempature in celsious:\n";
	cin >> celcius;
	farenheight = celcius * CELCIUS_FARENHEIGHT_CONSTANT;
	farenheight = farenheight + C_F_32_CONSTANT;
	cout << "Temp is " << farenheight << " degrees\n";
}
//the main entry point of the application
int main()
{
	cout << "Part 1: in comments of this code\n";
	//Part 2
	maine();
	//Part 3
	mane();
	//Part 4
	mayne();
	//Act as a pause
	cout << "Press enter to exit...\n";
	cin.get();
	cin.get();
	return 0;
}