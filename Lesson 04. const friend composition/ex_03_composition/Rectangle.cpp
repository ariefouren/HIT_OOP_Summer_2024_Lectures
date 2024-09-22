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
	p1(p1.getX(), p1.getY()), 
    p2(p2.getX(), p2.getY()),		
        // p1 and p2 are initialized using constructor with parameters
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
    cout << "Rectangle [id = " << id << ", p1 = ";
    p1.print();
    cout << ", ";
    cout << "p2 = ";
    p2.print();
    cout << "]";
}

// destructor
Rectangle::~Rectangle()
{
	cout << "destructor for ";
    print();
    cout << endl << endl;
}