//
// ex_11_variables.cpp
// variables can be declared in any place in the code
// 
#include <iostream>
using namespace std;

int main() {
	double height;
	double width;
	cout << "Enter the rectangle's height:";
	cin >> height;
	cout << "Enter the rectangle's width :";
	cin >> width;

	double area = height * width; // note that variables can be declared in any place in the code
	cout << "The rectangle's area is     : " << area << endl;	
}
