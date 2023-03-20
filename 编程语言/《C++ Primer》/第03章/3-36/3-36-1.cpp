#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    constexpr size_t size1 = 10;
    constexpr size_t size2 = 11;
    int arr1[size1];
    int arr2[size2];
    for (size_t i = 0; i < size1; ++i) {
        cin >> arr1[i];
    }
    for (size_t i = 0; i < size2; ++i) {
        cin >> arr2[i];
    }
    if (size1 == size2) {
        for (size_t i = 0; i < size1; ++i) {
            if (arr1[i] != arr2[i]) {
                cout << "在第" << i + 1 << "个位置处出现不同" << endl;
                return -1;
            }
        }
    } else {
        cout << "二者大小不同" << endl;
        return -2;
    }
    cout << "两数组相同" << endl;

    return 0;
}