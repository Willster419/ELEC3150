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
#include <fstream>

//defines
#define YEARS_ARRAY_LENGTH 4

//constants
const string task_done = "done with task, press enter to continue..";

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
	print ("Lab 6 - Double Linked List");
	int result = QBSize();//0
	print();
	print("the initial size of the list is",result);
	print("adding from file...");
	if (addQBFromFile() == -1)
		{
			print("failed to load file");
			return -1;
	}
	printList();
	run_complete(task_done);
	print();
	print("searching for index of 'Trent Dilfer'...");
	result = getIndex("Trent","Dilfer");//should return 1
	print("index is " + int2String(result) + " , meaning sucess");
	print("searching for index of 'Trentt Dilfer'...");
	result = getIndex("Trentt","Dilfer");//should return -1
	print("index is " + int2String(result) + " , meaning it does not exist");
	run_complete(task_done);
	print();
	print("searching and printing information for 'Trent Dilfer'...");
	qb_t *answer = search("Trent","Dilfer");
	if (answer != NULL)printList(answer);
	print();
	print("searching and printing information for QB with 1 wins...");
	answer = search(1,true);
	if (answer != NULL)printList(answer);
	print();
	print("searching and printing information for QB winner of 2006...");
	answer = search(2006,false);
	if (answer != NULL)printList(answer);
	print();
	print("searching and printing information for QB winner of 2020 (which does not exist)...");
	answer = search(2020,false);
	if (answer != NULL)printList(answer);
	else print("not found");
	print();
	run_complete(task_done);
	print("Deleting QB 'Trent Dilfer'...");
	result = deleteQB("Trent","Dilfer");//should be 1
	print("result was " + int2String(result) + " (sucess)");
	print();
	print("Deleting QB 'Trent2 Dilfer2' (does not exist)...");
	result = deleteQB("Trent2","Dilfer2");//should be -1
	print("result was " + int2String(result) + " (cound not find it)");
	print();
	print("Deleting QB @ index 4...");
	result = deleteQB(4);//should be 1
	print("result was " + int2String(result) + " (sucess)");
	print();
	run_complete(task_done);
	print("adding 'Trent Dilfer' to the list...");
	result = addQB("Trent","Dilfer",2001);
	print("result was " + int2String(result) + " (sucess)");
	print();
	result = QBSize();
	print("by the way, the length of the list is",result);
	run_complete(task_done);
	print();
	print("here is the list before sorting");
	printList();
	print();
	print("here is the list after sorting");
	sortList();
	printList();
	run_complete(task_done);
	print("recursivly deleting the list...");
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
				return 1;
			}
			temp = temp->next;
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
		return 1;
	}
	return -1;
}

//add a series of QB's from file
//-1 indicates error
int addQBFromFile()
{
	ifstream theFile ("Lab 6_QB_List.txt");
	string line;
	string tempArray[3];
	int i = 0;
	if (theFile.is_open())
	{
		while (getline(theFile,line))
		{
			stringstream parser(line);
			i=0;
			while(parser.good())
			{
				parser >> tempArray[i];
				i++;
			}
			string fName = tempArray[0];
			string lName = tempArray[1];
			string year = tempArray[2];
			char convert[420];
			for (int k = 0; k < year.size(); k++)
			{
				convert[k] = year[k];
			}
			sscanf(convert,"%d",&i);
			addQB(fName,lName,i);
		}
		theFile.close();
		return 0;
	}
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
	int size = QBSize(customList);
	int i = 0;
	while (true)
	{
		string winz = int2String(theNext->numWins);
		print(theNext->firstName + " " + theNext->lastName + ", " + winz + " wins in " + getAllWins(theNext->years,YEARS_ARRAY_LENGTH));
		theNext = theNext->next;
		i++;
		if (theNext == NULL || i == size)
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
		if (temp == 0 || temp == -1) break;
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
	bool sorted = false;
	int size2 = QBSize();
	int sizePart2 = size2;
	//detach the list
	qb_t *temp = master;
	temp->previous->next = NULL;
	temp->previous = NULL;
	while (!sorted)
	{
		sorted = true;
		for (qb_t *te = master; te != NULL; te = te->next)
		{
			if (te->next != NULL)
			{
			int i = 0;
			char current = te->lastName[i];
			char next = te->next->lastName[i];
			while (te->lastName[i] == te->next->lastName[i])
			{
				i++;
				if ((i == te->lastName.size()) || (i == te->next->lastName.size()))
				{
					int j = 0;
					current = te->firstName[j];
					next = te->next->firstName[j];
					while (te->firstName[j] == te->next->firstName[j])
					{
						j++;
						current = te->firstName[j];
						next = te->next->firstName[j];
					}
					break;
				}
				current = te->lastName[i];
				next = te->next->lastName[i];
			}
			if (current > next)
			{
				//swap
				sorted = false;
				if(te->type == first_T)
				{
					//special case of first one
					qb_t *other = te->next;
					qb_t *next = te->next->next;
					//set type orders
					other->type = first_T;
					te->type = other_T;
					//create next links
					other->next = te;
					te->next = next;
					//create previous links
					next->previous = te;
					te->previous = other;
					other->previous = NULL;
					master = other;
				}
				else if ((te->type == last_T) || te->next->next == NULL)
				{
					//special case of last one
					qb_t* other = te->next;
					qb_t* prev = te->previous;
					//set orders
					other->type = other_T;
					te->type = last_T;
					//create next links
					prev->next = other;
					te->next = NULL;
					other->next = te;
					//create previous links
					other->previous = prev;
					te->previous = other;
				}
				else
				{
				qb_t *previous = te->previous;
				previous->next = NULL;
				qb_t *next = te->next->next;
				next->previous = NULL;
				qb_t *moving = te->next;
				moving->next = NULL;
				moving->previous = NULL;
				te->previous = NULL;
				te->next = NULL;
				//relink nexts
				previous->next = moving;
				moving->next=te;
				te->next=next;
				//relink previouses
				next->previous = te;
				te->previous = moving;
				moving->previous=previous;
				}
				
				//backup and break the links for the next and previous not being flipped
				
			}
			}
		}
	}
	//relink the lists and declare which is which in terms of type
	qb_t *te2 = master;
	te2->type = first_T;
	for ( ;te2->next != NULL; te2 = te2->next)
		{
			te2->next->type = other_T;
		}
	te2->type = last_T;
	te2->next=master;
	master->previous = te2;
}