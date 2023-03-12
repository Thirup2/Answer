#include <iostream>
#include <string>
int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if (s1.size() == s2.size()) {
        std::cout << "same size!" << std::endl;
    } else {
        std::cout << ((s1.size() >= s2.size()) ? s1 : s2) << std::endl;
    }
    return 0;
}