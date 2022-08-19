#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int fact(int i);
int main()
{
    int val;
    cin >> val;
    cout << val << "'s fact is " << fact(val) << endl;

    return 0;
}
int fact(int i)
{
    if (i > 2) {
        return i * fact(i - 1);
    } else {
        return i;
    }
}