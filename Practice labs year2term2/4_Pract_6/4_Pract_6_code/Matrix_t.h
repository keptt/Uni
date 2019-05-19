#pragma once
#include <iostream>
#include <vector>

template <class Type>
class ProxyBracketsHelper;

template<class Type>
class Matrix
{
	unsigned int size_rows;
	unsigned int size_cols;

	friend class ProxyBracketsHelper<Type>;
	std::vector<std::vector<Type>> matrix;

public:
	Matrix(unsigned int cols = 3, unsigned int rows = 3);
	Matrix(const Matrix<Type> &) = default;
	~Matrix() = default;

	bool add(unsigned int col, unsigned int row, Type data);

	unsigned int get_cols() const;
	unsigned int get_rows() const;

	Matrix<Type> &operator=(const Matrix<Type> &) = default;
	ProxyBracketsHelper<Type> operator[](unsigned int first_index);

	template<class Type>
	friend std::ostream&operator<<(std::ostream &, const Matrix<Type> &);
};

