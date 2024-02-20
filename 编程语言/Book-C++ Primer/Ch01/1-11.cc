#include <iostream>
#include <string>

int main()
{
    int min, max;
    std::cout << "Please input two integer: ";
    std::cin >> min >> max;
    if (min > max) {
        int tmp = min;
        min = max;
        max = tmp;
    }
    std::string method("while");
    std::cout << "Please input a loop method from while, for: ";
    while (std::cin >> method) {
        if (method == "while") {
            while (min <= max) {
                std::cout << min++ << std::endl;
            }
            break;
        } else if (method == "for") {
            for (; min <= max; min++) {
                std::cout << min << std::endl;
            }
            break;
        } else {
            std::cout << "input error, please input a loop method from while, for: ";
            continue;
        }
    }

    return 0;
}