// File: ex_07_passing_structures.cpp
// demonstrates passing structure to functions 
// - by value
// - by pointer
// - by reference

#define _USE_MATH_DEFINES 
#include <iostream>
#include <iomanip>      // for setw(), used to format output

#define WIDTH 4         // the width of output for setw(WIDTH) 
using namespace std;    // to avoid writing std::cout, std::cin, std::endl

// define a structure Point
struct Point
{
    double x;   // x-coordinate of the point
    double y;   // y-coordinate of the point
};

// function prototypes
// print the point p
// the function gets a constant reference to the point
void print(const Point &p); 

// move the point p by dx, dy
// the function gets a reference to the point, 
// so the changes will be reflected in the calling function
void moveBy(Point &p, double dx, double dy);

// create a new point that is the middle point of p1 and p2
// the new point is returned by value
Point middlePoint(const Point &p1, const Point &p2);    

int main()
{
    Point p1 = { 1, 2 };
    cout << "Before moving:          p1 = ";
    print(p1);

    moveBy(p1, 3, 4);
    cout << "After moving by (3, 4): p1 = ";
    print(p1);

    cout << endl;
    Point p2 = { 0, 0 };
    cout << "p1 = ";
    print(p1);
    cout << "p2 = ";
    print(p2);
    cout << "The middle point of p1 and p2 is: ";
    print(middlePoint(p1, p2));
}

// print the point p
void print(const Point &p)
{
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}

// move the point p by dx, dy
void moveBy(Point &p, double dx, double dy)
{   // point p is passed by reference, 
    // so the changes will be reflected in the calling function
    p.x += dx;
    p.y += dy;
}

// create a new point that is the middle point of p1 and p2
Point middlePoint(const Point &p1, const Point &p2)
{
    Point middle;   // create a new point
    middle.x = (p1.x + p2.x) / 2;
    middle.y = (p1.y + p2.y) / 2;
    return middle;  // return the new point

    // the above code can be written in a single line:
    // return { (p1.x + p2.x) / 2, (p1.y + p2.y) / 2 };
}
