#include <iostream>
#include "resources/Sales_item.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_item sum;
    Sales_item now;
    if (cin >> now) {      // 重定向到 ./resource/data/same_items
        sum = now;
        while (cin >> now) {
            if (sum.isbn() == now.isbn()) {
                sum += now;
            } else {
                break;
            }
        }
        cout << sum << endl;
    }
    return 0;
}