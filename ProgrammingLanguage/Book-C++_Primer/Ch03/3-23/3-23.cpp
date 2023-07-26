#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

int main()
{
    vector<int> ivec(10);
    int now;
    cout << "输入 10 个整数：" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> now;
        ivec[i] = now;
    }
    for (vector<int>::iterator beg = ivec.begin(), end = ivec.end(); beg != end; ++beg) {
        *beg *= 2;
    }
    for (int cir : ivec) {
        cout << cir << " ";
    }
    cout << endl;

    return 0;
}