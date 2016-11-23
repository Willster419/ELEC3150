/////////////////////////////////
// Willard Wider               //
// Main.cpp                    //
// 11/23/16                    //
// In Class 9                  //
// Last Modified 11/23/16      //
/////////////////////////////////

//C library includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

//user includes
#include "LabAPI.h"

//defines


//constants


//structs and typedefs


//method prototypes


//other definitions
using namespace std;


//the main entry point of the application
int main()
{
	//create and random fill the vector
	vector<int> v;
	v.push_back(2);
	v.push_back(7);
	v.push_back(9);
	v.push_back(0);
	v.push_back(1);
	//print them
	print("Vector Values are");
	for (vector<int>::iterator temp = v.begin(); temp != v.end(); ++temp)
	{
		cout << *temp << "\n";
	}
	//sort them
	sort(v.begin(),v.end());
	//print them
	print("Sorted Vector Values are");
	for (vector<int>::iterator temp = v.begin(); temp != v.end(); ++temp)
	{
		cout << *temp << "\n";
	}
	return 0;
}