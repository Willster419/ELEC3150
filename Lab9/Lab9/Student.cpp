////////////////////////////////////
// Willard Wider                  //
// Student.cpp                    //
// 11/09/16                       //
// Class student extending Person //
// Last Modified 11/09/16         //
////////////////////////////////////

//C library includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>

//user includes
#include "Student.h"

//defines


//constants


//structs and typedefs


//method prototypes


//other definitions
using namespace std;

string Student::getSchool()
{
	return school;
}


int Student::getClassYear()
{
	return classYear;
}


string Student::getGraduationDate()
{
	return graduationDate;
}


void Student::setSchool(string schooll)
{
	school = schooll;
}


void Student::setClassYear(int year)
{
	classYear = year;
}


void Student::setGraduationDate(string date)
{
	graduationDate = date;
}


Student::Student()
{
	print("student created");
	school = "";
	classYear = 0;
	graduationDate = "";
}


Student::Student(string schooll, int classYearr, string graduationDatee)
{
	print("student created");
	school = schooll;
	classYear = classYearr;
	graduationDate = graduationDatee;
}


Student::~Student()
{

}

void Student::addSchoolSkill(string skill)
{
	schoolSkillz.push_back(skill);
}


string Student::getSchoolSkillz()
{
	int counter = 0;
	string tempp = "";
	for (vector<string>::iterator temp = schoolSkillz.begin(); temp != schoolSkillz.end(); ++temp)
	{
		tempp+=*temp + "\n";
		counter++;
	}
	if (counter == 0)
	{
		return "";
	}
	else
	{
		return tempp;
	}
	return "";
}