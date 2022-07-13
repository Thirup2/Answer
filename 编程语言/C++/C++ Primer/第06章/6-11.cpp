#include <iostream>
using namespace std;
void reset(int &val);
int main(void)
{
    int val;
    cin >> val;
    cout << "now val = " << val << endl;
    reset(val);
    cout << "now val = " << val << endl;
    return 0;
}
void reset(int &val)
{
    val = 0;
}