// File: matrix.h
// definition of the matrix class
// demonstrating dynamic memory allocation
//
#include <iostream>

class Matrix {
    public:
        Matrix(int rows, int cols); // constructor, for: Matrix m(2, 3);
        Matrix(const Matrix &m);    // copy constructor, for: Matrix m2 = m1;
        ~Matrix();                  // destructor

        Matrix &operator=(const Matrix &m); // assignment operator, for: m1 = m2;

        // access the individual elements
        double get(int row, int col) const; // for: m1.get(1, 2);
        void set(int row, int col, double value); // for: m1.set(1, 2, 3.0);
        
        // print the matrix
        void print() const; // for: m1.print();

        Matrix transpose() const; // return the transpose of the matrix, for: m1.transpose()
             
        int getRows() const;    // return the number of rows
        int getCols() const;    // return the number of columns

    private:
        int rows;   // number of rows
        int cols;   // number of columns
        double **data;  // pointer to the data
};
    
