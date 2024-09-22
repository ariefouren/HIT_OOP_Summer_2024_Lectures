//
// File: ex_10_function_overloading.cpp
// demonstrates common errors in function overloading
// if compiler can't identify by the parameter's types 
// which overloaded function to call, it displays a compilation error
// 
#include <iostream>
using namespace std;

float add(int n, float x);
float add(float x, int n);

float add(float x, float y = 0);
float add(float x);

int main()
{
	int n = 10;
	float x = 5.5;
	add(n, x);	// OK
	add(x, n);	// OK
	
	/*
	add(n, n);	// Error ! The function call matches two overloaded functions
	add(x);		// Error ! The function call matches two overloaded functions
	*/
}

float add(int n, float x) {
	cout << "add(int,  float)     : " << n << " + " << x << " = " << n + x << endl;
	return n + x;
}

float add(float x, int n) {
	cout << "add(float, int)      : " << x << " + " << n << " = " << x + n << endl;
	return x + n;
}

float add(float x, float y)
{
	cout << "add(float, float)    : " << x << " + " << y << " = " << x + y << endl;
	return x + y;
}

float add(float x)
{
	cout << "add(float)    : " << x << " = " << x << endl;
	return x;
}
