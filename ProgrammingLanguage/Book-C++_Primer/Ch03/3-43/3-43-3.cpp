#include <iostream>
#include <iterator>
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    int(*pbeg)[4] = begin(ia);
    int(*pend)[4] = end(ia);
    for (; pbeg != pend; pbeg++) {
        for (int *ibeg = begin(*pbeg), *iend = end(*pbeg); ibeg != iend; ibeg++) {
            cout << *ibeg << " ";
        }
        cout << endl;
    }

    return 0;
}