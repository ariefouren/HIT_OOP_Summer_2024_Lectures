#include <iostream>
using namespace std;

class B;
class C;

class A {
    friend class B;
    private:
    int a;
};

class B {
    friend class C;
    public:
    void f(A& a) {
        a.a = 1;        // line 17
    }
    private:
    int b;
};

class C {
    public:
    void f(A& a) {
        a.a = 1;        // line 26
    }
    
    void g(B& b) {
        b.b = 2;        // line 30
    }

    void h(C& c) {
        c.c = 3;        // line 34
    }

    private:
    int c;
};

