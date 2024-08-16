//
// File: DynamicMemoryAllocTest.cpp
// Testing dynamic memory allocation
//   
#include <iostream>
#include "Point.h"		
using namespace std;

int main()
{
	Point* p1 = new Point(0, 0);    // constructor with parameters
	Point* p2 = new Point(*p1);     // default copy constructor

	cout << "After creating p1 and p2: \n";
	cout << "point (*p1): ";
	p1->print();
	cout  << endl;
	cout << "point (*p2): ";
	p2->print();
	cout << endl;

	cout << "\n\ndeleting p1 and p2: \n";
	delete p1;
	delete p2;
	// delete p2; // ERROR !
    // an attempt to delete the same object twice causes a runtime error 

	cout <<"--------------------------------------------------\n";

	cout << "Creating an array of points: \n";
	const int numPoints = 5;
	Point* pointArr = new Point[numPoints];			// array of pointers
	// the points are created with the default constructor
	for (int i = 0; i < numPoints; i++)
	{
		pointArr[i].setXY(i, i);
	}

	cout << "\n\nAfter creating pointArr[]: \n";
	for (int i = 0; i < numPoints; i++)
	{
		cout << "pointArr[" << i << "]: ";
		pointArr[i].print();
		cout << endl;
	}
	
	cout << "\n\ndeleting pointArr[]: \n";
	delete[] pointArr; // note the use of delete[] to delete an array of objects


}
