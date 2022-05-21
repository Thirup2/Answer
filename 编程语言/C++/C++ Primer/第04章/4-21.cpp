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
    for (auto p = num.begin(); p != num.end(); ++p) {
        cout << (((*p) % 2 == 0) ? (*p) : (*p * 2)) << " ";
    }
    cout << endl;

    return 0;
}