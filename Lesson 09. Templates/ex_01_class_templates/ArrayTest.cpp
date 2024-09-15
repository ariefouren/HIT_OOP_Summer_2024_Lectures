// Fig. 8.4: fig08_04.cpp
// Driver for simple class Array
#include <iostream>
#include <complex>  // for complex class definition
#include "Array1.h"
using namespace std;

int main()
{
    cout << "--- 1. Testing class Array<int> ---\n";
    // create <int> array
    Array<int> integers1(5);
    // fill integers1 with even integers
    for (int i = 0; i < integers1.getSize(); i++)
        integers1[i] = i * 2;

   // create array integers2 using integers1 as an initializer
   Array<int> integers2(integers1); // calls copy constructor

   cout << "# of <int> arrays = "
        << Array<int>::getArrayCount() << endl;

    // print integers1 and integers2
    cout << "integers1:\n" << integers1 << endl;
    cout << "integers2:\n" << integers2 << endl;

    // use overloaded assignment (=) operator
    Array<int> integers3; // create <int> array
    cout << "after creating integers3, # of <int> arrays = "
        << Array<int>::getArrayCount() << endl;
    cout << "integers3:\n" << integers3 << endl << endl;

    cout << "checking if integers1 == integers3\n";
    cout << "integers1 and integers3 are" 
        << (integers1 == integers3 ? " equal" : " not equal") << endl;

    integers3 = integers1; // calls overloaded assignment operator
    cout << "after assigning integers1 to integers3 : \n";
    cout << "integers3:\n" << integers3 << endl << endl; 

    cout << "checking if integers1 == integers3\n";
    cout << "integers1 and integers3 are" 
        << (integers1 == integers3 ? " equal" : " not equal") << endl << endl;


    cout << "--- 2. Testing class Array<complex> ---\n";
    // define an alias representing a complex number
    using complex = complex<double>; // note that complex itself is a template
    // alternative (old) way to define an alias: typedef complex<double> complex;

    // create a complex array
    Array<complex> complex1(5);
    // fill complex1 with complex numbers
    for (int i = 0; i < complex1.getSize(); i++)
        complex1[i] = complex(i, i);

    Array<complex> complex2;
    cout << "complex1:\n" << complex1 << '\n';
    cout << "complex2:\n" << complex2 << '\n';

    cout << "checking if complex1 == complex2\n";
    cout << "complex1 and complex2 are" 
        << (complex1 == complex2 ? " equal" : " not equal") << '\n';

    complex2 = complex1; // calls overloaded assignment operator
    cout << "after assigning complex1 to complex2 : \n";
    cout << "complex2:\n" << complex2 << '\n';
    cout << "checking if complex1 == complex2\n";
    cout << "complex1 and complex2 are" 
        << (complex1 == complex2 ? " equal" : " not equal") << '\n';
   
   cout << "reverse the order of elements in complex2" <<
    " using operator[] and auxiliary Array<complex>\n";
   Array<complex> tmp(complex2); // tmp is a copy of complex2
   for (int i = 0; i < complex2.getSize(); i++)
         complex2[i] = tmp[complex2.getSize() - 1 - i];

    cout << "complex2 after reversing the order of elements:\n" 
        << complex2 << '\n'; 

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
