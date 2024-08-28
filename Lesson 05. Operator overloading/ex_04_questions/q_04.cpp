#include <iostream>
class X {};
_____ operator<<(std::ostream &os, X x) { . . .}

void main() {
    X x;
    std::cout << x << x;
}
