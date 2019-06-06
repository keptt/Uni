#include "NumberException.h"



NumberException::NumberException(const char * msg): msg(msg)
{
}

NumberException::NumberException(): msg("Undefined exception")
{
}

char const * NumberException::what() const throw()
{
	return msg;
}

