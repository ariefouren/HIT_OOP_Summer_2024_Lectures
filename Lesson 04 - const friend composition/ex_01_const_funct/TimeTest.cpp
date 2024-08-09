// File: TestTime.cpp
// test the Time class

#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    Time start(16, 00, 00); // create a non-const object
    const Time finish(17, 50, 00); // create a const object

    start.print(); // for non-const object the non-const print function is called
    cout << endl;
    finish.print(); // for const object the const print function is called

    return 0;
}

// end of file TestTime.cpp
