#include "head.h"
void reset(int &n);
int main()
{
    int val;
    cin >> val;
    reset(val);
    cout << val << endl;

    return 0;
}
void reset(int &n)
{
    n = 0;
}