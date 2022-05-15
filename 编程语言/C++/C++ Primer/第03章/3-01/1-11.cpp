#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
    int m, n;
    int temp;
    cout << "请输入两个整数" << endl;
    cin >> m >> n;
    if (m > n) {
        temp = m;
        m = n;
        n = temp;
    }
    while (m <= n) {
        cout << m << endl;
        m++;
    }

    return 0;
}