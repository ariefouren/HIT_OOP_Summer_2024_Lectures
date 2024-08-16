// File: matrix.cpp
// implementation of the matrix class
// demonstrates dynamic memory allocation
//
#include "matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

#define WIDTH 8 // the width of the output field for setw()

// constructor
// creates a matrix with the given number of rows and columns
// and initializes all elements to zero
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    // dynamically allocate memory for the array of pointers to rows
    data = new double*[rows];
    // for each row, dynamically allocate memory for the array of elements
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        // initialize the elements of the row to zero
        for (int j = 0; j < cols; j++) {
            data[i][j] = 0.0;
        }
    }
}

//copy constructor
// creates a copy of the source matrix m
// using dynamic memory allocation
Matrix::Matrix(const Matrix &m) : rows(m.rows), cols(m.cols) {
    // dynamically allocate memory for the array of pointers to rows
    data = new double*[rows];
    // for each row, dynamically allocate memory for the array of elements
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        // copy the elements of the row from the source matrix m
        for (int j = 0; j < cols; j++) {
            data[i][j] = m.data[i][j];
        }
    }
}

// destructor
// deallocate dynamically allocated memory
Matrix::~Matrix() {
    // deallocate memory for each row
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    // deallocate memory for the array of pointers to rows
    delete[] data;
}



// access the element at the given row and column
double Matrix::get(int row, int col) const {
    return data[row][col];
}


// set the element at the given row and column
void Matrix::set(int row, int col, double value) {
    data[row][col] = value;
}

// print the matrix
void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << std::setw(WIDTH) << data[i][j];
        }
        cout << endl;
    }
}


// transpose
Matrix Matrix::transpose() const {
    // create a new matrix with the dimensions of this matrix swapped
    Matrix result(cols, rows);
    // copy each element m(i, j) to result(j, i)
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            result.set(i, j,  data[j][i]); // set the element at row i, column j
            // of the transposed matrix to the element at row j, column i of this matrix
        }
    }
    // return the result matrix by value (creates a copy)
    return result;
}


// get the number of rows
int Matrix::getRows() const {
    return rows;
}

// get the number of columns
int Matrix::getCols() const {
    return cols;
}

// end of matrix.cpp
