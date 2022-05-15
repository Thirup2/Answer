#include <iostream>
using namespace std;
using int_arr = int[4];
int main(void)
{
    int_arr ia[3] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    for (int_arr *p = ia; p != ia + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }

    return 0;
}