#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void print(const vector<T>& vect)
{
    // Print elements, size, and capacity of vect
    for(T num : vect) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Size : " << vect.size() << endl;
    cout << "Capacity : " << vect.capacity() << endl;
};

int main() {
    // Step 1: Create vector numbers1 with values {0,..., 9}
    vector<int> numbers1(10);
    for (int i = 0; i < 10; ++i) {
        numbers1[ i ] = i; // note access using overloaded operator[]
    }

    // Step 2: Print elements, size, and capacity of numbers1
    // using function template
    cout << "Elements of vector : ";
    print(numbers1);
        
    // Step 3: Set numbers1[5] equal to 0 using overloaded operator[]
    numbers1[5] = 0; // without bounds checking

    // Step 4: Set numbers1[5] equal to 0 using function at()
    numbers1.at(5) = 0; // performs bounds checking. 
                        // If the index is out of bounds, 
                        // it throws an std::out_of_range exception, 
                        // which we can catch and handle.

    // Step 5.1: Insert (-1) to numbers1 as 1st element using insert()
    numbers1.insert(numbers1.begin(), -1);
    cout << "Elements of numbers1 after numbers1.insert(numbers1.begin(), -1);  : ";
    print(numbers1);

    // Step 5.2: Insert 5 copies of (-1) to numbers1 as 3rd element using insert()
    // note the use of pointer arithmetics
    numbers1.insert(numbers1.begin() + 2, 5, -1); 
    // Print elements, size, and capacity of numbers1 after modifications
    cout << "Elements of numbers1 after numbers1.insert(numbers1.begin() + 2, 5, -1);  : ";
    print(numbers1);

    // Step 5.3: Insert a range of elements 
    // from one vector to another
    // note the use of pointer arithmetics
    vector<int> numbers2;
    for (int i = 0; i < 10; i++) numbers2.push_back(100 * (i+1));
    cout << "Elements of numbers2: ";
    print(numbers2);
    numbers1.insert(numbers1.begin(), numbers2.begin()+3, numbers2.end()-2);
    cout << "Elements of numbers1 after numbers1.insert(numbers1.begin(), numbers2.begin() + 3, numbers2.end() - 2);  : ";
    print(numbers1);

    // Step 7: Try to insert 0 at position 2000 using at(),  
    // catch exception
    cout << "Try to insert 0 at position 2000 using at(): ";
    try {
        numbers1.at(2000) = 0;
    }
    catch (const out_of_range& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    // Step 8: Erase the 1st element of numbers1 using erase()
    numbers1.erase(numbers1.begin());

    // Step 9: Print elements, size, and capacity of numbers1 after erasing
    cout << "Elements of numbers1 after numbers1.erase(numbers1.begin()) : ";
    print(numbers1);

    // Step 10: Erase all elements of numbers1 using erase() and iterator
    numbers1.erase(numbers1.begin(), numbers1.end());

    // Step 12: Clear numbers1 using clear()
    numbers1.clear();

    // Print elements, size, and capacity of numbers1 after clearing
    cout << "Elements of numbers1 after clearing: ";
    print(numbers1);
    
    return 0;
}
