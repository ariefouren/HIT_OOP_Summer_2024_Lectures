// File: ex_08_function_templates_non_type_parameters.cpp
// demonstrate the use of function templates with non-type parameters

#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
using namespace std;

template<class N, class D, class Q = N>
Q quotient(N numerator, D denominator)
{
	return (Q)numerator / denominator;
}

double quotient(double numerator, double denominator)
{
	cout << "double quotient(double, double) is called ... ";
	return numerator / denominator;
}

int main()
{
	int a = 4, b = 3;
	double x = 4.1, y = 3.2;
	
	cout << "quotient<double, double>(x, y) = " 
		<< quotient<double, double>(x, b) << endl;
	// if template specialization and a function 
	// equally match, the function is preferred
	cout << "quotient(x, y) = " << quotient(x, y) << endl;
	cout << "quotient(a, y) = " << quotient(a, y) << endl;
	cout << "quotient(a, (double)b) = " << quotient(a, (double)b) << endl;
	cout << "quotient((double)a, (double)b) = " << quotient((double)a, (double)b) << endl;
}

