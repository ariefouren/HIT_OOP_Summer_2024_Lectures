// File: test_matrix.cpp
// test the matrix class
// demonstrates dynamic memory allocation
//
#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    Matrix m1(2, 3);
    m1.set(0, 0, 1.0); m1.set(0, 1, 2.0); m1.set(0, 2, 3.0);
    m1.set(1, 0, 4.0); m1.set(1, 1, 5.0); m1.set(1, 2, 6.0);

    const Matrix m2 = m1; // copy constructor
 
   
    cout<< "\n\n ------- After initialization:   " << endl;  
    cout << "m1: " << endl;
    m1.print();
    cout << endl;

    cout << "m2: " << endl;
    m2.print();
    cout << endl;

    cout << "\n\n  ------- Test matrix transpose: " << endl;
    Matrix m3 = m2.transpose(); // create m3 using a copy constructor
    cout << "After m3 = m2.transpose(): " << endl;
    cout << "m3: " << endl;
    m3.print();
    cout << endl;

    return 0;

}
