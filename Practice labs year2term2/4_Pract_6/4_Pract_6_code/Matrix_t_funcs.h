#pragma once
#include "Matrix_t.h"
#include "ProxyBracketsHelper.h"
#include "ProxyBracketsHelperFuncs.h"
template<class Type>
class Matrix;

template<class Type>
Matrix<Type>::Matrix(unsigned int cols, unsigned int rows) : size_cols(cols), size_rows(rows)
{
	matrix.resize(cols);
	
	for (auto &i : matrix)
	{
		i.resize(rows);
	}
}

template<class Type>
bool Matrix<Type>::add(unsigned int col, unsigned int row, Type data)
{
	if (matrix.size() && col < matrix.size() && row < matrix[0].size())
	{
		matrix[col][row] = data;
		return true;
	}

	return false;
}

template<class Type>
unsigned int Matrix<Type>::get_cols() const
{
	return matrix.size();
}

template<class Type>
unsigned int Matrix<Type>::get_rows() const
{
	if (matrix.size() > 0)
		return matrix[0].size();
	return 0;
}

template<class Type>
ProxyBracketsHelper<Type> Matrix<Type>::operator[](unsigned int first_index)
{
	return ProxyBracketsHelper<Type>(this, first_index);
}

template<class Type>
std::ostream & operator<<(std::ostream &out, const Matrix<Type> &matrix_obj)
{
	for (const auto &i : matrix_obj.matrix)
	{
		for (const auto &j : i)
		{
			out << j << ' ';
		}
		out << '\n';
	}

	return out;
}
