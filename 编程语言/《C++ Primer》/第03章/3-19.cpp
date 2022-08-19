#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    vector<int> v1(10, 42);
    vector<int> v2{42,42,42,42,42,42,42,42,42,42};
    vector<int> v3(10);
    for (auto &i : v3) {
        i = 42;
    }

    cout << "v1(" << v1.size() << "): ";
    for (auto i : v1) {
        cout << i << " ";
    }
    cout << endl;
    cout << "v2(" << v2.size() << "): ";
    for (auto i : v2) {
        cout << i << " ";
    }
    cout << endl;
    cout << "v3(" << v3.size() << "): ";
    for (auto i : v3) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}