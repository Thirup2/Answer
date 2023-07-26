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
    for (vector<int>::size_type i = 0; i < ivec.size() - 1; ++i) {
        cout << "num(" << i + 1 << ") + num(" << i + 2 << ") = " << ivec[i] + ivec[i + 1] << endl;
    }
    return 0;
}