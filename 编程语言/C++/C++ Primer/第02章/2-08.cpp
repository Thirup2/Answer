#include <iostream>
int main(void)
{
    std::cout << "2\115\012" << std::endl;
    std::cout << "2\t\x4d\n" << std::endl;

    return 0;
}