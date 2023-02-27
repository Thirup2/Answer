#include <iostream>
#include "resources/Sales_item.h"

int main()
{
    Sales_item record;
    while (std::cin >> record) {        // 重定向到 ./resources/data/book_sales
        std::cout << record << std::endl;
    }

    return 0;
}