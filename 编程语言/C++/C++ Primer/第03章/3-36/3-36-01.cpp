#include <iostream>
#define SIZE 10
using namespace std;
typedef int ElemType;
int main(void)
{
    ElemType arr1[SIZE] = {};
    ElemType arr2[SIZE] = {};
    bool r = true;
    for (int i = 0; i < SIZE; i++) {
        if (arr1[i] != arr2[i]) {
            r = false;
            break;
        }
    }
    if (r) {
        cout << "相同"<< endl;
    } else {
        cout << "不相同" << endl;
    }

    return 0;
}