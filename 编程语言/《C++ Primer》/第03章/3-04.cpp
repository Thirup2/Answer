#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << ((s1 == s2) ? "" : (s1 > s2 ? s1 : s2)) << endl;
    cout << ((s1.size() == s2.size()) ? "" : (s1.size() > s2.size() ? s1 : s2)) << endl;

    return 0;
}