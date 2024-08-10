// File: ex_05_friend_classes.cpp
// demonstrating friend classes
#include <iostream>
using namespace std;

class B;    // forward declaration of class B
class C;    // forward declaration of class C

class A
{
    friend class B;   // A declares B as a friend class

public:
    A(): count(0) {}	// constructor
	void print() const
    {
	    cout << "class A object, count = " << count << endl;
    }

private:
	int count;
};

// definition of class B (friend of A)
class B
{
	friend class C;  // B declares C as a friend class

public:
	void setCount(A& objectA, int value)
    {
	    objectA.count = value;	// B is a friend class of A
        // therefore B has access to private members of A   
    }

};

// definition of class C(friend of B, but not of A)
class C
{
public:
	void tryToAccessA(A& objectA)
    {
	// cout << objectA.count;	// ERROR ! 
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

	b.setCount(a, 100);
    cout << "After b.setCount(a, 100): ";
	a.print();

}
