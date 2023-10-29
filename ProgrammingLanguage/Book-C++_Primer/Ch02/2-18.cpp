#include <iostream>

int main()
{
    int ival = 42;
    int ival2 = 1024;
    int *pi = &ival;
    
    *pi = 1;
    pi = &ival2;
    *pi = 2;

    std::cout << "ival = " << ival << "; ival2 = " << ival2 << std::endl;

    return 0;
}