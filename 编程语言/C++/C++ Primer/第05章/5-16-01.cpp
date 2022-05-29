#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<int> num;
    int n;
    while (cin >> n) {
        num.push_back(n);
    }
    for (auto beg = num.begin(); beg != num.end(); ++beg) {
        cout << *beg << endl;
    }

    return 0;
}