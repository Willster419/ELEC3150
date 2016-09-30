/////////////////////////////////
// Willard Wider               //
// 09/26/16                    //
// In Class 3 or 4             //
// Last Modified 09/26/16      //
/////////////////////////////////
#include <iostream>
#include "LabAPI.h"
using namespace std;

void cardCounter ( int cardNumber, int &cardCount)
{
	if ( cardNumber > 9)
	{
		if (cardNumber == 0)
		{
			
		}
		else
		{
			cardCount--;
		}

	}
	else
	{
		cardCount++;
	}
}


int main()
{
	int cardCount = 0;
	cardCounter(9, cardCount);
	cout << "The current card count is: " << cardCount << "\n";
	cardCounter(2, cardCount);
	cout << "The current card count is: " << cardCount << "\n";
	cardCounter(10, cardCount);
	cout << "The current card count is: " << cardCount << "\n";
	cardCounter(13, cardCount);
	cout << "The current card count is: " << cardCount << "\n";
	cardCounter(7, cardCount);
	cout << "The current card count is: " << cardCount << "\n";
}