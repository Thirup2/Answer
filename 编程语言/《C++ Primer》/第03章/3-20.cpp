#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    int val;
    vector<int> list;
    while (cin >> val) {
        list.push_back(val);
    }
    for (vector<int>::size_type i = 0; i + 1 < list.size(); i++) {
        cout << list[i] + list[i + 1] << " ";
    }
    cout << endl;
    for (vector<int>::size_type i = 0; i <= list.size() / 2; i++) {
        if (i == list.size() - 1 - i) {
            cout << list[i];
        } else {
            cout << list[i] + list[list.size() - i - 1] << " ";
        }
    }
    cout << endl;

    return 0;
}