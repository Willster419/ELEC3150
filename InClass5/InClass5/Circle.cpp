/////////////////////////////////
// Willard Wider               //
// Circle.cpp                  //
// 10/31/16                    //
// It's a circle class I guess //
// Last Modified 10/31/16      //
/////////////////////////////////

#include "Circle.h"


Circle::Circle()
{
	radius = 0;
}

Circle::Circle(float rad)
{
	radius = rad;
}

float Circle::getRadius()
{
	return radius;
}

float Circle::getArea()
{
	float ha_gadi = radius * radius;
	ha_gadi = ha_gadi * PI;
	return ha_gadi;
}

float Circle::getCircumfrence()
{
	float deezNutz = radius * PI;
	deezNutz = deezNutz*2;
	return deezNutz;
}

void Circle::setRadius(float rad)
{
	radius=rad;
}

Circle::~Circle()
{
	print("instance has been rekt");
}
