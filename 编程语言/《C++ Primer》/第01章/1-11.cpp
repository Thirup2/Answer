#include <iostream>
int main(void)
{
    int a, b;
    std::cout << "请输入两个整数作为范围: " << std::endl;
    std::cin >> a >> b;
    while (a <= b) {
        std::cout << a++ << " ";
    }
    std::cout << std::endl;

    return 0;
}