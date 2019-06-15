#include "NumberException.h"
#pragma warning(disable: 4996)

#include <cstring>

NumberException::NumberException(const char * msg): msg(new char[strlen(msg) + 1])
{
	strcpy(this->msg, msg);
}

NumberException::NumberException(): msg(new char[strlen("Undefined exception") + 1])
{
	strcpy(this->msg, "Undefined exception");
}

char const * NumberException::what() const throw()
{
	return msg;
}

NumberException::~NumberException()
{
	delete[] msg;
}