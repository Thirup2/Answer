#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    int val;
    vector<int> v1{0, 1, 1, 2, 3, 5, 8};
    vector<int> v2;
    while (cin >> val) {
        v2.push_back(val);
    }
    bool r = true;
    auto &v = (v1.size() > v2.size() ? v2 : v1);
    for (vector<int>::size_type i = 0; i < v.size(); i++) {
        if (v1[i] != v2[i]) {
            r = false;
            break;
        }
    }
    if (r == true) {
        cout << "真" << endl;
    } else {
        cout << "假" << endl;
    }

    return 0;
}