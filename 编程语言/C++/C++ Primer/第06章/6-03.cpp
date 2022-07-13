#include <iostream>
using namespace std;
int fact(int val);
int main(void)
{
    int n;
    cin >> n;
    cout << n << "! = " << fact(n) << endl;
    return 0;
}
int fact(int val)
{
    int result = 1;
    while (val > 1) {
        result *= val--;
    }
    return result;
}