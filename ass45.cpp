//45.	Write a class Matrix which will store elements of integer matrix
// (two dimensional array) in dynamically allocated space.
// Provide below functions in matrix class -
//1. Default constructor - Take 3 as default row and column size.
// Initialize the matrix elements to 0
//2. Parameterized constructor - Takes row and column size as parameters.
// Initialize matrix to 0.
//3. Copy constructor - Performs deep copy of matrix object.
//4. Destructor - Deletes memory which is allocated dynamically.

//5. Overloaded + operator - Performs addition of two matrices.
//6. Overloaded !operator - Calculates transpose of a user entered square matrix.
//7. Overload >> -Accepts row & column size from user.Also accepts matrix elements from user.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Matrix {
    int row;
    int col;
    int** arr;
public:
    Matrix();
    Matrix(int r, int c);
    Matrix(Matrix& m); 
    ~Matrix();
    void accept();
    void display();
    Matrix operator+(Matrix&);
    Matrix operator!();
};

Matrix::Matrix(){
    row = 3;
    col = 3;
    arr = new int* [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++) {
            arr[i][j] = 0;
        }
    }
}

Matrix::Matrix(int r, int c) {
    row =r;
    col= c;
    arr = new int* [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++) {
            arr[i][j] = 25; 
        }
    }
}

Matrix::Matrix(Matrix& m){
    row = m.row; 
    col = m.col;
    arr = new int* [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++) {
            arr[i][j] = m.arr[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    //cout << "Destructor" << endl;
}

void Matrix::accept() {
    cout << "Enter the " << row << " by " << col << " Matrix Element" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }
}

void Matrix::display() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::operator+(Matrix& m) {
    Matrix temp(row, col); 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp.arr[i][j] = arr[i][j] + m.arr[i][j];
        }
    }
    return temp;
}

Matrix Matrix::operator!() {
    if (row != col) {
        cout << "Error:" << endl;
        return *this;
    }
    Matrix temp(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp.arr[j][i] = arr[i][j];
        }
    }
    return temp;
}

int main() {
    Matrix m1;
    Matrix m2(3, 3);
    Matrix m3;

    m1.accept();
    m2.display();

    cout << "Addition" << endl;
    Matrix m4;
    m4 = m1 + m2;
    m4.display();
    
    cout << "transpose" << endl;
    m2 =! m1;
    m2.display();
    return 0;
}