#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    auto beg = scores.begin();
    while (cin >> grade) {
        if (grade <= 100) {
            *(beg + (grade / 10)) += 1;
        }
    }
    for (auto i : scores) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}