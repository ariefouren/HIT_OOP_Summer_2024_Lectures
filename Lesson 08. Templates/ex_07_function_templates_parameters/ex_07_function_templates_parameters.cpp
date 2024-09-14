// File: ex_07_function_templates_parameters
// demonstrate the use of function templates with parameters

#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
using namespace std;

template<class N, class D = N, class Q = N>
Q quotient(N numerator, D denominator)
{
	cout << "quotient<" << typeid(N).name() << ", " << typeid(D).name() << ", " << typeid(Q).name() << ">(" << numerator << ", " << denominator << ") = ";
	return (Q) (numerator / denominator);
}


int main()
{
	int a = 4, b = 3;
	double x = 4.1, y = 3.2;

	cout << "--- 1. explicit specialization of function template: ---\n";
	cout << "quotient<double, double, double>(" << x <<", " << y<< ") : "; 
	cout << quotient<double, double, double>(x, y) << endl; 

	cout << "quotient<double, double>(" << x <<", "<< y<<") : ";
	cout << quotient<double, double>(x, y) << endl;

	cout << "quotient<double, double, int>(" << x <<", " << y <<") : ";
	cout << quotient<double, double, int>(x, y) << endl;

	cout << "quotient<int, int, int>(" << x <<", " << y <<") : ";
	cout << quotient<int, int, int>(x, y) << endl;

	cout << "\n--- 2. implicit specialization of function template: ---\n";
	cout <<  "quotient(" << a <<", "<< y <<") : ";
	cout << quotient(a, y) << endl;

	cout << "quotient(" << x<< ", " << b <<") : ";
	cout << quotient(x, b) << endl;

	cout << "quotient(" << a<<", " << b<<") : ";
	cout << quotient(a, b) << endl;

	cout <<"quotient(" << x <<", "<< y <<") : ";
	cout << quotient(x, y) << endl;

	cout << "\n--- 3. implicit specialization of function template with default parameter: ---\n"; 
	cout << "quotient<int>(x, y) : ";
	cout << quotient<int>(x, y) << endl;
	
	cout << "quotient<>(a, y) : ";
	cout << quotient<>(a, y) << endl;
	// if not all the template parameters are specified, the type of the function argument
	// has a preference over the default template parameter
	
	
}

