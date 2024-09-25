#include <iostream>     // for cout
#include <string>       // for to_string
#include <memory>       // for unique_ptr

using namespace std;

class MyClass {
public:
    MyClass(int d) : data(d) {
        cout << "MyClass constructor for: " << ToString() << endl;
    }
    
    ~MyClass() {
        cout << "MyClass destructor for: " << ToString() << endl;
    }

    int get() const {
        return data;
    }

    void set(int d) {
        data = d;
    }

    string ToString() const {
        return "MyClass[data = "+ to_string(data) + "]";
    }

private:
    int data;
};

int main()
{

    cout << "--- 1. Creating a unique_ptr to MyClass" << endl;
    // make_unique allocates memory for the object and returns a unique_ptr
    unique_ptr<MyClass> uptr1 = make_unique<MyClass>(42); 
    // alternatively, you can use new to create a unique_ptr:
    // unique_ptr<MyClass> uptr1(new MyClass(42));

    // Access the object using the pointer
    cout << "uptr1->get() = " << uptr1->get() << endl;

    (*uptr1).set(100); // using the dereference operator and . operator
    cout << "after (*uptr1).set(100):"<< endl;
    cout << "(*uptr1).get() = " << (*uptr1).get() << endl << endl;


    cout << "--- 2. Demonstrate move semantics" << endl;
    // for each  object, there is only one unique_ptr that owns it
    // assigning a unique_ptr to another unique_ptr transfers ownership
    // the first unique_ptr becomes nullptr
    // this insures that the object accessed through the unique_ptr
    // is destroyed only once

    // move the unique_ptr to another unique_ptr
    unique_ptr<MyClass> uptr2 = move(uptr1);
    cout << "uptr1 is moved to uptr2" << endl;
    cout<< "is uptr1 == nullptr ? " << (uptr1 == nullptr) << endl;
    cout << "uptr2->ToString() = " << uptr2->ToString() << endl << endl;

    cout << "The unique_ptr is destroyed when it goes out of scope" << endl;
    cout << "The destructor of unique_ptr calls the destructor of MyClass" << endl;


    return 0;
}