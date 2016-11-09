///////////////////////////////////
// Willard Wider                 //
// Intern.cpp                    //
// 11/09/16                      //
// Intern Class extending Person //
// Last Modified 11/09/16        //
///////////////////////////////////

//C library includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>

//user includes
#include "Intern.h"

//defines


//constants


//structs and typedefs


//method prototypes


//other definitions
using namespace std;

string Intern::getCompanyOfEmployment()
{
	return companyOfEmployment;
}


float Intern::getWeeklyPay()
{
	return weeklyPay;
}


string Intern::getDateJobCompletion()
{
	return dateJobCompletion;
}


void Intern::setCompanyOfEmployment(string comp)
{
	companyOfEmployment = comp;
}


void Intern::setWeeklyPay(float p)
{
	weeklyPay = p;
}


void Intern::setDateJobCompletion(string date)
{
	dateJobCompletion = date;
}


Intern::Intern()
{
	print("Intern Created");
	companyOfEmployment = "";
	weeklyPay = 0;
	dateJobCompletion = "";
}


Intern::Intern(string comp, float pay, string date)
{
	print("Intern Created");
	companyOfEmployment = comp;
	weeklyPay = pay;
	dateJobCompletion = date;
}


Intern::~Intern()
{

}


void Intern::addWorkSkill(string skill)
{
	workSkillz.push_back(skill);
}


string Intern::getWorkSkillz()
{
	int counter = 0;
	string tempp = "";
	for (vector<string>::iterator temp = workSkillz.begin(); temp != workSkillz.end(); ++temp)
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