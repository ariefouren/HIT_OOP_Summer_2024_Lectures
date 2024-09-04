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
	virtual ~Shape() = 0; 	// virtual destructor allows dynamic binding
							// of the destructor in run-time
							// virtual destructor must have a body
							// pure virtual destructor makes Shape an abstract class

	virtual string toString() const; // virtual function allows dynamic binding
	virtual double area() const = 0; // pure virtual function makes Shape an abstract class
	
protected:
	double x;			// x coordinate of the center of the shape
	double y;			// y coordinate of the center of the shape
};
