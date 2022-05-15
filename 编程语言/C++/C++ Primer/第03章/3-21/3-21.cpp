#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main(void)
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{ 10 };
    vector<int> v5{ 10,42 };
    vector<string> v6{ 10 };
    vector<string> v7{ 10,"hi" };
    cout << "v1: " << v1.size() << endl;
    if (v1.size() > 0) {
        for (auto i = v1.begin(); i != v1.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
    cout << "v2: " << v2.size() << endl;
    if (v2.size() > 0) {
        for (auto i = v2.begin(); i != v2.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
    cout << "v3: " << v3.size() << endl;
    if (v3.size() > 0) {
        for (auto i = v3.begin(); i != v3.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
    cout << "v4: " << v4.size() << endl;
    if (v4.size() > 0) {
        for (auto i = v4.begin(); i != v4.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
    cout << "v5: " << v5.size() << endl;
    if (v5.size() > 0) {
        for (auto i = v5.begin(); i != v5.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
    cout << "v6: " << v6.size() << endl;
    if (v6.size() > 0) {
        for (auto i = v6.begin(); i != v6.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
    cout << "v7: " << v7.size() << endl;
    if (v7.size() > 0) {
        for (auto i = v7.begin(); i != v7.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
    return 0;
}