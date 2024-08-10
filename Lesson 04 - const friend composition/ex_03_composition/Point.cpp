//
// Point.cpp
// implementation of class Point   
//

#include <iostream>
#include "Point.h"		
using namespace std;

// initialization of static member variable
int Point::count = 0;

// default constructor
Point::Point(): 
    x(0), y(0), id(++count)
{
    cout << "default constructor for ";
    print();
    cout << endl;
}

// constructor with parameters
Point::Point(double x, double y):
	x(x), y(y), id(++count)
{
	cout << "constructor with parameters for "; 
	print();
	cout << endl;
}

// destructor
Point::~Point()
{
	cout << "destructor for point "; 
	print();
	cout << endl;
}

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

