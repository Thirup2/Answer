#include <iostream>

int main()
{
    int sum = 0;
    int value;
    std::cout << "please input a set of integers: ";
    while (std::cin >> value) {
        sum += value;
    }
    std::cout << "the sum of the set of integers you input is " << sum << std::endl;

    return 0;
}