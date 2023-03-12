#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {        // 重定向至 ./resources/book_sales
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            if (total.bookNo == trans.bookNo) {
                double amount = total.units_sold * total.revenue + trans.units_sold * trans.revenue;
                total.units_sold += trans.units_sold;
                total.revenue = amount / (double) total.units_sold;
            } else {
                double amount = total.units_sold * total.revenue;
                cout << total.bookNo << " " << total.units_sold << " " << amount << " " << total.revenue << endl;
                total.bookNo = trans.bookNo;
                total.revenue = trans.revenue;
                total.units_sold = trans.units_sold;
            }
        }
        double amount = total.units_sold * total.revenue;
        cout << total.bookNo << " " << total.units_sold << " " << amount << " " << total.revenue << endl;
    } else {
        cerr << "No data?!" << endl;
    }

    return 0;
}