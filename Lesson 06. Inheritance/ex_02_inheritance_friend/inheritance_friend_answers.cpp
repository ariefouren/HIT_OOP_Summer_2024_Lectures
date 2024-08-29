//
// inheritance_friend.cpp
// Testing inheritance with friend functions
//   
#include <iostream>
using namespace std;

class B;
class A
{
	friend void friendOfA(A& a, B& b);
public:
	int publicInA; 
protected:
	int protectedInA;
private:
	int privateInA;
};

class B: public A //private A // protected A 
{
	friend void friendOfB(A& a, B& b);
public:
	void print() const
	{
		int x;
		x = publicInA;
		x = protectedInA;
		x = privateInA;

	};
};

class C : public B 
{
	void print() const 
	{
		int x;
		x = publicInA;
		x = protectedInA;
		x = privateInA;
	};
};

void friendOfA(A& a, B& b)
{
	int x;
	// friend function of class A has exactly to the same access 
	// to the members of A as the member functions of A
	
	// access to object of class A
	x = a.publicInA;
	x = a.protectedInA;
	x = a.privateInA;

	// access to object of class B
	x = b.publicInA;
	x = b.protectedInA;
	x = b.privateInA;
}

void friendOfB(A& a, B& b)
{
	int x;
	// for object of class B, the friend function is like a member function
	// and it has access to the public and protected members of A
	// (but not to the private members of A)

	// for object of class A, the friend function of B 
	// is like any external function and it has access 
	// only to the public members of A
	
	x = a.publicInA;
	x = a.protectedInA;  
	// ^^^ ERROR: for objects of class A, the friend function of B
	// ^^^ is like any external function and it has access
	// ^^^ only to the public members of A
	x = a.privateInA;  
	// ^^^ ERROR: for objects of class A, the friend function of B
	// ^^^ is like any external function and it has access
	// ^^^ only to the public members of A
	
	// access to the members of object of class B
	x = b.publicInA;
	x = b.protectedInA;
	x = b.privateInA;	
	// ^^^ ERROR: for objects of class B, the friend function of B
	// ^^^ is like a member function and it has access to the public
	// ^^^ and protected members of A (but not to the private members of A)
}

int main()
{
	A a;
	B b; 
	C c;
	int x;

	// access to object of class A
	x = a.publicInA;
	x = a.protectedInA;
	// ^^^ ERROR: protected members of A are not accessible 
	// ^^^ outside of A
	x = a.privateInA;
	// ^^^ ERROR: private members of A are not accessible
	// ^^^ outside of A

	// access to object of class B
	x = b.publicInA;
	x = b.protectedInA;
	// ^^^ ERROR: protected members of A are protected in B
	// ^^^ and are not accessible outside of B
	x = b.privateInA;
	// ^^^ ERROR: private members of A are private in B
	// ^^^ and are not accessible outside of B

	// access to object of class C
	x = c.publicInA;
	x = c.protectedInA;
	// ^^^ ERROR: protected members of A are protected in C
	// ^^^ and are not accessible outside of C
	x = c.privateInA;
	// ^^^ ERROR: private members of A are private in C
	// ^^^ and are not accessible outside of C
}
