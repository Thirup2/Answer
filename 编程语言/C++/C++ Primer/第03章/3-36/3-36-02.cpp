#include <iostream>
#include <vector>
using namespace std;
typedef int ElemType;
int main(void)
{
    ElemType temp1, temp2;
    vector<ElemType> arr1;
    vector<ElemType> arr2;
    while (cin >> temp1 >> temp2) {
        arr1.push_back(temp1);
        arr2.push_back(temp2);
    }   // C++怎么做到在两个循环中分别读取
    auto beg1 = arr1.begin(), end1 = arr1.end();
    auto beg2 = arr2.begin(), end2 = arr2.end();
    bool r = true;
    while (beg1 != end1 && beg2 != end2) {
        if (*beg1 != *beg2) {
            r = false;
        }
        beg1 += 1;
        beg2 += 1;
    }
    if (r) {
        cout << "相同" << endl;
    } else {
        cout << "不相同" << endl;
    }

    return 0;
}