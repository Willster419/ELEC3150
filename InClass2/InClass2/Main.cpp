/////////////////////////////////
// Willard Wider               //
// 10/03/16                    //
// In-Class 2                  //
// Last Modified 10/03/16      //
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


//method stub things
int factorial(int num);

//other
using namespace std;

//the main entry point of the application
int main()
{
	int number = 0;
	print("Factorial of what number?");
	cin >> number;
	print("Answer is");
	int ans = factorial(number);
	print(ans);
	return 0;
}

//recursivly find the factorial of the number
int factorial(int num)
{
	static int numToAdd = num;
	static int numToMult = num;
	numToAdd = numToAdd-1;
	if (numToAdd == 0)
	{
		return numToMult;
	}
	numToMult = numToMult * numToAdd;
	factorial(numToAdd);
}