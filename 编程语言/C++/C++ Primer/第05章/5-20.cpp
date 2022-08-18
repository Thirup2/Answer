#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string pre, now;
    bool r = false;
    if (cin >> pre) {
        while (cin >> now) {
            if (pre == now) {
                cout << pre << endl;
                r = true;
                break;
            } else {
                pre = now;
            }
        }
        if (r == false) {
            cout << "No Match" << endl;
        }
    }

    return 0;
}