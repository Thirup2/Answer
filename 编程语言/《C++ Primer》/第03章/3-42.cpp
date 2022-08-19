#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    vector<int> ivec(10, 42);
    int arr[10];
    for (size_t i = 0; i < 10; i++) {
        arr[i] = ivec[i];
    }
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}