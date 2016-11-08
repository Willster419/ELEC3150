/////////////////////////////////
// Willard Wider               //
// LabAPI.cpp                  //
// 09/21/16                    //
// General Lab Assistance File //
// Last Modified 10/24/16      //
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


//structs


//typedefs


//other definitions
using namespace std;
ostringstream oss;//extra std::string stream to allow for other types than std::strings to be added to an output
string swapstring;

//method to simplifing the procedure of printing to the console
void print(string str)
{
	cout << str << "\n";
	oss.str("");
}

//method to simplifing the procedure of printing to the console
/*void print(unsigned char c)
{
	cout << c << "\n";
	oss.str("");
}*/

//method to provide a blank space
void print()
{
	cout << "" << "\n";
	oss.str("");
}

void print(string text, char value)
{
	cout << text << " " << value << "\n";
	oss.str("");
}

void print(string text, int value)
{
	cout << text << " " << value << "\n";
	oss.str("");
}

void print(string text, float value)
{
	cout << text << " " << value << "\n";
	oss.str("");
}

void printPointer(char *refChar)
{
	cout << *refChar << "\n";
	oss.str("");
}

void printPointer(int *refInt)
{
	cout << *refInt << "\n";
	oss.str("");
}

void printPointer(float *refFloat)
{
	cout << *refFloat << "\n";
	oss.str("");
}

void printPointer(double *refDub)
{
	cout << *refDub << "\n";
	oss.str("");
}

//returns the size of the character array of characters that are in use
int size(char temp[])
{
	int tempp = 0;
	while(temp[tempp] !=0 )//while the value at that index is not null
	{
		tempp++;//incrase the index to find the null value
	}
	return tempp;
}

//returns the size of the character array of characters that are in use
int size(int temp[])
{
	int tempp = sizeof (temp);
	/*while(temp[tempp] !=0 )//while the value at that index is not null
	{
		tempp++;//incrase the index to find the null value
	}*/
	return tempp;
}

//returns the size of the character array of characters that are in use
int size(unsigned char temp[])
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

void run_complete( string message = "Run Complete, press enter to continue...")
{
	string temps;
	cin.clear();
	string temp;
	print(message);
	getline(cin,temps);
	cin.clear();
}

void printArray (int arrayToPrint[],int size)
{
	for ( int i = 0; i < size; i++)
	{
		oss << "index " << i << ", array value " << arrayToPrint[i];
		print(oss.str());
	}
}

void printArray (char arrayToPrint[],int size)
{
	for ( int i = 0; i < size; i++)
	{
		oss << "index " << i << ", array value " << arrayToPrint[i];
		print(oss.str());
	}
}

//returns the index of where the the specified item of search is
int binarySearch(int theArray[],int size,int search)
{
	/*
		Step 0: Check (or in this case, assume cause we know) the array is already sorted
		Step 1: get the middle index of the array
		Step 2: determine if it needs to move left or right and do it
		Step 3: determine if the search value is inbetween the current and next
		value, meaning that the value searched for does not exist, and error out
		if that is the case
		Step 4: determine if the searched value is equal to the selected array index
		value, and if so return the index of which the searched value can be found
	*/
	int theSize = size/2 +1 ;//saves the middle index of the array
	while (true)
	{
		if (theArray[theSize] > search)
		{
			//go down one
			theSize--;
		}
		else if (theArray[theSize] < search)
		{
			//go up one
			theSize++;
		}
		//if the search term is in between the array values
		if (theArray[theSize] < search && search < theArray[theSize+1] && theArray[theSize] != search)
		{
			//does not exist (which it does not in this case), return error
			return -1;
		}
		if (theArray[theSize] == search)
		{
			//return index value where it is
			return theSize;
		}
	}
}

//sorts an array using ubble sort
void bubbleSort(int theArray[],int size)
{
	bool sorted = false;//start it as false to it enteres the loop
	int size2 = size;
	int sizePart2 = size2;
	while (!sorted)
	{
		sorted = true;//set it to true for default
		
		for (int i = 0; i < size2; i++)
		{
			//condition to check if it's the last item in the array
			if (i+1 == size2)//if it starts to go out of bounds, stop it
			{
				break;
			}
			int current = theArray[i];
			int next = theArray[i+1];
			if ( current > next)//if the next one is smaller
			{
				//swap
				sorted = false;//the fact that it made it here means that another
				//pass must be made on the array, so set the bool to false to it runs again
				theArray[i] = next;
				theArray[i+1] = current;
			}
		}
		//if it makes it here with the sorted bool as true, it will set the while condition
		//to false and break the loop because the array will be sorted
	}
}

//puts an item in stack of an array
//1 = was put in, 0 = array was full
int push(char (&stack)[5], char value, int size)
{
	int index = size-1;
	while(index != 0)
	{
		if (stack[index] != 0)
		{
			return 0;
		}
		stack[index] =stack[index-1] ;
		index--;
	}
	stack[0] = value;
	return 1;
}

//takes an item out of stack of an array
char pop(char (&stack)[5], int size)
{
	char deezNutz = stack[0];
	int index = 1;
	while(index != size)
	{
		stack[index-1] = stack[index];
		index++;
	}
	return deezNutz;
}

//puts an item in queue of an array
//1 = was put in, 0 = array was full
int enqueue(char (&Q)[5], char value, int size)
{
	int index = 0;
	while (true)
	{
		if (index == size)
		{
			return 0;
		}
		if (Q[index] == 0)
		{
			Q[index] = value;
			return 1;
		}
		index++;
	}
}

//takes an item out of queue of an array
char dequeue(char (&Q)[5], int size)
{
	char haGadi = Q[0];
	int index = 1;
	while(index != size)
	{
		Q[index-1] = Q[index];
		index++;
	}
	return haGadi;
}

string int2String (int intToConvert)
{
	ostringstream ossT;
	ossT << intToConvert;
	return ossT.str();
}

//create the log file
void createLogFile()
{
	string path;
	//get current executable location

	//open the filestream


}

//appends to a log file
void appendLog(string text)
{

}