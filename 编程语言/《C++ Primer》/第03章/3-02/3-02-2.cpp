#include <iostream>
#include <string>
int main()
{
    std::string word;
    int i = 0;
    while (std::cin >> word) {
        std::cout << word << " ";
        i++;
        if (i % 3 == 0) {
            std::cout << std::endl;
        }
    }
    return 0;
}