#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                if (ch < 'N') {
                    ch += 13;
                } else {
                    ch -= 13;
                }
            } else {
                if (ch < 'n') {
                    ch += 13;
                } else {
                    ch -= 13;
                }
            }
        }
        putchar(ch);
    }

    return 0;
}