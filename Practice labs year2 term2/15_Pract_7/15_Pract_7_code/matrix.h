#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "matrixexception.h"

class Matrix
{
private:
    int **matrix;
    unsigned int colSize;
    unsigned int rowSize;
public:
    Matrix(int **arr, unsigned int colSizeC, unsigned int rowSizeC);
    Matrix(unsigned int colSizeC, unsigned int rowSizeC);
    Matrix(const Matrix&);
    ~Matrix();

    friend Matrix operator+(const Matrix&, const Matrix&);
    Matrix &operator=(const Matrix&);
    //friend Matrix operator=(const Matrix&, const Matrix&);
    void add(int element, unsigned int col, unsigned int row);


    void printOut() const;
};

//Matrix operator+(const Matrix&, const Matrix&);

#endif // MATRIX_H
