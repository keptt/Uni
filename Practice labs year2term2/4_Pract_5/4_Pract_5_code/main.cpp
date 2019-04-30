#include "Matrix.h"
#include "MatrixFuncs.h"

int main()
{
	Matrix<int> m;

	m.add(0, 0, 1);
	m.add(0, 1, 1);
	m.add(0, 2, 1);
	m.add(1, 0, 1);
	m.add(1, 1, 1);
	m.add(1, 2, 1);
	m.add(2, 0, 1);
	m.add(2, 1, 1);
	//m.add(2, 2, 1);

	m[0][0] = 2;

	std::cout << m[2][2] << std::endl;

	std::cout << m << "\n" << std::endl;

	Matrix<int> m1(1, 1);
	m1.add(0, 0, 1);

	m = m1;

	std::cout << m << "\n" << std::endl;

	Matrix<int> m3(m);

	std::cout << m3 << "\n" << std::endl;

	Matrix<double> m_d(2, 2);
	m_d.add(0, 0, 1.5);
	m_d.add(0, 1, 1.5);
	m_d.add(1, 0, 1.5);

	std::cout << m_d << "\n" << std::endl;

	Matrix<float> m_f(2, 2);
	m_f.add(0, 0, 1.5f);
	m_f.add(0, 1, 1.5f);
	m_f.add(1, 0, 1.5f);

	std::cout << m_f << "\n" << std::endl;

	Matrix<char> m_c(2, 2);//
	m_c.add(0, 0, 'a');
	m_c.add(0, 1, 'a');
	m_c.add(1, 0, 'a');
	
	std::cout << m_c << std::endl;

	std::cin.get();

	return 0;
}
