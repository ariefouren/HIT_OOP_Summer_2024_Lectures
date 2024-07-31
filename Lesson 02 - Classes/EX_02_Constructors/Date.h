#pragma once	
//
// File: Date.h
// definition of class Date
//
#define DEFAULT_DAY 1
#define DEFAULT_MONTH 1
#define DEFAULT_YEAR 2024

// class Date definition
class Date
{
public:
	// constructors
	Date(int d, int m, int y = DEFAULT_YEAR);	// constructor with default value
	Date();										// default constructor

	void print();

private:
	int day;
	int month;
	int year;
};
// End of Date.h



