#include <iostream>
#include "resources/Sales_item.h"

int main()
{
    Sales_item record1, record2;
    std::cin >> record1 >> record2;     // 重定向到 ./resources/data/add_item
    std::cout << record1 + record2 << std::endl;

    return 0;
}