#include <iostream>
using namespace std;
int called_times(void);
int main(void)
{
    int n;
    while (cin >> n) {
        called_times();
    }
    cout << called_times() << endl;
    return 0;
}
int called_times(void)
{
    static int times = 0;
    return times++;
}