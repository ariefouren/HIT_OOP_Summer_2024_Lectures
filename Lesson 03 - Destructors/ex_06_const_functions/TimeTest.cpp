// File: TestTime.cpp
// test the Time class

#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    Time lessonStart(16, 00, 00);

    // the function returns a not-const reference to a private member,
    // that can be used to access and modify the private member
    int &hourRef = lessonStart.badSetHour(18);
    hourRef = 25; // invalid hour is set using a reference to private member
    lessonStart.print(); // prints 25:00:00

    // since the function returns a not-const reference to a private member, 
    // it can be used as an lvalue in an assignment
    lessonStart.badSetHour(18) = 30; // invalid hour is set using a reference to private member 
    lessonStart.print(); // prints 30:00:00

    return 0;
}

// end of file TestTime.cpp