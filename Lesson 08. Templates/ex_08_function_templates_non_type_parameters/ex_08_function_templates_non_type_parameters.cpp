#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
using namespace std;

#define BASE_2 2
#define BASE_10 10

// template of a function that calculates the logarithm of a number
// with a non-type parameter for the base with default value 10
// floating-point template parameters are not allowed
template<class N, int BASE = BASE_10> 
N Log(N x)
{
	return (N) (log(x) / log((N)BASE)); // log(x) is the natural logarithm
}

int main()
{
	const int CONST_BASE2 = 2;
	const int CONST_BASE10 = 10;

	int base2 = 2;
	int base10 = 10;

	int a = 100;
	double x = 100.0;

	cout << "--- 1. Implicit deduction of the parameter type and the base ---" << endl;
	cout << "Log(a) = " << Log(a) << endl;
	// the following line is error, because the base is not specified
	// cout << "Log<10>(a) = " << Log<10>(a) << endl;

	cout << endl;
	cout << "--- 2. Explicit definition of the parameter type and the base ---" << endl;
	cout << "Log<int>(a) = " << Log<int>(a) << endl;
	cout << "Log<int, 10>(a) = " << Log<int, 10>(a) << endl;
	cout << "Log<int, BASE_10>(a) = " << Log<int, BASE_10>(a) << endl;
	// CONST_BASE10 is a constant, so it can be used as a template parameter 
	cout << "Log<int, CONST_BASE10>(a) = " << Log<int, CONST_BASE10>(a) << endl;

	// the following line is error, because base10 is a variable, 
	// not a constant expression
	// cout << "Log<int, base10>(a) = " << Log<int, base10>(a) << endl;
	
cout << endl << endl;	
cout << "Log<int, 2>(x) = " << Log<int, 2>(x) << endl;
cout << "Log<double, 2>(x) = " << Log<double, 2>(x) << endl;
cout << "Log<double>(x) = " << Log<double>(x) << endl;
cout << "Log(x) = " << Log(x) << endl;
// the following line is error, the function requires only one parameter
// cout << "Log(x, BASE_2) = " << Log(x, BASE_2) << endl;


}

