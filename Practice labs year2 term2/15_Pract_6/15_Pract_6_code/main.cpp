#include <iostream>
#include "FifoFunc.h"
#include "Fifo.h"

using namespace std;

int main()
{
    Fifo<int> q;

    for (int i = 1; i <= 10; ++i)
    {
        q.pushBack(i);
    }

    cout << q << endl;

    for (int i = 1; i <= 10; ++i)
    {
        q.popFront();
    }
    cout << q << endl;

    q.pushBack(10);

    cout << q << endl;

    int i = q.getFront();
    std::cout << "first elem: " << i << "\n";

    Fifo<int> q2(q);

    cout << q2 << endl;

    q = q2;

    cout << q << endl;

    q.clear();
    cout << q << endl;

    Fifo<char> q1;

    for (int i = 65; i < 75; ++i)
    {
        q1.pushBack(i);
    }
    cout << q1 << endl;

    for (int i = 1; i <= 10; ++i)
    {
        q1.popFront();
    }

    Fifo<double> q22;

    for (double i = 1; i <= 5; i+=0.5)
    {
        q22.pushBack(i);
    }
    cout << q22 << endl;

    q22.clear();

    return 0;
}
