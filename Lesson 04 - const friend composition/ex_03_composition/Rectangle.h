//
// File: Rectangle.h
// definition of class Rectangle
// demonstrates composition and the order 
#pragma once
#include "Point.h"

class Rectangle
{
public:
    Rectangle();    // default constructor
	Rectangle(const Point& p1, const Point& p2); // constructor with parameters
	~Rectangle();

    void print() const; // print the rectangle

private:
	Point p1;
	Point p2;
    int id;        // rectangle id
    static int count; // number of rectangles created
};

