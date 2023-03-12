#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string s;
    while (std::getline(std::cin, s)) {
        for (char c : s) {
            if (!ispunct(c)) {
                std::cout << c;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}