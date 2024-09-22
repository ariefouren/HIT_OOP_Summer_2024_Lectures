#include <iostream>
using namespace std;

class A{
private:
	int x;
public:
	A(int _x) { x = _x; }
	int get() { return x; }
};
A a(0);

class B{
	static A a;
public:
	static int get(){return a.get();}
};
A B::a(1);

int main(void){
	B b;
	cout << a.get()<<b.get();
	return 0;
}
