#include "Sales_item.h"
#include <iostream>
int main()
{
    Sales_item item;
    while (std::cin >> item) {
        std::cout << item << std::endl;
    }

    return 0;
}