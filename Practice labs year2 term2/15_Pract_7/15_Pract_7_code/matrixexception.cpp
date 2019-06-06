#include "matrixexception.h"

const char *MatrixException::what() const noexcept
{
    return msg;
}

MatrixException::MatrixException(const char *s)
{
    msg = s;//(const) nonconst_msg = const_s???? what then?
}
