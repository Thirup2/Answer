#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int arr[] = {1,2,3,4,5};
    vector<int> cparr(begin(arr), end(arr));

    for (auto i : cparr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}