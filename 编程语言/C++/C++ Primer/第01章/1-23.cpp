#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item book1,book2;
    if(std::cin >> book1){
        int count = 1;
        while(std::cin >> book2){
            if(book1.isbn()==book2.isbn()){
                count++;
            }else{
                std::cout << book1.isbn() << " has " << count << std::endl;
                book1=book2;
                count=1;
            }
        }
        std::cout << book1.isbn() << " has " << count << std::endl;
    }

    return 0;
}
// 只有录入数据的ISBM号按顺序排列才有用