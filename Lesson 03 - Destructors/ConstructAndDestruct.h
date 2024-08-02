#pragma once	
//
// ConstructAndDestruct.h     
// definition of class ConstructAndDestruct that demonstrates 
// constructors and destructors
// adapted from P. Deitel, H. Deitel C++ How to Program
//
#include <string>
using namespace std;

class ConstructAndDestruct
{
public:
	ConstructAndDestruct(int id, string msg);
	~ConstructAndDestruct();
	
private:
	int objectId; 
	string message;
};
