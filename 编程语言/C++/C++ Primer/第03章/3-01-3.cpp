/* 1.4.1节练习1.11 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    cout << "请输入两个整数作为范围: " << endl;
    int a, b;
    cin >> a >> b;
    int max, min;
    max = a > b ? a : b;
    min = a <= b ? a : b;
    for (; min <= max; ++min) {
        cout << min << " ";
    }
    cout << endl;

    return 0;
}