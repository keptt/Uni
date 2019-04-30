#pragma once
#include <iostream>

template <class Type>
class ProxyBracketsHelper;

template<class Type>
class Matrix
{
	unsigned int size_rows;
	unsigned int size_cols;
	Type **matrix;
	Matrix<Type> &make_clone(const Matrix<Type> &);

public:
	//Matrix();
	Matrix(unsigned int cols = 3, unsigned int rows = 3);
	Matrix(const Matrix<Type> &);
	~Matrix();

	bool add(unsigned int col, unsigned int row, Type data);
	
	const Type** get_matrix_ptr() const;
	unsigned int get_cols() const;
	unsigned int get_rows() const;

	Matrix<Type> &operator=(const Matrix<Type> &);
	ProxyBracketsHelper<Type> operator[](unsigned int first_index);

	template<class Type>
	friend std::ostream&operator<<(std::ostream &, const Matrix<Type> &);
};
