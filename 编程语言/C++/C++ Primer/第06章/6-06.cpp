#include <iostream>
using namespace std;
int called_times(int val);
int main(void)
{
    int val;
    while (cin >> val) {
        cout << "形参/局部变量(val): " << val << endl;
        cout << "局部静态变量(times): " << called_times(val) << endl;
    }
    return 0;
}
int called_times(int val)
{
    static int times = 0;
    return times++;
}