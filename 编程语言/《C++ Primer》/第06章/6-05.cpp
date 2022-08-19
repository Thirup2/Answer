#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int iabs(int a);
int main()
{
    int val;
    cin >> val;
    cout << val << " 的绝对值是 " << iabs(val) << endl;

    return 0;
}
int iabs(int a)
{
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}