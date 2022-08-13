/* 3.2.3节练习3.6 while形式 */
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
    int i = 0;
    while (i < text.size()) {
        if (text[i] != '\n') {
            text[i] = 'X';
        }
        i++;
    }
    cout << text << endl;

    return 0;
}