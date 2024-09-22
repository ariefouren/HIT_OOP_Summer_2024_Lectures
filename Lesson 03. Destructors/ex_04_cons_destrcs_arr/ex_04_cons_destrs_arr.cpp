// File: ex_04_cons_destrs_local.cpp
// demonstrates the order of constructor and destructor calls
#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A(){ 
        id = privateVar ++;
        cout << "A constructor for object id = " << id << endl; 
    }
    ~A() { 
        privateVar --;
        cout << "A destructor for object id = " << id << endl; 
    }

private:
    static int privateVar;   // the number of objects created
    int id;             // the id of the object
};

int A::privateVar = 0; // initialize the static member variable
int main () {
    cout << "main() starts" << endl;
    cout << "Defining local array: A arr1[2];" << endl;
    A arr1[2];

    cout << "\nDefining dynamic array: A* arr2 = new A[3];" << endl;
    A* arr2 = new A[3];

    cout << "\nDeleting dynamic array: delete[] arr2;" << endl;
    delete[] arr2;

    cout << "\nmain() ends" << endl;
}