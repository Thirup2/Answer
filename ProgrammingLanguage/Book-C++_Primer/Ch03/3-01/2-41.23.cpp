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
    unsigned cnt = 0;
    Sales_data item;
    if (cin >> item.bookNo >> item.units_sold >> item.revenue) {       // 重定向至 ./resources/book_sales
        Sales_data now;
        cnt++;
        while (cin >> now.bookNo >> now.units_sold >> now.revenue) {
            if (now.bookNo == item.bookNo) {
                cnt++;
            } else {
                cout << item.bookNo << ": " << cnt << endl;
                item.bookNo = now.bookNo;
                cnt = 1;
            }
        }
        cout << item.bookNo << ": " << cnt << endl;
    }

    return 0;
}