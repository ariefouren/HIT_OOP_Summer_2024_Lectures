// File: ex_03_vector_sort_and_merge.cpp
// Demonstrates sorting and merging two vectors using 
// <algorithm> functions
#include <iostream>
#include <vector>
#include <algorithm> // for std::merge, std::sort
using namespace std;

int main() {
    vector<int> v1 = {1, -2, 3, - 4, 5, -6, 7};
    vector<int> v2 = {-5, 6, -3, 2, 7, 1 };

    ostream_iterator<int> out_it(cout, "\t"); 
    cout << "--- 0. Initial vectors ---" << endl;
    cout << "v1: \t";
    copy(v1.begin(), v1.end(), out_it);
    cout << endl << endl;

    cout << "v2: \t";
    copy(v2.begin(), v2.end(), out_it);
    cout << endl << endl;

    cout << "--- 1. Sorting a vector using sort() from <algorithm> ---" << endl;
    // by default, sort() uses operator< to compare elements
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    cout << "after sort(v1.begin(), v1.end()): " << endl;
    cout << "v1: \t";
    copy(v1.begin(), v1.end(), out_it);
    cout << endl << endl;

    cout << "after sort(v2.begin(), v2.end()): " << endl;
    cout << "v2: \t"; 
    copy(v2.begin(), v2.end(), out_it);
    cout << endl << endl;

    cout << "--- 2. Merging two sorted vectors using merge() from <algorithm> ---" << endl;    
    vector<int> v3(v1.size() + v2.size());
    // Merge v1 and v2 into v3
    // merge() requires the input ranges to be sorted
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << "after merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin()): " << endl;
    cout << "v3: \t";
    copy(v3.begin(), v3.end(), out_it);
    cout << endl << endl;

    cout << "--- 3. Sorting a vector in descending order using greater<int>() ---" << endl;
    // sort in descending order using greater<int>() as a comparison function
    sort(v3.begin(), v3.end(), greater<int>());
    cout << "after sort(v3.begin(), v3.end(), greater<int>()): " << endl;
    cout << "v3: \t";
    copy(v3.begin(), v3.end(), out_it);

    return 0;
}
