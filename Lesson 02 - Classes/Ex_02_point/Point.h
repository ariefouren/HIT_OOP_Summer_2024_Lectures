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
    Point() : x(0), y(0) {} // default constructor
                            // private data members x and y are initialized to 0.0
                            // using an initialization list
                            // this simple constructor is implemented in the header file
                            // (not in a separate .cpp file)

    Point(double xVal, double yVal) : x(xVal), y(yVal) {} 
                            // constructor with parameters
                            // private data members x and y are initialized
                            // to xVal and yVal using an initialization list
                            // this simple constructor is implemented in the header file
                            // (not in a separate .cpp file)

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

