//
// Point.cpp
// implementation of class Point   
// demonstrates static class member variables and functions
//

#include <iostream>
#include "Point.h"		
using namespace std;

int Point::numPointsCreated = 0;	// definition and initialization of a static member variable
// instructs the compiler to allocate storage for the static member variable
// and initialize it to 0

Point::Point(double x, double y):
	x(x), y(y), pointId(++numPointsCreated)
    // static member variable numPointsCreated is used to assign a unique ID to each Point object
{
	cout << "constructor for ";
	print();
	cout << endl;
}

Point::~Point()
{
	cout << "destructor for ";
	print();
	cout << endl;
}

void Point::setXY(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Point::print() const
{
	cout << "point id = " << pointId << " (" << x << ", " << y << ")";
}

// static member function that returns the number of Point objects created
// can be called without creating an object of the class
// note that in the definition of a static member function, 
// the static keyword is not repeated
int Point::getNumPointsCreated()
{
	return numPointsCreated;
}
