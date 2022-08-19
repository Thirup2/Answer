#include <iostream>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    char str1[] = "This is the first";
    char str2[] = "This is the first";
    if (strcmp(str1, str2)) {
        cout << "不等" << endl;
    } else {
        cout << "相等" << endl;
    }
    string s1 = "This is the first string";
    string s2 = "This is the second string";
    if (s1 != s2) {
        cout << "不等" << endl;
    } else {
        cout << "相等" << endl;
    }

    return 0;
}