#include "head.h"
bool HaveUp(string s);
void tolower_str(string &s);
int main()
{
    string str;
    cin >> str;
    if (HaveUp(str)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    tolower_str(str);
    cout << str << endl;

    return 0;
}
bool HaveUp(string s)
{
    for (auto c : s) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}
void tolower_str(string &s)
{
    for (auto &c : s) {
        c = tolower(c);
    }
}