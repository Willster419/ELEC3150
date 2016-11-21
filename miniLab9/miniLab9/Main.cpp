/////////////////////////////////
// Willard Wider               //
// Main.cpp                    //
// 11/18/16                    //
// Mini-Lab 9                  //
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
#include "LabAPI.h"

//defines


//constants


//structs and typedefs


//other definitions
using namespace std;
template <class T, class U, class V>
T miniLab9(U var0, V var1)
{
	cout << var0 << " " << var1 << endl;
	var1 = (var0 + var1)/2;
	return (T)var1;
}
//method prototypes


//the main entry point of the application
int main()
{
	float param0 = 4.0;
	short param1 = 5.0;
	float result = miniLab9<float>(param0,param1);
	return 0;
}


