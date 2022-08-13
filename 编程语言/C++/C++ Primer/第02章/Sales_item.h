#ifndef _SALES_ITEM_H_
#define _SALES_ITEM_H_

#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif