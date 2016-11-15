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
	public Person//extends the base class person
{
private://private instance variables related to student (not person), but can be
	//inherited by other classes further down the road.
	string school;
	int classYear;
	string graduationDate;
	vector<string> schoolSkillz;//a vecor of string school skillz, is dynamic
	//i.e. can have 0 items, or have any number of items
public://same ad above about private
	string getSchool();
	int getClassYear();
	string getGraduationDate();
	void setSchool(string schooll);
	void setClassYear(int year);
	void setGraduationDate(string date);
	Student();
	Student(string schooll, int classYear, string graduationDate);
	//add a school skill to the schoolSkillz vector array
	void addSchoolSkill(string skill);
	//return a string of all school skillz
	string getSchoolSkillz();
	~Student();
};

#endif