#include <iostream>
#include "resources/Sales_item.h"

int main()
{
    Sales_item sum;
    Sales_item item;
    // 重定向到 resources/data/same_items
    if (std::cin >> sum) {
        while (std::cin >> item) {
            sum += item;
        }
    }
    std::cout << sum << std::endl;

    return 0;
}