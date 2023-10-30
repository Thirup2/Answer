#include <iostream>
#include <string>

int main()
{
    std::string method("while");
    std::cout << "please input a method to loop: ";
    while (std::cin >> method) {
        if (method == "while") {
            int i = 10;
            while (i > 1) {
                std::cout << --i << std::endl;
            }
            break;
        } else if (method == "for") {
            for (int i = 9; i > 0; --i) {
                std::cout << i << std::endl;
            }
            break;
        } else {
            std::cout << "input error, please input a loop method from while, for: ";
            continue;
        }
    }
    return 0;
}