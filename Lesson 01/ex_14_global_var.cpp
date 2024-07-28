//
// File: ex_14_global_var.cpp
// demonstrates the declaration and access to a global variable
// 
#include <iostream>
using namespace std;

double a = 10.5;	// global variable

int main() {

	double a = 1.2;		// local variable
	
	cout << "local  value:   a =" << a << endl;
	cout << "global value: ::a = " << ::a << endl; // :: is the scope resolution operator

}
