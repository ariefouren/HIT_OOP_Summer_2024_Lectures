#include <iostream>     // for cout
#include <exception>

using namespace std;

// Demonstrates custom function to handle new failures

// custom new exception handler
void my_new_handler() {
    cout << "my_new_handler: out of memory" << endl;
    exit(EXIT_FAILURE); // terminate the program  with an error code
}

int main() {
    // set my_new_handler as the handler for new failures
    // set_new_handler is a function from <new> header
    // that sets the new handler function to be called
    // when operator new fails to allocate memory
    set_new_handler(my_new_handler);

    // try to allocate a large blocks of memory
    for (int i = 0; i < 100; i++) {
        new int[50'000'000]; // allocate 50 million ints
        cout << "step " << i << "\t: successfully allocated 50 million ints" << endl;
    }
}