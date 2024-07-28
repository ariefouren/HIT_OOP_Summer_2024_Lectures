// File: ex_06_structures.cpp
// demonstrates structures in C++: 
// - defining a structure
// - accessing structure members using operators . and -> 
// - defining an array of structures

#define _USE_MATH_DEFINES 
#include <iostream>
#include <iomanip>		// for setw(), used to format output

#define WIDTH 10		// the width of output for setw(WIDTH) 
using namespace std;	// to avoid writing std::cout, std::cin, std::endl

// define a structure Point
struct Point
{
	double x;	// x-coordinate of the point
	double y;	// y-coordinate of the point
};

int main()
{
	Point p1; // create a point p1 
	p1.x = 1.0; // set the x-coordinate of p1
	p1.y = 2.0; // set the y-coordinate of p1

	Point* ptr1 = &p1; // create a pointer to p1
	ptr1->x = 3.0; // set the x-coordinate of p1 using the pointer
	ptr1->y = 4.0; // set the y-coordinate of p1 using the pointer

	Point &ref1 = p1; // create a reference to p1
	ref1.x = 5.0; // set the x-coordinate of p1 using the reference
	ref1.y = 6.0; // set the y-coordinate of p1 using the reference
	
	Point p2 = { 5.0, 6.0 }; 	// create a point p2 and initialize it 
								// using an initializer list

	Point array[3]; // create an array of 3 points
	array[0] = p1;	// assign p1 to the first element of the array
	array[1] = p2;	// assign p2 to the second element of the array
	array[2] = { 7.0, 8.0 }; // assign a new point to the third element of the array
}
