/* 1.6节练习1.25 */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_data item;
    Sales_data sum;
    double total = 0;
    if (std::cin >> item.bookNo >> item.units_sold >> item.revenue) {
        total = item.units_sold * item.revenue;
        while (std::cin >> sum.bookNo >> sum.units_sold >> sum.revenue) {
            if (item.bookNo == sum.bookNo) {
                total += sum.units_sold * sum.revenue;
                item.units_sold += sum.units_sold;
                item.revenue = total / item.units_sold;
            } else {
                std::cout << item.bookNo << " "
                    << item.units_sold << " "
                    << total << " "
                    << item.revenue << std::endl;
                item.bookNo = sum.bookNo;
                item.revenue = sum.revenue;
                item.units_sold = sum.units_sold;
                total = item.units_sold * item.revenue;
            }
        }
        std::cout << item.bookNo << " "
            << item.units_sold << " "
            << total << " "
            << item.revenue << std::endl;
    }

    return 0;
}