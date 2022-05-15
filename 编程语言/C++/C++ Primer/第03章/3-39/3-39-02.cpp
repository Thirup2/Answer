#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
    char str1[] = "this is the first string.";
    char str2[] = "this is the second string.";
    int n;
    n = strcmp(str1, str2);
    if (n < 0) {
        cout << "The bigger is str2" << endl;
    } else if (n > 0) {
        cout << "The bigger is str1" << endl;
    } else {
        cout << "The two strings are same" << endl;
    }

    return 0;
}