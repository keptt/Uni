#pragma once
#include "Matrix.h"

template<class Type>
class ProxyBracketsHelper
{
	Matrix<Type> *host;
	size_t first_index;
public:
	ProxyBracketsHelper(Matrix<Type> *host, unsigned int first_index);
	Type &operator[](unsigned int second_index);
};
