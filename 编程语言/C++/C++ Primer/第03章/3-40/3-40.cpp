#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
    char str1[40] = "This is the first line.";
    char str2[40] = " And this is the tuzuku.";
    char str3[80];
    strcat(str1, str2);
    strcpy(str3, str1);
    const char *cp = str3;
    while (*cp) {
        cout << *cp;
        ++cp;
    }
    cout << endl;

    return 0;
}