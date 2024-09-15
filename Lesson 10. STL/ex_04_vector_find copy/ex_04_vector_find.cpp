#include <iostream>
#include <vector>
#include <algorithm> // for std::merge, std::sort
using namespace std;

bool pos_condition(int x)
{ 
    return  x > 0;
}

int main() {
    vector<int> v1 = {1, -2, 3, - 4, 5, -6, 7};
    
    ostream_iterator<int> out_it(cout, "\t"); 
    cout << "--- 0. Initial vector ---" << endl;
    cout << "v1: \t";   
    copy(v1.begin(), v1.end(), out_it);

    cout << endl << "--- 1. Find all positive elements ---" << endl;
    vector<int>::iterator it = find_if(v1.begin(), v1.end(), pos_condition);
    while(it != v1.end())
    {
        cout << "Found: " << *it << endl;
        it = find_if(++it, v1.end(), pos_condition);
    }
}