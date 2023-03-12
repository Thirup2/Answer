#include <iostream>
#include <string>

int main()
{
    std::string line;
    while (std::getline(std::cin, line)) {       // 重定向到 ./resources/book_sales
        std::cout << line << std::endl;
    }

    return 0;
}