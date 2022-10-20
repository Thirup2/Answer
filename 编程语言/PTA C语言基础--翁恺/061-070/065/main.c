#include <stdio.h>
int main(void)
{
    int ch;
    while ((ch = getchar()) != '\n') {
        if (ch >= 'A' && ch <= 'Z') {
            ch = 'Z' - (ch - 'A');
        }
        putchar(ch);
    }

    return 0;
}