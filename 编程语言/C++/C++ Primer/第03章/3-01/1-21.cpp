#include <iostream>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
int main(void)
{
    Sales_data book1, book2;
    cin >> book1.ISBN >> book1.Book_num >> book1.All_money;
    cin >> book2.ISBN >> book2.Book_num >> book2.All_money;
    if (book1.ISBN == book2.ISBN) {
        book1.Book_num += book2.Book_num;
        book1.All_money += book2.All_money;
    } else {
        cerr << "您输入的两条记录不是同一本书" << endl;
        exit(EXIT_FAILURE);
    }
    cout << book1.ISBN << " " << book1.Book_num << " " << book1.All_money << endl;

    return 0;
}