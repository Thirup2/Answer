#include <iostream>
#include <string>
int main()
{
    std::string tot, now;
    if (std::cin >> now) {
        tot = now;
        while (std::cin >> now) {
            tot += " " + now;
        }
    }
    std::cout << tot << std::endl;

    return 0;
}