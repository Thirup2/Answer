#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string pre;
    string now;
    int count = 1;
    int max_count = 0;
    string max_str;
    if (cin >> pre) {
        while (cin >> now) {
            if (now == pre) {
                ++count;
            } else {
                if (count > max_count) {
                    max_count = count;
                    max_str = pre;
                }
                pre = now;
                count = 1;
            }
        }
    }
    if (max_count == 0) {
        cout << "任何单词都没连续重复过" << endl;
    } else {
        cout << max_str << "连续重复了" << max_count << "次" << endl;
    }

    return 0;
}