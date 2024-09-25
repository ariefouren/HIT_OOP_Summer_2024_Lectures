// File: ex_02_vector_element_manip.cpp
// demonstrates how to manipulate elements of a vector

#include <iostream>
# include <vector> // #include <algorithms>
#include <iterator> // for ostream_iterator
using namespace std;

int main() {
    cout << "Vector element manipulation" << endl << endl;
    cout << "--- 1. Creating a vector of integers ---" << endl;
    vector<int> v1 = {1, 2, 3, 4, 5, 6}; // create a vector of integers with 5 elements
    vector<int> v2(v1.cbegin()+1, v1.cend()-2); // create a vector of integers with some of the elements of v1
    // v2 = {2, 3, 4}
    // create an ostream_iterator for printing, `\t`` is the separator
    ostream_iterator<int> out_it(cout, "\t"); 
    cout << "v1: ";
    copy(v1.begin(), v1.end(), out_it); // print the elements of v1 using the ostream_iterator
    cout << endl << endl;

    cout << "v2: ";
    copy(v2.begin(), v2.end(), out_it); // print the elements of v2 using the ostream_iterator
    cout << endl << endl;

    cout << "--- 2. Accessing elements of a vector ---" << endl;
    cout << "v1.front(): " << v1.front() << endl; // print the first element of v1
    cout << "v1.back(): " << v1.back() << endl; // print the last element of v1
    cout << endl << endl;

    cout << "--- 3. Modifying elements of a vector ---" << endl;    
    v1[0] = 10; // modify the first element of v1
    v1.at(1) = 20; // modify the second element of v1
    v1.insert(v1.begin()+2, 30); // insert 30 at the third position of v1
    v1.insert(v1.end()-1, 40); // insert 40 at the second last position of v1
    v1.push_back(50); // insert 50 at the last position of v1
    cout << "after v1.[0] = 10,\n" << 
    "v1.at(1) = 20, \n" <<
    "v1.insert(v1.begin()+2, 30), \n" <<
    "v1.insert(v1.end()-1, 40), \n" <<
    "v1.push_back(50): \n";
    cout << "v1: ";
    copy(v1.begin(), v1.end(), out_it); // print the elements of v1 using the ostream_iterator
    cout << endl << endl;

    cout << "--- 3.1 Accessing out of range elements ---" << endl;
    // try to access an element that is out of range
    try {
        cout << endl << "v1.at(100): " << v1.at(100) << endl; // try to access the 100th element of v1
    } 
    catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << endl; // print the exception message
    }

    cout << endl << "--- 4. Erasing elements of a vector ---" << endl;
    v1.erase(v1.begin()+1); // erase the second element of v1
    cout << "after v1.erase(v1.begin()+1): " << endl;
    cout << "v1: ";
    copy(v1.begin(), v1.end(), out_it); // print the elements of v1 using the ostream_iterator
    cout << endl << endl;

    v1.erase(v1.begin(), v1.end() - 2); // erase all elements except the last two
    cout << "after v1.erase(v1.begin(), v1.end() - 2): " << endl;
    cout << "v1: ";
    copy(v1.begin(), v1.end(), out_it); // print the elements of v1 using the ostream_iterator
    cout << endl << endl;

    v1.erase(v1.begin(), v1.end()); // erase all elements
    cout << "after v1.erase(v1.begin(), v1.end()): ";
    copy(v1.begin(), v1.end(), out_it); // print the elements of v1 using the ostream_iterator
    cout << endl << endl;

    cout << endl << "--- 5. Insert elements from another vector ---" << endl;
    v1 = {1, 2, 3, 4, 5}; // reset v1
    v2 = {10, 20, 30}; // reset v2
    v1.insert(v1.begin(), v2.begin(), v2.end()); // insert all elements of v2 at the beginning of v1
    // v1 = {10, 20, 30, 1, 2, 3, 4, 5} 
    cout << "after v1.insert(v1.begin(), v2.begin(), v2.end()): " << endl;
    cout << "v1: ";
    copy(v1.begin(), v1.end(), out_it); // print the elements of v1 using the ostream_iterator
    cout << endl << endl;

    cout << endl << "--- 6. Clearing a vector ---" << endl;
    cout << "v1: ";
    copy(v1.begin(), v1.end(), out_it); // print the elements of v1 using the ostream_iterator
    cout << endl << endl;
    cout << "is v1 empty? " << (v1.empty() ? "yes" : "no") << endl; // check if v1 is empty

    v1.clear(); // clear all elements of v1
    cout << "after v1.clear(): " << endl;
    cout << "v1: ";
    copy(v1.begin(), v1.end(), out_it); // print the elements of v1 using the ostream_iterator
    cout << endl ;
    cout << "is v1 empty? " << (v1.empty() ? "yes" : "no") << endl; // check if v1 is empty

}
