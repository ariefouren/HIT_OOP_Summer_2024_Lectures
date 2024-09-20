#include <iostream>
#include <fstream>
#include <vector>

int main() {
    // 2D array (or vector of vectors) to be written to CSV
    std::vector<std::vector<int>> array = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Create and open a CSV file
    std::ofstream file("output.csv");

    // Check if the file is open
    if (file.is_open()) {
        // Iterate over rows
        for (const auto& row : array) {
            // Iterate over columns in each row
            for (size_t i = 0; i < row.size(); ++i) {
                file << row[i];
                // Add a comma after every element except the last one
                if (i < row.size() - 1) {
                    file << ",";
                }
            }
            // Add a newline after each row
            file << "\n";
        }
        // Close the file
        file.close();
        std::cout << "Array saved to output.csv!" << std::endl;
    } else {
        std::cerr << "Unable to open the file!" << std::endl;
    }

    return 0;
}
