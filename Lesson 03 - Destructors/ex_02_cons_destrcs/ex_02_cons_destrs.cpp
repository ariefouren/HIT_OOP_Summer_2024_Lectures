// File: ex_02_cons_destrs.cpp
// demonstrates the order of constructor and destructor calls
#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A(){ 
        id = count ++;
        cout << "A constructor for object id = " << id << endl; 
    }
    ~A() { 
        count --;
        cout << "A destructor for object id = " << id << endl; 
    }

private:
    static int count;   // the number of objects created
    int id;             // the id of the object
};

int A::count = 0; // initialize the static member variable
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