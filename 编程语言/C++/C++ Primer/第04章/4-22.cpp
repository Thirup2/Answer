#include <iostream>
#include <string>
#define EDITION 2
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    int val;
    if (EDITION == 1) {
        while (cin >> val) {
            cout << (val < 60 ? "fail" : (val <= 75 ? "low pass" : (val <= 90 ? "pass" : "high pass"))) << endl;
        }
    } else {
        while (cin >> val) {
            if (val < 60) {
                cout << "fail" << endl;
            } else if (val <= 75) {
                cout << "low pass" << endl;
            } else if (val <= 90) {
                cout << "pass" << endl;
            } else {
                cout << "high pass" << endl;
            }
        }
    }

    return 0;
}