
// File: RectangleTest.cpp
// Testing class Rectangle
//   
#include <iostream>
#include "Point.h"		
#include "Rectangle.h"
using namespace std;

int main()
{
    cout << "Creating p1(0, 0) and p2(10, 5)" << endl;
	Point p1(0, 0);
	Point p2(10, 5);
    cout << endl << endl;

    cout << "Creating rec1(p1, p2)" << endl;
	Rectangle rec1(p1, p2);
    cout << "Created: rec1 = ";
    rec1.print();
    cout << endl << endl;

    cout << "Creating rec2" << endl;
    Rectangle rec2; // use default constructor
    cout << "Created: rec2 = ";
    rec2.print();
    cout << endl << endl;
}


