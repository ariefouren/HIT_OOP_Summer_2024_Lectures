#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
using namespace std;

// class template with default type 
template<class T_RE = double, class T_IM = T_RE>
class Complex
{
public:
	Complex(T_RE re = T_RE(), T_IM im = T_IM()) : re(re), im(im) {};
private:
	T_RE re;
	T_IM im;
};

// void print(Complex<T_RE, T_IM> x); 		// line 1
//ERROR: T_RE and T_IM are not defined

void print(Complex<double, double> x);		// line 2

void print(Complex<double> x);				// line 3

void print(Complex<> x); 					// line 4

template<class T_RE, class T_IM>
void print(Complex<T_RE, T_IM> x);			// line 5

template<class T>
void print(Complex<T> x);					// line 6

template<>
void print(Complex<> x);					// line 7

// template<>
// void print(Complex<T> x); 					// line 8
// ERROR: T is not defined


int main()
{


}

