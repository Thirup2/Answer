#include <iostream>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string pre, now;
    bool r = true;
    if (cin >> pre) {
        while (cin >> now) {
            if (isupper(now[0]) && now == pre) {
                cout << now << endl;
                r = false;
                break;
            } else {
                pre = now;
            }
        }
        if (r) {
            cout << "No Match" << endl;
        }
    }

    return 0;
}