// File: class_template_with_default_param.cpp
// demonstrates class template with default type
#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
using namespace std;


// class template with default type 
template<class T = double> // the default type T is double
class Complex
{
public:
	Complex(T re = 0, T im = 0) : re(re), im(im) {};

	// Declare operator<<(ostream &, const Complex<T> &) as a friend
	// function template for class Complex<T>. It makes 
	// operator<<(ostream &, const Complex<int> &) a friend of Complex<int>
	// and
	// operator<<(ostream &, const Complex<double> &) a friend of Complex<double> etc.
	// etc. 
	template<class T>
	friend ostream& operator<<(ostream& os, const Complex<T>& c);

private:
	T re, im;
};

template <class T>
ostream& operator<<(ostream& os, const Complex<T>& c) {
    os << "(" << c.re << (c.im >= 0 ? "+" : "") << c.im << "i)";
    return os;
}

int main()
{
	int a = 1, b = 2;
	double x = 3.1, y = 4.2;

	Complex<int> complex1(a, b);
	Complex<int> complex2(x, y);
	Complex<double> complex3(a, b);
	Complex<double> complex4(x, y);
	Complex<> complex5(a, b);	
	Complex<> complex6(x, y);
	Complex<> complex7;

	cout << "complex1 = " << complex1 << " \ttype: " << typeid(complex1).name() << endl;
	cout << "complex2 = " << complex2 << " \ttype: " << typeid(complex2).name() << endl;
	cout << "complex3 = " << complex3 << " \ttype: " << typeid(complex3).name() << endl;
	cout << "complex4 = " << complex4 << " \ttype: " << typeid(complex4).name() << endl;
	cout << "complex5 = " << complex5 << " \ttype: " << typeid(complex5).name() << endl;
	cout << "complex6 = " << complex6 << " \ttype: " << typeid(complex6).name() << endl;
	cout << "complex7 = " << complex7 << " \ttype: " << typeid(complex7).name() << endl;
	
}

