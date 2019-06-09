#include "Number.h"
#include "NumberException.h"
#include <limits>

Number::Number()
{
}

Number::Number(int number) : number(number)
{
}

Number Number::operator*(Number second)
{
	if (abs(number) > abs(INT_MAX / second.number))
	{
		throw NumberException("integer overflow");
	}
	return number * second.number;
}

int Number::get_number() const
{
	return 0;
}

void Number::set_number(const int number)
{
	Number::number = number;
}

std::ostream & operator<<(std::ostream & out, const Number & n)
{
	out << n.number;

	return out;
}
