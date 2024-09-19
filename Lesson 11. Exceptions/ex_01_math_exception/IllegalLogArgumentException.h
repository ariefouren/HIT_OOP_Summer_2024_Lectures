#include <stdexcept>    // for runtime_error
using namespace std;

// functions that detect illegal arguments to the log function
// should throw an IllegalLogArgumentException
class IllegalLogArgumentException : public runtime_error {
public:
    // call the base class constructor with the error message
    IllegalLogArgumentException() : runtime_error("Illegal log argument") {}
};
