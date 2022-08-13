/* 1.5.1节的练习1.21 */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_data item1, item2;
    double sum;
    std::cin >> item1.bookNo >> item1.units_sold >> item1.revenue;
    std::cin >> item2.bookNo >> item2.units_sold >> item2.revenue;
    if (item1.bookNo == item2.bookNo) {
        sum = item1.units_sold * item1.revenue + item2.units_sold * item2.revenue;
        std::cout << item1.bookNo << " "
            << item1.units_sold + item2.units_sold << " "
            << sum << " "
            << sum / (item1.units_sold + item2.units_sold) << std::endl;
    } else {
        std::cout << "Not same book" << std::endl;
        return -1;
    }
    return 0;
}