#pragma once
#include <exception>

class NumberException
{
	char *msg;
public:
	NumberException(const char *msg);
	NumberException();
	NumberException();
	~NumberException() = delete;
	NumberException &operator=(const NumberException &other) = delete;
	char const *what() const throw();
};

