#include <iostream>
#include "resources/Sales_item.h"

int main()
{
    Sales_item sum;
    Sales_item now;
    if (std::cin >> now) {      // 重定向到 ./resource/data/same_items
        sum = now;
        while (std::cin >> now) {
            if (sum.isbn() == now.isbn()) {
                sum += now;
            } else {
                break;
            }
        }
        std::cout << sum << std::endl;
    }
    return 0;
}