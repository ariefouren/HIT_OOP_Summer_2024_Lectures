// Fig. 8.4: fig08_04.cpp
// Driver for simple class Array
#include <iostream>
#include "Array1.h"
#include "CharArray.h"
#include "ArrayWithDefaultValue.h"

using namespace std;

int main()
{ 
	cout << "Testing Array<char> : \n";
	Array<char> charArr1(5), charArr2(5);
	cout << "enter 5 characters for charArr1: ";
	cin >> charArr1;

	cout << "enter 5 characters for charArr2: ";
	cin >> charArr2;

	cout << "charArr1 = " << charArr1 << endl;
	cout << "charArr2 = " << charArr2 << endl;

	cout << "charArr1 == charArr2 returns " 
		<< (charArr1 == charArr2);

	cout << "\n\nTesting CharArrayIgnoreCase: \n";
	CharArrayIgnoreCase charArrIgnoreCase1(5), charArrIgnoreCase2(5);
	cout << "enter 5 characters for charArr1: ";
	cin >> charArrIgnoreCase1;

	cout << "enter 5 characters for charArr2: ";
	cin >> charArrIgnoreCase2;

	cout << "charArrIgnoreCase1 = " << charArrIgnoreCase1 << endl;
	cout << "charArrIgnoreCase2 = " << charArrIgnoreCase2 << endl;

	cout << "charArrIgnoreCase1 == charArrIgnoreCase2 returns " 
		<< (charArrIgnoreCase1 == charArrIgnoreCase2);

	ArrayWithDefaultValue<int> arr;
   return 0;
}




/**************************************************************************
 * (C) Copyright 2000 by Deitel & Associates, Inc. and Prentice Hall.     *
 * All Rights Reserved.                                                   *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
