#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main(void)
{
    string line;
    getline(cin, line);
    for (auto c : line) {
        if (!ispunct(c)) {
            cout << c;
        }
    }
    cout << endl;

    return 0;
}