#include "matrix.h"
#include <iostream>
#include <vector>

int main()
{
	bool ok = false;
	int temp;
	size_t n, m;
	const size_t pair = 2;

	while (!ok)
	{
		std::vector<Matrix> mv;
		mv.reserve(2);
		for (size_t i = 0; i < pair; ++i)
		{

			std::cout << "Input m: ";
			std::cin >> m;
			std::cout << "Input n: ";
			std::cin >> n;
			Matrix matr_ft(m, n);
			for (size_t j = 0; j < m; ++j)
			{
				for (size_t k = 0; k < n; ++k)
				{
					std::cout << "Input val for matr: ";
					std::cin >> temp;
					matr_ft.push(temp, j, k);
				}
			}
			matr_ft.display();
			std::cout << "\n";
			mv.push_back(matr_ft);
		}

		Matrix matr_res(*mv.cbegin());
		for (std::vector<Matrix>::const_iterator it = ++mv.cbegin(); it != mv.cend(); ++it)
		{
			try
			{
				matr_res = matr_res + *it;
				ok = true;
			}
			catch (const MyExcp &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		if (ok)
		{
			matr_res.display();
		}
	}
	
	std::cin.get();
	std::cin.get();
	return 0;
}
