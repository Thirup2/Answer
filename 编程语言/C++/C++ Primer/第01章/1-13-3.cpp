#include <iostream>
int main()
{
    int a, b;
    std::cout << "请输入两个整数作为范围: " << std::endl;
    std::cin >> a >> b;
    for (; a <= b; ++a) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    return 0;
}