#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item book1,book2;
    std::cout << "请输入两个ISBN相同的Sales_item对象:" <<std::endl;
    std::cin >> book1 >> book2;
    std::cout << book1 + book2 << std::endl;

    return 0;
}