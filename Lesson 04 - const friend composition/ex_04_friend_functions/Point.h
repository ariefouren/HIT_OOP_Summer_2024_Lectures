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

    // friend function declaration
    // friend is not a member of the class, but has access 
    // to its private and protected members
    friend double distance(const Point& p1, const Point& p2); 

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

