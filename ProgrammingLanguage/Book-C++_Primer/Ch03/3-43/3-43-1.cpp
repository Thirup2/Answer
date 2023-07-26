#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    for (int (&i)[4] : ia) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}