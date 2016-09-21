/////////////////////////////////
// Willard Wider               //
// 09/21/16                    //
// Lab 3                       //
// Last Modified 09/21/16      //
/////////////////////////////////
//basic start to the program
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <iso646.h>
using namespace std;
ostringstream oss;//extra string stream to allow for other types than strings to be added to an output
//declare all requried variables for this project
int key = 0;
int xorKey = 42;//'*'

void setKey()
{
	key = time(NULL);
	srand(key);
	key = rand() %420;
}

//main entry point of the application
int main()
{
	//step 1: convert to int
	//C in asci is 67 in decimal
	char theChar = 'C';
	char theIntOfChar = -1;
	theIntOfChar = theChar;//char -> int

	//step 2: randomize the int using specific key to multiply
	setKey();
	theIntOfChar = (theIntOfChar * key) %128;//randomize the int
	

	//step 3: use bitwise xor
	theIntOfChar = ( theIntOfChar ^= xorKey);

	//step 4: use bitwise negate
	theIntOfChar = ~theIntOfChar;

	//step 5: back to char for encrypted value
	char temp2 = theIntOfChar;
	
	//step 6: back to int
	theIntOfChar = temp2;
	
	//step 7: bitwise negate
	theIntOfChar = ~theIntOfChar;

	//step 8: bitwise xor
	theIntOfChar = ( theIntOfChar ^= xorKey);

	//step 9: unrandomize the int using key to divide
	theIntOfChar = theIntOfChar / key;
	
	//step 10: back to char
	
	char temp;
	temp = (char) theIntOfChar;//int -> char
	cout << temp;
	return 0;
}

void phaseOneEncryption()
{
	/*setKey();
	int encryptedInt = theIntOfChar * key;//randomize the int
	theIntOfChar = encryptedInt / key;*/
}

void phaseTwoEncryption()
{
	/*
	theChar = ( theChar ^= xorKey);
	theChar = ( theChar ^= xorKey);
	*/
}

void phaseThreeEncryption()
{
	/*
	theChar = ~theChar;
	theChar = ~theChar;
	*/
}