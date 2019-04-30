#pragma once
#include "ProxyBracketsHelper.h"
#include "ProxyBracketsHelperFuncs.h"
//#include "Matrix.h"

template<class Type>
class Matrix;

template<class Type>
Matrix<Type>& Matrix<Type>::make_clone(const Matrix<Type> &other)
{
	size_rows = other.size_rows;
	size_cols = other.size_cols;

	matrix = new Type *[size_cols];

	for (unsigned int i = 0; i < size_cols; ++i)
	{
		matrix[i] = new Type[size_rows];
		std::copy(other.matrix[i], other.matrix[i] + size_rows, matrix[i]);
	}

	return *this;
}

template<class Type>
Matrix<Type>::Matrix(unsigned int cols, unsigned int rows) : size_cols(cols), size_rows(rows)
{
	matrix = new Type *[size_cols];

	for (unsigned int i = 0; i < size_cols; ++i)
	{
		matrix[i] = new Type[size_rows];
		memset(matrix[i], 0, sizeof(Type) * size_rows);
	}
}

template<class Type>
Matrix<Type>::Matrix(const Matrix<Type> &other)
{
	make_clone(other);
}

template<class Type>
Matrix<Type>::~Matrix()
{
	for (unsigned int i = 0; i < size_cols; ++i)
	{
		delete [] matrix[i];
	}
	delete[] matrix;
}

template<class Type>
bool Matrix<Type>::add(unsigned int col, unsigned int row, Type data)
{
	if (col < size_cols && row < size_rows)
	{
		matrix[col][row] = data;
		return true;
	}
	
	return false;
}

template<class Type>
const Type ** Matrix<Type>::get_matrix_ptr() const
{
	return (const Type **)matrix;
}

template<class Type>
unsigned int Matrix<Type>::get_cols() const
{
	return size_cols;
}

template<class Type>
unsigned int Matrix<Type>::get_rows() const
{
	return size_rows;
}

template<class Type>
Matrix<Type> & Matrix<Type>::operator=(const Matrix<Type> &other)
{
	if (this != &other)
	{
		this->~Matrix();
		return make_clone(other);
	}

	return *this;
}

template<class Type>
ProxyBracketsHelper<Type> Matrix<Type>::operator[](unsigned int first_index)
{
	return ProxyBracketsHelper<Type>(this, first_index);
}

template<class Type>
std::ostream & operator<<(std::ostream &out, const Matrix<Type> &matrix_obj)
{
	for (unsigned int i = 0; i < matrix_obj.size_cols; ++i)
	{
		for (unsigned int j = 0; j < matrix_obj.size_rows; ++j)
		{
			out << matrix_obj.matrix[i][j] << ' ';
		}
		out << (i == matrix_obj.size_cols - 1 ? '\0' : '\n');
	}

	return out;
}