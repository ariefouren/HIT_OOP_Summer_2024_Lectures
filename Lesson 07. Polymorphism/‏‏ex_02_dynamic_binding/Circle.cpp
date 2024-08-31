//
// Circle.cpp
// implementation of class Circle 
//

#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>
#include <iostream>
#include <string>
#include <sstream> //for printing to string
#include <iomanip> //for std::setprecision, formatted printing

using namespace std;

Circle::Circle(double x, double y, double r):
	Shape(x, y), 
	r(r)
{
	#ifdef VERBOSE // print the message only if VERBOSE is defined
	cout << "constructor for " << this->toString() <<endl;
	#endif
}

Circle::~Circle()
{
	#ifdef VERBOSE // print the message only if VERBOSE is defined
	cout << "destructor for " << this->toString() << endl;
	#endif
}

string Circle::toString() const
{
	ostringstream oss;
    oss << fixed << setprecision(2); // set 2 decimal places 
    oss << "Circle[ x = " << x << ", y = " << y << ", r = " << r << "]";
	return oss.str();
}

double Circle::area() const
{
	return M_PI * pow(r, 2);
}

void Circle::setR(double r)
{
	this->r = r;
}

