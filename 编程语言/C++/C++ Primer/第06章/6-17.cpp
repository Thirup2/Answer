#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool Upper_Exist(const string &s);
void Lower_Str(string &s);
int main(void)
{
    string str;
    getline(cin, str);
    cout << "Original: " << str << endl;
    cout << "There is" << (Upper_Exist(str) ? "" : " no") << " upper_letter" << endl;
    Lower_Str(str);
    cout << "Now: " << str << endl;
    return 0;
}
bool Upper_Exist(const string &s)
{
    for (auto &c : s) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}
void Lower_Str(string &s)
{
    for (auto &c : s) {
        c = tolower(c);
    }
}