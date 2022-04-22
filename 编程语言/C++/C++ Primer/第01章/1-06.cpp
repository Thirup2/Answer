#include <iostream>
int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int n1,n2;
    std::cin >> n1 >> n2;
    std::cout << "The sum of " << n1 << " and " << n2 << " is " << n1 + n2 << std::endl;
    /*原代码段由于第一行尾添加了分号,所以后面每一行都应该有`std::cout`代码,否则应该删去前两行的分号*/

    return 0;
}