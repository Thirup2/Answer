#include <stdio.h>
int main(void)
{
    char ch;
    printf("请输入一个大写字母: ");
    scanf("%c", &ch);
    for (int i = 0; i < ch - 'A' + 1; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c ", ch - j);
        }
        printf("\n");
    }

    return 0;
}