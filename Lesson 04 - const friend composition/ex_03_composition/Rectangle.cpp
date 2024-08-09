//
// File: Rectangle.cpp
// implementation of class Rectangle
// demonstrates composition and the order of constructor/destructor calls

#include <iostream>
#include "Point.h"
#include "Rectangle.h"		
using namespace std;

// initialization of static member variable
int Rectangle::count = 0;

// default constructor
Rectangle::Rectangle(): id(++count) 
	// default constructor for p1 and p2 is called
    // before the body of the constructor
{
    cout << "default constructor for ";
    print();
    cout << endl;
}

// constructor with parameters
Rectangle::Rectangle(const Point& p1, const Point& p2) :
	p1(p1), p2(p2),		// p1 and p2 are initialized using default copy constructor
                        // of class Point
    id(++count)
{
	cout << "constructor with parameters for ";
    print();
    cout << endl;
}

// print the rectangle
void Rectangle::print() const
{
    cout << "Rectangle (";
    p1.print();
    cout << ", ";
    p2.print();
    cout << ")";
    cout << " id =" << id;
}

// destructor
Rectangle::~Rectangle()
{
	cout << "destructor for ";
    print();
    cout << endl;
}