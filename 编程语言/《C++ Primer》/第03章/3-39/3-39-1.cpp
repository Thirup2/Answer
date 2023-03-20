#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;

int main()
{
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    if (str1 == str2) {
        cout << str1 << " = " << str2 << endl;
    } else {
        cout << str1 << ((str1 < str2) ? " < " : " > ") << str2 << endl;
    }
    return 0;
}