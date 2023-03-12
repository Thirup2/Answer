#include <iostream>
#include <string>
int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if (s1 == s2) {
        std::cout << "same strings!" << std::endl;
    } else {
        std::cout << ((s1 >= s2) ? s1 : s2) << std::endl;
    }
    return 0;
}