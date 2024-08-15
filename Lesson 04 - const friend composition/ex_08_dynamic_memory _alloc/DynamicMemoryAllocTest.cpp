//
// File: Test.cpp
// Testing dynamic memory allocation
//   
#include <iostream>
#include "Point.h"		
using namespace std;

int main()
{
	Point* p1 = new Point(0, 0);    // constructor with parameters
	Point* p2 = new Point(*p1);     // default copy constructor
	Point* p3 = p1; // pointer assignment
                    // no new object is created, p3 points to the same object as p1


	cout << "point (*p1): ";
	p1->print();
	cout << "point (*p2): ";
	p2->print();
	cout << "point (*p3): ";
	p3->print();

	(*p3).setXY(10, 20);
	cout << "\n\nafter (*p3).setXY(10, 20) :\n";

	cout << "point (*p1): ";
	p1->print();
	
	cout << "point (*p2): ";
	p2->print();
	
	cout << "point (*p3): ";
	p3->print();
    cout << endl;

	delete p1;
	delete p2;
	// delete p3; // ERROR !
    // an attempt to delete the same object twice causes a runtime error 

}
