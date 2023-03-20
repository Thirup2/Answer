#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

void my_gets(char *str, size_t size);
void my_puts(char *str);

int main()
{
    constexpr size_t size = 256;
    char str1[size / 2];
    char str2[size / 2];
    char str[size];
    my_gets(str1, size / 2);
    my_gets(str2, size / 2);
    strcpy(str, str1);
    strcat(str, str2);
    my_puts(str1);
    cout << " + ";
    my_puts(str2);
    cout << " = ";
    my_puts(str);
    cout << endl;

    return 0;
}

void my_gets(char *str, size_t size)
{
    char ch;
    size_t i = 0;
    while (((ch = getchar()) != '\n') && i < size - 1) {
        *(str + i) = ch;
        i++;
    }
    *(str + i) = '\0';
}
void my_puts(char *str)
{
    while (*str != '\0') {
        putchar(*str);
        str++;
    }
}