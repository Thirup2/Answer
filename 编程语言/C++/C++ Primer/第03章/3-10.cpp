#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
int main()
{
    string text, line;
    while (getline(cin, line)) {
        text += line + '\n';
    }
    for (auto &s : text) {
        if (!ispunct(s)) {
            cout << s;
        }
    }
    cout << endl;

    return 0;
}