//
// File: ConstructAndDestructTest.cpp    
// Test of class ConstructAndDestruct that demonstrates 
// constructors and destructors
// adapted from P. Deitel, H. Deitel C++ How to Program
//
#include <string>
#include <iostream>
#include "ConstructAndDestruct.h"
using namespace std;

void create(); // function that declares local objects

ConstructAndDestruct obj1(1, "(global, declared before main)");

int main()
{
	cout << "\n\nStart of main()\n";
	
	ConstructAndDestruct obj2(2, "(local in main)");
	static ConstructAndDestruct obj3(3, "(static local in main)");

	create();
	create();

	ConstructAndDestruct obj4(4, "(local in main)");
	
	cout << "End of main()\n\n";

}

void create()
{
	cout << "\n\nStart of create()\n";

	ConstructAndDestruct obj5(5, "(local in create)");
	static ConstructAndDestruct obj6(6, "(static local in create)");
	ConstructAndDestruct obj7(7, "(local in create)");

	cout << "End of create()\n\n";
}
