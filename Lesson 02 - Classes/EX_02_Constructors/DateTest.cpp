//
// DateTest.cpp
// testing class Date
//
#include <iostream>
#include <iomanip>		// for setw()

#include "Date.h"	

using namespace std;


int main()
{
	Date date1(9, 7, 2023);
	Date date2;		// use constructor with default values 01/01/2023
	Date date3(16, 7); // use constructor with default value for year (2023)
	Date date4(12, 31, 2023);  // incorrect date

	Date date5 = Date(7, 7, 2001);  // create a new object and copy it to date5
	Date date6 = Date();	//  create a new object using 
							// the default constructor and copy it to date6
	Date* date7ptr = new Date(5,5,2002); // create a Date object using dynamic allocation
								// and 

	 
	Date date8();  // no object is created; interpreted as a function definition
	/*
	date8.print(); // Error: object date8 doesn't exist
	*/ 


	cout << "date1 : ";
	date1.print();

	cout << "date2 : ";
	date2.print();

	cout << "date3 : ";
	date3.print();

	cout << "date4 : ";
	date4.print();

	cout << "date5 : ";
	date5.print();

	cout << "date6 : ";
	date6.print();

	cout << "date7ptr : ";
	(*date7ptr).print();
}
