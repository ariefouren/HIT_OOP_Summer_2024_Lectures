// File: ex_08_map.cpp
// demonstrates the use of the map container
// from the STL library
#include <iostream>
#include <iomanip> 
#include <map>


using namespace std;

#define WIDTH 10

// map container stores elements in key-value pairs
// allows fast look-up of elements based on keys
// elements are stored in a sorted order based on keys
// duplicate keys are not allowed
// implemented as a balanced binary search tree

void printGrades(const map<string, double>& gradesBook){
    cout << left << setw(WIDTH) << "Name" << "Grade" << endl;
    cout << setfill('-') << setw(WIDTH + 5) << "" << endl;
    cout << setfill(' ');

    // in the range-based for loop, record is a pair of key and value
    // record is a copy of the element in the map
    // modifying record does not change the element in the map
    for (auto record: gradesBook){
        cout << left << setw(WIDTH) << 
        record.first << record.second << endl;
    }
}

// increase the grades that are in the range [low, high] by given number of points
void increaseGrades(map<string, double>& gradesBook, double low, double high, double points){
    // record is a reference to the element in the map
    // modifying record changes the element in the map
    for (auto& record: gradesBook){
        if (record.second >= low && record.second <= high){
            record.second += points;
        }
    }
}


int main(){
    

    map<string, double> gradesBook; // map container with string keys and double values
    // insert elements into the map
    // students' names are keys and their grades are values
    gradesBook["Alice"] = 90.0;
    gradesBook["Bob"] = 85.5;
    gradesBook["Charlie"] = 88.0;
    gradesBook["David"] = 57.5;
    gradesBook["Eve"] = 56.0;

    // print the grades
    printGrades(gradesBook);
 

    // increase Alice's grade by 5 points
    gradesBook["Alice"] += 5.0;
    cout << "\n\nafter increasing Alice's grade by 5 points:" << endl;
    printGrades(gradesBook);

    // increase the grades that are in the range [55, 60] by 5 points
    increaseGrades(gradesBook, 55, 60, 5);
    cout << "\n\nafter increasing the grades in the range [55, 60] by 5 points:" << endl;
    printGrades(gradesBook);


}