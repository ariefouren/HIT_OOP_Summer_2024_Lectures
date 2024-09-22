//
// File: Point.h
// definition of class Point
//
#pragma once

class Point
{
public:
	Point();                    // default constructor
    Point(double x, double y);  // constructor with parameters
	~Point();                   // destructor
	void print() const;         // print the point
    double getX() const;        // get x
    double getY() const;        // get y

private:
	double x;
	double y;
    int id;                     // member variable
    static int count;           // static member variable 
                                // indicates the number of points created
};

