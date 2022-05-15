#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main(void)
{
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    if (line1 < line2) {
        cout << line2 << endl;
    } else {
        cout << line1 << endl;
    }

    return 0;
}