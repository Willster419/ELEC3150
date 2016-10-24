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
int add( string firstName, string lastName, int gradee);
void removeL(string firstName, string lastName);
void removeL(int grade);
student_t* search( string firstname, string lastName);
student_t* search(int gradeSearch);
void printList();
void printList(student_t *tmep);
void removeAll(student_t *s);
int countL();

//other definitions
using namespace std;
student_t *master = NULL;

//the main entry point of the application
int main()
{
	add("Willard","Wider",92);
	//add("Willard","Wider",90);
	add("Bryon","Kushman",90);
  	add("Deez","Nutz",92);
	bool done = false;
	string input = "nullLOL";
	int inputGrade = 0;
	string fNameInput = "null";
	string lNameInput = "null";
	while (!done)
	{
		print("Type add, remove, removeAll, search, or print, or quit");
		cin >> input;
		if (input == "quit")
		{
			done = true;
		}
		else if (input == "print")
		{
			//print the list
			printList();
		}
		else if (input == "search")
		{
			print("type grade or name");
			cin >> input;
			if (input == "grade")
			{
				//search grade
				print("input grade 0-100");
				cin >> inputGrade;
				printList(search(inputGrade));
			}
			else if (input == "name")
			{
				//search name
				print("input first name");
				cin >> fNameInput;
				print("input last name");
				cin >> lNameInput;
				printList(search(fNameInput,lNameInput));
			}
			else
			{
				print("invalid input");
			}
		}
		else if (input == "removeAll")
		{
			removeAll(master);
		}
		else if (input == "remove")
		{
			print("type grade or name");
			cin >> input;
			if (input == "grade")
			{
				//search grade
				print("input grade 0-100");
				cin >> inputGrade;
				removeL(inputGrade);
			}
			else if (input == "name")
			{
				//search name
				print("input first name");
				cin >> fNameInput;
				print("input last name");
				cin >> lNameInput;
				removeL(fNameInput,lNameInput);
			}
			else
			{
				print("invalid input");
			}
		}
		else if (input == "add")
		{
			print("input grade 0-100");
			cin >> inputGrade;
			print("input first name");
			cin >> fNameInput;
			print("input last name");
			cin >> lNameInput;
			if(!add(fNameInput,lNameInput,inputGrade))
			{

			}
			else
			{
				print("Error: name already exists");
			}
		}
		else
		{
			print("invalid input");
		}
	}
	return 0;
}

int add( string firstName, string lastName, int gradee)
{
	if (master == NULL)
	{
		student_t *temp = new student_t;
		(*temp).fname = firstName;
		(*temp).lName = lastName;
		(*temp).next = NULL;
		(*temp).grade = gradee;
		master = temp;
	}
	else
	{
		student_t *traverseTemp = master;
		while (traverseTemp != NULL)
		{
			if((traverseTemp->fname == firstName) && (traverseTemp->lName == lastName))
				return -1;
			traverseTemp = traverseTemp->next;
		}
		traverseTemp = master;
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
	return 0;
}

void removeL(string firstName, string lastName)
{
	for (student_t *temp = master; temp != NULL; )
	{
		student_t *previous = temp;
		student_t *current = temp->next;
		if ((previous->fname == firstName) && (previous->lName == lastName))
		{
			//first in list
			
			
				//replace master
				master = previous->next;
				temp = temp->next;
				delete(previous);
				previous = NULL;
			
			continue;
		}
		else if (current == NULL)
		{
			//DNE
			break;
		}
		else if (current->next == NULL)
		{
			//last in list
			if ((current->fname == firstName) && (current->lName == lastName))
			{
				current = NULL;
				previous->next = NULL;
			}
			break;
		}
		else
		{
			//regualr middle part somewhere
			if((current->fname == firstName) && (current->lName == lastName))
			{
				previous->next = current->next;
			}
			temp = temp->next;
			continue;
		}
		
	}
}

void removeL(int grade)
{
	for (student_t *temp = master; temp != NULL; )
	{
		student_t *previous = temp;
		student_t *current = temp->next;
		if (previous->grade == grade)
		{
			//first in list
			
			
				//replace master
				master = previous->next;
				temp = temp->next;
				delete(previous);
				previous = NULL;
			
			continue;
		}
		else if (current == NULL)
		{
			//DNE
			break;
		}
		else if (current->next == NULL)
		{
			//last in list
			if (current->grade == grade)
			{
				current = NULL;
				previous->next = NULL;
			}
			break;
		}
		else
		{
			//regualr middle part somewhere
			if(current->grade == grade)
			{
				previous->next = current->next;
			}
			temp = temp->next;
			continue;
		}
		
	}
}

student_t* search( string firstname, string lastName)
{
	if (master == NULL)
		return NULL;
	student_t *temp = master;
	student_t *returnTemp = NULL;
	while (true)
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
		if (temp->next == NULL)
		{
			break;
		}
		temp = temp->next;
	}
	return returnTemp;
}

student_t* search(int gradeSearch)
{
	if (master == NULL)
		return NULL;
	student_t *temp = master;
	student_t *returnTemp = NULL;
	while (true)
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
		if (temp->next == NULL)
		{
			break;
		}
		temp = temp->next;
	}
	return returnTemp;
}

void printList()
{
	if (master == NULL)
	{
		print("list is empty");
		return;
	}
	student_t *current = master;
	while (true)
	{
		print("student " + current->fname + ", " + current->lName + " has a grade of",current->grade);
		if (current->next == NULL)
		{
			break;
		}
		current = current->next;
	}
}

void printList(student_t *tmep)
{
	print("search results:");
	if (tmep == NULL)
	{
		print("search is empty");
		return;
	}
	student_t *current = tmep;
	while (true)
	{
		print("student " + current->fname + ", " + current->lName + " has a grade of",current->grade);
		if (current->next == NULL)
		{
			break;
		}
		current = current->next;
	}
}

void removeAll(student_t *s)
{
	if (s != NULL)
	{
		removeAll(s->next);
		delete(s);
		master = NULL;
	}
}

int countL()
{
	int count = 0;
	student_t *current = master;
	if (master==NULL)
		return count;
	while (true)
	{
		count++;
		if (current->next == NULL)
		{
			break;
		}
		current = current->next;
	}
	return count;
}