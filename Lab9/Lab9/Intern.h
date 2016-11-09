////////////////////////////////////
// Willard Wider                  //
// Intern.h                       //
// 11/09/16                       //
// Intern Header                  //
// Last Modified 11/09/16         //
////////////////////////////////////

//C library includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

//header guard
#ifndef INTERN_H
#define INTERN_H

//other definitions
using namespace std;
#include "person.h"
#include "Student.h"
#include "LabAPI.h"

class Intern :
	public Student
{
private:
	string companyOfEmployment;
	float weeklyPay;
	string dateJobCompletion;
	vector<string> workSkillz;
public:
	string getCompanyOfEmployment();
	float getWeeklyPay();
	string getDateJobCompletion();
	void setCompanyOfEmployment(string comp);
	void setWeeklyPay(float p);
	void setDateJobCompletion(string date);
	Intern();
	Intern(string comp, float pay, string date);
	void addWorkSkill(string skill);
	string getWorkSkillz();
	~Intern();
};

#endif