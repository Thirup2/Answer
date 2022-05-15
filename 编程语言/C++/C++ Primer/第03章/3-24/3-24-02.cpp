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
    auto end = num.end() - 1;
    while (beg <= end) {
        cout << *beg << " + " << *end << " = " << *beg + *end << endl;
        beg += 1;
        end -= 1;
    }
    return 0;
}