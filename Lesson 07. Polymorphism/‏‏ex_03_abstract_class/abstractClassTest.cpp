//
// File: abstractClassTest.cpp	
// Demonstrates the use of abstract classes and pure virtual functions
//   
 
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace std;

int main()
{
	// Pointers and inheritance 
	// with static binding, the type of the function invoked 
	// depends on the type of the pointer, not on the type of the object 
	cout << "--- 1.Static binding: the type of the function invoked depends on the type of the pointer" << endl << endl; 

	Shape* shapePtr = new Shape(0, 0);
	cout << "after shapePtr = new Shape(0, 0);" << endl;
	cout << "shapePtr->toString() = " << shapePtr->toString() << endl;

	Circle* circlePrt = new Circle(1, 1, 10);
	cout << "after circlePrt = new Circle(1, 1, 10);" << endl;
	cout << "circlePrt->toString() = " << circlePrt->toString() << endl;

	shapePtr = circlePrt;	// Allowed since each circle is a shape
	cout << "after shapePtr = circlePrt;" << endl;
	cout << "shapePtr->toString() = " << shapePtr->toString() << endl;

	// circlePrt = shapePtr;			// ERROR ! not each shape is circle
	circlePrt = (Circle*) shapePtr;	// Dangerous ! May cause run-time  error 

	cout << "circlePrt->setR(10) is OK provided that shapePtr points to a Circle object" << endl;
	circlePrt->setR(10);


	// Assignments of the base and the derived classes
	cout << endl << endl << "--- 2. Assignments of the base and the derived classes" << endl << endl;
	Shape shape1(0, 0);
	Circle circle1(1, 1, 10);
	shape1 = circle1;  // performs Shape::operator=(Shape& ) const
			// warning: slicing
	cout << "after shape1 = circle1;" << endl;
	cout << "shape1.toString() =" << shape1.toString() << endl;

	// circle1 = shape1;	// ERROR ! no operator Circle = Shape is defined
			// since not all the members of Circle can be set 
			// using the members of Shape 
	
	
	cout << endl << endl << "--- 3. Array of pointers to Shape, static binding" << endl << endl;
	int numOfShapes = 3;
	Shape* *shapesArr = new Shape*[numOfShapes]; // array of pointers to Shape
	shapesArr[0] = new Shape(0, 0);
	shapesArr[1] = new Circle(1, 1, 1);
	shapesArr[2] = new Rectangle(2, 2, 2, 2);

	for (int i = 0; i < numOfShapes; i++)
	{
		cout << "shapesArr[" << i << "]->toString() = " << shapesArr[i]->toString() << endl;
		
		Shape& shapeRef = *shapesArr[i];
		cout << "shapeRef.toString() =      " << shapeRef.toString() << endl << endl;
	}

}
