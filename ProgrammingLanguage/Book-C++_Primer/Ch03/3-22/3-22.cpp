#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::getline;
#include <cctype>

int main()
{
    vector<string> text;
    string line;
    string word;
    char ch;
    while (cin >> word) {
        line += word;
        if (*(word.end() - 1) == '.') {
            text.push_back(line);
            line = "";
        }
        ch = getchar();
        if (ch == '\n') {
            text.push_back(line);
            text.push_back("");
        } else {
            line += " ";
        }
    }
    for (vector<string>::iterator beg = text.begin(), end = text.end(); beg != end; ++beg) {
        if (*beg == "") {
            break;
        }
        for (char &c : *beg) {
            c = toupper(c);
        }
        cout << *beg;
    }
    cout << endl;
    return 0;
}