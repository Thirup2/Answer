#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int n;
    vector<int> num{ 1,2,3,4,5,6,7,8,9,10 };
    for (auto i = num.begin(); i != num.end(); i++) {
        *i = *i * 2;
    }
    for (auto i : num) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}