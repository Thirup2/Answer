#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item1, item2;
    if (std::cin >> item1) {
        int cnt = 1;
        while (std::cin >> item2) {
            if (item2.isbn() != item1.isbn()) {
                std::cout << item1.isbn() << " : " << cnt << std::endl;
                item1 = item2;
                cnt = 0;
            }
            cnt++;
        }
        std::cout << item1.isbn() << " : " << cnt << std::endl;
    }

    return 0;
}