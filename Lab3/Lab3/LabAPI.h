/////////////////////////////////
// Willard Wider               //
// 09/21/16                    //
// LabAPI header file          //
// Last Modified 09/21/16      //
/////////////////////////////////
//basic start to the program
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <time.h>
#include <stdio.h>
using namespace std;
ostringstream oss;//extra string stream to allow for other types than strings to be added to an output

//method to simplifing the procedure of printing to the console
void print(string str)
{
	cout << str << "\n";
	oss.str("");
}