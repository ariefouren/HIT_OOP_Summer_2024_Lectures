// File: ex_15_static_vars.cpp
#include <iostream>

void exampleFunction() {
    static int counter = 0; // Static local variable
    counter++;
    std::cout << "Counter: " << counter << std::endl;
}

int main() {
    exampleFunction(); // Output: Counter: 1
    exampleFunction(); // Output: Counter: 2
    exampleFunction(); // Output: Counter: 3
    return 0;
}
