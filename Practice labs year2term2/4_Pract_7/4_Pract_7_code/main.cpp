#include <iostream>
#include "Number.h"
#include "NumberException.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int a, b;

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
	catch (std::exception ex)
	{
		cout << ex.what() << endl;
	}

	cout << "Input first number to be multiplied: ";

	cin >> a;

	cout << "Input second number to be multiplied: ";

	cin >> b;

	firstnum.set_number(a);
	secondnum.set_number(b);

	try
	{
		std::cout << firstnum * secondnum << endl;
	}
	catch (NumberException ex)
	{
		cout << ex.what() << endl;
	}

	system("pause");

	return 0;
}
