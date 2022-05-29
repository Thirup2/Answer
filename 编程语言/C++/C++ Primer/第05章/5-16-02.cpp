#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<int> num;
    for (int n; cin >> n; num.push_back(n));
    auto beg = num.begin();
    while (beg != num.end()) {
        cout << *beg << " ";
        ++beg;
    }
    cout << endl;

    return 0;
}