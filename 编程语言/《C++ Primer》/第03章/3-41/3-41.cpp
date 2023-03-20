#include <iostream>
#include <vector>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main()
{
    constexpr size_t size = 128;
    int arr[size] = {};
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
        if (arr[i] == -1) {
            break;
        }
    }
    int *beg = begin(arr);
    int *en = end(arr);
    vector<int> ivec(beg, en);
    for (int i : ivec) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}