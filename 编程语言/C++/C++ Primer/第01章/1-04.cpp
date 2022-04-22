#include <iostream>
int main(void)
{
    std::cout << "请输入两个数,我将求出它们的积:" << std::endl;
    int n1,n2;
    std::cin >> n1 >> n2;
    std::cout << n1 << " * " << n2 << " = " << n1*n2 << std::endl;

    return 0;
}