//
// inheritance_friend.cpp
// Testing inheritance  and access to member variables
//   
#include <iostream>
using namespace std;

class A
{
    public: 
        int publicInA; 
    protected:
        int prot_a;
    private:
        int priv_a;
}; 

class B: public A // protected A  // private A
{
    public:
    void checkAccess() const
    {
        cout << publicInA;          // line 23
        cout << prot_a;       // line 24
        cout << priv_a;		    // line 25 <-- error: 'int A::privateInA' is private within this context

    };
}; 

class C : public B 
{
    public:
    void checkAccess() const 
    {
        cout << publicInA;          // line 35
        cout << prot_a;       // line 36
        cout << priv_a;		    // line 37 <-- error: 'int A::privateInA' is private within this context
    };
}; 

int main()
{
    A a;
    B b; 
    C c;

    cout << a.publicInA;            // line 47
    cout << a.prot_a;         // line 48 <-- error: 'int A::protectedInA' is protected within this context
    cout << a.priv_a;           // line 49 <-- error: 'int A::privateInA' is private within this context

    cout << b.publicInA;			// line 51
    cout << b.prot_a;			// line 52 <-- error: 'int A::protectedInA' is protected within this context
    cout << b.priv_a;			// line 53 <-- error: 'int A::privateInA' is private within this context

    cout << c.publicInA;			// line 55
    cout << c.prot_a;			// line 56 <-- error: 'int A::protectedInA' is protected within this context
    cout << c.priv_a;			// line 57 <-- error: 'int A::privateInA' is private within this context
} 