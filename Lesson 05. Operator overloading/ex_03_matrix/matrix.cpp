// File: matrix.cpp
// implementation of the matrix class

#include "matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

#define WIDTH 8 // the width of the output field for setw()

// constructor
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
Matrix::~Matrix() {
    // deallocate memory for each row
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    // deallocate memory for the array of pointers to rows
    delete[] data;
}

// assignment operator
Matrix &Matrix::operator=(const Matrix &m) {
    // check for self-assignment
    if (this == &m) {   // if the address of the source matrix is the same as this
                        // nothing to do, just return this
        return *this;
    }
    // if the dimensions are different, delete the old data (like in the destructor)
    // and allocate new data with the dimensions of the source matrix m
    // (like in the copy constructor)
    if (rows != m.rows || cols != m.cols) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        rows = m.rows;
        cols = m.cols;
        data = new double*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];
        }
    }
    // copy the elements of the source matrix m to this matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = m.data[i][j];
        }
    }
    return *this;
}

// access the element at the given row and column
// using the overloaded operator()
// (non-const version)
double &Matrix::operator()(int row, int col) {
    return data[row][col];
}

// access the element at the given row and column
// using the overloaded operator()
// (const version)
double Matrix::operator()(int row, int col) const {
    return data[row][col];
}

// output operator
std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            os << std::setw(WIDTH) << m(i, j);  // note the use of operator()(int, int) 
                                                // for future compatibility
        }
        os << std::endl;
    }
    return os;
}

// transpose
Matrix Matrix::transpose() const {
    // create a new matrix with the dimensions of this matrix swapped
    Matrix result(cols, rows);
    // copy each element m(i, j) to result(j, i)
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            result(i, j) = data[j][i];
        }
    }
    // return the result matrix by value (creates a copy)
    return result;
}

// scalar multiplication
Matrix operator*(double scalar, const Matrix &m) {
    // create a new matrix with the same dimensions as m
    // to store the result
    Matrix result(m.getRows(), m.getCols());
    // multiply each element of m by the scalar
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            result(i, j) = scalar * m(i, j);
        }
    }
    // return the new matrix by value (creates a copy)
    return result;
}

// matrix addition
Matrix Matrix::operator+(const Matrix &m) const {
    // check if the matrices have the same dimensions
    if (rows != m.rows || cols != m.cols) {
        cerr << "Matrix dimensions do not match." << endl;
        exit(1); // terminate the program
    }
    // create a new matrix with the same dimensions as this matrix (and as m) to store the result
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // each element of the result is the sum of the corresponding elements
            // of the two matrices
            result(i, j) = data[i][j] + m(i, j);
        }
    }
    // return the new matrix by value (creates a copy)
    return result;
}

// matrix multiplication
Matrix Matrix::operator*(const Matrix &m) const {
    // check if the matrices can be multiplied
    if (cols != m.rows) {
        cerr << "Matrix dimensions do not match." << endl;
        exit(1); // terminate the program
    }
    // create a new matrix with this->rows and m.cols to store the result
    Matrix result(rows, m.cols);
    // each element result(i, j) is the dot product of the i-th row of this matrix
    // and the j-th column of m
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            for (int k = 0; k < cols; k++) {
                result(i, j) += data[i][k] * m(k, j);
            }
        }
    }
    return result;  // return the new matrix by value (creates a copy)
}

// equality operator
bool Matrix::operator==(const Matrix &m) const {
    // check if the matrices have the same dimensions
    // and if all the elements are equal
    if (rows != m.rows || cols != m.cols) {
        return false;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (data[i][j] != m.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// inequality operator
bool Matrix::operator!=(const Matrix &m) const {
    // note the use of the equality operator
    return !(*this == m);
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
