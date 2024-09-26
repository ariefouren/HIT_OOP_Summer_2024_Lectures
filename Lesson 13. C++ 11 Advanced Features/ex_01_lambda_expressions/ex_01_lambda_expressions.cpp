// File: ex_01_lambda_expressions.cpp
// demonstrates lambda expressions (C++ 11)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

// in C++ 11, lambda expressions allow to define anonymous functions
// that can be passed as arguments to functions
// lambda expressions are defined using the following syntax:
// [capture clause] (parameters) -> return_type { body }
// capture clause is used to capture variables from the enclosing scope
// parameters are the parameters of the lambda function
// return_type (optional) is the return type of the lambda function

int main() {
    // create a vector of strings and sort it using a lambda expression
    vector<string> words = {"a", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};

    // define a lambda expression that prints a vector of strings
    auto print_vector = [](const vector<string>& v) {
        for (const string& s : v) {
            cout << s << endl;
        }
        cout << endl;
    };

    // print the original vector using the lambda expression
    cout << "Original vector:" << endl;
    print_vector(words);

    // sort the vector lexically using a lambda expression
    sort(words.begin(), words.end(), 
        [](const string& a, const string& b) {
        return a < b;
    });

    // print the sorted vector using the lambda expression
    cout << "Vector sorted lexicographically:" << endl;
    print_vector(words);

    // sort the vector by string length using a lambda expression
    sort(words.begin(), words.end(), 
        [](const string& a, const string& b) {
        return a.size() < b.size();
    });

    // print the sorted vector using the lambda expression
    cout << "Vector sorted by string length:" << endl;
    print_vector(words);

    // convert the vector to uppercase using a lambda expression
    for_each(words.begin(), words.end(), 
        [](string& s) {
        transform(s.begin(), s.end(), s.begin(), toupper);
    });

    // print the uppercase vector using the lambda expression
    cout << "Vector converted to uppercase:" << endl;
    print_vector(words);

    // count the number of appearances of each character in the vector
    // using map and a lambda expression
    // define a map to store the character counts
    map<char, int> char_counts;
    for_each(words.begin(), words.end(), 
        [&char_counts](const string& s) {  // capture char_counts by reference
                                            // to make it accessible inside the lambda expression
        for (char c : s) {
            char_counts[c]++;
        }
    });

    // print the character counts using the lambda expression
    cout << "Character counts:" << endl;
    for_each(char_counts.begin(), char_counts.end(), 
        [](const pair<char, int>& p) {
        cout << p.first << ": " << p.second << endl;
    });

    return 0;
}