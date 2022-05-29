#include <iostream>
#include <stdexcept>
using namespace std;
int main(void)
{
    int n1, n2;
    while (cin >> n1 >> n2) {
        if (n2 == 0) {
            throw runtime_error("除数不能为0");
        }
        cout << n1 / n2 << endl;
    }

    return 0;
}