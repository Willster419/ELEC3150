/////////////////////////////////
// Willard Wider               //
// Main.cpp                    //
// 10/28/16                    //
// InClass5                    //
// Last Modified 10/28/16      //
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


//defines


//constants
const string task_done = "done with task, press enter to continue..";

//structs


//typedefs


//method prototypes(if no header file)


//other definitions
using namespace std;


//the main entry point of the application
int main()
{
	print("creating circles, one with regualr construct one with fancy construct");
	Circle *c1 = new Circle();
	c1->setRadius(10);
	Circle c2 = *new Circle(5);
	print("The radius of c1 is" , c1->getRadius());
	print("The radius of c2 is" , c2.getRadius());
	print("The circumfrence of c1 is" , c1->getCircumfrence());
	print("The circumfrence of c2 is" , c2.getCircumfrence());
	print("The area of c1 is" , c1->getRadius());
	print("The area of c2 is" , c2.getRadius());
	print("desturcting the c1 nd c2...");
	return 0;
}
