/* 1.5.1节练习1.22 */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_data item;
    std::cin >> item.bookNo >> item.units_sold >> item.revenue;
    double total = item.units_sold * item.revenue;
    Sales_data now;
    while (std::cin >> now.bookNo >> now.units_sold >> now.revenue) {
        if (now.bookNo == item.bookNo) {
            total += now.units_sold * now.revenue;
            item.units_sold += now.units_sold;
            item.revenue = total / item.units_sold;
        }
    }
    std::cout << item.bookNo << " "
        << item.units_sold << " "
        << total << " "
        << item.revenue << std::endl;

    return 0;
}