#include <iostream>
using namespace std;

class X {
public:
    X(int i) { n = i; }
    int &f() { return n; }
private:
    int n;
};

int main() {
    X x1(5);
    int &j = x1.f();
    j += 2;
    cout << j << x1.f() << endl;
}