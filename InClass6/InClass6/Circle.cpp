#include "Circle.h"
#include "LabAPI.h"

Circle::Circle()
{
	print("Circle Created");
}


Circle::~Circle()
{
}

float Circle::getRadius(){return radius;}
void Circle::setRadius(float r){radius = r;}