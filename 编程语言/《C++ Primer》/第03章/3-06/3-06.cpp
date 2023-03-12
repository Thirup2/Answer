#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string s;
    while (std::getline(std::cin, s)) {
        for (char &c : s) {
            if (!isblank(c)) {
                c = 'X';
            }
        }
        std::cout << s << std::endl;
    }
    return 0;
}