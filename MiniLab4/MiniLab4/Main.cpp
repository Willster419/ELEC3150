/////////////////////////////////
// Willard Wider               //
// 09/19/16                    //
// Mini Lab 4                  //
// Last Modified 09/19/16      //
/////////////////////////////////
//first start, declare all dependancies
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
ostringstream oss;//extra string stream to allow for other types than strings to be added to an output
//method to simplifing the procedure of printing to the console
int part1Array[] = {1, 8, 10, 14, 16, 26, 50};
int part2Array[] = {100, 75, 25, 50, 0};
void print(string str)
{
	cout << str << "\n";
	oss.str("");
}
//main entry point of the application
int main() {
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
	size_t size = (sizeof part1Array/ sizeof part1Array[0]);//gets the number of elements in the array
	int theSize = size/2 +1 ;//saves the middle index of the array
	int search = 15;//the search value
	int returnedValue;//that value that would be returned if this search were in a seperate method
	while (true)
	{
		if (part1Array[theSize] > search)
		{
			//go down one
			theSize--;
		}
		else if (part1Array[theSize] < search)
		{
			//go up one
			theSize++;
		}
		//if the search term is in between the array values
		if (part1Array[theSize] < search && search < part1Array[theSize+1] && part1Array[theSize] != search)
		{
			//does not exist (which it does not in this case), return error
			returnedValue = -1;
			break;
		}
		if (part1Array[theSize] == search)
		{
			//return index value where it is
			returnedValue = theSize;
			break;
		}
	}
	print("Part 2: Bubble sort the part 2 array");
	
	bool sorted = false;//start it as false to it enteres the loop
	size_t size2 = (sizeof part2Array/ sizeof part2Array[0]);
	int sizePart2 = size2;
	print("the unsorted array reads");
	for ( int i = 0; i < size2; i++)
	{
		oss << "index " << i << ", array value " << part2Array[i];
		print(oss.str());
	}
	print ("");
	while (!sorted)
	{
		sorted = true;//set it to true for default
		for (int i = 0; i < size2; i++)
		{
			if (i+1 == size2)//if it starts to go out of bounds, stop it
			{
				break;
			}
			int current = part2Array[i];
			int next = part2Array[i+1];
			if ( current > next)//if the next one is smaller
			{
				//swap
				sorted = false;//the fact that it made it here means that another
				//pass must be made on the array, so set the bool to false to it runs again
				part2Array[i] = next;
				part2Array[i+1] = current;
			}
		}
		//if it makes it here with the sorted bool as true, it will set the while condition
		//to false and break the loop because the array will be sorted
	}
	print("the sorted array reads");
	for ( int i = 0; i < size2; i++)
	{
		oss << "index " << i << ", array value " << part2Array[i];
		print(oss.str());
	}
}