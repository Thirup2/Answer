#include <stdio.h>
#include <string.h>
int main(void)
{
    char str1[10000];
    char str2[10000];
    char ch;
    int r = 1;
    int i = 0;
    for (; (ch = getchar()) != '\n' && ch != EOF; i++) {
        str1[i] = ch;
    }
    str1[i + 1] = '\0';
    i = 0;
    for (; (ch = getchar()) != '\n' && ch != EOF; i++) {
        str2[i] = ch;
    }
    str2[i + 1] = '\0';
    for (int i = 0; i < strlen(str1); i++) {
        for (int j = 0; j < strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                r = 0;
                break;
            }
        }
        if (r == 1) {
            putchar(str1[i]);
        }
        r = 1;
    }

    return 0;
}