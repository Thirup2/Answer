#include <iostream>
using namespace std;
int abs(int val);
int main(void)
{
    int val;
    cin >> val;
    cout << val << "的绝对值是:" <<  abs(val) << endl;
    return 0;
}
int abs(int val)
{
    if (val < 0) {
        return -val;
    } else {
        return val;
    }
}