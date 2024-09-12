// File: ex_07_function_templates_parameters
// demonstrate the use of function templates with parameters

#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
using namespace std;

template<class N, class D, class Q = N>
Q quotient(N numerator, D denominator)
{
	return (Q) (numerator / denominator);
}


int main()
{
	int a = 4, b = 3;
	double x = 4.1, y = 3.2;

	cout << "--- 1. explicit specialization of function template: ---\n";
	cout << "quotient<double, double, double>(" << x <<", " << y<< ") = " 
		<< quotient<double, double, double>(x, y) << endl; 
	cout << "quotient<double, double>(" << x <<", "<< y<<") = "
		<< quotient<double, double>(x, y) << endl;
	cout << "quotient<double, double, int>(" << x <<", " << y <<") = "
		<< quotient<double, double, int>(x, y) << endl;
	cout << "quotient<int, int, int>(" << x <<", " << y <<") = "
		<< quotient<int, int, int>(x, y) << endl;

	cout << "\n--- 2. implicit specialization of function template: ---\n";
	cout <<  "quotient(" << a <<", "<< y <<") = "
		<< quotient(a, y) << endl;
	cout << "quotient(" << x<< ", " << b <<") = "
		<< quotient(x, b) << endl;
	cout << "quotient(" << a<<", " << b<<") = "
		<< quotient(a, b) << endl;
	cout <<"quotient(" << x <<", "<< y <<") = "
		<< quotient(x, y) << endl;
}

