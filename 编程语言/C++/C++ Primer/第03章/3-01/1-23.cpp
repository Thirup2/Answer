#include <iostream>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
    Sales_data book1, book2;
    int count = 0;
    if (cin >> book1.ISBN >> book1.Book_num >> book1.All_money) {
        count++;
        while (cin >> book2.ISBN >> book2.Book_num >> book2.All_money) {
            if (book1.ISBN == book2.ISBN) {
                count++;
            } else {
                cout << book1.ISBN << " 一共有: " << count << endl;
                book1.ISBN = book2.ISBN;
                count = 1;
            }
        }
        cout << book1.ISBN << " 一共有: " << count << endl;
    }

    return 0;
}