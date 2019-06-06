#pragma once
#include <exception>

class NumberException
{
	const char *msg;
public:
	NumberException(const char *msg);
	NumberException();
	char const *what() const throw();
};

