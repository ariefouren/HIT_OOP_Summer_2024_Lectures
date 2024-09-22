// File: ex_03_references.cpp
// demonstrates references in C++
// - defining a reference
// - accessing a variable using a reference
// - reference to array

#include <iostream>
using namespace std;

int main() {
	int a = 1;      // a is an integer variable
	int &refA = a;  // refA is a reference to a

    cout << "initially :   a = " << a << " refA = " << refA << endl;
    a++; // increment a
    cout << "after a++:    a = " << a << " refA = " << refA << endl;
    refA++; // increment refA
    cout << "after refA++: a = " << a << " refA = " << refA << endl;

    // incorrect usage of references:
    // int &ref; // error: 'ref' declared as reference but not initialized
	int n = 10;
    int& refN = n;
    int m = 20;
    // int& refN = m; // error: redeclaration of 'int& refN'
	
	// reference to an array:
	int arr[4] = { 1,2,3,4 };   // an array of 4 integers
	int(&arrRef)[4] = arr;      // a reference to an array of 4 integers
    cout << endl << endl; 
    cout << "initially : " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "arr[ " << i << " ] = " << arr[i] << 
			"    arrRef[ " << i << " ] = " << arrRef[i] << endl;
	}
	
    cout << endl << endl; 
	arrRef[0] = 100;
	cout << "after arrRef[0] = 100 : " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "arr[ " << i << " ] = " << arr[i] <<
			"    arrRef[ " << i << " ] = " << arrRef[i] << endl;
	}
}
