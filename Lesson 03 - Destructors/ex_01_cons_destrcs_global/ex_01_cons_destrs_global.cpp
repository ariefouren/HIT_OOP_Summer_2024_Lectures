// File: ex_01_cons_destrs_global.cpp
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

// define two global objects
    A a1("global a1");
    A a2("global a2");

int main () {
    cout << "main() starts" << endl;;
    cout << "main() ends" << endl;
}