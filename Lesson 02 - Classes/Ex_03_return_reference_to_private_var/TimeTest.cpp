// File: TestTime.cpp
// test the Time class

#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    Time t1; // create a Time object using the default constructor
    Time t2(14, 30, 72); // create a Time object 
                        // using the constructor with parameters
                        // with incorrect values

    cout << "\nThe time of t1 is: "; 
    t1.print();

    cout << "\nThe time of t2 is: ";
    t2.print();

    // set new values for t2
    t2.setHour(14);
    t2.setMinute(72);   // incorrect value
    t2.setSecond(30);

    cout << "\nAfter setting the time of t2 to 14:72:30" << endl;
    cout << "The time of t2 is: ";
    t2.print();

    cout << "\nThe hour of t2 is: " << t2.getHour() << endl;
    cout << "The minute of t2 is: " << t2.getMinute() << endl;
    cout << "The second of t2 is: " << t2.getSecond() << endl;

    return 0;
}

// end of file TestTime.cpp