/////////////////////////////////
// Willard Wider               //
// Main.cpp                    //
// 11/18/16                    //
// In Class 7                  //
// Last Modified 11/18/16      //
/////////////////////////////////

//C library includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>

//user includes
#include "Base.h"
//defines


//constants


//structs and typedefs


//method prototypes


//other definitions
using namespace std;

//the main entry point of the application
int main()
{
	Base <float> thing;
	thing.setArray(1,2,3,4);
	thing.printArray();
	cout << "avg is " << thing.getAvg() << "\n";
	cout << "min is " << thing.getMin() << "\n";
	cout << "max is " << thing.getMax() << "\n";
	return 0;
}