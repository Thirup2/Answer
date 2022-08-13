#include <iostream>
#include <string>
#define EDITION 2
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
int main()
{
    string text, word;
    if (EDITION == 1) {
        while (cin >> word) {
            text += word;
        }
        cout << text << endl;
    } else {
        while (cin >> word) {
            text += word + " ";
        }
        cout << text << endl;
    }
    return 0;
}