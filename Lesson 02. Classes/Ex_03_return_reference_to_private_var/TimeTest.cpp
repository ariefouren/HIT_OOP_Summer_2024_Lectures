// File: TestTime.cpp
// test the Time class

#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    Time lessonStart(16, 00, 00);
    cout <<"Initially:" << endl;
    lessonStart.print();

    int &hourRef = lessonStart.badSetHour(15); // get a reference to the private member hour
    hourRef = 35; // modify the private member hour through the reference
    cout << "After hourRef = 35:" << endl;
    lessonStart.print(); // print the time

    // the function returns a not-const reference to the private member hour
    // therefore, it can be used as lvalue in an assignment
    lessonStart.badSetHour(25) = 70; 
    cout <<"After lessonStart.badSetHour(25) = 70 :" << endl;
    lessonStart.print(); // print the time

    return 0;
}

// end of file TestTime.cpp