#include <iostream>
int main()
{
    int i = 20;
    int j = 34;
    int *p = &i;
    std::cout << "*p = " << *p << "; p = " << p << std::endl;
    p = &j;
    std::cout << "*p = " << *p << "; p = " << p << std::endl;
    *p = 35;
    std::cout << "*p = " << *p << "; p = " << p << std::endl;

    return 0;
}