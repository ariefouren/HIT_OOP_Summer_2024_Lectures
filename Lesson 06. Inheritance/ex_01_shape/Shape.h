//
// Shape.h
// definition of class Shape
//
#pragma once
#include <string>
using namespace std;

class Shape
{
public:
	Shape(double x = 0, double y = 0);  // constructor with default values
	~Shape();                           // destructor

	string toString() const;            // returns a string representation of the shape
	double area() const;                // returns the area of the shape

	double getX() const;                // returns the x coordinate of the center of the shape
	double getY() const;                // returns the y coordinate of the center of the shape
	
private:
	double x;       // x coordinate of the center of the shape
	double y;       // y coordinate of the center of the shape
};
