#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> strvec;
    std::string str;
    while (std::cin >> str) {
        strvec.push_back(str);
    }
    for (std::string now : strvec) {
        std::cout << now << std::endl;
    }

    return 0;
}