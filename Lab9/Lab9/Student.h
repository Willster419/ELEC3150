////////////////////////////////////
// Willard Wider                  //
// Student.h                      //
// 09/21/16                       //
// Header of Student Class        //
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
#ifndef STUDENT_H
#define STUDENT_H

//other definitions
using namespace std;
#include "person.h"
#include "LabAPI.h"

class Student :
	public Person
{
private:
	string school;
	int classYear;
	string graduationDate;
	vector<string> schoolSkillz;
public:
	string getSchool();
	int getClassYear();
	string getGraduationDate();
	void setSchool(string schooll);
	void setClassYear(int year);
	void setGraduationDate(string date);
	Student();
	Student(string schooll, int classYear, string graduationDate);
	void addSchoolSkill(string skill);
	string getSchoolSkillz();
	~Student();
};

#endif