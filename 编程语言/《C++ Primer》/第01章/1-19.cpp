#include <iostream>
int main()
{
    int m, n;
    std::cout << "请输入两个整数作为范围: " << std::endl;
    std::cin >> m >> n;
    int max, min;
    if (m > n) {
        max = m;
        min = n;
    } else {
        max = n;
        min = m;
    }
    for (; min <= max; ++min) {
        std::cout << min << " ";
    }
    std::cout << std::endl;

    return 0;
}