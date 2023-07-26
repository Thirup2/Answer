#include <iostream>
#include "resources/Sales_item.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_item item;
    Sales_item read;
    int count = 1;
    if (cin >> read) {         // 重定向到 ./resources/data/book_sales
        item = read;
        while (cin >> read) {
            if (item.isbn() == read.isbn()) {
                count++;
            } else {
                cout << item.isbn() << " " << count << endl;
                item = read;
                count = 1;
            }
        }
        cout << item.isbn() << " " << count << endl;
    }
    
    return 0;
}