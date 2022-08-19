/* 3.3.3节练习3.16 */
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<int> v1, v2(10), v3(10, 42), v4{10}, v5{10, 42};
    vector<string> v6{10}, v7{10, "hi"};
    cout << "v1(" << v1.size() << "): ";
    for (auto beg = v1.begin(), end = v1.end(); beg != end; ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
    cout << "v2(" << v2.size() << "): ";
    for (auto beg = v2.begin(), end = v2.end(); beg != end; ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
    cout << "v3(" << v3.size() << "): ";
    for (auto beg = v3.begin(), end = v3.end(); beg != end; ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
    cout << "v4(" << v4.size() << "): ";
    for (auto beg = v4.begin(), end = v4.end(); beg != end; ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
    cout << "v5(" << v5.size() << "): ";
    for (auto beg = v5.begin(), end = v5.end(); beg != end; ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
    cout << "v6(" << v6.size() << "): ";
    for (auto beg = v6.begin(), end = v6.end(); beg != end; ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
    cout << "v7(" << v7.size() << "): ";
    for (auto beg = v7.begin(), end = v7.end(); beg != end; ++beg) {
        cout << *beg << " ";
    }
    cout << endl;

    return 0;
}