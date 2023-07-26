#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a, b;
    cout << "请输入两个整数 a, b (a <= b): " << endl;
    cin >> a >> b;
    if (a > b) {
        return -1;
    }
    while (a <= b) {
        cout << a++ << endl;
    }
    return 0;
}