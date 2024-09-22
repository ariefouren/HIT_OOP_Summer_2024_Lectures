// File: ex_04_parameters.cpp
// demonstrates passing parameters by value, by reference, and by pointers
#include <iostream>
using namespace std;

// function prototypes
void swapByValue(int a, int b);     // pass by value
void swapByReference(int& aRef, int& bRef); // pass by reference
void swapByPointers(int* aPtr, int* bPtr); // pass by pointers

int main() 
{
	int a = 1; 
	int b = 2;

    cout << "Before swapping:             a = " << a << ", b = " << b << endl;
    swapByValue(a, b);  // according to the function definition, a and b are passed by value
    cout << "After swapping by value:     a = " << a << ", b = " << b << endl << endl;

    cout << "Before swapping:             a = " << a << ", b = " << b << endl;
    swapByReference(a, b);  // according to the function definition, a and b are passed by reference
    cout << "After swapping by reference: a = " << a << ", b = " << b << endl<< endl;

    cout << "Before swapping:             a = " << a << ", b = " << b << endl;
    swapByPointers(&a, &b); // the addresses of a and b (pointers) are passed to the function
    cout << "After swapping by pointers:  a = " << a << ", b = " << b << endl << endl;

}

// function definitions
// passing parameters by value
void swapByValue(int a, int b) 
{
	int tmp = a;
	a = b;
	b = tmp;
}

// passing parameters by reference
void swapByReference(int& aRef, int& bRef) 
{
	int tmp = aRef;
	aRef = bRef;
	bRef = tmp;
}

// passing parameters by pointers
void swapByPointers(int* aPtr, int* bPtr) 
{
	int tmp = *aPtr;
	*aPtr = *bPtr;
	*bPtr = tmp;
} 
