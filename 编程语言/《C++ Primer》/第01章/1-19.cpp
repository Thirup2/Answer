#include <iostream>

int main()
{
    int a, b;
    std::cout << "请输入两个整数 a, b (a <= b): " << std::endl;
    std::cin >> a >> b;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    while (a <= b) {
        std::cout << a++ << std::endl;
    }
    return 0;
}