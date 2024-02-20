#include <iostream>
#include "resources/Sales_item.h"

int main()
{
    Sales_item item;
    // 重定向输入为 resources/data/book_sales
    while (std::cin >> item) {
        std::cout << item << std::endl;
    }
    
    return 0;
}