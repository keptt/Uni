#include "Matrix.h"

Matrix::Matrix(int **matrix, size_t size_columns, size_t size_row) : m_size_columns(size_columns), m_size_rows(size_row)
{
	matrix = new int *[size_columns];
	for (size_t i = 0; i < size_columns; ++i)
	{
		matrix[i] = new int[size_row];
		for (size_t j = 0; j < size_row; ++j)
		{
			matrix[i][j] = matrix[i][j];
		}
	}
}

Matrix operator+(const Matrix &first_matr, const Matrix &second_matr) 
{
	if (first_matr.m_size_columns != second_matr.m_size_columns || first_matr.m_size_rows != second_matr.m_size_rows)
		throw MatrixException("Sizes of matrixes mismatch");

	Matrix m(first_matr.m_size_columns, first_matr.m_size_rows);
	for (size_t i = 0; i < first_matr.m_size_columns; ++i) 
	{
		for (size_t j = 0; j < first_matr.m_size_rows; ++j) 
		{
			m.mtrx[i][j] = first_matr.mtrx[i][j] + second_matr.mtrx[i][j];
		}
	}
	return m;
}

Matrix::Matrix(size_t size_columns, size_t size_rows) : m_size_columns(size_columns), m_size_rows(size_rows) 
{
	mtrx = new int *[m_size_columns];
	for (size_t i = 0; i < m_size_columns; ++i)
	{
		mtrx[i] = new int[m_size_rows];
	}
}

Matrix::Matrix(const Matrix &alien) : m_size_columns(alien.m_size_columns), m_size_rows(alien.m_size_rows) 
{
	mtrx = new int *[m_size_columns];
	for (unsigned int i = 0; i < m_size_columns; ++i) 
	{
		mtrx[i] = new int[m_size_rows];
		for (size_t j = 0; j < m_size_rows; ++j) 
		{
			mtrx[i][j] = alien.mtrx[i][j];
		}
	}
}

void Matrix::display() const
{
	for (size_t i = 0; i < m_size_columns; ++i)
	{
		for (size_t j = 0; j < m_size_rows; ++j)
		{
			std::cout << this->mtrx[i][j] << " ";
		}
		std::cout << "\n";
	}
}

Matrix &Matrix::operator=(const Matrix &other) 
{
	delete[] mtrx;
	m_size_rows = other.m_size_rows;
	m_size_columns = other.m_size_columns;

	mtrx = new int *[m_size_columns];

	for (unsigned int i = 0; i < m_size_columns; ++i) 
	{
		mtrx[i] = new int[m_size_rows];
		for (unsigned int j = 0; j < m_size_rows; ++j) 
		{
			mtrx[i][j] = other.mtrx[i][j];
		}
	}
	return *this;
}

void Matrix::push(int element, size_t indx_columns, size_t indx_row)
{
	if (indx_columns >= m_size_columns || indx_row >= m_size_rows)
		throw MatrixException("wrong index was provided");
	mtrx[indx_columns][indx_row] = element;
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < m_size_columns; ++i)
	{
		delete[] mtrx[i];
	}
	delete[] mtrx;
}
