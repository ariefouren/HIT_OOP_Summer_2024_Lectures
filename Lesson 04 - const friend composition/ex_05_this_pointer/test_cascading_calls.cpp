// File: test_cascading_calls.cpp
// Testing cascading calls with the this pointer

#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    cout << "Creating p1(0, 0)" << endl;
    Point p1(0, 0);
    cout << "p1 = ";
    p1.print();
    cout << endl << endl;

    cout << "After p1.setX(5).setY(10) :" << endl;
    p1.setX(5).setY(10); // cascading calls
    cout << "p1 = ";
    p1.print();
    cout << endl << endl;
}