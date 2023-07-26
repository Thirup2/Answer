#include <iostream>
#include <iterator>
using std::cout;
using std::endl;
using std::begin;
using std::end;
using IteToIntF = int(*)[4];

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    IteToIntF pbeg = begin(ia);
    IteToIntF pend = end(ia);
    for (; pbeg != pend; pbeg++) {
        for (int *ibeg = begin(*pbeg), *iend = end(*pbeg); ibeg != iend; ibeg++) {
            cout << *ibeg << " ";
        }
        cout << endl;
    }

    return 0;
}