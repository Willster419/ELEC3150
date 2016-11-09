/////////////////////////////////
// Willard Wider               //
// LabAPI.h                    //
// 09/21/16                    //
// General Lab Assistance File //
// Last Modified 11/01/16      //
/////////////////////////////////

//C library includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>

//header guard
#ifndef SHAPE_H
#define SHAPE_H

//other definitions
using namespace std;
class Shape
{
private:
	float area;
	float perimiter;
public:
	float getPerimiter();
	float getArea();
	void setArea(float a);
	void setPerimiter(float p);
	Shape();
	~Shape();
};

#endif