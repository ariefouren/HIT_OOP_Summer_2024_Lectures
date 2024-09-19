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
    cout << "Creating a unique_ptr to MyClass" << endl;
    // make_unique allocates memory for the object and returns a unique_ptr
    unique_ptr<MyClass> uptr1 = make_unique<MyClass>(42); 

    // Access the object using the pointer
    cout << "uptr1->get() = " << uptr1->get() << endl;

    (*uptr1).set(100); // using the dereference operator and . operator
    cout << "after (*uptr1).set(100):"<< endl;
    cout << "(*uptr1).get() = " << (*uptr1).get() << endl;

    cout << "The unique_ptr is destroyed when it goes out of scope" << endl;
    cout << "The destructor of unique_ptr calls the destructor of MyClass" << endl;

    return 0;
}