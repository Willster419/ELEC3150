/////////////////////////////////
// Willard Wider               //
// Main.cpp                    //
// 10/24/16                    //
// Lab 7                       //
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
#include "DoubleLinkedList.h"
#include "LabAPI.h"


//defines


//constants
const string task_done = "done with task, press enter to continue..";

//structs


//typedefs


//method prototypes(if no header file)
int whichList();

//other definitions
using namespace std;


//the main entry point of the application
int main()
{
	print("Lab 7: 'Classifying' our double linked lists");
	print("You see what I did there, Classify? Cause we're putting them into classes...moving on");
	print("Step 1: Create the lists for Quarterbacks and EM winners");
	DoubleLinkedList* QB = new DoubleLinkedList();
	DoubleLinkedList* EM = new DoubleLinkedList();
	print("Objects created, populating from file...");
	if (QB->addQBFromFile("Lab 6_QB_List.txt") == -1)
	{
		print("Error loading the Lab 6 QB list");
		return -1;
	}
	if (EM->addQBFromFile("Lab 7_EM_List.txt") == -1)
	{
		print("Error loading the Lab 7 EM list");
		return -1;
	}
	print("Lists populated");
	run_complete("Press enter to go to user input mode");
	bool done = false;
	string input = "nullLOL";
	int inputGrade = 0;
	string fNameInput = "null";
	string lNameInput = "null";
	while (!done)
	{
		print();
		print("Type add, remove, removeAll, search, print, or quit");
		cin >> input;
		if (input == "quit")
		{
			print("Deleting lists...");
			QB->~DoubleLinkedList();
			EM->~DoubleLinkedList();
			done = true;
		}
		else if (input == "print")
		{
			//print the list
			int decision = whichList();
			if (decision == 1)
			{
				print("QB SELECTED");
				QB->printList();
			}
			else if (decision == 2)
			{
				print("EM SELECTED");
				EM->printList();
			}
			else if (decision == 3)
			{
				print("BOTH SELECTED");
				print("QB");
				QB->printList();
				print("EM");
				EM->printList();
			}
			else
			{
				print ("Invalid input");
			}
		}
		else if (input == "search")
		{
			print("type 'year' or 'name' or 'numWins'");
			cin >> input;
			if (input == "year")
			{
				//search year
				//true = numWinz, false = year
				print("input year");
				cin >> inputGrade;
				int decision = whichList();
				if (decision == 1)
				{
					print("QB SELECTED");
					QB->printList(QB->search(inputGrade, false));
				}
				else if (decision == 2)
				{
					print("EM SELECTED");
					EM->printList(EM->search(inputGrade, false));
				}
				else if (decision == 3)
				{
					print("BOTH SELECTED");
					print("QB");
					QB->printList(QB->search(inputGrade, false));
					print("EM");
					EM->printList(EM->search(inputGrade, false));
				}
				else
				{
					print ("Invalid input");
				}
			}
			else if (input == "name")
			{
				//search name
				print("input first name");
				cin >> fNameInput;
				print("input last name");
				cin >> lNameInput;
				int decision = whichList();
				if (decision == 1)
				{
					print("QB SELECTED");
					QB->printList(QB->search(fNameInput,lNameInput));
				}
				else if (decision == 2)
				{
					print("EM SELECTED");
					EM->printList(EM->search(fNameInput,lNameInput));
				}
				else if (decision == 3)
				{
					print("BOTH SELECTED");
					print("QB");
					QB->printList(QB->search(fNameInput,lNameInput));
					print("EM");
					EM->printList(EM->search(fNameInput,lNameInput));
				}
				else
				{
					print ("Invalid input");
				}
			}
			else if (input == "numWins")
			{
				//search numWins
				//true = numWinz, false = year
				print("input numWinz");
				cin >> inputGrade;
				int decision = whichList();
				if (decision == 1)
				{
					print("QB SELECTED");
					QB->printList(QB->search(inputGrade, true));
				}
				else if (decision == 2)
				{
					print("EM SELECTED");
					EM->printList(EM->search(inputGrade, true));
				}
				else if (decision == 3)
				{
					print("BOTH SELECTED");
					print("QB");
					QB->printList(QB->search(inputGrade, true));
					print("EM");
					EM->printList(EM->search(inputGrade, true));
				}
				else
				{
					print ("Invalid input");
				}
			}
			else
			{
				print("invalid input");
			}
		}
		else if (input == "removeAll")
		{
			int decision = whichList();
			if (decision == 1)
			{
				print("QB SELECTED");
				QB->deleteAll();
			}
			else if (decision == 2)
			{
				print("EM SELECTED");
				EM->deleteAll();
			}
			else if (decision == 3)
			{
				print("BOTH SELECTED");
				print("QB");
				QB->deleteAll();
				print("EM");
				EM->deleteAll();
			}
			else
			{
				print ("Invalid input");
			}
		}
		else if (input == "remove")
		{
			print("type 'name' or 'index'");
			cin >> input;
			if (input == "index")
			{
				//search year
				//true = numWinz, false = year
				print("input index");
				cin >> inputGrade;
				int decision = whichList();
				if (decision == 1)
				{
					print("QB SELECTED");
					QB->deleteQB(inputGrade);
				}
				else if (decision == 2)
				{
					print("EM SELECTED");
					EM->deleteQB(inputGrade);
				}
				else if (decision == 3)
				{
					print("BOTH SELECTED");
					print("QB");
					QB->deleteQB(inputGrade);
					print("EM");
					EM->deleteQB(inputGrade);
				}
				else
				{
					print ("Invalid input");
				}
			}
			else if (input == "name")
			{
				//search name
				print("input first name");
				cin >> fNameInput;
				print("input last name");
				cin >> lNameInput;
				int decision = whichList();
				if (decision == 1)
				{
					print("QB SELECTED");
					QB->deleteQB(fNameInput,lNameInput);
				}
				else if (decision == 2)
				{
					print("EM SELECTED");
					EM->deleteQB(fNameInput,lNameInput);
				}
				else if (decision == 3)
				{
					print("BOTH SELECTED");
					print("QB");
					QB->deleteQB(fNameInput,lNameInput);
					print("EM");
					EM->deleteQB(fNameInput,lNameInput);
				}
				else
				{
					print ("Invalid input");
				}
			}
			else
			{
				print("invalid input");
			}
		}
		else if (input == "add")
		{
			print("input year");
			cin >> inputGrade;
			print("input first name");
			cin >> fNameInput;
			print("input last name");
			cin >> lNameInput;
			int decision = whichList();
			if (decision == 1)
			{
				print("QB SELECTED");
				QB->addQB(fNameInput,lNameInput,inputGrade);
			}
			else if (decision == 2)
			{
				print("EM SELECTED");
				EM->addQB(fNameInput,lNameInput,inputGrade);
			}
			else if (decision == 3)
			{
				print("BOTH SELECTED");
				print("QB");
				EM->addQB(fNameInput,lNameInput,inputGrade);
				print("EM");
				EM->addQB(fNameInput,lNameInput,inputGrade);
			}
			else
			{
				print ("Invalid input");
			}
		}
		else
		{
			print("invalid input");
		}
	}
	return 0;
}

int whichList()
{
	print("QB, EM, or both?");
	print("1 - QB");
	print("2 - EM");
	print("3 - both");
	int temp = 0;
	cin >> temp;
	if (temp == 1)
	{
		return 1;
	}
	else if (temp == 2)
	{
		return 2;
	}
	else if (temp == 3)
	{
		return 3;
	}
	else
	{
		return -1;
	}
	return -1;
}