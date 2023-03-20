#include <iostream>
using std::cout;
using std::endl;

int main()
{
    constexpr size_t size = 10;
    int arr[size];
    int *pa = arr + (size / 2);
    *pa = 0;
    for (int now : arr) {
        cout << now << " ";
    }
    cout << endl;

    return 0;
}