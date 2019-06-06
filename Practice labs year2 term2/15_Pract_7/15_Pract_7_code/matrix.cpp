#include "matrix.h"

Matrix operator+(const Matrix &m1, const Matrix &m2){
//    try{
    if (m1.colSize != m2.colSize || m1.rowSize != m2.rowSize)
        throw MatrixException("Sizes of matrixes are not equal");
//    }
//    }catch(std::logic_error e){
//        std::cout << e.what() << std::endl;
//    }

    Matrix m(m1.colSize, m1.rowSize);

    for (unsigned int i = 0; i < m1.colSize; ++i){
        for (unsigned int j = 0; j < m1.rowSize; ++j){
            m.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
        }
    }

    return m;
}

Matrix::Matrix(int **matrixC, unsigned int colSizeC, unsigned int rowSizeC):colSize(colSizeC),
                                                                        rowSize(rowSizeC){
    matrix = new int *[colSizeC];
    for (unsigned int i = 0; i < colSizeC; ++i){
        matrix[i] = new int[rowSizeC];
        for (unsigned int j = 0; j < rowSizeC; ++j){
            matrix[i][j] = matrixC[i][j];
        }
    }
}

Matrix::Matrix(unsigned int colSizeC, unsigned int rowSizeC) : colSize(colSizeC),
        rowSize(rowSizeC){
        matrix = new int *[colSize];
        for (unsigned int i = 0; i < colSize; ++i){
            matrix[i] = new int[rowSize];
         }
}

Matrix::Matrix(const Matrix &alien):colSize(alien.colSize),
                                    rowSize(alien.rowSize){
    matrix = new int *[colSize];
    for (unsigned int i = 0; i < colSize; ++i){
        matrix[i] = new int[rowSize];
        for (unsigned int j = 0; j < rowSize; ++j){
            matrix[i][j] = alien.matrix[i][j];
        }
    }
}

Matrix::~Matrix(){
    for (unsigned int i = 0; i < colSize; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;
}

Matrix &Matrix::operator=(const Matrix &alien){
    delete[] matrix;
    colSize = alien.colSize;
    rowSize = alien.rowSize;

    matrix = new int *[colSize];

    for (unsigned int i = 0; i < colSize; ++i){
        matrix[i] = new int[rowSize];
        for (unsigned int j = 0; j < rowSize; ++j){
            matrix[i][j] = alien.matrix[i][j];
        }
    }
    return *this;
}

void Matrix::add(int element, unsigned int colIndx, unsigned int rowIndx)
{
    if (colIndx >= colSize || rowIndx >= rowSize)
        throw MatrixException("subscript bounds violation");

    matrix[colIndx][rowIndx] = element;
}

void Matrix::printOut() const{
    for (unsigned int i = 0; i < colSize; ++i){
        for (unsigned int j = 0; j < rowSize; ++j){
            std::cout << this->matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
