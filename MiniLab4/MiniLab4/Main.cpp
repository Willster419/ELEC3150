/////////////////////////////////
// Willard Wider               //
// 09/19/16                    //
// Mini Lab 4                  //
// Last Modified 09/27/16  :/  //
/////////////////////////////////
#include <iostream>
#include <string>
#include <sstream>
#include "LabAPI.h"
using namespace std;
static const int P_1_SIZE(7);
static const int P_2_3_SIZE(5);

//part 1
void part1(int theArray[],int size)
{
	print("Part 1: Binary search for 15");
	print("look in the commends in the code");
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
	int search = 15;//the search value
	int returnedValue;//that value that would be returned if this search were in a seperate method
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
			returnedValue = -1;
			break;
		}
		if (theArray[theSize] == search)
		{
			//return index value where it is
			returnedValue = theSize;
			break;
		}
	}
}

//part 2
void part2(int theArray[],int size)
{
	print("Part 2: Bubble sort the array");
	print("The array origionally reads");
	printArray(theArray,size);
	bool sorted = false;//start it as false to it enteres the loop
	int size2 = size;
	int sizePart2 = size2;
	print ("");
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
	print("the sorted array reads");
	printArray(theArray,size);
	print("");
}

//part 3
void part3(int theArray[],int size)
{
	int temp = theArray[5];
	print("Part 3: Select sort the same array");
	print("The array origionally reads");
	printArray(theArray,size);
	print("");
	for (int i = 0; i < P_2_3_SIZE; i++)
	{
		int current = theArray[i];
		int index = 0;
		bool needToSwap = false;
		for (int j = i; j < P_2_3_SIZE; j++)
		{
			//detection of the end of the array
			if (j + 1 >= P_2_3_SIZE)
			{
				break;
			}
			int next = theArray[j + 1];
			if (next < current)
			{
				needToSwap = true;
				index = j+1;
				current = next;
			}
		}
		if (needToSwap)
		{
			int tempPlace = theArray[i];
			int tempPlace2 = theArray[index];
			theArray[i] = tempPlace2;
			theArray[index] = tempPlace;
		}
	}
	print("the sorted array reads");
	printArray(theArray,size);
	print("");
}

//part 4
void part4()
{
	print("Part 4: see the comments in the code");
	/*
	Technically, you could just linear seach every time you need to access something in an array.
	However, literally any other search method would be quicker, and if you access that array
	a lot you are spending more time searching than you have to. To save time (and out of good
	coding pratice) one should add a "if not sorted, sort" then search it.
	*/
}

//main entry point of the application
int main() {
	print("Mini Lab 4");
	int part1Array[7] = {1, 8, 10, 14, 16, 26, 50};
	int part3Array[5] = {100, 75, 25, 50, 0};
	int part2Array[5] = {100, 75, 25, 50, 0};
	part1(part1Array,P_1_SIZE);
	part2(part2Array,P_2_3_SIZE);
	part3(part3Array,P_2_3_SIZE);
	part4();
	//string tepm;
	//getline(cin, tepm);
}