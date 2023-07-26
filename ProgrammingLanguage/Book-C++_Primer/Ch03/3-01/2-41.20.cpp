#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data item;
    while (cin >> item.bookNo >> item.units_sold >> item.revenue) {    // 重定向至 ./resources/book_sales
        cout << item.bookNo << " " << item.units_sold << " " << item.units_sold * item.revenue << " " << item.revenue << endl;
    }

    return 0;
}