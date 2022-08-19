#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int val[] = {1,2,3,4,5,6,7,8,9,10};
    for (auto beg = std::begin(val), end = std::end(val); beg != end; ++beg) {
        *beg = 0;
    }
    for (auto i : val) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}