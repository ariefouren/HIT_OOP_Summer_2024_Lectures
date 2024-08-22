//
// Complex.cpp
// implementation of the class Complex that represents complex numbers
// demonstrates operators' overloading
//
#include <iostream>
#include <string>
#include <sstream> //for std::ostringstream - printing complex numbers to string
#include "Complex.h"
using namespace std;

Complex::Complex(double re, double imaginary)
    : real(re), imaginary(imaginary) {}


// Cast operator to convert Complex to double (real part)
Complex::operator double() const {
    return this->real;
}

// explicit cast operator to convert Complex to string
#include <iomanip> // Add this line to include the <iomanip> header file

Complex::operator string() const
{
    ostringstream oss;
    oss << fixed << setprecision(2); // Set 2 decimal places 

    oss << "(" << real 
        << (imaginary >= 0 ? " + " : " - ") // Add '+' if imaginary part is positive, else add '-'
        << abs(imaginary) << "i)";  // Add the imaginary part
    return oss.str(); // Return the string
    
}

// Overloading + operator for Complex + Complex
Complex Complex::operator+(const Complex& other) const {
    return Complex(this->real + other.real, this->imaginary + other.imaginary);
}

// Overloading - operator for Complex - Complex
Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imaginary - other.imaginary);
}

// Overloading * operator for Complex * Complex
Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imaginary * other.imaginary,
        real * other.imaginary + imaginary * other.real);
}

// Overloading == operator for Complex == Complex
bool Complex::operator==(const Complex& other) const {
    return (real == other.real) && (imaginary == other.imaginary);
}

// Overloading != operator for Complex != Complex
bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// Overloading + operator for Complex + Real
Complex Complex::operator+(const double& realNum) const {
    return Complex(real + realNum, imaginary);
}

// Overloading - operator for Complex - Real
Complex Complex::operator-(const double& realNum) const {
    return Complex(real - realNum, imaginary);
}

// Overloading * operator for Complex * Real
Complex Complex::operator*(const double& realNum) const {
    return Complex(real * realNum, imaginary * realNum);
}

// Overloading + operator for Real + Complex
Complex operator+(const double& realNum, const Complex& complex) {
    return complex + realNum; // Reuse the already defined operator
}

// Overloading - operator for Real - Complex
Complex operator-(const double& realNum, const Complex& complex) {
    return Complex(realNum - complex.real, -complex.imaginary);
}

// Overloading * operator for Real * Complex
Complex operator*(const double& realNum, const Complex& complex) {
    return complex * realNum; // Reuse the already defined operator
}

// Function to get the real part of the complex number
double Complex::getReal() const {
    return real;
}

// Function to get the imaginary part of the complex number
double Complex::getImaginary() const {
    return imaginary;
}

// Overloading / operator for Complex / Complex
Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    double realPart = (real * other.real + imaginary * other.imaginary) / denominator;
    double imagPart = (imaginary * other.real - real * other.imaginary) / denominator;
    return Complex(realPart, imagPart);
}

// Overloading / operator for Complex / Real
Complex Complex::operator/(const double& realNum) const {
    return Complex(real / realNum, imaginary / realNum);
}

// Overloading / operator for Real / Complex
Complex operator/(const double& realNum, const Complex& complex) {
    double denominator = complex.real * complex.real + complex.imaginary * complex.imaginary;
    double realPart = (realNum * complex.real) / denominator;
    double imagPart = (-realNum * complex.imaginary) / denominator;
    return Complex(realPart, imagPart);
}

// Prefix ++ operator affecting the real part only
Complex& Complex::operator++() {
    ++real;
    return *this;
}

// Postfix ++ operator affecting the real part only
Complex Complex::operator++(int) {
    Complex temp(*this);
    ++real;
    return temp;
}



// Postfix -- operator affecting the real part only (friend function)
Complex operator--(Complex& complex, int) {
    Complex temp(complex);
    complex.real--;
    return temp;
}

// Prefix -- operator affecting the real part only (friend function)
Complex& operator--(Complex& complex) {
    --complex.real;
    return complex;
}
// Overloading << operator for printing complex numbers
ostream& operator<<(ostream& os, const Complex& complex) {
    os << (string) complex;
    return os;
}

istream& operator>>(std::istream& is, Complex& complex) {
    char sign;
    is >> complex.real;
    is >> sign;
    if (sign == '+') {
        is >> complex.imaginary;
    }
    else if (sign == '-') {
        is >> complex.imaginary;
        complex.imaginary = -complex.imaginary;
    }
    else {
        is.setstate(std::ios::failbit);
        return is;
    }
    if (is.peek() == 'i') // Check for 'i' at the end
        is.ignore(); // Ignore 'i' character if present
    return is;
}
