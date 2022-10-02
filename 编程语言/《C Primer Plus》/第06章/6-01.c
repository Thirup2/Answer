#include <stdio.h>
int main(void)
{
    char sletter[26];
    char ch = 'a';
    for (int i = 0; i < 26; i++) {
        sletter[i] = ch++;
    }
    for (int i = 0; i < 25; i++) {
        printf("%c ", sletter[i]);
    }
    printf("%c\n", sletter[25]);

    return 0;
}