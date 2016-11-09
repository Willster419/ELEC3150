/////////////////////////////////
// Willard Wider               //
// Person.h                    //
// 11/09/16                    //
// Person class header         //
// Last Modified 11/09/16      //
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

class Person
{
private:
	string homeCity;
	int age;
	string fname;
	string lname;
	vector<string> skillz;
public:
	string getCity();
	string getFname();
	string getLname();
	int getAge();
	void setCity(string city);
	void setFName(string fn);
	void setLName(string ln);
	void setAge(int a);
	Person();
	Person(string city, int a, string fn, string ln);
	~Person();
};

#endif