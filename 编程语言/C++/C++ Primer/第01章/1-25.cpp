#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item total;
    if(std::cin >> total){
        Sales_item now;
        while(std::cin >> now){
            if(total.isbn()==now.isbn()){
                total+=now;
            }else{
                std::cout << total << std::endl;
                total=now;
            }
        }
        std::cout << total << std::endl;
    }else{
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}