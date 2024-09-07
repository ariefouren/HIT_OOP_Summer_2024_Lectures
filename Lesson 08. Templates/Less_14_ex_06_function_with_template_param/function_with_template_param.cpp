#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
using namespace std;

// class template with default type 
template<class T = double>
class Complex
{
public:
	Complex(T re = 0, T im = 0) : re(re), im(im) {};
private:
	T re, im;

friend std::ostream& operator<<(std::ostream& os, const Complex<double>& x);

template<class T>
friend std::ostream& operator<<(std::ostream& os, const Complex<T>& x);
};

void print(Complex<T> x);

void print(Complex<double> x);

void print(Complex<> x);

template<class T>
void print(Complex<T> x);



int main()
{
	int a = 1, b = 2;
	Complex<int> intComplex;

}

