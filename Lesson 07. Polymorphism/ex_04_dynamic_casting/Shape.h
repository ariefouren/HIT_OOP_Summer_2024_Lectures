//
// Shape.h
// definition of class Shape
//
#pragma once
#include <string>
using namespace std;

#define VERBOSE	// make verbose output (in constructors and destructors)

class Shape		// base class    
{
public:
	Shape(double x = 0, double y = 0);
	virtual ~Shape(); 	// virtual destructor is necessary for dynamic binding 
						// of destructors

	virtual string toString() const; // virtual function allows dynamic binding
	virtual double area() const = 0; // pure virtual function makes Shape an abstract class
	
protected:
	double x;			// x coordinate of the center of the shape
	double y;			// y coordinate of the center of the shape
};
