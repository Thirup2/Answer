#include <iostream>
#include "resources/Sales_item.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_item record1, record2;
    cin >> record1 >> record2;     // 重定向到 ./resources/data/add_item
    cout << record1 + record2 << endl;

    return 0;
}