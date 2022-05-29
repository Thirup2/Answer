#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string pre;
    while (cin >> pre) {
        if (*(pre.begin()) < 'A' || *(pre.begin()) > 'Z') {
            continue;
        }
        break;
    }
    string now;
    bool r = false;
    while (cin >> now) {
        if (*(now.begin()) < 'A' || *(now.begin()) > 'Z') {
            continue;
        }
        if (pre == now) {
            cout << pre << endl;
            r = true;
            break;
        } else {
            pre = now;
        }
    }
    if (r == false) {
        cout << "No match words" << endl;
    }
    return 0;
}