#include <iostream>
int main()
{
    std::cout << "请输入两个整数: " << std::endl;
    int m, n;
    std::cin >> m >> n;
    std::cout << m;
    std::cout << " * ";
    std::cout << n;
    std::cout << " = ";
    std::cout << m * n << std::endl;

    return 0;
}