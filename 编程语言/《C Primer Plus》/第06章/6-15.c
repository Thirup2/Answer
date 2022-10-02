#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[255];
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n') {
        str[i++] = ch;
    }
    str[i] = '\0';
    for (int j = strlen(str) - 1; j > 0; j--) {
        printf("%c", str[j]);
    }
    printf("%c\n", str[0]);

    return 0;
}