#include <iostream>     // for cout
#include <exception>
using namespace std;

// Demonstrates constructor that throws an exception
// to indicate that the object cannot be created
// Constructor can't return a value, so the best way
// to indicate that the object can't be created is to throw an exception
class Array {
    public:
        // constructor
        Array(int n): size(n) {
            cout << "Array constructor: " << endl;
            if (n <= 0) {
                throw invalid_argument("Array size must be positive");
            }
            // try to allocate memory
            try {
                data = new int[size];
            } 
            catch (bad_alloc& e) {
                cout << "Array constructor: exception occurred: " <<
                e.what() << endl;
                cout << "Array constructor: throwing invalid_argument" << endl;
                throw invalid_argument("Array size too large");
            }
            
        }

        // destructor
        ~Array() {
            cout << "Array destructor" << endl;
            delete[] data;
        }
    private:
        int* data;
        int size;
};

int main() {
    cout<< "--- 1. Trying to create an array with a negative size ---" << endl;
    try {
        cout << "main: try Array a(-1);" << endl;
        Array a(-1);
    } catch (exception& e) {
        cout << "main: Exception: " << e.what() << endl;
    }

    cout << "--- 2. Trying to create an array with a large size ---" << endl;
    try {
        cout << "main: try Array b(1'000'000'000);" << endl; 
        Array b(1'000'000'000);
    } catch (exception& e) {
        cout << "main: Exception: " << e.what() << endl;
    }
    
    return 0;
}