#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int n;
    vector<int> num;
    while (cin >> n) {
        num.push_back(n);
    }
    auto beg = num.begin();
    while (beg + 1 != num.end()) {
        cout << *beg << " + " << *(beg + 1) << " = " << *beg + *(beg + 1) << endl;
        beg += 1;
    }

    return 0;
}