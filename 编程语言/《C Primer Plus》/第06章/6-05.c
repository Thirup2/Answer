#include <stdio.h>
int main(void)
{
    int levels;
    printf("请输入要打印的行数: ");
    scanf("%d", &levels);
    for (int i = 0; i < levels; i++) {
        for (int j = levels - i - 1; j > 0; j--) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%c", 'A' + j);
        }
        for (int j = 0; j < i; j++) {
            printf("%c", 'A' + i - j - 1);
        }
        printf("\n");
    }

    return 0;
}