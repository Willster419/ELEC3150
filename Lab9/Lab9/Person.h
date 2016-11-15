/////////////////////////////////
// Willard Wider               //
// Person.h                    //
// 11/09/16                    //
// Person class header         //
// Last Modified 11/14/16      //
/////////////////////////////////

//C library includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

//header guard
#ifndef PERSON_H
#define PERSON_H

//other definitions
using namespace std;
#include "LabAPI.h"

class Person //base class person
{
private:
	//private instance variables for all further inheritances
	string homeCity;
	int age;
	string fname;
	string lname;
public:
	//methods for all types of person
	///////////////////////
	//standard gets and sets
	string getCity();
	string getFname();
	string getLname();
	int getAge();
	void setCity(string city);
	void setFName(string fn);
	void setLName(string ln);
	void setAge(int a);
	//////////////////////
	//standard constructor
	Person();
	//constructor with ability to define instance variables on instance start
	Person(string city, int a, string fn, string ln);
	~Person();
};

#endif