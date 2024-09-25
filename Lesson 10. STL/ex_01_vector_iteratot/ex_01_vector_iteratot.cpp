#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v; // create an empty vector of integers
    cout << "Size: " << v.size() << endl; // print the size of the vector
    cout << "Capacity: " << v.capacity() << endl; // print the capacity of the vector
    
    for (int i = 0; i < 10; i++) {
        v.push_back(i); // add elements to the end of the vector
    }

    cout << "Size: " << v.size() << endl; // print the size of the vector
    cout << "Capacity: " << v.capacity() << endl; // print the capacity of the vector
    cout << "Print the elements of the vector using iterator: " << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " "; // print the elements of the vector
    }
    cout << endl << endl;

    cout << "Print the elements of the vector in reverse order using reverse iterator: " << endl;
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
        cout << *it << " "; // print the elements of the vector in reverse order
    }
    cout << endl << endl;

    cout << "Print the elements of the vector using iterator arithmetic: " << endl;
    vector<int>::iterator it = v.begin();
      for(int i = 0; i < v.size(); i++) {
        cout << *(it + i) << " "; // print the elements of the vector using iterator arithmetic
    }

    cout << "Print the elements of the vector reverse iterator and iterator arithmetic: " << endl;
    vector<int>::reverse_iterator rit = v.rend(); // create a reverse iterator pointing to the element before the first element
    for(int i = 1; i <= v.size(); i++) {
        cout << *(rit - i) << " "; 
    }

    return 0; // exit the program
 
}