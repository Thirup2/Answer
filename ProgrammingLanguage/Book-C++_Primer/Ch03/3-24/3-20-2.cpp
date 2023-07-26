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
    vector<int>::iterator beg;
    vector<int>::iterator end;
    for (beg = ivec.begin(), end = ivec.end() - 1; beg < end; ++beg, --end) {
        cout << "num(" << i << ") + num(" << ivec.size() - i + 1 << ") = " << *beg + *end << endl;
        i++;
    }
    if (beg == end) {
        cout << "num(" << i << ") = " << *beg << endl;
    }

    return 0;
}