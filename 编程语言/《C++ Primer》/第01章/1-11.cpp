#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int a, b;
    cout << "请输入两个整数 a, b (a <= b): " << endl;
    cin >> a >> b;
    if (a > b) {
        cout << "输入错误，程序已退出！" << endl;
    }
    while (a <= b) {
        cout << a++ << endl;
    }
    return 0;
}