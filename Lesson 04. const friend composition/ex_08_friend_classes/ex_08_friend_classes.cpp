//
// File: ex_08_friend_classes.cpp
// demonstrating friend classes
//
#include <iostream>
using namespace std;

class B;    // forward declaration of class B
class C;    // forward declaration of class C

class A
{
    friend class B;   // A declares B as a friend class

public:
    A(): privateVar(0) {}	// constructor
	void print() const
    {
	    cout << "class A object, count = " << privateVar << endl;
    }

private:
	int privateVar;
};

// definition of class B (friend of A)
class B
{
	friend class C;  // B declares C as a friend class

public:
	void setPrivateVarOfClassA(A& objectA, int value)
    {
	    objectA.privateVar = value;	// B is a friend class of A
        // therefore B has access to private members of A   
    }

};

// definition of class C(friend of B, but not of A)
class C
{
public:
	void tryToAccessA(A& objectA)
    {
	// cout << objectA.privateVar;	// ERROR ! 
	// class C is a friend of B but not of A
    // therefore C does not have access to private members of A
	// the relation "friend of" is not transitive
    }
};

int main()
{
	A a;
	B b;
	cout << "Initially :               ";
	a.print();

// since B is a friend of A, it can access private members of A
// and can modify them through a public member function 
// setPrivateVarOfClassA of class B
	b.setPrivateVarOfClassA(a, 100);
    cout << "After b.setPrivateVarOfClassA(a, 100): ";
	a.print();

}
