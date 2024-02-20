#include <iostream>
#include "resources/Sales_item.h"

int main()
{
    Sales_item item1, item2;
    // 重定向到 resources/data/add_item
    std::cin >> item1 >> item2;
    std::cout << item1 + item2 << std::endl;

    return 0;
}