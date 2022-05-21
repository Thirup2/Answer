#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<int> ivec;
    int n;
    while (cin >> n) {
        ivec.push_back(n);
    }
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != cnt; ix++, cnt--) {
        ivec[ix] = cnt;
    }

    return 0;
}