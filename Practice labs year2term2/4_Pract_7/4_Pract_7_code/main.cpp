#include <iostream>
#include "Number.h"
#include "NumberException.h"

#define TIMES 2

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int a, b;

	for (int i = TIMES; i > 0; i--)
	{
		cout << "Input first number to be multiplied: ";

		cin >> a;

		cout << "Input second number to be multiplied: ";

		cin >> b;

		Number firstnum(a);									//cin>>...

		Number secondnum(b);

		try
		{
			std::cout << firstnum * secondnum << endl;
		}
		catch (const NumberException &ex)
		{
			cout << ex.what() << endl;
		}
	}

	system("pause");

	return 0;
}
