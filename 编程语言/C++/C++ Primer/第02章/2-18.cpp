#include <iostream>
int main(void)
{
    int a=40;
    int * p=nullptr;
    std::cout << p << std::endl;
    p=&a;
    std::cout << *p << std::endl;
    *p=50;
    std::cout << *p << std::endl;

    return 0;
}