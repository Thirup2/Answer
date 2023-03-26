#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a;
    while (cin >> a) {
        if (a % 2 == 1) {
            cout << "奇数" << endl;
        } else {
            cout << "偶数" << endl;
        }
    }

    return 0;
}