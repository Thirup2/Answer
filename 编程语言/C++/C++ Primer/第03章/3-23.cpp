#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    int val;
    vector<int> v(10, 42);
    for (auto beg = v.begin(), end = v.end(); beg != end; ++beg) {
        *beg *= 2;
    }
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}