#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    while ((ch = getchar()) != EOF) {
        if (isupper(ch)) {
            ch = tolower(ch);
        }
        putchar(ch);
    }

    return 0;
}