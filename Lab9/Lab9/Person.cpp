/////////////////////////////////
// Willard Wider               //
// Person.cpp                  //
// 11/09/16                    //
// Person Class                //
// Last Modified 11/09/16      //
/////////////////////////////////

//C library includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>

//user includes
#include "Person.h"

//defines


//constants


//structs and typedefs


//method prototypes


//other definitions
using namespace std;

string Person::getCity()
{
	return homeCity;
}


string Person::getFname()
{
	return fname;
}


string Person::getLname()
{
	return lname;
}


int Person::getAge()
{
	return age;
}


void Person::setCity(string city)
{
	homeCity = city;
}


void Person::setFName(string fn)
{
	fname = fn;
}


void Person::setLName(string ln)
{
	lname = ln;
}


void Person::setAge(int a)
{
	age = a;
}


Person::Person()
{
	homeCity = "";
	age = 0;
	fname = "";
	lname = "";
	print("Person created");
}


Person::Person(string city, int a, string fn, string ln)
{
	homeCity = city;
	age = a;
	fname = fn;
	lname = ln;
	print("Person created");
}


Person::~Person()
{

}
