// File: ex_02_cons_destrs_local.cpp
// demonstrates the order of constructor and destructor calls
#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A(string name): name(name) { cout << "A constructor for " << name << endl; }
    ~A() { cout << "A destructor for " << name << endl; }
private:
    string name;
};

int main () {
    cout << "main() starts" << endl;;
    A a1("a1");
    A a2("a2");

    cout << "main() ends" << endl;
}