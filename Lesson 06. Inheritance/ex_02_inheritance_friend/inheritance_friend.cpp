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
}; // line 20

class B: public A //private A // protected A 
{
    friend void friendOfB(A& a, B& b);
public:
    void print() const
    {
        int x;
        x = publicInA;          // line 27
        x = protectedInA;       // line 28
        x = privateInA;		    // line 29

    };
}; 

class C : public B 
{
    void print() const 
    {
        int x;
        x = publicInA;          // line 38
        x = protectedInA;       // line 39
        x = privateInA;		    // line 40
    };
}; 

void friendOfA(A& a, B& b)
{
    int x;
    
    x = a.publicInA;            // line 49
    x = a.protectedInA;         // line 50
    x = a.privateInA;	        // line 51

    x = b.publicInA;            // line 53
    x = b.protectedInA;         // line 54
    x = b.privateInA;           // line 55
} 

void friendOfB(A& a, B& b)
{
    int x;
    
    x = a.publicInA;            // line 62
    x = a.protectedInA;         // line 63  
    x = a.privateInA;           // line 64  
    
    x = b.publicInA;            // line 66
    x = b.protectedInA;         // line 67
    x = b.privateInA;           // line 68	
} 

int main()
{
    A a;
    B b; 
    C c;
    int x;

    x = a.publicInA;            // line 78
    x = a.protectedInA;         // line 79
    x = a.privateInA;           // line 80

    x = b.publicInA;			// line 82
    x = b.protectedInA;			// line 83
    x = b.privateInA;			// line 84

    x = c.publicInA;			// line 86
    x = c.protectedInA;			// line 87
    x = c.privateInA;			// line 88
} 