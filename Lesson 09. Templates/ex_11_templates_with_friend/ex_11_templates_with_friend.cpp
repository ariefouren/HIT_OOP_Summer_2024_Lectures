#include <iostream>
using namespace std;

// defines class template Matrix<T> with a friend operator*
template <class T>
class Matrix {
   // friend operator* template for scalar * matrix operation
        // operator*<U> is friend of Matrix<T> for any U
        template <class U>
        friend Matrix<U> operator*(const U scalar, const Matrix<U>& m2);
        
    /*    
        // friend operator* template for matrix * scalar operation
        // operator*<T> is friend of Matrix<T> only
        // parameter T here is the same s the class template parameter T
        friend Matrix<T> operator* <>(const T scalar, const Matrix<T>& m2);
    */

        // operator*(const bool scalar, const Matrix<int>& m2) is a regular function
        // is friend of Matrix<T> for any T
        friend Matrix<bool> operator* (const bool scalar, const Matrix<int>& m2);

        // friend operator<< for output
        // operator<<(ostream&, const Matrix<T>&) is friend of Matrix<T> for any T
        template <class U>
        friend ostream& operator<<(ostream& os, const Matrix<U>& m);

    public:
        Matrix(int rows, int cols);
        Matrix(const Matrix<T>& m); // copy constructor
        ~Matrix();
        T& operator()(int i, int j); // access element (i,j)
        const T& operator()(int i, int j) const; // access element (i,j) for const objects
        
     
    private:
        T** data;
        int rows;
        int cols;
};

template <class T>
Matrix<T>::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    data = new T*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new T[cols];
    }
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& m) {
    rows = m.rows;
    cols = m.cols;
    data = new T*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new T[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = m.data[i][j];
        }
    }
}

template <class T>
const T&  Matrix<T>::operator()(int i, int j) const {
    return data[i][j];
}

template <class T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

template <class T>
T& Matrix<T>::operator()(int i, int j) {
    return data[i][j];
}

template <class T>
Matrix<T> operator*(const T scalar, const Matrix<T>& m2) {
    Matrix<T> result(m2.rows, m2.cols);
    for (int i = 0; i < m2.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            result(i, j) = scalar * m2(i, j);            
        }
    }
    return result;
}

// regular function
Matrix<bool> operator* (const bool scalar, const Matrix<int>& m2) {
    Matrix<bool> result(m2.rows, m2.cols);
    for (int i = 0; i < m2.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            result(i, j) = scalar * m2(i, j);
        }
    }
    return result;
}

template <class T>
ostream& operator<<(ostream& os, const Matrix<T>& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            os << m(i, j) << " ";
        }
        os << endl;
    }
    return os;
}

int main() {
    Matrix<double> m(2, 2);
    m(0, 0) = 1.0;
    m(0, 1) = 2.0;
    m(1, 0) = 3.0;
    m(1, 1) = 4.0;
    cout << "m:" << endl << m << endl;

    Matrix<double> m2 = 0.5 * m;
    cout << "m2:" << endl << m2 << endl;

    Matrix<int> m3(2, 2);
    m3(0, 0) = 1;
    m3(0, 1) = 0;
    m3(1, 0) = 0;
    m3(1, 1) = 4;
    cout << "m3:" << endl << m3 << endl;

    Matrix<bool> m4 = true * m3;
    cout << "true * m3:" << endl << m4 << endl;

    return 0;
}




    
