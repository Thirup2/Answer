#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
int main()
{
    vector<int> ivec;
    int i;
    while (cin >> i) {
        ivec.push_back(i);
    }
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--) {
        ivec[ix] = cnt;
    }
    for (int n : ivec) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}