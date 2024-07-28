//
// File: ex_13_local_var_in_loop.cpp
// local variables can be declared inside a loop
// 
#include <iostream>
using namespace std;

int main() {
	// int i = 0; 
	for(int i = 0; i <= 5; i++) // i is a local variable 
	{
		cout << " i = " << i << endl;
	}
	// cout << i << endl  // <-- Error ! variable i is undefined outside the loop
}
