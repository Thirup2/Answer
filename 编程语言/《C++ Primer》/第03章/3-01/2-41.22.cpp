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
    Sales_data item;
    if (cin >> item.bookNo >> item.units_sold >> item.revenue) {       // 重定向至 ./resources/same_items
        Sales_data now;
        while (cin >> now.bookNo >> now.units_sold >> now.revenue) {
            if (item.bookNo == now.bookNo) {
                double amount = item.units_sold * item.revenue + now.units_sold * now.revenue;
                item.units_sold += now.units_sold;
                item.revenue = amount / (double) item.units_sold;
            } else {
                break;
            }
        }
        double amount = item.units_sold * item.revenue;
        cout << item.bookNo << " " << item.units_sold << " " << amount << " " << item.revenue << endl;
    }

    return 0;
}