/* 1.5.2节练习1.23 */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_data item1, item2;
    if (std::cin >> item1.bookNo >> item1.units_sold >> item1.revenue) {
        int cnt = 1;
        while (std::cin >> item2.bookNo >> item2.units_sold >> item2.revenue) {
            if (item1.bookNo == item2.bookNo) {
                ++cnt;
            } else {
                std::cout << item1.bookNo << " : " << cnt << std::endl;
                item1.bookNo = item2.bookNo;
                cnt = 1;
            }
        }
        std::cout << item1.bookNo << " : " << cnt << std::endl;
    }

    return 0;
}