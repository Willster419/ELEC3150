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
#ifndef CIRCLE_H
#define CIRCLE_H

//other definitions
using namespace std;
#include "shape.h"
class Circle :
	public Shape
{
private:
	float radius;
public:
	float getRadius();
	void setRadius(float r);
	Circle();
	~Circle();
};

#endif