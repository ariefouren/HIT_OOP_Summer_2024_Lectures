//
// File: ex_09_function_overloading.cpp
// demonstrates function overloading
// function overloading is the ability to define multiple functions 
// with the same name but with different signatures
#include <iostream>
using namespace std;

int add(int n, int m);
float add(float x, float y);
float add(int n, float x);
float add(float x, int n);

int main()
{
	int n = 10, m = 12;
	float x = 5.5, y = 3.8;
	cout << add(n, m) << "\n"; // calls int add(int n, int m)
	cout << add(x, y) << "\n"; // calls float add(float x, float y)
	cout << add(n, x) << "\n"; // calls float add(int n, float x)
	cout << add(x, n) << "\n"; // calls float add(float x, int n)
}

int add(int n, int m) {
	cout << "int + int addition gives     : " <<
		n << " + " << m << " = ";
	return n + m;
}

float add(float x, float y) {
	cout << "float + float addition gives : " <<
		x << " + " << y << " = ";
	return x + y;
}
float add(int n, float x) {
	cout << "int + float addition gives   : " <<
		n << " + " << x << " = ";
	return n + x;
}

float add(float x, int n) {
	cout << "float + int addition gives   : " <<
		x << " + " << n
		<< " = ";
	return x + n;
}
