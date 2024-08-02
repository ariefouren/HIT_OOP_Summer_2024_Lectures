//
// File: ConstructAndDestruct.cpp     
// implementation of class ConstructAndDestruct that demonstrates 
// constructors and destructors
// adapted from P. Deitel, H. Deitel C++ How to Program
//
#include <string>
#include <iostream>
using namespace std;

#include "ConstructAndDestruct.h"

// constructor
ConstructAndDestruct::ConstructAndDestruct(int id, string msg)
	:objectId(id), message(msg)	// initialization list of the member variables
{
	cout << "object: " << objectId << " " 
		<< message << " constructor runs" << endl;
}

// destructor
ConstructAndDestruct::~ConstructAndDestruct()
{
	cout << "object: " << objectId << " "
		<< message << " destructor runs" << endl;
}
