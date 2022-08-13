#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    int arr1[10];
    for (int i = 0; i < 10; ++i) {
        arr1[i] = i;
    }
    int arr2[10];
    for (int i = 0; i < 10; ++i) {
        arr2[i] = arr1[i];
    }
    vector<int> list(10);
    for (vector<int>::size_type i = 0; i < 10; ++i) {
        list[i] = i;
    }

    for (auto i : arr2) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : list) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}