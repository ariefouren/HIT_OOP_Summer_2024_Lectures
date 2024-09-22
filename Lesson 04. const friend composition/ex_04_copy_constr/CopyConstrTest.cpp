//
// CopyConstrTest.cpp
// demonstrating copy constructor and default assignment operator
//
#include <iostream>
using namespace std;

class MyClass
{
public:
    MyClass(int val = 0): val(val) // constructor with default parameter
    {
        cout << "constructor with parameter for ";
        print();     
    }

    MyClass(const MyClass& obj) :
        val(obj.getVal())
    {
        cout << "COPY constructor for ";
        print();		
    }

    int getVal() const
    {
        return val;
    }

    void print()
    {
        cout << "object " << "val = " << val << endl;
    }

private:
    int val;
};

// the function gets an object by value, so the COPY constructor is called
// the function returns an object by value, so the COPY constructor is called again
MyClass f(MyClass obj)
{
    cout << "start of function f with parameter ";
    obj.print();
    cout << "returning from function f" << endl;
    return obj;
}

 int main()
{
    cout << "Creating obj1(1)" << endl;
    MyClass obj1(1);		// constructor with parameter call
    cout << "------------------------------\n\n";
    cout << "Creating obj2 = obj1" << endl;
    MyClass obj2 = obj1;	// COPY constructor call
    cout << "------------------------------\n\n";

    cout << "call f(obj1).print()" << endl;
    f(obj1).print();	// COPY contractor call twice: for the parameter and
                        // for the returned value
    cout << "------------------------------\n\n";

    cout << "Creating obj3(obj1)" << endl;
    MyClass obj3(obj1); // COPY constructor 
    cout << "------------------------------\n\n";

    cout << "Creating obj4" << endl;
    MyClass obj4;		// default constructor is used for obj4
    cout << "------------------------------\n\n";
    cout << "Performing obj4 = obj3" << endl;
    obj4 = obj3;		// default assignment operator, NOT copy constructor !
    obj4.print();
}