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
#include "labAPI.h"
#include <cstdlib>
#define KEY_OFFSET 33
#define KEY_BITMASK 69
using namespace std;
//declare all requried variables for this project
unsigned char key, xorKey, theChar, numAdded, sizeOfMessage;
bool hasString = false;
char input[420];

//sets a key char based on a random number generator seeded with the time function, therefore always
void setKeys(char theXorKey, bool encryptOrDecrypt)
{
	//true = encrypt, false = decrypt
	unsigned char temp;
	if(encryptOrDecrypt)
	{
		temp = input[size(input)-1];
		sizeOfMessage = 0;
		srand(temp);
		key = rand();
		xorKey = theXorKey;
		input[size(input)] = ++xorKey;
		input[size(input)] = ++key;
		
	}
	else
	{
		//need to set the xorKey, sizeOfMessage, and key
		xorKey = size(input)/2;
		key = (size(input)/2) +1;
		xorKey--;
		key--;
		sizeOfMessage = (size(input)/2) -1;
	}
	

}

unsigned char phaseOne(bool encryptOrDecrypt, unsigned char c)
{
	//true = encrypting, false = decrypting
	if (encryptOrDecrypt)
	{
		numAdded = 1;
		c += key;
		while (32 > c || c > 127)
		{
			c += key;
			numAdded++;
		}
		numAdded += KEY_OFFSET;
		input[size(input)+ sizeOfMessage++]=numAdded;
		return c;
	}
	else
	{
		numAdded = input[size(input)-1 - sizeOfMessage];
		numAdded -= KEY_OFFSET;
		while ( numAdded != 0)
		{
			c -= key;
			numAdded--;
		}
		c -=key;
		input[size(input)-1 - sizeOfMessage--] = 0;
		return c - key;
	}
	return -1;
}

//xor bit logic. second phase of encryption
unsigned char phaseTwo(unsigned char c)
{
	c = (c ^= xorKey);
	return c;
}

//bit inversion. the third phase of encryption
unsigned char phaseThree(unsigned char c)
{
	c = ~c;
	return c;
}

//stuff
unsigned char encrypt(unsigned char inputValue)
{
	//generate key
	//encrypt key
	//encrypt message
	//attack encrypted key
	unsigned char tmep;
	//bitwise negate
	tmep = phaseThree(inputValue);
	//bitwise xor
	tmep = phaseTwo(tmep);
	//randomize the int using specific key to multiply
	tmep = phaseOne(true,tmep);
	return tmep;
}

//more stuff
unsigned char decrypt(unsigned char inputValue)
{
	unsigned char temp;
	//unrandomize
	temp = phaseOne(false,inputValue);
	//bitwise xor
	temp = phaseTwo(temp);
	//bitwise negative
	temp = phaseThree(temp);
	return temp;
}

//main entry point of the application
int main()
{
	//encryption
	print("enter a string");
	cin.getline(input,420);
	setKeys(input[0],true);
	int currentSize = size(input)-1;
	for(int i = 0; i < currentSize; i++)
	{
		input[i] = encrypt(input[i]);
	}
	oss <<"your encrypted string is " << input;
	print (oss.str());

	//decryption
	setKeys(input[0],false);
	currentSize = size(input)/2;
	for(int i = 0; i < currentSize; i++)
	{
		input[i] = decrypt(input[i]);
	}
	oss <<"your decrypted string is " << input;
	print (oss.str());
	print ("press enter to continue...");
	cin.getline(input,420);

	return 0;
}