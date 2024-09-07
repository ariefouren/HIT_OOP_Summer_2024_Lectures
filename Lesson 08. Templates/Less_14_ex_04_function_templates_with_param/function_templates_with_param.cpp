#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
using namespace std;


template<class N, int BASE = 2>
N Log(N x)
{
	return log(x) / log(BASE);
}

int main()
{
	int a = 1000;
	double x = 1000.0;

	int base2 = 2;
	int base10 = 10;

	cout << "Log(a) = " << Log(a) << endl;
	cout << "Log(x) = " << Log(x) << endl;

	cout << "Log<int>(a) = " << Log<int>(a) << endl;
	cout << "Log<int, 10>(a) = " << Log<int, 10>(a) << endl;
	// cout << "Log<int, base10>(a) = " << Log<int, base10>(a) << endl;
	
	cout << "Log<int>(x) = " << Log<int>(x) << endl;
	cout << "Log<int, 10>(x) = " << Log<int, 10>(x) << endl;
	// cout << "Log<double, base10>(x) = " << Log<double, base10>(x) << endl;
	cout << "Log<double, 10>(x) = " << Log<double, 10>(x) << endl;
	// cout << "Log<double, 10>(x) = " << Log<double>(x, base10) << endl;

}

