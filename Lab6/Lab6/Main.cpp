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
//method prototypes
int addQB(string fName, string lName, int year);
int addQBFromFile();
int getIndex(string fN, string lN);
void printList();
void printList(qb_t *CustomList);
void deleteAll(qb_t* startingPoint);
int deleteQB(string fN, string lN);
int deleteQB(int index);
int QBSize();
int QBSize(qb_t *customList);
void addYear(int *years, int size, int year);
void initYearsArray(int *years, int size);
string getAllWins(int *yearsWon, int size);
qb_t* search(string fName, string lName);
qb_t* search(int year, bool yearOrNumwinz);
void sortList();



//the main entry point of the application
int main()
{
	if (addQBFromFile() == -1) return;
	int result = QBSize();//0
	addQB("Kurt","Warner",2000);
	result = QBSize();//1
	addQB("Trent2","Dilfer2",2001);
	result = QBSize();//2
	addQB("Trent","Dilfer",2002);
	addQB("Trent","Dilfer",2003);
	result = getIndex("Trent","Dilfer");//should return 2
	result = getIndex("Trentt","Dilfer");//should return -1
	qb_t *answer = search("Trent","Dilfer");
	answer = search(1,true);
	answer = search(2000,false);
	printList();//prints all of them
	printList(answer);//prints the winner of 2000 Kurt
	result = deleteQB("Trent2","Dilfer2");//should be 1
	result = deleteQB("Trent2","Dilfer2");//should be -1
	result = deleteQB(1);//should be 1
	addQB("Brent2","Bilfer2",2001);
	result = QBSize();//2
	printList();
	sortList();
	printList();
	deleteAll(master);
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
	ifstream theFile;

	return -1;
}

//get the index of the QB matching the specified criteria
//-1 indicates error
int getIndex(string fN, string lN)
{
	int index = 0;
	qb_t *temp = master;
	while (true)
	{
		if ((temp->firstName == fN) && (temp->lastName == lN))
		{
			return index;
		}
		temp = temp->next;
		index++;
		if (temp->type == first_T)
		{
			break;
		}
	}
	return -1;
}

//prints the entire list so far
void printList()
{
	//int length = lengthQB();
	//if (length == 0 || length == -1) return;
	if (master == NULL || master == 0) return;
	qb_t *theNext = master;
	while (true)
	{
		string winz = int2String(theNext->numWins);
		print(theNext->firstName + " " + theNext->lastName + " won " + winz + " times: " + getAllWins(theNext->years,YEARS_ARRAY_LENGTH));
	theNext = theNext->next;
		if (theNext->type == first_T)
		{
			break;
		}
	}
}

//prints a custom qb list
void printList(qb_t *customList)
{
	//int length = lengthQB();
	//if (length == 0 || length == -1) return;
	if (customList == NULL || customList == 0) return;
	qb_t *theNext = customList;
	print("search results:");
	while (true)
	{
		string winz = int2String(theNext->numWins);
		print(theNext->firstName + " " + theNext->lastName + ", " + winz + " wins in " + getAllWins(theNext->years,YEARS_ARRAY_LENGTH));
		theNext = theNext->next;
		if (theNext == NULL)
		{
			break;
		}
	}
}

//deletes the entire list
//-1 indicates error
void deleteAll(qb_t* startingPoint)
{
	if(startingPoint->type != last_T)
	{
		deleteAll(startingPoint->next);
	}
	delete startingPoint;
}

//delets a QB from the list based on the first and last name
//-1 indicates error
int deleteQB(string fN, string lN)
{
	if (master == NULL || master == 0) return -1;
	qb_t *theNext = master;
	while (true)
	{
		if ((theNext->firstName == fN) && (theNext->lastName == lN))
		{
			theNext->previous->next = theNext->next;
			theNext->next->previous = theNext->previous;
			delete (theNext);
			return 1;
		}
	theNext = theNext->next;
		if (theNext->type == first_T)
		{
			break;
		}
	}
	return -1;
}

//deletes a QB from the list based on the index
//-1 indicates error
int deleteQB(int index)
{
	if (master == NULL || master == 0) return -1;
	qb_t *theNext = master;
	int i = 0;
	while (true)
	{
		if (i == index)
		{
			deleteQB(theNext->firstName,theNext->lastName);
			return 1;
		}
	theNext = theNext->next;
	i++;
		if (theNext->type == first_T)
		{
			break;
		}
	}
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

//gets the length of the qb list
//-1 indicates error
int QBSize(qb_t *customList)
{
	if (customList == NULL) return 0;
	int count = 0;
	string firstNameCheck = customList->firstName;
	string lastNameCheck = customList->lastName;
	for ( qb_t *theNext = customList; theNext != NULL; theNext = theNext->next)
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

//returns a custom linked list of all qb's matching the search criteria
qb_t* search(string fName, string lName)
{
	qb_t* starter = NULL;
	qb_t *tempp = master;
	bool created = false;
	while (true)
	{
		if ((tempp->firstName == fName) && (tempp->lastName == lName))
		{
			if (!created)
			{
				//if first time in the list
				starter = new qb_t;
				(*starter).firstName = (*tempp).firstName;
				(*starter).lastName = (*tempp).lastName;
				(*starter).numWins = (*tempp).numWins;
				(*starter).type = first_T;
				for (int i = 0; i < YEARS_ARRAY_LENGTH; i++)
				{
					(*starter).years[i] = (*tempp).years[i];
				}
				(*starter).next = NULL;
			}
			else if (QBSize(starter) == 1)
			{
				//just keep making the list
				starter->next = new qb_t;
				starter->previous = starter->next;
				qb_t *ttemp = starter->next;
				(*ttemp).firstName = (*tempp).firstName;
				(*ttemp).lastName = (*tempp).lastName;
				(*ttemp).numWins = (*tempp).numWins;
				(*ttemp).type = last_T;
				ttemp->next = starter;
				ttemp->previous = starter;
				for (int i = 0; i < YEARS_ARRAY_LENGTH; i++)
				{
					(*ttemp).years[i] = (*tempp).years[i];
				}
			}
			else
			{
				//same as above, but this one is inserting
				//traverse to the last element in the list
				//create and link
				qb_t *ttemp = starter;
				while (ttemp->type != last_T)
				{
					ttemp = ttemp->next;
				}
				ttemp->type = other_T;
				ttemp->next = new qb_t;
				qb_t *temp = ttemp->next;
				(*temp).firstName = (*tempp).firstName;
				(*temp).lastName = (*tempp).lastName;
				(*temp).numWins = (*tempp).numWins;
				(*temp).type = last_T;
				for (int i = 0; i < YEARS_ARRAY_LENGTH; i++)
				{
					(*temp).years[i] = (*tempp).years[i];
				}
				ttemp->next=temp;
				temp->previous=ttemp;
				temp->next=starter;
			}
		}
		tempp = tempp->next;
		if (tempp->type == first_T)
		{
			//end of the list
			break;
		}
	}
	return starter;
}

//returns a custom linked list of all qb's matching the search criteria
qb_t* search(int year, bool yearOrNumWinz)
{
	if(yearOrNumWinz)
	{
		//searching for numWinz
		qb_t* starter = NULL;
	qb_t *tempp = master;
	bool created = false;
	while (true)
	{
		if (tempp->numWins == year)
		{
			if (!created)
			{
				//if first time in the list
				starter = new qb_t;
				(*starter).firstName = (*tempp).firstName;
				(*starter).lastName = (*tempp).lastName;
				(*starter).numWins = (*tempp).numWins;
				(*starter).type = first_T;
				for (int i = 0; i < YEARS_ARRAY_LENGTH; i++)
				{
					(*starter).years[i] = (*tempp).years[i];
				}
				(*starter).next = NULL;
				created = true;
			}
			else if (QBSize(starter) == 1)
			{
				//just keep making the list
				starter->next = new qb_t;
				starter->previous = starter->next;
				qb_t *ttemp = starter->next;
				(*ttemp).firstName = (*tempp).firstName;
				(*ttemp).lastName = (*tempp).lastName;
				(*ttemp).numWins = (*tempp).numWins;
				(*ttemp).type = last_T;
				ttemp->next = starter;
				ttemp->previous = starter;
				for (int i = 0; i < YEARS_ARRAY_LENGTH; i++)
				{
					(*ttemp).years[i] = (*tempp).years[i];
				}
			}
			else
			{
				//same as above, but this one is inserting
				//traverse to the last element in the list
				//create and link
				qb_t *ttemp = starter;
				while (ttemp->type != last_T)
				{
					ttemp = ttemp->next;
				}
				ttemp->type = other_T;
				ttemp->next = new qb_t;
				qb_t *temp = ttemp->next;
				(*temp).firstName = (*tempp).firstName;
				(*temp).lastName = (*tempp).lastName;
				(*temp).numWins = (*tempp).numWins;
				(*temp).type = last_T;
				for (int i = 0; i < YEARS_ARRAY_LENGTH; i++)
				{
					(*temp).years[i] = (*tempp).years[i];
				}
				ttemp->next=temp;
				temp->previous=ttemp;
				temp->next=starter;
			}
		}
		tempp = tempp->next;
		if (tempp->type == first_T)
		{
			//end of the list
			break;
		}
	}
	return starter;
	}
	else
	{
	//searching for year
	qb_t* starter = NULL;
	qb_t *tempp = master;
	bool created = false;
	while (true)
	{
		for (int i = 0; i < YEARS_ARRAY_LENGTH; i++)
		{
		if (tempp->years[i] == year)
		{
			if (!created)
			{
				//if first time in the list
				starter = new qb_t;
				(*starter).firstName = (*tempp).firstName;
				(*starter).lastName = (*tempp).lastName;
				(*starter).numWins = (*tempp).numWins;
				(*starter).type = first_T;
				for (int i = 0; i < YEARS_ARRAY_LENGTH; i++)
				{
					(*starter).years[i] = (*tempp).years[i];
				}
				(*starter).next = NULL;
			}
			else if (QBSize(starter) == 1)
			{
				//just keep making the list
				starter->next = new qb_t;
				starter->previous = starter->next;
				qb_t *ttemp = starter->next;
				(*ttemp).firstName = (*tempp).firstName;
				(*ttemp).lastName = (*tempp).lastName;
				(*ttemp).numWins = (*tempp).numWins;
				(*ttemp).type = last_T;
				ttemp->next = starter;
				ttemp->previous = starter;
				for (int i = 0; i < YEARS_ARRAY_LENGTH; i++)
				{
					(*ttemp).years[i] = (*tempp).years[i];
				}
			}
			else
			{
				//same as above, but this one is inserting
				//traverse to the last element in the list
				//create and link
				qb_t *ttemp = starter;
				while (ttemp->type != last_T)
				{
					ttemp = ttemp->next;
				}
				ttemp->type = other_T;
				ttemp->next = new qb_t;
				qb_t *temp = ttemp->next;
				(*temp).firstName = (*tempp).firstName;
				(*temp).lastName = (*tempp).lastName;
				(*temp).numWins = (*tempp).numWins;
				(*temp).type = last_T;
				for (int i = 0; i < YEARS_ARRAY_LENGTH; i++)
				{
					(*temp).years[i] = (*tempp).years[i];
				}
				ttemp->next=temp;
				temp->previous=ttemp;
				temp->next=starter;
			}
		}
	}
		tempp = tempp->next;
		if (tempp->type == first_T)
		{
			//end of the list
			break;
		}
	}
	return starter;
	}
	return NULL;
}

//sorts the list using bubbleSort
void sortList()
{

}