#include <iostream>

int main()
{
    int sum = 0;
    int begin = 50;
    while (begin <= 100) {
        sum += begin;
        begin++;
    }
    std::cout << sum << std::endl;

    return 0;
}