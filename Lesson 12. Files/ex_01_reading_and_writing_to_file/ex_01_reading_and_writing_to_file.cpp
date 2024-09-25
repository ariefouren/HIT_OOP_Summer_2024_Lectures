// File: ex_01_reading_and_writing_to_file.cpp
// The program reads a text file,
// counts the number of words in the file 
// using  a map container from the STL, and saves the result to a CSV file.

#include <iostream>
#include <fstream> // for file I/O
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>  // for isalnum
#include <map>

using namespace std;

// Custom comparator function to compare <string, int> pairs by value (word count)
bool greaterThenByValue(const pair<string, int>& a, 
                    const pair<string, int>& b) {
    return a.second > b.second;  // Compare values
}

int main() {
    // Create a map to store the word count
    map<string, int> wordCount;

    // Open the input file
    // creates ifstream object associated with the file
    string filename = "Alice's Adventures in Wonderland";
    ifstream inputFile{filename + ".txt"};
    
    // Check if the file is open
    // note the overloaded operator! 
    // that checks if the file is successfully opened
    if(!inputFile) { 
        cerr << "Unable to open the file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    // Read the file line by line
    string line;
    // function getline defined in <iostream> reads one line from the file
    // and stores it in the string variable line
    // variable line does not include the end-of-line character (EOL)
    while (getline(inputFile, line)) {
        // Process each word in the line
        string word;
        for (char c : line) {
            // Check if the character is a letter or a digit
            // function isalnum defined in <cctype> 
            // checks if the character is a letter or a digit
            if (isalnum(c)) {
                // Convert the character to lowercase and append it to the word
                word += tolower(c);
            } 
            else {  // if the character is not a letter or a digit
                    // it is considered as a word separator

                // If the word is not empty, update the word count
                // using the subscript operator[] of the map
                if (!word.empty()) {
                    wordCount[word]++;
                    word.clear();  // function clear() defined in <string> clears the string
                }
            }
        }
        // Since the line variable does not include the end-of-line character (EOL)
        // the last word in the line is not processed in the loop
        // so we need to process it separately
        if (!word.empty()) {
            wordCount[word]++;
            word.clear();
        }
    }

    // Close the input file
    inputFile.close();

    // Create and open the output CSV file
    ofstream outputFile(filename + ".csv");

    // Check if the file is open
    if(!outputFile) {
        cerr << "Unable to open the file: " << filename << ".csv" << endl;
        exit(EXIT_FAILURE);
    }
    // Write the header to the CSV file
    outputFile << "Word,Count\n";

    // Write the word count data to the CSV file
    // note the range-based for loop with const reference to the pair
    for (const auto& pair : wordCount) {
        outputFile << pair.first << "," << pair.second << "\n";
    }

    // Close the output file
    outputFile.close();
    cout << "Word count saved to " << filename << ".csv!" << endl;

    // Sort the word count data by frequency in descending order
    // and save the sorted data to a new CSV file

    // copy the word count data to a vector of pairs
    vector<pair<string, int>> wordFrequencyVector(wordCount.begin(), wordCount.end());

    // sort the vector in descending order by frequency
    // using a custom comparator function compareByValue
    sort(wordFrequencyVector.begin(), wordFrequencyVector.end(), 
        greaterThenByValue); 

    // Create and open the output CSV file
    ofstream sortedOutputFile(filename + "_frequency_sorted.csv");
    if(!sortedOutputFile) {
        cerr << "Unable to open the file: " << filename << "_frequency_sorted.csv" << endl;
        exit(EXIT_FAILURE);
    }

    // store the sorted data in the CSV file
    sortedOutputFile << "Word,Count\n";
    for (const auto& pair : wordFrequencyVector) {
        sortedOutputFile << pair.first << "," << pair.second << "\n";
    }

    // Close the output file
    sortedOutputFile.close();
    cout << "Word count sorted by frequency saved to " << filename << "_frequency_sorted.csv!" << endl;

    return 0;
}