#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    vector<int> copy;
    for (auto i : arr) {
        copy.push_back(i);
    }
    for (auto i : copy) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}