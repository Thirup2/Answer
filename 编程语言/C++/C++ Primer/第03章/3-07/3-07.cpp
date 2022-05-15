#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main(void)
{
    string line;
    getline(cin, line);
    for (char &c : line) {
        c = 'X';
    }
    cout << line << endl;

    return 0;
}