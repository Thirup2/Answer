#include <iostream>
using namespace std;
int main()
{
    double inch;
    double cm;
    cout << "请输入一个英寸值: " << endl;
    while (cin >> inch) {
        if (inch <= 0) {
            cout << "您的输入不合理, 请重新输入: " << endl;
            continue;
        } else {
            cout << inch << "英寸 = " << inch * 2.54 << "厘米" << endl;
        }
        cout << "请输入一个英寸值: " << endl;
    }

    return 0;
}