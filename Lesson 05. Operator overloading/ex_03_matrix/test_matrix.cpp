// File: test_matrix.cpp
// test the matrix class

#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    Matrix m1(2, 3);
    m1(0, 0) = 1.0; m1(0, 1) = 2.0; m1(0, 2) = 3.0;
    m1(1, 0) = 4.0; m1(1, 1) = 5.0; m1(1, 2) = 6.0;

    const Matrix m2 = m1; // copy constructor

    Matrix m3(1, 1);
   
    cout<< "\n\n ------- After initialization:   " << endl;  
    cout << "m1: " << endl << m1 << endl;
    cout << "m2: " << endl << m2 << endl;
    cout << "m3: " << endl << m3 << endl;

    cout << "\n\n  ------- Test assignment operator: " << endl;
    m3 = m1;
    cout << "m3 = m1: " << endl << m3 << endl;

    cout << "\n\n  ------- Access to a constant object: " << endl;
    cout << "m2(1, 2) : " << endl << m2(1, 2) << endl;

    cout << "\n\n  ------- Test matrix transpose: " << endl;
    Matrix m7 = m1.transpose();
    cout << "m1.transpose(): " << endl << m7 << endl;

    cout << "\n\n  ------- Test scalar multiplication: " << endl;
    Matrix m6 = 2.0 * m1;
    cout << "2.0 * m1: " << endl << m6 << endl;

    cout << "\n\n  ------- Test matrix addition: " << endl;
    Matrix m4 = m1 + m2;
    cout << "m1 + m2: " << endl << m4 << endl;

    cout << "\n\n  ------- Test matrix multiplication: " << endl;
    // Matrix m5 = m1 * m2; // should generate a runtime error
                            // because the dimensions do not match
    Matrix identity2(2, 2); // identity matrix
    identity2(0, 0) = 1.0; identity2(0, 1) = 0.0;
    identity2(1, 0) = 0.0; identity2(1, 1) = 1.0;
    Matrix m5 = identity2 * m1;
    cout << "identity2 * m1: " << endl << m5 << endl;

    Matrix identity3(3, 3); // identity matrix 3 x 3
    identity3(0, 0) = 1.0; identity3(0, 1) = 0.0; identity3(0, 2) = 0.0;
    identity3(1, 0) = 0.0; identity3(1, 1) = 1.0; identity3(1, 2) = 0.0;
    identity3(2, 0) = 0.0; identity3(2, 1) = 0.0; identity3(2, 2) = 1.0;
    m5 = m1 * identity3;
    cout << "m1 * identity3: " << endl << m5 << endl;

    m5 = m1 * m1.transpose();
    cout << "m1 * m1.transpose(): " << endl << m5 << endl;
    m5 = m1.transpose() * m1;
    cout << "m1.transpose() * m1: " << endl << m5 << endl;   

    cout << "\n\n  ------- Test matrix comparison: " << endl;
    cout << "m1 == m2: " << (m1 == m2) << endl;
    cout << "m1 != m2: " << (m1 != m2) << endl;

    return 0;

}