/////////////////////////////////
// Willard Wider               //
// Main.cpp                    //
// 11/09/16                    //
// Lab 9                       //
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
#include "LabAPI.h"
#include "Intern.h"
#include "Student.h"

//defines


//constants


//structs and typedefs


//method prototypes


//other definitions
using namespace std;
ostringstream oss2;

//the main entry point of the application
int main()
{
	//to do this in array (or vector)
	//Person *peopleList[3];

	//Creating all values of Person
	Person p = *new Person("Hollis",21,"Willard","Wider");

	//Creating all values of Person->Student
	Student s = *new Student("Wentworth",2018,"4/20/2018");
	s.setCity("Brookline");
	s.setAge(22);
	s.setFName("Bryon");
	s.setLName("Kush");
	s.addSchoolSkill("Programming in C++");
	s.addSchoolSkill("Engineering Economy");


	//Creating all values of Person->Student->Intern
	Intern i = *new Intern("BAE Systems",420.69,"9/9/2020");
	i.setCity("Nashua");
	i.setAge(32);
	i.setFName("Joe");
	i.setLName("Rodger");
	i.setSchool("Wentworth");
	i.setClassYear(2018);
	i.setGraduationDate("9/3/2018");
	i.addSchoolSkill("Programming in Java");
	i.addSchoolSkill("Database Management");
	i.addWorkSkill("Project Management");
	i.addWorkSkill("Communications");

	print();
	//print each one
	//person info
	print("Person " + p.getFname() + " " + p.getLname() + " from " + p.getCity());
	print();

	//student info
	print("Person " + s.getFname() + " " + s.getLname() + " from " + s.getCity());
	oss2 << "is also student of " << s.getSchool() << " graduating " << s.getClassYear() << " with graduation date " << s.getGraduationDate();
	print(oss2.str());
	print("also has the following school skills");
	print(s.getSchoolSkillz());
	print();
	
	//intern info
	print("Person " + i.getFname() + " " + i.getLname() + " from " + i.getCity());
	oss2 << "is also student of " << i.getSchool() << " graduating " << i.getClassYear() << " with graduation date " << i.getGraduationDate();
	print(oss2.str());
	oss2 << "is also intern of " << i.getCompanyOfEmployment() << " with pay " << i.getWeeklyPay() << " with job completion date " << i.getDateJobCompletion();
	print(oss2.str());
	print("also has the following school skills");
	cout << i.getSchoolSkillz();
	print("also has the following work skills");
	print(i.getWorkSkillz());
	return 0;
}