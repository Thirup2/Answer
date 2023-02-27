#include <iostream>
#include "resources/Sales_item.h"

int main()
{
    Sales_item item;
    Sales_item read;
    int count = 1;
    if (std::cin >> read) {         // 重定向到 ./resources/data/book_sales
        item = read;
        while (std::cin >> read) {
            if (item.isbn() == read.isbn()) {
                count++;
            } else {
                std::cout << item.isbn() << " " << count << std::endl;
                item = read;
                count = 1;
            }
        }
        std::cout << item.isbn() << " " << count << std::endl;
    }
    
    return 0;
}