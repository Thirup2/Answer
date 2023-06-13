#include <iostream>
#include "resources/Sales_item.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_item record;
    while (cin >> record) {        // 重定向到 ./resources/data/book_sales
        cout << record << endl;
    }

    return 0;
}