#include <iostream>
#include <vector>
#include <algorithm> // for std::merge, std::sort
using namespace std;

// Condition object to find positive elements
class GreaterOrEqualCondition
{
public:
    GreaterOrEqualCondition(int min_value) : min_value(min_value) {}
    virtual bool operator()(int x) {
        return x >= min_value;
    }
private:
    int min_value;
};



int main() {
    vector<int> v1 = {1, -2, 3, - 4, 5, -6, 7};
    
    ostream_iterator<int> out_it(cout, "\t"); 
    cout << "--- 0. Initial vector ---" << endl;
    cout << "v1: \t";   
    copy(v1.begin(), v1.end(), out_it);

    cout << endl << "--- 1. Find all positive elements using conditional object with operator() ---" << endl;
    
    vector<int>::iterator it = find_if(v1.begin(), v1.end(), 
            GreaterOrEqualCondition(0));
    while(it != v1.end())
    {
        cout << "Found: " << *it << endl;
        it = find_if(++it, v1.end(), GreaterOrEqualCondition(0));
    }
    cout << endl << endl;

    cout << "--- 2. Remove all positive elements using conditional object and remove_if---" << endl;
    cout << "v1: \t";
    copy(v1.begin(), v1.end(), out_it);
    cout << endl << endl;

    // remove_if does not remove elements from the vector, it just moves them to the end
    // and returns an iterator pointing to the first element that was not removed
    vector<int>::iterator it2 = remove_if(v1.begin(), v1.end(), GreaterOrEqualCondition(0));
    cout << "after remove_if(v1.begin(), v1.end(), GreaterOrEqualCondition(0))" << endl;
    cout << "v1: \t";
    copy(v1.begin(), v1.end(), out_it);
    cout << endl << endl;

    // We can then use the erase method to remove the elements from the vector
    v1.erase(it2, v1.end());
    cout << "after v1.erase(it2, v1.end())" << endl;
    cout << "v1: \t";
    copy(v1.begin(), v1.end(), out_it);

}