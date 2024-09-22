//
// File: Point.cpp
// implementation of class Point
//
#include <iostream>
#include <iomanip>		// for setw()

#include "Point.h"		// include the header file 
						// with the definition of the class Point
#define WIDTH 3		    // the width of output for setw(WIDTH) 
using namespace std;

// set the value of x
void Point::setX(double xVal)
{
    x = xVal;
}

// set the value of y
void Point::setY(double yVal)
{
    y = yVal;
}

// get the value of x
double Point::getX()
{
    return x;
}

// get the value of y
double Point::getY()
{
    return y;
}

// move the point by dx and dy
void Point::moveBy(double dx, double dy)
{
    x += dx;
    y += dy;
}

// print the point
void Point::print()
{
	cout	<< "(" << setw(WIDTH) << getX() << ", " 
			<< setw(WIDTH) << getY() <<")";	
}

// end of Point.cpp