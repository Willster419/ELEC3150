/////////////////////////////////
// Willard Wider               //
// 09/21/16                    //
// LabAPI header file          //
// Last Modified 09/22/16      //
/////////////////////////////////
//basic start to the program
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;
ostringstream oss;//extra string stream to allow for other types than strings to be added to an output
string swapstring;
//method to simplifing the procedure of printing to the console
void print(string str)
{
	cout << str << "\n";
	oss.str("");
}

//method to simplifing the procedure of printing to the console
void print(char c)
{
	cout << c << "\n";
	oss.str("");
}

//returns the size of the character array of characters that are in use
int getSize(char temp[])
{
	int tempp = 0;
	while(temp[tempp] !=0 )//while the value at that index is not null
	{
		tempp++;//incrase the index to find the null value
	}
	return tempp;
}

//returns the size of the character array of characters that are in use
int getSize(unsigned char temp[])
{
	int tempp = 0;
	while(temp[tempp] !=0 )
	{
		tempp++;
	}
	return tempp;
}

//swapps all the items of a given array from top and bottom
//same logic as lab 1
string swapString (string stringToSwap)
{
	string temp = stringToSwap;
	for (int i = 0; i < stringToSwap.size(); i++)
	{
		char tempp = stringToSwap[i];
		temp[stringToSwap.size()-i-1] = tempp;
	}
	return temp;
}

void printArray (int arrayToPrint[],int size)
{
	for ( int i = 0; i < size; i++)
	{
		oss << "index " << i << ", array value " << arrayToPrint[i];
		print(oss.str());
	}
}