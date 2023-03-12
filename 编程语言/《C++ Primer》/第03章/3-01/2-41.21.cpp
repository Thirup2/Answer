#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data item1, item2;
    // 重定向至 ./resources/add_item
    if (cin >> item1.bookNo >> item1.units_sold >> item1.revenue && cin >> item2.bookNo >> item2.units_sold >> item2.revenue) {
        if (item1.bookNo == item2.bookNo) {
            unsigned amount = item1.units_sold + item2.units_sold;
            double sum = item1.units_sold * item1.revenue + item2.units_sold * item2.revenue;
            cout << item1.bookNo << " " << amount << " " << sum << " " << sum / (double) amount << endl;
        }
    }

    return 0;
}