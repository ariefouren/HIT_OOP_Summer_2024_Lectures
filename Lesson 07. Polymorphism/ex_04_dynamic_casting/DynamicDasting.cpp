//
// DynamicCastingTest.cpp
// Testing dynamic casting and virtual destructors
//   
#include <typeinfo> // for operator typeid and class type_info
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace std;

int main()
{
	
	int numOfShapes = 3;
	Shape* *shapesArr = new Shape*[numOfShapes]; // array of pointers to Shape
	shapesArr[0] = new Circle(0, 0, 12);
	shapesArr[1] = new Circle(1, 1, 1);
	shapesArr[2] = new Rectangle(2, 2, 2, 2);
	
	for (int i = 0; i < numOfShapes; i++)
	{
		// display the object' type using operator typeid
		cout << "typeid(*shapesArr[" << i<< "]).name() = " 
			<< typeid(*shapesArr[i]).name() << endl;

		// demonstrate dynamic casting
		Circle* circlePtr = dynamic_cast<Circle*>(shapesArr[i]);
		if (circlePtr != nullptr) // dynamic casting to (Circle*) succeeded
		{
			cout << "dynamic casting of shapesArr[" << i << "] "
				<< "to (Circle*) succeeded.\n"
				<< "Call circlePtr->setR(50)\n";
			circlePtr->setR(50);
			cout << circlePtr->toString() << endl << endl;
		}
		else // dynamic casting to (Circle*)  failed
		{
			cout << "dynamic casting of shapesArr[" << i << "] "
				<< "to (Circle*) failed :( \n";
			cout << "shapesArr[" << i << "]->toString() = "
				<< shapesArr[i]->toString() << endl << endl;
		}
	}

	cout << "\n\ndemonstrating virtual destructors\n";
	for (int i = 0; i < numOfShapes; i++)
	{
		cout << "delete shapesArr[" << i << "] : ";
		delete shapesArr[i];
	}
}