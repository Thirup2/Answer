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
    for (auto &v : list) {
        if (v % 2 == 1) {
            v *= 2;
        }
    }
    for (auto s : list) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}