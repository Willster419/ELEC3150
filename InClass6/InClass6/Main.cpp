/////////////////////////////////
// Willard Wider               //
// Main.cpp                    //
// XX/XX/XX                    //
// Lab X                       //
// Last Modified XX/XX/XX      //
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
#include "Circle.h"
#include "Shape.h"

//defines


//constants


//structs and typedefs


//method prototypes


//other definitions
using namespace std;


//the main entry point of the application
int main()
{
	Shape thing = *new Shape();
	thing.setArea(4);
	thing.setPerimiter(2);
	print("shape thing has area",thing.getArea());


	Circle c = *new Circle();
	c.setArea(5);
	c.setPerimiter(2);
	c.setRadius(1);
	print("circle c has perimiter",c.getPerimiter());
	print("cicle c also has radius",c.getRadius());
	return 0;
}