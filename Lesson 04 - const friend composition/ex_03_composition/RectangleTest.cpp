
// RectangleTest.cpp
// Testing class Rectangle
//   
#include <iostream>
#include "Point.h"		
#include "Rectangle.h"
using namespace std;

int main()
{
	Point p1(0, 0);
	Point p2(10, 5);
	Rectangle rec1(p1, p2);
    cout << "Created: rec1 = " << endl;

    Rectangle rec2; // use default constructor
    cout << "Created: rec2 = " << endl;
}


