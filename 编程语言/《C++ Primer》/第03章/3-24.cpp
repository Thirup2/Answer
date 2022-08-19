/* 3.3.3节练习3.20 */
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    int val;
    vector<int> list;
    while (cin >> val) {
        list.push_back(val);
    }
    for (auto beg = list.begin(), end = list.end(); beg != end && beg + 1 != end; ++beg) {
        cout << *beg + *(beg + 1) << " ";
    }
    cout << endl;
    for (auto beg = list.begin(), end = list.end(); beg <= end - 1; ++beg, --end) {
        if (beg == end - 1) {
            cout << *beg;
        } else {
            cout << *beg + *(end - 1) << " ";
        }
    }
    cout << endl;

    return 0;
}