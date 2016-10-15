/////////////////////////////////
// Willard Wider               //
// 10/13/16                    //
// Lab 6                       //
// Last Modified 10/15/16      //
/////////////////////////////////

//includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "LabAPI.h"
#include <cstdlib>

//defines
#define YEARS_ARRAY_LENGTH 4

//constants


//method prototypes
int addQB(string fName, string lName, int year);
int addQBFromFile();
int getIndex(string fN, string lN);
void printList();
string getInfo(int index);
int deleteAll();
int deleteQB(string fN, string lN);
int deleteQB(int index);
int QBSize();
void addYear(int *years, int size, int year);
void initYearsArray(int *years, int size);
string getAllWins(int *yearsWon, int size);

//other definitions
using namespace std;
struct qb_t
{
	string firstName, lastName;
	int numWins;
	int years[YEARS_ARRAY_LENGTH];
	int type;
	qb_t* next;
	qb_t* previous;
};
qb_t* master = 0;
qb_t* backup = 0;
typedef enum type_t
{
	first_T=0,
	last_T=1,
	other_T=-1
};

//the main entry point of the application
int main()
{
	int count = QBSize();
	addQB("Kurt","Warner",2000);
	count = QBSize();
	addQB("Trent2","Dilfer2",2001);
	count = QBSize();
	addQB("Trent","Dilfer",2002);
	count = QBSize();
	addQB("Trent","Dilfer",2003);
	count = QBSize();
	printList();
	return 0;
}

//add QB directly to the list. appends to the back
//-1 indicates error
int addQB(string fName, string lName, int year)
{
	if (master == NULL)
	{
		//first entry
		master = new qb_t;
		//qb_t first;
		
		(*master).firstName=fName;
		(*master).lastName=lName;
		(*master).numWins=1;
		int *yearsPointer = (*master).years;
		initYearsArray(yearsPointer, YEARS_ARRAY_LENGTH);
		(*master).years[0]=year;
		(*master).type=first_T;
		(*master).next=NULL;
		(*master).previous=NULL;
		backup = master;
		//master = &first;
		return 1;
	}
	else if (QBSize() == 1 && fName != master->firstName && lName != master->lastName)
	{
		//second entry
		master->next = new qb_t;
		qb_t *temp = master->next;
		(*temp).firstName=fName;
		(*temp).lastName=lName;
		(*temp).numWins=1;
		int *yearsPointer = (*temp).years;
		initYearsArray(yearsPointer, YEARS_ARRAY_LENGTH);
		(*temp).years[0]=year;
		(*temp).type=last_T;
		temp->next = master;
		temp->previous=master;
		master->previous = temp;
		return 1;
	}
	else
	{
		//traverse to the last element in the list
		//create and link
		qb_t *temp = master;
		while (temp->type != last_T)
		{
			//check for first and last name match
			if ((temp->firstName == fName) && (temp->lastName == lName))
			{
				//just add the year and pluz the wins
				temp->numWins++;
				addYear(temp->years,YEARS_ARRAY_LENGTH,year);
				break;
			}
			temp = temp->next;
		}
		if ((temp->firstName == fName) && (temp->lastName == lName))
			{
				//just add the year and pluz the wins
				temp->numWins++;
				addYear(temp->years,YEARS_ARRAY_LENGTH,year);
				return 1;
			}
		temp->type = other_T;
		temp->next = new qb_t;
		qb_t *theRealNext = temp->next;
		(*theRealNext).firstName=fName;
		(*theRealNext).lastName=lName;
		(*theRealNext).numWins=1;
		int *yearsPointer = (*theRealNext).years;
		initYearsArray(yearsPointer, YEARS_ARRAY_LENGTH);
		(*theRealNext).years[0]=year;
		(*theRealNext).type=last_T;
		theRealNext->next = master;
		theRealNext->previous = temp;
		master->previous = theRealNext;
	}
	return -1;
}

//add a series of QB's from file
//-1 indicates error
int addQBFromFile()
{

	return -1;
}

//get the index of the QB matching the specified criteria
//-1 indicates error
int getIndex(string fN, string lN)
{

	return -1;
}

//prints the entire list so far
void printList()
{
	//int length = lengthQB();
	//if (length == 0 || length == -1) return;
	if (master == NULL || master == 0) return;
	for ( qb_t *theNext = master; theNext != NULL; theNext = theNext->next)
	{
		string winz = IntToString(theNext->numWins);
		print(theNext->firstName + " " + theNext->lastName + " won " + winz + " times: " + getAllWins(theNext->years,YEARS_ARRAY_LENGTH));
	}
}

//gets all info on the QB in the form of a string
//-1 indicates error
string getInfo(int index)
{

	return "";
}

//deletes the entire list
//-1 indicates error
int deleteAll()
{

	return -1;
}

//delets a QB from the list based on the first and last name
//-1 indicates error
int deleteQB(string fN, string lN)
{

	return -1;
}

//deletes a QB from the list based on the index
//-1 indicates error
int deleteQB(int index)
{

	return -1;
}

//gets the length of the qb list
//-1 indicates error
int QBSize()
{
	if (master == NULL) return 0;
	int count = 0;
	string firstNameCheck = master->firstName;
	string lastNameCheck = master->lastName;
	for ( qb_t *theNext = master; theNext != NULL; theNext = theNext->next)
	{
		if ((count > 0) && (firstNameCheck == theNext->firstName) && (lastNameCheck == theNext->lastName))
		{
			return count;
		}
		count++;
	}
	return count;
}

void addYear(int *years, int size, int year)
{
	for (int i = 0; i < YEARS_ARRAY_LENGTH; i++)
	{
		if (years[i]==0)
			{
				years[i] = year;
				break;
			}
		else
		{

		}
	}
}

void initYearsArray(int *years, int size)
{
	for (int i = 0; i < size; i++)
	{
		years[i]=0;
	}
}

string getAllWins(int *yearsWon, int size)
{
	ostringstream o;
	for (int i = 0; i < size; i++)
	{
		o << yearsWon[i];
		int temp = yearsWon[i+1];
		if (temp == 0) break;
		o << ", ";
	}
	return o.str();
}