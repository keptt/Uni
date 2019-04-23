#include <iostream>
#include "Menu.h"
#include "vector"

class A
{

};

class B : public A
{
	int b;
};

class C : public A
{
	double c;
};


int main()
{
	std::vector<A *> vec;

	vec.push_back(new B);

	vec.push_back(new C);
	
	for (const auto atom : vec)
	{
		if (typeid(*atom) == typeid(B))
		{
			std::cout << "I am B\n";
		}
		else if (typeid(*atom) == typeid(C))
		{
			std::cout << "I am C\n";
		}
		else
		{
			std::cout << "I am GODKNOWSWHAT\n";
		}
	}


	//PriorityQueue pq;
	
	//Menu::menu().run();

	//pq.push_back('a', 1);
	//pq.push_back('a', 2);
	//pq.push_back('a', 3);
	//pq.push_back('b', 5);
	//pq.push_back('b', 6);
	//pq.push_back('z', 8);
	//pq.push_back('y', 7);
	//pq.push_back('c', 4);


	//std::cout << pq.pop_front() << std::endl;
	//std::cout << pq.pop_front() << std::endl;
	//std::cout << pq.pop_front() << std::endl;
	//std::cout << pq.pop_front() << std::endl;
	//std::cout << pq.pop_front() << std::endl;
	//std::cout << pq.pop_front() << std::endl;
	//std::cout << pq.pop_front() << std::endl;
	//std::cout << pq.pop_front() << std::endl;

	//pq.clear();

	getchar();

	return 0;
}

