/////////////////////////////////
// Willard Wider               //
// XX/XX/XX                    //
// Mini Lab 1                  //
// Last Modified XX/XX/XX      //
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


//other
using namespace std;

//the main entry point of the application
int main()
{
	int array2[10] = {0,1,2,3,4,5,6,7,8,9};
	//declare pointer(s)
	int *arryPtr = 0;
	int *printPtr = 0;
	//set it equal to the array
	arryPtr = &array2[0];
	printPtr = &array2[0];
	for (int i = 0; i < 10; i+=2, arryPtr+=2)
	{
		*arryPtr +=1;
		
	}
	for (int i = 0; i < 10; i++, printPtr++)
	{
		cout << "At " << long(printPtr) << " the value is " << *printPtr << "\n";
	}
	return 0;
}