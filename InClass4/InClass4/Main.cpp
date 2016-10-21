/////////////////////////////////
// Willard Wider               //
// 10/21/16                    //
// In class 4                  //
// Last Modified 10/21/16      //
/////////////////////////////////

//includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "LabAPI.h"
#include <cstdlib>

//defines


//constants


//structs and typedefs
struct student_t{
	string fname;
	string lName;
	student_t *next;
	int grade;
};

//method prototypes
void add( string firstName, string lastName, int gradee);
void remove(string firstName, string lastName);
void remove(int grade);
student_t* search( string firstname, string lastName);
student_t* search(int gradeSearch);
void printList();
void printList(student_t *tmep);
void removeAll(student_t *s);

//other definitions
using namespace std;
student_t *master = NULL;

//the main entry point of the application
int main()
{
	bool done = false;
	string input = "nullLOL";
	while (!done)
	{
		print("Type add, remove, removeAll, search, or print, or quit");
		cin >> input;
		if (input == "quit")
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

void add( string firstName, string lastName, int gradee)
{
	if (master == NULL)
	{
		student_t *temp = new student_t;
		(*temp).fname = firstName;
		(*temp).lName = lastName;
		(*temp).next = NULL;
		(*temp).grade = gradee;
	}
	else
	{
		student_t *traverseTemp = master;
		while (traverseTemp->next != NULL)
		{
			traverseTemp = traverseTemp->next;
		}
		student_t *temp = new student_t;
		(*temp).fname = firstName;
		(*temp).lName = lastName;
		(*temp).next = NULL;
		(*temp).grade = gradee;
		traverseTemp->next = temp;
	}
}

void remove(string firstName, string lastName)
{
	student_t *temp = master;
	while (temp->next != NULL)
	{
		if ((temp->fname == firstName) && (temp->lName == lastName))
		{
			temp->next = temp->next->next;
			delete(temp->next);
		}
		temp = temp->next;
	}
}

void remove(int grade)
{
	student_t *temp = master;
	while (temp->next != NULL)
	{
		if (temp->grade == grade)
		{
			temp->next = temp->next->next;
			delete(temp->next);
		}
		temp = temp->next;
	}
}

student_t* search( string firstname, string lastName)
{
	student_t *temp = master;
	student_t *returnTemp = NULL;
	while (temp->next != NULL)
	{
		if ((temp->fname == firstname) && (temp->lName == lastName))
		{
			if (returnTemp == NULL)
			{
				returnTemp = new student_t;
				(*returnTemp).fname = temp->fname;
				(*returnTemp).lName = temp->lName;
				(*returnTemp).grade = temp->grade;
				(*returnTemp).next = NULL;
			}
			else
			{
				student_t *next = new student_t;
				returnTemp->next = next;
				(*next).fname = temp->fname;
				(*next).lName = temp->lName;
				(*next).grade = temp->grade;
				(*next).next = NULL;
			}
		}
		temp = temp->next;
	}
	return returnTemp;
}

student_t* search(int gradeSearch)
{
	student_t *temp = master;
	student_t *returnTemp = NULL;
	while (temp->next != NULL)
	{
		if (temp->grade == gradeSearch)
		{
			if (returnTemp == NULL)
			{
				returnTemp = new student_t;
				(*returnTemp).fname = temp->fname;
				(*returnTemp).lName = temp->lName;
				(*returnTemp).grade = temp->grade;
				(*returnTemp).next = NULL;
			}
			else
			{
				student_t *next = new student_t;
				returnTemp->next = next;
				(*next).fname = temp->fname;
				(*next).lName = temp->lName;
				(*next).grade = temp->grade;
				(*next).next = NULL;
			}
		}
		temp = temp->next;
	}
	return returnTemp;
}

void printList()
{
	student_t *current = master;
	while (current->next != NULL)
	{
		print("student " + current->fname + ", " + current->lName + " has a grade of",current->grade);
		current = current->next;
	}
}

void printList(student_t *tmep)
{
	print("search results:");
	student_t *current = tmep;
	while (current->next != NULL)
	{
		print("student " + current->fname + ", " + current->lName + " has a grade of",current->grade);
		current = current->next;
	}
}

void removeAll(student_t *s)
{
	while (master != NULL)
	{
		removeAll(master->next);
	}
}