#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

int main()
{
    vector<int> vec1;
    vector<int> vec2;
    int now;
    while (cin >> now && now != -1) {
        vec1.push_back(now);
    }
    while (cin >> now) {
        vec2.push_back(now);
    }
    if (vec1 == vec2) {
        cout << "两vector相同" << endl;
    } else {
        cout << "两vector不同" << endl;
    }
    return 0;
}