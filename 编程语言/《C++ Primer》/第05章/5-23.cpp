#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int val1, val2;
    while (cin >> val1 >> val2) {
        try {
            if (val2 == 0) {
                throw std::runtime_error("除数不能为0");
            }
            cout << val1 / val2 << endl;
        } catch (std::runtime_error rerr) {
            cout << rerr.what()
                << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n') {
                break;
            }
        }
    }

    return 0;
}