//
// Shape.cpp
// implementation of class Shape
//

#include "Shape.h"
#include <iostream>
#include <string>
#include <sstream> //for printing to string
#include <iomanip> //for std::setprecision, formatted printing

using namespace std;

Shape::Shape(double x, double y) : x(x), y(y)
{
	#ifdef VERBOSE // print the message only if VERBOSE is defined
	cout << "constructor for " << this->toString() << endl;
	#endif
}

Shape::~Shape()
{
	#ifdef VERBOSE // print the message only if VERBOSE is defined
	cout << "destructor for " << this->toString() << endl;
	#endif
}

string Shape::toString() const
{
	ostringstream oss;
    oss << fixed << setprecision(2); // set 2 decimal places 
    oss << "Shape[ x = " << x << ", y = " << y << "]";
	return oss.str();
}

double Shape::area() const
{
	return 0.0;
}
