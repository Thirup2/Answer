#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstring>

void my_gets(char *str, size_t size);
void my_puts(char *str);

int main()
{
    constexpr size_t size = 128;
    char str1[size];
    char str2[size];
    my_gets(str1, size);
    my_gets(str2, size);
    if (!strcmp(str1, str2)) {
        my_puts(str1);
        cout << " = ";
        my_puts(str2);
        cout << endl;
    } else {
        my_puts(str1);
        cout << ((strcmp(str1, str2) < 0) ? " < " : " > ");
        my_puts(str2);
        cout << endl;
    }

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