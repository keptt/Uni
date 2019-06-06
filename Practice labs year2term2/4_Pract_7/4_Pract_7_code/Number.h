#pragma once
#include <iostream>

class Number
{
	int number;
public:
	Number();
	Number(int number);

	Number operator*(Number second);

	int get_number() const;
	void set_number(const int number);

	friend std::ostream &operator<<(std::ostream &out, const Number &n);
};

