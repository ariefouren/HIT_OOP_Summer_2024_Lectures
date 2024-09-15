// File: ArrayTest.cpp
#include <iostream>
#include "Array1.h"
#include "CharArrayIgnoreCase.h"
#include "ArrayWithDefaultValue.h"

using namespace std;

int main()
{ 
	cout << "--- 1. Testing Array<char> : \n";
	Array<char> charArr1(5), charArr2(5);
	cout << "enter 5 characters for charArr1: ";
	cin >> charArr1;

	cout << "enter 5 characters for charArr2: ";
	cin >> charArr2;

	cout << "charArr1 = " << charArr1 << endl;
	cout << "charArr2 = " << charArr2 << endl;

	cout << "charArr1 == charArr2 returns " 
		<< (charArr1 == charArr2);

	cout << "\n\n--- 2. Testing CharArrayIgnoreCase: \n";
	CharArrayIgnoreCase charArrIgnoreCase1(5), charArrIgnoreCase2(5);
	cout << "enter 5 characters for charArrIgnoreCase1: ";
	cin >> charArrIgnoreCase1;

	cout << "enter 5 characters for charArrIgnoreCase2: ";
	cin >> charArrIgnoreCase2;

	cout << "charArrIgnoreCase1 = " << charArrIgnoreCase1 << endl;
	cout << "charArrIgnoreCase2 = " << charArrIgnoreCase2 << endl;

	cout << "charArrIgnoreCase1 == charArrIgnoreCase2 returns " 
		<< (charArrIgnoreCase1 == charArrIgnoreCase2);

	cout << "\n\n--- 3. Testing ArrayWithDefaultValue<double> : \n";
	ArrayWithDefaultValue<double> arr_with_default_value1(5, 3.14);
	cout << "arr_with_default_value1 = " << arr_with_default_value1 << endl;
	cout << "type of arr_with_default_value1 = " << typeid(arr_with_default_value1).name() << endl;

   return 0;
}

