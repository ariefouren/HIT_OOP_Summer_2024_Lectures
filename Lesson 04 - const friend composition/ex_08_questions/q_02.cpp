#include <iostream>
using namespace std;

class A {
public:
	A() {};
	void f(A& a) { cout << 1; };
	void f(A& a) const { cout << 2; };
	void f(const A& a) { cout << 3; };
	
};

int main() {
	const A a1;
	A a2;
	a1.f(a2);
	a2.f(a2);
	a2.f(a1);
}
