/////////////////////////////////
// Willard Wider               //
// 09/21/16                    //
// Lab 3                       //
// Last Modified 09/22/16      //
/////////////////////////////////
//basic start to the program
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "labAPI.h"
#include <cstdlib>
#define KEY_BITMASK 5
const unsigned char ASCII_LOW = 32;
const unsigned char ASCII_HIGH = 126;
using namespace std;

//adds a specific ammount to a number withen a specified range i.e. creating a new "base" to work off of
unsigned char addInRange(unsigned char currentPOS, unsigned char add)
{
	//get the adition down
	add = add % (ASCII_HIGH-ASCII_LOW)-1;
	if(ASCII_HIGH >= currentPOS+add)
	{
		return currentPOS+add;
	}
	unsigned extra = (currentPOS + add) - ASCII_HIGH;
	unsigned char answer = extra + (ASCII_LOW-1);
	return answer;
}

//subtracts from a number withen its own "base"
unsigned char subInRange(unsigned char currentPOS, unsigned char add)
{
	//get the adition down
	add = add % (ASCII_HIGH-ASCII_LOW)-1;
	if(ASCII_LOW <= currentPOS-add)
	{
		return currentPOS-add;
	}
	//kill the 32 offset
	unsigned char answer = currentPOS-ASCII_LOW;
	answer -= add;
	answer -=ASCII_HIGH+3;
	return answer;
}

/*
//returns a key char based on a random number generator seeded with the time function, therefore always random upon run
unsigned char generateKey()
{
	srand(time(0));
	return rand() % 126 + 32;
}
*/

//adds encryption by masking the input character by a specified ammount
unsigned char bitMask(bool encryptOrDecrypt, unsigned char inputChar, unsigned char amount)
{
	//true = encrypting, false = decrypting
	if (encryptOrDecrypt)
	{
		//adds the key amount to the input character for bit masking, and keeps it withen
		//a specified range, like the ascii character range, for example
		inputChar = addInRange(inputChar,amount);
		return inputChar;
		//old method origionaly tried to add withen a specific range
		/*
		inputChar += amount;
		while (32 > inputChar || inputChar > 127)
		{
		inputChar += amount;
		}
		return inputChar;
		*/
	}
	else
	{
		inputChar = subInRange(inputChar,amount);
		return inputChar;
		//old method origionaly tried to subtract withen a specific range
		/*
		inputChar -= amount;
		while (32 > inputChar || inputChar > 127)
		{
		inputChar -= amount;
		}
		*/
		return inputChar;
	}
	return -1;
}

/*
//xor bit logic.
unsigned char xor(unsigned char c,unsigned char key)
{
c = (c ^= key);
return c;
}
*/

//bit inversion logic.

/*
unsigned char invert(unsigned char c)
{
	return ~c;
}
*/

//main encryption method, get the input string from main and outputs an encrypted string
string encrypt(string input)
{
	//encrypt message
	for(int i = 0; i < input.size(); i++)
	{
		input[i] = bitMask(true,input[i],KEY_BITMASK);
	}
	//swap the string
	//input = swapString(input);
	return input;
}

//main decryption method, get the input string from main and outputs a decrypted version of the string
string decrypt(string input)
{
	//unswap the string
	//input = swapString(input);
	//decrypt message
	for(int i = 0; i < input.size(); i++)
	{
		input[i] = bitMask(false,input[i],KEY_BITMASK);
	}
	return input;
}

//main entry point of the application
int main()
{
	bool done = false;
	while (!done)
	{
		//menu to select to encrypt, decrypt, exit
		print("type encrypt to encrypt a message,");
		print("type decrypt to dectypt a message");
		print("type exit to exit");
		string input;
		getline(cin,input);
		if(input == "encrypt")
		{
			print("type message to encrypt");
			getline(cin,input);
			//encrypt
			print("your encrypted message is ");
			input = encrypt(input);
			if(input[input.size()-1] == ' ')
			{
				print("");
				print("THERE IS A SPACE AT THE END OF THAT SENTANCE");
				print("if you would like, encrypt it again to get a new string without a space");
				print("");
			}
			print(input);
		}
		else if (input == "decrypt")
		{
			print("type message to decrypt");
			getline(cin,input);
			//decrypt
			print("your decrypted message is ");
			print(decrypt(input));
		}
		else if (input == "exit")
		{
			done = true;
		}
		else
		{
			print("invalid input");
		}
	}
	return 0;
}