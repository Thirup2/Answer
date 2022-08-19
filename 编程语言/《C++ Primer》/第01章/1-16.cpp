#include <iostream>
int main()
{
    int sum = 0, val;
    while (std::cin >> val) {
        sum += val;
    }
    std::cout << "输入值的和是: " << sum << std::endl;

    return 0;
}