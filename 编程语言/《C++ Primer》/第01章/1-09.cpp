#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int sum = 0;
    int begin = 50;
    while (begin <= 100) {
        sum += begin;
        begin++;
    }
    cout << sum << endl;

    return 0;
}