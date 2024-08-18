#include <iostream>
using namespace std;
class A {
public:
    A(int x = 0):a(x) {};
    friend void f(A& a);        // line 1
private:
    int a;
};

void f(A& a) {
    ++a.a;    // line 2
}

int main() {
    A a, b;     // line 3
    f(a);       // line 4
    a.f(b);     // line 5
    return 0;
}