#include <iostream>

int main()
{
    int some;
    int sum = 0;
    while (std::cin >> some) {
        sum += some;
    }
    std::cout << sum << std::endl;

    return 0;
}