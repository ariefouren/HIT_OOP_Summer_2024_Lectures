// File: ex_05_const_by_reference.cpp
// demonstrates passing a constant by reference
#include <iostream>
using namespace std;

// function prototypes
void printAndInc(int& x);     // pass by reference
void printConst(const int& x); // pass a constant by reference

int main() 
{
    int x = 5;
    printAndInc(x);
    cout << "After incrementing: x = " << x << endl;

    // printAndInc(100);    // error: invalid initialization of non-const reference
                            // of type 'int&' from an rvalue of type 'int'
    printConst(100);        // OK
}

// function definitions
// passing a constant by reference
void printConst(const int& x) 
{
    cout << "The value of x is: " << x << endl;
    // x++; // error: increment of read-only reference 'x'
}

// passing by reference
void printAndInc(int& x) 
{
    cout << "The value of x is: " << x << endl;
    x++;
}
