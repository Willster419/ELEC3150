/////////////////////////////////
// Willard Wider               //
// 09/12/16                    //
// Lab 1                       //
// Last Modified 09/14/16      //
/////////////////////////////////
//basic start to the program
#include <iostream>
#include <string>
#include <sstream>
#define NDEX 20//default setting length of the array
using namespace std;
int intArray [NDEX];//uses the defined index length
ostringstream oss;//extra string stream to allow for other types than strings to be added to an output
//method to simplifing the procedure of printing to the console
void print(string str)
{
	cout << str << "\n";
	oss.str("");
}

void loopOne()
{
	for (int i = 0; i < NDEX ; i++)
	{
		intArray[i] = i;//sets each array index to the index number
		oss << "Filling array Index " << i << " with value " << i;//sets up the output string
		print(oss.str());
	}
}

void loopToo()
{
	int j = NDEX-1;//int to facilitate with the reverse-filling of the index
	int stopper = NDEX /2;//int to stop the 
	int temp = 0;
	for (int i = 0; i < NDEX ; i++)
	{
		if (i == stopper)//check for the middle of the array, where the inversion would need to stop because it's complete
		{
			print("middle reached, stopping...");
			print ("array now has values as follows");
			for (int i = 0; i < NDEX; i++)
			{
				oss << "Array Index " << i << " has value " << intArray[i];
				print(oss.str());
			}
			break;//break out of the for loop
		}
		temp = intArray[j];//create a temp value to store the bottom variable
		intArray[j] = intArray[i];//uses the high->low int (j) for the index value of the array,
		//and uses the low->high int (i) for it's value. End result is the high->low index has the low->high value
		oss << "Filling array Index " << j << " with value " << i;
		print(oss.str());
		intArray[i] = temp;//End result is the low->high index has the high->low value
		oss << "Filling array Index " << i << " with value " << j;
		print(oss.str());
		j--;//decrement the high index withen the for loop
	}
}

int main()
{
	print("starting project...");
	print("starting loop 1...");
	loopOne();
	print("starting loop 2...");
	loopToo();
	print("run complete, press enter to continue...");
	cin.get();
	return 0;
}