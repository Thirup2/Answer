#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    char str1[] = "Hello ";
    char str2[] = "World!\n";
    char str3[50];
    strcpy(str3, str1);
    strcat(str3, str2);
    cout << str3 << endl;
    
    return 0;
}