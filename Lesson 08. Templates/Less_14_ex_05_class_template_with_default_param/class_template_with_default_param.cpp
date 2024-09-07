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
};


int main()
{
	int a = 1, b = 2;
	Complex<int> intComplex;
	Complex<> doubleComplex;
	Complex<> complex(a, b);
}

