#include <iostream>
#include <stdexcept>
using namespace std;
int main(void)
{
    int n1, n2;
    while (cin >> n1 >> n2) {
        try {
            if (n2 == 0) {
                throw runtime_error("除数不能为0");
            }
        } catch (runtime_error err) {
            cout << err.what() << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (c == 'y') {
                continue;
            } else {
                break;
            }
        }
        cout << n1 / n2 << endl;
    }
    return 0;
}