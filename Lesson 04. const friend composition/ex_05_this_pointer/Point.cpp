//
// Point.cpp
// implementation of class Point   
//

#include <iostream>
#include <cmath>    // for sqrt(), pow()
#include "Point.h"		
using namespace std;

// initialization of static member variable
int Point::count = 0;

// default constructor
Point::Point(): x(0), y(0), id(++count) { }

// constructor with parameters
Point::Point(double x, double y): x(x), y(y), id(++count) { }

// destructor
Point::~Point() { }

// print the point
void Point::print() const
{
	cout << "Point[id = " << id << ", " <<
        "x = " << x << ", " << 
        "y = " << y << "]";
}

// get x
double Point::getX() const
{
    return x;
}

// get y
double Point::getY() const
{
    return y;
}

// set x
// this function returns a reference to the object
// to allow cascading calls
Point& Point::setX(double x)
{
    this->x = x;    // this pointer is used to resolve the ambiguity 
                    // between the member variable x and the parameter x
    return *this; // return the reference to the object to allow cascading calls
}

// set y
// this function returns a reference to the object
// to allow cascading calls
Point& Point::setY(double y)
{
    this->y = y;    // this pointer is used to resolve the ambiguity 
                    // between the member variable y and the parameter y
    return *this; // return the reference to the object to allow cascading calls
}