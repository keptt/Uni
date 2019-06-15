#ifndef MATRIXEXCEPTION_H
#define MATRIXEXCEPTION_H
#include <exception>
#include <cstring>
#include <string>

class MatrixException : public std::exception
{
private:
    const char *msg;
public:
    MatrixException(const char *);
    MatrixException(const MatrixException &) = delete;
    MatrixException &operator=(const MatrixException &) = delete;
    ~MatrixException();
    const char*what() const noexcept;
};

#endif // MATRIXEXCEPTION_H
