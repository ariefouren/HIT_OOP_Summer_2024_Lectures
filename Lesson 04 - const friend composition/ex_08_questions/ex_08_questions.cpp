// File: ex_08_questions.cpp
#include <iostream>
using namespace std;

class A
{
    public:
        A() {};
    private:
        A a; // Error: recursive member declaration, results in infinite recursion
}