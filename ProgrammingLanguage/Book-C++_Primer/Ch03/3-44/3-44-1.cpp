#include <iostream>
using std::cout;
using std::endl;
using ReToIntF = int(&)[4];

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    for (ReToIntF i : ia) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}