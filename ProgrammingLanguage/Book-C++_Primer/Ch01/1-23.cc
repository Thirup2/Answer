#include <iostream>
#include "resources/Sales_item.h"

int main()
{
    Sales_item pre;
    Sales_item now;
    int cnt = 0;
    // 输入重定向到 resources/data/book_sales
    if (std::cin >> pre) {
        cnt++;
        while (std::cin >> now) {
            if (pre.isbn() == now.isbn()) {
                cnt++;
            } else {
                std::cout << pre.isbn() << ": " << cnt << std::endl;
                pre = now;
                cnt = 1;
            }
        }
        std::cout << pre.isbn() << ": " << cnt << std::endl;
    }

    return 0;
}