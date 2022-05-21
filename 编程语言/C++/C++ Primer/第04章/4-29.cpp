#include <iostream>
using namespace std;
int main(void)
{
    int x[10]; int *p = x;
    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(p) / sizeof(*p) << endl;

    return 0;
}