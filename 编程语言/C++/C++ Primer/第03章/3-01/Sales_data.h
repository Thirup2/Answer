#ifndef SALES_DATA_H__
#define SALES_DATA_H__

#include <string>
struct Sales_data {
    std::string ISBN;
    unsigned Book_num = 0;
    double All_money = 0.0;
};

#endif