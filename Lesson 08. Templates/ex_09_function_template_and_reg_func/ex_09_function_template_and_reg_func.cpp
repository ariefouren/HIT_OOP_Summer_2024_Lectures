// File: ex_08_function_templates_non_type_parameters.cpp
// demonstrate the use of function templates with non-type parameters

#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
using namespace std;

template<class N, class D, class Q = N>
Q quotient(N numerator, D denominator)
{
	cout << "template<class N, class D, class Q = N> is called ... ";
	cout << " with N: " << typeid(N).name() << ", D: " << typeid(D).name() << ", Q: " << typeid(Q).name() << endl;	
	return (Q) (numerator / denominator) ;
}

double quotient(double numerator, double denominator)
{
	cout << "double quotient(double, double) is called ... " << endl;
	return numerator / denominator;
}

int main()
{
	int a = 4, b = 3;
	double x = 4.1, y = 3.2;
	
	double result;
	cout << "1. quotient<double, double>(x, y): "<< endl;
	cout << quotient<double, double>(x, b) << endl << endl;

	// if template specialization and a function 
	// equally match, the function is preferred
	cout << "2. quotient(x, y): " << endl;
	cout << quotient(x, y) << endl << endl;

	cout << "3. quotient(a, y) : " << endl;
	cout << quotient(a, y) << endl << endl;

	cout << "4. quotient(a, (double)b) : " << endl;
	cout  << quotient(a, (double)b) << endl << endl;

	cout << "5. quotient((double)a, (double)b) : " << endl;
	cout << quotient((double)a, (double)b) << endl;
}

