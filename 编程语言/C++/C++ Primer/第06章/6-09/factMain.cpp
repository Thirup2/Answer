#include "Chapter6.h"
int main(void)
{
    int val;
    while (cin >> val) {
        cout << val << "! = " << fact(val) << endl;
    }
    return 0;
}