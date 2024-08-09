// File: Time.cpp
// implementation of the Time class

#include <iostream>
#include "Time.h"
using namespace std;

#define MAX_HOURS 24
#define MAX_MINUTES 60
#define MAX_SECONDS 60

#define DEFAULT_HOUR 0
#define DEFAULT_MINUTE 0
#define DEFAULT_SECOND 0

// default constructor
Time::Time()
{
    setHour(DEFAULT_HOUR);      // set the hour to default value
    setMinute(DEFAULT_MINUTE);  // set the minute to default value
    setSecond(DEFAULT_SECOND);  // set the second to default value
}

// constructor with parameters
// if one of the parameters is invalid, the corresponding value is set to 0
Time::Time(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

// public function that returns a not-const reference 
// to the private member hour
// DANGEROUS ! Breaks encapsulation !
// allows an access and modification of the private member hour
// should be avoided !
int &Time::badSetHour(int h)      
{
    setHour(h);
    return hour; // return a not-const reference to the private member hour
}

// set the hour
void Time::setHour(int h)
{
    if (0 <= h && h < MAX_HOURS)  
        hour = h; 
    else 
        hour = DEFAULT_HOUR;   // set the hour to default value if the value is invalid
}

// set the minute
void Time::setMinute(int m)
{
    if (0 <= m && m < MAX_MINUTES) 
        minute = m; 
    else 
        minute = DEFAULT_MINUTE;  // set the minute to default value if the value is invalid
}

// set the second
void Time::setSecond(int s)
{
    if (0 <= s && s < MAX_SECONDS) 
        second = s; 
    else 
        second = DEFAULT_SECOND;  // set the second to default value if the value is invalid
}

// get the hour
int Time::getHour() const
{
    return hour;
}

// get the minute
int Time::getMinute() const
{
    return minute;
}

// get the second
int Time::getSecond() const
{
    return second;
}

// print the time in the format hh:mm:ss
void Time::print() const
{
    cout << (hour < 10 ? "0" : "") << hour << ":"
         << (minute < 10 ? "0" : "") << minute << ":"
         << (second < 10 ? "0" : "") << second << endl;
}

// end of Time.cpp