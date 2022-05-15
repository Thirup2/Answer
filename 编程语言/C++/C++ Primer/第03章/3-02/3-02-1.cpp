#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main(void)
{
    string line;
    while (getline(cin, line)) {
        cout << line << endl;
    }

    return 0;
}