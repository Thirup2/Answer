#include <iostream>
using std::cout;
using std::endl;

int main()
{
    constexpr size_t size = 10;
    int arr[size];
    for (size_t i = 0; i < size; i++) {
        arr[i] = i;
    }
    int arr2[size];
    for (size_t i = 0; i < size; i++) {
        arr2[i] = arr[i];
    }

    for (int now : arr2) {
        cout << now << " ";
    }
    cout << endl;

    return 0;
}