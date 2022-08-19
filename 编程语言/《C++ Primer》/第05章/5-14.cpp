#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string max_pre, max_now;
    int times = 0;
    string now;
    int cnt = 0;
    if (cin >> max_now) {
        cnt++;
        while (cin >> now) {
            if (now == max_now) {
                cnt++;
            } else {
                if (cnt > times) {
                    max_pre = max_now;
                    times = cnt;
                    max_now = now;
                    cnt = 1;
                }
            }
        }
        if (cnt > times) {
            max_pre = max_now;
            times = cnt;
        }
    }
    cout << max_pre << " " << times << endl;

    return 0;
}