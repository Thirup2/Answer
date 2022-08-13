#include <iostream>
int main()
{
    int va1, va2;
    std::cout << "请输入两个整数: " << std::endl;
    std::cin >> va1 >> va2;
    std::cout << va1 << " * " << va2 << " = " << va1 * va2 << std::endl;

    return 0;
}