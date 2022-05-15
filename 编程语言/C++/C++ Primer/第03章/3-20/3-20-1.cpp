#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main(void)
{
    int n;
    vector<int> num;
    while (cin >> n) {
        num.push_back(n);
    }
    int pre;
    int count = 0;
    for (auto n : num) {
        if (count > 0) {
            cout << n + pre << endl;
        }
        pre = n;
        count++;
    }

    return 0;
}