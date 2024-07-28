//
// File: ex_12_local_variables.cpp
// local variables can be declared inside a block of code
// 
#include <iostream>
using namespace std;

int main() {

	int a = 10;
	{   // a block of code
        // variables declared inside a block of code are local to that block
		int a = 20; // a is a local variable to this block
                    // it hides the global variable a
        int b = 30;
		cout << "inside the block: a = " << a << endl;
	}
	cout << "outside the block: a = " << a << endl;
    // cout << b; // Error: b is not declared in this scope
}
