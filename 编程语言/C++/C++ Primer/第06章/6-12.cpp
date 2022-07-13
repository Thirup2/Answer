#include <iostream>
using namespace std;
void swap(int &a, int &b);
int main(void)
{
    int a, b;
    while (cin >> a >> b) {
        cout << "previous: " << "a = " << a << ", b = " << b << endl;
        swap(a, b);
        cout << "now: a = " << a << ", b = " << b << endl;
    }
    return 0;
}
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}