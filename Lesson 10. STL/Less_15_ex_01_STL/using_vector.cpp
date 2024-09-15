#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Step 1: Define vector<int> numbers, initially empty
    vector<int> numbers;

    // Print the size and capacity of the vector "numbers"
    cout << "Size of numbers: " << numbers.size() << endl;
    cout << "Capacity of numbers: " << numbers.capacity() << endl;

    // Step 2: Add 10 integers 0..9 to vector "numbers" using push_back()
    for (int i = 0; i < 10; ++i) {
        numbers.push_back(i);
    }

    // Print the size and capacity of the vector "numbers" after adding elements
    cout << "Size of numbers: " << numbers.size() << endl;
    cout << "Capacity of numbers: " << numbers.capacity() << endl;

    // Print elements using iterator after adding
    cout << "Elements in numbers after adding:";
    for (vector<int>::iterator it = numbers.begin(); 
        it != numbers.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;

    // Step 3: Compute and print the sum of elements in "numbers" 
    // using a for loop and vector<int>::iterator
    int sum1 = 0;
    for (vector<int>::iterator it = numbers.begin(); 
        it != numbers.end(); ++it) {
        sum1 += *it;
    }
    cout << "Sum of elements using iterator: " << sum1 << endl;

    // Step 4: Print the elements in "numbers" using a while loop 
    // and vector<int>::reverse_iterator
    cout << "Elements in numbers in reverse order, using reverse_iterator : ";
    vector<int>::reverse_iterator rit = numbers.rbegin(); 
    while(rit != numbers.rend()) {
        cout << *rit <<" ";
        ++rit;
    }
    cout << endl;
    return 0;
}
