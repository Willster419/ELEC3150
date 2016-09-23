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
#define KEY_BITMASK 69
using namespace std;

//even more stuff
unsigned char addInRange(unsigned char low, unsigned char high, unsigned char currentPOS, unsigned char add)
{
	if(high >= currentPOS+add)
	{
		return currentPOS+add;
	}
	unsigned char answer = (currentPOS+add) - (high+1);
	unsigned char room = high - low;
	answer = answer%room;
	return low+answer;
}

//even more cool stuff
unsigned char subInRange(short low, short high, short currentPOS, short add)
{
	if(low <= currentPOS-add)
	{
		return currentPOS-add;
	}
	short answer = (currentPOS-add) - (low-1);
	//answer++;
	answer = answer*-1;
	short room = high - low;
	answer = answer%room;
	return high-answer;
}

//sets a key char based on a random number generator seeded with the time function, therefore always
unsigned char generateKey()
{
	srand(time(0));
	return rand();
}

unsigned char bitMask(bool encryptOrDecrypt, unsigned char inputChar, unsigned char amount)
{
	//true = encrypting, false = decrypting
	if (encryptOrDecrypt)
	{
		
		inputChar = addInRange(32,126,inputChar,amount);
		return inputChar;
		
		/*inputChar += amount;
		while (32 > inputChar || inputChar > 127)
		{
			inputChar += amount;
		}
		return inputChar;*/
	}
	else
	{
		inputChar = subInRange(32,126,inputChar,amount);
		return inputChar;
		/*
		inputChar -= amount;
		while (32 > inputChar || inputChar > 127)
		{
			inputChar -= amount;
		}*/
		return inputChar;
	}
	return -1;
}

//xor bit logic. second phase of encryption
unsigned char xor(unsigned char c,unsigned char key)
{
	c = (c ^= key);
	return c;
}

//bit inversion. the third phase of encryption
unsigned char invert(unsigned char c)
{
	return ~c;
}

//stuff
string encrypt(string input)
{
	//generate key
	unsigned char ukey = generateKey();
	unsigned char key = ukey;
	//encrypt key
	//key = xor(key,KEY_BITMASK);
	//key = invert(key);
	key = bitMask(true,key,KEY_BITMASK);
	//encrypt message
	for(int i = 0; i < input.size(); i++)
	{
		//input[i] = xor(input[i],ukey);
		//input[i] = invert(input[i]);
		//input[i] = bitMask(true,input[i],xor(input[i],ukey));
		//input[i] = bitMask(true,input[i],invert(ukey));
		input[i] = bitMask(true,input[i],ukey);
	}
	//attach encrypted key
	input += key;
	return input;
}

//more stuff
string decrypt(string input)
{
	//remove encrypted key
	unsigned char key = input[input.size()-1];
	//decrypt key
	key = bitMask(false,key,KEY_BITMASK);
	//key = invert(key);
	//key = xor(key,KEY_BITMASK);
	//decrypt message
	for(int i = 0; i < input.size()-1; i++)
	{
		input[i] = bitMask(false,input[i],key);
		//input[i] = bitMask(false,input[i],invert(key));
		//input[i] = bitMask(false,input[i],xor(key,key));
		//input[i] = invert(input[i]);
		//input[i] = xor(input[i],key);
	}
	input = input.substr(0,input.size()-1);
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
			print("your encrypted message is " + encrypt(input));
			print("press enter to continue...");
			getline(cin,input);
		}
		else if (input == "decrypt")
		{
			print("type message to decrypt");
			getline(cin,input);
			//decrypt
			print("your decrypted message is " + decrypt(input));
			print("press enter to continue...");
			getline(cin,input);
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