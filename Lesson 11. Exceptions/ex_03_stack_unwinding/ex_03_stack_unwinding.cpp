#include <iostream>     // for cout
#include <exception>
using namespace std;

// Demonstrates stack unwinding
// If an exception is thrown in a function, the stack is unwound.
// It includes calling destructors for local variables
// in the reverse order of their creation, 
// as the program moves back up the call stack to find 
// a matching exception handler (catch block).
class MyClass{
public:
    MyClass(int id): id(id){
        cout << "Constructor of MyClass[id = " << id << "]"<< endl;
    }
    ~MyClass(){
        cout << "Destructor of MyClass[id = " << id << "]"<< endl;
    }
    private:
    int id;
};

// forward declarations
void f1();
void f2();
void f3();

// function f1 calls f2
void f1() {
    MyClass obj(1);
    cout << "Function f1 calls f2" << endl;
    f2();
}

// function f2 calls f3
void f2() {
    MyClass obj(2);
    cout << "Function f2 calls f3" << endl;
    f3();
}

// function f3 throws an exception
// and doesn't catch it
void f3() {
    MyClass obj(3);
    cout << "Function f3 throws an exception: " <<
            "--- Exception thrown in f3 ----" << endl;
    throw runtime_error("--- Exception thrown in f3 ----");
}

// function main calls f1
// and catches the exception, demonstrating stack unwinding
int main() {
    MyClass obj(4);
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