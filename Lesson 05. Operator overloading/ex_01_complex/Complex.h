//
// Complex.h
// definition of the class Complex that represents complex numbers
// demonstrates operators' overloading
//
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Complex {
    // Overloading >> operator
    friend std::istream& operator>>(std::istream& is, Complex& complex);

    // Postfix -- operator affecting the real part only
    friend Complex operator--(Complex& complex, int);

    // Prefix -- operator affecting the real part only (friend function)
    friend Complex& operator--(Complex& complex);

    // Overloading + operator for Real + Complex
    friend Complex operator+(const double& realNum, const Complex& complex);

    // Overloading - operator for Real - Complex
    friend Complex operator-(const double& realNum, const Complex& complex);

    // Overloading * operator for Real * Complex
    friend Complex operator*(const double& realNum, const Complex& complex);

    // Overloading / operator for Real / Complex
    friend Complex operator/(const double& realNum, const Complex& complex);

public:
    // the constructor is defined as explicit
    // to prevent implicit cast
   explicit Complex(double re = 0.0, double imaginary = 0.0);

    // Overloading + operator for Complex + Complex
    Complex operator+(const Complex& other) const;
    
    // Overloading - operator for Complex - Complex
    Complex operator-(const Complex& other) const;

    // Overloading * operator for Complex * Complex
    Complex operator*(const Complex& other) const;
    
    // Overloading == operator for Complex == Complex
    bool operator==(const Complex& other) const;
    
    // Overloading != operator for Complex != Complex
    bool operator!=(const Complex& other) const;
    
    // Overloading + operator for Complex + Real
    Complex operator+(const double& realNum) const;
    
    // Overloading - operator for Complex - Real
    Complex operator-(const double& realNum) const;
    
    // Overloading * operator for Complex * Real
    Complex operator*(const double& realNum) const;
    
    // Overloading / operator for Complex / Complex
    Complex operator/(const Complex& other) const;

    // Overloading / operator for Complex / Real
    Complex operator/(const double& realNum) const;
 
    // Postfix ++ operator affecting the real part only
    Complex operator++(int);

    // Prefix ++ operator affecting the real part only
    Complex& operator++();

    // Cast operator to convert Complex to double (real part)
    operator double() const;

    // Cast operator to convert Complex to string
    explicit operator string() const;
            
    // Function to get the real part of the complex number
    double getReal() const;
    
    // Function to get the imaginary part of the complex number
    double getImaginary() const; 

private:
        double real;
        double imaginary;
};

// Overloading << operator for printing complex numbers
ostream& operator<<(std::ostream& os, const Complex& complex);
