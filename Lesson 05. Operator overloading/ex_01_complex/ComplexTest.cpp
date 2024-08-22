//
// ComplexTest.cpp
// testing the class Complex that represents complex numbers
// demonstrates operators' overloading
//
#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    Complex c1; 
    cout << "Enter complex number  (for example 2 - 1i) :";
    cin >> c1;
    
    Complex c2(1.5, 2.5);
    
    // explicit casting of Complex to double
    double r1 = (double) c1;

    // implicit casting of Complex to double
    double r2 = c2;
    cout << "casting to double: r1 = " << r1 << " r2 = " << r2 << endl;


    // explicit casting of Complex to string
    string s1 = (string) c1;

    // implicit casting of Complex to string is not allowed
    // since the cast operator string() is defined as explicit
    // string s2 = c2; // ERROR ! implicit cast is not allowed
    cout << "casting to string: s1 = " << s1 << endl;


    // explicit casting of double to Complex
    // possible if one-argument Complex(double) constructor is defined 
    Complex c3 = (Complex)-3.0;
    Complex c4;
    c4 = (Complex)-4.0;

    // implicit casting of double to Complex 
    // possible if one-argument Complex(double) constructor is defined 
    // if the constructor is define as explicit, implicit
    // casting is prohibited
    // Complex c5 = 5.0;    // ERROR ! implicit casting is prohibited 
    Complex c6; 
    // c6 = 6.0;            // ERROR ! implicit casting is prohibited  

    cout << "explicit and implicit casting of double to Complex: " <<
            " c3 = " << c3 << " c4 = " << c4 << endl ;

    // testing overloaded operators 
    cout << "\ntesting overloaded operators :" << endl;
    cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
    cout << c1 << " - " << c2 << " = " << c1 - c2 << endl;
    cout << c1 << " * " << c2 << " = " << c1 * c2 << endl;
    cout << c1 << " / " << c2 << " = " << c1 / c2 << endl << endl;

    cout << "(" << c1 << " == " << c2 << ") =  " << (c1 == c2) << endl;
    cout << "(" << c1 << " != " << c2 << ") = " << (c1 != c2) << endl << endl;

    cout << "5.0 * " << c1 << " = " << 5.0 * c1 << endl;
    cout << c1 << " * 5.0" << " = " << c1 * 5.0 << endl << endl;

    
    cout << "Postfix ++ : " << "c1 = " << c1;
    cout << "   c1++ = " << c1++ << "   c1 = " << c1 << endl;

    cout << "Prefix ++ : " << "c1 = " << c1;
    cout << "   ++c1 = " << ++c1 << "   c1 = " << c1 << endl << endl;

    cout << "Postfix -- : " << "c1 = " << c1;
    cout << "   c1-- = " << c1-- << "   c1 = " << c1 << endl;

    cout << "Prefix -- : " << "c1 = " << c1;
    cout << "   --c1 = " << --c1 << "   c1 = " << c1 << endl << endl;

    return 0;
}
