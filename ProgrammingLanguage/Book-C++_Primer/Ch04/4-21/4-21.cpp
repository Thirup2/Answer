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
    for (int &n : ivec) {
        cout << n << " ";
        if (n % 2 == 1 || n % 2 == -1) {
            n *= 2;
        }
    }
    cout << endl;
    for (int n : ivec) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}