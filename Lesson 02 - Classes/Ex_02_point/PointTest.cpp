//
// File: PointTest.cpp
// testing class Point
//

#include <iostream>
#include <iomanip>		// for setw()

#include "Point.h"	
using namespace std;

int main()
{
	Point p1;   // create an object of class Point
                // using the default constructor
                // x and y are initialized to 0.0
	
    Point p2(1.0, 2.0); // create an object of class Point
                        // using the constructor with parameters
                        // x is initialized to 1.0 and y to 2.0

    cout << "initially: \n";
    cout << "p1 = ";
    p1.print(); // print the point p1
    cout << "\np2 = ";
    p2.print(); // print the point p2

    p1.setX(3.0); // set the value of x of p1 to 3.0
    p1.setY(4.0); // set the value of y of p1 to 4.0
    cout << "\n\nafter p1.setX(3.0) and p1.setY(4.0) : " << endl;
    cout << "p1 = "; 
    p1.print(); // print the point p1

    p2.moveBy(1.0, 1.0); // move the point p2 by 1.0 in x and 1.0 in y
    cout << "\n\nafter p2.moveBy(1.0, 1.0): \n";
    cout << "p2 = ";
    p2.print(); // print the point p2
}

// end of PointTest.cpp