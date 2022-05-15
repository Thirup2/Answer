#include <iostream>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
int main(void)
{
    Sales_data total;
    if (cin >> total.ISBN >> total.Book_num >> total.All_money) {
        Sales_data trans;
        while (cin >> trans.ISBN >> trans.Book_num >> trans.All_money) {
            if (total.ISBN == trans.ISBN) {
                total.Book_num += trans.Book_num;
                total.All_money += trans.All_money;
            } else {
                cout << total.ISBN << " " << total.Book_num << " " << total.All_money << endl;
                total.ISBN = trans.ISBN;
                total.Book_num = trans.Book_num;
                total.All_money = trans.All_money;
            }
        }
        cout << total.ISBN << " " << total.Book_num << " " << total.All_money << endl;
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }

    return 0;
}