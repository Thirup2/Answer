#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    auto beg = std::begin(arr);
    auto end = std::end(arr);
    vector<int> vec(beg, end);

    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}