// File: Time.cpp
// implementation of the Time class

#include <iostream>
#include "Time.h"
using namespace std;

#define MAX_HOURS 24
#define MAX_MINUTES 60
#define MAX_SECONDS 60

// default constructor
Time::Time()
{
    hour = 0;
    minute = 0;
    second = 0;
}

// constructor with parameters
// if one of the parameters is invalid, the corresponding value is set to 0
Time::Time(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

// set the hour
void Time::setHour(int h)
{
    if (0 <= h && h < MAX_HOURS)  
        hour = h; 
    else 
        hour = 0;   // set the hour to 0 if the value is invalid
}

// set the minute
void Time::setMinute(int m)
{
    if (0 <= m && m < MAX_MINUTES) 
        minute = m; 
    else 
        minute = 0;  // set the minute to 0 if the value is invalid
}

// set the second
void Time::setSecond(int s)
{
    if (0 <= s && s < MAX_SECONDS) 
        second = s; 
    else 
        second = 0;  // set the second to 0 if the value is invalid
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
         << (second < 10 ? "0" : "") << second;
}

// end of Time.cpp