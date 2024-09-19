#include <iostream>     // for cout
#include <exception>
using namespace std;

// function that throws an exception, catches it, and rethrows again
void RethrowException() {
    try {
        // throw an exception
        cout << "\nFunction RethrowException throws an exception " << endl;
        throw (runtime_error{"--- exception thrown in RethrowException ---"}); // throw an exception};
    }
    catch (exception& e) {
        cout << "Function RethrowException catches an exception: " << 
            e.what() << " and tries to handle it" << endl;

        // rethrow the exception
        cout << "Function RethrowException rethrows the exception\n" << endl;
        throw;
    }
}

int main() {
    try {
        cout << "Function main() calls RethrowException" << endl;
        RethrowException();
    }
    catch (exception& e) {
        cout << "Function main() catches an exception: " << 
            e.what() << " and handles it" << endl;
    }
    return 0;
}