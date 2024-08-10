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

// implementation of the friend function distance
// note that in the implementation we do not use the keyword friend
double distance(const Point& p1, const Point& p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

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

