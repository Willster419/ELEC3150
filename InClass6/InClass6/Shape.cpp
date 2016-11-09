#include "Shape.h"
#include "LabAPI.h"

Shape::Shape()
{
	print("Shape Created");
}


Shape::~Shape()
{
}

float Shape::getPerimiter() {return perimiter;}
float Shape::getArea() {return area;}
void Shape::setArea(float a){area = a;}
void Shape::setPerimiter(float p) {perimiter = p;}