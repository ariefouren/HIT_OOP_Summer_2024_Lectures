// File: ex_05_function_templates_largest.cpp
// demonstrates function templates
#include <iostream>
using namespace std;

// function template to return the largest of two values
template<class T>
T largest(T x, T y)
{
	return x > y ? x : y;
}

int main()
{
	int a = 4, b = 3;
	double x = 4.1, y = 3.2;

	cout << "largest(" << a <<", " << b<< ") = " 
		<< largest(a, b) << endl; // int largest<int>(int, int)

	cout << "largest<int>(" << a << ", " << b << ") = "	
		<< largest<int>(a, b) << endl; // int largest<int>(int, int)

	cout << "largest<double>(" << a << ", " << b << ") = "
		<< largest<double>(a, b) << endl << endl; // double largest<double>(double, double)

	cout << "largest(" << x <<", " << y << ") = "
		<< largest(x, y) << endl; // double largest<double>(double, double)

	cout << "largest<double>(" << x << ", " << y << ") = "
		<< largest<double>(x, y) << endl; // double largest<double>(double, double)

	cout << "largest<int>(" << x << ", " << y << ") = "
		<< largest<int>(x, y) << endl << endl; // double largest<int>(double, double)

	/*
	cout << "largest(" << x << ", " << b << ") = "
		<< largest(x, b) << endl; // error: no instance of template matches the argument list
	*/ 
	largest<int>(x, b);
	string s1 = "abc", s2 = "def";
	cout << "largest(" << s1 << ", " << s2 << ") = "
		<< largest(s1, s2) << endl; // string largest<string>(string, string)

	cout << "largest<string>(" << s1 << ", " << s2 << ") = "
		<< largest<string>(s1, s2) << endl; // string largest<string>(string, string)

}