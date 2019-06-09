#include "MyExcp.h"


MyExcp::MyExcp(std::string s)
{
	err_rational = s;
}

std::string MyExcp::what() const
{
	return err_rational;
}
