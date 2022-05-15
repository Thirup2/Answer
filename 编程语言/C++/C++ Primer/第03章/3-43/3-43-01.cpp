#include <iostream>
using namespace std;
int main(void)
{
    int ia[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    for (const auto &i : ia) {
        for (const auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}