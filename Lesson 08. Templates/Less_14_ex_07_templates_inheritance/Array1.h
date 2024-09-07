// Fig. 8.4: array1.h
// Simple class Array (for integers)
#pragma  once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>

using namespace std;

template <class T>
// Alternative form:
// template <typename T>
class Array {
   template <class T>
        friend ostream &operator<<( ostream &, const Array<T> & );
   template <class T>
        friend istream &operator>>( istream &, Array<T> & );
public:
   Array( int = 10 );                   // default constructor
   Array( const Array & );              // copy constructor
   virtual ~Array();                            // destructor
   virtual const Array &operator=( const Array & ); // assign arrays
   
   virtual bool operator==( const Array & ) const;  // compare equal

   virtual int getSize() const;                 // return size
   // Determine if two arrays are not equal (uses operator==).
   virtual bool operator!=( const Array &right ) const  
      { return ! ( *this == right ); }
   
   virtual T &operator[]( int );    // subscript operator - returns l-value
   virtual const T &operator[]( int ) const; // subscript operator - returns r-value
 
   static int getArrayCount();          // Return count of 
                                        // arrays instantiated.
protected:
   int size; // size of the array
   T *ptr; // pointer to first element of array
   static int arrayCount;  // # of Arrays instantiated
};

// Initialize static data member at file scope
template <class T>
int Array<T>::arrayCount = 0;   // no objects yet

// Default constructor for class Array (default size 10)
template <class T>
Array<T>::Array(int arraySize)
{
    size = (arraySize > 0 ? arraySize : 10);
    ptr = new T[size]; // create space for array
    assert(ptr != 0);    // terminate if memory not allocated
    ++arrayCount;          // count one more object

    for (int i = 0; i < size; i++)
        ptr[i] = 0;          // initialize array
}

// Copy constructor for class Array
// must receive a reference to prevent infinite recursion 
// [Q] why the problem arises and why passing the parameter by 
//     reference solves it ?
template <class T>
Array<T>::Array(const Array& initArr) : size(initArr.size)
{
    ptr = new T[size];     // create space for array
    assert(ptr != 0);      // terminate if memory not allocated
    ++arrayCount;            // count one more object

    for (int i = 0; i < size; i++)
        ptr[i] = initArr.ptr[i];  // copy initArr into object
}

// Destructor for class Array
template <class T>
Array<T>::~Array()
{
    delete[] ptr;            // reclaim space for array
    --arrayCount;             // one fewer objects
}

// Get the size of the array
template <class T>
int Array<T>::getSize() const { return size; }

// Overloaded assignment operator
// const return avoids: ( a1 = a2 ) = a3
// but allows a1 = a2 = a3 (which is equal to a1 = (a2 = a3) ) 
template <class T>
const Array<T>& Array<T>::operator=(const Array& right)
{
    if (&right != this) {  // check for self-assignment

       // for arrays of different sizes, deallocate original
       // left side array, then allocate new left side array.
        if (size != right.size) {
            delete[] ptr;         // reclaim space
            size = right.size;     // resize this object
            ptr = new T[size];   // create space for array copy
            assert(ptr != 0);    // terminate if not allocated
        }

        for (int i = 0; i < size; i++)
            ptr[i] = right.ptr[i];  // copy array into object
    }

    return *this;   // enables a1 = a2 = a3;
}

// Determine if two arrays are equal and
// return true, otherwise return false.
template <class T>
bool Array<T>::operator==(const Array& right) const
{
    if (size != right.size)
        return false;    // arrays of different sizes

    for (int i = 0; i < size; i++)
        if (ptr[i] != right.ptr[i])
            return false; // arrays are not equal

    return true;        // arrays are equal
}

// Overloaded subscript operator for non-const Arrays
// Reference return creates an l-value
template <class T>
T& Array<T>::operator[](int subscript)
{
    // check for subscript out of range error
    assert(0 <= subscript && subscript < size);

    return ptr[subscript]; // reference return
}

// Overloaded subscript operator for const Arrays
// const reference return creates an r-value
template <class T>
const T& Array<T>::operator[](int subscript) const
{
    // check for subscript out of range error
    assert(0 <= subscript && subscript < size);

    return ptr[subscript]; // const reference return
}

// Return the number of Array objects instantiated.
// Static functions cannot be const 
// [Q] Why ?
template <class T>
int Array<T>::getArrayCount() {
    return arrayCount;
}

// Overloaded input operator for class Array;
// inputs values for entire array.
template <class T>
istream& operator>>(istream& input, Array<T>& a)
{
    for (int i = 0; i < a.size; i++)
        input >> a.ptr[i];

    return input;   // enables cin >> x >> y;
}

// Overloaded output operator for class Array 
template <class T>
ostream& operator<<(ostream& output, const Array<T>& a)
{
    int i;

    for (i = 0; i < a.size; i++) {
        output << setw(6) << a.ptr[i];

        if ((i + 1) % 10 == 0) // 10 numbers per row of output
            output << endl;
    }
    return output;   // enables cout << x << y;
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
