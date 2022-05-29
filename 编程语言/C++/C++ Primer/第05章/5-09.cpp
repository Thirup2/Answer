#include <iostream>
using namespace std;
int main(void)
{
    char n;
    int a_cnt = 0;
    while (cin >> n) {
        switch (n) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++a_cnt;
                break;
        }
    }
    cout << "一共有" << a_cnt << "个元音字母";

    return 0;
}