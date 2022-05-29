#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<int> num1;
    vector<int> num2;
    for (int n = 0; cin >> n && n != -1; num1.push_back(n));
    for (int n = 0; cin >> n && n != -1; num2.push_back(n));
    bool r = true;
    auto beg1 = num1.begin();
    auto beg2 = num2.begin();
    if (num1.size() > num2.size()) {
        for (; beg2 != num2.end(); ++beg2, ++beg1) {
            if (*beg2 != *beg1) {
                r = false;
            }
        }
    } else {
        for (; beg1 != num1.end(); ++beg1, ++beg2) {
            if (*beg1 != *beg2) {
                r = false;
            }
        }
    }
    cout << r << endl;

    return 0;
}