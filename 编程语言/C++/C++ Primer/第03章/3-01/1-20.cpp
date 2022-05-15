#include <iostream>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
    Sales_data book;
    while (cin >> book.ISBN >> book.Book_num >> book.All_money) {
        cout << book.ISBN << " " << book.Book_num << " " << book.All_money << endl;
    }
    return 0;
}