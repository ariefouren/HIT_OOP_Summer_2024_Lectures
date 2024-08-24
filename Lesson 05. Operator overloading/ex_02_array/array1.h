// Fig. 8.4: array1.h
// Simple class Array (for integers)
#ifndef ARRAY1_H
#define ARRAY1_H

#include <iostream>

using std::ostream;
using std::istream;

class Array {
   friend ostream &operator<<( ostream &, const Array & );
   friend istream &operator>>( istream &, Array & );
public:
   
   Array( int = 10 );                   // default constructor
   Array( const Array & );              // copy constructor
   ~Array();                            // destructor
   const Array &operator=( const Array & ); // assign arrays
   
   bool operator==( const Array & ) const;  // compare equal

   int getSize() const;                 // return size
   // Determine if two arrays are not equal and
   // return true, otherwise return false (uses operator==).
   bool operator!=( const Array &right ) const  
      { return ! ( *this == right ); }
   
   int &operator[]( int );             // subscript operator, 
                                       // returns lvalue
                                       // allows modification of arr[i]
   const int &operator[]( int ) const; // subscript operator, const
                                       // version, returns rvalue
                                       // (cannot be used as lvalue)
   operator int() // conversion to int type operator
   {
	   return size;
   }

   static int getArrayCount();          // Return count of 
                                        // arrays instantiated.
private:
   int size; // size of the array
   int *ptr; // pointer to first element of array
   static int arrayCount;  // # of Arrays instantiated
};

#endif



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
