//
// Circle.h
// definition of class Circle 
//

#pragma once
#include "Shape.h"

class Circle : public Shape // derived class, inherit from Shape
{
public:
	Circle(double x = 0, double y = 0, double r = 0);
	~Circle();
	string toString() const; 	// overrides Shape::toString
	double area() const;		// overrides Shape::area
	void setR(double r);		

private:
	double r;
};
