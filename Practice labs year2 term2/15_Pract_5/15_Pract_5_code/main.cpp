#include <iostream>
#include "fifo.h"
#include "fifo_funcs.h"

int main()
{
	Fifo<int> q;
	
	for (int i = 1; i <= 10; ++i)
	{
		q.pushBack(i);
	}
	q.show();

	for (int i = 1; i <= 10; ++i)
	{
		q.popFront();
	}
	q.show();

	q.pushBack(10);

	q.show();

	int i = q.getFront();
	//q.show();
	//std::cout << i << "\n";

	Fifo<int> q2(q);

	q2.show();

	q = q2;

	q.show();

	q.clear();
	q.show();

	Fifo<char> q1;

	for (int i = 65; i < 75; ++i)
	{
		q1.pushBack(i);
	}
	q1.show();

	for (int i = 1; i <= 10; ++i)
	{
		q1.popFront();
	}

	Fifo<double> q22;

	for (double i = 1; i <= 5; i+=0.5)
	{
		q22.pushBack(i);
	}
	q22.show();

	q22.clear();
	


	std::cin.get();
}
