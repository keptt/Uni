#include <iostream>
#include "queue.hpp"
#include "queue_methods.hpp"

#define LOOP_NUMBER 10

int main()
{
    Queue<int> q;

    Queue<int> q2(q);

    std::cout << q2 << std::endl;

    for (size_t i = 0; i < LOOP_NUMBER; ++i)
    {
        q.push_back(static_cast<int>(i));
    }

    std::cout << q << std::endl;

    std::cout << "q is empty: " << q.is_empty() << std::endl;

    for (size_t i = 0; i <= LOOP_NUMBER; ++i)
    {
        q.erase_front();
    }

    std::cout << q << std::endl;

    q.clear();

    std::cout << q << std::endl;

    std::cout << "q is empty: " << q.is_empty() << std::endl;

    Queue<short> qs;
    Queue<long long> qll;
    Queue<float> qf;
    Queue<double> qd;
    Queue<bool> qb;
    Queue<char> qc;

    return 0;
}
