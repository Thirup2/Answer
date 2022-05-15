#include <iostream>
#define SIZE 10
typedef int ElemType;
using namespace std;
int main(void)
{
    ElemType arr[SIZE];
    for (auto &i : arr) {
        i = 0;
    }
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}