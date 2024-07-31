#pragma once	// ensures that the .h file is included only once 
				// during compilation
//
// File: Point.h
// definition of class Point
//

class Point
{
public:
    // public member functions are accessible from outside the class
    Point(); // default constructor
    Point(double xVal, double yVal); // constructor with parameters

    void setX(double xVal); // set the value of x
    void setY(double yVal); // set the value of y
    double getX(); // get the value of x
    double getY(); // get the value of y

	void print(); // print the point
	void moveBy(double dx, double dy); // move the point by dx and dy 

private:
	double x;
	double y;
};

// end of Point.h

