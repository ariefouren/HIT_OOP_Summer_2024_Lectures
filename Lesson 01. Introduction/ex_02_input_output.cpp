// File: ex_02_input_output.cpp
// demonstrates basic input and output

#include <iostream>     // for cout, cin, endl
using namespace std;    // to avoid writing std::cout, std::cin, std::endl

int main() {
	int age;            // integer variable to store age
	char name[100];     // character array to store name
	cout << "Enter your name :";  
	cin >> name;        // input name from user and store it in variable name
	cout << "Enter your age :";
	cin >> age;         // input age from user and store it in variable age

	cout << "Hello, " << name << " !" << endl;          // output name
	cout << "you are " << age << " years old." << endl; // output age
	cout << "Bye !   :-) " << endl;                     // output bye message
}
