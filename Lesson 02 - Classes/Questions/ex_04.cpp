#include <iostream>
using namespace std;

class A {
public:
    A(int x = 0): a(x) {}
    int &g() { return a; }
private:
    int a;
};

int main() {
    A a(5), b;
    b = a;
    a.g() = 10;
    cout << a.g() << " " << b.g() << endl;
}
