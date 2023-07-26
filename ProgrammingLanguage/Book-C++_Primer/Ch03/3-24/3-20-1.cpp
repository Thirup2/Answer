#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

int main()
{
    vector<int> ivec;
    int now;
    while (cin >> now) {
        ivec.push_back(now);
    }
    int i = 1;
    for (vector<int>::iterator beg = ivec.begin(), end = ivec.end(); beg < end - 1; ++beg) {
        cout << "num(" << i << ") + num(" << i + 1 << ") = " << *beg + *(beg + 1) << endl;
        i++;
    }
    return 0;
}