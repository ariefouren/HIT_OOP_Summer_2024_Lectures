//
// File: ex_08_default_values.cpp
// demonstrates the use of default values in function arguments
// 
#include <iostream>
using namespace std;

// function prototype with default values
// default values should be specified only once, in the first declaration
// default values are not a part of the function signature
// note that x1 does not have a default value
void f(int x1, int x2 = 0, int x3 = 0); 

int main()
{
	// cout << "f() gives           : ";
	// f(); // error: too few arguments to function 'void f(int, int, int)'

	cout << "f(10) gives         : ";
	f(10);

	cout << "f(10, 20) gives     : ";
	f(10, 20);

	cout << "f(10, 20, 30) gives : ";
	f(10, 20, 30);


}

// default values should be specified only once, in the first declaration
// default values are not a part of the function signature
void f(int x1, int x2, int x3)
{
	cout << "x1 = " << x1
		<< " x2 = " << x2
		<< " x3 = " << x3 << endl;
}
