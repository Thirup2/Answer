#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

int main()
{
    vector<int> ivec;
    int some;
    while (cin >> some) {
        ivec.push_back(some);
    }
    constexpr size_t size = 128;
    if (size < ivec.size()) {
        cout << "尺寸过小" << endl;
        return -1;
    }
    int arr[size] = {};
    for (vector<int>::size_type i = 0; i < ivec.size(); i++) {
        arr[i] = ivec[i];
    }
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}