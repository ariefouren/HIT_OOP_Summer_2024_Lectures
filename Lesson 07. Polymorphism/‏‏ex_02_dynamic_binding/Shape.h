//
// Shape.h
// definition of class Shape
//
#pragma once
#include <string>
using namespace std;

class Shape		// base class    
{
public:
	Shape(double x = 0, double y = 0);
	~Shape();

	virtual string toString() const; // virtual function allows dynamic binding
	virtual double area() const;
	
protected:
	double x;			// x coordinate of the center of the shape
	double y;			// y coordinate of the center of the shape
};
