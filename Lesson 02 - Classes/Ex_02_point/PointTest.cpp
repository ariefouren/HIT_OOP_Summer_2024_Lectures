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
    // ---------------------------------------------------------
    // creating objects of class Point using default constructor
    // ---------------------------------------------------------
    cout << "Creating objects using default constructor:\n";
    // Way 1: Default constructor using default initialization (C++98/03)
    Point p1; // Object p1 is created using the default constructor
    // This syntax calls the default constructor of the class Point.

    // Way 2: Default constructor using parentheses (C++98/03)
    Point p2(); // This is NOT an object, but a function declaration! (most vexing parse)
    // This line declares a function named p2 that returns a Point object and takes no parameters.
    // Avoid this syntax for object creation as it leads to the most vexing parse problem.

    // Way 3: Default constructor using braces (C++11)
    Point p3{}; // Object p3 is created using the default constructor (uniform initialization)
    // This syntax uses brace initialization to call the default constructor.

    // Way 4: Default constructor using new keyword (dynamic allocation)
    Point* p4 = new Point(); // Object p4 is created using the default constructor (dynamic allocation)
    // This creates an object of Point on the heap and p4 is a pointer to it.

    // Way 5: Default constructor using parentheses in dynamic allocation
    Point* p5 = new Point; // Object p5 is created using the default constructor (dynamic allocation)
    // This is equivalent to the above dynamic allocation method.

    // print the points created using the default constructor
    cout << "Point p1: ";
    p1.print();
    cout << endl;
    
    cout << "Point p3: ";
    p3.print();
    cout << endl;

    // print the points created using dynamic allocation
    cout << "Point p4: ";
    p4->print();
    cout << endl;

    cout << "Point p5: ";
    p5->print();
    cout << endl;

    // Cleaning up dynamic allocations
    delete p4; // Free the dynamically allocated memory for p4
    delete p5; // Free the dynamically allocated memory for p5

    // ---------------------------------------------------------------
    // creating objects of class Point using parameterized constructor
    // ---------------------------------------------------------------
    cout << "\n\nCreating objects using parameterized constructor:\n";
    // Way 1: Parameterized constructor using parentheses (C++98/03)
    Point p6(1.0, 2.0); // Object p6 is created using the parameterized constructor
    // This syntax calls the parameterized constructor of the class Point.

    // Way 2: Parameterized constructor using braces (C++11)
    Point p7{3.0, 4.0}; // Object p7 is created using the parameterized constructor (uniform initialization)
    // This syntax uses brace initialization to call the parameterized constructor.

    // Way 3: Parameterized constructor using braces (C++11)
    Point p8 = {5.0, 6.0}; // Object p8 is created using the parameterized constructor (uniform initialization)
    // This syntax uses brace initialization to call the parameterized constructor.

    // Way 4: Parameterized constructor using new keyword (dynamic allocation)
    Point* p9 = new Point(7.0, 8.0); // Object p9 is created using the parameterized constructor (dynamic allocation)
    // This creates an object of Point on the heap and p9 is a pointer to it.

    // Way 5: Parameterized constructor using parentheses in dynamic allocation
    Point* p10 = new Point{9.0, 10.0}; // Object p10 is created using the parameterized constructor (dynamic allocation)
    // This is equivalent to the above dynamic allocation method.

    // print the points created using the parameterized constructor
    cout << "Point p6: ";
    p6.print();
    cout << endl;

    cout << "Point p7: ";
    p7.print();
    cout << endl;

    cout << "Point p8: ";
    p8.print();
    cout << endl;

    // print the points created using dynamic allocation
    cout << "Point p9: ";
    p9->print();
    cout << endl;

    cout << "Point p10: ";
    p10->print();
    cout << endl;

    // Cleaning up dynamic allocations
    delete p9; // Free the dynamically allocated memory for p9
    delete p10; // Free the dynamically allocated memory for p10

}
// end of PointTest.cpp