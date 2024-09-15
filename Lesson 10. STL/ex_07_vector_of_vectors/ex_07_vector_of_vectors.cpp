#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


int main(){
    vector<vector<int>> m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ostream_iterator<int> out_it(cout, "\t");
    cout << "Initial matrix: \n";
    for(auto row : m){
        copy(row.begin(), row.end(), out_it);
        cout << endl;
    }
    cout << endl;

    cout << "--- 1. Exchange rows 1 and 2: \n";
    swap(m[0], m[1]); 
    cout << "Matrix after swap(m[0], m[1]): \n";
    for(auto row : m){
        copy(row.begin(), row.end(), out_it);
        cout << endl;
    }
    cout << endl;

    cout << "--- 2. Add row 1 multiplied by 2 to row 2: \n";
    for(int i = 0; i < m[0].size(); i++){
        m[1][i] += 2 * m[0][i];
    }
    cout << "Matrix after adding row 1 multiplied by 2 to row 2: \n";
    for(auto row : m){
        copy(row.begin(), row.end(), out_it);
        cout << endl;
    }

    cout << "--- 3. Multiply the matrix by -2: \n";
    for(auto& row : m){
        for(auto& elem : row){
            elem *= -2;
        }
    }
}