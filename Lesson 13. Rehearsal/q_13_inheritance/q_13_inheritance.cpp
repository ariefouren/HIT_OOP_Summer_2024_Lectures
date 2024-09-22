#include <iostream>
using namespace std;

class X {
public:
	X(int i = 0, int j = 0, int k = 0) { a = i; b = j; c = k; }
	~X() { }
	int a;
protected:
	int b;
private:
	int c;
};
class Y : protected X {
public:
	Y(int i = 0, int j = 0, int k = 0) : X(i, j, k) { d = i; e = j; f = k; }
	~Y() { }
	void printY() { cout << a << b << d << e << f << endl; }
	int d;
protected:
	int e;
private:
	int f;
};
class Z : public Y {
public:
	Z(int i = 0) { l = i; }
	~Z() { }
	void funcZ() { a = 21; b = 22; d = 31; e = 32; }
	void printZ() { cout << a << b << d << e << endl; }
	int l;
};
int main() {
	Z myZ1(5);      // Line 1
	myZ1.a = 101;   // Line 2
	myZ1.d = 201;   // Line 3
	myZ1.l = 301;   // Line 4
	return 1;
}
