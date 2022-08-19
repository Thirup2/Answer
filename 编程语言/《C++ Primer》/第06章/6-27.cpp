#include "head.h"
int sumof(initializer_list<int> list);
int main()
{
    initializer_list<int> list{1, 2, 3, 4, 5, 6, 7};
    cout << sumof(list) << endl;
}
int sumof(initializer_list<int> list)
{
    int sum = 0;
    for (auto beg = list.begin(), end = list.end(); beg != end; ++beg) {
        sum += *beg;
    }
    return sum;
}