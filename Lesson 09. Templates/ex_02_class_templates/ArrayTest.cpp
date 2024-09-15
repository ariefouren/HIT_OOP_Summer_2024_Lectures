// File: ArrayTest.cpp
// Test Array<char> class template
//
#include <iostream>
#include <cctype> // for isalpha() and toupper()
#include "ArrayChar.h"
using namespace std;

#define FIRST_CHAR 32
#define LAST_CHAR 126

int main()
{

   //// Testing Array<char>
   Array<char> charArr1(LAST_CHAR - FIRST_CHAR + 1);
   // fill charArr1 with ASCII printable characters
   for(int i = 0; i < charArr1.getSize(); i++)
       charArr1[i] = FIRST_CHAR + i;
    cout << "ASCII printable characters (charArr1):\n" << charArr1 << endl;

    Array<char> charArr2;
    cout << "charArr2:\n" << charArr2 << '\n';
    charArr2 = charArr1;
    cout << "charArr2 after assignment:\n" << charArr2 << '\n';

    cout << "put all alpha characters in charArr2 to upper case\n";
    for(int i = 0; i < charArr2.getSize(); i++)
        if(isalpha(charArr2[i]))
            charArr2[i] = toupper(charArr2[i]);

    cout << "charArr2 after upper case conversion:\n" << charArr2 << '\n';
    cout << "checking if charArr1 == charArr2\n";
    cout << "charArr1 and charArr2 are" 
        << (charArr1 == charArr2 ? " equal" : " not equal") << endl << endl;

   return 0;
}
