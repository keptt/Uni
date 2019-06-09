#pragma once
#include <string>
#include <cstring>

class MyExcp
{
	std::string err_rational;
public:
	MyExcp(std::string);
	std::string what() const;
};
