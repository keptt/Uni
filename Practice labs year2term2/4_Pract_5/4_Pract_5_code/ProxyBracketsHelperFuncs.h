#include "ProxyBracketsHelper.h"

template<class Type>
ProxyBracketsHelper<Type>::ProxyBracketsHelper(Matrix<Type> *host, unsigned int first_index) : host(host), first_index(first_index)
{
}

template<class Type>
Type & ProxyBracketsHelper<Type>::operator[](unsigned int second_index)
{
	return const_cast<Type **>(host->get_matrix_ptr())[first_index][second_index];
}
