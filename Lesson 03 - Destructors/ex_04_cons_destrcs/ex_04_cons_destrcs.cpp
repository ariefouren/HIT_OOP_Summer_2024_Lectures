// File: ex_04_cons_destrs.cpp
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

static A global1("global1");           // Static global variable
static A global2("global2");           // Another static global variable

void function() {
    static A local("Local");    // Static local variable
}

int main() {
    std::cout << "\nmain() starts" << std::endl;
    function(); // Call the function to initialize the static local variable
    function(); // second call to function does not initialize the static local variable
	cout << "\nmain() ends" << endl;
    return 0;
}
