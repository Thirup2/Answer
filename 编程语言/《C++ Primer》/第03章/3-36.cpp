#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {1,2,3,4,5};
    int r = 0;
    for (int i = 0; i < (sizeof(arr1) / sizeof(arr1[0])) && i < (sizeof(arr2) / sizeof(arr2[0])); ++i) {
        if (arr1[i] != arr2[i]) {
            cout << "不等" << endl;
            r = 1;
        }
    }
    if (r == 0) {
        cout << "相等" << endl;
    }

    vector<int> list1(10, 42);
    vector<int> list2(9, 42);
    cout << (list1 == list2 ? "相等" : "不等") << endl;

    return 0;
}