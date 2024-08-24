// File: matrix.h
// definition of the matrix class
#include <iostream>

class Matrix {
    public:
        Matrix(int rows, int cols); // constructor, for: Matrix m(2, 3);
        Matrix(const Matrix &m);    // copy constructor, for: Matrix m2 = m1;
        ~Matrix();                  // destructor

        Matrix &operator=(const Matrix &m); // assignment operator, for: m1 = m2;

        // access the individual elements
        // using overloaded operator()
        double &operator()(int row, int col); // for: m(1, 2) = 3.0 
        double operator()(int row, int col) const; // for: double x = m(1, 2)
        
        // print the matrix
        friend std::ostream &operator<<(std::ostream &os, const Matrix &m); // for cout << m1;
        
        Matrix transpose() const; // return the transpose of the matrix, for: m1.transpose()

        // the following operators return a new matrix by value
        friend Matrix operator*(double scalar, const Matrix &m); // scalar * matrix, for: 2.0 * m  
        Matrix operator+(const Matrix &m) const; // matrix addition, for: m1 + m2
        Matrix operator*(const Matrix &m) const; // matrix multiplication, for: m1 * m2
                
        // comparison operators return true or false
        bool operator==(const Matrix &m) const; // for: m1 == m2
        bool operator!=(const Matrix &m) const; // for: m1 != m2
        
        int getRows() const;    // return the number of rows
        int getCols() const;    // return the number of columns

    private:
        int rows;   // number of rows
        int cols;   // number of columns
        double **data;  // pointer to the data
};
    
