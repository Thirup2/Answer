/* 3.2.3节练习3.6 传统for形式 */
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
int main()
{
    string line, text;
    while (getline(cin, line)) {
        text += line + '\n';
    }
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] != '\n') {
            text[i] = 'X';
        }
    }
    cout << text << endl;

    return 0;
}