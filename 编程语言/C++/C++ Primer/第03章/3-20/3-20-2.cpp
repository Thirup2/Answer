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
    for (int i = 0; i <= (num.size() - 1) / 2; i++) {
        cout << num[i] << " + " << num[num.size() - 1 - i] << " = " << num[i] + num[num.size() - 1 - i] << endl;
    }

    return 0;
}