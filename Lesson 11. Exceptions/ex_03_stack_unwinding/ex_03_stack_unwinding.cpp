#include <iostream>     // for cout
#include <exception>
using namespace std;

// forward declarations
void f1();
void f2();
void f3();

// function f1 calls f2
void f1() {
    cout << "Function f1 calls f2" << endl;
    f2();
}

// function f2 calls f3
void f2() {
    cout << "Function f2 calls f3" << endl;
    f3();
}

// function f3 throws an exception
// and doesn't catch it
void f3() {
    cout << "Function f3 throws an exception: " <<
            "--- Exception thrown in f3 ----" << endl;
    throw runtime_error("--- Exception thrown in f3 ----");
}

// function main calls f1
// and catches the exception, demonstrating stack unwinding
int main() {
    cout << "Function main calls f1" << endl;
    try {
        f1();  // the function that throws an exception
    }
    catch (const exception& e) {
        cout << "in main: exception caught: " << e.what() << endl;
        cout << "main handles the exception" << endl;
    }
    return 0;
}