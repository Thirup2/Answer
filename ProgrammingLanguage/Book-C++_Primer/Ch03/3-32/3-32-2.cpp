#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <iterator>
using std::begin;
using std::end;

int main()
{
    constexpr vector<int>::size_type size = 10;
    vector<int> vec1(size);
    for (vector<int>::size_type i = 0; i < size; ++i) {
        vec1[i] = i;
    }
    vector<int> vec2(vec1);
    for (int now : vec2) {
        cout << now << " ";
    }
    cout << endl;

    return 0;
}