#include <string.h>
#include "matrixexception.h"

const char *MatrixException::what() const noexcept
{
    return msg;
}

MatrixException::MatrixException(const char *s) : msg(s ? new char[strlen(s) + 1] : nullptr)
{
    strcpy(msg, s);
}
MatrixException::~MatrixException()
{
    delete[] msg;
}
