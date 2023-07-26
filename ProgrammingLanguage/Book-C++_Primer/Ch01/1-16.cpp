#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int some;
    int sum = 0;
    while (cin >> some) {
        sum += some;
    }
    cout << sum << endl;

    return 0;
}