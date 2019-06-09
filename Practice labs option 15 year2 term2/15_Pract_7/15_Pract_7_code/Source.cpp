#include "matrix.h"
#include <iostream>

int main()
{

	int temp;


	Matrix matr_first_ft(3, 3);
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			std::cout << "Input val for matr: ";
			std::cin >> temp;
			matr_first_ft.push(temp, i, j);
		}
	}

	matr_first_ft.display();
	std::cout << "\n";
	Matrix matr_second_ft(3, 3);
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			std::cout << "Input val for matr:";
			std::cin >> temp;
			matr_second_ft.push(temp, i, j);
		}
	}

	matr_second_ft.display();

	std::cout << "addition of first and second matr: ";
	try
	{
		matr_first_ft = matr_first_ft + matr_second_ft;
		matr_first_ft.display();
	}
	catch (const MyExcp &e) 
	{
		std::cout << e.what() << std::endl;
	}

	Matrix matr_first(3, 3);
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			std::cout << "Input val for matr: ";
			std::cin >> temp;
			matr_first.push(temp, i, j);
		}
	}

	matr_first.display();
	std::cout << std::endl;
	Matrix matr_second(3, 2);
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 2; ++j)
		{
			std::cout << "Input val for matr:";
			std::cin >> temp;
			matr_second.push(temp, i, j);
		}
	}

	matr_second.display();
	std::cout << std::endl;
	std::cout << "addition of first and second matr: ";
	try 
	{
		matr_first = matr_first + matr_second;
		matr_first.display();
	}
	catch (const MyExcp &e) 
	{
		std::cout << e.what() << std::endl;
	}




	std::cin.get();
	std::cin.get();
	return 0;
}
