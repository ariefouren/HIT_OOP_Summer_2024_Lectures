// File: ex_03_cons_destrs_static_local.cpp
// demonstrates the order of constructor and destructor calls
#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A(const char* name) : name(name) {
        std::cout << "Constructor: " << name << std::endl;
    }
    ~A() {
        std::cout << "Destructor: " << name << std::endl;
    }
private:
    const char* name;
};

A global1("global1");           // global variable defined outside of main
A global2("global2");           // global variable defined outside of main

void function() {
    cout << "\nfunction() starts" << endl;
    static A local1("local1");    // Static local variable defined inside a function
    cout << "function() ends" << endl;
}

int main() {
    std::cout << "\nmain() starts" << std::endl;
    function(); // Call the function to initialize the static local variable
    function(); // second call to function does not initialize the static local variable
	cout << "\nmain() ends" << endl;
    return 0;
}
