#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main(void)
{
    string st1, st2;
    getline(cin, st1);
    getline(cin, st2);
    if (st1.size() > st2.size()) {
        cout << st1 << endl;
    } else {
        cout << st2 << endl;
    }

    return 0;
}