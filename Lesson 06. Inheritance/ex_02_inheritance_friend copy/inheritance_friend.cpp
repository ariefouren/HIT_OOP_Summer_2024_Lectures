//
// inheritance_friend.cpp
// Testing inheritance with friend functions
//   
#include <iostream>
using namespace std;

class B;
class A
{
    void memberOfA(B& b);
    friend void friendOfA(B& b);
protected:
    int prot_a;
private:
    int priv_a;
};

void A::memberOfA(B& b)
{
    // member function of class A has access to the members of A
    // in the object of the derived class B
    cout <<  b.prot_a; 
    cout <<  b.priv_a;  

    // member function of class A has no access to the 
    // private and protected members of the derived class B
    cout <<  b.prot_b; 
    cout <<  b.priv_b;  
}

// friend function of class A has the same access to the members of A
// as the member functions of A
void friendOfA(B& b)
{
    // friend function of class A has access to the members of A
    // in the object of the derived class B
    cout <<  b.prot_a; 
    cout <<  b.priv_a;  

    // friend function of class A has no access to the 
    // private and protected members of the derived class B
    cout <<  b.prot_b; 
    cout <<  b.priv_b;  
} 

class B: public A 
{
    void memberOfB(A& a, B& b);
    friend void friendOfB(A& a, B& b);
    protected:
        int prot_b;
    private:
        int priv_b;
}; 

void B::memberOfB(A& a, B& b)
{   
    // member function of class B has no access 
    // to the private and protected members of A 
    cout <<  a.prot_a;        
    cout <<  a.priv_a;    
    
    // member function of class B has access to the protected members of A
    // but not to the private members of A
    // in the object of the derived class B
    cout <<  b.prot_a;         
    cout <<  b.priv_a;           

    cout <<  b.prot_b;         
    cout <<  b.priv_b;           
} 

void friendOfB(A& a, B& b)
{   
    // friend function of class B has no access 
    // to the private and protected members of A 
    cout <<  a.prot_a;        
    cout <<  a.priv_a;    
    
    cout <<  b.prot_a;         
    cout <<  b.priv_a;           

    cout <<  b.prot_b;         
    cout <<  b.priv_b;           
} 

