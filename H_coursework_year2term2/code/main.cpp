#include <iostream>

int main()
{
    int a;
    int *ptr = &a;
    void *ptr1 = new int[5];
    std::cin  >> *(int*)ptr1;
    std::cout << "------------\n";
    int *ip = (int*)ptr1;
    std::cout << *ip << std::endl;
    std::cout << *((int*)ptr1);
    std::cout << ptr;
//    std::cin >> *((int *)ptr);
//    std::cout << a << std::endl;
//    //std::cout << ptr << std::endl;
//    int b = *((int *)ptr);
//    std::cout << *((int *)(ptr)) << std::endl;;
//    std::cin >> *ptr;
//    std::cout << a << std::endl;
//    std::cout << ptr << std::endl;
//    std::cout << (int)*ptr;
    return 0;
}
