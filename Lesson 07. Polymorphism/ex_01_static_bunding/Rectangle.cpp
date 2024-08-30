//
// Rectangle.cpp
// implementation of class Rectangle
//

#include "Rectangle.h"	
#include <iostream>
#include <iomanip> //for std::setprecision, formatted printing
#include <string>
#include <sstream> //for printing to string

using namespace std;

Rectangle::Rectangle(double x, double y, double length, double height):
	Shape(x, y), length(length), height(height)
{
	#ifdef VERBOSE // print the message only if VERBOSE is defined
	cout << "constructor for : " << toString() << endl;
	#endif
}

Rectangle::~Rectangle()
{
	#ifdef VERBOSE // print the message only if VERBOSE is defined
	cout << "destructor for : " << toString() << endl;
	#endif
}

string Rectangle::toString() const
{
	ostringstream oss;
    oss << fixed << setprecision(2); // set 2 decimal places 
    oss << "Rectangle[ x = " << x << 
					", y = " << y << 
					", length = " << length << 
					", height = " << height << "]";
	return oss.str();
}

double Rectangle::area() const
{
	return length * height;
}
