#include "IllegalLogArgumentException.h"
#include <iostream>     // for cout
#include <cmath>        // for log
using namespace std;

// the Log function calculates the natural logarithm of a number
// if the number is less than or equal to zero, it throws an IllegalLogArgumentException
double Log(double x) {
    if (x <= 0) {
        throw IllegalLogArgumentException();
    }
    return log(x);
}

int main() {
    double xValues[] = {1.0, 0.0, -1.0, 2.0};
    // calculate the natural logarithm of each value in the array
    for (double x : xValues) {
        try {
            double result = Log(x);
            cout << "log(" << x << ") = " << result << std::endl;
        } 
        catch (IllegalLogArgumentException& e) {
            // what() is a member function of the runtime_error class
            // that returns the error message
            cout << "Caught an IllegalLogArgumentException: " << e.what() << std::endl;
        }
    }
}