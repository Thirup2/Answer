#include "head.h"
void swap(int &a, int &b);
int main()
{
    int a, b;
    cin >> a >> b;
    cout << "pre: a = " << a << "; b = " << b << endl;
    swap(a, b);
    cout << "now: a = " << a << "; b = " << b << endl;

    return 0;
}
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}