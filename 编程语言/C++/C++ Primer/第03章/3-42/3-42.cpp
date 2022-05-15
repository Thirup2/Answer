#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<int> arr;
    int n;
    while (cin >> n) {
        arr.push_back(n);
    }
    int cparr[10];
    int j = 0;
    for (auto i : arr) {
        cparr[j] = i;
        j++;
        if (j == 10) {
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << cparr[i] << " ";
    }
    cout << endl;

    return 0;
}