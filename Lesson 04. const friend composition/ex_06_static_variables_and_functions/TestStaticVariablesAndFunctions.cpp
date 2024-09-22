//
// TestStaticVariablesAndFunctions.cpp
// demonstrates static class member variables and functions
//   

#include <iostream>
#include "Point.h"		
using namespace std;

int main()
{
	cout << "number of points created: " << 
        Point::getNumPointsCreated() << endl;
    // note the call to a static member function using the class name,
    // not an object name

    // cout << Point::numberOfPoints << endl; // error: numberOfPoints is private
    
    Point p1(1, 2);
    Point p2(3, 4);
    cout << "After creating p1 and p2\n";
    cout << "number of points created: " << 
        Point::getNumPointsCreated() << endl << endl;


	cout << "After creating array1[2]\n";
	Point array1[2];	// a default constructor Point()
						// is called for each element of array1[]	

	cout << "number of points created: " << Point::getNumPointsCreated() << endl;
	cout << "\nend of main()\n";
}
