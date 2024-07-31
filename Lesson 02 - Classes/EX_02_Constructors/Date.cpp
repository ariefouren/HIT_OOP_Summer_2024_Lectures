//
// Date.cpp
// implementation of class Date
//

#include <iostream>
#include <iomanip>		// for setw()

#include "Date.h"	

#define WIDTH 2	

using namespace std;

Date::Date(int d, int m, int y)	// constructor with default values
{
	day = d;
	month = m;
	year = y;
	
}

// default constructor
Date::Date()
{
	day = DEFAULT_DAY;
	month = DEFAULT_MONTH;
	year = DEFAULT_YEAR;
}

// print the date in the format dd/mm/yyyy
void Date::print()
{
    cout << (day < 10 ? "0" : "") << day << "/";        // if day is less than 10, print a 0 before the day
    cout << (month < 10 ? "0" : "") << month << "/";    // if month is less than 10, print a 0 before the month
    cout << year << endl;
}