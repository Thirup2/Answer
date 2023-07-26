#include <iostream>

int main()
{
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;

    std::cout << "j: " << "int" << std::endl;
    std::cout << "k: " << "const int &" << std::endl;
    std::cout << "p: " << "const int *" << std::endl;
    std::cout << "j2: " << "const int" << std::endl;
    std::cout << "k2: " << "const int &" << std::endl;

    return 0;
}