#include <iostream>

int main()
{
    int a, b;
    std::cout << "Please input two integers: ";
    std::cin >> a >> b;
    
    std::cout << a;
    std::cout << " * ";
    std::cout << b;
    std::cout << " = ";
    std::cout << a * b;
    std::cout << std::endl;

    return 0;
}