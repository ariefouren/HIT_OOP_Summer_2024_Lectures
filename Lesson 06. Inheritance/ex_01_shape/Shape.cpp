//
// Shape.cpp
// implementation of class Shape
//

#include <iostream>
#include <cmath>
#include "Shape.h"

using namespace std;

Shape::Shape(double x, double y) : x(x), y(y)
{
	cout << "constructor for " << this->toString() << endl;
}

Shape::~Shape()
{
	cout << "destructor for " << this->toString() << endl;
}

string Shape::toString() const
{
	string str = "Shape [x = " + to_string(x) +
			" y = " + to_string(y) + "]";
	return str;
}

double Shape::area() const
{
	return 0;
}

double Shape::getX() const
{
	return x;
}

double Shape::getY() const
{
	return y;
}
