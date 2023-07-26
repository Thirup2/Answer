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
        int temp = a;
        a = b;
        b = temp;
    }
    while (a <= b) {
        cout << a++ << endl;
    }
    return 0;
}