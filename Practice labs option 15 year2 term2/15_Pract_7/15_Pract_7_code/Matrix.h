#pragma once
#include <iostream>
#include "MyExcp.h"

class Matrix
{
	int **mtrx;
	size_t m_size_columns;
	size_t m_size_rows;

public:
	Matrix(int **arr, size_t size_columns, size_t size_rows);
	Matrix(size_t size_columns, size_t size_rows);
	Matrix(const Matrix &other);
	void display() const;
	friend Matrix operator+(const Matrix &matr_first, const Matrix &matr_second);
	Matrix &operator=(const Matrix &other);
	void push(int elem, size_t columns, size_t rows);
	~Matrix();
};
