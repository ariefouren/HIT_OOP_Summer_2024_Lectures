// File: friend_test.cpp
// Testing friend functions

#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    cout << "Creating p1(0, 0) and p2(10, 5)" << endl;
    Point p1(0, 0);
    Point p2(10, 5);
    cout << endl << endl;

    cout << "Distance between p1 and p2 is " << distance(p1, p2) << endl;
    cout << endl << endl;
}