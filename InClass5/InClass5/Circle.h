/////////////////////////////////
// Willard Wider               //
// Circle.h                    //
// 10/31/16                    //
// It's a circle class I guess //
// Last Modified 10/31/16      //
/////////////////////////////////
#define PI 3.1416
#include "LabAPI.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H 
class Circle
{

private:
	float radius;

public:
	void setRadius(float rad);
	float getRadius();
	float getArea();
	float getCircumfrence();
	Circle();
	Circle(float rad);
	~Circle();
};
#endif

