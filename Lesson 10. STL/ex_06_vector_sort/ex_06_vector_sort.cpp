#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class CompareByLength{
public:
    bool operator()(string s1, string s2){
        return s1.length() < s2.length();
    }
};

class CompareLexigraphically{
public:
    bool operator()(string s1, string s2){
        return s1 < s2;
    }
};

int main(){
    vector<string> v = {"zero", "one", "two", "three", "four", "five"};
    ostream_iterator<string> out_it(cout, "\n");
    cout << "Initial vector: \n";
    copy(v.begin(), v.end(), out_it);
    cout << endl;

    cout << "--- 1. Sorting by length: \n";
    sort(v.begin(), v.end(), CompareByLength());
    copy(v.begin(), v.end(), out_it);
    cout << endl;

    cout << "--- 2. Sorting lexigraphically: \n";
    sort(v.begin(), v.end(), CompareLexigraphically());
    copy(v.begin(), v.end(), out_it);
    cout << endl;

    cout << "--- 3. Sorting lexicographically in reverse order: \n";
    sort(v.begin(), v.end(), greater<string>());
    copy(v.begin(), v.end(), out_it);
    cout << endl;
}