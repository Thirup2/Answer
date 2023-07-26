#include <iostream>

int main()
{
    int i = 42;
    int j = 32;
    int *p;
    std::cout << "i = " << i << "; j = " << j << "; p = " << p << std::endl;
    p = &i;
    std::cout << "i = " << i << "; j = " << j << "; p = " << p << std::endl;
    p = &j;
    std::cout << "i = " << i << "; j = " << j << "; p = " << p << std::endl;
    std::cin >> *p;
    std::cout << "i = " << i << "; j = " << j << "; p = " << p << std::endl;

    return 0;
}