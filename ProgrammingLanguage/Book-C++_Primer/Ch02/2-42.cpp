#include <iostream>
#include "resources/Sales_data.h"

// 1.20
void OTwentyZro();
// 1.21
void OTwentyOne();
// 1.22
void OTwentyTwo();
// 1.23
void OTwentyThr();
// 1.25
void OTwentyFiv();

int main()
{
    int i = 0;
    char ch;
    std::cout << "请选择题目((1.20: 20); (1.21: 21); (1.22: 22); (1.23: 23); (1.25: 25)): " << std::endl;
    std::cin >> i;
    if (i == 20) {
        OTwentyZro();
    } else if (i == 21) {
        OTwentyOne();
    } else if (i == 22) {
        OTwentyTwo();
    } else if (i == 23) {
        OTwentyThr();
    } else if (i == 25) {
        OTwentyFiv();
    } else {
        std::cout << "输入错误，已退出！" << std::endl;
    }

    return 0;
}

// 1.20
void OTwentyZro()
{
    Sales_data item;
    while (std::cin >> item.bookNo >> item.units_sold >> item.revenue) {    // 重定向至 ./resources/book_sales
        std::cout << item.bookNo << " " << item.units_sold << " " << item.units_sold * item.revenue << " " << item.revenue << std::endl;
    }
}
// 1.21
void OTwentyOne()
{
    Sales_data item1, item2;
    // 重定向至 ./resources/add_item
    if (std::cin >> item1.bookNo >> item1.units_sold >> item1.revenue && std::cin >> item2.bookNo >> item2.units_sold >> item2.revenue) {
        if (item1.bookNo == item2.bookNo) {
            unsigned amount = item1.units_sold + item2.units_sold;
            double sum = item1.units_sold * item1.revenue + item2.units_sold * item2.revenue;
            std::cout << item1.bookNo << " " << amount << " " << sum << " " << sum / (double) amount << std::endl;
        }
    }
}
// 1.22
void OTwentyTwo()
{
    Sales_data item;
    if (std::cin >> item.bookNo >> item.units_sold >> item.revenue) {       // 重定向至 ./resources/same_items
        Sales_data now;
        while (std::cin >> now.bookNo >> now.units_sold >> now.revenue) {
            if (item.bookNo == now.bookNo) {
                double amount = item.units_sold * item.revenue + now.units_sold * now.revenue;
                item.units_sold += now.units_sold;
                item.revenue = amount / (double) item.units_sold;
            } else {
                break;
            }
        }
        double amount = item.units_sold * item.revenue;
        std::cout << item.bookNo << " " << item.units_sold << " " << amount << " " << item.revenue << std::endl;
    }
}
// 1.23
void OTwentyThr()
{
    unsigned cnt = 0;
    Sales_data item;
    if (std::cin >> item.bookNo >> item.units_sold >> item.revenue) {       // 重定向至 ./resources/book_sales
        Sales_data now;
        cnt++;
        while (std::cin >> now.bookNo >> now.units_sold >> now.revenue) {
            if (now.bookNo == item.bookNo) {
                cnt++;
            } else {
                std::cout << item.bookNo << ": " << cnt << std::endl;
                item.bookNo = now.bookNo;
                cnt = 1;
            }
        }
        std::cout << item.bookNo << ": " << cnt << std::endl;
    }
}
// 1.25
void OTwentyFiv()
{
    Sales_data total;
    if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {        // 重定向至 ./resources/book_sales
        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            if (total.bookNo == trans.bookNo) {
                double amount = total.units_sold * total.revenue + trans.units_sold * trans.revenue;
                total.units_sold += trans.units_sold;
                total.revenue = amount / (double) total.units_sold;
            } else {
                double amount = total.units_sold * total.revenue;
                std::cout << total.bookNo << " " << total.units_sold << " " << amount << " " << total.revenue << std::endl;
                total.bookNo = trans.bookNo;
                total.revenue = trans.revenue;
                total.units_sold = trans.units_sold;
            }
        }
        double amount = total.units_sold * total.revenue;
        std::cout << total.bookNo << " " << total.units_sold << " " << amount << " " << total.revenue << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
    }
}