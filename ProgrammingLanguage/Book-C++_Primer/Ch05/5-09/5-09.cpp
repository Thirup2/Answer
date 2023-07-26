#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main(void)
{
    string line;
    getline(cin, line);
    int cnt = 0;
    for (auto c : line) {
        if (tolower(c) == 'a') {
            cnt++;
        } else if (tolower(c) == 'e') {
            cnt++;
        } else if (tolower(c) == 'i') {
            cnt++;
        } else if (tolower(c) == 'o') {
            cnt++;
        } else if (tolower(c) == 'u') {
            cnt++;
        }
    }
    cout << "一共有" << cnt << "个元音字母" << endl;

    return 0;
}