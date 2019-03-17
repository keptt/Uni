#include <iostream>
#include <bitset>

int count_zero_pairs(int&);

int main()
{
    int num;
    std::cout << "Input num: ";
    std::cin >> num;
    std::bitset<32> binary(num);
    std::cout << binary;

    std::cout << "count: " << count_zero_pairs(num) << std::endl;
    return 0;
}


int count_zero_pairs(int &num)
{
    bool seen_once = 0;
    unsigned char count = 0;

    while (num != 0)
    {

        if (num & 1) {
            seen_once = 0;
        }
        else
        {
            if (seen_once)
            {
                ++count;
                seen_once = 0;
            }
            else
            {
                seen_once = 1;
            }
        }
        num >>= 1;
    }
    return count;
}
